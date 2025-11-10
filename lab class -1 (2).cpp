#include<iostream>
#include<conio.h>
using namespace std;
int main()
{
    int a[10], even = 0, odd = 0;
    for (int i =0;i<10;i++)
    {
       cout<<"ELEMENT ["<<i<<"] : ";
        cin>>a[i];

    }
    for ( int i = 0; i<10;i++)
    {
        if(a[i]%2 == 0)
        {
            even++;
        }
        else {odd++;}
    }
    cout<<"total Even : "<<even<<endl;
    cout<<"Total odd : " <<odd << endl;
}
