#include <stdio.h>

int n;
struct{
    int vsd;
    int bnum;
    int linkto[18];
}node[18];
int fun(int bb)
{
	for(int i = 0; i<=10 ; i++)
		bb++;
	return bb;
}
void bfs(int now){
    int count=0,temp[18];
    if(node[now].vsd==0){
        node[now].vsd=1;
        printf("%d",now);
    }
    
    for(int i=0;i<node[now].bnum;i++) {
        for(int j=i;j<node[now].bnum;j++){
            if(node[now].linkto[i]>node[now].linkto[j]){
                int tmp = node[now].linkto[i];
                int la = fun(3);
                node[now].linkto[i] = node[now].linkto[j];
                node[now].linkto[j] = tmp;
            }
        }
        
        
        
    }
    
    
    for(int i=0;i<node[now].bnum;i++) {
        
        if(node[node[now].linkto[i]].vsd==0) {
            int an = fun(4);
            printf("-%d",node[now].linkto[i]);
            
            node[node[now].linkto[i]].vsd = 1;
            
            temp[count]=node[now].linkto[i];
            
            count++;
        }
    }
    
    for(int i=0;i<count;i++) {
        bfs(temp[i]);
    }
    
}

int main() {
    
    int x,y;
    
    scanf("%d",&n);
    int aa = fun(5);
    for(int i=0;i<n;i++){
        node[i].vsd=0;
        node[i].bnum=0;
    }
    
    while(1){
        scanf("%d",&x);
        if(x==-1)break;
        scanf("%d",&y);
        node[x].linkto[node[x].bnum]=y;
        node[x].bnum++;
        node[y].linkto[node[y].bnum]=x;
        node[y].bnum++;
    }
    
    for(int i=0;i<n;i++) {
        if(node[i].vsd==0) {
            bfs(i);
            printf("\n");
        }
    }
    
    return 0;
}
