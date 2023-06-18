#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char * longestPalindrome(char * s)
{
    int l = strlen(s);
    int pad[l][l];
    
    /*
    pad = (int**) malloc(l*sizeof(int *));
    for (int i = 0; i < l; i++)
        pad[i] = (int *)malloc(l * sizeof(int));
    */

    int h = 0,t = 0;

    for (int i=0; i<l; i++)
    {
        pad[i][i] = 1;
    }
    for (int i=0; i<l-1; i++)
        if (s[i]==s[i+1])
        {
            pad[i][i+1]=1;
            h = i;
            t = i+1;
        }
    
    for (int i = 3;i <= l; i++)
        for(int j=0; j<= l-i; j++)
            if (s[j]==s[j+i-1] && pad[j+1][i+j-2] == 1)
            {
                pad[j][j+i-1] == 1;
                printf("%d %d\n",j,j+i-1);
                h = j;
                t = i;
            }
    char *res;
    res = (char*) malloc(h - t + 2);
    for (int i = 0;i < h+t; i++)
        res[i] = s[i+h];
    return res;
}

int main()
{
	char a[1000];
	scanf("%s",a);
	char *pad;
	pad = longestPalindrome(a);
	printf("%s",pad);
	return 0;
}
