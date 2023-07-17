#include <stdio.h>
#define MAXLINE 1000


void getline(char line[],char key[],FILE *fp);
int check(char bsentence[],char key[]);
int main()
{
    FILE *fp;
    char line[MAXLINE],key[100],replace1;
    char longest[MAXLINE];
    int len;
    int max = 0;
    fp = fopen("input.txt", "r");
    if (fp == NULL) {
        printf("Error: Could not open file.\n");
        return 1;
    }
    printf("Enter the key you want to search for\n");
    scanf("%s",key);
    getline(line,key,fp);
    fclose(fp);
    return 0;
}

void getline(char s[], char key[], FILE *fp)
{
    char c,k,replace1[100];
    int i,j=0,m=0,a=0,b=0,status=0,p=0,q=0;
    printf("Enter the key you want to replace for\n");
    scanf("%s",replace1);
    puts(replace1);
    while(key[p]!='\0')
    {
        p++;
    }
    while(replace1[q]!='\0')
    {
        q++;
    }
    if(p==q)
    {
        for (i = 0; (c=fgetc(fp))!=EOF && c!='\n'; i++)
    {
       s[i]=c;
       if(c=='\n' || c==EOF)
       {
           s[i]='\0';
           m=check(s,key);
           if(m==1)
           {
               printf("%s ",s);
               printf("\n");
               while(s[a]!='\0')
               {
                   if(s[a]==key[0])
                   {
                       while(replace1[b]!='\0')
                       {
                           s[a+b]=replace1[b];
                           b++;
                       }
                   }
                   a++;
               }
           }
           else
           {
               printf("ads\n");
           }
       }

    }
    }
    else
    {
        printf("The given keyword and the word that we want to replace arent of same length\n");
    }

}
int check(char bsentence[],char key[])
{
    int a[10],i=0,j=1,tp=0;
    while(bsentence[i]!='\0')
    {
        tp=0;
        if(bsentence[i]==key[0])
        {
            while(key[j]!='\0')
            {
                if(bsentence[i+j]!=key[j])
                   {
                       break;
                   }
                   j++;
            }
            if(key[j]=='\0')
            {
                tp=1;
                break;
            }
            else
            {
                j=0;
            }
        }
        i++;
    }
    return tp;
}

