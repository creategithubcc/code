#include <stdio.h>    
#include <stdlib.h>    
    
typedef struct sdata    
{  char  data;    
   struct sdata *next;    
} SNODE;    
    
void setlink( SNODE *, char * ), outlink( SNODE * );    
int listlen( SNODE * );    
SNODE * ziplist( SNODE *, SNODE * );    
SNODE * findlist( SNODE *, SNODE * );    
    
int main( )    
{    
    SNODE * head1, * head2, *head;    
    char str1[100], str2[100];    
    
    gets( str1 );    
    gets( str2 );    
    
    head1 = (SNODE *) malloc( sizeof(SNODE) );    
    head2 = (SNODE *) malloc( sizeof(SNODE) );    
    head = (SNODE *) malloc( sizeof(SNODE) );    
    head->next = head1->next = head2->next = NULL;    
    
    setlink( head1, str1 );    
    setlink( head2, str2);    
    
    head->next = ziplist( head1, head2 );    
    
    head->next = findlist( head1, head2 );    
    outlink( head );    
    return 0;    
}    
    
void setlink( SNODE *head, char *str )    
{    
    SNODE *p ;    
    
    while ( *str != '\0' )    
    {   p  = ( SNODE * ) malloc( sizeof( SNODE ) );    
        p->data = *str;    
        p->next = NULL;    
        str++;    
        head->next = p;    
        head = p;    
    }    
    return;    
}    
    
void outlink( SNODE * head )    
{    
    while ( head->next != NULL )    
    {    
        printf( "%c", head -> next -> data );    
        head = head -> next;    
    }    
    printf("\n");    
    return;    
}    
    
int listlen( SNODE * head )    
{    
    int len=0;    
    while ( head->next != NULL )    
    {    
        len ++;    
        head = head->next;    
    }    
    return len;    
}    
    
SNODE * findlist( SNODE * head1, SNODE * head2 )    
{    
    int m, n;    
    SNODE *p1=head1, *p2=head2;    
    
    m = listlen( head1 );    
    n = listlen( head2 );    
    while  ( m > n )    
    {   p1 = p1->next;    
        m--;    
    }    
    while  ( m < n )    
    {   p2 = p2->next;    
        n--;    
    }    
    
    while( p1->next != NULL && p1->next != p2->next )    
    {    
        p1 = p1->next;    
        p2 = p2->next;    
    }    
    return p1->next;    
}    
    
SNODE * ziplist( SNODE * head1, SNODE * head2 )  
{  
	int len1=listlen(head1),len2=listlen(head2);  
    SNODE *p1=head1,*p2=head2;  
    while(len1>len2)  
    {  
        len1--;  
        p1=p1->next;  
    }  
    while(len1<len2)  
    {  
        len2--;  
        p2=p2->next;  
    }  
    SNODE *tt=p1,*ttt=p2;  
    while(p1->next->next!=NULL)  
    {  
        if(p1->next->data!=p2->next->data)  
        {  
            ttt=p2->next;  
            tt=p1->next;  
        }  
        p2=p2->next;  
        p1=p1->next;  
    }  
    if(p1->next->data!=p2->next->data)  
        return NULL;  
    else  
    {  
        ttt->next=tt->next;  
        return ttt->next;  
    }  
}
