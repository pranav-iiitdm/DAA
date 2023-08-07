#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int n;
    cin>>n;
    
    int p[n],total=0,count=0;
    
    for(int i=0;i<n;i++)
    {
        cin>>p[i];
        total+=p[i];
    }
    
    for(int i=0;i<n;i++)
    {
        if(p[0]!=p[i])
        {
            break;
        }
        
        else
        {
            count++;
        }
    }
    
    if(total%2==0)
    {
        if(count==n && n%2!=0)
        {
            cout<<"NO"<<endl;
        }
        
        else
        {
            cout<<"YES"<<endl;
        }
    }
    
    else
    {
        cout<<"NO"<<endl;
    }
    
    return 0;
}


/*
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
     Enter your code here. Read input from STDIN. Print output to STDOUT 
    int n;
    cin>>n;
    
    int p[n],total=0,sum=0;
    
    for(int i=0;i<n;i++)
    {
        cin>>p[i];
        total+=p[i];
    }
    
    int draw;
    draw=total/2;
    
    if(draw*2!=total)
    {
        cout<<"NO"<<endl;
    }
    
    else
    {
        for(int i=0;i<n;i++)
        {
            if(sum+p[i]<=draw)
            {
                sum+=p[i];
            }
        }
        
        if(sum==draw)
        {
            cout<<"YES"<<endl;
        }
        
        else
        {
            cout<<"NO"<<endl;
        }
    }
    
    return 0;
}

*/