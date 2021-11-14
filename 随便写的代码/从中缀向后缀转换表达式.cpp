#include<cstdio> 
#include<string.h> 
#include<map> 
#include<stack> 
#include<math.h> 
#include<iostream> 
#include<cctype>
#include<cstring>
using namespace std; 
int GetproiIncoming(char c);
int GetproInstack(char c);
string str; 
stack<char> stchar;
int main()
{
	int n,i,j;
	scanf("%d%*c",&n);
	while(n--)
	{
		while(!stchar.empty())//Çå¿ÕÕ» 
			stchar.pop();
		getline(cin, str);
		for(i=0;str[i]!='#';i++)
		{
			if((isalpha(str[i]))||isdigit(str[i]))
			{
				printf("%c",str[i]);
				continue;
			}
			else
			{
				if(i==0&&str[i]=='-'&&(isdigit(str[i+1])||isalpha(str[i+1])))
				{
					printf("%c",str[i]);
					continue;
				}
	            if (stchar.empty()||str[i]=='(') 
				{ 
                  	stchar.push(str[i]); //ÈëÕ» 
					continue; 
                }
				else if(str[i] == ')')
				{
					while(!stchar.empty() &&  stchar.top()!= '(')
					{
						printf("%c",stchar.top());
						stchar.pop(); 
					}
					stchar.pop(); //µ¯³ö) 
				}
				else
				{
					if(str[i]=='-'&&(isalpha(str[i+1])||isdigit(str[i+1]))&&str[i-1]=='(')
					{
						printf("%c",str[i]);
						continue;	
					} 
					int val = GetproiIncoming(str[i]);
					int tag;
					while(!stchar.empty() && (tag = GetproInstack(stchar.top())) > val)
					{
						printf("%c", stchar.top());
						stchar.pop();
					}
					stchar.push(str[i]);
				} 
			}	
		}		
		while (!stchar.empty())
		{
			printf("%c",stchar.top());
			stchar.pop();	
		}
	  	printf("\n");
	}
return 0;	
}
int GetproiIncoming(char c)
{ 
	switch (c) 
	{ 
	  case('+') : return 3; 
	  case('-') : return 3; 
	  case('*') : return 5; 
	  case('/') : return 5; 
	  case('%') : return 5; 
	  case('(') : return 10; 
	  case('^') : return 8; 
	} 
} 
int GetproInstack(char c)
{ 
   	switch (c) 
 	{ 
	  	case('+') : return 4; 
	  	case('-') : return 4; 
	  	case('*') : return 6; 
	  	case('/') : return 6; 
	  	case('%') : return 6; 
	  	case('(') : return 1; 
	  	case('^') : return 7; 
  	} 
} 
