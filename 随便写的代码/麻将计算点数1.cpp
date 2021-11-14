#include <stdio.h>
#include <math.h>

long long int t;

int main()
{
 int x,y,z;
 scanf("%d",&t);
 for(;t>0;t--)
 {
  z=0;
  scanf("%d %d",&x,&y);
  switch(x)
  {
    case 1:case 2: 
   {
    z=6*(int)(pow(2*1.0,(2+x)*1.0))*y;
          if (z%100==0)
           z=z/100*100;
          else 
           z=z/100*100+100;
          printf("%d\n",z);
          break;
   }
     case 3:
      {
       if (y>=70)
       {
        printf("12000\n");
        break;
       }
    else
    {
     z=6*(int)(pow(2*1.0,(2+x)*1.0))*y;
              if (z%100==0)
                z=z/100*100;
              else 
                z=z/100*100+100;
              printf("%d\n",z);
              break;
    }
   }
   case 4:
   {
    if (y>=40)
     {
        printf("12000\n");
        break;
       }
    else if (y==25)
     {
      printf("9600\n");
        break;
     }
    else
     {
      printf("11600\n");
        break;
     }
   }
   case 5:
    {
     printf("12000\n");
     break;
    }
   case 6:case 7:
    {
     printf("18000\n");
     break;
    }
   case 8:case 9:case 10:
    {
     printf("24000\n");
     break;
    }
   case 11:case 12:
    {
     printf("36000\n");
     break;
    }
   default:
    {
     printf("48000\n");
     break;
    }
  }
  
 }
}
