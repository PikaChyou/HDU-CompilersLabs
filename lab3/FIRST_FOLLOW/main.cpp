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
    set<Symbol> first = g.calf({"B", "A"});
    cout << "FIRST(A B) = { ";
    for (const auto &symbol : first)
        cout << symbol << " ";
    cout << "}" << endl;
    cout << endl;
    return 0;
}