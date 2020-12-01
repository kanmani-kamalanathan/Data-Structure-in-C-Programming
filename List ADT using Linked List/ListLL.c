#include<stdio.h>
#include<stdlib.h>
struct Node;
typedef struct Node * ptr;
typedef ptr List;
typedef ptr Pos;
struct Node
{
	int e;
	Pos next;
};
void insert(int x,List l,Pos p){
	Pos temp;
	temp=(struct Node*)malloc(sizeof(struct Node));
	if(temp==NULL)
		printf("Memory out of space\n");
	else{
		temp->e=x;
		temp->next=p->next;
		p->next=temp;
	}
}
int isLast(Pos p){
	return(p->next==NULL);
}
Pos findPrev(int x,List l){
	Pos p=l;
	while(p->next!=NULL && p->next->e!=x)
		p=p->next;
	return p;
}
void delete(int x,List l){
	Pos p,temp;
	p=findPrev(x,l);
	if(!isLast(p)){
		temp=p->next;
		p->next=temp->next;
		free(temp);
	}
	else
		printf("Element does not exist!!!\n");
}
void display(List l){
	printf("The list elements are : ");
	Pos p=l->next;
	while(p!=NULL){
		printf("%d -> ",p->e);
		p=p->next;
	}
}
void merge(List l,List l1){
	int i,n,x,j;
	Pos p;
	printf("Enter the number of elements to be merged : ");
	scanf("%d",&n);
	for(i=1;i<=n;i++){
		p=l1;
		scanf("%d",&x);
		for(j=1;j<i;j++)
			p=p->next;
		insert(x,l1,p);
	}
	printf("The new list : ");
	display(l1);
	printf("The merged list : ");
	p=l;
	while(p->next!=NULL)
		p=p->next;
	p->next=l1->next;
	display(l);
}
int main(){
	int x,pos,ch,i;
	List l,l1;
	l=(struct Node *)malloc(sizeof(struct Node));
	l->next=NULL;
	List p=l;
	printf("LINKED LIST IMPLEMENTATION OF LIST ADT\n\n");
	do{
		printf("\n1. INSERT\t 2. DELETE\t 3. MERGE\t 4. PRINT\t 5. QUIT\n\nEnter the choice : ");
		scanf("%d",&ch);
		switch(ch){
			case 1:
				p=l;
				printf("Enter the element to be inserted : ");
				scanf("%d",&x);
				printf("Enter the position of the element : ");
				scanf("%d",&pos);
				for (i = 1; i < pos; i++)
					p=p->next;
				insert(x,l,p);
				break;
			case 2:
				p = l;
 				printf("Enter the element to be deleted : ");
 				scanf("%d",&x);
 				delete(x,p);
 				break;
 			case 3:
 				l1 = (struct Node *) malloc(sizeof(struct Node));
 				l1->next = NULL;
 				merge(l, l1);
 				break;
 			case 4:
 				display(l);
 				break;
 		}
	}while(ch<5);
 	return 0;
}
