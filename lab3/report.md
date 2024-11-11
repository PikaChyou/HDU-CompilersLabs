- [3.1 上下文无关文法左递归消去算法的实现](#31-上下文无关文法左递归消去算法的实现)
  - [3.1.1 实验目的](#311-实验目的)
  - [3.1.2 实验要求与实验内容](#312-实验要求与实验内容)
    - [实验内容](#实验内容)
    - [实验要求](#实验要求)
  - [3.1.3 设计方案与算法描述](#313-设计方案与算法描述)
    - [数据结构](#数据结构)
    - [识别直接左递归与去除](#识别直接左递归与去除)
    - [识别间接左递归与去除](#识别间接左递归与去除)
  - [3.1.4 测试结果](#314-测试结果)
  - [3.1.5 源代码](#315-源代码)
    - [`head.h`](#headh)
    - [`func.cpp`](#funccpp)
    - [`main.cpp`](#maincpp)
- [3.2 文法左公共因子提取方法及实现](#32-文法左公共因子提取方法及实现)
  - [3.2.1 实验目的](#321-实验目的)
  - [3.2.2 实验要求与实验内容](#322-实验要求与实验内容)
    - [实验内容](#实验内容-1)
    - [实验要求](#实验要求-1)
  - [3.2.3 设计方案与算法描述](#323-设计方案与算法描述)
  - [3.2.4 测试结果](#324-测试结果)
  - [3.2.5 源代码](#325-源代码)
- [3.3 上下文无关文法FIRST集和FOLLOW集求解及实现](#33-上下文无关文法first集和follow集求解及实现)
  - [3.3.1 实验目的](#331-实验目的)
  - [3.3.2 实验要求与实验内容](#332-实验要求与实验内容)
  - [3.3.3 设计方案与算法描述](#333-设计方案与算法描述)
  - [3.3.4 测试结果](#334-测试结果)
  - [3.3.5 源代码](#335-源代码)
- [3.4 LL(1)文法判定与预测分析器设计及实现](#34-ll1文法判定与预测分析器设计及实现)
  - [3.4.1 实验目的](#341-实验目的)
  - [3.4.2 实验要求与实验内容](#342-实验要求与实验内容)
  - [3.4.3 设计方案与算法描述](#343-设计方案与算法描述)
  - [3.4.4 测试结果](#344-测试结果)
  - [3.4.5 源代码](#345-源代码)

## 3.1 上下文无关文法左递归消去算法的实现

### 3.1.1 实验目的

- 理解上下⽂⽆关⽂法中左递归的概念及其对语法分析的影响。
- 掌握消去上下⽂⽆关⽂法中直接和间接左递归的算法。
- 培养运⽤编程语⾔实现⽂法变换的能⼒。

### 3.1.2 实验要求与实验内容

#### 实验内容

1. 对⾮终结符集合进⾏排序。
2. 按顺序遍历每个⾮终结符，检查其候选式是否以排在其前⾯的⾮终结符开头，并进⾏代换。
3. 消去直接左递归

#### 实验要求

1. 输⼊：⼀个上下⽂⽆关⽂法，包括⾮终结符、终结符和产⽣式。
2. 输出: 消去左递归后的⽂法。
3. 算法: 应处理直接和间接左递归，确保输出⽂法与输⼊⽂法等价。
4. 测试：提供测试⽤例，验证算法的正确性。
5. ⽂档：编写⽂档，说明如何使⽤你的程序，包括输⼊格式和输出解释

### 3.1.3 设计方案与算法描述

#### 数据结构

符号
```cpp
typedef string Symbol;
```

规则
```cpp
struct Rule
{
    Symbol left;
    vector<vector<Symbol>> rights;
};
```

文法
```cpp
struct Grammar
{
    int num;
    vector<Symbol> terminals = {"ε"};
    vector<Symbol> nonterminals;
    vector<Rule> rules;
};
```

#### 识别直接左递归与去除

对于形如 $A -> A\alpha | \beta$ 的直接左递归，可按照以下形式去除：  

- $A -> \beta A'$
- $A' -> \alpha A' | \epsilon$  

首先要识别是否存在直接左递归  
直接扫描每一条规则的左右，如果存在右侧的第一个符号等同于左侧，则返回 `true` 指示存在直接左递归 
```cpp
bool hasLeftRecursion(const Rule &r)
{
    Symbol A = r.left;
    for (auto &right : r.rights)
    {
        if (right[0] == A)
            return true;
    }
    return false;
}
```

消除直接左递归  
根据先前提过的公式将规则分为 $\alpha$ 与 $\beta$ 部分，随后根据这两个集合产生两条规则，并新增一个符号进入非终结符集合
```cpp
Grammar eliminateDirectLeftRecursion(const Grammar &g)
{
    Grammar newGrammar = g;
    newGrammar.rules.clear();
    for (auto &r : g.rules)
    {
        if (!hasLeftRecursion(r))
        {
            newGrammar.rules.push_back(r);
            continue;
        }

        Symbol A = r.left;
        vector<vector<Symbol>> alpha; 
        vector<vector<Symbol>> beta;  

        for (auto &right : r.rights)
        {
            if (right[0] == A)
                alpha.push_back(vector<Symbol>(right.begin() + 1, right.end()));
            else
                beta.push_back(right);
        }

        Symbol A1 = getSymbol(newGrammar, A + "'");

        Rule newRule1;
        newRule1.left = A;
        for (vector<Symbol> &right : beta)
            right.push_back(A1);
        newRule1.rights = beta;
        newGrammar.rules.push_back(newRule1);

        Rule newRule2;
        newRule2.left = A1;
        for (vector<Symbol> &right : alpha)
            right.push_back(A1);
        newRule2.rights = alpha;
        newRule2.rights.push_back({getSymbol(newGrammar, "ε")});
        newGrammar.rules.push_back(newRule2);
    }
    return newGrammar;
}
```

#### 识别间接左递归与去除

首先按照字典序对非终结符进行排序
```cpp
void sortNonterminals(Grammar &g)
{
    sort(g.nonterminals.begin(), g.nonterminals.end());
}
```

参考书 P65 算法4-1  
将候选式中该非终结符为首用该非终结符的产生式替代，从而将可能的间接左递归转化为直接左递归  
```cpp
Grammar eliminateLeftRecursion(const Grammar &g)
{
    Grammar newGrammar = g;
    sortNonterminals(newGrammar);
    for (auto i = newGrammar.nonterminals.begin(); i != newGrammar.nonterminals.end(); i++)
    {
        for (auto j = newGrammar.nonterminals.begin(); j != i; j++)
        {
            auto Ai = find_if(newGrammar.rules.begin(), newGrammar.rules.end(), [&](const Rule &r)
                              { return r.left == *i; });
            auto Aj = find_if(newGrammar.rules.begin(), newGrammar.rules.end(), [&](const Rule &r)
                              { return r.left == *j; });

            vector<vector<Symbol>> newRights;

            for (auto it = Ai->rights.begin(); it != Ai->rights.end();)
            {
                auto right = *it;
                if (!right.empty() && right[0] == *j)
                {
                    for (auto &ajRight : Aj->rights)
                    {
                        vector<Symbol> newRight;
                        newRight.insert(newRight.end(), ajRight.begin(), ajRight.end());
                        newRight.insert(newRight.end(), right.begin() + 1, right.end());
                        newRights.push_back(newRight);
                    }
                    it = Ai->rights.erase(it);
                }
                else
                {
                    ++it;
                }
            }

            Ai->rights.insert(Ai->rights.end(), newRights.begin(), newRights.end());
        }
    }
    return eliminateDirectLeftRecursion(newGrammar);
}
```

### 3.1.4 测试结果

```
请输入文法规则：
S->S+T|T
T->T+F|F
F->(E)|i

原始文法：
S -> S + T | T
T -> T + F | F
F -> ( E ) | i
消除左递归后的文法：
S -> T S'
S' -> + T S' | ε
T -> ( E ) T' | i T'
T' -> + F T' | ε
F -> ( E ) | i
```

### 3.1.5 源代码

#### `head.h`

```cpp
#include <iostream>
#include <vector>
#include <set>
#include <string>
#include <algorithm>

using namespace std;

// 符号
typedef string Symbol;

// 规则
struct Rule
{
    Symbol left;
    vector<vector<Symbol>> rights;
};

// 文法
struct Grammar
{
    int num;
    vector<Symbol> terminals = {"ε"};
    vector<Symbol> nonterminals;
    vector<Rule> rules;
};

// 获取符号,如果符号不在文法中，则将其加入文法的符号集合中
Symbol getSymbol(Grammar &g, const Symbol &s);

// 输入文法
Grammar input();

// 输出文法
void output(const Grammar &g);

// 判断文法是否有直接左递归
bool hasLeftRecursion(const Rule &r);

// 消除直接左递归
Grammar eliminateDirectLeftRecursion(const Grammar &g);

// 将非终结符按照字典序排序
void sortNonterminals(Grammar &g);

// 消除包含间接在内的所有左递归
Grammar eliminateLeftRecursion(const Grammar &g);
```

#### `func.cpp`

```cpp
#include "head.h"

// 获取符号,如果符号不在文法中，则将其加入文法的符号集合中
Symbol getSymbol(Grammar &g, const Symbol &s)
{
    if (find(g.terminals.begin(), g.terminals.end(), s) != g.terminals.end() ||
        find(g.nonterminals.begin(), g.nonterminals.end(), s) != g.nonterminals.end())
        return s;
    if (isupper(s[0]))
        g.nonterminals.push_back(s);
    else
        g.terminals.push_back(s);
    return s;
}

// 输入文法
Grammar input()
{
    Grammar g;
    g.num = 0;
    cout << "请输入文法规则：" << endl;
    string s;
    while (getline(cin, s))
    {
        if (s == "\n" || s == "")
            break;
        Rule r;
        Symbol left = getSymbol(g, s.substr(0, s.find("->")));
        r.left = left;
        s = s.substr(s.find("->") + 2);
        vector<Symbol> right_part;
        size_t pos = 0;
        while ((pos = s.find('|')) != string::npos)
        {
            string token = s.substr(0, pos);
            for (char &c : token)
            {
                Symbol sym = getSymbol(g, string(1, c));
                right_part.push_back(sym);
            }
            r.rights.push_back(right_part);
            right_part.clear();
            s.erase(0, pos + 1);
        }
        for (char &c : s)
        {
            Symbol sym = getSymbol(g, string(1, c));
            right_part.push_back(sym);
        }
        r.rights.push_back(right_part);
        g.rules.push_back(r);
    }
    return g;
}

// 输出文法
void output(const Grammar &g)
{
    for (auto &r : g.rules)
    {
        cout << r.left << " -> ";
        for (size_t i = 0; i < r.rights.size(); ++i)
        {
            for (auto &s : r.rights[i])
            {
                cout << s << ' ';
            }
            if (i < r.rights.size() - 1)
                cout << "| ";
        }
        cout << endl;
    }
}

// 判断文法是否有直接左递归
bool hasLeftRecursion(const Rule &r)
{
    Symbol A = r.left;
    for (auto &right : r.rights)
    {
        if (right[0] == A)
            return true;
    }
    return false;
}

// 消除直接左递归
Grammar eliminateDirectLeftRecursion(const Grammar &g)
{
    Grammar newGrammar = g;
    newGrammar.rules.clear();
    for (auto &r : g.rules)
    {
        if (!hasLeftRecursion(r))
        {
            newGrammar.rules.push_back(r);
            continue;
        }

        Symbol A = r.left;
        vector<vector<Symbol>> alpha; // alpha是所有以A开头的产生式
        vector<vector<Symbol>> beta;  // beta是所有不以A开头的产生式

        for (auto &right : r.rights)
        {
            if (right[0] == A)
                alpha.push_back(vector<Symbol>(right.begin() + 1, right.end()));
            else
                beta.push_back(right);
        }

        Symbol A1 = getSymbol(newGrammar, A + "'");

        Rule newRule1;
        newRule1.left = A;
        for (vector<Symbol> &right : beta)
            right.push_back(A1);
        newRule1.rights = beta;
        newGrammar.rules.push_back(newRule1);

        Rule newRule2;
        newRule2.left = A1;
        for (vector<Symbol> &right : alpha)
            right.push_back(A1);
        newRule2.rights = alpha;
        newRule2.rights.push_back({getSymbol(newGrammar, "ε")});
        newGrammar.rules.push_back(newRule2);
    }
    return newGrammar;
}

// 将非终结符按照字典序排序
void sortNonterminals(Grammar &g)
{
    sort(g.nonterminals.begin(), g.nonterminals.end());
}

// 消除包含间接在内的所有左递归
Grammar eliminateLeftRecursion(const Grammar &g)
{
    Grammar newGrammar = g;
    sortNonterminals(newGrammar);
    for (auto i = newGrammar.nonterminals.begin(); i != newGrammar.nonterminals.end(); i++)
    {
        for (auto j = newGrammar.nonterminals.begin(); j != i; j++)
        {
            auto Ai = find_if(newGrammar.rules.begin(), newGrammar.rules.end(), [&](const Rule &r)
                              { return r.left == *i; });
            auto Aj = find_if(newGrammar.rules.begin(), newGrammar.rules.end(), [&](const Rule &r)
                              { return r.left == *j; });

            vector<vector<Symbol>> newRights;

            for (auto it = Ai->rights.begin(); it != Ai->rights.end();)
            {
                auto right = *it;
                if (!right.empty() && right[0] == *j)
                {
                    for (auto &ajRight : Aj->rights)
                    {
                        vector<Symbol> newRight;
                        newRight.insert(newRight.end(), ajRight.begin(), ajRight.end());
                        newRight.insert(newRight.end(), right.begin() + 1, right.end());
                        newRights.push_back(newRight);
                    }
                    it = Ai->rights.erase(it);
                }
                else
                {
                    ++it;
                }
            }

            Ai->rights.insert(Ai->rights.end(), newRights.begin(), newRights.end());
        }
    }
    return eliminateDirectLeftRecursion(newGrammar);
}
```

#### `main.cpp`

```cpp
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
```

## 3.2 文法左公共因子提取方法及实现

### 3.2.1 实验目的

- 理解上下⽂⽆关⽂法中的左公共因⼦的概念及其对语法分析的影响。
- 掌握从上下⽂⽆关⽂法中提取左公共因⼦的算法，形成⽆⼆义性的语法结构。
- 熟练运⽤数据结构（如 Trie 树）处理和优化⽂法。

### 3.2.2 实验要求与实验内容

#### 实验内容

实现从上下⽂⽆关⽂法中提取左公共因⼦的算法，具体步骤包括：
1. 对每个⾮终结符的候选式，识别最⻓的公共前缀。
2. 构建字典树（Trie），辅助提取最⻓公共前缀，将公共前缀提取为新⾮终结符的候选式。
3. 输出去除左公共因⼦的等价⽂法。

#### 实验要求

1. 输⼊⼀个上下⽂⽆关⽂法，包括⾮终结符、终结符和产⽣式。
2. 输出提取左公共因⼦后的⽂法。
3. 使⽤适当的数据结构（如 Trie 树）提⾼提取效率。
4. 确保输出⽂法⽆⼆义性，且与输⼊⽂法等价。

### 3.2.3 设计方案与算法描述

### 3.2.4 测试结果

### 3.2.5 源代码

## 3.3 上下文无关文法FIRST集和FOLLOW集求解及实现

### 3.3.1 实验目的

### 3.3.2 实验要求与实验内容

### 3.3.3 设计方案与算法描述

### 3.3.4 测试结果

### 3.3.5 源代码

## 3.4 LL(1)文法判定与预测分析器设计及实现 

### 3.4.1 实验目的

### 3.4.2 实验要求与实验内容

### 3.4.3 设计方案与算法描述

### 3.4.4 测试结果

### 3.4.5 源代码