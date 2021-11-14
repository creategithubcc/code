#include <iostream>  
#include <cstdio>  
#include <algorithm>  
#include <cstring>  
#include <math.h>  
#include <queue>  
using namespace std;  

const int x[]={0,0,1,-1};  
const int y[]={1,-1,0,0};
struct sjk 
{  
int xx, yy;  
int s;  
int t;  
sjk(int _x,int _y,int _step,int _time):xx(_x),yy(_y),s(_step),t(_time){}  
};  
queue<sjk> que;  
int c[1000][1000];  
char d[1000][1000];  
int main() 
{  
int i,j,k,n,m,tt,ff=0,xx,yy,x1,y1,x2,y2,ans=0;
cin>>n>>m>>k;
for (i=0;i<=n-1;i++) 	
{  
cin>>d[i];  
}  
cin>>x1>>y1>>x2>>y2;
memset(c,0,sizeof(c));  
que.push(sjk(x1,y1,0,0));  
c[x1-1][y1-1]=1;  
while (!que.empty())
{  
sjk tmp=que.front();/////////////
tt=tmp.t;  
que.pop();  
if(tmp.xx==x2&&tmp.yy==y2) 
{  
ans=tmp.t;ff=1;  
break;  
}  ////////////
for(i=0;i<=3;i++) 
{  
tt=tmp.t;/////////  
for(j=1;j<=k;j++)
{  
xx=tmp.xx+j*x[i],yy=tmp.yy+j*y[i];  

if(xx<=0||xx>n||yy<=0||yy>m||d[xx-1][yy-1]=='#') 
{  
break;  
}  
if(c[xx-1][yy-1]==1)
{  
continue;  
}  
if(xx==x2&&yy==y2)
{  
ans=tt+1;  
ff=1;  
goto loop;  
}  
que.push(sjk(xx,yy,tmp.s+1,tt+1)); 
c[xx-1][yy-1]=1;  
}  
}  
}  
loop:;     
if(ff==1)
{
printf("%d\n",ans);
}   
else 
{
printf("-1\n");
}  
return 0;  
}  
