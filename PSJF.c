#include<stdio.h>
int main(){
    int n,time=0,completed=0;
    printf("Enter the number of process\n");
    scanf("%d",&n);
    int at[n],bt[n],rt[n];
    for(int i=0;i<n;i++){
        printf("Enter the arrival time and burst time of p%d",i+1);
        scanf("%d%d",&at[i],&bt[i]);
        rt[i]=bt[i];
    }
    while(completed!=n){
        int shortest =-1;
        for(int i=0;i<n;i++){
            if(at[i]<=time && rt[i]>0){
                if(shortest == -1 || rt[i]<rt[shortest]){
                    shortest = i;
                }
            }
        }
        if(shortest == -1){
            time++;
            continue;
        }
        printf("Time %d : p%d\n",time , shortest+1);
        rt[shortest]--;
        if(rt[shortest]==0){
            completed++;
            printf("\n p%d completed at time %d\n",shortest+1,time );
        }
        time ++;
    }
    return 0;
}
