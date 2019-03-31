# Windows7 Dev C++

## BETTER

check 2018_D.cpp
STL sort用法

## ATTENTION

临时表示只能用`C`, 替代解决方案

* include 要加h
* 尝试使用`qsort`代替STL
* 无`bool`类型

## 上机首要环境设置Env

工具->编译选项, 加入命令:`-std=c++11`

工具, 快捷键选项 拉到最后设置代码提示为`ctrl+enter`

## shortcuts

运行->调试      F5
complie       F9
run           F10
complie+run   F11
Copy Line     Ctrl+E
Delete Line   Ctrl+D
Format        Ctrl+Shift+A

## STL

1. `algorithm`库
2. using namespace std;

## File Operator

within DEAL.cpp

1. 声明`*fp`
2. fopen
3. fgets()/fscanf()/fprintf()
4. fclose