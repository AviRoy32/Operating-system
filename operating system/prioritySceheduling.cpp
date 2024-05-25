#include<bits/stdc++.h>
using namespace std;
struct process
{
    int PID,Priority,AT,BT,TAT,WT,CT,RT;
};
bool comparebyAT(const process &a,const process &b)
{
    return a.AT<b.AT;
}
void findCT(process proc[],int n)
{
    int completed=0,currentTime=0;
    bool ok[n];
    while(completed<n)
    {
        int highestPiority=INT_MIN,idx=-1;
        for(int i=0;i<n;i++)
        {
            if(!ok[i] && proc[i].AT<=currentTime && proc[i].Priority>highestPiority)
            {
                highestPiority=proc[i].Priority;
                idx=i;
            }
        }
        if(idx!=-1)
        {
            proc[idx].CT=currentTime+proc[idx].BT;
            ok[idx]=true;
            completed++;
            currentTime=proc[idx].CT;
        }
    }
}
void findTAT(process proc[],int n)
{
    for(int i=0;i<n;i++)
    {
        proc[i].TAT=proc[i].CT-proc[i].AT;
    }
}
void findWT(process proc[],int n)
{
    for(int i=0;i<n;i++)
    {
        proc[i].WT=proc[i].TAT-proc[i].BT;
        if(proc[i].BT<0) proc[i].BT=0;
    }
}
int main()
{
    int n;
    cin>>n;
    process proc[n];
    for(int i=0;i<n;i++)
    {
        cin>>proc[i].PID>>proc[i].Priority>>proc[i].AT>>proc[i].BT;
    }
    sort(proc,proc+n,comparebyAT);
    findCT(proc,n);
    findTAT(proc,n);
    findWT(proc,n);

    cout<<"PRIORITY SCEHEDULING\n";
    cout<<"PID\t"<<"Pri\t"<<"AT\t"<<"BT\t"<<"CT\t"<<"TAT\t"<<"WT\t"<<"RT\n";
    for(int i=0;i<n;i++)
    {
        cout<<'P'<<proc[i].PID<<"\t"<<proc[i].Priority<<"\t"<<proc[i].AT<<"\t"<<proc[i].BT<<"\t"<<proc[i].CT<<"\t"<<proc[i].TAT<<"\t"<<proc[i].WT<<"\t"<<proc[i].WT<<'\n';
    }
    return 0;
} 