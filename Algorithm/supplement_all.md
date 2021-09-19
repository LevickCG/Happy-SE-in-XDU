<center><font size=6> 算法补充1</font></center>
1.Draw the recursion tree for
$$
T(n)=4T(\lfloor n/2 \rfloor)+cn
$$
where e is a constant,and provide a tight asymptotic bound on its solution. Verify your bound by the substitution method.

> Answer: $\theta(n^2)$

2.Given the following recurrence:
$$
T(n)=4T(n/2)+n^2lgn
$$
give an asymptotic upper bound for this recurrence.

> Answer:  $O(n^2(lgn)^2)$



<div style="page-break-after: always";></div>



<center><font size=6> 算法补充2</font></center>

1、归并排序在最坏最好和平均的时候时间复杂度分别是多少？

> Best: $O(nlgn)$
>
> Worst: $O(nlgn)$
>
> Average: $O(nlgn)$

2、判断归并排序的空间复杂度是 O(1)？ 

> False. It’s $O(n)$

3、优先队列的 Extract maximum element 算法的时间复杂度（O 表示） 

> $O(lgn)$.

4、堆排序在最坏最好和平均的时候时间复杂度分别是多少 ？ 

> All are $O(nlgn)$.
>
> Best case is controversial  $O(nlgn) \ \ \& \ O(n) $

5、堆排序空间复杂度是 O(1)？ 

> True.

6、堆排序的适用情况？（写两个即可） 。排序考点：时间复杂度、空间复杂度、稳定性、适用场景

> 1.n比较大
>
> 2.部分排序（前n大，前n小）
>
> 3.实时应用 (real-time application)

7、构建大顶堆的算法 Maxheapify 时间复杂度是 ，构建一个大顶堆 Build-Max-Heap 算法的时间复杂度  

> Maxheapify: $O(lgn)$
>
> Build-Max-Heap: $O(n)$.  Proof seen at P159 of the textbook. ($3_{rd}$ edition)

8、快速排序在最坏最好和平均的时候时间复杂度分别是多少？ 

> Best: $O(nlgn)$
>
> Worst: $O(n^2)$
>
> Average: $O(nlgn)$

9-13、判断算法的稳定性：归并排序、堆排序、快速排序、直接插入排序、计数 排序。 

>  Respectively :  stable, unstable, unstable, stable, stable.



14、如果待排序的元素有相同的值，那么快速排序需要比较多少次？

> Suppose we have n numbers with the same value. We have to compare  $\frac{n(n-1)}{2}$ times using quick sort.

15、写出快速排序最坏情况的两种实例

> Worst cases: Already sorted  (descending or ascending) or all the same numbers.
>
> e.g. `1,2,3,4,5,6` or `2,2,2,2,2,2,`

<center><font size=5>基本排序算法总结</font></center>

| **排序算法**     | **平均时间复杂度** | **最坏时间复杂度** | **最好时间复杂度** | **空间复杂度** | 原地 | **稳定性** |
| ---------------- | ------------------ | ------------------ | ------------------ | -------------- | :--: | ---------- |
| **直接插入排序** | O(n²)              | O(n²)              | O(n)               | O(1)           |  是  | 稳定       |
| **快速排序**     | O(nlogn)           | O(n²)              | O(nlogn)           | O(logn)        |  是  | 不稳定     |
| **堆排序**       | O(nlogn)           | O(nlogn)           | O(nlogn)           | O(1)           |  是  | 不稳定     |
| **希尔排序**     | O(nlogn)           | O(ns)              | O(n)               | O(1)           |  是  | 不稳定     |
| **归并排序**     | O(nlogn)           | O(nlogn)           | O(nlogn)           | O(n)           |  否  | 稳定       |
| **计数排序**     | O(n+k)             | O(n+k)             | O(n+k)             | O(n+k)         |  否  | 稳定       |
| **基数排序**     | O(N*M)             | O(N*M)             | O(N*M)             | O(M)           |  否  | 稳定       |

<div style="page-break-after: always;"></div>




<center><font size=6> 算法补充3</font></center>

1、用括号写出矩阵链乘的最终形式

a) <3, 5, 2, 1,10>     

> Answer: $((A_1(A_2A_3))A_4)$

b) <2, 7, 3, 6, 10> 

> Answer:  $(((A_1A_2)A_3)A_4)$

c) <10, 3, 15, 12, 7, 2> 

> Answer: $(A_1(A_2(A_3(A_4A_5))))$

d) <7, 2, 4, 15, 20, 5> 

> Answer: $(A_1(((A_2A_3)A_4)A_5))$

**BTW. Running time of the algorithm is $\theta(\frac{n(n-2)(n-3)}{6})$** . e.g. case (a) will iterate for 10 times.

2、写出矩阵链乘的递推表达式 (important)

> $$m[i, j]=\left\{\begin{array}{ll}
> 0 & \text { if } i=j \\
> \underset {i \leq k} \min \left\{m[i, k]+m[k+1, j]+p_{i-1} p_{k} p_{j}\right\} & \text { if } i<j
> \end{array}\right.$$

3、判断题：$A_i, A_{i+1}, …, A_j $被完全加括号的开销等于计算矩阵 $A_{[i..k]}$与计 算矩阵 $A_{[k+1..j]}$的开销之和。 

> False.     $p_{i-1}p_{k}p_{j}$ missing.

4、矩阵链乘算法 matrix_chain_order 时间复杂度是多少 

> $O(n^3)$

5-6、矩阵链乘需要两个辅助数组 m 数组和 s 数组，分别写出两个数组的作用。 

(矩阵链乘最优子结构，子问题个数)

> m数组: 计算$A_{[i…j]}$所需要最少乘法次数。
>
> s数组：记录$A_i,A_{i+1},...,A_j$最优分裂位置，即  k 的值

7、写出 LCS 算法的递推式。 

（LCS最优子结构，子问题个数）

> $$c[i, j]=\left\{\begin{array}{ll}
> 0 & \text { if } i=0 \text { or } j=0 \\
> c[i-1, j-1]+1 & \text { if } i, j>0 \text { and } x_{i}=y_{j} \\
> \max (c[i, j-1], c[i-1, j]) & \text { if } i, j>0 \text { and } x_{i} \neq y_{j}
> \end{array}\right.$$

8、若两个序列的长度分别是 m、n,则算法 LCSlenth 时间复杂度是多少？（用 O） 子问题个数是多少个？（可以用θ） 

> Both $O(mn)$

9、outputLCS 算法的时间复杂度。 

> O(m+n)

10、max_sum 的递推式。 最优子结构

> $b_{[i]}=max(b_{[i-1]}+a_{[i]},a_{[i]})$            $1\leq i \leq n$

<div style="page-break-after:always";></div>



<center><font size=6> 算法补充4</font></center>



根据上机第三次第一题:

1.写出分数背包和01背包属于哪一类算法？贪心还是动态规划等

> 分数背包：贪心
>
> 01背包：动态规划

2.分别写出分数/01背包解决这个题目最后的和值

> 分数背包：163
>
> 01背包：155

3.若得到分数背包的最优解需要满足什么条件

> 根据价值与容量的比值从高到低对物品进行选择。

4.写出01背包算法的递推表达式

>  $c[i, w]=\left\{\begin{array}{ll}
>  0 & \text { if } i=0 \text { or } w=0 \\
>  c[i-1, w] & \text { if } w_{i}>w \\
>  \max \left(c\left[i-1, w-w_{i}\right]+v_{i}, c[i-1, w]\right) & \text { if } i>0 \text { and } w \geq w_{i}
>  \end{array}\right.$

5.01背包算法的时间复杂度，输出背包的时间复杂度

> $O(nW)$, n 为物品数量，W为背包的容量
>
> $O(n)$

第三次上机的第三个小题：
1.笔算从A到各个顶点的值计算

|       | B        | C        | D        | E        |
| :---- | :------- | -------- | -------- | -------- |
| init  | $\infty$ | $\infty$ | $\infty$ | $\infty$ |
| pass1 | -1       | 2        | -2       | 1        |
| pass2 | -1       | 2        | -2       | 1        |
| pass3 | -1       | 2        | -2       | 1        |
| pass4 | -1       | 2        | -2       | 1        |
|       |          |          |          |          |
在pass1就收敛了。

2.写出上题采用的是哪个算法，为什么？

> Bellman-ford, 可检测是否存在负权值回路。
>
> （因为原图含有负权值边，Dijkstra算法不适用）

3.简述采用算法的核心思想以及时间复杂度

> 每次对所有边进行松弛（relaxation）操作，做 V-1次。
>
> O(VE)

<center><font size=4 >Graph algorithm Run Time Sum-up</font></center>

|               Dijkstra                | Bellmam-Ford | Floy-wallshall |             Johnson              |      |
| :-----------------------------------: | :----------: | :------------: | :------------------------------: | ---- |
| $\theta (VT_{extractmin}+ET_{DecreaseKey})$ |   $O(VE)$    |    $O(V^3)$    | $\theta (T_{Bellman-ford}+VT_{Dijkstra})$ |      |
|  |              |                |||

where V is the size of vertex set and E is the size of the edge set.

第三次上机的第四个题目
1.写出弗洛伊德 Warshall的递推表达式$D_{ij}^{(m)}$

> $$
> D_{ij}^{(m)}=min(D_{ik}^{(m-1)}+a_{kj}),\ \ \ \ \ m=1,2,3,...,n-1
> $$


2.Johnson算法在边少的情况效率是高还是低

> 高。


<div style="page-break-after:always";></div>





<center><font size=6> 期末复习</font></center>

> - 判断题 (8个[往年])，最基本的概念，分布广、均匀。绝对化词语
> - 递归树求解递推式
>   - 树根，树高（最左侧），每层开销（最右侧）；叶子节点T(1)万金油
>   - 根据树计算得到递推式。正确使用等比、等差公式
>   - 证明（verify your answer)。替换法，注意低阶项
> - 求解递推式（方法不限）。替换（推荐）、主定理（推荐）、递推式。注意不要算错，尽量给出过程，得过程分
> - 排序
>   - 时间复杂度、空间复杂度、稳定性、适用条件
> - 计算&问答，题型多变
>   - case1: 计算题，书上例题（装配线、LCS、背包）
>     - DP， Greedy. 
>     - 矩阵链乘，计算m，s数组（一个示例，后给最终结果），括号位置。（最后做）
>     - LCS，图，箭头方向，根据走向求LCS
>   - case2: 问答题。写清楚重点，写出序号
>     - 分治，三个步骤
>     - DP，四个步骤
>     - 贪心的思想
>     - 回溯，关键核心代码记忆
>   - case3: 算法设计，不能写伪代码
>     - 往年例：多段图，左侧源点到右侧终点。DP实现，转换成装配线。
>     - 技巧步骤：e.g.DP.写出DP思想，本题设计思想，写递推表达式，相应字母含义，对多种情况进行解释说明。总结一下。
>   - 丢分点：
>     - 错当成计算题，给出了一个具体答案。
>     - 惯性思维。（最长，最短，最大，最小）
> - 综合性问题
>   - case1: 综合性问题，一类问题多个算法结合考查
>   - case2: 一个（一类）算法多问，先计算，后说明，再简答
>   - case3: 上机题代码

时间分配：

Time consuming: 递归树(复杂递归树)，计算题(矩阵链乘)。	

回溯法核心代码，背。各种经典算法的递推表达式非常重要。

<div style="text-align: right";>
<i>Summarized by Leivck Cheng</i> 
</div>
