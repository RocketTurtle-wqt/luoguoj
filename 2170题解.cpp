#include<cstdio>
#include<cmath>
#include<algorithm>
using namespace std;
int f[100000],p[100000],i,j,x,y,k,m,n,s[100000],dp[100000],tot;
int find(int u)
{
    if(f[u]==u) return u;
    else return f[u]=find(f[u]);
}
int main()
{
    scanf("%d%d%d",&n,&m,&k);
    for(i=1;i<=n;i++)
        f[i]=i,p[i]=1; //pԤ����Ϊ1,��Ϊһ��ʼÿ������ֻ��һ����
    for(i=1;i<=k;i++)
    {
        scanf("%d%d",&x,&y);
        int u=find(x);int v=find(y); //���鼯
        if(u!=v) f[u]=v,p[v]+=p[u];  //p��¼����Ԫ�ظ���
    }
    for(i=1;i<=n;i++) //�ҵ�ÿ�����ϵĸ��ڵ㣬�Ѽ��ϵ�Ԫ�ظ���������
    if(f[i]==i)
    {
        tot++;
        s[tot]=p[i];
    }
    for(i=1;i<=tot;i++)
    printf("%d ",s[i]);
    for(i=1;i<=tot;i++) //��������
        for(j=2*m;j>=s[i];j--)
            dp[j]=max(dp[j],dp[j-s[i]]+s[i]);
    int ans=999999999,minn=999999999;
    for(i=1;i<=2*m;i++) //�ҵ���ӽ�m��
    {
        if(minn>abs(dp[i]-m)) minn=abs(dp[i]-m),ans=dp[i];
    }
//    if(ans==999999999) printf("0");
//    else    printf("%d",ans);
    return 0;
}
