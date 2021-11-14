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

void Single_Left_Roate(tree &bit)
{
	tree p;
	p = bit->left;    //假如此时bit指向4，则p指向3；
    bit->left = p->right; //把3的右子树挂接到4的左子树上（此例子3右子树为空）
    p->right = bit;       //让3的右孩子指向4.
    bit = p;        //根指向节点3
}
void Single_Right_Roate(tree &bit)
{
	tree p;
    p = bit->right;     //假如此时bit指向4，则p指向7.
    bit->right = p->left;  //让7的左子树挂接到4的右子树上
    p->left = bit;    //让7的左孩子指向4
    bit = p;   //树根指向7
}
void Double_LR_Roate(tree &bit)
{
	tree t2,t1;
    t1 = bit->left;
    t2 = t1->right;
    t1->right = t2->left;
    bit->left = t2->right;
    t2->left = t1;
    t2->right = bit;
    bit = t2;
}

void Double_RL_Roate(tree &bit)
{
	tree t1,t2;
	t1 = bit->right;
    t2 = t1->left;
    bit->right = t2->left;
    t1->left = t2->right;
    t2->left = bit;
    t2->right = t1;
    bit = t2;
}
 
int depth(tree &bit)//深度 
{
	if(bit == NULL)
		return 0;
	else
	{
		int dep_L = depth(bit->left);
		int dep_R = depth(bit->right);
		return(dep_L > dep_R ? dep_L+1:dep_R+1);	
	}	
}
void Insert_AVLTree(tree &bit,char ch)
{
	if(bit == NULL)
	{
		bit = new shu();
		bit->data = ch;
		bit->left = NULL;
		bit->right = NULL;	
	} 
	else if(ch == bit->data)
		return;
	else if(ch < bit->data)
	{
		Insert_AVLTree(bit->left , ch);
		if(depth(bit->left) - depth(bit->right) == 2)
		{
			if(ch < bit->left->data)
			{
				Single_Left_Roate(bit);
			}
			else
			{
				Double_LR_Roate(bit);
			}	
		} 
	}
	else
	{
		Insert_AVLTree(bit->right , ch);
		if(depth(bit->right) - depth(bit->left) == 2)
		{
			if(ch > bit->right->data)
			{
				Single_Right_Roate(bit);
			}
			else
			{
				Double_RL_Roate(bit);
			}	
		} 
		
	}	
}
void preorder_traversal(tree &bit)
{
	if(bit == NULL)
		return;
	else
	{
		printf("%c",bit->data);
		preorder_traversal(bit->left);
		preorder_traversal(bit->right);	
	}	
}
void inorder_traversal(tree &bit)
{
	if(bit == NULL)
		return;
	else
	{	
		inorder_traversal(bit->left);
		printf("%c",bit->data);
		inorder_traversal(bit->right);	
	}	
}
void postorder_traversal(tree &bit)
{
	if(bit == NULL)
		return;
	else
	{	
		postorder_traversal(bit->left);
		postorder_traversal(bit->right);	
		printf("%c",bit->data);
	}	
}
void output(tree &bit, int flag)
{
    if (bit == NULL)
        return;
    else
    {
        output(bit->right, flag + 1);
        for (int i = 0; i < flag; i++)
            printf("    ");
        printf("%c\n", bit->data);
        output(bit->left, flag + 1);
    }
}
int main()
{
	char c;
	tree root;
	while(1)
	{
		c = getchar();
		if( c == '\n')
			break;
		Insert_AVLTree(root,c);
	}
	printf("Preorder: ");
	preorder_traversal(root);printf("\n");
	printf("Inorder: ");
	inorder_traversal(root);printf("\n");
	printf("Postorder: ");
	postorder_traversal(root);printf("\n");
	printf("Tree:\n");
	output(root, 0);
return 0;	
} 
