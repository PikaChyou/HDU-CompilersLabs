#include "func.cpp"

int main()
{
    Grammar g;

    Rule r = {"S", {{"A", "B"}}};
    g.insert(r);
    r = {"A", {{"a"}, {"ε"}}};
    g.insert(r);
    r = {"B", {{"b"}}};
    g.insert(r);
    g.output();
    FIRST first = g.getFIRST();
    FOLLOW follow = g.getFOLLOW(first);
    cout << "FIRST:" << endl;
    displaySet(first);
    cout << "FOLLOW:" << endl;
    displaySet(follow);
    return 0;
}