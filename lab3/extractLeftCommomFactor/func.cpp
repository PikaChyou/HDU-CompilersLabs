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

// 生成Trie树
TrieNode *generateTrie(const Rule &rule)
{
    // 生成Trie树
    TrieNode *root = new TrieNode();
    TrieNode *node;
    for (auto right : rule.rights)
    {
        node = root;
        for (auto symbol : right)
        {
            if (node->children.find(symbol) == node->children.end())
                node->children[symbol] = new TrieNode();
            node = node->children[symbol];
        }
        node->isEndOfWord = true;
    }
    return root;
}

// 使用递归构建无左公因式文法
void Grammar::traverseTrie(TrieNode *root, Symbol L, vector<Symbol> R)
{
    // 若当前节点只有一个子节点，则继续遍历树
    while (root->children.size() == 1)
    {
        auto it = root->children.begin();
        R.push_back(it->first);
        root = it->second;
    }
    // 若当前节点是叶子节点，则插入规则
    if (root->children.size() == 0 && root->isEndOfWord)
        insert({L, {R}});
    // 遇到分叉节点，将该节点作为新的根节点，继续遍历树
    else
    {
        Symbol newL = L;
        while (find(nonterminals.begin(), nonterminals.end(), newL) != nonterminals.end())
            newL += "'";
        vector<Symbol> tmp = R;
        tmp.push_back(newL);
        insert({L, {tmp}});
        tmp.clear();
        for (auto it = root->children.begin(); it != root->children.end(); ++it)
        {
            tmp.push_back(it->first);
            traverseTrie(it->second, newL, tmp);
        }
        tmp.clear();
        if (root->isEndOfWord)
            insert({newL, {{"ε"}}});
    }
}

// 提取左公因式
void Grammar::extractLeftCommonFactors()
{

    vector<Rule> preRules = rules;
    rules.clear();
    // 遍历每一条规则
    for (auto it = preRules.begin(); it != preRules.end(); ++it)
    {
        TrieNode *root = generateTrie(*it);
        Symbol L = it->left;
        vector<Symbol> R;

        for (auto it = root->children.begin(); it != root->children.end(); ++it)
        {
            R.push_back(it->first);
            traverseTrie(it->second, L, R);
            R.clear();
        }
    }
    preRules.clear();
}