/*
#include <stdio.h>

typedef struct {
    int pid ; 
    int priority ;
    int arrival_time ; 
    int burst_time ;
    int completion_time ;
    int turnaround_time ;
    int waiting_time ;
    int response_time ;
} Process ;

void swap(Process *a , Process *b){
    Process temp = *a ;
    *a = *b ;
    *b = temp ;
}

void sort(Process *p , int n){
    for(int i = 0 ; i < n ; i++){
        for(int j = i+1 ; j < n ; j++){
            if(p[i].arrival_time > p[j].arrival_time){
                swap(&p[i] , &p[j]) ;
            }
        }
    }
}

void create(Process *p , int n){
    for(int i = 0 ; i < n ; i++){
        p[i].pid = i+1 ;
        printf("ENTER THE PRIORITY, ARRIVAL TIME AND BURST TIME OF PROCESS %d : " , i+1) ;
        scanf("%d%d%d" , &p[i].priority, &p[i].arrival_time , &p[i].burst_time) ;
    }
}

void display(Process *p , int n){
    printf("PID\tPR\tAT\tBT\tCT\tTAT\tWT\tRT\n") ;
    for(int i = 0 ; i < n ; i++){
        printf("%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d\n" , p[i].pid , p[i].priority, p[i].arrival_time , p[i].burst_time , p[i].completion_time , p[i].turnaround_time , p[i].waiting_time, p[i].response_time) ;
    }
}

void statistics(Process *p , int n){
    float avg_tat = 0 , avg_wt = 0 , total_bt = 0, avg_rt = 0, max_completion_time = 0  ;
    for(int i = 0 ; i < n ; i++){
        avg_tat += p[i].turnaround_time ;
        avg_wt += p[i].waiting_time ;
        total_bt += p[i].burst_time ;
        avg_rt += p[i].response_time ;
        if(p[i].completion_time > max_completion_time){
            max_completion_time = p[i].completion_time ;
        }
    }
    float cpu_utilization = total_bt / max_completion_time ;
    float throughput = n / max_completion_time;

    printf("AVERAGE TURNAROUND TIME : %f\n" , avg_tat/n) ;
    printf("AVERAGE WAITING TIME    : %f\n" , avg_wt/n) ;
    printf("AVERAGE RESPONSE TIME   : %f\n" , avg_rt/n) ;
    printf("CPU UTILIZATION(PERCENT): %f\n" , cpu_utilization*100) ;
    printf("THROUGHPUT              : %f\n" , throughput) ;    
}

void priorityScheduling(Process *p, int n) {
    sort(p, n);
    int hash[n];
    int time = 0;
    for (int i = 0; i < n; i++) {
        hash[i] = 0;
    }
    for (int i = 0; i < n; i++) {
        int min = 1000000;
        int index = -1;
        for (int j = 0; j < n; j++) {
            if (hash[j] == 0 && p[j].arrival_time <= time && p[j].priority < min) {
                min = p[j].priority;
                index = j;
            }
        }
        if (index == -1) {
            continue;
        }
        hash[index] = 1;
        p[index].response_time = time - p[index].arrival_time;
        if (p[index].response_time < 0) {
            p[index].response_time = 0;
        }
        p[index].waiting_time = time - p[index].arrival_time;
        if (p[index].waiting_time < 0) {
            p[index].waiting_time = 0;
        }
        time += p[index].burst_time;
        p[index].completion_time = time;
        p[index].turnaround_time = p[index].completion_time - p[index].arrival_time;
    }
}


int main(){
    int n ;
    printf("ENTER THE NUMBER OF PROCESSES : ") ;
    scanf("%d" , &n) ;
    Process p[n] ;
    create(p , n) ;
    sort(p , n) ;
    priorityScheduling(p , n) ;
    display(p , n) ;
    statistics(p , n) ;
    return 0 ;
}
*/

#include<stdio.h>

struct Process{
    int bt,wt,tt,pid,priority;
};

int main(){
    int n,waitingtime,totaltime=0,twait=0, tturnaround=0;
    printf("Enter number of process:");
    scanf("%d",&n);
    struct Process p[n];
    for(int i=0;i<n;i++){
        printf("Enter burst time and priority of Process%d: ",i+1);
        scanf("%d %d",&p[i].bt, &p[i].priority);
        p[i].pid=i+1;
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<n-i-1;j++){
            if(p[j].priority>p[j+1].priority){
                struct Process temp;
                temp=p[j];
                p[j]=p[j+1];
                p[j+1]=temp;
            }
        }
    }
    for(int i=0;i<n;i++){
        p[i].wt=totaltime;
        totaltime+=p[i].bt;
        twait+=p[i].wt;
        p[i].tt=p[i].bt+p[i].wt;
        tturnaround+=p[i].tt;
    }
    printf("------------------------------------------\n");
    printf(" Process\t BT \t WT \t TT \t Priority\n");
    for(int i=0;i<n;i++){
        printf(" %d\t\t%d \t %d \t %d \t %d\n",p[i].pid,p[i].bt,p[i].wt,p[i].tt,p[i].priority);
    }
    printf("------------------------------------------\n");
    twait=twait/n;
    tturnaround=tturnaround/n;
    printf("Average Wait time:%d\n",twait);
    printf("Average TurnAround time:%d\n",tturnaround);
    return 0;
}
