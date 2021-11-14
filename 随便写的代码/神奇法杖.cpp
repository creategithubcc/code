#include <iostream>  
#include <algorithm> 
#include <stdio.h>
using namespace std;
struct sjk
{  
    long long a;  
    long int b;  
};  
bool Cmp(const sjk &c, const sjk &d)           
{  
     return c.a<d.a;  
} 
int fun(const void*e,const void*f)
{
    return*(int*)e-*(int*)f;
}
sjk dog[10086];       //别问我为什么要狗，因为龙神要苟下去 
sjk dog2[10086];      //龙神 -1s-1s-1s-1s..... 
int main() //
{  
    long long int i,j,k,p,q,n,sum=1,t=0,max=0,ans=0;
    cin>>n>>q;//scanf("%d %d",&n,&q); 
    for(i=0;i<n;i++)
	{  
		cin>>dog[i].a>>dog[i].b;//scanf("%d %d",&dog[i].a,&dog[i].b);//输入时间和伤害 
        t+=dog[i].b;  //伤害积累
    }  
    sort(dog,dog+n,Cmp);//排序 
    dog2[0].a=dog[0].a;  //传递到新的数组里 
    dog2[0].b=dog[0].b;  
    for(i=1;i<n;i++)                          //每个时间点有一个值,要求去掉长度为k的一段时间段，使得整个时间轴的值最小
	{  
        if(dog[i].a==dog2[sum-1].a)           //从头到尾扫一遍
		{  
            dog2[sum-1].b+=dog[i].b;          //如果时间段一样，就可以在某个时刻抵挡n个人的攻击 
        }  
        else if(dog[i].a!=dog2[sum-1].a)
		{  
			dog2[sum].a=dog[i].a;     //        
            dog2[sum].b=dog[i].b;
            sum+=1;  
        }  
    } 
    for(i=0;i<q;i++)
	{  
        cin>>k;//scanf("%d",&k);                           //输入k 
        max=0;
		ans=0;  
        if(dog2[0].a+k-1>=dog2[sum-1].a)          //最后的时刻刚好和sum-1时刻一样的话就是零 
		{  
            cout<<"0\n";//printf("0\n");  
        }  
        else if(dog2[0].a+k-1<dog2[sum-1].a)
		{  
        for(j=0;j<sum;j++)
		{  
            if(dog2[j].a-dog2[0].a<=k-1)
			{  
                max+=dog2[j].b;  
                ans+=dog2[j].b;  
            }  
            else if(dog2[j].a-dog2[0].a>k-1)
			{
				p=0;
				p+=1;
				break;               
			}
        }  
        for(p=1;p<sum;p++)
		{  
            ans-=dog2[p-1].b;  
            while(j<=sum-1)//
			{  
                if(dog2[p].a+k-1>=dog2[j].a)
				{  
                    ans+=dog2[j].b;  
                    j+=1;  
                }  
                else if(dog2[p].a+k-1<dog2[j].a)
				{
					break;	
				}  
            }  
            if(max<ans)
			{  
                max=ans;  //如果答案大于最大值，则把答案的值赋给最大值 
            }
            else if(max>=ans)
            {
            	if(max==ans)
            	{
            		int x=ans;
				}
				else
				{
					int x=max;
				}
				/*cout<<t-x<<endl;*/
			}
        } 
        cout<<t-max<<endl;//printf("%d\n",t-max);  
        }  
    }  
}  
