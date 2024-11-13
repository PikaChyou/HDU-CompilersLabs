#include <iostream>
#include <vector>
#include <unordered_map>
#include <set>
#include <string>
#include <algorithm>

using namespace std;

// 符号
typedef string Symbol;

// 规则
struct Rule
{
    Symbol left;
    vector<vector<Symbol>> rights;

    bool operator==(const Rule &other) const
    {
        return left == other.left;
    }
};

// Trie树节点
struct TrieNode
{
    unordered_map<Symbol, TrieNode *> children;
    bool isEndOfWord;

    TrieNode() : isEndOfWord(false) {}
};

// 生成Trie树
TrieNode *generateTrie(const Rule &rule);

// 文法
class Grammar
{
private:
    vector<Symbol> terminals;    // 终结符
    vector<Symbol> nonterminals; // 非终结符
    vector<Rule> rules;          // 规则

public:
    Grammar() : terminals({"ε"}) {};                                                    // 默认终结符集合中包含空串
    Grammar(vector<Symbol> terminals, vector<Symbol> nonterminals, vector<Rule> rules); // 构造函数
    ~Grammar();                                                                         // 析构函数
    void input();                                                                       // 输入文法
    bool insert(const Rule &r);                                                         // 插入规则
    void output() const;                                                                // 输出文法
    void merge(Grammar *g);                                                             // 合并文法，需要手动销毁被合并的函数
    void extractLeftCommonFactors();                                                    // 提取左公因式

private:
    void traverseTrie(TrieNode *root, Symbol L, vector<Symbol> R); // 使用递归构建无左公因式文法
};
