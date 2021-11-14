#include "stdio.h"
#include "stdlib.h"
typedef struct hole{               // struct hole就是myhole，只是为了方便才叫myhole，用来申明 
    long long number;
    long long width;
    long long height;
    struct hole *pre;             //指针指向了一个 上一个节点 
    struct hole *next;           //指针指向了下一个节点，他们两个指向了hole这个结构体，节点本身就是hole 
} myhole;                        //hole的功能是规定节点长什么样，类似于基因DNA和婴儿的关系 
 
long long ans[100005];
 
int main(){
    myhole *left, *right, *prehole, *cur, *deep;//声明了一个指针，他指向了myhole，也就是hole 
    long long n;
    long long a, b;
    left = (myhole *)malloc(sizeof(myhole));//新建一个节点，链表最开始都必须要这个语句 ，这是刚出生的婴儿 ，他没有名字，你想访问它必须得用next或是pre 
    left->width = 0;                        //一个名字叫做left的节点，它的宽和高等于0和1000005，后天赋予的技能 
    left->height = 1000005;
    left->pre = left->next = NULL;         //节点left的前一个和后一个都是空 
    prehole = left;
    deep = left; 
    scanf("%lld", &n);
 
    for (long long i = 0; i < n; i++){
        scanf("%lld%lld", &a, &b);
        cur = (myhole *)malloc(sizeof(myhole)); //指针值是指向一个节点 
        cur->width = a;
        cur->height = b;
        cur->pre = prehole;
        cur->next = NULL;
        cur->number = i;
        prehole->next = cur;
        prehole = cur;
 
        if(deep->height > b)//求出最低平台 
            deep = cur;
    }
 
    right = (myhole *)malloc(sizeof(myhole));
    right->width = 0;
    right->height = 1000005;
    right->pre = cur;
    cur->next = right;
    right->next = NULL;
 
 
    //开始计算覆盖的需要时间
    long long time = 0;
    while(deep->pre->height != deep->next->height){    //节点指向节点代表他的上一个或是下一个节点，如果指向变量则是那个节点空间里的变量 
        ans[deep->number] = time + deep->width;
        if(deep->pre->height > deep->next->height){
            time = time + (deep->next->height - deep->height) * deep->width;
            deep->next->width += deep->width;
            deep->pre->next = deep->next;
            deep->next->pre = deep->pre;
            deep = deep->next;
        }
        else{
            time = time + (deep->pre->height - deep->height) * deep->width;
            deep->pre->width += deep->width;
            deep->pre->next = deep->next;
            deep->next->pre = deep->pre;
            deep = deep->pre;
        }
 
        if(deep->height < deep->pre->height && deep->height < deep->next->height)
            continue;
        else if(deep->pre->height > deep->next->height){
            while(deep->height > deep->next->height)
                deep = deep->next;
        }
        else{
            while(deep->height > deep->pre->height)
                deep = deep->pre;
        }
    }
    ans[deep->number] = time + deep->width;
 
    for (long long i = 0; i < n; i++){
        printf("%lld\n", ans[i]);
    }
}
