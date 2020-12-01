#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
#define CAPACITY 1000
struct stack{
	int data;
	struct stack *next;
}*top;
int size=0;
void push(int ele);
int pop();
int main(){
	int choice,data;
	while(1){
		printf("----------------------------------------\n");
		printf("STACK IMPLEMENTATION PROGRAM\n");
		printf("----------------------------------------\n");
		printf("1.Push\t2.Pop\t3.Size\t4.Exit\n");
		printf("----------------------------------------\n");
		printf("Enter your Choice\n");
		scanf("%d",&choice);
		switch(choice){
			case 1:
				printf("Enter the data to push into stack:");
				scanf("%d",&data);
				push(data);
				break;
			case 2:
				data=pop();
				if(data!=INT_MIN)
					printf("Data=>%d\n",data);
				break;
			case 3:
				printf("Stack Size:%d\n",size);
				break;
			case 4:
				exit(0);
				break;
			default:
				printf("Invalid Choice, Please try again\n");
		}
	}
	return 0;
}
void push(int ele){
	if(size>=CAPACITY){
		printf("Stack overflow, You can't add more elements\n");
		return;
	}
	struct stack *newNode=(struct stack*)malloc(sizeof(struct stack));
	newNode->data=ele;
	newNode->next=top;
	top=newNode;
	size++;
	printf("Data Pushed to stack\n");
}
int pop(){
	int data=0;
	struct stack *topNode;
	if(size<=0 || !top){
		printf("Stack is empty\n");
		return INT_MIN;
	}
	topNode=top;
	data=top->data;
	top=top->next;
	free(topNode);
	size--;
	return data;
}
