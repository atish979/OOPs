#include <iostream>
#include<string>
using namespace std;

template<typename t>
void myswap(t &a, t &b)
{
t temp = a;
a=b;
b=temp;
}

int main()
{
int emp1=100;
int emp2=102;
myswap(emp1,emp2);
 
cout<<"employe id after swap"<<emp1<<" "<<emp2<<endl;

int room1=401;
int room2=402;
myswap(room1,room2);

cout<<"rooms after swap"<<room1<<" "<<room2<<endl;

float p1=35.90;
float p2=67.09;
myswap(p1,p2);

cout<<"the  values after swap"<<p1<<" "<<p2<<endl;

return 0;
}

