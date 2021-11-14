#include<stdio.h>
#include<math.h>
#include<string.h>
#include<algorithm>
using namespace std;
int n,i,j,mid,k;
double min;
double MIN(double a,double b) 
{
	return a<b?a:b;
}
struct ZBD
{
    double x,y;
}ans[100086],anser[100086];
double fuc(ZBD a,ZBD b)
{
    double gen=sqrt((b.x-a.x)*(b.x-a.x)+(b.y-a.y)*(b.y-a.y));//x*x+y*y的根  
    return gen;
}
bool pdy(ZBD a,ZBD b) 
{
	return a.y<b.y;
}
bool pdx(ZBD a,ZBD b) 
{
	return a.x<b.x;
}
double function(int left,int right)
{
	if(left+2==right)
	{
		return MIN(fuc(ans[left],ans[left+1]),MIN(fuc(ans[left],ans[right]),fuc(ans[left+1],ans[right])));
	}
    else if(left+1==right) 
	{
		return fuc(ans[left],ans[right]);//2点
	}
    mid=(left+right)>>1;
    double min=MIN(function(left,mid),function(mid+1,right));
    k=0;
    for(i=left;i<=right;i++)
    {
        if(fabs(ans[i].x-ans[mid].x)<=min)
        {
        	anser[k++]=ans[i];
		}    
    }
    sort(anser,anser+k,pdy);
    for(i=0;i<k;i++) 
	{
		j=0;
		for(j=i+1;j<k;j++)
	    {
	        if(anser[j].y-anser[i].y>=min)//两两相乘大于min的话就不是最小的了 
			{
				break;
			}
	        min=MIN(min,fuc(anser[i],anser[j]));
	    }
	}
    return min;
}
int main()
{
	int n,i; 
    loop: 
    scanf("%d",&n); 
    if(n!=0) 
    { 
       for(i=0;i<n;i++) 
        { 
          scanf("%lf%lf",&ans[i].x,&ans[i].y);
        } 
        sort(ans,ans+n,pdx);
        printf("%.2lf\n",function(0,n-1)/2); 
        goto loop; 
    } 
  else if(n==0) 
  { 
      return 0; 
  } 
}
