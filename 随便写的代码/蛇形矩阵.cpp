#include<stdio.h> 
int main()
{
    int n ; // ���ξ���߳�
    int i=0 ; // ���ƶ�
    int j=0 ; // ���ƶ�
    int k ; // ��������
    int h ; // ÿתnȦ�����εı߳�
    int start ; //��ֵ
    int a[100][100];
    
    scanf ("%d",&n);
    
    start = 0 ;
    h = n ;
    while ( h >= 1 )
    {
        for ( k = 0 ; k < h ; k ++ ) //���ξ����Ⱥ����ߣ�
        {
            start ++;
            a[i][j] = start ;
            j++;
        }
        j--;
        i++;
        
        for ( k=0 ; k < h-1 ; k++ ) //��������
        {
            start ++ ;
            a[i][j] = start ;
            i++;
        }
        i--;
        j--;
        
        for ( k = 0 ; k < h-1 ; k++ ) //��������
        {
            start ++ ;
            a[i][j] = start ;
            j--;
        }
        j++;
        i--;
        
        for ( k = 0 ; k < h-2 ; k++ ) //��������
        {
            start ++ ;
            a[i][j] = start ;
            i--;
        }
        i++;
        j++;
        h -= 2 ;  //ÿ��һȦ�����α߳�����2
    }
    
    for ( i = 0 ; i < n ; i++ )
    {
        for ( j = 0 ; j < n ; j++ )
            printf ("%3d",a[i][j]);  //�������
        printf ("\n");
    }
    
    return 0;
}
