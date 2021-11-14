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
queue <tree> que;
int leaf=0; 
void CreatBinaryTree()//���������� 
{
	char ch;
	tree bit,son;
	while(!que.empty())
	{
		ch = getchar();
		bit = que.front();
		que.pop();
		if(ch == '\n')
			break;
		bit->data = ch;
		son = (tree)malloc(sizeof(tree));//��ڵ� ������Ҳ����Ҷ��� 
		son->data = '\0';
		bit->left = son;
		que.push(son);
		son = (tree)malloc(sizeof(tree));//�ҽڵ� 
		son->data = '\0';
		bit->right = son;
		que.push(son);	
	}
}
void output(tree bit,int n) //�ݹ���� 
{
	int i;
	if(bit->data!='#'&&bit->data!='\0')
	{
		for(i=1;i<=n;i++)
		{
			printf("    ");
		}
		printf("%c",bit->data); 
		printf("\n");
		n++;
		output(bit->left,n);
		output(bit->right,n);
	}
}
void antione_output(tree bit,int n) //�ݹ���� 
{
	int i;
	if(bit->data!='#'&&bit->data!='\0')
	{
		for(i=1;i<=n;i++)
		{
			printf("    ");
		}
		printf("%c",bit->data); 
		printf("\n");
		n++;
		antione_output(bit->right,n);
		antione_output(bit->left,n);
	}
}
void preorder_traversal(tree bit)
{
	if(bit->data!='#'&&bit->data!='\0')
	{
		if((bit->left->data=='#'||bit->left->data=='\0')&&(bit->right->data=='#'||bit->right->data=='\0')) 
			leaf++;//ͳ��Ҷ�ӽڵ���Ŀ
		printf("%c",bit->data);
		preorder_traversal(bit->left);
		preorder_traversal(bit->right);
	}
	return; 
}
void antione_preorder_traversal(tree bit)
{
	if(bit->data!='#'&&bit->data!='\0')
	{
		printf("%c",bit->data);
		antione_preorder_traversal(bit->right);
		antione_preorder_traversal(bit->left);
	}
	return; 
}
void inorder_traversal(tree bit)
{
	if(bit->data!='#'&&bit->data!='\0')	
	{
		inorder_traversal(bit->left);
		printf("%c",bit->data);
		inorder_traversal(bit->right);
	} 
	return;
}
void antione_inorder_traversal(tree bit)
{
	if(bit->data!='#'&&bit->data!='\0')	
	{
		antione_inorder_traversal(bit->right);	
		printf("%c",bit->data);
		antione_inorder_traversal(bit->left);
	} 
	return;
}
void postorder_traversal(tree bit)  
{
	if(bit->data!='#'&&bit->data!='\0')	
	{
		postorder_traversal(bit->left);
		postorder_traversal(bit->right);
		printf("%c",bit->data);
	}
	return; 
}
void antione_postorder_traversal(tree bit)  
{
	if(bit->data!='#'&&bit->data!='\0')	
	{
		antione_postorder_traversal(bit->right);
		antione_postorder_traversal(bit->left);
		printf("%c",bit->data);
	}
	return; 
}
int main()
{
	tree root;
	printf("BiTree\n");
	root = (tree)malloc(sizeof(tree));//���ڵ�;
	que.push(root);
	CreatBinaryTree();//��������� 
	output(root,0);//��������� 
	printf("pre_sequence  : ");
	preorder_traversal(root);printf("\n");//�������
	printf("in_sequence   : ");
	inorder_traversal(root);printf("\n");//������� 
	printf("post_sequence : ");
	postorder_traversal(root);printf("\n"); //�������
	printf("Number of leaf: %d\n", leaf);
	printf("BiTree swapped\n");
	antione_output(root,0);//������������ 
	printf("pre_sequence  : ");
	antione_preorder_traversal(root);printf("\n");//�����������
	printf("in_sequence   : ");
	antione_inorder_traversal(root);printf("\n");//����������� 
	printf("post_sequence : ");
	antione_postorder_traversal(root);printf("\n"); //���������� 
return 0;	
} 
