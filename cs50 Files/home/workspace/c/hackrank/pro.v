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
                    char string1[90],rows,column,arr[100][100],i;
                        for(i=0;i<=85;i++)
                                    {
                                            string1[i]=' ';
                                                }
                                                        for(i=0;((string1[i]!=' ')&&(string1[i+1]!=' '));i++)
                                                                    {
                                                                            scanf("%c",&string1[i]);
                                                                                    if(string1[i]=' ')
                                                                                                    i=i-1;
                                                                                                        }
                                                                                                                
                                                                                                                for(i=0;i<=85;i++)
                                                                                                                            {
                                                                                                                                    printf("%c",string1[i]);
                                                                                                                                        }
                                                                                                                                                
                                                                                                                                                
                                                                                                                                            }

