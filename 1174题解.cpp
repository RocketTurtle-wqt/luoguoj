#include<bits/stdc++.h>
using namespace std;
const int maxn=5e5+10;
int n,a[maxn],p[maxn],tree[maxn]; //treeΪ��״����
long long ans=0;
bool cmp(int x,int y) //��ɢ������
{
  return a[x]<a[y];
}
int lowbit(int x)
{
  return x&(-x);
}
void update(int x,int d)
{
  while(x<=n)
  {
    tree[x]+=d;
    x+=lowbit(x);
  }
}
long long query(int x)
{
  long long ret=0;
  while(x>0)
  {
    ret+=tree[x];
    x-=lowbit(x);
  }
  return ret;
}
int main()
{ //����������������Ҫ��ɢ������
  scanf("%d",&n);
  for(int i=1; i<=n; i++) 
  {
    scanf("%d",&a[i]);
    p[i]=i; //p��¼�ڵ���
  } //�ܶ���20�־�����Ϊ���������stable_sort�����ı�ԭ�����е�Ԫ��λ�ã�����Ԫ�����ʱ��
  stable_sort(p+1,p+n+1,cmp);
  for(int i=1; i<=n; i++) a[p[i]]=i; //��ɢ��
  for(int i=n; i>=1; i--) //����ѭ��
  {
    ans+=query(a[i]-1); //��ѯ���Լ�С�����Լ���������м���
    update(a[i],1); //ֵΪa[i]�����ĸ���+1
  }
  printf("%lld\n",ans); //ͬ��������long long
  return 0;
}
