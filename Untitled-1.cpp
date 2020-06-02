#include <iostream>

using namespace std;

void swap(int &x, int &y)
{
	int tmp = x;
	x = y;
	y = tmp;
}

int main()
{
    int a=2,b=3;
    cout<<a<<" "<<b<<endl;
    swap(a,b);
    cout<<a<<" "<<b<<endl;
    return 0;
}
