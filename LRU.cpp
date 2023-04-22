#include<iostream>
#include<vector>
using namespace std;
int to_rep(int*pages,int x,int *order,int i,int n,vector<bool>&is_pres){
    vector<bool>is_ap(n,0);
    int count=0;
    int ans;
    for(int k=i-1;k>0;k--){
        int temp=order[k];
        if(count<x-1 && is_pres[temp] && !is_ap[temp]){
            count++;
            is_ap[temp]=true;
        }
    }
    if(count<=x-1){
        for(int k=0;k<x;k++){
            int temp=pages[k];
            if(!is_ap[temp]){
                ans=temp;
            }
        }
    }
    return ans;
}
int main(){
    int n;
    cout<<"Enter the number of pages:";
    cin>>n;
    int x;
    cout<<"Enter the number of page slots:";
    cin>>x;
    int*order=new int[n];
    cout<<"Enter the pages in order:";
    for(int i=0;i<n;i++){
        cin>>order[i];
    }    
    vector<bool>is_pres(n,0);
    int*pages=new int[x];
    int pf=0;
    int j=0;
    for(int i=0;i<n;i++){
        int temp=order[i];
        if(j<x && !is_pres[temp]){
            pages[j]=temp;
            is_pres[temp]=true;
            pf++;
            j++;
        }
        if(j>=x && !is_pres[temp]){
            int rep=to_rep(pages,x,order,i,n,is_pres);
            for(int k=0;k<3;k++){
                if(pages[k]==rep){
                    pages[k]=temp;
                    break;
                }
            }
            is_pres[temp]=true;
            is_pres[rep]=false;
            pf++;
        }
    }
    cout<<"The total number of page faults are:"<<pf<<endl;
    cout<<"The total number of page hits are:"<<n-pf<<endl;
}