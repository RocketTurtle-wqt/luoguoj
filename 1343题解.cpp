#include<cstdio>
#include<cstring>
#include<cmath>
#include<queue>
#include<algorithm>
using namespace std;
int map[310][310],n,m,x,flow[310],pre[310];
queue<int> q;
int bfs(int s,int t)
{
        while(!q.empty()) q.pop();
            for(int i=1;i<=n;i++) pre[i]=-1;//ǰ��Ϊ�� 
            pre[s]=0;//������� 
            flow[s]=0x7f7f7f;//�������Ϊ����
            q.push(s);
            while(!q.empty())
            {
                        int x=q.front();
                        q.pop();
                            if(x==t) break;//�ҵ�����·
                        for(int i=1;i<=n;i++)
                        {
                                    if(i!=s&&map[x][i]>0&&pre[i]==-1)
                                    {
                                                pre[i]=x;//��¼ǰ�� 
                                                if(flow[x]<map[x][i]) flow[i]=flow[x];
                                                else flow[i]=map[x][i];//������ 
                                                q.push(i);
                                    }
                        } 
            }
            if(pre[t]==-1) return -1;
            else return flow[t];
}
int max_flow(int s,int t)
{
            int ins_flow=0;
            int tot_flow=0;
            while((ins_flow=bfs(s,t))!=-1)
            {
                        int k=t;//���յ�������� 
                        while(k!=s)
                        {
                                    int last=pre[k];
                                    map[last][k]-=ins_flow;//������� 
                                    map[k][last]+=ins_flow;//�ķ���� 
                                    k=last;
                        }
                        tot_flow+=ins_flow;
            }
            return tot_flow;
}
int main()
{
            scanf("%d%d%d",&n,&m,&x);
            for(int i=1;i<=m;i++)
            {
                        int x,y,z;
                        scanf("%d%d%d",&x,&y,&z);
                        map[x][y]+=z;
                }
            int temp=max_flow(1,n);
            if(temp==0){
                printf("Orz Ni Jinan Saint Cow!\n");
                return 0;
            }
            if(x%temp==0) printf("%d %d\n",temp,x/temp);
            else printf("%d %d\n",temp,x/temp+1);
            return 0;
}
