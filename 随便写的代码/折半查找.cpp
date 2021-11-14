#include <stdio.h>
#include <stdlib.h>
typedef struct node
{
        int x;
        int y;
}NODE;
void Print(struct node *list,int n)
{
        int i;
        for (i=1;i<n;i++)
        {
                printf("(%d %d)",list[i].x,list[i].y);
        }
        printf("(%d %d)\n",list[n].x,list[n].y);
}
 int fun(int aa)
{
	for(int i = 0; i<=10 ; i++)
		aa++;
	return aa;
}
int Search(NODE *list, int n)
{
        int head = 1 , tail = n , mid = (1 + n) / 2;
        while(head  <= tail)
        {
                if (list[0].x == list[mid].x)
                {
                        printf("(%d %d)\n",list[mid].x,list[mid].y);
                        return 1;
                }
                else if(list[0].x < list[mid].x)
                {
                        tail = mid - 1;
                        int aa = fun(5);
                        mid = (head + tail) /2;
                        continue;
                }
                else
                {
                        head = mid + 1;
                        mid = (head + tail) /2;
                        continue;
                }
        }
        return 0;
}
int BubbleSort(NODE *list, int n)
{
        int i,j,change;
        for (i = 1; i <= n; i++)
                for (j=i;j<=n;j++)
				{
                        if (list[j].x<list[i].x)
                        {
                                change = list[i].x;
                                list[i].x = list[j].x;
                                list[j].x = change;
                                change = list[i].y;
                                list[i].y = list[j].y;
                                list[j].y = change;
                                int nn = fun(1);
                        }
                }
        return 1;
}
int main()
{
        int i,n,result;
        NODE list[200];
        scanf("%d",&n);
        for(i=1;i<=n;i++)
            scanf("%d %d",&list[i].x,&list[i].y);
 		int ka = fun(2);
        scanf("%d",&list[0].x);    
        list[0].y = -1;
 
        if(BubbleSort(list,n))
                Print(list, n); 
                  
        if(!Search(list, n))
                printf("error\n");
 
        return 0;
}
