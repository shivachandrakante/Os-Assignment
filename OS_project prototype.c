#include <stdio.h>
 
int current[5][5], maximum_requested[5][5], available[5];
int allocation[5] = {0, 0, 0, 0, 0};
int maxinstances[5], Executing[5], safe = 0;
int counter = 0, i, j, exec, resources, processes, k = 1;
 
int main()
{
		printf("\nEnter number of processes: ");
    	scanf("%d", &processes);
 
    	for (i = 0; i < processes; i++) 
		{
        	Executing[i] = 1;
        	counter++;
    	}
 
    	printf("\nEnter number of resources: ");
    	scanf("%d", &resources);
 
    	
    	for (i = 0; i < resources; i++) 
		{ 
			printf("\nEnter no of instance's for %d resource  ",i+1 );
	        scanf("%d", &maxinstances[i]);
    	}
 
   		printf("\nEnter Allocated Resource Table:\n");
        for (i = 0; i < resources; i++) 
		{
			printf("\n");
        	for(j = 0; j < processes; j++) 
			{
  				scanf("%d", &current[j][i]);
        	}
    	}
/*		for (i = 0; i < processes; i++) 
		{
			printf("\n");
	        for(j = 0; j < resources; j++) 
			{
  				scanf("%d", &current[i][j]);
        	}
    	}
*/ 
    	printf("\nEnter Maximum Need Table:\n");
    	for (i = 0; i < resources; i++) 
		{
			printf("\n");
        	for(j = 0; j < processes; j++) 
			{
            	scanf("%d", &maximum_requested[j][i]);
        	}
    	}
/*    	for (i = 0; i < processes; i++) 
		{
			printf("\n");
        	for(j = 0; j < resources; j++) 
			{
          		scanf("%d", &maximum_requested[i][j]);
        	}
    	}
*/ 
		printf("\nThe Maxium Instances are: ");
    	for (i = 0; i < resources; i++) 
		{
	    	printf("\t%d", maxinstances[i]);
		}
 
    	printf("\nThe Allocated Resource Table:\n");
    	for (i = 0; i < processes; i++) 
		{
	        for (j = 0; j < resources; j++) 
			{
            	printf("\t%d", current[i][j]);
        	}
			printf("\n");
    	}
 
    	printf("\nThe Maximum Claim Table:\n");
    	for (i = 0; i < processes; i++) 
		{
        	for (j = 0; j < resources; j++) 
			{
		        printf("\t%d", maximum_requested[i][j]);
        	}
        	printf("\n");
    	}
 
    	for (i = 0; i < processes; i++) 
		{
        	for (j = 0; j < resources; j++) 
			{
            		allocation[j] += current[i][j];
        	}
    	}
 
    	printf("\nAllocated resources:");
    	for (i = 0; i < resources; i++) 
		{
        	printf("\t%d", allocation[i]);
    	}
 
    	for (i = 0; i < resources; i++) 
		{
	        available[i] = maxinstances[i] - allocation[i];
		}
 
    	printf("\nAvailable resources:");
    	for (i = 0; i < resources; i++) 
		{
        	printf("\t%d", available[i]);
    	}
    	printf("\n");
 
    	while (counter != 0) 
		{
        	safe = 0;
        	for (i = 0; i < processes; i++) 
			{
            	if (Executing[i]) 
				{
                	exec = 1;
                	for (j = 0; j < resources; j++) 
					{
                    	if (maximum_requested[i][j] - current[i][j] > available[j]) 
						{
                        	exec = 0;
                        	break;
                    	}
                	}
                	if (exec) 
					{
                    	printf("\nProcess %d is executing\n", i );
                    	Executing[i] = 0;
                    	counter--;
                    	safe = 1;
                  		for (j = 0; j < resources; j++) 
						{
                        	available[j] += current[i][j];
                    	}
			            break;
                	}
            	}
        	}
        	if (!safe) 
			{
            	printf("\nThe processes are in unsafe state.\n");
            	break;
        	} 
			else 
			{
            	printf("\nThe process is in safe state");
            	printf("\nAvailable vector:");
            	for (i = 0; i < resources; i++) 
				{
                	printf("\t%d", available[i]);
            	}
		        printf("\n");
        	}
    	}
    	return 0;
}
