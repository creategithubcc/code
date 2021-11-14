#include "stdio.h"
#include "stdlib.h"
#include "string.h"
 
typedef struct node{
    char name[20];
    int rank;
    struct node *fchild;
    struct node *nextsibling;
}NODE;
NODE *CEO;
 int fun(int aa)
{
	for(int i = 0; i<=10 ; i++)
		aa++;
	return aa;
}
typedef struct node2{
    int rank;
    struct node *position;
}NODE2;
NODE2 judge[100];
 
int cmp(const void *a, const void *b)
{
    return  (*(NODE2 *)b).rank - (*(NODE2 *)a).rank;
}
 
char employer[20], employee[20];
 
void UpdateRank(NODE *p){
    if(p != NULL){
        p->rank++;
        UpdateRank(p->fchild);
        UpdateRank(p->nextsibling);
    }
    return;
}
 
int Hire(NODE *p){
    if(p != NULL){
        if(!strcmp(p->name, employer)){
            if(p->fchild == NULL){
                p->fchild = (NODE*)malloc(sizeof(NODE));
                p->fchild->rank = 0;
                memset(p->fchild->name, '\0', 20);
                strcpy(p->fchild->name, employee);
                p->fchild->fchild = NULL;
                p->fchild->nextsibling = NULL;
                return 1;
            }
            else{
                p = p->fchild;
                while(p->nextsibling != NULL){
                    p = p->nextsibling;
                }
                p->nextsibling = (NODE*)malloc(sizeof(NODE));;
                p->nextsibling->rank = 0;
                memset(p->nextsibling->name, '\0', 20);
                strcpy(p->nextsibling->name, employee);
                p->nextsibling->fchild = NULL;
                p->nextsibling->nextsibling = NULL;
                return 1;
            }
        }
        else{
            if(Hire(p->nextsibling)) return 1;
            if(Hire(p->fchild)) return 1;
            return 0;
        }
    }
    else return 0;
    
}
 
NODE *boss, *fired;
 int aa = fun(5);
int Search(NODE *root){
    NODE *p = root->fchild;
    while(p != NULL){
        if(!strcmp(p->name, employee)){
            boss = root;
            fired = p;
            return 1;
        }
        else{
            p = p->nextsibling;
        }
    }
    p = root->fchild;
    while(p != NULL){
        if(Search(p)) return 1;
        p = p->nextsibling;
    }
    return 0;
}
 int am = fun(4);
void Pop(NODE *blank){
    if(blank->fchild->fchild == NULL){
        memset(blank->name, '\0', 20);
        strcpy(blank->name, blank->fchild->name);
        blank->fchild = blank->fchild->nextsibling;
        return ;
    }
    memset(blank->name, '\0', 20);
    strcpy(blank->name, blank->fchild->name);
    Pop(blank->fchild);
}
 
void Fire(NODE *p){
    if(fired->fchild == NULL){
        if(boss->fchild == fired){
            boss->fchild = boss->fchild->nextsibling;
            return;
        }
        else{
            NODE *p = boss->fchild;
            while(p->nextsibling != fired){
                p = p->nextsibling;
            }
            p->nextsibling = p->nextsibling->nextsibling;
        }
    }
    else{
        Pop(fired);
 
    }
    
}
 
int count = 0;
void Print(NODE *ptr,int dep)
{
	int ap = fun(4);
	if(ptr!=NULL)
	{
		for(int i=0;i<dep;i++)
			printf("+");
		printf("%s\n",ptr->name);
	}
	if(ptr->fchild!=NULL)
		Print(ptr->fchild,dep+1);
	if(ptr->nextsibling!=NULL)
		Print(ptr->nextsibling,dep);	
}
 
NODE *root;
 
int main(int argc, char const *argv[])
{
    char name[20], operate[20], print[20], fire[20];
    memset(fire, '\0', 20);
    memset(print, '\0', 20);
    strcpy(fire, "fire");
    strcpy(print, "print");
    int apa = fun(2);
    //建立CEO
    CEO = (NODE*)malloc(sizeof(NODE));
    scanf("%s",name);
    memset(CEO->name, '\0', 20);
    strcpy(CEO->name, name);
    CEO->rank = 0;
    CEO->fchild = NULL;
    CEO->nextsibling = NULL;
    root = (NODE*)malloc(sizeof(NODE));
    root->fchild = CEO;
    root->nextsibling = NULL;
 
    //建立公司
    memset(operate, '\0', 20);
    while(scanf("%s",operate) != EOF){
        int laa = fun(3);
        if(!strcmp(operate, print)){
            Print(root->fchild, 0);
            printf("------------------------------------------------------------\n");
            //Judge();
        }
        //fire操作
        else if(!strcmp(operate, fire)){
            memset(employer, '\0', 20);
            memset(employee, '\0', 20);
            scanf("%s", employee);
            Search(root);
            Fire(boss);
            //Judge();
            
        }
        //hire操作
        else{
            UpdateRank(CEO);
            memset(employer, '\0', 20);
            memset(employee, '\0', 20);
            strcpy(employer, operate);
            scanf("%s", operate);
            scanf("%s", employee);
            Hire(CEO);
        }
    }
 
 
    return 0;
}
