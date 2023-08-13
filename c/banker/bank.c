#include <stdio.h>
int main()
{
    int n, m, i, j, k, y, alloc[20][20], max[20][20], avail[50], ind = 0;
    printf("Enter the no of Process:");
    scanf("%d", &n);
    printf("Enter the no of Resources:");
    scanf("%d", &m);
    printf("Enter the Allocation Matrix:");
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < m; j++)
            scanf("%d", &alloc[i][j]);
    }
    printf("Enter the Max Matrix:");
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < m; j++)
            scanf("%d", &max[i][j]);
    }
    printf("Enter the Available Matrix");
    for (i = 0; i < m; i++)
        scanf("%d", &avail[i]);
    int finish[n], safesequence[n], work[m], need[n][m];
    // calculating NEED matrix
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < m; j++)
            need[i][j] = max[i][j] - alloc[i][j];
    }
    printf("NEED matrix is");
    for (i = 0; i < n; i++)
    {
        printf("\n");
        for (j = 0; j < m; j++)
            printf(" %d ", need[i][j]);
    }
    for (i = 0; i < m; i++)
    {
        work[i] = avail[i];
    }
    for (i = 0; i < n; i++)
    {
        finish[i] = 0;
    }
    for (k = 0; k < n; k++)
    {
        for (i = 0; i < n; i++)
        {
            if (finish[i] == 0)
            {
                int flag = 0;
                for (j = 0; j < m; j++)
                {
                    if (need[i][j] > work[j])
                    {
                        flag = 1;
                        break;
                    }
                }
                if (flag == 0)
                {
                    safesequence[ind++] = i;
                    for (y = 0; y < m; y++)
                        work[y] += alloc[i][y];
                    finish[i] = 1;
                }
            }
        }
    }
    printf("\nFollowing is the SAFE Sequence\n");
    for (i = 0; i <= n - 1; i++)
        printf(" P%d ", safesequence[i]);
}

// 1. Read the number of processes (n) and number of resources (m).
// 2. Read the Allocation Matrix (alloc[i][j]), where i ranges from 0 to n-1 and j ranges from 0 to m-1.
// 3. Read the Max Matrix (max[i][j]), where i ranges from 0 to n-1 and j ranges from 0 to m-1.
// 4. Read the Available Matrix (avail[i]), where i ranges from 0 to m-1.
// 5. Initialize arrays: finish[n], safesequence[n], work[m], need[n][m].
// 6. Calculate the Need Matrix (need[i][j] = max[i][j] - alloc[i][j]).
// 7. Initialize work[i] = avail[i] and finish[i] = 0 for all processes.
// 8. For k = 0 to n-1:
//     a. For i = 0 to n-1:
//          If finish[i] == 0:
//             - Initialize flag = 0.
//             - For j = 0 to m-1:
//                 - If need[i][j] > work[j], set flag = 1 and break.
//             - If flag == 0:
//                 - Add i to safesequence[ind].
//                 - For y = 0 to m-1, update work[y] += alloc[i][y].
//                 - Set finish[i] = 1.
// 9. Print the SAFE Sequence: "Following is the SAFE Sequence".
//    For i = 0 to n-1, print "P" + safesequence[i].
// 10. Exit.