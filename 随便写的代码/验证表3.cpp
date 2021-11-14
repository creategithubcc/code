#include<stdio.h>
#include<string.h>
struct node{
	int num;
	char ch[50];
};
struct node list1[1000],list2[1000];
int n,m;

int search(struct node item)
{
	int i;
	for (i=0;i<n;i++)
	{
		if(item.num==list1[i].num&&strcmp(list1[i].ch,item.ch)==0)
		{
			return 1;
		}
	}
	return 0;
}

int main()
{
	int i,j,k,flag=0;
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		scanf("%d %s",&list1[i].num,list1[i].ch);
	}
	scanf("%d",&m);
	for(i=0;i<m;i++)
	{
		scanf("%d %s",&list2[i].num,list2[i].ch);
	}
	if(m==0)
	{
		printf("the LIST2 is NULL.\n");
		return 0;
	}
	for(i=0;i<m;i++)
	{
		
		if(search(list2[i])==0)
		{
			printf("%8d %s is not in LIST1.\n",list2[i].num,list2[i].ch);
			flag=1;
		}
		
	}
	
	if(flag==0)
	{
		printf("the records of LIST2 are all in the LIST1.\n");
	}
}
