#include "func.cpp"

int main()
{
    Grammar g = input();
    cout << "原始文法：" << endl;
    output(g);

    Grammar newGrammar = eliminateLeftRecursion(g);
    cout << "消除左递归后的文法：" << endl;
    output(newGrammar);

    return 0;
}