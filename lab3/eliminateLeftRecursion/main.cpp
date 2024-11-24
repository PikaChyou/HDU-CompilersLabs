#include "func.cpp"

int main()
{
    Grammar g;

    Rule r = {"S", {{"S", "+", "T"}, {"T"}}};
    g.insert(r);
    r = {"T", {{"T", "+", "F"}, {"F"}}};
    g.insert(r);
    r = {"F", {{"(", "E", ")"}, {"id"}}};
    g.insert(r);

    cout << "原文法：" << endl;
    g.output();

    g.eliminateLeftRecursion();
    cout << "消除左递归后的文法：" << endl;
    g.output();

    return 0;
}