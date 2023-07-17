#include<stdio.h>
void read(int m,int n,int a,int b,int matrix[m][n],int matrix2[a][b]);
void multiplication(int m,int n,int a,int b,int matrix[m][n],int matrix2[a][b]);
void main()
{
    int i,j,m,n,a,b;
    int matrix[m][n],matrix2[a][b];
    printf("Enter the number of rows and columns in first matrix\n");
    scanf("%d%d",&m,&n);
    printf("Enter the number of rows and columns in second matrix\n");
    scanf("%d%d",&a,&b);
    if(n==a)
    {
        read(m,n,a,b,matrix,matrix2);
        multiplication(m,n,a,b,matrix,matrix2);
    }
    else
    {
        printf("The given matrices cant be multiplied\n");
    }
}
void read(int m,int n,int a,int b,int matrix[m][n],int matrix2[a][b])
{
    printf("Enter the elements of first matrix\n");
    for(int i=0;i<m;i++)
    {
        for(int j=0;j<n;j++)
        {
            scanf("%d",&matrix[i][j]);
        }
    }
     printf("Enter the elements of first matrix\n");
     for(int i=0;i<a;i++)
    {
        for(int j=0;j<b;j++)
        {
            scanf("%d",&matrix2[i][j]);
        }
    }
     printf(" the elements of second matrix\n");
    for(int i=0;i<m;i++)
    {
        for(int j=0;j<n;j++)
        {
            printf("%d ",matrix[i][j]);
        }
        printf("\n");
    }
     printf("Enter the elements of second matrix\n");
     for(int i=0;i<a;i++)
    {
        for(int j=0;j<b;j++)
        {
            printf("%d ",matrix2[i][j]);
        }
        printf("\n");
    }
}
void multiplication(int m,int n,int a,int b,int matrix[m][n],int matrix2[a][b])
{
    int matrix3[m][b];
    for(int i=0;i<m;i++)
    {
        for(int j=0;j<b;j++)
        {
            matrix3[i][j]=matrix[i][j]*matrix2[j][i];
        }
    }
    printf("The multiplied matrix is \n");
     for(int i=0;i<m;i++)
    {
        for(int j=0;j<b;j++)
        {
            printf("%d ",matrix3[i][j]);
        }
        printf("\n");}
}
