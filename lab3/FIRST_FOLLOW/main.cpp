#include "func.cpp"

int main()
{
    Grammar g;

    // S -> A B
    Rule r = {"S", {{"A", "B"}}};
    g.insert(r);
    // A -> a A | ε
    r = {"A", {{"a", "A"}, {"ε"}}};
    g.insert(r);
    // B -> b
    r = {"B", {{"b"}}};
    g.insert(r);
    g.output();
    cout << endl;
    cout << "FIRST集：" << endl;
    g.get_FIRST(true);
    cout << endl;
    cout << "FOLLOW集：" << endl;
    g.get_FOLLOW(true);
    cout << endl;
    set<Symbol> first = g.calf({"B", "A"});
    cout << "FIRST(A B) = { ";
    for (const auto &symbol : first)
        cout << symbol << " ";
    cout << "}" << endl;
    cout << endl;
    return 0;
}