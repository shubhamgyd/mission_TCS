#include <stdio.h>

void find_paths(int m,int n,int k)
{
   int dp[10][10][10][2]={{{{0}}}},i,j,turns,sum=0;
   /* dp[row][column][turns][direction] direction =0 paths in horizontal direction direction =1 paths in vertical direction*/
   for(i=1;i<n;i++)
   {
       dp[0][i][0][0]=1;//no of ways of coming horizontally to ith column from 0 row

   }
   for(i=1;i<m;i++)
   {
       dp[i][0][0][1]=1;//no of ways to come vertically to ith row for 0 column
   }
   for(i=1;i<m;i++)
   {
        for(j=1;j<n;j++)
            {
                 //paths with no change in direction
                 for(turns=0;turns<=k;turns++)
                 {
                     dp[i][j][turns][1]+=dp[i-1][j][turns][1];// i j will gave same number of vertical paths with same number of turns
                     dp[i][j][turns][0]+=dp[i][j-1][turns][0];//i j will have same number of horizontal paths with same number of turns
                     dp[i][j][turns+1][1]+=dp[i-1][j][turns][0];//horizontal to verical path will add a turn
                     dp[i][j][turns+1][0]+=dp[i][j-1][turns][1];//vertical to horizontal will add a turn

                }

            }
   }

for(i=0;i<=k;i++)
{
    sum+=dp[m-1][n-1][i][0];
    sum+=dp[m-1][n-1][i][1];
}
   printf("%d",sum);

}


int main()
{   int m,n,k;
    printf("enter size of matrix m and n and k\n");
    scanf("%d %d %d",&m,&n,&k);
    find_paths(m,n,k);
    return 0;
}
