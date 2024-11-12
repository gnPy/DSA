#include <stdio.h>

typedef struct{
    int pid ; 
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
        printf("ENTER THE ARRIVAL TIME AND BURST TIME OF PROCESS %d : " , i+1) ;
        scanf("%d%d" , &p[i].arrival_time , &p[i].burst_time) ;
    }
}

void display(Process *p , int n){
    printf("PID\tAT\tBT\tCT\tTAT\tWT\tRT\n") ;
    for(int i = 0 ; i < n ; i++){
        printf("%d\t%d\t%d\t%d\t%d\t%d\t%d\n" , p[i].pid , p[i].arrival_time , p[i].burst_time , p[i].completion_time , p[i].turnaround_time , p[i].waiting_time, p[i].response_time) ;
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

void sjf(Process *p , int n){
    int hash[n] ; 
    for(int i = 0 ; i < n ; i++){
        hash[i] = 0 ;
    }
    sort(p , n) ;
    int current_time = 0 ;
    for(int i = 0 ; i < n ; i++){
        int min = 9999 , index = -1 ;
        for(int j = 0 ; j < n ; j++){
            if(hash[j] == 0 && p[j].arrival_time <= current_time && p[j].burst_time < min){
                min = p[j].burst_time ;
                index = j ;
            }
        }
        if(index == -1){
            continue ;
        }
        hash[index] = 1 ;
        p[index].completion_time = current_time + p[index].burst_time ;
        p[index].turnaround_time = p[index].completion_time - p[index].arrival_time ;
        p[index].waiting_time = p[index].turnaround_time - p[index].burst_time ;
        p[index].response_time = current_time - p[index].arrival_time ;
        current_time = p[index].completion_time ;
    }
}

int main(){
    int n ;
    printf("ENTER THE NUMBER OF PROCESSES : ") ;
    scanf("%d" , &n) ;
    Process p[n] ;
    create(p , n) ;
    sjf(p , n) ;
    display(p , n) ;
    statistics(p , n) ;
}