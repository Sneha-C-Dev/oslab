#include <stdio.h>
#include <stdlib.h>

void calc_need(int** need, int no_p, int no_r, const int max[no_p][no_r], const int alloc[no_p][no_r])
{
	for(int i=0; i<no_p; i++)
	{
		for(int j=0; j<no_r; j++)
			need[i][j] = max[i][j] - alloc[i][j];
	}
}
void get_sequence(int* c, int* sequence, int no_p, int no_r, const int max[no_p][no_r], const int alloc[no_p][no_r], const int avail[no_r], int **need)
{
	*c = 1;
	int work[no_r];
	int finish[no_p];
	for(int i=0; i<no_r; i++)
	{
		sequence[i] = -1;
		work[i] = avail[i];
	}
	for(int i=0; i<no_p; i++)
		finish[i] = 0;

	int flag = -1, seq_pos = 0;
	for(int i=0; flag != i && seq_pos < no_p; i = (i+1)%no_p)
	{
		if(flag == -1)
			flag = i;
		int f = 1;
		if(!finish[i])
		{
			for(int j=0; j<no_r; j++)
			{
				if(need[i][j] > work[j])
				{
					f = 0;
					break;
				}
			}
		}
		else
			f = 0;
		if(f == 1)
		{
			flag = i;
			finish[i] = 1;
			for(int j=0; j<no_r; j++)
				work[j] += alloc[i][j];
			sequence[seq_pos] = i;
			seq_pos++;
		}
	}
	if(seq_pos != no_p)
		*c = 0;
}

int main()
{
	int no_p, no_r, p;
	printf("Enter number of processes: "); scanf("%d", &no_p);
	printf("Enter number of resources: "); scanf("%d", &no_r);
	int max[no_p][no_r], alloc[no_p][no_r], avail[no_r], request[no_r], sequence[no_p];
	printf("Enter maximum (PxR):\n");
	for(int i=0; i<no_p; i++)
	{
		for(int j=0; j<no_r; j++)
			scanf("%d",&(max[i][j]));
	}
	printf("Enter allocated (PxR):\n");
	for(int i=0; i<no_p; i++)
	{
		for(int j=0; j<no_r; j++)
			scanf("%d",&(alloc[i][j]));
	}
	printf("Enter available (R):\n");
	for(int i=0; i<no_r; i++)
	{
		scanf("%d",&(avail[i]));
	}

	int c = 1;
	int** need = malloc(no_p * sizeof(int*));
	for(int i=0; i<no_p; i++)
		need[i] = malloc(no_r * sizeof(int));

	calc_need(need, no_p, no_r, max, alloc);
	printf("Need:\n");
	for(int i=0; i<no_p; i++)
	{
		for(int j=0; j<no_r; j++)
		{
			printf("%d\t", need[i][j]);
			if(need[i][j] < 0)
				c = 0;
		}
		printf("\n");
	}
	if(c == 0)
	{
		printf("Invalid state.\n");
		return 0;
	}
	get_sequence(&c, sequence, no_p, no_r, max, alloc, avail, need);
	do
	{
		printf("Enter request: (P, resource needs):\n");
		scanf("%d",&p);
		for(int i=0; i<no_r; i++)
		{
			scanf("%d",&(request[i]));
		}

		int allowed = 1;
		for(int i=0; i<no_r; i++)
		{
			if(avail[i] < request[i] || need[p][i] < request[i])
				allowed = 0;
			avail[i] -= request[i];
			alloc[p][i] += request[i];
			need[p][i] -= request[i];
		}

		if(allowed)
		{
			printf("Need:\n");
			for(int i=0; i<no_p; i++)
			{
				for(int j=0; j<no_r; j++)
					printf("%d\t", need[i][j]);
				printf("\n");
			}
			get_sequence(&allowed, sequence, no_p, no_r, max, alloc, avail, need);
			if(!allowed)
			{
				printf("Unsafe state. ");
			}
			else
			{
				printf("Safe Sequence: ");
				for(int j=0; j<no_p; j++)
					printf("%d\t", sequence[j]);
				printf("\n");
			}
		}
		if(!allowed)
		{
			printf("Request denied. ");
			for(int i=0; i<no_r; i++)
			{
				avail[i] += request[i];
				alloc[p][i] -= request[i];
				need[p][i] += request[i];
			}
		}

		printf("Another request? (1 or 0): ");
		scanf("%d",&c);
	}
	while(c>0);
	for(int i=0; i<no_p; i++)
		free(need[i]);
	free(need);
}
