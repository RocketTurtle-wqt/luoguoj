#include <cstdio>
#include <algorithm>
using namespace std;
struct data {int x,y,z;};//�ṹ���������ı任
data f[100005];
int n,m,a[20005],b[20005],i;
inline bool cmp(data a,data b)//��дcmp����
{
    return a.z>b.z;
}
inline int find(int x)
{
    if(a[x]==x) return x;
    a[x]=find(a[x]);
    return a[x];
}
inline void ad(int x,int y)//�ϲ�
{
    x=find(a[x]);
    y=find(a[y]);
    a[x]=y;
}
inline bool check(int x,int y)//����
{
    x=find(x);
    y=find(y);
    if(x==y) return true;
    return false;
}
int main()
{
    scanf("%d%d",&n,&m);
    for(i=1;i<=n;i++) a[i]=i;
    for(i=1;i<=m;i++)
        scanf("%d%d%d",&f[i].x,&f[i].y,&f[i].z);
    sort(f+1,f+m+1,cmp);//c������Խ��~
    for(i=1;i<=m+1;i++)//Ϊʲôm+1�أ�������е�m+1�����0������Ϊʲô��
    {
        if(check(f[i].x,f[i].y)) {printf("%d",f[i].z);break;}//��������ﷸ�Ѿ���ͬһ��������� �����˳�
        else
        {
            if(!b[f[i].x]) b[f[i].x]=f[i].y;//��ǡ����ˡ�
                else {ad(b[f[i].x],f[i].y);}//�����˵ĵ��˺ϲ�
            if(!b[f[i].y]) b[f[i].y]=f[i].x;
                else {ad(b[f[i].y],f[i].x);}
        }
    }
    return 0;
}
