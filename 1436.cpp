#include<cstdio>
#include<string.h>
#include<algorithm>
#include<iostream>
using namespace std;
int n;
int map[150][150],dp[20][20][20][20][20],sum[150][150];
void add(int i,int j)
{
//��������Ǽ���ǰ׺�����顣����(1,1)����(i,j)�ļ�ֵ
//�ú�����Ϊʲô������չ�����ʱ��߾���+�ұ߾���-�ص��Ĳ���+�����ļ�ֵ��
    sum[i][j]=sum[i-1][j]+sum[i][j-1]-sum[i-1][j-1]+map[i][j];
    return ;
}
int s(int x1,int y1,int x2,int y2)
{
//�����������������(x1,y1)����(x2,y2)�ļ�ֵ
//�����ݳ�ԭ��
    int now=sum[x2][y2]-sum[x2][y1-1]-sum[x1-1][y2]+sum[x1-1][y1-1];
    return now;
}
void start()
{
	cin>>n;
	
	for(int i=1;i<=8;i++)
	for(int j=1;j<=8;j++)
	{
	    cin>>map[i][j];
	    add(i,j);
	}
}
void solve()
{
	for(int i=1;i<=8;i++)
    for(int j=1;j<=8;j++)
    for(int x=i;x<=8;x++)
    for(int y=j;y<=8;y++)
    dp[0][i][j][x][y]+=s(i,j,x,y),
    dp[0][i][j][x][y]*=dp[0][i][j][x][y];
	//dp���̣�����һ����������һ�淽�̡�
    for(int k=1;k<n;k++)
    for(int i=1;i<=8;i++)
    for(int j=1;j<=8;j++)
    for(int x=i;x<=8;x++)
    for(int y=j;y<=8;y++)
    {
        int minn=0x3f3f3f3f;
        for(int a=j;a<y;a++)
        minn=min(minn,min(dp[k-1][i][j][x][a]+dp[0][i][a+1][x][y],dp[0][i][j][x][a]+dp[k-1][i][a+1][x][y]));
        for(int b=i;b<x;b++)
        minn=min(minn,min(dp[k-1][i][j][b][y]+dp[0][b+1][j][x][y],dp[0][i][j][b][y]+dp[k-1][b+1][j][x][y]));
        dp[k][i][j][x][y]=minn;
    }
	cout<<dp[n-1][1][1][8][8];
}
int main()
{
	start();
	solve();
	return 0;
}
