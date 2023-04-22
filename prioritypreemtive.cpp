#include<iostream>
using namespace std;
int main(){
    int n;
    cout<<"Enter the number of processes:";
    cin>>n;
    int*at=new int[n];
    int*bt=new int[n];
    int*pr=new int[n];
    int*rt=new int[n];
    for(int i=0;i<n;i++){
        cout<<"Enter the arrival time for process"<<i+1<<":";
        cin>>at[i];
        cout<<"Enter the burst time for process"<<i+1<<":";
        cin>>bt[i];
        cout<<"Enter the priority for process"<<i+1<<":";
        cin>>pr[i];
        rt[i]=bt[i];
    }
    int ttat=0,twt=0;
    int remain=0;
    int smallest_in;
    cout<<"Process_id Arrival-time Burst-time Priority Completion-time Turnaround-time Waiting-time"<<endl;
    cout<<"(Order of completion)"<<endl;
    for(int time=0;remain!=n;time++){
        int smallest=INT_MAX;
        for(int i=0;i<n;i++){
            if(at[i]<=time && pr[i]<smallest && rt[i]!=0){
                smallest=pr[i];
                smallest_in=i;
            }
        }
        rt[smallest_in]--;
        if(rt[smallest_in]==0){
            cout<<"P"<<smallest_in+1<<"               "<<at[smallest_in]<<"        "<<pr[smallest_in]<<"         "<<bt[smallest_in]<<"          "<<time+1<<"             "<<time+1-at[smallest_in]<<"            "<<time+1-at[smallest_in]-bt[smallest_in]<<endl;
            ttat+=time+1-at[smallest_in];
            twt+=time+1-at[smallest_in]-bt[smallest_in];
            remain++;
        }
    }
    cout<<"Average turnaround time is "<<(float)ttat/n<<endl;
    cout<<"Average waiting time is "<<(float)twt/n<<endl;
}