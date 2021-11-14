#include<stdio.h>
#define N 10
int count[N];
int value=1;
void Deal(int k)
{
    if(k<=0)return;
    int one,ten;
    one=k%10;
    k/=10;
    ten=k;

    for(int i=0;i<=one;i++)  //��һ��
    {
        count[i]+=value;
    }

    while(ten)  //��һ��
    {
        count[ten%10]+=value*(one+1);
        ten/=10;
    }

    for(int j=0;j<10;j++) //�ڶ���
    {
        count[j]+=value*k;
    }
    count[0]-=value;
    value*=10;  //������
    Deal(k-1);   //������

}
int main()
{
    int a,b;
    while(scanf("%d%d",&a,&b)!=EOF)
    {
        for(int i=0;i<10;i++)
        count[i]=0;
        value=1;
        Deal(b);
        value=-1;
        Deal(a-1);
        printf("%d\n",count[1]);

    }
    

    return 0;
}
