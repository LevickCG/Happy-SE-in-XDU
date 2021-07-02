## 2021年的题目有相当多的与2020年的相同（指完全一致) ##
## PS：打印店的题目是真的 ##
选择题：2points\*10  
很多题与2020年的题目一样  
填空题：2points\*10  
我记得跟2020年的题目完全一样  
简答题：4points\*5  
  1. 对称加密和非对称加密中，哪种方法得到加密密钥后可以轻易得到解密密钥（好像是这个意思） 
  2. 软链接和硬链接的区别  
  3. 为何在程序初始化时分配所有资源不会导致死锁？  
  4. 补全并解释代码，和2020年的第三题一样  
  5. 还有一个忘了。。但应该挺简单的  

应用题：10points\*4  
  1. 求缺页中断数，分别使用FIFO和LRU，题目数据与2020年应用题第一题完全一样
  2. kernel level thread和user level thread的优点和缺点
  3. 银行家算法，判断状态是否安全，与2020年的题目完全一样
  4. 读以下两段代码  
      fork.c:  
      ```c
      #include<unistd.h>
      #include<stdio.h>
      int main()
      {
        pid_t pid
        pid = fork();
        if(pid == 0)
          printf("os exam\n");
        if(pid > 0)
          printf("os exam\n");
        return 0;
      }
      ```
      execl.c:  
      ```c
      #include<unistd.h>
      #include<stdio.h>
      int main()
      {
        pid_t pid;
        pid = fork();
        if(pid==0)
          printf("os exam\n");
        if(pid>0)
        {
          execl("/bin/ls","ls","-l",0);
          printf("os exam\n");
        }
        return 0;
      }
      ```
      这两段程序分别会打印出几个os exam？
