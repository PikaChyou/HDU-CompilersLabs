#include "func.cpp"

int main()
{
    Grammar g;

    Rule r = {"S", {{"A", "B"}}};
    g.insert(r);
    r = {"A", {{"a", "A"}, {"ε"}}};
    g.insert(r);
    r = {"B", {{"b"}}};
    g.insert(r);
    g.output();
    cout << endl;
    g.get_FIRST(true);
    cout << endl;
    g.get_FOLLOW(true);
    cout << endl;
    cout << g.isLL1() << endl;
    cout << endl;
    if (g.LL1_parser(vector<Symbol>{"a", "b"}))
        cout << "Parsing Successful" << endl;
    else
        cout << "Syntax Error" << endl;
    return 0;
}