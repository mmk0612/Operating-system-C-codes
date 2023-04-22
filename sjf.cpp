#include<iostream>
#include<vector>
using namespace std;
int main(){
    int n;
    cout<<"Enter the number of processes:";
    cin>>n;
    int*bt=new int[n];
    for(int i=0;i<n;i++){
        cout<<"Enter the burst time for the process"<<i+1<<":";
        cin>>bt[i];
    }
    int remain=0,ct=0;
    int wt_sum=0,tat_sum=0;
    vector<bool>isdone(n,false);
    cout<<"Process id  Burst time  Turnaround time  Waiting time"<<endl;
    for(int time=0;remain!=n;time++){
        int smallest=INT_MAX,smallest_in;
        for(int i=0;i<n;i++){
            if(bt[i]<smallest && !isdone[i]){
                smallest_in=i;
                smallest=bt[i];
            }
        }
        ct+=bt[smallest_in];
        isdone[smallest_in]=true;
        cout<<"P"<<smallest_in+1<<"              "<<bt[smallest_in]<<"               "<<ct<<"                "<<ct-bt[smallest_in]<<endl; 
        wt_sum+=ct-bt[smallest_in];
        tat_sum+=ct;
        remain++;
    }
    cout<<"Average turnaround time is:"<<(float)tat_sum/n<<endl;
    cout<<"Average waiting time is:"<<(float)wt_sum/n<<endl;
}