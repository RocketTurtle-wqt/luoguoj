#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
int n;//n���ܹ��еĵ���
int map[9][9];//��ͼ����ֵ
int sum[9][9];//ǰ׺������
int dp[9][9][9][9][15];//dp��������
inline void add(int i,int j)
{
//��������Ǽ���ǰ׺�����顣����(1,1)����(i,j)�ļ�ֵ
//�ú�����Ϊʲô������չ�����ʱ��߾���+�ұ߾���-�ص��Ĳ���+�����ļ�ֵ��
    sum[i][j]=sum[i-1][j]+sum[i][j-1]-sum[i-1][j-1]+map[i][j];
    return ;
}
inline int s(int x1,int y1,int x2,int y2)
{
//�����������������(x1,y1)����(x2,y2)�ļ�ֵ
//�����ݳ�ԭ��
    int now=sum[x2][y2]-sum[x2][y1-1]-sum[x1-1][y2]+sum[x1-1][y1-1];
    return now;
}
int main()
{
    scanf("%d",&n);
    for(int i=1;i<=8;i++)
      for(int j=1;j<=8;j++)
      scanf("%d",&map[i][j]),
      add(i,j);//���룬����ǰ׺��

//debug
//  for(int i=1;i<=8;i++,puts(""))
//    for(int j=1;j<=8;j++)
//    printf("%-5d ",sum[i][j]); 
//������0��ʱ�����μ�ֵ��ƽ��
    for(int i=1;i<=8;i++)
     for(int j=1;j<=8;j++)
       for(int x=i;x<=8;x++)
         for(int y=j;y<=8;y++)
           dp[i][j][x][y][0]+=s(i,j,x,y),
           dp[i][j][x][y][0]*=dp[i][j][x][y][0];
//dp���̣�����һ����������һ�淽�̡�
    for(int k=1;k<n;k++)
      for(int i=1;i<=8;i++)
        for(int j=1;j<=8;j++)
          for(int x=i;x<=8;x++)
            for(int y=j;y<=8;y++)
            {
                int minn=0x3f3f3f3f;
                for(int a=j;a<y;a++)
                  minn=min(minn,min(dp[i][j][x][a][k-1]+dp[i][a+1][x][y][0],dp[i][j][x][a][0]+dp[i][a+1][x][y][k-1]));
                for(int b=i;b<x;b++)
                  minn=min(minn,min(dp[i][j][b][y][k-1]+dp[b+1][j][x][y][0],dp[i][j][b][y][0]+dp[b+1][j][x][y][k-1]));
                dp[i][j][x][y][k]=minn;
            }
    printf("%d",dp[1][1][8][8][n-1]); 
 //���������ݰݡ�
    return 0;
}



//	for(int i=1;i<=8;i++)
//	for(int j=1;j<=8;j++)
//	for(int u=i;u<=8;u++)
//	for(int v=j;v<=8;v++)
//	{
//        for(int k=i;k<=u;k++)
//        for(int h=j;h<=v;h++)
//        dp[1][i][j][u][v]+=map[k][h];
//        dp[1][i][j][u][v]*=dp[1][i][j][u][v];
//    }
//      for(int i=1;i<=8;i++)
//      for(int j=1;j<=8;j++)
//      dp[1][i][j][i][j]=map[i][j]*map[i][j];
//    printf("%d\n",dp[1][2][1][1][8]);
}


	for(int k=1;k<=n;k++)
	for(int i=1;i<=8;i++)
	for(int j=1;j<=8;j++)
	for(int x=i;x<=8;x++)
	for(int y=j;y<=8;y++)
	for(int h=1;h<k;h++)
	{
		if(k==1) continue;
//		if(k==3&&i==1&&j==1&&x==8&&y==8) printf("true");
		for(int u=i;u<x;u++)
		{
//			if(k==3&&i==1&&j==1&&x==8&&y==8)
//			{
//			    printf("h=%d i=%d j=%d u=%d y=%d    k-h=%d u+1=%d j=%d x=%d y=%d\n ",h,i,j,u,y,k-h,u+1,j,x,y);
//                printf("dp[%d][%d][%d][%d][%d]=%d dp[%d][%d][%d][%d][%d]=%d\n",h,i,j,u,y,dp[h][i][j][u][y],k-h,u+1,j,x,y,dp[k-h][u+1][j][x][y]);	
//			}
			if(dp[k][i][j][x][y]==0) dp[k][i][j][x][y]=dp[h][i][j][u][y]+dp[k-h][u+1][j][x][y];
		    else dp[k][i][j][x][y]=min(dp[h][i][j][u][y]+dp[k-h][u+1][j][x][y],dp[k][i][j][x][y]);
		}
		for(int v=j;v<y;v++)
		{
//			if(k==3&&i==1&&j==1&&x==8&&y==8)
//			{
//			    printf("h=%d i=%d j=%d x=%d v=%d     k-h=%d i=%d v+1=%d x=%d y=%d\n",h,i,j,x,v,k-h,i,v+1,x,y);
//			    printf("dp[%d][%d][%d][%d][%d]=%d dp[%d][%d][%d][%d][%d]=%d\n",h,i,j,x,v,dp[h][i][j][x][v],k-h,i,v+1,x,y,dp[k-h][i][v+1][x][y]);
//			}
            if(dp[k][i][j][x][y]==0) dp[k][i][j][x][y]=dp[h][i][j][x][v]+dp[k-h][i][v+1][x][y];
		    else dp[k][i][j][x][y]=min(dp[h][i][j][x][v]+dp[k-h][i][v+1][x][y],dp[k][i][j][x][y]);
		}
	}
//	cout<<dp[2][1][1][4][4];
//    cout<<dp[3][1][1][7][7];
