#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    int n,m;
    cin>>n;
    cin>>m;
    int a[n],b[m],c[n+m];
    if(n==0 && m==0)
    {
        cout<<"0"<<endl;
        return 0;
    }
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    for(int i=0;i<m;i++)
    {
        cin>>b[i];
    }
    int i1=0,i2=0,count=0;
    while(i1<n && i2<m)
    {
        if(a[i1]<b[i2])
        {
            c[count++]=a[i1++];
        }
        else if(a[i1]>b[i2])
        {
            c[count++]=b[i2++];
        }
        else
        {
            c[count++]=b[i2];
            i1++;
            i2++;
        }
    }
    while(i1<n)
    {
        c[count++]=a[i1++];
    }
    while(i2<m)
    {
        c[count++]=b[i2++];
    }
    if(count%2!=0)
    {
        cout<<c[count/2]<<endl;
    }
    else
    {
        cout<<(c[count/2]+c[(count/2)-1])*1.0/2<<endl;
    }
    return 0;
}