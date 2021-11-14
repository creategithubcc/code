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

void InsertSort(int min2)//��������
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

void HUFFMAN(int n)//������������
{  
 int min1,min2;
 int i;
 BiTNode *p;
 min1=n;//��С
 min2=n-1;//��С
 for(i=1;i<n;i++)
 {
  p=(BiTNode *)malloc(sizeof(BiTNode));//�����½ڵ������ڵ�
  p->lchild=queue[min1];//��С����p������
  p->rchild=queue[min2];//��С����p������
  queue[min1]->parent=queue[min2]->parent=p;//��С��С�ĸ��ڵ㶼��p

  p->weigh=queue[min1]->weigh+queue[min2]->weigh;//���ڵ��Ƶ��Ϊ���Һ���Ƶ�Ⱥ�
 
  p->parent=NULL;//���ڵ�ĸ��ڵ��ÿ�
  queue[0]=p;

  InsertSort(min2);//��������
 
  min1=min2;// ��С   //���г�Ա����1
  min2--;   //��С
 }
}

void HaffmanCode(int n)//���ַ��Ĺ���������
{
 BiTNode *child,*parent;
 int count,bit[21];
 int i,j,k;
 for(i=1;i<=n;i++)
 {
  child=leaf[i];
  parent=child->parent;
  count=21;

  while(parent)//    ���ڵ��ǲ��ռ�������   �����Ǹ��ڵ㼴ֹͣ
  { 
      if(child==parent->lchild)//�����Ǹ��ڵ������ ����0
     bit[--count]=0;
      else                     //�����Ǹ��ڵ���Һ��� ����1
     bit[--count]=1;

   child=parent;           //���ӡ����ڵ������ȡ
   parent=parent->parent;
  }
       
  for(j=count,k=1;j<=20;j++,k++)//�������ַ��Ĺ���������
   HuffCode[i].bit[k]=bit[j];
  HuffCode[i].count=k-1;
  HuffCode[i].c=leaf[i]->c;
 }
}

void preorder(BiTNode *bt)//���������������
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

void print(int n)//������ַ��Ĺ���������
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
 printf("�������ַ��ĸ���N:\n");
 scanf("%d ",&n);
 printf("�������ַ�&���ǵ�Ƶ��\n");

 for(i=1;i<=n;i++)//���ַ���¼�벢���� Ҷ�ӽڵ�
 {
  p=(BiTNode *)malloc(sizeof(BiTNode));
  scanf("%c ",&c);
  p->c=c;
  p->lchild=p->rchild=NULL;
  queue[i]=p;
 }
 
 for(i=1;i<=n;i++)//���ַ�Ƶ�ȵ�¼��
 {
  scanf("%d ",&f);
  queue[i]->weigh=f;
 }
 qsort(queue+1,n,sizeof(queue[1]),cmp);//���ַ���Ƶ���ɴ�С���� Ƶ����ͬ���ֵ�������
 for(i=1;i<=n;i++)
 {
  leaf[i]=queue[i];//ָ��leaf����ָ����ַ� �������ַ��Ĺ���������
   //  printf("l==%c %d\n",leaf[i]->c,queue[i]->weigh);
 }
 
    HUFFMAN(n);//������������

// preorder(queue[1]);//���������������

 HaffmanCode(n);//���ַ��Ĺ���������

 print(n);//������ַ��Ĺ���������
 return 0;
}
