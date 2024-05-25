#include<bits/stdc++.h>
using namespace std;
struct process
{
    int PID,AT,BT,CT,TAT,WT,RT;
};
bool comparebyAT(const process &a,const process &b)
{
    return a.AT<b.AT;
}
void findCT(process proc[],int n)
{
    proc[0].CT=proc[0].BT;
    for(int i=1;i<n;i++)
    {
        proc[i].CT=proc[i-1].CT+proc[i].BT;
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
        if(proc[i].WT<0) proc[i].WT=0;
    }
}
int main()
{
    int n;
    cin>>n;
    process proc[n];
    for(int i=0;i<n;i++) cin>>proc[i].PID>>proc[i].AT>>proc[i].BT;
    sort(proc,proc+n,comparebyAT);
    findCT(proc,n);
    findTAT(proc,n);
    findWT(proc,n);

    cout<<"FCFS SCEHEDULING ALGORITHM\n";
    cout<<"PID\t"<<"AT\t"<<"BT\t"<<"CT\t"<<"TAT\t"<<"WT\t"<<"RT\n";
    for(int i=0;i<n;i++)
    {
        cout<<'P'<<proc[i].PID<<"\t"<<proc[i].AT<<"\t"<<proc[i].BT<<"\t"<<proc[i].CT<<"\t"<<proc[i].TAT<<"\t"<<proc[i].WT<<"\t"<<proc[i].WT<<'\n';
    }
    return 0;
} 