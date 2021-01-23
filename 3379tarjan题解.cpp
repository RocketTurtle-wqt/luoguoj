#include<iostream>
#include<cstdio>
#include<cstdlib>
#define maxium 1000010
#define de system("pause");
using namespace std;
int fir[500050],to[1000100],ne[1001000];//�������� 
int firp[500500],as[1000050],nep[1001000],ans[1000100],head1[5000500],head2[500050];//�����洢ѯ�ʹ�ϵ�� 
int n,m,s,e,q,a,b,cnt,an;
bool vis[500050];  //��ǰ�ڵ��Ƿ��߹��� 
int fa[500050];//���ڲ��鼯��ѯ�� 
int f[500010];//���ڼ�¼��ǰ�ڵ�ĸ��׽ڵ��Ա�����ýڵ���ӽڵ㣻 
struct Edge
{
	int to;
	int prev;
}edge[maxium];
struct Ask
{
	int to;
	int start;
	int prev;
}ask[maxium];
void addedge(int x,int y)
{
	edge[++cnt].to=y;
	edge[cnt].prev=head1[x];
	head1[x]=cnt;
}
void addask(int x,int y)
{
	ask[++an].to=y;
	ask[an].start=x;
	ask[an].prev=head2[x];
	head2[x]=an;
}
//void add(int u,int v)  //�ڽӱ�洢�� 
//{
//    e++;
//    to[e]=v;
//    ne[e]=fir[u];
//    fir[u]=e;
//}
//void app(int x,int y)  //�ڽӱ�洢ѯ�ʹ�ϵ 
//{
//    q++;
//    as[q]=y;
//    nep[q]=firp[x];
//    firp[x]=q;
//}
int find(int x)  //���鼯 
{
    if(x!=fa[x])
    {
        fa[x]=find(fa[x]);
    }
    return fa[x];
}
void un(int x,int y)   //���鼯 
{
    int xx=find(x);
    int yy=find(y);
    if(xx!=yy)
    {
        fa[xx]=yy;
    }
}
void tarjan(int x)   //tarjan���ģ����ʾ���dfs������� 
{
//	printf("%d ",x);
    for(int i=head1[x];i;i=edge[i].prev)
    {
        int t=edge[i].to;
        if(t==f[x])     //�����ӽڵ� 
        {
            continue;
        }        
        f[t]=x;
        tarjan(t);     //�������±����� 
        un(t,x);      //��t�ϲ���x  ���ǳ���Ҫ�� 
        vis[t]=1;      //��t��x���ӽڵ㣩���Ϊ���߹� 
    }
    for(int i=head2[x];i;i=ask[i].prev)
    {
        int y=ask[i].to;    //��ѯ��x�йص�lcaѯ�� 
        if(vis[y])    //����������� 
        {
            ans[i]=find(y);  //��ôx��y������������Ⱦ���find��y��; 
        }
    }
}
inline int read()
{
    int ee=0,ff=1;
    char ss=getchar();
    while((ss<'0'||ss>'9')&&ss!='-')ss=getchar();
    while((ss>='0'&&ss<='9')||ss=='-')
    {
        if(ss=='-')ff=-1;
        else ee=ee*10+ss-'0';
        ss=getchar();
    }
    return ee*ff;
}
int main()
{
    n=read();m=read();s=read();//��ĿҪ������ 
    for(int i=1;i<=n-1;i++)
    {
        a=read();b=read();
        addedge(a,b);addedge(b,a);// ��ĿҪ������
    }
    for(int i=1;i<=m;i++)
    {
        a=read();b=read();  //��ĿҪ�����룬�����ڽӱ�洢ѯ�ʹ�ϵ��
        addask(a,b);addask(b,a);  //x,y �Ĺ��������� y,x �Ĺ���������һ���ģ�Ҫ��˫�� 
    }
    for(int i=1;i<=n;i++)   //���鼯�����ʼ�� 
    {
        fa[i]=i;
        f[i]=i;
    }
    tarjan(s);     //��sΪ���ڵ㿪ʼ���� 
    for(int i=1;i<=m;i++)
    {
        printf("%d\n",max(ans[2*i],ans[2*i-1]));
    }
    return 0;
}
