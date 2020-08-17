# 2020OS回忆版本

## 题型

第一部分选择题 10*1

第二部分填空题 10*1

第三部分 简答题 5*6

第四部分 大题 5*10

## Part I

## Part II

security包括哪些方面

process状态有哪些

spin lock use ?

process定义

TLB是什么



## Part III

1. Difference between semaphore and busy-waiting

2. Register LOCK.

   ![image-20200817193044458](./img/image-20200817193044458.png)

3. For quota list, why it limits the number of files？

4. Give an example of circular wait that will not lead to deadlock

5. How many "hello" will be printed?

   ```c
   int main()
   {
       fork();
       printf("hello\n");
       exelc("/bin/ls","ls",-1,0);
       printf("hello\n");
   }
   ```

   

## Part IV

1. The difference between  three  I/O types.

2. Dining philosophy. Give out the test().

   ![image-20200817192639817](./img/image-20200817192639817.png)

3. 银行家算法计算是否处于安全状态。

4. The difference between bitmap allocation and list allocation.

5. LRU\OPT PRA 计算缺页次数。