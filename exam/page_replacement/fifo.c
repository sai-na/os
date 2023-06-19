#include<stdio.h>
int main()
{
int stream[20],pageFaults=0,frames=3;
int m,n,s,i,pages;
printf("Enter the number of incoming stream\n");
scanf("%d",&pages);
printf("Enter the page stream one by one\n");
for(i=0;i<pages;i++)
scanf("%d",&stream[i]);
 printf(" Incoming\t\tFrame 1\t\tFrame 2\t\tFrame 3 ");  
    int temp[ frames ];  
    for(m = 0; m < frames; m++)  
    {  
        temp[m] = -1;  
    }  
    for(m = 0; m < pages; m++)  
    {  
        s = 0;   
        for(n = 0; n < frames; n++)  
        {  
            if(stream[m] == temp[n])  
            {  
                s++;  
                pageFaults--;  
            }  
        }  
        pageFaults++;  
        if((pageFaults <= frames) && (s == 0))  
        {  
            temp[m] = stream[m];  
        }  
        else if(s == 0)  
        {  
            temp[(pageFaults - 1) % frames] = stream[m];  
        }  
        printf("\n");  
        printf("\t%d\t",stream[m]);  
        for(n = 0; n < frames; n++)  
        {  
            if(temp[n] != -1)  
                printf("\t%d\t", temp[n]);  
            else  
                printf(" \t-\t");  
        }  
    }  
    printf("\nTotal Page Faults:%d\n", pageFaults);
    printf("Total page hits:%d\n",pages-pageFaults);  
    return 0;  
}  
