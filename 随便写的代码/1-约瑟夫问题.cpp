#include<stdio.h>
#include<stdlib.h>
int n,k,m;

struct node 
{
    int no;
    struct node * next;
};

int main()
{
	int i,count;char ch;
	scanf("%d,%d,%d",&n,&k,&m);
	
	if(n<1||k<1||m<1)
	{
		printf("n,m,k must bigger than 0.\n");
		return 0;
	}
	if(k>n)
	{
		printf("k should not bigger than n.\n");
		return 0;
	}
	struct node *head,*p,*q;
    head=(struct node *)malloc(sizeof(struct node));
	
	head->no=-1;				//构造链表 
    head->next=head;
    q=head;
	for(i=1;i<=n;i++)
	{
		p=(struct node *)malloc(sizeof(struct node));
		p->no=i;
		q->next=p;
		q=p;
	}
	q->next=head->next;
	
	p=head;						//移至第k个 
	for(i=1;i<k;i++)
		p=p->next;
	
	count=0;					//输出 
	while(p->next!=p)
	{
		for(i=m;i>1;i--)
		{
			p=p->next;
		}
		printf("%d%c",p->next->no,ch=count==9?'\n':' ');
		if(count==9) count=-1;
		count++;
		p->next=p->next->next;
	}
	printf("%d\n",p->no);
	
	return 0;
} 
