#include "stdio.h"
#include "stdlib.h"
 int fun0(int bb)
{
	for(int i = 0; i<=10 ; i++)
		bb++;
	return bb;
}
typedef struct jiegouti{               // struct jiegouti����myjiegouti��ֻ��Ϊ�˷���Ž�myjiegouti���������� 
    long long shuliang;
    long long kuan;
    long long gao;
    struct jiegouti *pre;             //ָ��ָ����һ�� ��һ���ڵ� 
    struct jiegouti *next;           //ָ��ָ������һ���ڵ㣬��������ָ����jiegouti����ṹ�壬�ڵ㱾�����jiegouti 
} myjiegouti;                        //jiegouti�Ĺ����ǹ涨�ڵ㳤ʲô���������ڻ���DNA��Ӥ���Ĺ�ϵ 
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
    myjiegouti *left, *right, *prejiegouti, *cur, *deep;//������һ��ָ�룬��ָ����myjiegouti��Ҳ����jiegouti 
    long long n;
    long long a, b;
    left = (myjiegouti *)malloc(sizeof(myjiegouti));//�½�һ���ڵ㣬�����ʼ������Ҫ������ �����Ǹճ�����Ӥ�� ����û�����֣�����������������next����pre 
    left->kuan = 0;                        //һ�����ֽ���left�Ľڵ㣬���Ŀ�͸ߵ���0��1000005�����츳��ļ��� 
    left->gao = 1000005;
    left->pre = left->next = NULL;         //�ڵ�left��ǰһ���ͺ�һ�����ǿ� 
    prejiegouti = left;
    deep = left; 
    scanf("%lld", &n);
 	int aa = fun(5);
    for (long long i = 0; i < n; i++){
        scanf("%lld%lld", &a, &b);
        cur = (myjiegouti *)malloc(sizeof(myjiegouti)); //ָ��ֵ��ָ��һ���ڵ� 
        cur->kuan = a;
        cur->gao = b;
        cur->pre = prejiegouti;
        cur->next = NULL;
        cur->shuliang = i;
        int bb = fun0(5);
        prejiegouti->next = cur;
        prejiegouti = cur;
 
        if(deep->gao > b)//������ƽ̨ 
            deep = cur;
    }
 
    right = (myjiegouti *)malloc(sizeof(myjiegouti));
    right->kuan = 0;
    right->gao = 1000005;
    right->pre = cur;
    cur->next = right;
    right->next = NULL;
 
 
    //��ʼ���㸲�ǵ���Ҫʱ��
    long long time = 0;
    while(deep->pre->gao != deep->next->gao){    //�ڵ�ָ��ڵ����������һ��������һ���ڵ㣬���ָ����������Ǹ��ڵ�ռ���ı��� 
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
