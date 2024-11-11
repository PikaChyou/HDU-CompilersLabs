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

// 判断文法是否有直接左递归
bool hasLeftRecursion(const Rule &r)
{
    Symbol A = r.left;
    for (auto &right : r.rights)
    {
        if (right[0] == A)
            return true;
    }
    return false;
}

// 消除直接左递归
Grammar eliminateDirectLeftRecursion(const Grammar &g)
{
    Grammar newGrammar = g;
    newGrammar.rules.clear();
    for (auto &r : g.rules)
    {
        if (!hasLeftRecursion(r))
        {
            newGrammar.rules.push_back(r);
            continue;
        }

        Symbol A = r.left;
        vector<vector<Symbol>> alpha; // alpha是所有以A开头的产生式
        vector<vector<Symbol>> beta;  // beta是所有不以A开头的产生式

        for (auto &right : r.rights)
        {
            if (right[0] == A)
                alpha.push_back(vector<Symbol>(right.begin() + 1, right.end()));
            else
                beta.push_back(right);
        }

        Symbol A1 = getSymbol(newGrammar, A + "'");

        Rule newRule1;
        newRule1.left = A;
        for (vector<Symbol> &right : beta)
            right.push_back(A1);
        newRule1.rights = beta;
        newGrammar.rules.push_back(newRule1);

        Rule newRule2;
        newRule2.left = A1;
        for (vector<Symbol> &right : alpha)
            right.push_back(A1);
        newRule2.rights = alpha;
        newRule2.rights.push_back({getSymbol(newGrammar, "ε")});
        newGrammar.rules.push_back(newRule2);
    }
    return newGrammar;
}

// 将非终结符按照字典序排序
void sortNonterminals(Grammar &g)
{
    sort(g.nonterminals.begin(), g.nonterminals.end());
}

// 消除包含间接在内的所有左递归
Grammar eliminateLeftRecursion(const Grammar &g)
{
    Grammar newGrammar = g;
    sortNonterminals(newGrammar);
    for (auto i = newGrammar.nonterminals.begin(); i != newGrammar.nonterminals.end(); i++)
    {
        for (auto j = newGrammar.nonterminals.begin(); j != i; j++)
        {
            auto Ai = find_if(newGrammar.rules.begin(), newGrammar.rules.end(), [&](const Rule &r)
                              { return r.left == *i; });
            auto Aj = find_if(newGrammar.rules.begin(), newGrammar.rules.end(), [&](const Rule &r)
                              { return r.left == *j; });

            vector<vector<Symbol>> newRights;

            for (auto it = Ai->rights.begin(); it != Ai->rights.end();)
            {
                auto right = *it;
                if (!right.empty() && right[0] == *j)
                {
                    for (auto &ajRight : Aj->rights)
                    {
                        vector<Symbol> newRight;
                        newRight.insert(newRight.end(), ajRight.begin(), ajRight.end());
                        newRight.insert(newRight.end(), right.begin() + 1, right.end());
                        newRights.push_back(newRight);
                    }
                    it = Ai->rights.erase(it);
                }
                else
                {
                    ++it;
                }
            }

            Ai->rights.insert(Ai->rights.end(), newRights.begin(), newRights.end());
        }
    }
    return eliminateDirectLeftRecursion(newGrammar);
}