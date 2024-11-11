// re2nfa_head.h
#include <iostream>
#include <map>

using namespace std;

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