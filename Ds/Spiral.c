void spiral(int m, int n) 
{ 
    int a[m][n];
    int rows=m,columns=n;
    int i, k = 0, l = 0,c=1; 
    while (k < m && l < n) { 
        for (i = l; i < n; ++i) { 
            a[k][i]=c;
            c++; 
        } 
        k++; 
        for (i = k; i < m; ++i) { 
            a[i][n - 1]=c;
            c++; 
        } 
        n--; 
        if (k < m) { 
            for (i = n - 1; i >= l; --i) { 
                a[m - 1][i]=c;
                c++; 
            } 
            m--; 
        } 
        if (l < n) { 
            for (i = m - 1; i >= k; --i) { 
                a[i][l]=c; 
                c++ ;
            } 
            l++; 
        } 
    } 
    for(i=0;i<rows;i++)
        {for(int j=0;j<columns;j++)
            printf("%02d ",a[i][j]);
        printf("\n");}
    } 
int main() 
{ 
    int m,n;
    scanf("%d",&n);
	spiral(n, n); 
	return 0; 
}
