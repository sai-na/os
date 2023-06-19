#include<stdlib.h>
#include<stdio.h>

int mutex = 1, full = 0, empty = 5, x = 0;

void producer() {
	--mutex;
	++full;
	
	--empty;
	x++;
	printf("\nProducer produces item %d", x);
	++mutex;
}

void consumer() {
	--mutex;
	--full;
	
	++empty;
	printf("\nConsumer consumes item %d",x);
	x--;
	++mutex;	
}

int main() {
	int n, i;
	while(n != 3){
	printf("\n1. Producer\n2. Consumer\n3. Exit\n");
	
	
		printf("Enter your choice: ");
		scanf("%d", &n);
		switch (n) {
			case 1: if (mutex == 1 && empty != 0)		
					  	producer();
					else printf("Buffer is full!"); break;
			case 2: if (mutex == 1 && full != 0)
						consumer();
					else printf("Buffer is empty!");
			case 3: break;
			default: printf("Enter valid input!"); break;
		}
	}
	
}
