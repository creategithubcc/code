#include <queue>  
#include <cstdio>  
#include <algorithm>  
#include <cstring>      //��������ע��ȫ������������뿴����ѧ�ϵı������ܲ���֧�ֳ��˺��ֺ���ĸ��������� 
#include <iostream>     //�����ѧ����ʾ�����룬�Ǿ�˵����ѧ�޷�֧�ֵ�������Ȼ���� 
using namespace std; 
const int x[]={0,0,1,-1};  
const int y[]={1,-1,0,0};  
struct sjk
{  
int xx,yy,t;  
sjk(int _x, int _y, int _time):xx(_x),yy(_y),t(_time){}  
};
int cmp(const void*a,const void*b)    
{    
return*(long long*)a>*(long long*)b;    
}     
int fun(const void*a1,const void*b1) 
{ 
return*(int*)a1-*(int*)b1; 
} 
queue<sjk> zhan;  
int c[100][100][55];////  �󤭤�����Ȥʤ����Ҥ�󤫤ʤ�����Ȥꤢ�����������ˤ��� 
char d[100][100];
int main()
{  
int i,j,k,n,m,p,q,ff=0,x1,y1,ans=0,xx,yy;  
cin>>n;  
for(i=0;i<n;i++)
{  
memset(d,'\0',sizeof(d));  
while(!zhan.empty())//zhan�Τʤ��ˤޤ��ǩ`������Фꤻ�ä� 
{  
zhan.pop();  
}  
cin>>m>>p>>q;  
for(i=0;i<m;i++) 
{  
cin>>d[i]; 
for(j=0;j<p;j++)
{  
if(d[i][j]=='S')//�����`�� 
{  
x1=i+1;  
y1=j+1;  
}  
}  
}  
zhan.push(sjk(x1-1,y1-1,0));//sjk�Τʤ��Τǩ`������夦����  
memset(c,0,sizeof(c));
c[x1-1][y1-1][0]=1;
while(!zhan.empty())
{  
sjk tmp=zhan.front();
zhan.pop();
if(d[tmp.xx][tmp.yy]=='E')//����ꡢ����������� 
{  
ff=1;
ans=tmp.t;
break;  
}  
for(i=0;i<=3;i++)
{  
xx=tmp.xx+x[i];yy=tmp.yy+y[i];
if(xx<0||xx>=m||yy<0||yy>=p||d[xx][yy]=='#'||c[xx][yy][(tmp.t+1)%q]==1||(d[xx][yy]=='*'&&(tmp.t+1)%q!=0)) 
{  
continue;  
}    
c[xx][yy][(tmp.t+1)%q]=1;  
zhan.push(sjk(xx,yy,tmp.t+1));
}  
}    
if(ff!=1)
{
cout<<"-1"<<endl;//	
} 
else if(ff==1)
{
ff=0;
cout<<ans<<endl;  
}    
}    
return 0;  
}  
