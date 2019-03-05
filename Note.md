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

### Chapter 3

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

### 3.1 基础模拟

#### B1011

主要问题在于题目中的范围: `[-2^31, 2^31]`
超过了int, 所以需要用`long long`并用`lld`来scanf

#### B1018

scanf的`%c`会读取换行符`\n`需要用getchar()吸收空格

#### B1026 程序运行时间

主要考察printf输出`格式`问题
还有一个就是考试过程中`禁用round`函数,替代方案如下

```c++
z = (x + 0.5) / d;
```

#### A1046

1. 数组定义需要注意`初始化`, 否则数据不准确
2. 注意运行时间, 减少循环.

#### A1065

1. long long范围: `[−2^63,2^​63​)`, scanf使用`%lld`
2. 边界判定取余操作max:2^63*2-2 % 2^64 = -2`右边界`, 左边界则为0
3. bool格式运用;

#### B1010

1. 未知数量的数据输入, 利用scanf返回值判断结束;
2. EOF:-1, windows: `ctrl-z`, mac: `ctrl-d`;
3. 递推最好以1为单位, 否则多余的考虑内容过多;
4. 在scanf和输入EOF上花了比较多的时间

#### A1002

1. 英文单词不认识, 题意理解不透彻;
2. 最好打草稿来理解题目陷阱;
3. 不够熟练.

### 3.2元素查找

#### B1041

1. 结构体定义和`typedef`;
2. scanf和结构体数组搭配;
3. PS: 利用string居然不给过;
4. 可以简化为单一循环, 不过预先需要给个大结构体数组;

#### B1004

1. 寻找max/min类型: init value可以设置为边界外部.
   Example: [0-100], min = 101, max = -1;
2. PAT的判断数据过少导致特殊情况也能返回答案正确

#### B1028 日期比较

1. 大小范围比较的🙅错误‍示范: `if(a<x<b)`;
2. 利用这个方案进行简化, (暂时不清楚是否有特殊问题;
   >BETTER: x = yy \* 10000 + mm \* 100 + dd;
3. 在合法性比较上缺少了对极端情况的判断, 所有数据均不合格
4. 题解上的日期判断也可以参考一下:

```cpp
bool MoreEqu(person a, person b) {
  if(a.yy != b.yy) return a.yy > b.yy
  else if(a.mm != b.mm) return a.mm > b.mm;
  else return a.dd > b.dd;
}
```

#### A1011

1. 赌博倍率题, 难点是英文理解; A类简单题

#### A1006

1. 和B1028基本一样; 另一种方式是转化为秒做, 不过感觉没有必要;