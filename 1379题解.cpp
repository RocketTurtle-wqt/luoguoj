#include<bits/stdc++.h>
#define ll long long int
using namespace std;
int n,g=123804765;
short a[4][4],fx,fy,nx,ny;
int dx[4]={1,-1,0,0};
int dy[4]={0,0,1,-1}; //�������ĸ������ƶ�
queue<int> q;
map<int,int> v;
map<int,int> ans;
inline void change1(int x){
	int now=x;
	for(int i=3;i>=1;i--)
	for(int j=3;j>=1;j--){
		a[i][j]=now%10;
		now/=10;
	}
}
inline int change2(){
	int sum=0,m=1;
	for(int i=3;i>=1;i--)
	for(int j=3;j>=1;j--){
		sum+=a[i][j]*m;
		m*=10;
	}
	return sum;
}
void solve()
{
    if(n==g)         //����
    {
        printf("0");
        exit(0);
    }               
    q.push(n);      //��ʼ״̬����ֹ״̬ͬʱ���
    q.push(g);
    ans[n]=0;
    ans[g]=1;       
    v[g]=2;         //�����������ǳɲ�ͬ������
    v[n]=1;
    while(!q.empty())
    {
        ll now,cur=q.front();
        q.pop();
        change1(cur);
        for(int i=1;i<=3;i++)
        for(int j=1;j<=3;j++)
        if(a[i][j]==0) fx=i,fy=j;
        for(int i=0;i<4;i++)
        {
            nx=fx+dx[i];
            ny=fy+dy[i];
            if(nx<1 || nx>3 || ny<1 || ny>3) continue;
            swap(a[fx][fy],a[nx][ny]);
            now=0;
            now=change2();
            if(v[now]==v[cur]) 
            {
                swap(a[fx][fy],a[nx][ny]); //һ��Ҫ�Ȼ�����������
                continue;
            }
            if(v[now]+v[cur]==3)        //˵����������ĵ��ѱ���һ������ʹ�
            {
                printf("%d",ans[cur]+ans[now]);//���������ͼ�Ϊ�ܲ���
                exit(0);
            }
            ans[now]=ans[cur]+1;
            v[now]=v[cur];              //����һ״̬�ķ��򱣳�һ��
            q.push(now);
            swap(a[fx][fy],a[nx][ny]); //��Ҫ���ǽ�������
        }   
    }
}
int main()
{
    scanf("%d",&n);
    solve();
}
