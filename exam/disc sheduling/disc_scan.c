#include<stdio.h>
#include<stdlib.h>
void main(){
	int IORequest[10];
	int executingArray[10];
	int initial;
	int i,j,n,sum;
	printf("Enter number of requests: ");
	scanf("%d",&n);
	for(i=1;i<=n;i++){
		printf("Enter position: ");
		scanf("%d",&IORequest[i]);
	}
	printf("Enter initial head: ");
	scanf("%d",&IORequest[0]);
	initial=IORequest[0];
	for(i=0;i<n;i++){
		for(j=0;j<n-i;j++){
			if(IORequest[j]>IORequest[j+1]){
				int temp= IORequest[j];
				IORequest[j]=IORequest[j+1];
				IORequest[j+1]=temp;
			}
		}
	}
	i=0;
	while(i<=n && IORequest[i]!=initial){
		i++;
	}
	sum=0;
	int k=0;
	if(IORequest[i]==initial){
		for(j=i;j>=0;j--){
			executingArray[k]=IORequest[j];
			k++;
		}
		executingArray[k]=0;
		k++;
		for(j=i+1;j<=n;j++){
			executingArray[k]=IORequest[j];
			k++;
		}
	}
	for(i=0;i<=n;i++){
		printf("%d ",executingArray[i]);
		if(executingArray[i]>executingArray[i+1]){
			sum= sum+ (executingArray[i]-executingArray[i+1]);
		}
		else{
			sum= sum+(executingArray[i+1]-executingArray[i]);
			}
	}
	printf("%d",executingArray[n+1]);
	printf("\nTime: %d",sum);
}
