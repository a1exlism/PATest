# Preface(前言)

记录coding过程中遇到的相关知识点
按两本书进度来写, 便于查找

## Requirement

>Chen Yue
首先有十分钟拿下乙级15分题的本事。
然后要能在半小时内完成乙级20分题1道。
接下来训练自己45分钟完成乙级25分题。
这时你有了2.5小时满乙级的本事！
下面改做甲级英文题。
要有用十分钟读完4题的本事。
20分钟写完20分题并至少过样例。
1小时内写完2道25分题并至少过样例。
1小时写完最难题并至少过样例。
此时你应该有70分左右了，
最后半小时拚命过90吧！

## 算法笔记

### Chapter-3

#### B1036 隐式类型转换

```cpp
int z, y, x = 3;
y = round(x/2);   //  1
z = round(x/2.0); //  2
```

#### Codeup1928 日期间隔

日期计算方式思路很好: day by day

#### B1022/-X 进制转换

做法都是先`%`后`/`

* 十进制转D进制 do while格式
* D进制转十进制 while格式

看了一下1009的错误才知道Runtime Error的问题, 数组开的太小导致越界
[Runtime Error Refer](https://blog.csdn.net/user_longling/article/details/22488905)

#### B1009 倒序输出

```c++
char * fgets ( char * str, int num, FILE * stream );
//  num: 最大输入数量
//  strem: 输入流
```

* 实际读入的数据为num-1(考虑到`\n`和`\0`)
* gets函数不可使用, 换成`fgets(str, str_len, stdin)`
* fgets在最后会保留`\n`

hack code:
```c++
char str[101];
fgets(str, 101, stdin);
str[strlen(str)-1] = '\0';
```

#### 其他教训

* 输出百分号: `%%` 
* `strlen(str)/2`至少为str中值, arr下标以0为开始 
* 既定内存可以更大, 数组内存过少导致partitial accept
* for循环会让结构更清晰


[Refer](https://bbs.csdn.net/topics/310214704)

## 上机指南

### Chapter\-3

#### B1011 A+B>C

主要问题在于题目中的范围: `[-2^31, 2^31]`
超过了int, 所以需要用`long long`并用`lld`来scanf

#### B1026 程序运行时间

主要考察printf输出`格式`问题
还有一个就是考试过程中`禁用round`函数,替代方案如下

```c++
z = (x + 0.5) / d;
```