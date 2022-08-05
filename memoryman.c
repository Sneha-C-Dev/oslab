//first_fit
// C implementation of First - Fit algorithm
#include<stdio.h>

// Function to allocate memory to
// blocks as per First fit algorithm
void firstFit(int blockSize[], int m, int processSize[], int n)
{
	int i, j;
	// Stores block id of the
	// block allocated to a process
	int allocation[n];

	// Initially no block is assigned to any process
	for(i = 0; i < n; i++)
	{
		allocation[i] = -1;
	}

	// pick each process and find suitable blocks
	// according to its size ad assign to it
	for (i = 0; i < n; i++)	 //here, n -> number of processes
	{
		for (j = 0; j < m; j++)	 //here, m -> number of blocks
		{
			if (blockSize[j] >= processSize[i])
			{
				// allocating block j to the ith process
				allocation[i] = j;

				// Reduce available memory in this block.
				blockSize[j] -= processSize[i];

				break; //go to the next process in the queue
			}
		}
	}

	printf("\nProcess No.\tProcess Size\tBlock no.\n");
	for (int i = 0; i < n; i++)
	{
		printf(" %i\t\t\t", i+1);
		printf("%i\t\t\t\t", processSize[i]);
		if (allocation[i] != -1)
			printf("%i", allocation[i] + 1);
		else
			printf("Not Allocated");
		printf("\n");
	}
}

// Driver code
int main()
{
	int m; //number of blocks in the memory
	int n; //number of processes in the input queue
	int blockSize[] = {100, 500, 200, 300, 600};
	int processSize[] = {212, 417, 112, 426};
	m = sizeof(blockSize) / sizeof(blockSize[0]);
	n = sizeof(processSize) / sizeof(processSize[0]);

	firstFit(blockSize, m, processSize, n);

	return 0 ;
}


//worst fit
// C++ implementation of worst - Fit algorithm
#include<bits/stdc++.h>
using namespace std;

// Function to allocate memory to blocks as per worst fit
// algorithm
void worstFit(int blockSize[], int m, int processSize[],
												int n)
{
	// Stores block id of the block allocated to a
	// process
	int allocation[n];

	// Initially no block is assigned to any process
	memset(allocation, -1, sizeof(allocation));

	// pick each process and find suitable blocks
	// according to its size ad assign to it
	for (int i=0; i<n; i++)
	{
		// Find the best fit block for current process
		int wstIdx = -1;
		for (int j=0; j<m; j++)
		{
			if (blockSize[j] >= processSize[i])
			{
				if (wstIdx == -1)
					wstIdx = j;
				else if (blockSize[wstIdx] < blockSize[j])
					wstIdx = j;
			}
		}

		// If we could find a block for current process
		if (wstIdx != -1)
		{
			// allocate block j to p[i] process
			allocation[i] = wstIdx;

			// Reduce available memory in this block.
			blockSize[wstIdx] -= processSize[i];
		}
	}

	cout << "\nProcess No.\tProcess Size\tBlock no.\n";
	for (int i = 0; i < n; i++)
	{
		cout << " " << i+1 << "\t\t" << processSize[i] << "\t\t";
		if (allocation[i] != -1)
			cout << allocation[i] + 1;
		else
			cout << "Not Allocated";
		cout << endl;
	}
}

// Driver code
int main()
{
	int blockSize[] = {100, 500, 200, 300, 600};
	int processSize[] = {212, 417, 112, 426};
	int m = sizeof(blockSize)/sizeof(blockSize[0]);
	int n = sizeof(processSize)/sizeof(processSize[0]);

	worstFit(blockSize, m, processSize, n);

	return 0 ;
}


//best fit
#include<stdio.h>
void main()
{
int a[20],p[20],i,j,n,m;
printf("Enter no of Blocks.\n");
scanf("%d",&n);
for(i=0;i<n;i++)
{
                        printf("Enter the %dst Block size:",i);
                        scanf("%d",&a[i]);
}
printf("Enter no of Process.\n");
scanf("%d",&m);
for(i=0;i<m;i++)
{
                        printf("Enter the size of %dst Process:",i);
                        scanf("%d",&p[i]);
}
            for(i=0;i<n;i++)
{
for(j=0;j<m;j++)
                        {
                                    if(p[j]<=a[i])
                                    {
                                                printf("The Process %d allocated to %d\n",j,a[i]);
                                                p[j]=10000;
                                                break;
                                    }
                        }
}
for(j=0;j<m;j++)
{
if(p[j]!=10000)
                        {
printf("The Process %d is not allocated\n",j);
                        }
}
}
