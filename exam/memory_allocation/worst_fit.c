#include<stdio.h>

void main () {
    int bno, pno, i, j;

    printf("Enter number of blocks: ");
    scanf("%d", &bno);

    printf("Enter number of processes: ");
    scanf("%d", &pno);

    int bsize[bno], psize[pno], all[pno];

    printf("Enter the size of each block: ");
    for (i = 0; i < bno; i++)
        scanf("%d", &bsize[i]);

    printf("Enter the size of each process: ");
    for (i = 0; i < pno; i++) {
        scanf("%d", &psize[i]);
        all[i] = -1;
    }

    for (i = 0; i < bno; i++) {
        int worst_place = -1;
        for (j = 0; j < pno; j++) {
            if (bsize[j] > psize[i]) {
                if (worst_place == -1)
                    worst_place = j;
                else if (bsize[worst_place] < bsize[j])
                    worst_place = j;
            }

        }
        printf("%d\t%d\t", i + 1, psize[i]);
        if (all[i] != -1)
            printf("%d\n", all[i] + 1);
        else printf("Not allocated");
    }
        
}
