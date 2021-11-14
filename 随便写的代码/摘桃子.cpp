#include <stdio.h>
#define N 3005
int peach_per_day[N] = {0};
int main(){
    int n,v;
    scanf("%d %d", &n, &v);
    int i,j;
    int day, peach;
    for(i=0;i<n;i++){
        scanf("%d %d", &day, &peach);
        peach_per_day[day] += peach;
    }

    int peach_cnt = 0;
    // on first day, pick as many peaches as you can
    if(peach_per_day[0] <= v){
        peach_cnt += peach_per_day[0];
        peach_per_day[0] = 0;
    }
    else{
        peach_cnt = v;
        peach_per_day[0] -= v;
    }

    int health;
    for(i = 1;i<N;i++){
        health = v;
        // pick last day's left peaches first
        if(peach_per_day[i-1] <= health){
            health -= peach_per_day[i-1];
            peach_per_day[i-1] = 0;
        }
        else{
            peach_per_day[i-1] -= health;
            health = 0;
        }

        // pick today's peach
        if(peach_per_day[i] <= health){
            health -= peach_per_day[i];
            peach_per_day[i] = 0;
        }
        else{
            peach_per_day[i] -= health;
            health = 0;
        }

        peach_cnt += (v - health);
    }

    printf("%d\n", peach_cnt);
}
