**一 填空**

1．非对称数字用户线（ADSL）采用的多路复用技术是 `________`。

>  FDM（频分多路复用）。
>
> ADSL采用的是FDM（频分多路复用技术）

2．在相隔2000km的两地间通过电缆以4800b/s的速率传送3000比特长的数据包，从开始发送到接收完数据需要的时间是`________`，如果用50 Kb/s的卫星信道传送，则需要的时间是 `________`。

> $T=\dfrac{3000}{4800}+\dfrac{2000k}{3\times 10^{8}\times \dfrac{2}{3}}=635\ ms$（传输时间+传播时间）
>
> $T_{satellite}=\dfrac{3000}{4800}+270=330\ ms$,卫星传输有固定270ms延时（传输时间+传播延时）

3．8个9600b/s的信道按时分多路复用在一条线路上传输，在统计TDM情况下，假定每个子信道有80％的时间忙，复用线路的控制开销为5％，那么复用线路的带宽为`________`。

>  $B=(9600\times80\%)\times8\div (1-5\%)=64.637kbps$

4．E1载波把32个信道按`________`方式复用在一条2.048Mb/s的高速信道上，每条话音信道的数据速率是`________`，该基本帧的传送时间为`________`。

> TDM
>
> 64kb /s
>
> 125us

5．贝尔系统T3信道的数据速率大约是`________`Mb/s。

> 44.736 Mb/s

6．下图所示的调制方式是`________`，若载波频率为2400Hz，则码元速率为`________`。

![img](C:\Users\Levick\source\github\HSIXDU\networking\img\clip_image002.gif)

> DPSK
>
> $r=2,S=\dfrac{n}{r}=1200\ baud$

7．设信道带宽为3400Hz，采用PCM编码，采样周期为125μs，每个样本量化为128个等级，则信道的数据速率为`________`。

> $r=log_{2}128=7,Sampling\ rate=\dfrac{1}{125us}=8k\ sample/s,N=7\times8k=56k\ bps$

8．假设模拟信号的最高频率为5MHz，采样频率必须大于`________`，才能使得到的样本信号不失真，如果每个样本量化为256个等级，则传输的数据速率是`________`。

> 10MHz
>
> $N=10M\times log_{2}256=80MHz$

9．在异步通信中，每个字符包含1位起始位、7位数据位、1位奇偶位和2位终止位，若每秒钟传送100个字符，采用4相相位调制，则码元速率为`________`，有效数据速率为`________`。

> $r=log_{2}4=2,N=(1+7+1+2)\times 100=1100\ bps,N_{有效}=\dfrac{7}{1+7+1+2}\times N=700\ bps,S=\dfrac{N}{2}=550\ baud$

 

**二 选择题**

● 下图表示了某个数据的两种编码，这两种编码分别是 （1）`________`，该数据是 （2）`________`。

![img](C:\Users\Levick\source\github\HSIXDU\networking\img\clip_image004.gif)

 

（1）A. X为差分曼彻斯特码，Y为曼彻斯特码

B. X为差分曼彻斯特码，Y为双极性码

C. X为曼彻斯特码，Y为差分曼彻斯特码

D. X为曼彻斯特码，Y为不归零码 

（2）A. 010011110              B. 010011010           

C. 011011010              D. 010010010

> 排除法
>
> (1)C
>
> (2)B

●最大传输速率能达到100Mb/s的双绞线是 （3）`________`。

（3）A. CAT3     B. CAT4        C. CAT5        D. CAT6

> C

● 光纤分为单模光纤与多模光纤，这两种光纤的区别是 （4）`________`。

（4）A. 单模光纤的纤芯大，多模光纤的纤芯小

B. 单模光纤比多模光纤采用的波长长

C. 单模光纤的传输频带窄，而多模光纤的传输频带宽

D. 单模光纤的光源采用发光二极管（Light Emitting Diode），而多模光纤的光源采用激光二极管（Laser Diode）   

> B.
>
> A.单模光纤的纤芯小，多模光纤的纤芯大。
>
> C.单模光纤的传输频带宽，而多模光纤的传输频带窄
>
> D.单模光纤的光源采用激光二极管（Laser Diode)，而多模光纤的光源采用发光二极管（Light Emitting Diode).
>
> ACD均说反。答案选B。

● 关于曼彻斯特编码，下面叙述中错误的是（5）`________`。

（5）A. 曼彻斯特编码是一种双相码

B. 采用曼彻斯特编码，波特率是数据速率的2倍

C. 曼彻斯特编码可以自同步

D. 曼彻斯特编码效率高

> D.曼彻斯特编码$r=\dfrac{1}{2}$，每两个signal element才能编码一个data element，编码效率低。其他都正确。

 

● 设信道带宽为3400Hz，调制为4种不同的码元，理想信道的数据速率为 （6）`________`kbps。

（6）A.3.4     B. 6.8          C. 13.6         D. 34

> $N=2\times B\times log_{2}4=13.6$,选C。

 

● 100BASE-FX采用4B/5B和NRZ-I编码，这种编码方式的效率为 （7）`________`。

（7）A. 50％        B. 60％        C. 80％         D. 100％

> 4B/5B是用5位表示4位编码来制造冗余（redundancy），以改善同步问题（synchronization）。效率=4/5=80%

● 下图所示是一种 （8）`________`调制方式。

![img](C:\Users\Levick\source\github\HSIXDU\networking\img\clip_image006.gif)

（8）A. ASK       B. FSK         C. PSK         D. DPSK

> C.

●下面的网络中，属于电路交换网络的是 （9）`________`，属于分组交换网络的是 （10）`________`。

（9）A. VPN    B. PSTN        C. FRN         D. PPP

（10）A. VPN       B. PSTN        C. FRN         D. PPP

> B. PSTN  公共电话交换网络。
>
> C. FRN   **Frame Relay** is a standardized [wide area network](https://en.wikipedia.org/wiki/Wide_area_network) technology that specifies the [physical](https://en.wikipedia.org/wiki/Physical_layer) and [data link layers](https://en.wikipedia.org/wiki/Data_link_layer) of digital telecommunications channels using a [packet switching](https://en.wikipedia.org/wiki/Packet_switching) methodology.（来自wiki，百度百科有错误）

三 计算

Consider the transfer of a file containing one million 8-bits characters from one station to another. What is the total elapsed time and effective throughput for the following case: A local network with two stations a distance **D** apart, a data rate of **B** bps, and a frame size of **P** with **80** bits of overhead per frame. Each frame is acknowledged with an **88-bit frame** before the next is sent. The propagation speed on the bus is 200 m/us. Solve for:

(1) D = 1 km, B=1 Mbps, P= 256 bits.

(2) D=10 km, B=1 Mbps, P=256 bits

(3) D=1 km, B=50 Mbps, P=10,000 bits

> total elapsed time: 总耗时（这里指传输 1m 8-bits 字符所需总时间）
>
> **effective throughput**——the number of bits per second successfully delivered from source to destination for an individual data flow
>
> We define:
>
> $T_p:propagation\ \  time$
>
> $T_a:ACK\ \ packet\ \ transmission\ \ time$
>
> $T_d:data\ \ packet\ \ transmission\ \ time$
>
> $T:total\ \ elapsed\ \ time$
>
> $C:cycle\ \ time(time\ \ required\ \ per\ \ frame)$
>
> $T_e:effective\ \  throughput$
>
> $Q:data\ \ bits\ \ per\ \ packet$
>
> $N:total\ \ number\ \ frames\ \ we send$
>
> Then we have:
>
> $C=T_a+T_d+2\times T_p$
>
> $N=\dfrac{1M\times 8}{Q}$
>
> $T_d=\dfrac{P}{B}$
>
> $T_a=\dfrac{88}{B}$
>
> $T_p=\dfrac{D}{200m/us}$
>
> Q=P-80
>
> $T_e=\dfrac{Q}{C}$
>
> $T=N\times C$
>
> From the equatinos above we have:
>
> (1):C=354 us, T=16.09 s, $T_e=497.18\ \ kbps$
>
> (2):C=444 us, T=20.18 s, $T_e=396.40\ \ kbps$
>
> (3):C=211.76 us,T=0.171 s, $T_s=46.86\ \ Mbps$