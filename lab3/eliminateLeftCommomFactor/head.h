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
};

// 文法
struct Grammar
{
    int num;
    vector<Symbol> terminals = {"ε"};
    vector<Symbol> nonterminals;
    vector<Rule> rules;
};

// 获取符号,如果符号不在文法中，则将其加入文法的符号集合中
Symbol getSymbol(Grammar &g, const Symbol &s);

// 输入文法
Grammar input();

// 输出文法
void output(const Grammar &g);