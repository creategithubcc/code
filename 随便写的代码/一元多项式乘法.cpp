#include <stdio.h>  
#include <stdlib.h>  
  
typedef struct node  
{   int    coef, exp;  
    struct node  *next;  
} NODE;  
void multiplication( NODE *, NODE * , NODE * );  
void input( NODE * );  
void output( NODE * );  
NODE *Reverse(NODE * head)
/*将生的的链表逆置，使一元多项式呈指数递增形式*/
{
    NODE *q,*r,*p=NULL;
    q=head->next;
    while(q)
    {
        r=q->next;      /*r指向链表的待处理结点*/
        q->next=p;      /*将链表结点逆置*/
        p=q;            /*p指向刚逆置后链表结点*/
        q=r;            /*q指向下一准备逆置的结点*/
    }
    head->next=p;       /*将头结点的指针指向已经逆置后的链表*/
    return head;
}
void multiplication( NODE *head1, NODE* head2, NODE* head3 )
{
	NODE *p,*q,*h1,*h2,*xiang,*h3; 
	int k=0,i,tag=0,tbg=0,tcg=0,a=0,b=0,c=0,d=0;
	h3 = (NODE*) malloc(sizeof(NODE));
	head3->coef = 0;
	head3->exp = 0;
	head1 = Reverse(head1);
	p=head1->next;		
	q=head2->next;	
	while(q ->next!= NULL)
		q = q->next;
	//将1倒转
	int  coef[10000]={0};
	
	if(head1->next != NULL&& head2->next !=NULL )
		k=q->exp + p->exp;//最大的指数 
	else	
		return ;	
	h3=head3;	
	for(i=k;i>=0;i--)
	{

		h1 = head1->next;
		while(h1!=NULL && h1->exp>i)
			h1=h1->next; 
		if(h1 == NULL)
			continue; 
		h2 = head2->next;
		while(h2!=NULL && (h1->exp + h2->exp)<i &&h1!=NULL)
			h2=h2->next;	
		int xishu=0;
		while(h1!=NULL && h2!=NULL)
		{
			if(h1->exp+h2->exp==i)
			{
				xishu+= h1->coef*h2->coef;
				h1=h1->next;
				h2=h2->next;
			}
			else if(h1->exp+h2->exp>i)
			{
				h1=h1->next;
			} 
			else 
			{
				h2=h2->next;
			}
		}
		if(xishu!=0)
		{
			xiang = (NODE*)malloc (sizeof(NODE));
			xiang->coef=xishu;
			xiang->exp = i;
			xiang->next = h3->next;
			h3->next = xiang;
			h3 = xiang;	
		}	 
	}
	if(head3->next==NULL)
	{
		xiang = (NODE*)malloc (sizeof(NODE));
		xiang->coef=0;
		xiang->exp =0;
		xiang->next=head3->next;
		head3->next=xiang;
	}
	head3=Reverse(head3);
}
void input( NODE * head )  
{   int flag, sign, sum, x;  
    char c;  
  
    NODE * p = head;  
  
    while ( (c=getchar()) !='\n' )  
    {  
        if ( c == '<' )  
        {    sum = 0;  
             sign = 1;  
             flag = 1;  
        }  
        else if ( c =='-' )  
             sign = -1;  
        else if( c >='0'&& c <='9' )  
        {    sum = sum*10 + c - '0';  
        }  
        else if ( c == ',' )  
        {    if ( flag == 1 )  
             {    x = sign * sum;  
                  sum = 0;  
                  flag = 2;  
          sign = 1;  
             }  
        }  
        else if ( c == '>' )  
        {    p->next = ( NODE * ) malloc( sizeof(NODE) );  
             p->next->coef = x;  
             p->next->exp  = sign * sum;  
             p = p->next;  
             p->next = NULL;  
             flag = 0;  
        }  
    }  
}  
  
void output( NODE * head )  
{  
    while ( head->next != NULL )  
    {   head = head->next;  
        printf("<%d,%d>,", head->coef, head->exp );  
    }  
    printf("\n");  
}  
  
int main()  
{   NODE * head1, * head2, * head3;  
  
    head1 = ( NODE * ) malloc( sizeof(NODE) );  
    input( head1 );  
  
    head2 = ( NODE * ) malloc( sizeof(NODE) );  
    input( head2 );  
  
    head3 = ( NODE * ) malloc( sizeof(NODE) );  
    head3->next = NULL;  
    multiplication( head1, head2, head3 );  
  
    output( head3 );  
    return 0;  
}  
  
