#include<iostream>
#include<algorithm>
#include<stack>
#include<vector>
#include<map>
#include<set>
#include<math.h>
#include<iterator>
#include<bitset>
#include<queue>
// #include<bits/stdc++.h>
using namespace std;

int parent(vector<pair<int,pair<int,int>>> &a)
{
    set<int> m;
    for(int i=0;i<a.size();i++)
    {
        m.insert(a[i].first);
    }
    for(int i=0;i<a.size();i++)
    {
        m.erase(a[i].second.first);
    }
    if(!m.empty())
    return *m.begin();
    else 
    return -1;
}

void soln()
{
    int n;
    cin>>n;
    vector<pair<int,pair<int,int>>> u(n-1);
    for(int i=0;i<n-1;i++)
    {
        cin>>u[i].first>>u[i].second.first>>u[i].second.second;
    }
    int p=parent(u);
    bool child=1,par=0;
    stack<int> s;
    int done=0;
    cout<<p<<" ";
    while(done<n-1)
    {
        if(child)
        for(int j=0;j<u.size();j++)
        {
            if(u[j].first==p && u[j].second.second==1)
            {
                s.push(p);
                p=u[j].second.first;
                cout<<p<<" ";
                done++;
                child=1;
                par=0;
                break;
            }
            else
            {
                child=0;
                par=1;
            }
        }
        if(par)
        for(int j=0;j<u.size();j++)
        {
            if(u[j].first==p && u[j].second.second==0)
            {
                p=u[j].second.first;
                cout<<p<<" ";
                done++;
                child=1;
                par=0;
                break;
            }
            else
            par=0;
        }
        if(!child && !par)
        {
            p=s.top();
            s.pop();
            child=0;
            par=1;
        }
    }
    return;
}

int main()
{
    long long T;
    cin>>T;
    while(T--){
    soln();
    }
    return 0;
}