#include <stdio.h>
#include <stdlib.h>

int n, m, i, j, h, p, temp, k, total = 0;
int t[100], a[100], diff;

void main()
{
    printf("ENTER THE NUMBER OF TRACKS : ");
    scanf("%d", &n);
    printf("ENTER THE HEAD POINTER POSITION : ");
    scanf("%d", &h);
    printf("ENTER THE TRACKS TO BE TRAVERSED : ");
    for (i = 0; i < n; i++)
    {
        scanf("%d", &t[i]);
    }
    t[n] = h;
    n++;

    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n - i - 1; j++)
        {
            if (t[j] > t[j + 1])
            {
                temp = t[j];
                t[j] = t[j + 1];
                t[j + 1] = temp;
            }
        }
    }

    for (i = 0; i < n; i++)
    {
        if (t[i] == h)
        {
            k = i;
            break;
        }
    }

    printf("TRAVERSED ORDER : ");
    for (i = k; i < n; i++)
    {
        printf("%d => ", t[i]);
        a[p] = t[i];
        p++;
    }
    for (i = 0; i < k; i++)
    {
        printf("%d => ", t[i]);
        a[p] = t[i];
        p++;
    }

    for (total = 0, j = 0; j < p - 1; j++)
    {
        total = total + abs(a[j + 1] - a[j]);
    }
    printf("\b\b\b.  \nTOTAL HEAD MOVEMENTS : %d\n", total);
}
