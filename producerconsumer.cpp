#include<iostream>
using namespace std;
int mutx=1;            //initialize mutex semaphore to 1
int full=0;             //number of full slots as 0
int empty=10;           //number of empty slots as size of buffer
int x=0;                //item
void producer(){
    //decrease mutex value by 1
    mutx--;
    //increase number of full slots by 1
    full++;
    //decrease number of empty slots by 1
    empty--;
    if(full>10 || empty<0){
        cout<<"No more items can be produced since buffer is full."<<endl;
        return;
    }
    //item produced
    x++;
    cout<<"Producer produced item "<<x<<endl;
    //increase mutex by 1
    mutx++;
}
void consumer(){
    //decrease mutex value by 1
    mutx--;
    if(full==0){
        cout<<"No items to be consumed"<<endl;
        return;
    }
    //decrease number of full slots by 1
    full--;
    //increase number of empty slots by 1
    empty++;
    cout<<"Consumer consumes item "<<x<<endl;
    //item consumed
    x--;
    //increase value of mutex by 1
    mutx++;
}
int main(){
    int n;
    cout<<"Press 1 for Producing item"<<endl;
    cout<<"Press 2 for Consuming item"<<endl;
    cout<<"Press 3 for Exit"<<endl;
    for(int i=1;i>0;i++){
        cout<<"Enter your choice:";
        cin>>n;
        switch(n){
            case 1:
            producer();
            break;
            case 2:
            consumer();
            break;
            case 3:
            cout<<"Successfully exited."<<endl;
            i=-1;
            break;
            default:
            cout<<"Wrong choice selected,Select again."<<endl;
            i=1;
            break;
        }
    }
}