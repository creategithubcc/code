#include <iostream>  
#include <cstring> 
using namespace std;  
long long int aa[2086],a,b,m,bb[2086];  
int main()
{  
int n,i,j;                                                     //���}�Υݥ���Ȥ� 
cin>>n>>m;  												// //���`��i��1����n�ޤ�
long long int cc[2086];  									// ��s���Ƥ���Τϣ�i��Ŀ�Τ��x�k�����Ȥ��Υץ�����Ǥ���
memset(cc,0,sizeof cc);  									// �ڥ�`�פ�0�����D1�Ǥ��꣬���줾�섏�ब0�Ȅ��ब��D1��
memset(bb,0,sizeof bb);  									// ����Ȥ�������ϣ�ǵ��_�����ܤǤ���Τǣ���D1��ʮ�֤Ǥ���.
for(i=0;i<n;i++)
{  
cin>>aa[i];  
} 
for(j=0;j<n;j++)
{
b=m;
} 
for(j=0;j<n;j++)                                         
{  
for(i=0;i<m;i++)
{  
bb[(i+aa[j])%m]=cc[(i+aa[j])%m]%10000000+cc[i]%10000000;  
bb[(i+aa[j])%m]=bb[(i+aa[j])%m]%10000000;  
} 
for(i=0;i<m;i++)
{
for(b=0;b<m;b++)
{
cc[i]=bb[i]; 
} 
}  
cc[aa[j]%m]++;  
}  
cout<<cc[0]<<endl;  
}  
