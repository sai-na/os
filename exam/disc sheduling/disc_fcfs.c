#include<stdio.h>
#include<stdlib.h>
void main(){
	int IORequest[10];
	int i,j,n,sum;
	printf("Enter number of requests: ");
	scanf("%d",&n);
	for(i=1;i<=n;i++){
		printf("Enter position: ");
		scanf("%d",&IORequest[i]);
	}
	printf("Enter initial head: ");
	scanf("%d",&IORequest[0]);
	sum=0;
	for(i=0;i<n;i++){
		printf("%d ",IORequest[i]);
		if(IORequest[i]>IORequest[i+1]){
			sum=sum+(IORequest[i]-IORequest[i+1]);
		}
		else{
				sum=sum+(IORequest[i+1]-IORequest[i]);
			}
		}
		printf("%d",IORequest[n]);
		printf("\nTime: %d",sum);
	}