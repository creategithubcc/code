#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
int min(int a , int b)
{
    return a<=b?a:b;
}
struct sjk
{
    int orderid;
    int gupiao;
    float jiage;
    int shuliang;
    char type;
    struct sjk *next;
};
int main()
{
    int j,k,type,id,quantity,count=1,temquantity,flag=0;
    float price=0.0,temprice=0.0,i=0.0;
    char p,q;
    struct sjk *x,*y,*t3,*front1=NULL,*rear1=NULL,*front2=NULL,*rear2=NULL;
    struct sjk *temp;
    front1=rear1=(struct sjk*)malloc(sizeof(struct sjk));
    front2=rear2=(struct sjk*)malloc(sizeof(struct sjk));
    front1->next=NULL;
    front2->next=NULL;
    while (1)
    {
            scanf("%d",&type);
            switch(type)
            {
            case 0:
                    exit(0);
                    break;
            case 1:
                    scanf("%d %f %d",&id,&price,&quantity);
                    getchar();
                    scanf("%c",&x);
                    x=(struct sjk*)malloc(sizeof(struct sjk));
                    x->orderid=count++;
                    printf("orderid: %04d\n",x->orderid);
                    x->gupiao=id;
                    x->jiage=price;
                    x->shuliang=quantity;
                    x->type=p;
                    x->next=NULL;
                    if (p== 'b')
                    {
                            if (front2!=rear2)
                            {
                                    y=front2->next;
                                    while (y!=NULL&&x->shuliang!=0)
                                    {
                                            if (x->gupiao==y->gupiao&&x->jiage>=y->jiage&&y->shuliang!=0)
                                            {
                                                    temprice=(x->jiage+y->jiage)/2;
                                                    temquantity=min(x->shuliang,y->shuliang);
                                                    x->shuliang-=temquantity;
                                                    y->shuliang-=temquantity;
                                                    
                                                    printf("deal--price:%6.1f  quantity:%4d  buyorder:%04d  sellorder:%04d\n",temprice,temquantity,x->orderid,y->orderid);
                                            }
                                            y=y->next;
                                    }
                                    if (x->shuliang!=0)
                                    {
                                            if (front1!=rear1)
                                            {
                                                    y=front1->next;
                                                    temp=front1;
                                                    while (y!=NULL)
                                                    {
                                                            if (x->jiage<=y->jiage)
                                                            {
                                                                    temp=y;
                                                                    y=y->next;
                                                                    if (y==NULL)
                                                                    {
                                                                            temp->next=x;
                                                                    }
                                                                    continue;
                                                            }
                                                            else
                                                            {
                                                                    x->next=y;
                                                                    temp->next=x;
                                                                    break;
                                                            }
                                                            if (y->next==NULL)
                                                            {
                                                                    y->next=x;
                                                                    x->next=NULL;
                                                                    rear1=x;
                                                            }
                                                    }
                                            }
                                            else
                                            {
                                                    front1->next=rear1=x;
                                            }
                                    }
                                    else
                                    {
                                            free(x);
                                    }

                            }
                            else
                            {
                                    if (front1!=rear1)
                                    {
                                            y=front1->next;
                                            temp=front1;
                                            while (y!=NULL)
                                            {
                                                    if (x->jiage<=y->jiage)
                                                    {
                                                            temp=y;
                                                            y=y->next;
                                                            if (y==NULL)
                                                                            {
                                                                                    temp->next=x;
                                                                            }
                                                            continue;
                                                    }
                                                    else
                                                    {
                                                            x->next=y;
                                                            temp->next=x;
                                                            break;
                                                    }
                                                    if (y->next==NULL)
                                                    {
                                                            y->next=x;
                                                            x->next=NULL;
                                                            rear1=x;
                                                    }
                                            }
                                    }
                                    else
                                    {
                                            front1->next=rear1=x;
                                    }
                            }
                    }
                            if (p=='s')
                            {
                                    if (front1!=rear1)
                                    {
                                            y=front1->next;
                                            while (y!=NULL && y->shuliang!=0)
                                            {
                                                    if (x->gupiao==y->gupiao && x->jiage<=y->jiage && x->shuliang!=0)
                                                    {
                                                            temprice=(x->jiage+y->jiage)/2;
                                                            temquantity=min(x->shuliang,y->shuliang);
                                                            x->shuliang-=temquantity;
                                                            y->shuliang-=temquantity;
                                                            
                                                    printf("deal--price:%6.1f  quantity:%4d  sellorder:%04d  buyorder:%04d\n",temprice,temquantity,x->orderid,y->orderid);
                                                    }
                                                    y=y->next;
                                            }
                                            if (x->shuliang!=0)
                                            {
                                                    if (front2!=rear2)
                                                    {
                                                            y=front2->next;
                                                            temp=front2;
                                                            while (y!=NULL)
                                                            {
                                                                    if (x->jiage>=y->jiage)
                                                                    {
                                                                            temp=y;
                                                                            y=y->next;
                                                                            if (y==NULL)
                                                                            {
                                                                                    temp->next=x;
                                                                            }
                                                                            continue;
                                                                    }
                                                                    else
                                                                    {
                                                                            x->next=y;
                                                                            temp->next=x;
                                                                            break;
                                                                    }
                                                                    if (y->next==NULL)
                                                                    {
                                                                            y->next=x;
                                                                            x->next=NULL;
                                                                            rear2=x;
                                                                    }
                                                            }
                                                    }
                                                    else
                                                    {
                                                            front2->next=rear2=x;
                                                    }
                                            }
                                            else
                                            {
                                                    free(x);
                                            }
                                    }
                                    else
                                    {
                                            if (front2!=rear2)
                                            {
                                                    y=front2->next;
                                                    temp=front2;
                                                    while (y!=NULL)
                                                    {
                                                            if (x->jiage>=y->jiage)
                                                            {
                                                                    temp=y;
                                                                    y=y->next;
                                                                    if (y==NULL)
                                                                    {
                                                                            temp->next=x;
                                                                    }
                                                                    continue;
                                                            }
                                                            else
                                                            {
                                                                    x->next=y;
                                                                    temp->next=x;
                                                                    break;
                                                            }
                                                            if (y->next==NULL)
                                                            {
                                                                    y->next=x;
                                                                    x->next=NULL;
                                                                    rear2=x;
                                                            }
                                                    }
                                            }
                                            else
                                                    {
                                                            front2->next=rear2=x;
                                                    }
                            }

                    }
                    break;
            case 2:
                    scanf("%d",&id);
                    printf("buy orders:\n");
                    x=front1->next;
                    while (x!=NULL)
                    {
                            if (x->gupiao== id && x->shuliang!=0)
                            {
                                    printf("orderid: %04d, stockid:%04d, price: %6.1f, quantity: %4d, b/s: %c\n",x->orderid,x->gupiao,x->jiage,x->shuliang,x->type);
                            }
                            x=x->next;
                    }
                    printf("sell orders:\n");
                    x=front2->next;
                    while (x!=NULL)
                    {
                            if (x->gupiao== id && x->shuliang!=0)
                            {
                                    printf("orderid: %04d, stockid:%04d, price: %6.1f, quantity: %4d, b/s: %c\n",x->orderid,x->gupiao,x->jiage,x->shuliang,x->type);
                            }
                            x=x->next;
                    }
                    break;
            case 3:
                    scanf("%d",&id);
                    temp=front1;
                    x=front1->next;
                    while (x!=NULL)
                    {
                            if (x->orderid==id)
                            {
                                    temp->next=x->next;
                                    
                                    flag=1;
                                    printf("deleted order:orderid: %04d, stockid:%04d, price: %6.1f, quantity: %4d, b/s: %c\n",x->orderid,x->gupiao,x->jiage,x->shuliang,x->type);
                                    free(x);
                                    break;
                            }
                            temp=x;
                            x=x->next;
                    }
                    temp=front2;
                    x=front2->next;
                    while (x!=NULL && !flag)
                    {
                            if (x->orderid==id)
                            {
                                    temp->next=x->next;
                                    flag=1;
                                    printf("deleted order:orderid: %04d, stockid:%04d, price: %6.1f, quantity: %4d, b/s: %c\n",x->orderid,x->gupiao,x->jiage,x->shuliang,x->type);
                                    free(x);
                                    break;
                            }
                            temp=x;
                            x=x->next;
                    }
                    if (flag == 0)
                    {
                            printf("not found\n");
                    }
                    flag=0;
                    break;
            }
    }
}
