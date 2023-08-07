#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int total(vector<int> v1)
{
    int total=0;
    
    for(int i=0;i<v1.size();i++)
    {
        total=total+v1[i];
    }
    
    return (total);
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */ 
    int k,sz,x,min,a;
    cin>>k;
    
    int dup[k]={0};
    
    vector<int> size;
    vector<int> v[k];
    
    for(int i=0;i<k;i++)
    {
        cin>>sz;
        size.push_back(sz);
        
        for(int j=0;j<size[i];j++)
        {
            cin>>x;
            v[i].push_back(x);
        }
    }
    
    int sum=total(size);
    
    vector<int> ans;
    
    for(int i=0;i<sum;i++)
    {
        min=1000;
        
        for(int j=0;j<k;j++)
        {
            if(dup[j]<size[j])
            {
                if(min>v[j][dup[j]])
                {
                    min=v[j][dup[j]];
                    a=j;
                }
            }
        }
        dup[a]=dup[a]+1;
        ans.push_back(min);
    }
    
    for(int i=0;i<ans.size();i++)
    {
        cout<<ans[i]<<endl;
    }
    
    return 0;
}
