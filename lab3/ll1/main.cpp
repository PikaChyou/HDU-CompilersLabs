#include "func.cpp"

int main()
{
    Grammar g;
    // S->AB
    Rule r = {"S", {{"A", "B"}}};
    g.insert(r);
    // A->aA|ε
    r = {"A", {{"a", "A"}, {"ε"}}};
    // B->bB|ε
    g.insert(r);
    r = {"B", {{"b"}}};
    g.insert(r);
    g.output();
    cout << endl;
    g.get_FIRST(true);
    cout << endl;
    g.get_FOLLOW(true);
    g.generateParsingTable(true);
    cout << endl;
    if (g.isLL1())
    {
        cout << "LL(1) Grammar" << endl;
        if (g.LL1_parser(vector<Symbol>{"a", "b"}))
            cout << "Parsing Successful" << endl;
        else
            cout << "Syntax Error" << endl;
    }
    else
        cout << "Not LL(1) Grammar" << endl;
    cout << endl;
    return 0;
}