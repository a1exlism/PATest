# Preface(前言)

记录 coding 过程中遇到的相关知识点
按两本书进度来写, 便于查找

## Requirement

> Chen Yue
> 首先有十分钟拿下乙级 15 分题的本事。
> 然后要能在半小时内完成乙级 20 分题 1 道。
> 接下来训练自己 45 分钟完成乙级 25 分题。
> 这时你有了 2.5 小时满乙级的本事！
> 下面改做甲级英文题。
> 要有用十分钟读完 4 题的本事。
> 20 分钟写完 20 分题并至少过样例。
> 1 小时内写完 2 道 25 分题并至少过样例。
> 1 小时写完最难题并至少过样例。
> 此时你应该有 70 分左右了，
> 最后半小时拚命过 90 吧！

## type size

- int: -2^31 ~ 2^31-1 | 2\*10^9
- long long: -2^63 ~ 2^63-1 | 9\*10^18
- float: 2^128 精度 6~7 位
- double: 2^1024 精度 15~16 位
- char: -128 ~ 127

## 文件处理

- in File_operator

1. 注意在 windows 中用反斜杠, 加转义`\\`;
2. scanf/printf `f`prefix

## Chapter 3

### B1036 隐式类型转换

```cpp
int z, y, x = 3;
y = round(x/2);   //  1
z = round(x/2.0); //  2
```

### Codeup1928 日期间隔

日期计算方式思路很好: day by day

### B1022/-X 进制转换

做法都是先`%`后`/`

- 十进制转 D 进制 do while 格式
- D 进制转十进制 while 格式

看了一下 1009 的错误才知道 Runtime Error 的问题, 数组开的太小导致越界
[Runtime Error Refer](https://blog.csdn.net/user_longling/article/details/22488905)

### B1009 倒序输出

```c++
char * fgets ( char * str, int num, FILE * stream );
//  num: 最大输入数量
//  strem: 输入流
```

- 实际读入的数据为 num-1(考虑到`\n`和`\0`)
- gets 函数不可使用, 换成`fgets(str, str_len, stdin)`
- fgets 在最后会保留`\n`

hack code:

```c++
char str[101];
fgets(str, 101, stdin);
str[strlen(str)-1] = '\0';
```

- 若要添加 len, 则先 len=strlen-1, 然后`str[len]='\0'`

### 其他教训

- 输出百分号: `%%`
- `strlen(str)/2`至少为 str 中值, arr 下标以 0 为开始
- 既定内存可以更大, 数组内存过少导致 partitial accept
- for 循环会让结构更清晰

[Refer](https://bbs.csdn.net/topics/310214704)

## 3.1 基础模拟

### B1011

主要问题在于题目中的范围: `[-2^31, 2^31]`
超过了 int, 所以需要用`long long`并用`lld`来 scanf

### B1018

scanf 的`%c`会读取换行符`\n`需要用 getchar()吸收空格

### B1026 程序运行时间

主要考察 printf 输出`格式`问题
还有一个就是考试过程中`禁用round`函数,替代方案如下

```c++
z = (x + 0.5) / d;
```

### A1046

1. 数组定义需要注意`初始化`, 否则数据不准确
2. 注意运行时间, 减少循环.

### A1065

1. long long 范围: `[−2^63,2^​63​)`, scanf 使用`%lld`
2. 边界判定取余操作 max:2^63\*2-2 % 2^64 = -2`右边界`, 左边界则为 0
3. bool 格式运用;

### B1010

1. 未知数量的数据输入, 利用 scanf 返回值判断结束;
2. EOF:-1, windows: `ctrl-z`, mac: `ctrl-d`;
3. 递推最好以 1 为单位, 否则多余的考虑内容过多;
4. 在 scanf 和输入 EOF 上花了比较多的时间

### A1002

1. 英文单词不认识, 题意理解不透彻;
2. 最好打草稿来理解题目陷阱;
3. 不够熟练.

## 3.2 元素查找

### B1041

1. 结构体定义和`typedef`;
2. scanf 和结构体数组搭配;
3. PS: 利用 string 居然不给过;
4. 可以简化为单一循环, 不过预先需要给个大结构体数组;

### B1004

1. 寻找 max/min 类型: init value 可以设置为边界外部.
   Example: [0-100], min = 101, max = -1;
2. PAT 的判断数据过少导致特殊情况也能返回答案正确

### B1028 日期比较

1. 大小范围比较的 🙅 错误 ‍ 示范: `if(a<x<b)`;
2. 利用这个方案进行简化, (暂时不清楚是否有特殊问题;
   > BETTER: x = yy \* 10000 + mm \* 100 + dd;
3. 在合法性比较上缺少了对极端情况的判断, 所有数据均不合格
4. 题解上的日期判断也可以参考一下:

```cpp
bool MoreEqu(person a, person b) {
  if(a.yy != b.yy) return a.yy > b.yy
  else if(a.mm != b.mm) return a.mm > b.mm;
  else return a.dd > b.dd;
}
```

### A1011

1. 赌博倍率题, 难点是英文理解; A 类简单题

### A1006

1. 和 B1028 基本一样; 另一种方式是转化为秒做, 不过感觉没有必要;

### A1036

1. 理解 corresponding 含义

## 3.3 Graphic 图形输出

### **B1027**

1. 花了整整 50min, 对于 row 的计算没有把握好;

### A1031

1. 做了这题才想到 B1027 与此题非常相似, 在算临界点的循环中若不符合条件, 应进行`后悔`操作.也就是`回退数据`!

## 日期处理

### codeup 1928

1. 日期处理很麻烦, 一般就放弃了= =

## **进制转换**

### B1022

1. while...do 模式导致意外情况: A+B = 0

### B1037

1. Simple-找零问题, 全化作基础单位进行计算, 之后单位化.

### A1019

1. 除零会导致`floating point exception`;
2. 测试点 3,运行超时 比较懵逼 0307; 改了进制转换的算法之后问题消失, 蒙蔽.

### A1027

1. 很大的障碍, 英语题意理解错误导致没看懂;
2. 设置字典 dict 进行字母映射;
3. 0 的控制以 string 类型输出, 需要注意 x 个字母必须分配`x+1`空间, `str[x]='\0';`.

### A1058

1. 与前面几个类似, 考察加法`进位`, 简单题.

## 字符串处理

### WARNING: 关于结束符`\0`

0. `scanf("%s", str)`遇到空格也会停止接受数据;
1. gets/scanf 在结尾会`自动去掉`换行符`\n`并添加`\0`作为结尾, 相应的空间-1;
1. fgets()读取单行数据, **遇到换行结束读取**, `保留`换行符`\n`, 并添加`\0`作为结尾, 相应空间-2(算上`\n`);
   如下为 fgets => gets

   > str[strlen(str)-1] = '\0';

1. puts/printf 通过识别`\0`作为输出结尾.
1. C++11 已经弃用 gets, 转为`fgets`
   > fgets(str, strlen(str), stdin/filepointer);

REFER-LINK: [C 语言——输入输出函数](https://www.cnblogs.com/feipeng8848/p/7273939.html)

## string.h

> strlen(str)a;

- `\0`为结尾

> strcpy(str_to, str_from);

- `\0`也会一同 copy

> strcat(str_main, str_sub);

- concat 字符串连接, main 的结束符自动删除

> memset(str|intA, val, sizeof(str));

- 数组初始化, int: `0/-1`

ATTENTION: int 类型的数组初始化只能为 0, 其他数字写上去不报错但不`执行`

## StringIO | sscanf 和 sprintf 的使用

1. 格式化内容赋值

### B1006

1. 只需要正确处理求商取余即可, 简单题

### B1021

1. 字数统计相关, 需要用到 char 数组;
2. char 数组比较相关代码: `str[i] == '0'`, 顺序相关:0-9, a-z, A-Z;
3. 小写转大写: X 代表'X', 转换:`X-'A'+'a'`, 依据相对位置;

### B1031

1. 审题不清导致完全走偏方向;
2. 判负情况在循环状态下需要一个外部变量`Line 15`;

### B1002

1. 较长的 int 连续输入处理`%s`;
2. 十进制的数据按位分割`split`处理;
3. 字典包处理, 二维数组.

### B1009

1. WARNING, 这里需要强调一下 scanf 中的%s 和%c 的结束标志区别;

具体如下:

- %s 以空格和换行作为读取`结束`标识符;
- %c `可以读入`空格和换行, 这也是为什么某些题目需要 getchar 来消除空格和回车的原因;

2. 2nd 判断需要添加对`'\n'`的检查

### A1061/B1014

1. 主要是语意问题, character/capital.etc
2. 格式化输入: `%02d` prefix 为 0, 2 位数

### B1048

1. 主要难点在于输入是从前往后, 但是数据处理从后往前, 需要设计 reverse 函数以及合集 str 来进行两次 reverse;
2. index 从 0 开始的奇偶颠倒;

### A1001

1. 简单题, 注意点: 001 输出为`%03d`;
2. 另一种方式为数组 reverse, %10 /10 交替, 可以实现 10^6 以上数据的操作;

### A1005

1. 简单题, 与 A1001 类似, 借用数组 reverse 和字典进行输出;
2. fgets 读取之后需要`添加结束符`;
3. 判零情况大部分需要和 do...while 结合;
4. 递归本身就带有 reverse 性质, 可以使用递归来解决问题, 见 A1005_recursion.cpp(然而正确输出但是 oj 全错...)

### A1035

1. 简单题, 好像没啥注意点.

### A1077

思路一开始就有, 但是实现的过程有点坎坷

1. 一行内`有空格`, 所以只能用 fgets 获取 str;
2. 比较依然是从右往左, 所以需要 reverse;
3. 需要一个对照组(common string), 作为最终的输出结果, 每次输入与其进行比较, 缩短 comstr;

### A1082

做的一头包, 参考了书, 通过分割片段实现`千百十`的输出;

1. 设计两个游标 left,right 以 4 为单位从高位移向低位, 在 0-3 循环中输出千百十;
2. 零的输出有两个要点, 一个是 2+连续零的出现只能输出一个`ling`, 而且没有修饰, 另一个则是亿万的判断上需要注意例如`10000800`;
3. 亿万的输出条件需要打草稿, 代码考虑了最高 12 位的数字判定;

## Chapter 4.1 排序

### A1062

1. 题目看半天英语真菜;
2. 在不超范围情况下, 尽可能分配大的空间, 否则`段错误`|`运行时错误`;
3. 考了 STL sort 含义, 如下

```cpp
sort(firstAddr, lastAddr[not include][, cmp]);
```

cmp 细分为:

- ASC 升序

  > cmp(a, b) { return a < b;}

- DESC
  > cmp(a, b) { return a > b;}

### insert sort

之前没仔细想过, 做的比快排还累...如下:

1. 实质每次更新就是一次`swap`过程;
2. 插入这个过程需要考虑到数据的暂存问题, 所以每次的更新循环从后往前走;
3. update 的节点`arr[i]`需要暂存, 而且不能放在比较环节, 会被直接取代;
4. **比较的节点应该是前一个节点 arr\[j-1\]**而不是被取代的那个;

### A1025

1. 总体来说, 两个排序, 方式一样.
2. Ranking 的算法方案, 同分同名次. [QuickLink-Gist](https://gist.github.com/a1exlism/f5e3affd5fd3f68125b09a7b897ca9b6)
3. `13位左右`的数字, 似乎没办法进行大小比较, 至少在 PAT 的样例中无法通过(样例 4), 跟网上[另一个](https://www.windsings.com/posts/c61b8460/)同学情况一样;但是[柳婼](https://www.liuchuo.net/archives/2180)的代码用了 vector 之后发现可以通过, 等看到 STL-vector 搞一下.

### 4.2/3 散列/分治

- Hash && Recursion(划分小问题)

用到案例: 全排列, N 皇后问题.

1. HashTable 的建立, 数组设置按位 setup;
2. 递归核心: 找到临界条件, 只看上下文; File: `recursion_full_permutation.cpp`
3. N 皇后问题实质上也是排列组合问题, 在每次 generate 过程中需要判断是否规范.

### 4.4 贪心

局部最优解,最大收益问题.

#### 简单贪心

B1020,B1023, 记得`局部最优`即可

#### 区间贪心

区间不包含问题, example:

> (1,3), (3,5) 包含 (2,4)

with `interval_include.cpp`

### 4.5 二分

#### 设计目的

快速找到满足条件的点.

#### 条件

存在 x=>y, x 和 y 成正/负相关.

#### 注意点

1. 返回的结果范围;
2. CONDITION 条件的处理,即 left,right 更新的值;
3. while 的判定条件,由`2`决定;
4. 返回值,这个根据前面的 while 判定`3`决定.

#### Source

- Base template:
  `Common\ Codes/Binary_search_exact.cpp` 找出直接满足`等价`条件的 pos

- Enhanced template:  
  `Common\ Codes/Bianry_search_1st_match.cpp` 找到`第一个`满足条件的 pos,可演化出最后一个满足条件的 pos

  **先 right=mid,后 left=mid+1**

- Extend Question:
  1. `BS_approximate_value` 计算近似值 x;
  2. `BS_water_load` 装水问题;
  3. `BS_stick_cutting` **木棒切割问题**.
