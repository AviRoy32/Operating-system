#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,res;
    cout<<"Enter number of process: ";
    cin>>n;
    cout<<"Enter number of resource: ";
    cin>>res;
    vector<int>max_need[n],allocation[n],available(n);
    int x;
    cout<<"Enter maximum need values\n";
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<res;j++)
        {
            cin>>x;
            max_need[i].push_back(x);
        }
    }
    cout<<"Enter allocated values\n";
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<res;j++)
        {
            cin>>x;
            allocation[i].push_back(x);
        }
    }
    vector<int>total_resource(res),total_allocation(res);
    cout<<"Enter total resource:\n";
    for(int i=0;i<res;i++) cin>>total_resource[i];
    for (int i = 0; i < n; ++i) 
    {
        for (int j = 0; j < res; ++j) 
        {
            total_allocation[j] += allocation[i][j];
        }
    }
    for(int i=0;i<res;i++)
    {
        available[i]=total_resource[i]-total_allocation[i];
    }
    // cout<<"Enter available values\n";
    // for(int i=0;i<res;i++) cin>>available[i];
    vector<int>current_need[n];
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<res;j++)
        {
            x=max_need[i][j]-allocation[i][j];
            if(x<0) x=0;
            current_need[i].push_back(x);
        }
    }
    bool ok[n];
    int count=0;
    vector<int>ans;
    while(count<n)
    {
        bool found=false;
        for(int i=0;i<n;i++)
        {
            if(!ok[i])
            {
                bool canAllocate=true;
                for(int j=0;j<res;j++)
                {
                    if(available[j]<current_need[i][j])
                    {
                        canAllocate=false;
                        break;
                    }
                }
                if(canAllocate)
                {
                    count++;
                    for(int j=0;j<res;j++)
                    {
                        available[j]+=allocation[i][j];
                    }
                    ans.push_back(i);
                    ok[i]=true;
                    found=true;
                }
            }
        }
        if(!found)
        {
            cout<<"This is an unsafe state.\n";
            return 0;
        }
    }
    cout<<"system is in a safe state.\nsafe sequence is: ";
    for(int val:ans) cout<<'P'<<val<<" ";
    return 0;
} 