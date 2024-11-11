// func.cpp
#include "nfa2dfa_head.h"

int nodeNum = 0;

/*下面是转换为DFA的主要函数*/

// 计算 NFA 状态的ε闭包
DFAState eClosure(const set<string> &nfaStates, elem nfa)
{
    DFAState eClosureState;
    eClosureState.nfaStates = nfaStates;

    stack<string> stateStack;

    // 初始化栈，将初始状态加入栈，最开始nfaState里只有NFA_Elem.startName
    for (const string &nfaState_name : nfaStates)
    {
        stateStack.push(nfaState_name);
    }

    while (!stateStack.empty())
    {
        string currentState = stateStack.top();
        stateStack.pop();

        // 遍历 NFA 的边
        for (int i = 0; i < nfa.edgeCount; i++)
        {
            edge currentEdge = nfa.edgeSet[i];

            // 如果边的起始状态是当前状态，并且边的转换符号是#，那么将目标状态加入ε闭包
            if (currentEdge.startName.nodeName == currentState && currentEdge.tranSymbol == '#')
            {
                // 检查目标状态是否已经在ε闭包中，避免重复添加
                if (eClosureState.nfaStates.find(currentEdge.endName.nodeName) == eClosureState.nfaStates.end())
                {
                    eClosureState.nfaStates.insert(currentEdge.endName.nodeName);
                    // 将目标状态加入栈以便进一步处理
                    stateStack.push(currentEdge.endName.nodeName);
                }
            }
        }
    }

    // 为ε闭包分配一个唯一的名称
    for (const string &nfaState_name : eClosureState.nfaStates)
    {
        eClosureState.stateName += nfaState_name;
    }

    return eClosureState;
}

// move函数
DFAState move(const DFAState &dfaState, char transitionSymbol, elem nfa)
{
    DFAState nextState;

    // 遍历 DFAState 中的每个 NFA 状态
    for (const string &nfaState_name : dfaState.nfaStates)
    {
        // 在这里遍历所有 NFA 状态的边
        for (int i = 0; i < nfa.edgeCount; i++)
        {
            edge currentEdge = nfa.edgeSet[i];

            // 如果边的起始状态是当前状态，且边的转换符号等于输入符号，将目标状态加入 nextState
            if (currentEdge.startName.nodeName == nfaState_name && currentEdge.tranSymbol == transitionSymbol && currentEdge.tranSymbol != '#')
            {
                nextState.nfaStates.insert(currentEdge.endName.nodeName);
            }
        }
    }

    // 为 nextState 分配一个唯一的名称
    for (const string &nfaState_name : nextState.nfaStates)
    {
        nextState.stateName += nfaState_name;
    }

    return nextState;
}

// 检查 DFA 状态是否在状态集合中,即dfaStates里有没有找到targetState
bool isDFAStateInVector(const vector<DFAState> &dfaStates, const DFAState &targetState)
{
    for (const DFAState &state : dfaStates)
    {
        if (state.stateName == targetState.stateName)
        {
            return true; // 找到匹配的状态
        }
    }
    return false; // 没有找到匹配的状态
}

// 检查转换边是否在边集合中，比如a->b是否已经在集合中
bool isTransitionInVector(DFAState dfaState, DFAState dfaNextState, char symbol, vector<DFATransition> dfaTransitions)
{
    for (const DFATransition &transition : dfaTransitions)
    {
        if (transition.fromState.stateName == dfaState.stateName && dfaNextState.stateName == dfaNextState.stateName && symbol == transition.transitionSymbol)
        {
            return true; // 找到匹配的状态
        }
    }
    return false;
}

void buildDFAFromNFA(const elem &NFA_Elem, vector<DFAState> &dfaStates, vector<DFATransition> &dfaTransitions)
{
    // 初始化 DFA 状态集合和转换关系
    set<string> nfaInitialStateSet;
    nfaInitialStateSet.insert(NFA_Elem.startName.nodeName);
    DFAState dfaInitialState = eClosure(nfaInitialStateSet, NFA_Elem); // 计算 NFA 初始状态的 ε闭包
    dfaStates.push_back(dfaInitialState);

    // 开始构建 DFA
    for (int i = 0; i < dfaStates.size(); i++)
    {
        DFAState dfaState = dfaStates[i];
        for (int j = 0; j < NFA_Elem.edgeCount; j++)
        {
            char symbol = NFA_Elem.edgeSet[j].tranSymbol;
            DFAState nextState = move(dfaState, symbol, NFA_Elem);
            DFAState dfaNextState = eClosure(nextState.nfaStates, NFA_Elem);

            if (!nextState.nfaStates.empty())
            {
                // 如果下一个状态不为空，且在 DFA 状态集合中还未添加，则加入 DFA 状态集合
                if (!isDFAStateInVector(dfaStates, dfaNextState))
                {
                    dfaStates.push_back(dfaNextState);
                }
                // 对于边也要去重，因为等于a的边可能会遍历到两次
                // 如果当前边在 DFA 转换关系中还未添加，则加入 DFA 转换关系
                if (!isTransitionInVector(dfaState, dfaNextState, symbol, dfaTransitions))
                {
                    dfaTransitions.push_back({dfaState, dfaNextState, symbol});
                }
            }
        }
    }
}

// 显示 DFA 状态和转移关系，包括起始和结束状态
void displayDFA(const vector<DFAState> &dfaStates, const vector<DFATransition> &dfaTransitions)
{
    cout << "DFA States:" << endl;

    for (const DFAState &state : dfaStates)
    {
        cout << "State " << state.stateName << " (NFA States: ";
        for (const string &nfaState_name : state.nfaStates)
        {
            cout << nfaState_name << " ";
        }
        cout << ")";
        if (state.stateName == dfaStates.front().stateName)
        {
            cout << " (Initial State)";
        }
        if (state.stateName == dfaStates.back().stateName)
        {
            cout << " (Final State)";
        }
        cout << endl;
    }

    cout << "DFA Transitions:" << endl;
    for (const DFATransition &transition : dfaTransitions)
    {
        cout << "State " << transition.fromState.stateName << " --(" << transition.transitionSymbol << ")--> State " << transition.toState.stateName << endl;
    }
}

// 生成DFA的dot文件
void generateDotFile_DFA(vector<DFAState> &dfaStates, vector<DFATransition> &dfaTransitions)
{
    std::ofstream dotFile("dfa_graph.dot");

    if (dotFile.is_open())
    {
        dotFile << "digraph DFA {\n";
        dotFile << "  rankdir=LR;  // 横向布局\n\n";
        dotFile << " node [shape = circle];   // 初始状态\n\n";
        dotFile << dfaStates.back().stateName << "[shape = doublecircle];\n";
        // 添加DFA状态
        for (const auto &state : dfaStates)
        {
            dotFile << "  " << state.stateName;
            dotFile << " [label=\"State " << state.stateName;
            if (state.stateName == dfaStates.front().stateName)
                dotFile << "\\n(startState)";
            if (state.stateName == dfaStates.back().stateName)
            {
                dotFile << "\\n(endState)";
            }
            dotFile << "\"];\n";
        }
        dotFile << "\n";

        // 添加DFA转移
        for (const auto &transition : dfaTransitions)
        {
            dotFile << "  " << transition.fromState.stateName << " -> " << transition.toState.stateName << " [label=\"" << transition.transitionSymbol << "\"];\n";
        }

        dotFile << "}\n";

        dotFile.close();
        std::cout << "DFA DOT file generated successfully.\n";
    }
    else
    {
        std::cerr << "Unable to open DOT file.\n";
    }
}

/*下面是构造NFA的主要函数*/

// 创建新节点
node new_node()
{
    node newNode;
    newNode.nodeName = nodeNum + 65; // 将名字用大写字母表示
    nodeNum++;
    return newNode;
}

// 接收输入正规表达式
void input(string &RE)
{
    cout << "请输入正则表达式：  （操作符：() * |;字符集：a~z A~Z）" << endl;
    cin >> RE;
}

// 组成单元拷贝函数
void elem_copy(elem &dest, elem source)
{
    for (int i = 0; i < source.edgeCount; i++)
    {
        dest.edgeSet[dest.edgeCount + i] = source.edgeSet[i];
    }
    dest.edgeCount += source.edgeCount;
}

// 处理 a
elem act_Elem(char c)
{
    // 新节点
    node startNode = new_node();
    node endNode = new_node();

    // 新边
    edge newEdge;
    newEdge.startName = startNode;
    newEdge.endName = endNode;
    newEdge.tranSymbol = c;

    // 新NFA组成元素（小的NFA元素/单元)
    elem newElem;
    newElem.edgeCount = 0; // 初始状态
    newElem.edgeSet[newElem.edgeCount++] = newEdge;
    newElem.startName = newElem.edgeSet[0].startName;
    newElem.endName = newElem.edgeSet[0].endName;

    return newElem;
}

// 处理a|b
elem act_Unit(elem fir, elem sec)
{
    elem newElem;
    newElem.edgeCount = 0;
    edge edge1, edge2, edge3, edge4;

    // 获得新的状态节点
    node startNode = new_node();
    node endNode = new_node();

    // 构建e1（连接起点和AB的起始点A）
    edge1.startName = startNode;
    edge1.endName = fir.startName;
    edge1.tranSymbol = '#';

    // 构建e2（连接起点和CD的起始点C）
    edge2.startName = startNode;
    edge2.endName = sec.startName;
    edge2.tranSymbol = '#';

    // 构建e3（连接AB的终点和终点）
    edge3.startName = fir.endName;
    edge3.endName = endNode;
    edge3.tranSymbol = '#';

    // 构建e4（连接CD的终点和终点）
    edge4.startName = sec.endName;
    edge4.endName = endNode;
    edge4.tranSymbol = '#';

    // 将fir和sec合并
    elem_copy(newElem, fir);
    elem_copy(newElem, sec);

    // 新构建的4条边
    newElem.edgeSet[newElem.edgeCount++] = edge1;
    newElem.edgeSet[newElem.edgeCount++] = edge2;
    newElem.edgeSet[newElem.edgeCount++] = edge3;
    newElem.edgeSet[newElem.edgeCount++] = edge4;

    newElem.startName = startNode;
    newElem.endName = endNode;

    return newElem;
}

// 处理 N(s)N(t)
elem act_join(elem fir, elem sec)
{
    // 将fir的结束状态和sec的开始状态合并，将sec的边复制给fir，将fir返回
    // 将sec中所有以StartState开头的边全部修改
    for (int i = 0; i < sec.edgeCount; i++)
    {
        if (sec.edgeSet[i].startName.nodeName.compare(sec.startName.nodeName) == 0)
        {
            sec.edgeSet[i].startName = fir.endName; // 该边e1的开始状态就是N(t)的起始状态
        }
        else if (sec.edgeSet[i].endName.nodeName.compare(sec.startName.nodeName) == 0)
        {
            sec.edgeSet[i].endName = fir.endName; // 该边e2的结束状态就是N(t)的起始状态
        }
    }
    sec.startName = fir.endName;

    elem_copy(fir, sec);

    // 将fir的结束状态更新为sec的结束状态
    fir.endName = sec.endName;
    return fir;
}

// 处理a*
elem act_star(elem Elem)
{
    elem newElem;
    newElem.edgeCount = 0;
    edge edge1, edge2, edge3, edge4;

    // 获得新状态节点
    node startNode = new_node();
    node endNode = new_node();

    // e1
    edge1.startName = startNode;
    edge1.endName = endNode;
    edge1.tranSymbol = '#'; // 闭包取空串

    // e2
    edge2.startName = Elem.endName;
    edge2.endName = Elem.startName;
    edge2.tranSymbol = '#';

    // e3
    edge3.startName = startNode;
    edge3.endName = Elem.startName;
    edge3.tranSymbol = '#';

    // e4
    edge4.startName = Elem.endName;
    edge4.endName = endNode;
    edge4.tranSymbol = '#';

    // 构建单元
    elem_copy(newElem, Elem);

    // 将新构建的四条边加入EdgeSet
    newElem.edgeSet[newElem.edgeCount++] = edge1;
    newElem.edgeSet[newElem.edgeCount++] = edge2;
    newElem.edgeSet[newElem.edgeCount++] = edge3;
    newElem.edgeSet[newElem.edgeCount++] = edge4;

    // 构建NewElem的启示状态和结束状态
    newElem.startName = startNode;
    newElem.endName = endNode;

    return newElem;
}

int is_letter(char check)
{
    if (check >= 'a' && check <= 'z' || check >= 'A' && check <= 'Z')
        return true;
    return false;
}
//
string add_join_symbol(string add_string)
{
    int length = add_string.size();
    int return_string_length = 0;
    char *return_string = new char[2 * length + 2]; // 最多是两倍
    char first, second;
    for (int i = 0; i < length - 1; i++)
    {
        first = add_string.at(i);
        second = add_string.at(i + 1);
        return_string[return_string_length++] = first;
        // 要加的可能性如ab 、 *b 、 a( 、 )b 等情况
        // 若第二个是字母、第一个不是'('、'|'都要添加
        if (first != '(' && first != '|' && is_letter(second))
        {
            return_string[return_string_length++] = '+';
        }
        // 若第二个是'(',第一个不是'|'、'(',也要加
        else if (second == '(' && first != '|' && first != '(')
        {
            return_string[return_string_length++] = '+';
        }
    }
    // 将最后一个字符写入second
    return_string[return_string_length++] = second;
    return_string[return_string_length] = '\0';
    string STRING(return_string);
    cout << "加'+'后的表达式：" << STRING << endl;
    return STRING;
}

// 类里的各类元素定义
infixToPostfix::infixToPostfix(const string &infix_expression) : infix(infix_expression), postfix("")
{
    isp = {{'+', 3}, {'|', 5}, {'*', 7}, {'(', 1}, {')', 8}, {'#', 0}};
    icp = {{'+', 2}, {'|', 4}, {'*', 6}, {'(', 8}, {')', 1}, {'#', 0}};
}

int infixToPostfix::is_letter(char check)
{
    if (check >= 'a' && check <= 'z' || check >= 'A' && check <= 'Z')
        return true;
    return false;
}

int infixToPostfix::ispFunc(char c)
{
    int priority = isp.count(c) ? isp[c] : -1;
    if (priority == -1)
    {
        cerr << "error: 出现未知符号！" << endl;
        exit(1); // 异常退出
    }
    return priority;
}

int infixToPostfix::icpFunc(char c)
{
    int priority = icp.count(c) ? icp[c] : -1;
    if (priority == -1)
    {
        cerr << "error: 出现未知符号！" << endl;
        exit(1); // 异常退出
    }
    return priority;
}

void infixToPostfix::infToPost()
{
    string infixWithHash = infix + "#";
    stack<char> stack;
    int loc = 0;
    while (!stack.empty() || loc < infixWithHash.size())
    {
        if (is_letter(infixWithHash[loc]))
        {
            postfix += infixWithHash[loc];
            loc++;
        }
        else
        {
            char c1 = (stack.empty()) ? '#' : stack.top();
            char c2 = infixWithHash[loc];
            if (ispFunc(c1) < icpFunc(c2))
            {
                stack.push(c2);
                loc++;
            }
            else if (ispFunc(c1) > icpFunc(c2))
            {
                postfix += c1;
                stack.pop();
            }
            else
            {
                if (c1 == '#' && c2 == '#')
                {
                    break;
                }
                stack.pop();
                loc++;
            }
        }
    }
}

string infixToPostfix::getResult()
{
    postfix = ""; // 清空结果
    infToPost();
    return postfix;
}

/**表达式转NFA处理函数,返回最终的NFA集合
 */
elem express_to_NFA(string expression)
{
    int length = expression.size();
    char element;
    elem Elem, fir, sec;
    stack<elem> STACK;
    for (int i = 0; i < length; i++)
    {
        element = expression.at(i);
        switch (element)
        {
        case '|':
            sec = STACK.top();
            STACK.pop();
            fir = STACK.top();
            STACK.pop();
            Elem = act_Unit(fir, sec);
            STACK.push(Elem);
            break;
        case '*':
            fir = STACK.top();
            STACK.pop();
            Elem = act_star(fir);
            STACK.push(Elem);
            break;
        case '+':
            sec = STACK.top();
            STACK.pop();
            fir = STACK.top();
            STACK.pop();
            Elem = act_join(fir, sec);
            STACK.push(Elem);
            break;
        default:
            Elem = act_Elem(element);
            STACK.push(Elem);
        }
    }
    cout << "已将正则表达式转换为NFA!" << endl;
    Elem = STACK.top();
    STACK.pop();

    return Elem;
}

// 打印NFA
void Display(elem Elem)
{
    cout << "NFA States:" << endl;
    cout << "Start State: " << Elem.startName.nodeName << endl;
    cout << "End State: " << Elem.endName.nodeName << endl;

    cout << "NFA Transitions:" << endl;
    for (int i = 0; i < Elem.edgeCount; i++)
    {
        cout << "Edge " << i + 1 << ": ";
        cout << Elem.edgeSet[i].startName.nodeName << " --(" << Elem.edgeSet[i].tranSymbol << ")--> ";
        cout << Elem.edgeSet[i].endName.nodeName << endl;
    }

    cout << "End" << endl;
}

// 生成NFAdot文件
void generateDotFile_NFA(const elem &nfa)
{
    std::ofstream dotFile("nfa_graph.dot");

    if (dotFile.is_open())
    {
        dotFile << "digraph NFA {\n";
        dotFile << "  rankdir=LR;  // 横向布局\n\n";
        dotFile << " node [shape = circle];   // 状态节点\n\n";

        dotFile << nfa.endName.nodeName << " [shape=doublecircle];\n";
        // 添加 NFA 状态
        dotFile << "  " << nfa.startName.nodeName << " [label=\"Start State: " << nfa.startName.nodeName << "\"];\n";
        dotFile << "  " << nfa.endName.nodeName << " [label=\"End State: " << nfa.endName.nodeName << "\"];\n";

        // 添加 NFA 转移
        for (int i = 0; i < nfa.edgeCount; i++)
        {
            const edge &currentEdge = nfa.edgeSet[i];
            dotFile << "  " << currentEdge.startName.nodeName << " -> " << currentEdge.endName.nodeName << " [label=\"" << currentEdge.tranSymbol << "\"];\n";
        }

        dotFile << "}\n";

        dotFile.close();
        std::cout << "NFA DOT file generated successfully.\n";
    }
    else
    {
        std::cerr << "Unable to open NFA DOT file.\n";
    }
}
