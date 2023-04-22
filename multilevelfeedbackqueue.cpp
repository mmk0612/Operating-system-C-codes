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
    int*qno=new int[n];
    for(int i=0;i<n;i++){
        cout<<"Enter the arrival time of process"<<i+1<<":";
        cin>>at[i];
        cout<<"Enter the burst time of process"<<i+1<<":";
        cin>>bt[i];
        rt[i]=bt[i];
    }
    int tq;
    cout<<"Enter the time quantum for queue 1:";
    cin>>tq;
    queue<int> q1;
    queue<int> q2;
    for(int i=0;i<n;i++){
        if(bt[i]>5){
            qno[i]=2;
        }
        else{
            qno[i]=1;
        }
    }
    int smallest=INT_MAX;
    int smallest_in;
    for(int i=0;i<n;i++){
        if(at[i]<smallest && qno[i]==1){
            smallest_in=i;
            smallest=at[i];
        }
    }
    q1.push(smallest_in);
    int time=0;
    int ttat=0,twt=0;
    vector<bool>is_vis(n,false);
    is_vis[smallest_in]=true;
    vector<bool>is_done(n,false);
    cout<<"Proc_id  Arrival-time  Burst-time  Completion-time  Turnaround-time  Waiting-time Queue-no."<<endl;
    cout<<"(Order of completion)"<<endl;
    while(!q1.empty()){
        bool q_com=true;
        int temp=q1.front();
        q1.pop();
        if(rt[temp]<tq){
            time+=rt[temp];
            rt[temp]=0;
        }
        else{
            rt[temp]-=tq;
            time+=tq;
        }
        for(int i=0;i<n;i++){
            if(at[i]<=time && qno[i]==1 && !is_vis[i]){
                q1.push(i);
                is_vis[i]=true;
            }
        }
        if(rt[temp]==0 && !is_done[temp]){
            is_done[temp]=true;
            cout<<"P"<<temp+1<<"            "<<at[temp]<<"            "<<bt[temp]<<"              "<<time<<"                "<<time-at[temp]<<"             "<<time-at[temp]-bt[temp]<<"           "<<qno[temp]<<endl;
            ttat+=time-at[temp];
            twt+=time-at[temp]-bt[temp];
        }
        else{
            q1.push(temp);
        }
        if(q1.empty()){
            for(int i=0;i<n;i++){
                if(!is_vis[i] && qno[i]==1){
                    q1.push(i);
                    time=at[i];
                }
            }
        }
        for(int i=0;i<n;i++){
            if(!is_done[i] && qno[i]==1){
                q_com=false;
                break;
            }
        }
        if(q_com){
            break;
        }
    }
    smallest=INT_MAX;
    for(int i=0;i<n;i++){
        if(at[i]<smallest && qno[i]==2){
            smallest_in=i;
            smallest=at[i];
        }
    }
    vector<bool>is_pushed(n,false);
    q2.push(smallest_in);
    is_pushed[smallest_in]=true;
    time=smallest;
    while(!q2.empty()){
        int temp=q2.front();
        q2.pop();
        is_done[temp]=true;
        time+=rt[temp];
        rt[temp]=0;
        cout<<"P"<<temp+1<<"            "<<at[temp]<<"            "<<bt[temp]<<"              "<<time<<"                "<<time-at[temp]<<"             "<<time-at[temp]-bt[temp]<<"           "<<qno[temp]<<endl;
        ttat+=time-at[temp];
        twt+=time-at[temp]-bt[temp];
        smallest=INT_MAX;
        for(int i=0;i<n;i++){
            if(at[i]<smallest && qno[i]==2 && !is_pushed[i]){
                smallest_in=i;
                smallest=at[i];
            }
        }
        if(is_pushed[smallest_in]){
            break;
        }
        else{
            q2.push(smallest_in);
            is_pushed[smallest_in]=true;
        }
    }
    cout<<"Average turnaround time is "<<(float)ttat/n<<endl;
    cout<<"Average waiting time is "<<(float)twt/n<<endl;
}