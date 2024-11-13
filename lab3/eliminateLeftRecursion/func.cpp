#include "head.h"

// 非默认的构造函数
Grammar::Grammar(vector<Symbol> terminals, vector<Symbol> nonterminals, vector<Rule> rules)
    : terminals(terminals), nonterminals(nonterminals), rules(rules)
{
    this->terminals.push_back("ε");
}

// 输入文法
void Grammar::input()
{
    cout << "请输入文法规则：" << endl;
    string s;
    while (getline(cin, s))
    {
        if (s == "\n" || s == "")
            break;
        Rule r;
        Symbol left = s.substr(0, s.find("->"));
        r.left = left;
        s = s.substr(s.find("->") + 2);
        vector<Symbol> right_part;
        size_t pos = 0;
        while ((pos = s.find('|')) != string::npos)
        {
            string token = s.substr(0, pos);
            for (char &c : token)
            {
                Symbol sym = string(1, c);
                right_part.push_back(sym);
            }
            r.rights.push_back(right_part);
            right_part.clear();
            s.erase(0, pos + 1);
        }
        for (char &c : s)
        {
            Symbol sym = string(1, c);
            right_part.push_back(sym);
        }
        r.rights.push_back(right_part);
        rules.push_back(r);
    }
}

// 插入规则
bool Grammar::insert(const Rule &r)
{
    auto it = find(rules.begin(), rules.end(), r);

    // 如果规则左侧不在文法中，则插入规则
    if (it == rules.end())
    {
        rules.push_back(r);
        nonterminals.push_back(r.left);
        for (vector<Symbol> right : r.rights)
            for (Symbol s : right)
                if (find(terminals.begin(), terminals.end(), s) == terminals.end() &&
                    find(nonterminals.begin(), nonterminals.end(), s) == nonterminals.end())
                {
                    if (isupper(s[0]))
                        nonterminals.push_back(s);
                    else
                        terminals.push_back(s);
                }
        return true;
    }

    for (vector<Symbol> right : r.rights)
    {
        if (find(it->rights.begin(), it->rights.end(), right) == it->rights.end())
        {
            // 如果规则右侧不在文法中，则插入规则
            it->rights.push_back(right);
            // 更新文法的符号集合
            for (Symbol s : right)
                if (find(terminals.begin(), terminals.end(), s) == terminals.end() &&
                    find(nonterminals.begin(), nonterminals.end(), s) == nonterminals.end())
                {
                    if (isupper(s[0]))
                        nonterminals.push_back(s);
                    else
                        terminals.push_back(s);
                }
            return true;
        }
    }

    // 若规则已存在，则返回false
    return false;
}

// 合并文法，需要手动销毁被合并的函数
void Grammar::merge(Grammar *g)
{
    for (auto &t : g->terminals)
        if (find(terminals.begin(), terminals.end(), t) == terminals.end())
            terminals.push_back(t);

    for (auto &nt : g->nonterminals)
        if (find(nonterminals.begin(), nonterminals.end(), nt) == nonterminals.end())
            nonterminals.push_back(nt);

    for (auto &rule : g->rules)
    {
        auto it = find(rules.begin(), rules.end(), rule);
        if (it == rules.end())
            rules.push_back(rule);
        else
            for (vector<Symbol> right : rule.rights)
            {
                if (find(it->rights.begin(), it->rights.end(), right) == it->rights.end())
                    it->rights.push_back(right);
            }
    }
}

// 输出文法
void Grammar::output() const
{
    for (auto &r : rules)
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

// 析构函数
Grammar::~Grammar()
{
    for (auto &r : rules)
    {
        for (auto &right : r.rights)
            right.clear();
        r.rights.clear();
    }
    rules.clear();
    terminals.clear();
    nonterminals.clear();
}

// 将非终结符按照字典序排序
void Grammar::sortNonterminals(bool desc = false)
{
    if (desc)
        sort(nonterminals.begin(), nonterminals.end(), greater<Symbol>());
    else
        sort(nonterminals.begin(), nonterminals.end(), less<Symbol>());
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
void Grammar::eliminateDirectLeftRecursion()
{
    vector<Rule> pre = rules;
    rules.clear();
    for (auto &r : pre)
    {
        if (!hasLeftRecursion(r))
        {
            rules.push_back(r);
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

        Symbol A1 = A + "'";
        while (find(nonterminals.begin(), nonterminals.end(), A1) != nonterminals.end())
            A1 += "'";
        nonterminals.push_back(A1);

        Rule newRule1;
        newRule1.left = A;
        for (vector<Symbol> &right : beta)
            right.push_back(A1);
        newRule1.rights = beta;
        rules.push_back(newRule1);

        Rule newRule2;
        newRule2.left = A1;
        for (vector<Symbol> &right : alpha)
            right.push_back(A1);
        newRule2.rights = alpha;
        newRule2.rights.push_back({"ε"});
        rules.push_back(newRule2);
    }
    pre.clear();
}

// 消除包含间接在内的所有左递归
void Grammar::eliminateLeftRecursion()
{
    sortNonterminals();
    for (auto i = nonterminals.begin(); i != nonterminals.end(); i++)
    {
        for (auto j = nonterminals.begin(); j != i; j++)
        {
            auto Ai = find_if(rules.begin(), rules.end(), [&](const Rule &r)
                              { return r.left == *i; });
            auto Aj = find_if(rules.begin(), rules.end(), [&](const Rule &r)
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
                    ++it;
            }

            Ai->rights.insert(Ai->rights.end(), newRights.begin(), newRights.end());
        }
    }
    eliminateDirectLeftRecursion();
}