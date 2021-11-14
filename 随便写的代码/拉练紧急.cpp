#include<cmath>
#include<iostream>
#define INF 2147483647
using namespace std;
struct Point
{
    long long int x,y;
    Point(long long int x_, long long int y_):x(x_), y(y_){};
    Point(){};
};
long long int fun(Point a, Point b)
{
    return abs(a.x-b.x)+abs(a.y-b.y);
}
long long int i,j,k,n,m,c,d;//
Point sushe[1000086];
Point jihe[1000086];
int main()
{
    cin>>n>>m;
    cin>>c;
    Point jiao[4]={Point(0,0),Point(0,n),Point(0,m),Point(n,m)};
    long long int jiao_sushe[4]={-1,-1,-1,-1};
    long long int jiao_fun[4]={INF,INF,INF,INF};
    for(i=0;i<c;i++)
	{
        cin>>sushe[i].x>>sushe[i].y; 
        for(j=0;j<4;j++)
		{
            if(fun(sushe[i],jiao[j])<jiao_fun[j])
			{
                jiao_fun[j]=fun(sushe[i],jiao[j]);
                jiao_sushe[j]=i;
            }
        }
    }
    long long int min_time=INF;
    cin>>d;
    for(i=0;i<d;i++)
	{
        cin>>jihe[i].x>>jihe[i].y;
        long long int time=0;
        for(j=0;j<4;j++)
		{
            time=max(time,fun(jihe[i],sushe[jiao_sushe[j]]));
        }
        min_time=min(min_time,time);
    }
    cout<<min_time<<endl;
}
