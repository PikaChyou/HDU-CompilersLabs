- [HDU-CompilersLabs](#hdu-compilerslabs)
  - [实验环境说明](#实验环境说明)
  - [Lab1](#lab1)
  - [Lab2 词法分析实验](#lab2-词法分析实验)
    - [2.1 正规表达式转NFA算法及实现](#21-正规表达式转nfa算法及实现)
    - [2.2 NFA转DFA算法及实现](#22-nfa转dfa算法及实现)
    - [2.3 DFA最小化算法及实现](#23-dfa最小化算法及实现)
  - [Lab3 语法分析实验](#lab3-语法分析实验)
    - [3.1 上下文无关文法左递归消去算法的实现](#31-上下文无关文法左递归消去算法的实现)
    - [3.2 文法左公共因子提取方法及实现](#32-文法左公共因子提取方法及实现)
    - [...（正在施工）](#正在施工)

# HDU-CompilersLabs
杭电编译原理实验作业（词法分析/语法分析）  
采用 C++ 以及基本的 C++ STL 实现
## 实验环境说明  

|项目|说明|
|---|---|
|实验平台|Windows11|
|语言实现|C++|
|编译器|TDM-GCC-64 10.3.0|
|可视化|Graphviz  12.1.2|

## Lab1

简单的gcc编译实验  
太过简单以至于没什么好说的

## Lab2 词法分析实验
  
### 2.1 正规表达式转NFA算法及实现

该部分基本照搬这篇 [博客](https://blog.csdn.net/m0_61843614/article/details/134800065) 的实现  

### 2.2 NFA转DFA算法及实现

基本同上照搬  
原博客对于 NFA 转 DFA 时的终止状态没有进行判断，在这里已经加上

### 2.3 DFA最小化算法及实现

该部分大致框架由 Copilot 进行生成  
秉持能跑绝不改动的原则，尽管生成出来的代码非常不优雅，但个人并没有进行大刀阔斧的修改

## Lab3 语法分析实验

### 3.1 上下文无关文法左递归消去算法的实现

网上没找到 C++ 实现的版本，就算找到也都或多或少存在不小的问题，Copilot 跑出来也是纯纯的答辩   
那咋办，只能自己搓了呗  

### 3.2 文法左公共因子提取方法及实现

基于 3.1 定义的数据结构进行实现   
写到一半进行了一次大重构  
把原来散漫的函数式改成了相对优雅严谨一些的面向对象

### ...（正在施工）
