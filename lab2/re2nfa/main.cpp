// main.cpp
#include "re2nfa_func.cpp" // 包含提供的函数实现

void generatePic()
{
    system("dot -Tpng nfa_graph.dot -o nfa_graph.png");
}

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
    generateDotFile_NFA(NFA_Elem);

    // 生成图片
    generatePic();

    return 0;
}
