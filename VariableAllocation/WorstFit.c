#include<stdio.h>
#include<stdlib.h>

struct Allocation
{
    int Process;
    int fragment[5];
    int diff;
};

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
        if(*i <= *(i+1))
            swap(i,i+1);
}
 
void main()
{

    printf("Worst Fit(Variable Allocation) Programme by Arjun Kumar(16IT108)\n\n");

    int *BlockSize, *ProcessSize, Blockno, Processno, *check, i, j,k;


     
 
    printf("Enter no. of blocks: ");
    scanf("%d",&Blockno);

    struct Allocation allocated[Blockno];

    for(i=0;i<Blockno;i++)
    {
        allocated[i].diff=0;
        allocated[i].Process=0;
        for(j=0;j<5;j++)
        {
            allocated[i].fragment[j]=0;
        }
    }

    BlockSize = (int*) calloc(Blockno, sizeof(int));

    printf("\nEnter no. of processes: ");
    scanf("%d",&Processno);
    
    ProcessSize = (int*) calloc(Processno, sizeof(int));
    check = (int*) calloc(Blockno, sizeof(int));

    printf("\nEnter size of each block: \n");
    for(i = 0; i < Blockno; i++)
        scanf("%d", &BlockSize[i]);
    printf("\nEnter size of each process: \n");
    for(i = 0; i < Processno; i++)
        scanf("%d", &ProcessSize[i]);
    printf("Worst Fit Allocation inititaed\n");

    sort(BlockSize,Blockno);

    for(i = 0; i < Blockno; i++)
    {
        check[i] = 0;
    }
    
    for(i=0;i<Processno;i++)
        for(j=0;j<Blockno;j++)
            if(BlockSize[j] >= ProcessSize[i] && allocated[j].diff < ProcessSize[i] && check[j]==0 )
            {
                allocated[j].Process = i;
                allocated[j].diff=BlockSize[j]-ProcessSize[i];
                check[j] = 1;
                break;
            }
            else if(allocated[j].diff > 0 && BlockSize[j] >= ProcessSize[i] && check[j]==1 && ProcessSize[i] <= allocated[j].diff)
            {
                for(k=0;k<5;k++)
                    if(allocated[j].fragment[k] == 0)
                        {
                            allocated[j].fragment[k] = i;
                            allocated[j].diff=allocated[j].diff - ProcessSize[i];
                            break;
                        }
                break;
            }

    for(i = 0; i < Blockno; i++)
    {
        printf("Processes in Block %d are : \n",i+1);
            if(check[i] == 1)
            {
                printf("%d\n",allocated[i].Process+1);
                for(j=0;j<5;j++)
                {
                    if(allocated[i].fragment[j] != 0)
                    {
                        printf("%d\n",allocated[i].fragment[j]+1);
                    }
                }
            }
            else
                printf("Not Allocated\n");
    }
    printf("\n");
}