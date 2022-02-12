# 计组II Solution Manual

## 第六章

### 习题6.5

某CPU内有5级指令流水线，每级的处理时间(包括级间缓冲延迟)为10ns,5ns,5ns,10ns,5ns。
(1）当执行1000条指令时，该流水线的吞吐率和加速比为多少?
(2）若要改进该流水线的性能，可对流水线做何改造?改造后的流水线吞吐率可达到多少?

解：

(1):

​	吞吐率：$TP=\dfrac{n}{T_{流水}}=\dfrac{1000}{\sum\limits_{i=1}^{5}\Delta t_{i}+(1000-1) \times \Delta t_{max}}=99.75 \ MIPS$

​	加速比：$S=\dfrac{T_{顺}}{T_{流水}}=\dfrac{1000 \times \sum\limits_{i=1}^{5}\Delta t_{i}}{\sum\limits_{i=1}^{5}\Delta t_{i}+(1000-1) \times \Delta t_{max}}=3.49$

(2):

​	:one:将两瓶颈段变为两端，每段5ns，让各段时间相等

吞吐率：$TP^{'}=\dfrac{n}{T_{流水}^{'}}=\dfrac{1000}{7\times \Delta t+(1000-1) \times \Delta t}=199.8 \ MIPS$

加速比：$S^{'}=\dfrac{T_{顺}^{'}}{T_{流水}^{'}}=\dfrac{1000 \times 7\times \Delta t}{7\times \Delta t+(1000-1) \times \Delta t}=6.985$

:two: 将10ns瓶颈两两重复设置

结果与:one:同。



### 思考：“细分瓶颈”和“重复瓶颈过程”的性能指标是否相同？

![bottleneck-solving](./img/bottleneck-solving.png)

### 习题6.9

9．在一台具有5个功能段的线性流水线处理机上计算: $\sum\limits_{k=1}^{8}X_{k}$   。每个功能段均为1个时钟周期，设时钟频率为100MHz。计算实际吞吐率、实际加速比和实际效率。

解：

计算过程如下：

<img src="./img/image-20200930220239583.png" alt="image-20200930220239583" style="zoom: 40%;" />

时空图如下：

![image-20201003164213732](./img/image-20201003164213732.png)

$\Delta t=\dfrac{1}{f}=10\ ns,T_{流水}=18\Delta t=180\ ns, T_{顺}=5\times 7\times \Delta t=350ns$

$TP=\dfrac{n}{T_{流水}}=38.9\ MIPS,\ S=\dfrac{T_{顺}}{T_{流水}}=1.944, E=\dfrac{n\times \Delta t}{T_{流水}}=38.9\%$

### 习题6.10

​	在一条具有6个功能段静态多功能的流水线上，计算$\sum\limits_{k=1}^{8}(X_{k}\times Y_{k})$，其中,加法用12、3和6功能段,乘法用1、4、5和6功能段。计算吞吐率、加速比和效率。

解：

计算过程

<img src="./img/image-20201003171000214.png" alt="image-20201003171000214" style="zoom:50%;" />

时空图：

![image-20201003170034544](./img/image-20201003170034544.png)

设每段所用时间为$\Delta t$

吞吐率：$TP=\dfrac{n}{T_{流水}}=\dfrac{15}{26\Delta t}$

加速比：$S=\dfrac{T_{顺}}{T_{流水}}=\dfrac{15\times 4\Delta t}{26\Delta t}=2.307$

效率：$\dfrac{15\times \Delta t}{26\Delta t \times 6}=38.5\%$

## 第七章

### 习题7.2

芯片资料连接: [21256_1](./img/21256_1.png), [21256_2](./img/21256_2.png), [2164](https://blog.csdn.net/xiong_xin/article/details/100636937), [6264]( [https://baike.baidu.com/item/Intel6264%E8%8A%AF%E7%89%87/5162001?fr=aladdin](https://baike.baidu.com/item/Intel6264芯片/5162001?fr=aladdin)), [62 256](https://wenku.baidu.com/view/45aaf0a8f78a6529647d53f1.html)<br/>

00000H--3FFFFH -> 256K<br/>
6264是8K×8b，故需要256K÷8K=32片<br/>
62256是32K×8b，故需要256K÷32K=8片<br/>
2164是64K×1b，故需要256K÷64K×8=32片<br/>
21256是256K×1b，故需要256K÷256K×8=8片<br/>

### 习题7.3
PC/XT不需要奇偶分体(page230)，但8086需要奇偶分体。00000H--03FFFH共16k内存<br/>
PC/XT:<br/>
<img src="./img/7.3 1.jpg" alt="7.3 1" ><br/>
8086:<br/>
<img src="./img/7.3 2.jpg" alt="7.3 2" >

### 习题7.5
B-4=7<br/>
7BFFF(H)个字节=495KB

### 习题7.6
该芯片地址为1?00  ???X  XXXX  XXXX  XXXX，其中第一个问号"?"代表A18，它可以取1或0<br/>
后三个问号"???"代表A15,A14,A13,可以是000/100/110/111<br/>
当A18是0时，Y0为80000H--81FFFH；Y4为88000H--89FFFH；Y6为8C000H--8DFFFH，Y7为8E000H--8FFFFH<br/>
当A18为1时，Y0为C0000H--C1FFFH；Y4为C8000H--C9FFFH；Y6为CC000H--CDFFFH，Y7为CE000H--CFFFFH

### 习题7.7
需要4片6264，下面两片6264的连接方式和上面的类似<br/>
<img src="./img/7.7.JPG" alt="7.7" ><br/>
参考了以下内容(来自书本的232页)<br/>
<img src="./img/7.7-page 232.jpg" alt="7.7-page232" ><br/>
另一个解决方案，来自老师的ppt，注意这两个解决方案略有差别<br/>
<img src="./img/7.7-1 .jpg" alt="7.7-1 " ><br/>

### 习题7.16
1. 1111 110X XXXX XXXX XXXX，其中X表示A0到A12，故占用内存地址为FC000H--FDFFFH<br/>
2.需要两片该SRAM芯片。0011 00?X XXXX XXXX XXXX 其中X表示A0到A12，A13是"?"表示片选信号<br/>
  <img src="./img/7.16 2.JPG" alt="7.16 2" >

### 习题7.21
设命中率为x。17.5ns = (1-x)*100ns +10ns，解得x=92.5% 选D

### 习题7.22
(1)总共20位，每块1KB->块内地址10位；每组4块->组内块号2位；分为2组->区内组号1位；20-10-2-1=7，故主存区号7位<br/>
(2)ABCDE (H) = 1010 1011 1100 1101 1110 (B)，拼接主存区号和组内块号，得到1010 101 11->0001 0101 0111->157H，对应的第"1"组的157H是第"2"块,故组号和区内组号拼上块内地址即为0001 1000 1101 1110->18DE (H)

### 习题7.23
(1)高速缓存有4块，故地址变换表有4个单元；内存地址共20位，块内地址10位，故每个存储单元放20-10=10位<br/>
(2)设命中率为x。32.7ns = (1-x)*300ns +30ns，解得x=99.1%<br/>
(3)88888H = 1000 1000 1000 1000 1000B ->高10位为222H在cache中是第"1"块，故cache地址为100 1000 1000=488H；56789H=0101 0110 0111 1000 1001B->高10位为0001 0101 1001->159H，在cache中是第"2"块，故cache地址为1011 1000 1001->B89H<br/>
~(累了写不动了洗洗睡)~
