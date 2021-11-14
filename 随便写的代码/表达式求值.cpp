#include<stdio.h>
#include<string.h>
#include<math.h>
int check(char s)
{
	if (s == '+' || s == '-' || s == '*' || s == '/' || s == '^' || s == '%')
		return 1;
	else
		return 0;
}

int jisuan(int x,int y,char p) 
{ 
  switch(p) 
  { 
      case '+':return x+y;break; 
     case '-':return x-y;break; 
     case '*':return x*y;break; 
     case '/':return x/y;break; 
     case '%':return x%y;break; 
     case '^':return pow(x,y);break;  
   }  
}  
int judge(char a, char b){
	if (a == b&&a == '^')
		return -1;
	if (a == b)
		return 1;
	if ((a == '*' || a == '/') && (b == '+' || b == '-'))
		return 1;
	if ((a == '+' || a == '-') && (b == '*' || b == '/'))
		return -1;
	if (a != '^'&&b == '^')
		return -1;
	if (a == '^'&&b != '^')
		return 1;
	if ((a == '+' || a == '-') && (b == '+' || b == '-'))
		return 1;
	if ((a == '*' || a == '/') && (b == '*' || b == '/'))
		return 1;
	if (a == '\0'&&check(b))
		return -1;
	if (a == '('&&check(b))
		return -1;
}

int main()
{
	int n,i,j=0,k=0;
	int fu=1;
	char str[500],stackstr[500];
	int stacknum[500];
	scanf("%d",&n);
	while(n--)
	{
		stackstr[0] = '\0'; 
		j=1;k=0;
		memset(stacknum,0,sizeof(stacknum));
		memset(str,'\0',sizeof(str));
		memset(stackstr,'\0',sizeof(stackstr));
		scanf("%s",&str); 
		int len =strlen(str);
		for(i = 0; i< len ; i++)
		{	fu = 1;
			if(i==0 && str[i+1]>='0' && str[i+1]<='9' && str[0]=='+')
			{
				i++;
				goto t;
			}
			if(i==0 && str[i+1]>='0' && str[i+1]<='9' && str[0]=='-')
			{
				i++;
				fu=-1;//负数
				goto t; 
			}
			if(str[i] =='(')
			{
				if(str[i-1]==')')
				{
					printf("error.\n");
					goto next;
				}
				if (str[i - 1] >= '0' && str[i - 1] <= '9')
				{
					printf("error.\n");
					goto next;
				}
				if (check(str[i + 1]) && str[i + 1]!='+' && str[i+1]!='-')
				{
					printf("error.\n");
					goto next;
				}
				stackstr[j]=str[i];
				j+=1;
				if ((str[i+1]=='+' ||str[i + 1] == '-') && str[i + 2] >= '0'&&str[i + 2] <= '9')
					i++;
			}
			else
			{
				if (str[i] >= '0' && str[i] <= '9')//是数字 
				{
					if (str[i - 1] == '-'&&(check(str[i - 2])||str[i-2]=='('))
						fu=-1;
					t:;
					while(1)
					{
						if (str[i]>='0' && str[i] <= '9')
						{
							stacknum[k] =stacknum[k] * 10 + str[i] - '0';
							i++;
						}
						else
							break;
					}		
						if(fu == -1)
						{
							stacknum[k] *=-1;
						}	
						k+=1;
						i--;
					
				}
				else//不是数字 
				{
					if(check(str[i]))
					{
						if(judge(stackstr[j-1],str[i]) == -1)
						{
							stackstr[j] = str[i];
							j++;
							if ((str[i + 1] == '+' || str[i + 1] == '-') && str[i + 2] >= '0'&&str[i + 2] <= '9')
								i++;
						}
						else
						{
							while (1)
							{
								if (judge(stackstr[j - 1], str[i])==1)
								{
									if (stacknum[k - 1] == 0 && stackstr[j - 1] == '/'){
										printf("Divide 0.\n");
										goto next;
									}
									if (stacknum[k - 1] < 0 && stackstr[j - 1] == '^'){
										printf("error.\n");
										goto next;
									}
									stacknum[k - 2] = jisuan(stacknum[k - 2], stacknum[k - 1], stackstr[j - 1]);
									stacknum[k - 1] = 0;
									k--;
									j--;
								}
								else
									break;
							}
							stackstr[j] = str[i];
							j++;
							if ((str[i + 1] == '+' || str[i + 1] == '-') && str[i + 2] >= '0'&&str[i + 2] <= '9')
								i++;
						}
					}
					else
					{
						if (str[i] == ')')
						{
							if (str[i + 1] >= '0' && str[i + 1] <= '9'){
								printf("error.\n");
								goto next;
							}
							if (str[i + 1] == '('){
								printf("error.\n");
								goto next;
							}
							while (1)
							{
								if (stackstr[j - 1] != '(')
								{
									if (stacknum[k - 1] == 0 && stackstr[j - 1] == '/')
									{
										printf("Divide 0.\n");
										goto next;
									}
									if (stacknum[k - 1] < 0 && stackstr[j - 1] == '^')
									{
										printf("error.\n");
										goto next;
									}
									if (stackstr[j - 1] == '\0')
									{
										printf("error.\n");
										goto next;
									}
									stacknum[k - 2] = jisuan(stacknum[k - 2], stacknum[k - 1], stackstr[j - 1]);
									stacknum[k - 1] = 0;
									k--;
									j--;
								}
								else
								{
									j--;
									break;
								}
							} 
						}
					}
				}
			}
		}
			while (1)
			{
				if (stackstr[j - 1] != '\0'&&stackstr[j - 1] !='(' )
				{
					if (stacknum[k - 1] == 0 && stackstr[j - 1] == '/')
					{
						printf("Divide 0.\n");
						goto next;
					}
					if (stacknum[k - 1]<0 && stackstr[j - 1] == '^')
					{
						printf("error.\n");
						goto next;
					}
					stacknum[k - 2] = jisuan(stacknum[k - 2], stacknum[k - 1], stackstr[j - 1]);
					stacknum[k-1] = 0;
					k--;
					j--;
				}
				else{
					if (stackstr[j - 1] == '(')
					{
						printf("error.\n");
						goto next;
					}
					else
						break;
				}
			}	
		printf("%d\n", stacknum[0]);
	next:;	
	}
return 0;	
} 
