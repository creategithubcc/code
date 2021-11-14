#include <iostream> 
#include <algorithm>//这道题c++会更简单些 
using namespace std;
struct jgt
{ 
long long zb[3]; 
long long code; 
}xyz[100000]; 
int cmp(const void*a, const void*b)            //当return的是ture时，a先输出，所以示例中是升序 
{ 
	struct jgt*c=(jgt*)a; 
	struct jgt*d=(jgt*)b; 
	if((c->zb[2])!=(d->zb[2]))
	{
		return d->zb[2]-c->zb[2]; 
	}
	else if((c->zb[2]==d->zb[2])&&(c->zb[1]!=d->zb[1]))
	{
		return c->zb[1]-d->zb[1]; 	
	}
	else
	{
		return c->zb[0]-d->zb[0]; 
	}
} 
int fun(const void*aa,const void*bb)
{
    return*(int*)aa-*(int*)bb;
}
int main(int argc, char** argv) 
{ 
       long long int n,i,j,p=0,q=0,sum[100086],num[100086],flag,id,max1,max2,g; 
    	cin>>n; 
      for(i=0;i<n;i++)
	  { 
	  	cin>>xyz[i].zb[0]>>xyz[i].zb[1]>>xyz[i].zb[2];
        xyz[i].code=i+1; 
        } 
      for(i=0;i<n;i++)
	  { 
           sort(xyz[i].zb,xyz[i].zb+3); //把坐标按照从小到大排序 
    	} 
      qsort(xyz,n,sizeof(xyz[0]),cmp); //排序xyz数组本身 
      max1=xyz[0].zb[0];
	  q=xyz[0].code; 
     for(i=0;i<n;i++)
	 { 
           if(max1<xyz[i].zb[0])
		   { 
                max1=xyz[i].zb[0];
				q=xyz[i].code; 
         	} 
      }  
      j=0;
     for(i=0;i<n-1;i++)
	 { 
         if((xyz[i].zb[2]==xyz[i+1].zb[2])&&(xyz[i].zb[1]==xyz[i+1].zb[1]))
		 { 
			num[j]=i; 
			sum[j]=xyz[i].zb[0]+xyz[i+1].zb[0];
             if(sum[j]>xyz[i].zb[1])
			 { 
                  sum[j]=xyz[i].zb[1]; 
             } 
              j+=1; 
         } 
      } 
      g=0;
      for(i=0;i<n-1;i++)
      {
      	
      	/*if(xyz[i].zb[0]==xyz[i+1].zb[0]==xyz[i+2].zb[0])             这是一段实验
      	{
      		if(xyz[i].zb[1]==xyz[i+1].zb[1]==xyz[i+2].zb[1])
      	{
      		if(xyz[i].zb[2]==xyz[i+1].zb[2]==xyz[i+2].zb[2])
      	{
      		g=(xyz[i].zb[0])*(2*xyz[i].zb[1])*(xyz[i].zb[2]);
		  }
		  }
		  }
	  }*/
      max2=sum[0];
	  id=0; 
      for(i=0;i<j;i++)
	  { 
           if(max2<sum[i])
		   { 
                max2=sum[i];
				id=i; 
           } 
      } 
      if(max2>max1)
	  { 
	  cout<<"2\n"<<xyz[num[id]].code<<" "<<xyz[num[id]+1].code<<endl; 
      } 
      else 
	  {
	  	cout<<"1\n"<<q<<endl;
	  }
    }  

