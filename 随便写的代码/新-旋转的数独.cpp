#include<iostream>
#include<string.h>
#define qwe int
#define zxc void
#define asd char
#define ine return
#define iop for
#define kl if
#define f(i,a,y) iop (qwe i=4,a=y;i>0;i--,a++)
#define r(j,b,x) iop (qwe j=4,b=x;j>0;j--,b--)
#define q(j,a,y) iop (qwe j=1,a=y;j<5;j++,a++)
#define w(i,b,x) iop (qwe i=4,b=x;i>=1;i--,b--)
#define e(i) iop (qwe i=1;i<=4;i++)
qwe ff(qwe x);
inline qwe g(asd c);
zxc hh(qwe i, qwe j);
using namespace std;
asd aa[63][63],bb[63][63];
qwe cc[63],dd[21][21][3],ee[21][21][3],gg;
zxc cub(qwe x,qwe y)
{
f(i,a,y)
{
r(j,b,x)
bb[i][j]=aa[b][a];
}
q(j,a,y)
{
w(i,b,x)
aa[b][a]=bb[i][j];
}
}

#define l(j) iop (qwe j=1;j<=16;j++)
qwe main()
{
qwe N;
cin>>N;
memset(ee,0,sizeof(ee));
while(N--)
{
l(i)
cin>>aa[i]+1;
gg=48;
hh(4,0);
cout<<gg<<endl;
e(i)
e(j)
kl(ee[i][j][0]!=0)
iop(qwe k=0;k<ee[i][j][0];k++)
cout<<i<<" "<<j<<endl;
memset(ee,0,sizeof(ee));
}
}

qwe ff(qwe x)
{
iop (qwe i=x-3;i<=x;i++)
{
memset(cc,0,sizeof cc);
l(j)
{
kl(cc[g(aa[i][j])]!=0)
ine 0;
cc[g(aa[i][j])]=1;
}
}
l(j)
{
memset(cc,0,sizeof cc);
iop(qwe i=1;i<=x;i++)
{
kl(cc[g(aa[i][j])]!=0)
ine 0;
cc[g(aa[i][j])]=1;
}
}
ine 1;
}

inline qwe g(asd c)
{
ine(c>='0'&&c<='9')?c-'0':c-'A'+10;
}

#define abc(a,i,j) iop (qwe a=0;a<=3;a++,cub(i,j))
#define fgh(m) iop (qwe m=1;m<=4;m++)
zxc hh(qwe i,qwe j)
{
kl(i>16)
{
kl(gg>=j)
{
gg=j;
fgh(m)
fgh(n)
ee[m][n][0]=dd[m][n][0];
ine;
}
else kl(gg<j)
ine;
}
else kl(j>gg)
ine;
abc(a,i,1)
{
abc(b,i,5)
{
abc(c,i,9)
{
abc(d,i,13)
{
kl(ff(i)==0)
continue;
dd[i/4][1][0]=a;
dd[i/4][2][0]=b;
dd[i/4][3][0]=c;
dd[i/4][4][0]=d;
hh(i+4,j+a+b+c+d);
}
}
}
}
}
