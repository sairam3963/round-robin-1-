#include<stdio.h> 

int main() 
{ 
 
  int i,j,n,time,p,flag=0,slice; 
  int waittime=0,turntime=0,at[10],bt[10],rt[10]; 
  printf("Enter Total Process:\t "); 
  scanf("%d",&n); 
  p=n; 
  for(i=0;i<n;i++) 
  { 
    printf("Enter Arrival Time for Process Number %d :",i+1); 
    scanf("%d",&at[i]); 
    printf("Enter Burst Time for Process Number %d :",i+1);
    scanf("%d",&bt[i]); 
    rt[i]=bt[i]; 
  } 
  printf("Enter Time slice:\t"); 
  scanf("%d",&slice); 
printf("\n the turnaround time and waiting time for the given data is\n");
printf("\nprocess\t|Arrival time\t|burst time \n\n");
for(i=0;i<n;i++)
{
   printf("%d\t|\t%d\t|\t%d",i+1,at[i],bt[i]);
   printf("\n");
}
  printf("\n\nProcess\t|Turnaround Time|Waiting Time\n\n"); 
  for(time=0,i=0;p!=0;) 
  { 
    if(rt[i]<=slice && rt[i]>0) 
    { 
      time=time+rt[i]; 
      rt[i]=0; 
      flag=1; 
    } 
    else if(rt[i]>0) 
    { 
      rt[i]=rt[i]-slice; 
      time=time+slice; 
    } 
    if(rt[i]==0 && flag==1) 
    { 
      p=p-1; 
      printf("P[%d]\t|\t%d\t|\t%d\n",i+1,time-at[i],time-at[i]-bt[i]); 
      waittime=waittime+time-at[i]-bt[i]; 
      turntime=turntime+time-at[i]; 
      flag=0; 
    } 
    if(i==n-1) 
      i=0; 
    else if(at[i+1]<=time) 
      i++; 
    else 
      i=0; 
  } 
  printf("\nAverage Waiting Time= %f\n",waittime*1.0/n); 
  printf("Avg Turnaround Time = %f",turntime*1.0/n); 
  
  return 0; 
}
