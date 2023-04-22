#include<iostream>
#include<pthread.h>
#include<unistd.h>
using namespace std;
class monitor{
    private:
    int rcnt; //no. of readers
    int wcnt; //no. of writers
    int waitr; //no. of readers waiting
    int waitw; //no. of writers waiting
    pthread_cond_t canread; //condition variable to check whether reader can read
    pthread_cond_t canwrite; //condition variable to check whether writer can write
    pthread_mutex_t condlock; //mutex for synchronization
    public:
    monitor(){
        rcnt=0;
        wcnt=0;
        waitr=0;
        waitw=0;
        pthread_cond_init(&canread,NULL);
        pthread_cond_init(&canwrite,NULL);
        pthread_mutex_init(&condlock,NULL);
    }
    //mutex provides sychronization
    void beginread(int i){
        pthread_mutex_lock(&condlock);
        //if there are active or waiting writers
        if(wcnt==1 || waitw>0){
            //incrementing waiting readers
            waitr++;
            //reader suspended
            pthread_cond_wait(&canread,&condlock);
            waitr--;
        }
        //else reader reads the resource
        rcnt++;
        cout<<"Reader "<<i<<" is reading\n";
        pthread_mutex_unlock(&condlock);
        pthread_cond_broadcast(&canread);
    }
    void endread(int i){
        pthread_mutex_lock(&condlock);
        if(rcnt--==0)
            pthread_cond_signal(&canwrite);

        pthread_mutex_unlock(&condlock);
    }
    void beginwrite(int i){
        pthread_mutex_lock(&condlock);
        //a writer can enter if and only if there are no active or waiting readers or other writers
        if(wcnt==1 || rcnt>0){
            waitw++;
            pthread_cond_wait(&canwrite,&condlock);
            waitw--;
        }
        wcnt=1;
        cout<<"Writer "<<i<<" is writing\n";
        pthread_mutex_unlock(&condlock);
    }
    void endwrite(int i){
        pthread_mutex_lock(&condlock);
        wcnt=0;
        //if any readers are waiting, threads are unblocked
        if(waitr>0)
            pthread_cond_signal(&canread);
        else
            pthread_cond_signal(&canwrite);
        pthread_mutex_unlock(&condlock);
    }
}
//global object of monitor class
M;
void*reader(void*id){
    int c=0;
    int i=*(int*)id;
    //each reader attempts to read 5 times
    while(c<5){
        usleep(1);
        M.beginread(i);
        M.endread(i);
        c++;
    }
}
void*writer(void *id){
    int c=0;
    int i=*(int*)id;
    //each reader attempts to read 5 times
    while(c<5){
        usleep(1);
        M.beginwrite(i);
        M.endwrite(i);
        c++;
    }
}
int main(){
    pthread_t r[5],w[5];
    int id[5];
    for(int i=0;i<5;i++){
        id[i]=i;
        //creating threads for reader functions
        pthread_create(&r[i],NULL,&reader,&id[i]);
        //creating threads for writer functions
        pthread_create(&w[i],NULL,&writer,&id[i]);
    }
    for(int i=0;i<5;i++){
        pthread_join(r[i],NULL);
    }
    for(int i=0;i<5;i++){
        pthread_join(w[i],NULL);
    }
}
