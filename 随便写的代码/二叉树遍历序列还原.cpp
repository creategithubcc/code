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
tree bit=NULL;
void rebuild_tree(char *zhongxv,char *houxv,int root,tree *bit)
{
	if(!zhongxv || !houxv || root<=0 )
		return;
	int i;	
	for(i=0;i<root;i++)
	{
		if(zhongxv[i]==houxv[root-1])break;
	}
	if(i>=root)
		return;
	*bit = new shu;
	(*bit)->data=houxv[root-1];
	(*bit)->left=(*bit)->right=NULL;
	rebuild_tree(zhongxv,houxv,i,&((*bit)->left));
	rebuild_tree(zhongxv+i+1,houxv+i,root-i-1,&((*bit)->right));
}

void LevleOrder(tree bit)
{ 
	queue<tree> Q;   
	Q.push(bit);
	while(!Q.empty())
	{
		tree now;
		now = Q.front();
		printf("%c",now->data);
		Q.pop();
		if(now->left!=NULL) Q.push((now->left));
		if(now->right!=NULL) Q.push((now->right));
	}
}

int main()
{
	int len;
	char zhongxv[100],houxv[100];
	scanf("%s%s",&zhongxv,&houxv);
	tree bit=NULL;
	len = strlen(zhongxv);
	rebuild_tree(zhongxv,houxv,len,&bit); 
	LevleOrder(bit);
	printf("\n");
return 0;	
}
