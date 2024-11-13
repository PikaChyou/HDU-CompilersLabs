#include <iostream>
#include <vector>
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
    void sortNonterminals(bool desc);                                                   // 将非终结符按照字典序排序
    void eliminateLeftRecursion();                                                      // 消除直接左递归
private:
    void eliminateDirectLeftRecursion(); // 消除直接左递归
};

// 判断文法是否有直接左递归
bool hasLeftRecursion(const Rule &r);