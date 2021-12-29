#include<stdio.h>
#include<malloc.h>

void main()
{
	int n, i, j, pos, temp, *bt, *wt, *tat, *p;

        int count = 1;

	int *at,*ar,burst_no;
	float avgwt = 0, avgtat = 0;
	printf("\n Enter the number of processes : ");
    scanf("%d", &n);

	at  = (int*)malloc(n*sizeof(int));
	ar = (int*)malloc(n*sizeof(int));

    p = (int*)malloc(n*sizeof(int));
    bt = (int*)malloc(n*sizeof(int));
    wt = (int*)malloc(n*sizeof(int));
    tat = (int*)malloc(n*sizeof(int));
 	
	    printf("\n Enter the arrival time for each process \n");
	for(i=0; i<n; i++)
	{
	    printf(" Arrival time for P%d : ", i);
        scanf("%d", &at[i]);
	}
	
 	    printf("\n Enter the burst time for each process \n");
    for(i=0; i<n; i++)
    {
        printf(" Burst time for P%d : ", i);
        scanf("%d", &bt[i]);
        p[i] = i;
    }
    for(int i=0;i<n;i++)
    {
		if(at[i]>bt[0])
		{
			count++;
		}
    }
	
    for(i=count; i<n-(count-1); i++)
    {
    	pos = i;
    	for(j=i+1; j<n; j++)
    	{
    		if(bt[j] < bt[pos])
    		{
    			pos = j;
    		}
    	}
    	temp = bt[i];
    	bt[i] = bt[pos];
    	bt[pos] = temp;

    	temp = p[i];
    	p[i] = p[pos];
    	p[pos] = temp;
		
		temp = at[i];
    	at[i] = at[pos];
    	at[pos] = temp;
    }
	
    wt[0] = 0;
    tat[0] = bt[0];
    avgwt = wt[0];
    avgtat = tat[0];
    
	burst_no=bt[0];
	
    for(i=1; i<n; i++)
    {
        wt[i] = (burst_no)-at[i]+at[0];  //waiting time[p] = waiting time[p-1] + Burst Time[p-1]
        tat[i] = wt[i] + bt[i];           //Turnaround Time = Waiting Time + Burst Time
              
        burst_no+=bt[i];
        
        avgwt += wt[i];
        avgtat += tat[i];
    }

 
    avgwt = avgwt/n;
    avgtat = avgtat/n;

    printf("\n PROCESS \t BURST TIME \t WAITING TIME \t TURNAROUND TIME \n");
    printf("____________________________________________________________\n");
    for(i=0; i<n; i++)
    {
        printf(" P%d \t\t %d \t\t %d \t\t %d \n", i, bt[i], wt[i], tat[i]);
    }

    printf("\n Average Waiting Time = %f \n Average Turnaround Time = %f \n", avgwt, avgtat);

    printf("\n \tGAANT CHART \n");
    printf("__________________________\n");
    for(i=0; i<n; i++)
    {
        printf(" %d\t|| P%d ||\t%d\n", wt[i], i, tat[i]);
    }
	
	
}