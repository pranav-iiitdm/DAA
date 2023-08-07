#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */ 
    int k,size,x;
    cin>>k;
    
    vector <int> v;
    
    for(int i=0;i<k;i++)
    {
        cin>>size;
        
        for(int j=0;j<size;j++)
        {
            cin>>x;
            v.push_back(x);
        }
    }
    
    sort(v.begin(),v.end());
    
    for(int i=0;i<v.size();i++)
    {
        cout<<v[i]<<endl;
    }
    return 0;
}
