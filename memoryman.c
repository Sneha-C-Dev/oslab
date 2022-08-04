//first_fit
#include <stdio.h>
int main()
{
 int bsize[10],psize[10],bno,pno,allocation[10],i,j;
  for(i=0;i<10;i++)
    allocation[i]=-1;
  printf("Enter the number of blocks:");
  scanf("%d",&bno);
  printf("\nEnter the size of each block:");
  for(i=0;i<bno;i++)
  {
     printf("Memory block %d",bno);
     scanf("%d",&bsize[i]);
  }
  printf("\nEnter the number of processes:");
  scanf("%d",&pno);
  printf("Enter the size of each process:");
  for(j=0;j<pno;j++)
  {
      printf("process %d:",i+1);
      scanf("%d",&psize[i]);
  }
  
  for()
}
