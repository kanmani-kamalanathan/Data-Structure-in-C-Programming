#include<stdio.h>
#include<conio.h>
#include<ctype.h>
#define SIZE 50
char s[SIZE];
int top=-1;
void push(char ele){
	s[++top]=ele;
}
char pop(){
	return(s[top--]);
}
int pr(char ele){
	switch(ele){
		case '#':return 0;
		case '(':return 1;
		case '+':
		case '-':return 2;
		case '*':
		case '/':return 3;
	}
}
void main(){
	char infx[50],pofx[50],ch,ele;
	int i=0,k=0;
	printf("\n\nRead the infix Expression: ");
	scanf("%s",infx);
	push('#');
	while((ch=infx[i++])!='\0'){
		if(ch=='(')
			push(ch);
		else if(isalnum(ch))
			pofx[k++]=ch;
		else if(ch==')'){
			while(s[top]!='(')
				pofx[k++]=pop();
			ele=pop();
		}
		else{
			while(pr(s[top])>=pr(ch))
				pofx[k++]=pop();
			push(ch);
		}
	}
	while(s[top]!='#')
		pofx[k++]=pop();
	pofx[k]='\0';
	printf("\n\nGiven Infix Expression:%s\n\nPostfix Expression:%s\n",infx,pofx);
	getch();
}
