#include<iostream>
#include<queue>
#include<vector>
using namespace std;
int main(){
    int n,pw;
    cout<<"Enter the number of total pages:";
    cin>>n;
    cout<<"Enter the number of pages in one frame:";
    cin>>pw;
    vector<int>order(n);
    vector<bool>ispres(n,0);
    cout<<"Enter the string of the pages:";
    for(int i=0;i<n;i++){
        cin>>order[i];
    }
    queue<int>myq;
    int ph=0;
    for(int i=0;i<n;i++){
        int temp=order[i];
        int x=myq.size();
        if(x<pw && !ispres[temp]){
            myq.push(temp);
            ispres[temp]=true;
        }
        else if(x<=pw && ispres[temp]){
            ph++;
        }
        else{
            int mmk=myq.front();
            myq.pop();
            ispres[mmk]=0;
            myq.push(temp);
            ispres[temp]=true;
        }
    }
    cout<<"The total number of page hits are "<<ph<<endl;
    cout<<"The total number of page faults are "<<order.size()-ph;
}
