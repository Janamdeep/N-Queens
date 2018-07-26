#include<stdio.h>
//#include<math.h>

int a[20],count=0;

void print(int n)
{
 int i,j;
 printf("\n\nSolution %d:\n\n",++count);

 for(i=1;i<=n;++i)
 {

  for(j=1;j<=n;++j)
  {
   if(a[i]==j)
    printf("Q");
   else
    printf(".");
  }
  printf("\n");
 }
}


int valid(int row,int column)
{
 int i;
 for(i=1;i<row;++i)
 {

  if(a[i]==column)
   return 0;
  else{
    if((a[i]-column)==-(i-row) || (a[i]-column)==(i-row))
    return 0;
  }
 }
 return 1;
}


void queen(int row,int n)
{
 int column;
 for(column=1;column<=n;column++)
 {
  if(valid(row,column))
  {
   a[row]=column;
   if(row==n)
    print(n);
   else
    queen(row+1,n);
  }
 }
}

 main()
{
 int n;
a:printf("\nEnter number of Queens:  ");
 scanf("%d",&n);
 if(n>3 || n==1)
 queen(1,n);
 else if(n>1 && n<4)
 {printf("NO SOLUTION");}
 else
  {printf("Enter +ve no. of queens.");goto a;}

}


