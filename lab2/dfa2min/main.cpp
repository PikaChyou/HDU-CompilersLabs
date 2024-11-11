// main.cpp
#include "func.cpp" // 包含提供的头文件

int main()
{
    string Regular_Expression;
    elem NFA_Elem;
    input(Regular_Expression);
    if (Regular_Expression.length() > 1)
        Regular_Expression = add_join_symbol(Regular_Expression);
    infixToPostfix Solution(Regular_Expression);
    // 中缀转后缀
    cout << "后缀表达式为：";
    Regular_Expression = Solution.getResult();
    cout << Regular_Expression << endl;
    // 表达式转NFA
    NFA_Elem = express_to_NFA(Regular_Expression);
    // 显示
    Display(NFA_Elem);
    // 生成NFAdot文件
    // generateDotFile_NFA(NFA_Elem);

    DFA dfa;

    // 初始化 DFA 状态集合和转换关系
    vector<DFAState> dfaStates;           // 用于存储所有的DFA状态
    vector<DFATransition> dfaTransitions; // 用于存储DFA状态之间的转移
    set<string> nfaInitialStateSet;       // 存储NFA的初始状态
    buildDFAFromNFA(NFA_Elem, dfa);       // 从NFA构造DFA
    // 显示 DFA
    displayDFA(dfa);

    cout << "最小化DFA:" << endl;

    DFA minimizedDFA = hopcroft(dfa);

    // 生成DFAdot文件
    generateDotFile_DFA(minimizedDFA);
    return 0;
}
