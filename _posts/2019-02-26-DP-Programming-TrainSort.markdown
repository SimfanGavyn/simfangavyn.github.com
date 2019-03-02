---
layout: post
title:  "Dynamic Programming (一)"
date:   2019-02-26 00:00:00 +0900
category: Programs
site.url: ~/Destop/myblog
---
1. 背景
<br>
既然讲到了DP问题，就不得不提greedy和D&C。
<br>
Greedy，也称为贪婪算法，是指，将大问题分解成小问题，并且每次都以局部最优解来解决当前小问题，最终实现用最优解来解决大问题的结果。Greedy的弊端是在于局部最优解不一定就是全局最优解。因此也出现了与Greedy相关的算法正确性证明：_Staying ahead_ 和 _Exchange argument_。这两种方法是常见的证明Greedy是Optimal的方法。
<br>
<br>
D&C, devide and conquer, 也称为分而治之。类似的，也是将大问题分解成小问题，但是每个大问题与小问题间的解决方法基本一致，而且重点是在于分解成小问题后，再combine成大问题的过程。典型的例子就是 _Merge Sort_ 和 _中位数问题_。在D&C问题中，一个常用的降低时间复杂度的方法就是使用二分搜索树来将n(n^2)降低成n(nlog)。

2. 什么是DP问题
<br>
那，DP问题，有和上面的问题有什么不同呢。DP也是一个解决子问题的算法，它的子问题之间有很高的重复利用率。举个例子，在我们一开始学习递归算法的时候，会让我们求Fibonacci sequence。
``` c++
f(0) = 1;   // base case
f(1) = 1;   // base case
f(n) = f(n-1) + f(n-2)
```
在这种情况下，如果求f(5)的话，f(2)就会被重复计算了3次，这样子的重复计算很影响时间复杂度。因此，我们可以把需要被重复利用的数据给保存下来，保存在一个table里面，需要的时候就拿出来，避免了重复计算。
<br>
而这样一种，使用已有数据来解决递归问题的方法，就叫做DP。

3. 案例描述
<br>
[题目描述在这里](https://ucsb.kattis.com/problems/trainsorting)
<br>
也就是说，给你一串数列互不重复的input[n]和数列的长度n，你从前往后读，读到每一个数据的时候，可以选择加入或者不加入到按从大到小顺序的output[]中。如果加入的话，只能从已有的前面或者后面加。如果不加入的话，则读取下一个。Task是求的output数列最长有多长。
```bash
Input：
5
3 2 1 4 5
Output:
5
```
4. 解决方案及代码
<br>
首先，我们需要分析，如果我们从左到右，每一次都能拿出以input[i]为首的最长递增子序列和最长递减子序列，那我们就可以比较以input[i]为链接点的最长序列的长度。
```
如取A[0],则有321和345，因此，最长序列长度为3 + 3 — 1 = 5
取A[1],则有21和245，因此，最长序列长度为2 + 3 — 1 = 4
取A[2],则有1和145，因此，最长序列长度为1 + 3 — 1 = 3
取A[3],则有4和45，因此，最长序列长度为1 + 2 — 1 = 2
取A[4],则有5和5，因此，最长序列长度为1 + 1 — 1 = 1
```
进行比较则知道，应该以3作为链接点。至于怎么来获得以input[i]为首的最长递增子序列和最长递减子序列，可以参考这篇关于[LIS和LDS](https://blog.csdn.net/ltrbless/article/details/81318935)的DP基础应用。最终代码如下：
<br>
```c++
int main(){
    int num;
    cin >> num;
    int increase[num], decrease[num], dp[num], arr[num], ans = 0;
    for (int i = 0; i < num; i++) {
        cin >> arr[i];
    }
    for (int i = num - 1; i >= 0; i--) {
        increase[i] = 1;
        decrease[i] = 1;
        for (int j = num - 1; j > i; j--) {
            if (arr[j] < arr [i]) {
                increase[i] = max(increase[i], increase[j] + 1);
            } else if (arr[j] > arr[i]) {
                decrease[i] = max(decrease[i], decrease[j] + 1);
            }
        }
        dp[i] = increase[i] + decrease[i] - 1;
        ans = max(dp[i], ans);
    }
    cout << ans << endl;
    return 0;
}
```
<br>
<p align="right"><font size="2" color="grey">Done at 02.26.2019</font></p>
