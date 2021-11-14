#include<stdio.h>   
#include<string.h> 
int i,j,l=0,tl=0,ans=0,a[1000]={0},b[30]={0},p=0,c[30]={0},max=0,e[1000]={0};
char d[1000]={0};   
int main()   
{   
    scanf("%s",d);
	int q;
	q=strlen(d);   
    for(i=0;i<q;i++)   
    {   
        if(d[i]=='(') 
		{
			l++;
		}  
		else if(d[i]==',')
		{
			continue;   
		}
        else if(d[i]==')')   
        {
			l--;  
		}   
        else   
        {   
            ans++;     
            for(j=0;j<l-1;j++)   
            {
            	printf("    "); 
			}      
            printf("%c\n",d[i]);   
            if(l>tl)
            {   
                p++;   
                b[p]=ans-1;   
                c[ans]=b[p];   
                tl=l;   
            }   
            else if(l==tl)
            {
            	c[ans]=b[p];
			}
            else
            {   
                p--;   
                c[ans]=b[p];   
                tl=l;   
            }    
        }   
    }   
   /* int tt=0;
    for(i=0;i<ans;i++) 
	{
		tt++;   
	}  */ 
    for(i=0;i<=ans;i++) 
	{
		e[c[i]]++;   
	}     
    for(i=1;i<=ans;i++)   
    {   
        max=((max>e[i])?max:e[i]);   
        a[e[i]]++;   
    }   
    printf("Degree of tree: %d\n",max);   
    for(i=0;i<=max;i++) 
	{
		printf("Number of nodes of degree %d: %d\n",i,a[i]);   
	}   
} 
