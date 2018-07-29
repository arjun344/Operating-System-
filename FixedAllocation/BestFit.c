#include<stdio.h>
#include<stdlib.h>

void swap(int *x, int *y)
{
  int t;
  t = *x;
  *x = *y;
  *y = t;
}

void sort(int *p, int t)
{
   int *i,j;
   for(j=1;j<t;j++)
     for(i=p;i<p+t-j;i++)
        if(*i >= *(i+1))
            swap(i,i+1);
}


 
void main()
{

    printf("Best Fit(Fixed Alloctaion) Programme by Arjun Kumar(16IT108)\n\n");


    int *BlockSize, *ProcessSize, Blockno, Processno, *check, *allocation, i, j;
 
    printf("Enter no. of blocks: ");
    scanf("%d",&Blockno);

    BlockSize = (int*) calloc(Blockno, sizeof(int));

    printf("\nEnter no. of processes: ");
    scanf("%d",&Processno);
    
    ProcessSize = (int*) calloc(Processno, sizeof(int));
    check = (int*) calloc(Blockno, sizeof(int));
    allocation = (int*) calloc(Blockno, sizeof(int));
    
    for(i = 0; i < Blockno; i++)
    {
        check[i] = 0;
        allocation[i] = -1;
    }
    printf("\nEnter size of each block: \n");
    for(i = 0; i < Blockno; i++)
        scanf("%d", &BlockSize[i]);
    printf("\nEnter size of each process: \n");
    for(i = 0; i < Processno; i++)
        scanf("%d", &ProcessSize[i]);

    sort(BlockSize,Blockno);
    
    printf("Best Fit Alloctaion Initiated \n");
    
    for(i = 0; i < Processno; i++)         
        for(j = 0; j < Blockno; j++)
            if(check[j] == 0 && BlockSize[j] >= ProcessSize[i])
            {
                allocation[j] = i;
                check[j] = 1;
                break;
            }
    printf("\nBlock no.\tsize(k)\t\tprocess no.\t\tsize(k)");
    for(i = 0; i < Blockno; i++)
    {
        printf("\n%d\t\t%dk\t\t", i+1, BlockSize[i]);
        if(check[i] == 1)
            printf("%d\t\t\t%dk",allocation[i]+1,ProcessSize[allocation[i]]);
        else
            printf("Not allocated");
    }
    printf("\n");
}