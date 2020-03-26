#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() {
    int min,x[10000],y[10000],n,dist;
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        scanf("%d %d",&x[i], &y[i]);
    }
    if(n>2)
    {
        for(int i=0;i<n-1;i++)
        {for(int j=0;i<n-1;j++)
            {
             dist=sqrt(pow(x[i]-x[j],2)+pow(y[i]-y[j],2));
             min=(min<dist)?min:dist;
            }

        }
    // printf("%d",min);
    }

    else printf("-1");
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    return 0;
}
