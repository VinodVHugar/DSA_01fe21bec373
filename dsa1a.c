#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct news_list
{
    char news[1000];
};
struct news_list nl[20];

int longest_line(int n)
{
    int m=0,index,i,count,j;
    for(i=0;i<n;i++)
    {
        count=0;
        j=0;
        while(nl[i].news[j]!='\0')
        {
            count++;
            j++;
        }
        if(count>m)
        {
            m=count;
            index=i;
        }
    }
    return index;
}

int main()
{
    int i,n,M;
    char c;
    printf("Enter number of news\n");
    scanf("%d",&n);
    printf("Enter news line by line\n");
    c=getchar();
    for(i=0;i<n;i++)
    {
        gets(nl[i].news);
    }
    M=longest_line(n);

    printf("The Longest Line is :\n%s\n\n",nl[M].news);

    printf("Output\n");
    for(i=0;i<n;i++)
    {
       printf ("%s\n",nl[i].news);   
 }
return 0;
}
