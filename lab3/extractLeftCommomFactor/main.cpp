#include "func.cpp"

int main()
{
    Grammar g;
    // S -> abcd | abce | abaf
    Rule r = {"S", {{"a", "b", "c", "d"}, {"a", "b", "c", "e"}, {"a", "b", "a", "f"}}};
    g.insert(r);
    // X -> a | ab | ac
    r = {"X", {{"a"}, {"a", "b"}, {"a", "c"}}};
    g.insert(r);
    g.extractLeftCommonFactors();
    g.output();

    return 0;
}