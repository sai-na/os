#include <stdio.h>

void main()
{
    int fragment[20], b[20], p[20], nb, np, temp, lowest = 999, i, j;
    static int barray[20], parray[20];

    printf("Enter number of blocks: ");
    scanf("%d", &nb);

    printf("Enter number of processes: ");
    scanf("%d", &np);

    printf("Enter the size of blocks: ");
    for (i = 1; i < nb; i++)
        scanf("%d", &b[i]);

    printf("Enter the size of processes: ");
    for (i = 1; i < np; i++)
        scanf("%d", &p[i]);

    for (i = 1; i < np; i++)
    {
        for (j = 1; j < nb; j++)
        {
            if (barray[i] != 1)
            {
                temp = b[j] - p[j];
                if (temp >= 0)
                {
                    if (lowest > temp)
                    {
                        parray[i] = j;
                        lowest = temp;
                    }
                }
            }
            fragment[i] = lowest;
            barray[parray[i] = 1];
            lowest = 10000;
        }
        printf("\nProcess No.\tProcess Size\tBlock No.\t\tBlock SIze\tFragment\n");
        for (i = 1; i < np; i++)
            printf("\n%d\t\t%d\t\t%d\t\t%d\t\t%d", i, p[i], parray[i], b[parray[i]], fragment[i]);
    }
}
