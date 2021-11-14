#include<iostream>
#include<cstring>
#include<queue> 
#include<cstdio>
#include<algorithm>
using namespace std;
typedef struct shu 
{
	char data;
	struct shu *right;
	struct shu *left;
}ercha, *tree;
char str[100005]={'\0'};
tree bit,temp;
void chushihua()
{
	temp->left=NULL;
	temp->right=NULL;
}
int main()
{ 
	int n;
	bit =(tree)malloc(sizeof(tree));
	bit->data=0;
	bit->left=NULL;
	bit->right=NULL;
	scanf("%d",&n);
	while(n--)
	{
		temp=bit;	
		scanf("%s",&str);
		int len = strlen(str);
		for(int i=0;i<len;i++)
		{
			if(str[i]=='0')
			{
				if(temp->left == NULL)
				{
					temp->left =(tree)malloc(sizeof(tree));
					temp=temp->left;
					chushihua();
					if(i == len -1)
					{
						temp->data = 1;
					}
					else
					{
						temp->data = 0;	
					} 
				}
				else
				{
					if(temp->left->data == 1||i == len-1)
					{
						goto x;
					}
					else
					{
						temp=temp->left;
					}
				}
			}
			else if(str[i]=='1')
			{
				if(temp->right == NULL)
				{
					temp->right=(tree)malloc(sizeof(tree));
					temp=temp->right;
					chushihua();
					if(i == len -1)
					{
						temp->data = 1;
					}
					else
					{
						temp->data = 0;	
					} 
				}
				else
				{
					if(temp->right->data == 1|| i ==len-1) 
					{
						goto x; 
					}
					else
					{
						temp=temp->right;
					}
				}
			}
		}		
		memset(str,'\0',sizeof(str));
	}
	printf("YES\n");
	return 0;
	x:printf("%s\n",str);
return 0; 
}
 
