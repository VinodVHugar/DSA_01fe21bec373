
#include<stdio.h>
main()
{
  int i,n,j,k,arr[100],arr1[100],c=0;
  printf("Enter the array size\n");
  scanf("%d",&n);
  printf("read int arrays\n");
  for(i=0;i<n;i++)
  {
      scanf("%d",&arr[i]);
  }
  for(i=0;i<n-1;i++)
  {
      for(j=i+1;j<n;j++)
      {
          if(arr[i]==arr[j])
          {
              arr1[i]=arr[i];
              c++;
          }
      }
  }
  printf("Duplicate elements are\n");
  for(i=0;i<c;i++)
  {
      printf("%d\t",arr1[i]);
  }
}
