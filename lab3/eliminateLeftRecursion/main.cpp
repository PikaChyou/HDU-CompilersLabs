#include "func.cpp"

int main()
{
    Grammar g;
    g.input();
    cout << "原始文法：" << endl;
    g.output();

    g.eliminateLeftRecursion();
    cout << "消除左递归后的文法：" << endl;
    g.output();

    return 0;
}