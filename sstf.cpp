#include<iostream>
#include<vector>
using namespace std;
int main(){
    int n;
    cout<<"Enter the size of the seat stream:";
    cin>>n;
    int*arr=new int[n];
    cout<<"Enter the stream:";
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    vector<bool>is_vis(n,0);
    int head;
    cout<<"Enter the head element:";
    cin>>head;
    int ct=0;
    int min_diff=INT_MAX;
    int min_index=-1;
    int tst=0;
    while(ct<n){
        for(int i=0;i<n;i++){
            int diff=abs(head-arr[i]);
            if(diff<min_diff && !is_vis[i]){
                min_index=i;
                min_diff=diff;
            }
        }
        head=arr[min_index];
        is_vis[min_index]=1;
        tst+=min_diff;
        min_diff=INT_MAX;
        ct++;
    }
    cout<<"The total seat time is "<<tst;
}