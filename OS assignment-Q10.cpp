/* using banker's algorithm, coded by sriram-11717734*/ 
#include<stdio.h>
int main()
{
	/*P-PROCESSS, R-RESOURCES, i, j, k, n, temp1, temp2 constants*/
	
	int P,R,i,j,temp1=0,k=0,temp2=0,n;
	/*asking for total no.of process*/
	printf("Enter number of process::");
	scanf("%d",&P);
	/*asking for total no.of resources*/
	printf("Enter number of resources::");
	scanf("%d",&R);
	int max[P][R],allocation[P][R],available[R],need[P][R],instance,finish[P],request[P][R];
	for(i=0;i<P;i++)
	{
		finish[i]=0;
	}
	
	/*asking for maximum required instances for each resource in each process*/ 
	printf("Enter Max matrix::\n");
	for(i=0;i<P;i++)
	{
		printf("P[%d]\t",i);
		for(j=0;j<R;j++)
		{
			scanf("\n%d",&instance);
			max[i][j]=instance;
		}
	}
	
	/*asking for allocated instances for each resource in each process*/
	printf("Enter allocation matrix::\n");
	for(i=0;i<P;i++)
	{
		printf("P[%d]\t",i);
		for(j=0;j<R;j++)
		{
			scanf("\n%d",&instance);
			allocation[i][j]=instance;
		}
	}
	
	/*asking for available resources remaining after allocation*/
	printf("Enter available matrix::\n");
	for(j=0;j<R;j++)
	 {
			scanf("\n%d",&instance);
			available[j]=instance;
	 } 
	 
	 //calculating need matrix
	for(i=0;i<P;i++)
	{
		
		for(j=0;j<R;j++)
		{
			need[i][j]=max[i][j]-allocation[i][j];
		}
	}
	
	//printing need matrix
	printf("The need matrix is::");
	for(i=0;i<P;i++)
	{
		printf("\nP[%d]\t",i);
		for(j=0;j<R;j++)
		{
			printf("%d\t",need[i][j]);
		
		}
	}
	printf("\n\n");
	printf("Enter 1 to check a normal safe sequence\n");
	printf("Enter 2 to check the sequence when additional resources are requested by P[0]\n");
	printf("Enter 3 to check the sequence when additional resources are requested by P[1]\n");
	printf("Enter 4 to check the sequence when additional resources are requested by P[2]\n");
	scanf("\n%d",&n);
	
	switch(n)
	{
		/*displaying whether the system is safe or not in current state*/
	case 1:
		
		
	printf("\n\n");
	printf("The safe sequence for the above given processes if additional instances are not requested ::\n");
	printf("\n");
	while(temp1!=P)
	{
		/*checking whether need instances are less than or equal to available instances*/
		for(i=0;i<P;i++)
		{
			for(j=0;j<R;j++)
		   {
		   	 if(need[i][j]<=available[j])
		   	 {
		   	 
		   	 	k++;
		   	
		   	 }
	       }
	       /*if current process is completed then allocated instances are added to available instances*/
	       if(k==R && finish[i]==0)
	       {
	       	printf("P[%d]\t",i);
	       	finish[i]=1;
	       	for(j=0;j<R;j++)
	       	{
	       		available[j]=available[j]+allocation[i][j];
	       	}
	       	temp1++;
	       }
	        k=0;
	    }
		  	
		
	}
	break;
    //For P[0] requesting additional resources:
	case 2:
		
	//asking for additional request from the user	
	printf("Enter additional request by P0 processs\n");
	printf("request[0]::\t");
	for(j=0;j<R;j++)
	{
		
		scanf("%d",&instance);
		request[0][j]=instance;
	}
	for(j=0;j<R;j++)
	{
		if(request[0][j]<=need[0][j])
		{
/*checking whether requested instances are less than or equal to available instances*/
			if(request[0][j]<=available[j])
			{
				available[j]=available[j]-request[0][j];
				allocation[0][j]=allocation[0][j]+request[0][j];
				need[0][j]=need[0][j]-request[0][j];
			}
			else
			{
				printf("P[0] must wait because resources are not available\n");
			}
		}
		else
		{
			printf("The process has exceeded the maximum claim\n");
		}
	}
	printf("The sequence after additional request by P[0] is::::<<");
	while(temp1!=P)
	{
		temp2=temp1;
/*if need instances are less than or equal to available instances then process will execute and allocated get added to available resources*/		
		
		for(i=0;i<P;i++)
		{
			for(j=0;j<R;j++)
			{
				if(need[i][j]<=available[j])
				{
					k++;
				}
			}
			if(k==R && finish[i]==0)
			{
				printf("P[%d]",i);
				finish[i]=1;
				for(j=0;j<R;j++)
				{
					available[j]=available[j]+allocation[i][j];
				}
				temp1++;
			}
			k=0;
		}
		if(temp1==temp2)
		{
			printf("\tThe system is unsafe...there is a deadlock>>\n\n");
			printf("So Reenas operating system is unsafe if the following additional request was requested by P[0]\n");
			break;
		}
	}
	break;
	
	//For P[1] requesting additional resources
	case 3:
		
		/*asking for additional request from the user*/
		printf("Enter additional request by P[1] processs\n");
		printf("request[0]::\t");
	for(j=0;j<R;j++)
	{
		scanf("%d",&instance);
		request[0][j]=instance;
	}
	for(j=0;j<R;j++)
	{
		if(request[0][j]<=need[1][j])
		{
/*checking whether requested instances are less than or equal to available instances*/
	
			if(request[0][j]<=available[j])
			{
				available[j]=available[j]-request[0][j];
				allocation[1][j]=allocation[1][j]+request[0][j];
				need[1][j]=need[1][j]-request[0][j];
			}
			else
			{
				printf("P[1] must wait because resources are not available\n");
			}
		}
		else
		{
			printf("The process has exceeded the maximum claim\n");
		}
	}
	printf("The sequence after additional request by P[1] is::::");
	while(temp1!=P)
	{
		temp2=temp1;
/*if need instances  are less than or equal to available instances then process will execute and allocated get added to available resources*/				
		for(i=0;i<P;i++)
		{
			for(j=0;j<R;j++)
			{
				if(need[i][j]<=available[j])
				{
					k++;
				}
			}
			if(k==R && finish[i]==0)
			{
				printf("P[%d]\t",i);
				finish[i]=1;
				for(j=0;j<R;j++)
				{
					available[j]=available[j]+allocation[i][j];
				}
				temp1++;
			}
			k=0;
		}
	
		if(temp1==temp2)
		{
			printf("\tThe system is unsafe...there is a deadlock>>\n\n");
			printf("So Reenas operating system is unsafe if the following additional request was requested by P[0]\n");
			break;
		}
		
	}
	break;
	
	 /*For P[2] requesting additional resources:*/
	case 4:
		
	/*asking for additional request from the user*/
	printf("Enter additional request by P[2] processs\n");
	printf("request[0]::\t");
	for(j=0;j<R;j++)
	{
		
		scanf("%d",&instance);
		request[0][j]=instance;
	}
	for(j=0;j<R;j++)
	{
		if(request[0][j]<=need[2][j])
		{
/*checking whether requested instances are less than or equal to available instances*/
			if(request[0][j]<=available[j])
			{
				available[j]=available[j]-request[0][j];
				allocation[2][j]=allocation[2][j]+request[0][j];
				need[2][j]=need[2][j]-request[2][j];
			}
			else
			{
				printf("P[2] must wait because resources are not available\n");
			}
		}
		else
		{
			printf("The process has exceeded the maximum claim\n");
		}
	}
	printf("The sequence after additional request by P[2] is::::<<");
	while(temp1!=P)
	{
		temp2=temp1;
/*if need instances are less than or equal to available instances then process will execute and allocated get added to available resources*/		
		for(i=0;i<P;i++)
		{
			for(j=0;j<R;j++)
			{
				if(need[i][j]<=available[j])
				{
					k++;
				}
			}
			if(k==R && finish[i]==0)
			{
				printf("P[%d]",i);
				finish[i]=1;
				for(j=0;j<R;j++)
				{
					available[j]=available[j]+allocation[i][j];
				}
				temp1++;
			}
			k=0;
		}
		if(temp1==temp2)
		{
			printf("\tThe system is unsafe...there is a deadlock>>\n\n");
			printf("So Reenas operating system is unsafe if the following additional request was requested by P[2]\n");
			break;
		}
	}
	break;
	
	default:
	printf("      ' SORRY: INVALID ENTRY. ' ");		 
}
	
	return 0;
}

