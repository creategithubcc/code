#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct bitnode
{
 char c;
 int  weigh;
 struct bitnode *parent;
 struct bitnode *lchild;
 struct bitnode *rchild;
}BiTNode;
BiTNode *queue[101];
BiTNode *leaf[101];

int cmp(const void *a,const void *b)
{
 if( (*(BiTNode **)a)->weigh==(*(BiTNode **)b)->weigh)
    return ( ((*(BiTNode **)a)->c)-((*(BiTNode **)b)->c)   );
 else
  return ( (*(BiTNode **)b)->weigh-(*(BiTNode **)a)->weigh);
}

typedef struct
{
 char c;
 int bit[20];
 int count;
}HCodeType;
HCodeType HuffCode[101];

void InsertSort(int min2)//插入排序
{
 int i,j;
 if(min2==1)
  queue[1]=queue[0];
 else
 { 
  i=1;
     while(i<min2&&queue[0]->weigh<=queue[i]->weigh)
   i++;
 
     for(j=min2;j>i;j--)
      queue[j]=queue[j-1];
          queue[i]=queue[0];
  }
}

void HUFFMAN(int n)//建立哈夫曼树
{  
 int min1,min2;
 int i;
 BiTNode *p;
 min1=n;//最小
 min2=n-1;//次小
 for(i=1;i<n;i++)
 {
  p=(BiTNode *)malloc(sizeof(BiTNode));//申请新节点做父节点
  p->lchild=queue[min1];//最小得做p的左孩子
  p->rchild=queue[min2];//次小得做p的左孩子
  queue[min1]->parent=queue[min2]->parent=p;//最小次小的父节点都是p

  p->weigh=queue[min1]->weigh+queue[min2]->weigh;//父节点的频度为左右孩子频度和
 
  p->parent=NULL;//父节点的父节点置空
  queue[0]=p;

  InsertSort(min2);//插入排序
 
  min1=min2;// 最小   //队列成员减少1
  min2--;   //次小
 }
}

void HaffmanCode(int n)//求字符的哈弗曼编码
{
 BiTNode *child,*parent;
 int count,bit[21];
 int i,j,k;
 for(i=1;i<=n;i++)
 {
  child=leaf[i];
  parent=child->parent;
  count=21;

  while(parent)//    父节点是不空继续向上   空则是根节点即停止
  { 
      if(child==parent->lchild)//孩子是父节点的左孩子 则置0
     bit[--count]=0;
      else                     //孩子是父节点的右孩子 则置1
     bit[--count]=1;

   child=parent;           //孩子、父节点均向上取
   parent=parent->parent;
  }
       
  for(j=count,k=1;j<=20;j++,k++)//反向求字符的哈弗曼编码
   HuffCode[i].bit[k]=bit[j];
  HuffCode[i].count=k-1;
  HuffCode[i].c=leaf[i]->c;
 }
}

void preorder(BiTNode *bt)//先序遍历哈夫曼树
{
 if(bt==NULL)
  return ;
 if(bt->lchild)
 printf("%d\n",bt->weigh);
 else
       printf("%c %d\n",bt->c,bt->weigh);
 preorder(bt->lchild);
 preorder(bt->rchild);
 
}

void print(int n)//输出各字符的哈弗曼编码
{
 int i,j;
 for(i=1;i<=n;i++)
 { 

  printf("%c ",HuffCode[i].c);
  for(j=1;j<=HuffCode[i].count;j++)
   printf("%d",HuffCode[i].bit[j]);
  printf("\n");
 }
 printf("\n");
}


int main()
{   freopen("1.txt","r",stdin);
 int n,i,f,c;
 BiTNode *p;
 printf("请输入字符的个数N:\n");
 scanf("%d ",&n);
 printf("请输入字符&它们的频度\n");

 for(i=1;i<=n;i++)//各字符的录入并申请 叶子节点
 {
  p=(BiTNode *)malloc(sizeof(BiTNode));
  scanf("%c ",&c);
  p->c=c;
  p->lchild=p->rchild=NULL;
  queue[i]=p;
 }
 
 for(i=1;i<=n;i++)//各字符频度的录入
 {
  scanf("%d ",&f);
  queue[i]->weigh=f;
 }
 qsort(queue+1,n,sizeof(queue[1]),cmp);//各字符按频度由大到小排列 频度相同则按字典序排列
 for(i=1;i<=n;i++)
 {
  leaf[i]=queue[i];//指针leaf向量指向各字符 方便求字符的哈弗曼编码
   //  printf("l==%c %d\n",leaf[i]->c,queue[i]->weigh);
 }
 
    HUFFMAN(n);//建立哈夫曼树

// preorder(queue[1]);//先序遍历哈夫曼树

 HaffmanCode(n);//求字符的哈弗曼编码

 print(n);//输出各字符的哈弗曼编码
 return 0;
}
