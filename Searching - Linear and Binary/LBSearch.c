#include <stdio.h>
#include <conio.h>
void main( )
{
int m,i, n, j, temp, flg, low, middle, high, a[100];char ch;
flg=0;
printf("Enter the size of the array \n");
scanf("%d",&n);
printf("Enter the elements of the array \n");
for (i=1; i<=n;i++)
{
scanf("%d", &a[i]);
}
do
{
printf("\nEnter the number which you want to search :");
scanf("%d", &m);
printf ("\nPress 'l' for linear search and 'b' for binary search :");
ch=getch( );
switch(ch)
{
case 'l':
for (i=1; i<=n;i++)
{
 if(a[i]==m)
 {
 flg=1;
 break;
 }
}
if(flg== 1)
{
printf("\nThe element is found and the position is: %d",i);
printf("\n");
}
else
printf("\nElement is not found \n");
break;
case 'b':
for (i=1; i<=n-1;i++)
{
for (j=i+1;j<=n;j++)
{
if(a[i]>a[j])
{
temp=a[i];
a[i]=a[j];
a[j]=temp;
}
}
}
printf("\nThe sorted list is \n");
for (i=1; i<=n;i++)
{
printf("%d ",a[i]);
}
low=1;
high=n;
while (low<=high)
{
middle=(low+high)/2;
if(a[middle] == m)
{
flg = 1;
break;
}
else
{
if(a[middle]<m)
{
low=middle+1;
}
else
{
high=middle-1;
}
}
}
if(flg == 1)
printf("\nThe element is found and the position is : %d", middle);
else
printf("\nThe element is not found \n");
break;
default:
printf("\nWrong selection \n");
break;
}
printf("\nPress 'Y' to continue and any other key to discontinue : ");
ch=getch( );
}while (ch == 'Y');
getch( );
}
