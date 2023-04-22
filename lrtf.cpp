#include<iostream>
using namespace std;
int main(){
   int n;
   cout<<"Enter the number of processes:";
   cin>>n;
   int*at=new int[n];
   int*bt=new int[n];
   int*rt=new int[n];
   for(int i=0;i<n;i++){
      cout<<"Enter the arrival time for process"<<i+1<<":";
      cin>>at[i];
      cout<<"Enter the burst time for process"<<i+1<<":";
      cin>>bt[i];
      rt[i]=bt[i];
   }
   int largest_in=INT_MIN;
   int remain=0,ct=0,tat_sum=0,wait_sum=0;
   cout<<"Process id  Arrival time  Burst time  Turnaround time  Waiting time"<<endl;
   for(int time=0;remain!=n;time++){
      int largest=INT_MIN;
      for(int i=0;i<n;i++){
         if(at[i]<=time && rt[i]!=0 && rt[i]>largest){
            largest_in=i;
            largest=rt[i];
         }
      }
      rt[largest_in]--;
      if(rt[largest_in]==0){
         remain++;
         ct=time+1;
         cout<<"P"<<largest_in+1<<"              "<<at[largest_in]<<"            "<<bt[largest_in]<<"              "<<ct-at[largest_in]<<"               "<<ct-at[largest_in]-bt[largest_in]<<endl;
         tat_sum+=ct-at[largest_in];
         wait_sum+=ct-at[largest_in]-bt[largest_in];
      }
   }
   cout<<"Average turnaround time is "<<(float)tat_sum/n<<endl;
   cout<<"Average waiting time is "<<(float)wait_sum/n;
}
