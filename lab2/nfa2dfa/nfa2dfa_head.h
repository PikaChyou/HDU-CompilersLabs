// head.h
#ifndef HEAD_H
#define HEAD_H

#include <iostream>
#include <stdio.h>
#include <cctype>
#include <stack>
#include <string>
#include <map>
#include <set>
#include <vector>
#include <iterator>
#include <fstream>

using namespace std;

/*构造NFA和DFA所需要的结构体*/
// NFA的节点
struct node
{
    string nodeName;
};

// NFA的边
struct edge
{
    node startName;  // 起始点
    node endName;    // 目标点
    char tranSymbol; // 转换符号
};

// NFA的组成单元，一个大的NFA单元可以是由很多小单元通过规则拼接起来
struct elem
{
    int edgeCount;     // 边数
    edge edgeSet[100]; // 该NFA拥有的边
    node startName;    // 开始状态
    node endName;      // 结束状态
};

// 定义 DFA 的状态
struct DFAState
{
    set<string> nfaStates; // 一个包含NFA状态的集合
    string stateName;
};

// 定义 DFA 的转换关系
struct DFATransition
{
    DFAState fromState;
    DFAState toState;
    char transitionSymbol;
};

/*下面是转换为DFA的主要函数*/

// 计算 NFA 状态的ε闭包
DFAState eClosure(const set<string> &nfaStates, elem nfa);

// 计算 DFA 的状态转移
DFAState move(const DFAState &dfaState, char transitionSymbol, elem nfa);

// 检查 DFA 状态是否在状态集合中
bool isDFAStateInVector(const vector<DFAState> &dfaStates, const DFAState &targetState);

// 检查转换边是否在边集合中，比如a->b是否已经在集合中
bool isTransitionInVector(DFAState, DFAState, char, vector<DFATransition>);

// NFA转换为DFA
void buildDFAFromNFA(const elem &NFA_Elem, vector<DFAState> &dfaStates, vector<DFATransition> &dfaTransitions);

// 显示 DFA 状态和转移关系
void displayDFA(const vector<DFAState> &dfaStates, const vector<DFATransition> &dfaTransitions);

// 生成dot文件
void generateDotFile_DFA(vector<DFAState> &dfaStates, vector<DFATransition> &dfaTransitions);

/*下面是构造NFA的主要函数*/
// 创建新节点
node new_node();

// 处理 a
elem act_Elem(char);

// 处理a|b
elem act_Unit(elem, elem);

// 组成单元拷贝函数
void elem_copy(elem &, elem);

// 处理ab
elem act_join(elem, elem);

// 处理 a*
elem act_star(elem);

void input(string &);

string add_join_symbol(string); // 两个单元拼接在一起相当于中间有一个+，如ab相当于a+b

class infixToPostfix
{
public:
    infixToPostfix(const string &infix_expression);

    int is_letter(char check);
    int ispFunc(char c);
    int icpFunc(char c);
    void infToPost();
    string getResult();

private:
    string infix;
    string postfix;
    map<char, int> isp;
    map<char, int> icp;
};

elem express_to_NFA(string);

void Display(elem);

int is_letter(char check);

void generateDotFile_NFA(const elem &nfa);
#endif
