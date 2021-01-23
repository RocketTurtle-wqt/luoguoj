#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <algorithm>
#include <queue>
#define int long long
using namespace std;
const int orz=1000100;
struct EDGE{
    int ver,dis,nxt,pre,num;
}edge[orz];
int head[orz],n,m,cnt;
int ans[orz],dfn[orz],low[orz],dfs_cnt,size[orz];
inline int read(){
    int sym=0,res=0;char ch=0;
    while (ch<'0'||ch>'9')sym|=(ch=='-'),ch=getchar();
    while (ch>='0'&&ch<='9')res=(res<<3)+(res<<1)+(ch^48),ch=getchar();
    return sym?-res:res;
}
void file(){
    freopen("read.in","r",stdin);
    freopen("write.out","w",stdout);
}
void add(int u,int v){
    edge[++cnt].ver=v;
    edge[cnt].nxt=head[u];
    head[u]=cnt;
}
void tarjan(int u){
    dfn[u]=low[u]=++dfs_cnt;size[u]=1;
    int sum=0,child=0;bool cut=false;
    for (int i=head[u];i;i=edge[i].nxt){
        int v=edge[i].ver;
        if (!dfn[v]){
            tarjan(v);size[u]+=size[v];
            low[u]=min(low[u],low[v]);
            if (low[v]>=dfn[u]){
                ans[u]+=size[v]*(n-size[v]);//�ۼƷֳ�ȥ�Ķ��ӵĹ���
                sum+=size[v];child++;
                if (u!=1||child>=2)cut=true;
            }
        }else{
            low[u]=min(low[u],dfn[v]);
        }
    }
    if (!cut)ans[u]=2*(n-1);
    else ans[u]+=(n-sum-1)*(sum+1)+(n-1);
    //�����һ����ͨ�飬�������ǵĹ��ף�Ȼ���Լ���һ����ͨ�飬�����Լ��Ĺ���;
    //ÿ����ͨ��Ĺ��׶��Ǹÿ�size��n-size
}
signed main(){
    n=read();m=read();
    for (int i=1;i<=m;i++){
        int x=read(),y=read();
        add(x,y);add(y,x);
    }
    tarjan(1);
    for (int i=1;i<=n;i++){
        printf("%lld\n",ans[i]);
    }
    return 0;
}
