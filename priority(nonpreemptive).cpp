#include<iostream>
using namespace std;
int main(){
    int n;
    cout<<"Enter the number of processes";
    cin>>n;
    int*at=new int[n];
    int*bt=new int[n];
    int*pr=new int[n];
    for(int i=0;i<n;i++){
        cout<<"Enter the arrival time for process"<<i+1;
        cin>>at[i];
        cout<<"Enter the burst time for the process"<<i+1;
        cin>>bt[i];
        cout<<"Enter the priority for the process"<<i+1;
        cin>>pr[i];
    }
    int remain=0;
    int min_pr=INT_MAX;
    int min_ind;
    int twt=0,ttat=0;
    cout<<"Process_id Arrival-time Burst-time Priority Completion-time Turnaround-time Waiting-time"<<endl;
    for(int time=0;remain!=n;time++){
        for(int i=0;i<n;i++){
            if(at[i]<=time && pr[i]<min_pr && bt[i]!=0){
                min_ind=i;
            }
        }
        time+=bt[min_ind];
        cout<<"P"<<min_ind+1<<"       "<<at[min_ind]<<"        "<<bt[min_ind]<<"     "<<pr[min_ind]<<"       "<<time<<"         "<<time-at[min_ind]<<"          "<<time-at[min_ind]-bt[min_ind]<<endl;
        twt+=time-at[min_ind]-bt[min_ind];
        ttat+=time-at[min_ind];
        bt[min_ind]=0;
    }
    cout<<"Average turnaround time is "<<(float)ttat/n<<endl;
    cout<<"Average waiting time is "<<(float)twt/n<<endl;
}