#include<stdio.h>
int main()
{
int x = 3;
int *p, *q;
p = &x, q = &x;
printf("p=%p,p=%d\n", p, *p);
printf("%d\n", *p++);
printf("p=%p,p=%d\n", p, *p);
printf("-----\n");
printf("%d\n", (*q)++);
printf("%d\n", x);
}
