#include<stdio.h> 
int main()
{
    int n ; // 方形矩阵边长
    int i=0 ; // 行移动
    int j=0 ; // 列移动
    int k ; // 辅助变量
    int h ; // 每转n圈正方形的边长
    int start ; //赋值
    int a[100][100];
    
    scanf ("%d",&n);
    
    start = 0 ;
    h = n ;
    while ( h >= 1 )
    {
        for ( k = 0 ; k < h ; k ++ ) //蛇形矩阵先横向走，
        {
            start ++;
            a[i][j] = start ;
            j++;
        }
        j--;
        i++;
        
        for ( k=0 ; k < h-1 ; k++ ) //再向下走
        {
            start ++ ;
            a[i][j] = start ;
            i++;
        }
        i--;
        j--;
        
        for ( k = 0 ; k < h-1 ; k++ ) //再向左走
        {
            start ++ ;
            a[i][j] = start ;
            j--;
        }
        j++;
        i--;
        
        for ( k = 0 ; k < h-2 ; k++ ) //再向上走
        {
            start ++ ;
            a[i][j] = start ;
            i--;
        }
        i++;
        j++;
        h -= 2 ;  //每走一圈正方形边长减少2
    }
    
    for ( i = 0 ; i < n ; i++ )
    {
        for ( j = 0 ; j < n ; j++ )
            printf ("%3d",a[i][j]);  //输出数组
        printf ("\n");
    }
    
    return 0;
}
