#include<iostream>
#include<vector>
#include<queue>
using namespace std;
int main(){
    int n;
    cout<<"Enter the size of the seat stream:";
    cin>>n;
    queue<int> q;
    cout<<"Enter the stream:";
    for(int i=0;i<n;i++){
        int temp;
        cin>>temp;
        q.push(temp);
    }
    int head;
    cout<<"Enter the head element:";
    cin>>head;
    int tst=0;
    while(!q.empty()){
        int temp=q.front();
        q.pop();
        int diff=abs(head-temp);
        tst+=diff;
        head=temp;
    }
    cout<<"The total seat time is "<<tst;   
}