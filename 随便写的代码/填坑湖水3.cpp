#include "stdio.h"
#include "stdlib.h"
typedef struct hole{               // struct hole����myhole��ֻ��Ϊ�˷���Ž�myhole���������� 
    long long number;
    long long width;
    long long height;
    struct hole *pre;             //ָ��ָ����һ�� ��һ���ڵ� 
    struct hole *next;           //ָ��ָ������һ���ڵ㣬��������ָ����hole����ṹ�壬�ڵ㱾�����hole 
} myhole;                        //hole�Ĺ����ǹ涨�ڵ㳤ʲô���������ڻ���DNA��Ӥ���Ĺ�ϵ 
 
long long ans[100005];
 
int main(){
    myhole *left, *right, *prehole, *cur, *deep;//������һ��ָ�룬��ָ����myhole��Ҳ����hole 
    long long n;
    long long a, b;
    left = (myhole *)malloc(sizeof(myhole));//�½�һ���ڵ㣬�����ʼ������Ҫ������ �����Ǹճ�����Ӥ�� ����û�����֣�����������������next����pre 
    left->width = 0;                        //һ�����ֽ���left�Ľڵ㣬���Ŀ�͸ߵ���0��1000005�����츳��ļ��� 
    left->height = 1000005;
    left->pre = left->next = NULL;         //�ڵ�left��ǰһ���ͺ�һ�����ǿ� 
    prehole = left;
    deep = left; 
    scanf("%lld", &n);
 
    for (long long i = 0; i < n; i++){
        scanf("%lld%lld", &a, &b);
        cur = (myhole *)malloc(sizeof(myhole)); //ָ��ֵ��ָ��һ���ڵ� 
        cur->width = a;
        cur->height = b;
        cur->pre = prehole;
        cur->next = NULL;
        cur->number = i;
        prehole->next = cur;
        prehole = cur;
 
        if(deep->height > b)//������ƽ̨ 
            deep = cur;
    }
 
    right = (myhole *)malloc(sizeof(myhole));
    right->width = 0;
    right->height = 1000005;
    right->pre = cur;
    cur->next = right;
    right->next = NULL;
 
 
    //��ʼ���㸲�ǵ���Ҫʱ��
    long long time = 0;
    while(deep->pre->height != deep->next->height){    //�ڵ�ָ��ڵ����������һ��������һ���ڵ㣬���ָ����������Ǹ��ڵ�ռ���ı��� 
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
