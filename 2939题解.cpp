#include<iostream>
#include<cstdio>
#include<cstring>
#include<queue>
#define N 220010//��Ϊk�ķ�Χ����20�����ǿ��ܻὨ��20+��ͼ�㣬����Ҫ���Ĵ�һ��
using namespace std;
struct Edge
{
    int to,nexty,w;
}edge[4200010];//��ʽǰ���Ǵ��
/*struct node
{
    int code,dis;
    bool operator < (const node& rhs) const {return dis>rhs.dis;}
};*/  //���Ǳ��X�mһ��ʼ����ʱ��1ά�Ķ���dij��������֪��Ϊʲô������������...�������ոĳ��˶�ά
bool vis[N];
int n,m,u,v,k,t,tmp;//n��������m����·��k�λ��ᣬu��һ��·����㣬v���յ㣬t�����ĵ�ʱ�䣬tmp���ں�������
int dis[N],head[N],cnt;//���ʱ����
//�����ǿ���İ���
template<typename int_t>//��˵�����Զ��ж����������
void readx(int_t& x)
{
    x=0; int_t k=1; char ch=0;
    while(ch<'0'||ch>'9') {ch=getchar();if(ch=='-') k=-1;}
    while(ch>='0'&&ch<='9') {x=x*10+ch-'0';ch=getchar();}
    x*=k;
}
//���
void add(int x,int y,int w)
{
    cnt++;
    edge[cnt].to=y;
    edge[cnt].nexty=head[x];
    edge[cnt].w=w;
    head[x]=cnt;
}
priority_queue< pair<int,int> > q;
//����� ���ȶ��� pair��һάΪdist�෴�������С���ѣ� �ڶ�άΪ�ڵ��� 
void dij()//dijkstral �����· �����ӣ�
{
    memset(dis,0x3f,sizeof(dis));
    dis[1]=0;//dis��ʼ�� ���Ϊ0������Ϊ������
    memset(vis,0,sizeof(vis));//�ڵ������
    q.push(make_pair(0,1));
    while(q.size()){
        int x=q.top().second;
        q.pop();//ȡ�Ѷ�
        if(vis[x]) continue;
        vis[x]=1;//��ǽڵ�
        for(int i=head[x];i;i=edge[i].nexty)
        {//ɨ�����г���
            int y=edge[i].to,z=edge[i].w;
            if(dis[y]>dis[x]+z)
            {
                dis[y]=dis[x]+z;
                q.push(make_pair(-dis[y],y));
            }
        } 
    } 
}
int main()
{
    readx(n);readx(m);readx(k);//����
    for(int i=1;i<=m;i++)
    {
        readx(u);readx(v);readx(t);//����
        add(u,v,t);add(v,u,t);//�ȴ���ԭʼͼ
        for(int j=1;j<=k;j++)//����k�ĸ�������ԭʼͼ
        {
            add(j*n+u,j*n+v,t);
            add(j*n+v,j*n+u,t);
            add((j-1)*n+u,j*n+v,0);//ÿ���ıߵ�ȨֵΪ0
            add((j-1)*n+v,j*n+u,0);
        }
    }
    tmp=n;//��¼n
    dij();//���·
    for(int i=1;i<=n;i++)
    printf("%d ",dis[i]);
    int ans=dis[tmp];//��¼ԭͼ���ϵ���Сֵ
    for(int i=1;i<=k;i++)
    {
        ans=min(ans,dis[i*n+tmp]);//��ÿһ���ϵ���Сֵ���бȽϣ������´�
    }
    printf("%d",ans);//���
    return 0;
}
