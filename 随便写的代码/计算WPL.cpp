#include<stdio.h>
#include<stdlib.h>
#include<limits.h>

int last = 0, sum = 0, len;
void FindMin(int num[])
{
    int x1 = last, x2 = last;
    int min = num[last];//定义最小
    int min2 = INT_MAX;//定义第二最小
    for (int i = last; i <len; i++)
    {
        if (num[i]<min)
        {
            min = num[i];
            x1 = i;
        }
    }//获得最小
    
    for (int i = last; i < len; i++)
    {
        if (num[i] <= min2 && i != x1)
        {
            min2 = num[i];
            x2 = i;
        }
    }//获得第二小
    num[x2] = min + min2;
    sum += num[x2];
    if (x2 == last)
        num[x1] = num[x2];
    else
        num[x1] = num[last];
    num[last] = 0;
    last++;
}
 int fun(int aa)
{
	for(int i = 0; i<=10 ; i++)
		aa++;
	return aa;
}
int main()
{
    int n;
    int num[10005] = { 0 };
    scanf("%d", &n);
    len = n;
    int aa = fun(5);
    if (len == 1)
    {
        printf("%d\n", num[0]);
        return 0;
    }
    for (int i = 0; i < n; i++)
        scanf("%d", &num[i]);
	int bb = fun(4);
    while (n > 1)
    {
        FindMin(num);
        n--;
    }
    printf("WPL=%d\n", sum);
    //system("pause");
    return 0;
}
