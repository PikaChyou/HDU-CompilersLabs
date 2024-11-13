#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <set>
#include <string>
#include <queue>
#include <stack>
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
    map<Symbol, TrieNode *> children;
    bool isEndOfWord;

    TrieNode() : isEndOfWord(false) {}
};

typedef map<Symbol, set<Symbol>> FIRST;  // FIRST集
typedef map<Symbol, set<Symbol>> FOLLOW; // FOLLOW集

// 输出FIRST或者FOLLOW集
void displaySet(const map<Symbol, set<Symbol>> &sets);

// 生成Trie树
TrieNode *generateTrie(const Rule &rule);

// 判断文法是否有直接左递归
bool hasLeftRecursion(const Rule &r);

// 文法
class Grammar
{
private:
    vector<Symbol> terminals;                    // 终结符
    vector<Symbol> nonterminals;                 // 非终结符
    vector<Rule> rules;                          // 规则
    FIRST first;                                 // FIRST集
    FOLLOW follow;                               // FOLLOW集
    map<Symbol, map<Symbol, vector<Symbol>>> pt; // 预测分析表

public:
    Grammar() : terminals({"ε"}) {};                                                    // 默认终结符集合中包含空串
    Grammar(vector<Symbol> terminals, vector<Symbol> nonterminals, vector<Rule> rules); // 构造函数
    ~Grammar();                                                                         // 析构函数
    void input();                                                                       // 输入文法
    bool insert(const Rule &r);                                                         // 插入规则
    void output() const;                                                                // 输出文法
    void merge(Grammar *g);                                                             // 合并文法，需要手动销毁被合并的函数
    void sortNonterminals(bool desc);                                                   // 将非终结符按照字典序排序
    void eliminateLeftRecursion();                                                      // 消除直接左递归
    void extractLeftCommonFactors();                                                    // 提取左公因式
    FIRST get_FIRST(bool display);                                                      // 获取FIRST集并打印
    set<Symbol> calf(vector<Symbol> seq);                                               // 根据非终结符的FIRST集计算FIRST集
    FOLLOW get_FOLLOW(bool display);                                                    // 获取FOLLOW集并打印
    bool isLL1();                                                                       // 判断是否是LL(1)文法
    bool LL1_parser(const vector<Symbol> &input);                                       // LL(1)解析器

private:
    void eliminateDirectLeftRecursion();                           // 消除直接左递归
    void traverseTrie(TrieNode *root, Symbol L, vector<Symbol> R); // 使用递归构建无左公因式文法
    void compute_FIRST(Symbol symbol, set<Symbol> &visited);       // 计算FIRST集
    void compute_FOLLOW(Symbol symbol, set<Symbol> &visited);      // 计算FOLLOW集
    bool generateParsingTable();                                   // 生成预测分析表
};