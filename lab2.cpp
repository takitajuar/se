#include<iostream>
using namespace std;
int main()
{
   int a[10];
   cout<< "enter the 10 elements"<<endl;
   for
    (int i=0; i<10; i++)
    {
    cin>>a[i];

    }
   for(int i=0; i<10; i++)
    {
    cout<<a[i]<<" ";
    }
    cout<<endl;

   for(int j=9; j>=0; j--)
    {
     cout<<a[j]<<" ";
    }
    return 0;
}




