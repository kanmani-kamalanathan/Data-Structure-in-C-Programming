#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
int a[100],n,i;
void create();
void display();
void search();
void sort();
void insert();
void delete();
void reverse();
void main()
{
	int op;
	printf("ARRAY IMPLEMENTATION OF LIST ADT");
	printf("\n-------------------------------");
	printf("\n1.CREATE\n2.DISPLAY\n3.SEARCH\n4.SORT\n5.INSERT\n6.DELETE\n7.REVERSE\n8.EXIT");
	printf("\nENTER THE NUMBER OF ARRAY ELEMENTS:");
	scanf("%d",&n);
	do{
		printf("\nENTER THE OPTION:");
		scanf("%d",&op);
		switch(op)
		{
			case 1:
			{
				create();
				break;
			}
			case 2:
			{
				display();
				break;
			}
			case 3:
			{
				search();
				break;
			}	
			case 4:
			{
				sort();
				break;
			}
			case 5:
			{
				insert();
				break;
			}
			case 6:
			{
				delete();
				break;
			}
			case 7:
			{
				reverse();
				break;
			}
			case 8:
				exit(0);
			default:
			{
				printf("\nINVALID OUTPUT");
				break;
			}

		}
	}while(op!=8);
	getch();
}
void create()
{
	printf("\nENTER THE ARRAY ELEMENTS:");
	for(i=0;i<n;i++)
		scanf("%d",&a[i]);
}
void display()
{
	printf("\nTHE ARRAY ELEMENTS ARE:");
	for(i=0;i<n;i++)
		printf("\na[%d]=%d",i,a[i]);
}
void search()
{
	int m;
	printf("\nPLEASE ENTER THE ELEMENT TO SEARCH:");
	scanf("%d",&m);
	for(i=0;i<n;i++)
	{
		if(a[i]==m)
		{
			printf("\nTHE ELEMENT FOUND AT POSITION:%d",i);
			break;
		}
	}
	if(i==n)
		printf("\nELEMENT IS NOT FOUND");
}
void sort()
{
	int j,temp;
	for(i=0;i<n;i++)
	{
		for(j=i+1;j<n;j++)
		{
			if(a[i]>a[j])
			{
				temp=a[i];
				a[i]=a[j];
				a[j]=temp;
			}
		}
	}
	printf("\nTHE SORTED ARRAY IS:");
	for(i=0;i<n;i++)
		printf("\na[%d]=%d",i,a[i]);
}
void insert()
{
	int pos,m;
	printf("\n ENTER THE POSITION TO INSERT AN ELEMENT:");
	scanf("%d",&pos);
	printf("\nENTER THE ELEMENT TO INSERT:");
	scanf("%d",&m);
	for(i=n-1;i>=pos-1;i--)
		a[i+1]=a[i];
	a[pos-1]=m;
	n++;
}
void delete()
{
	int m,pos;
	printf("ENTER THE ELEMENT TO BE DELETED:");
	scanf("%d",&m);
	for(i=0;i<n;i++)
	{
		if(a[i]==m)
		{
			pos=i;
			break;
		}
	}
	if(i==n)
		pos=-1;
	for(i=pos;i<n-1;i++)
		a[i]=a[i+1];
	n--;
}
void reverse()
{
	printf("\nTHE LIST IN REVERSE ORDER IS:");
	for(i=n-1;i>=0;i--)
		printf("\n%d",a[i]);
}
