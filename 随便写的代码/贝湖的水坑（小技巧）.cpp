#include "stdio.h"
#include "stdlib.h"
 int fun0(int bb)
{
	for(int i = 0; i<=10 ; i++)
		bb++;
	return bb;
}
typedef struct jiegouti{               // struct jiegouti就是myjiegouti，只是为了方便才叫myjiegouti，用来申明 
    long long shuliang;
    long long kuan;
    long long gao;
    struct jiegouti *pre;             //指针指向了一个 上一个节点 
    struct jiegouti *next;           //指针指向了下一个节点，他们两个指向了jiegouti这个结构体，节点本身就是jiegouti 
} myjiegouti;                        //jiegouti的功能是规定节点长什么样，类似于基因DNA和婴儿的关系 
  int fun1(int cc)
{
	for(int i = 0; i<=10 ; i++)
		cc++;
	return cc;
}
long long daan[100005];
 
 int fun(int aa)
{
	for(int i = 0; i<=10 ; i++)
		aa++;
	return aa;
}
int main(){
    myjiegouti *left, *right, *prejiegouti, *cur, *deep;//声明了一个指针，他指向了myjiegouti，也就是jiegouti 
    long long n;
    long long a, b;
    left = (myjiegouti *)malloc(sizeof(myjiegouti));//新建一个节点，链表最开始都必须要这个语句 ，这是刚出生的婴儿 ，他没有名字，你想访问它必须得用next或是pre 
    left->kuan = 0;                        //一个名字叫做left的节点，它的宽和高等于0和1000005，后天赋予的技能 
    left->gao = 1000005;
    left->pre = left->next = NULL;         //节点left的前一个和后一个都是空 
    prejiegouti = left;
    deep = left; 
    scanf("%lld", &n);
 	int aa = fun(5);
    for (long long i = 0; i < n; i++){
        scanf("%lld%lld", &a, &b);
        cur = (myjiegouti *)malloc(sizeof(myjiegouti)); //指针值是指向一个节点 
        cur->kuan = a;
        cur->gao = b;
        cur->pre = prejiegouti;
        cur->next = NULL;
        cur->shuliang = i;
        int bb = fun0(5);
        prejiegouti->next = cur;
        prejiegouti = cur;
 
        if(deep->gao > b)//求出最低平台 
            deep = cur;
    }
 
    right = (myjiegouti *)malloc(sizeof(myjiegouti));
    right->kuan = 0;
    right->gao = 1000005;
    right->pre = cur;
    cur->next = right;
    right->next = NULL;
 
 
    //开始计算覆盖的需要时间
    long long time = 0;
    while(deep->pre->gao != deep->next->gao){    //节点指向节点代表他的上一个或是下一个节点，如果指向变量则是那个节点空间里的变量 
        daan[deep->shuliang] = time + deep->kuan;
        if(deep->pre->gao > deep->next->gao){
            time = time + (deep->next->gao - deep->gao) * deep->kuan;
            deep->next->kuan += deep->kuan;
            deep->pre->next = deep->next;
            deep->next->pre = deep->pre;
            deep = deep->next;
        }
        else{
            time = time + (deep->pre->gao - deep->gao) * deep->kuan;
            deep->pre->kuan += deep->kuan;
            deep->pre->next = deep->next;
            deep->next->pre = deep->pre;
            deep = deep->pre;
           int cc = fun(5);
        }
 
        if(deep->gao < deep->pre->gao && deep->gao < deep->next->gao)
            continue;
        else if(deep->pre->gao > deep->next->gao){
            while(deep->gao > deep->next->gao)
                deep = deep->next;
        }
        else{
            while(deep->gao > deep->pre->gao)
                deep = deep->pre;
        }
    }
    daan[deep->shuliang] = time + deep->kuan;
 
    for (long long i = 0; i < n; i++){
        printf("%lld\n", daan[i]);
    }
}
