# Database instructor‘s manual

## Chapter 2 Introduction to Relational Algebra

### 2.7, 2.8,2.12,2.13

![img](./img/A`7QO]J93GHMBRE5~YU_YTS.png)

## Chapter 3 Introduction to SQL

### 3.2

3.2 Suppose you are given a relation ***grade_points(grade, points)***(**<u>根据此relation来将等级成绩转换成数据成绩</u>**), which provides a conversion from letter grades in the takes relation to numeric scores; for example an “A” grade could be specified to correspond to 4 points, an “A-” to 3.7 points, a “B+” to 3.3 points, a “B” to 3 points, and so on. **<u>The grade points earned by a student for a course offering (section) is defined as the number of credits for the course multiplied by the numeric points for the grade that the student received.</u>**

<font color= red>(这句的意思是：$Grade\ points=credits\times numeric\  points$，e.g. 小明数据库等级是A，则根据题目所给***grade points***relation 得到分数[numeric points]是4，根据，数据库学分4分[credits]，那么小明数据库这门课的Grade points是$4\times 4=16$)</font>

Given the above relation, and our university schema, write each of the following queries in SQL. You can assume for simplicity that no takes tuple has the null value for grade.

![image-20200911091747096](D:/大三上课程/database/assignment/img/image-20200911091747096.png)



a. Find the total grade-points earned by the student with ID 12345, across all courses taken by the student.

```mysql
select sum(credits * points)
from takes natural join course natural join grade_points
where ID=12345
```



b. Find the grade-point average (GPA) for the above student(上面的学生，指代ID为12345的学生 ), that is, the total grade-points divided by the total credits for the associated courses.

```mysql
select sum(credits * points)/sum(credits)
from takes natural join course natural join grade_points
where ID=12345
```



c. Find the ID and the grade-point average of every student.

 ```mysql
select ID,sum(credits * points)/sum(creadits) as GPA
from takes natural join course natural join grade_points
group by ID
 ```



### 3.9

3.9 Consider the employee database of Figure 3.20, where the primary keys are underlined. Give an expression in SQL for each of the following queries.

*employee* (*<u>employee name</u>*, *street*, *city*)
*works* (*<u>employee name</u>*, *company name*, *salary*)
*company* (*<u>company name</u>*, *city*)
*manages* (*<u>employee name</u>*, *manager name*)

<center>Figure 3.20</center>

a. Find the names and cities of residence of all employees who work for “First Bank Corporation”.

```mysql
select employee_name, city
from works natural join employee
where commany_name='First Bank Corporation'
```



b. Find the names, street addresses, and cities of residence of all employees who work for “First Bank Corporation” and earn more than $10,000.

```mysql
select employee_name,street,city
from works natural join employee
where commany_name='First Bank Corporation' and salary > 10000
```



c. Find all employees in the database who do not work for “First Bank Corporation”.

```mysql
(select employee_name
from employee)
except
(select employee_name
 from employee natural join works
 where commany_name='First Bank Corporation'
)
```



d. Find all employees in the database who earn more than each employee of “Small Bank Corporation”.

```mysql
select employee_name,street,city
from employee natural join works
where salary >(select max(salary)
               from works
               where company_name='Small Bank Corporation')
/* OR
select employee_name,street,city
from employee natural join works
where salary >all (select salary
                   from works
                   where company_name='Small Bank Corporation')
*/
```



e. Assume that the companies may be located in several cities. Find all companies located in every city in which “Small Bank Corporation” is located.

```mysql
/*select company_name
from company
where city in (select city
               from company
               where company_name='Small Bank Corporation')  */-- >This solution seems to be wrong
               
with company_sum(company_name, quantity)
	as(select company_name, sum(city)
       from company
       where city in(select city
                     from company
                     where company_name='Small Bank Corporation')
       group by company_name)
/* 找到各公司在,SBC所在城市的，公司总数量 */
select company_name
from company_sum
where quantity=(select quantity
                from company_sum
                where company_name='Small Bank Corporation')

```



f. Find the company that has the most employees.

```mysql
with company_staff(company_name, staff_quantity) as
	(select company_name,count (employee_name)
	from works
	group by company_name)
select company_name
from company_staff
where staff_quantity=(select max(staff_quantity)
                      from company_staff)
```



g. Find those companies whose employees earn a higher salary, on average, than the average salary at “First Bank Corporation”.

```mysql
with company_avg_sal(company_name,avg_salary) as
	(select company, avg(salary)
     from works
     group by company_name)
select company_name
from company_avg_sal
where avg_salary >(select avg_salary
                  from company_avg_sal
                  where company_name='Fist Bank Corporation')
```

 

### 3.15

3.15 Consider the bank database of Figure 3.19, where the primary keys are underlined. Construct the following SQL queries for this relational database.

*branch*(<u>*branch name*</u>, *branch_city, assets*)
*customer* (*<u>customer name</u>*, *customer_street, customer_city*)
*loan* (*<u>loan number</u>*, *branch_name, amount*)
*borrower* (*<u>customer name</u>*, *loan_number*)
*account* (*<u>account number</u>*, *branch_name, balance* )
*depositor* (*<u>customer name</u>*, *account_number*)

Figure 3.19

a. Find all customers who have an account at all the branches located in “Brooklyn”.

思路：生成一张表包含各顾客在Brooklyn的账户数目，找到所有账户数目=Brooklyn所有branch数的顾客。

```mysql
with account_quantity(customer_name,quantity) 
	as(select customer_name, sum(account_number)
       from customer natural join account natural join depositor natural join branch
       where branch_city='Brooklyn'
       group by customer)
/*Get the account quantity in branch located in Brooklyn of each customer*/
select customer_name
from account_quantity
where quantity=(select sum(*)
                from branch
                where branch_city='Brooklyn')
```



b. Find out the total sum of all loan amounts in the bank.

```mysql
select sum(amount)
from loan
```



c.  Find the names of all branches that have assets greater than those of at least one branch located in “Brooklyn”.

```mysql
/*若此处assets对应的是branch中一个元组中的assets*/
select branch_name
from banch
where assets > some (select assets
                     from branch
                     where branch_cify='Brooklyn')
/*若此处assets对应的是一个branch的所有资产，*/                     
with branch_assets(branch_name,assets_total)
	as(select branch_name,sum(assets)
       from branch
       group by branch_name)
select branch_name
from branch_assets
where assets_total> some (select assets_total
                          from branch_assets
                          where branch_name in (select branch_name
                                                from branch
                                                where branch_city='Brooklyn'))                              
       
```

## Chapter 6 Formal Relational Query Language	

### 6.1

![image-20200911091747096](D:\大三上课程\database\assignment\img\image-20200911091747096.png)

6.1

a. Find the titles of courses in the Comp. Sci. department that have 3 credits.

>  $\Pi_{title}(\sigma_{dapt_name='Comp.Sci.'\wedge credits=3}(course))$

b. Find the IDs of all students who were taught by an instructor named Einstein; make sure there are no duplicates in the result.

>  $\Pi_{s\_ID}(\sigma_{i\_ID=ID\ \wedge\ Name='Einstein'}(instructor\times advisor))$

c. Find the highest salary of any instructor.

>  $\Pi_{salary}(instructor)-\Pi_{I1.salary}(\sigma_{I1.salary<I2.salary}(\rho_{I1}(instructor)\times \rho_{I2}(instructor)))$
>
>  或
>
>  $\mathcal{G}_{max(salary)}(instructor)$

d. Find all instructors earning the highest salary (there may be more than one with the same salary).

> $\Pi_{name,salary}(instructor) \div(\Pi_{salary}(instructor)-\Pi_{I1.salary}(\sigma_{I1.salary<I2.salary}(\rho_{I1}(instructor)\times \rho_{I2}(instructor))))$
>
> 或
>
> $\Pi_{name,salary}(instructor) \div\mathcal{G}_{max(salary)}(instructor)$

e. Find the enrollment of each section that was offered in Autumn 2009. (注意enrollment在这里表示登记人数的意思)

>  $_{sec\_id\ }\mathcal{G}_{count(ID)}(\sigma_{year=2009\ \wedge\ semester=Autumn}(section \bowtie takes))$

f. Find the maximum enrollment, across all sections, in Autumn 2009.

>  $\mathcal{G}_{max(count(ID))}(_{sec\_id\ }\mathcal{G}_{count(ID)}(\sigma_{year=2009\ \wedge\ semester=Autumn}(section \bowtie takes)))$

g. Find the sections that had the maximum enrollment in Autumn 2009.

> $\sigma_{count(ID)=\mathcal{G}_{max(count(ID))}(_{sec\_id\ }\mathcal{G}_{count(ID)}(\sigma_{year=2009\ \wedge\ semester=Autumn}(section \bowtie takes)))}(_{sec\_id\ }\mathcal{G}_{count(ID)}(\sigma_{year=2009\ \wedge\ semester=Autumn}(section \bowtie takes)))$

### 6.2

6.2 Consider the relational database of Figure 6.22, where the primary keys are underlined. Give an expression in the relational algebra to express each of the following queries:

![image-20200911202102094](D:\大三上课程\database\assignment\img\image-20200911202102094.png)

***<u>a. Find the names of all employees who live in the same city and on the same street as do their managers.(与经理同城同街的员工姓名)</u>*** 这题有点难。

> $\Pi_{person\_name}((employee \bowtie manages)\bowtie _{manageer\_name=E2.person\_name\wedge employee.street=E2.street \wedge employee.sicy=E2.city}(\rho_{E2}(employee)))$
>
> or
>
> $\Pi_{person\_name}(\sigma_{manageer\_name=E2.person\_name\wedge employee.street=E2.street \wedge employee.sicy=E2.city}(employee \bowtie manages)\times (\rho_{E2}(employee)))$

第一种写法为`theta join`，可以将选择和笛卡尔积整合成一次运算。

![image-20200917174003512](D:/大三上课程/database/assignment/img/image-20200917174003512.png)

b. Find the names of all employees in this database who do not work for “First Bank Corporation”.

> $\Pi_{person\_name}(employee)-\Pi_{person\_name}(\sigma_{company\_name='First\ Bank\ Corporation'}(employee\bowtie works))$

c. Find the names of all employees who earn more than every employee of “Small Bank Corporation”.

> $\Pi_{person\_name}(\sigma_{salary>\mathcal{G}_{max(salary)}(\sigma_{company\_name='Small\ Bank\ Corporation'}(works))}(works))$



