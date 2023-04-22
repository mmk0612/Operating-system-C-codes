// write a program for RR CPU scheduling
#include<iostream>
#include<queue>
using namespace std;
int main(){
    int n;
    cout<<"Enter the number of processes:";
    cin>>n;
    int*at=new int[n];
    int*bt=new int[n];
    int*rt=new int[n];
    int*alt=new int[n];
    for(int i=0;i<n;i++){
        cout<<"Enter the arrival time for the process P"<<i+1<<":";
        cin>>at[i];
        cout<<"Enter the burst time for the process P"<<i+1<<":";
        cin>>bt[i];
        rt[i]=bt[i];
    }
    int ts;
    cout<<"Enter the time slice:";
    cin>>ts;
    queue<int> rq;
    vector<bool> ispush(n,false);
    vector<bool> isdone(n,false);
    vector<bool> isallotted(n,false);
    int smallest=INT_MAX;
    int smallest_in;
    for(int i=0;i<n;i++){
        if(at[i]<smallest){
            smallest=at[i];
            smallest_in=i;
        }
    }
    rq.push(smallest_in);
    ispush[smallest_in]=true;
    int time=0;
    int twt=0;
    int ttat=0;
    int trt=0;
    cout<<"Proc_id  Arrival-time  Burst-time  Completion-time  Turnaround-time  Waiting-time  Response-time"<<endl;
    cout<<"(Order of completion)"<<endl;
    while(!rq.empty()){
        int temp=rq.front();
        rq.pop();
        if(!isallotted[temp]){
            isallotted[temp]=1;
            alt[temp]=time;
        }
        if(rt[temp]<ts){
            time+=rt[temp];
            rt[temp]=0;
        }
        else{
            time+=ts;
            rt[temp]-=ts;
        }
        if(rt[temp]==0 && !isdone[temp]){
            isdone[temp]=true;
            cout<<"P"<<temp+1<<"              "<<at[temp]<<"             "<<bt[temp]<<"             "<<time<<"                "<<time-at[temp]<<"             "<<time-at[temp]-bt[temp]<<"             "<<alt[temp]-at[temp]<<endl;
            twt+=time-at[temp]-bt[temp];
            ttat+=time-at[temp];
            trt+=alt[temp]-at[temp];
        }
        for(int i=0;i<n;i++){
            if(at[i]<=time && !ispush[i]){
                ispush[i]=true;
                rq.push(i);
            }
        }
        if(rt[temp]!=0){
            rq.push(temp);
        }
    }
    cout<<"Average turnaround time is "<<(float)ttat/n<<endl;
    cout<<"Average waiting time is "<<(float)twt/n<<endl;
    cout<<"Average response time is "<<(float)trt/n<<endl;
}