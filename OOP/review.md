# OOP复习

本文适合针对考试内容的复习，旨在快速对考试知识点有大概掌握。本文会以讲解例题的形式呈现。相应题目来源于网络。

## Part I  There is one error in each code paragraph. Find out the error and write down the error statement on your answer sheet.

第一部分为找错题，10个，每个两分。每题一个错误。

常考的知识点有：

### new开辟空间的释放(delete name; delete []name)

```c++
float * ptr=new float[20];
for (int i=0;i<20;i++)
    ptr[i]=i+2;
delete ptr;//---->delete []ptr;
```

### 命名空间(namespace)的使用

```c++
namespace{
    void do(){/* ......  */}
    int temp;
}
using namespace myspace;
using namespace myspace:temp;//---->using namespace myspace::temp;
```

### 构造函数(constructor)的使用

```c++
class Student{
//...
public:
    void Student();//---->Student();
    ~Student();
}
```

### 私有成员(private member )

```c++
class C{
    int x;//默认为private
    void setx(int a){
        /* .... */
}
};
void main(){
    C c1;
    c1.setx(3);//类外不能使用private成员
}
```
```c++
class BC{
    int x;
public:
    BC(int xx=0){x=xx;}
};
class DC:public BC{
	char c;
    DC(int x1,char c1){
    	x=x1;//子类不能调用父类的私有成员，若使用protected则可以
        c=c1;
	}
};
```

```c++
class BC{
protected
    void set_x(int);
};

class DC:public BC{
public:
    void f(){set_x(66);}
};
void f(){
    BC c1;
    c1.set_x(77);//类外不可调用父类protected成员
}
```



### 运算符重载(operator overloading)

```c++
class C{
	int sz;
public:
    friend C operator+(const C&, const C&);
    //...
};

C C::operator+(const C& c1, const C& c2){//友元函数（friend function）实现时不需要 "类名::"
    cout<<c1.sz;
    //...
}
```

### 纯虚函数(pure virtual function)，抽象类（abstract class）

```c++
class Animal{
public:
    virtual void f()=0;//纯虚函数
};

void f():{
    Animal b;//抽象类不可实例化
}
```

### 默认参数(default argument)

```c++
class B{
public:
    B(int a=10, float y)//默认实参从后向前绑定，不能有空隙
    {	i=a;z=y;}
private:
    int i;
    float z;
};
```

### 成员函数的调用

```c++
class C{
public:
    void m(){/* ... */}
    static void s(){/* ... */}  
};
void main(){
    C c1;
    c1.m();
    c1.s();
    C::s();//成员函数调用方式错误
}
```

### const变量

```c++
int* f(const int y){
    int temp=3;
    temp+=++y;//y为const整形变量，其值不可直接改变。
    return &temp;
}
```

### this指针

```c++
class S{
    //...
    friend int operator[](s,int);//重载成员函数时，this指针默认绑定到左侧运算对象
    							 //---->firend int operator[](int);即可
    int operator!(int);
    //...
};
```



### 函数重载

```c++
class BC{
public:
    virtual void f(){/*...*/}
    //...
};
class DC:public BC{
	//...
    void f(int x){/*...*/}
};
void f(){
    DC d;
    d.f();//此处候选函数(candidate function)只有void f(int x)，无可行函数(viabal funtion)
    	  //DC已经重载f()，此时 BC的f()对ｄ不可见
}
```



2020.9.1 update. To be continued...	