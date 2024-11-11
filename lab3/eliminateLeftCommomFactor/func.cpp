#include "head.h"

// 获取符号,如果符号不在文法中，则将其加入文法的符号集合中
Symbol getSymbol(Grammar &g, const Symbol &s)
{
    if (find(g.terminals.begin(), g.terminals.end(), s) != g.terminals.end() ||
        find(g.nonterminals.begin(), g.nonterminals.end(), s) != g.nonterminals.end())
        return s;
    if (isupper(s[0]))
        g.nonterminals.push_back(s);
    else
        g.terminals.push_back(s);
    return s;
}

// 输入文法
Grammar input()
{
    Grammar g;
    g.num = 0;
    cout << "请输入文法规则：" << endl;
    string s;
    while (getline(cin, s))
    {
        if (s == "\n" || s == "")
            break;
        Rule r;
        Symbol left = getSymbol(g, s.substr(0, s.find("->")));
        r.left = left;
        s = s.substr(s.find("->") + 2);
        vector<Symbol> right_part;
        size_t pos = 0;
        while ((pos = s.find('|')) != string::npos)
        {
            string token = s.substr(0, pos);
            for (char &c : token)
            {
                Symbol sym = getSymbol(g, string(1, c));
                right_part.push_back(sym);
            }
            r.rights.push_back(right_part);
            right_part.clear();
            s.erase(0, pos + 1);
        }
        for (char &c : s)
        {
            Symbol sym = getSymbol(g, string(1, c));
            right_part.push_back(sym);
        }
        r.rights.push_back(right_part);
        g.rules.push_back(r);
    }
    return g;
}

// 输出文法
void output(const Grammar &g)
{
    for (auto &r : g.rules)
    {
        cout << r.left << " -> ";
        for (size_t i = 0; i < r.rights.size(); ++i)
        {
            for (auto &s : r.rights[i])
            {
                cout << s << ' ';
            }
            if (i < r.rights.size() - 1)
                cout << "| ";
        }
        cout << endl;
    }
}