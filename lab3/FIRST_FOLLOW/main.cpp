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
    vector<FIRST> first = g.getFIRST();
    return 0;
}