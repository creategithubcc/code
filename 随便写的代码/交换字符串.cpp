#include<stdio.h>
#include<string.h>
#include<math.h>
int main()
{

char str1[1000];
gets(str1);
int len_str=strlen(str1);
char tmp;//×¢ÒâÊÇ×Ö·û´®
for(int i=0;i<len_str/2;i++)
{
tmp=str1[i];
str1[i]=str1[len_str-1-i];
str1[len_str-1-i]=tmp;
}
puts(str1);

return 0;

}
