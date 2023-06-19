#include<stdio.h>

void main()
{
    int bno, pno, flags[10], i, j;

    printf("Enter number of blocks: ");
    scanf("%d", &bno);

    printf("Enter number of processes: ");
    scanf("%d", &pno);

    int bsize[bno], psize[pno], allocation[pno];
    
    printf("Enter the size of each block: ");
    for (i = 0; i < bno; i++)
        scanf("%d", &bsize[i]);

    printf("Enter the size of each process: ");
    for (i = 0; i < pno; i++) {
        scanf("%d", &psize[i]);
        flags[i] = 0;
        allocation[i] = -1;
    }

    for (i = 0; i < pno; i++)
    {
        for (j = 0; j < bno; j++)
        {
            if (bsize[j] > psize[i])
            {
                allocation[i] = j;
                bsize[j] = psize[i];
                break;
            }
        }
    }

    printf("\nProcess No.\tProcess Size\tBlock No.\n");
    for (i = 0; i < pno; i++)
        printf("%d\t%d\t%d\n", i + 1, psize[i] );

    if (allocation[i] != -1)
        printf("%d", allocation[i] + 1);
    else
        printf("Not allocated");
}
