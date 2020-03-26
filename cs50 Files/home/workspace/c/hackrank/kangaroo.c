#include <assert.h>
#include <limits.h>
#include <math.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main(void)
{
        int x1,i=1,x2,v1,v2,k1[100000],k2[100000];
            scanf("%d %d %d %d",&x1,&v1,&x2,&v2);
                while((k1[i]<=1000)&&(k2[i]<=1000))
                        {
                                    k1[i]=x1+(v1*i);
                                            k2[i]=x2+(v2*i);
                                                   // if(k1[i]==k2[i])
                                                     //           {
                                                       //                         break;
                                                         //s                               }
                                                            printf("k1=%d k2=%d\n",k1[i],k2[i]);
                                                                   i++;
                                                                       }
                    if(k1[i]==k2[i])
                                printf("YES");
                        else
                                    printf("NO");

}
