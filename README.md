# HDU-CompilersLabs

杭电编译原理实验作业（词法分析/语法分析）  
采用 C++ 以及基本的 C++ STL 实现  
利用 Flex / Bison 制作 SysY2022 编译器

## Lab1

简单的gcc编译实验  

## Lab2 词法分析实验

|项目|说明|
|---|---|
|语言实现|C++|
|编译器|TDM-GCC-64 10.3.0|
|可视化|Graphviz  12.1.2|
  
该部分基本照搬这篇 [博客](https://blog.csdn.net/m0_61843614/article/details/134800065) 的实现  
原博客对于 NFA 转 DFA 时的终止状态没有进行判断，在这里已经加上

DFA 最小化部分基本由 Copilot 进行生成  
稍微改动了一点

## Lab3 语法分析实验

|项目|说明|
|---|---|
|语言实现|C++|
|编译器|TDM-GCC-64 10.3.0|

网上没找到 C++ 实现的版本，就算找到也都或多或少存在不小的问题，Copilot 跑出来也是纯纯的答辩   
因此是自己写的  

提供了两种输入的方式，不建议使用键盘输入，因为会无法识别多个字符组成的符号   
每个文件夹下的`main.cpp`都是自己乱写的测试用例  

我們的教育的確有問題！  
校方文档给出的预测分析表样例写错了

## Lab4 SysY 编译器设计 (正在建设)

|项目|说明|
|---|---|
|平台|Debian GNU/Linux 12.8| 
|编译|gcc (Debian 12.2.0-14) 12.2.0|
|Flex|flex 2.6.4|
|Bison|bison (GNU Bison) 3.8.2|

文档参考 => [GNU/Bison](https://www.gnu.org/software/bison/manual/html_node/index.html)  
照抄 SysY2022 定义文档会产生巨多错误，需要进行调整  
该部分参考了前人的智慧成果 => [kylinsoft/ex3-1-bison](https://github.com/kylinsoft/ex3-1-bison/blob/main/src/parser.y)  
`IF-ELSE` 移进/规约冲突使用了 `%nonassoc` 声明非结合性来处理，不过 Bison 在生成输出文件时仍然会产生 warning，可以忽视