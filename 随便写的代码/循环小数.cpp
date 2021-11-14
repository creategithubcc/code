#include <stdio.h>  
#include <stdlib.h>  
  
typedef struct node  
{   int         data;  
    struct node * next;  
} NODE;  
  
void output( NODE * );  
void change( int n, int m, NODE *head )
{
	int i,sum=0,a[51],count=0;
	a[0]=0;
	for(i=1;i<=50;i++)
	{
		count++;
		n*=10;
		a[i]=n/m;
		n=n%m;
		if(n==0)
		{
			break;
		}
	}
	//
/*	for(int j=0;j<=count;j++)
	{
		printf("%d\n",a[j]);
	}
	
*/	
	struct node *q=head;	
	for(i=1;i<=count;i++)
	{
		struct node *p=(struct node *)malloc(sizeof(struct node));
		p->data=a[i];
		p->next=q->next;
		q->next=p;
		q=p;
	 } 
} 
  
void output( NODE * head )  
{   int k=0;  
  
    printf("0.");  
    while ( head->next != NULL && k<50 )  
    {   printf("%d", head->next->data );  
        head = head->next;  
        k ++;  
    }  
    printf("\n");  
}  
  
int main()  
{   int n, m;  
    NODE * head;  
  
    scanf("%d%d", &n, &m);  
    head = (NODE *)malloc( sizeof(NODE) );  
    head->next = NULL;  
    head->data = -1;  
    change( n, m, head );  
    output( head );  
    return 0;  
}  
