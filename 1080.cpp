#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
struct Node{
	ll x,y;
}node[20000];
//ans[1]~ans[ans[0]]�Ǵ����λ�����λ�������֮��������~�� 
int n;
ll ans[4400],minx[4400],chen[4400]={1,1};
bool compare(struct Node a,struct Node b){
	return a.x*a.y<b.x*b.y;
}
void cheng(int k)//�����õ����ˣ�chen[]���浱ǰn���˳˵Ľ����ÿ�γ���ʱ��ͷ���Щ 
{
    int t=0;
    for(int i=1;i<=chen[0];i++)
    {
        chen[i]=chen[i]*k+t;
        t=chen[i]/10;
        chen[i]%=10;
        if(t>0&&i>=chen[0])
        chen[0]++;
    }
}
void chu(int k)//��������chen[]������ŵ�ans�� 
{
    int t=0,ok=1;
    memset(ans,0,sizeof(ans));
    for(int i=chen[0];i>0;i--)
    {
        ans[i]=(chen[i]+10*t)/k;
        t=(chen[i]+10*t)%k;
        if(ans[i]&&ok)
        ans[0]=i,ok=0; 
    }       
}
void print(long long q[])
{
    int i;
    for(i=q[0];i>0&&q[i]==0;i--);
    for(;i>0;i--)
    cout<<q[i];
    cout<<endl;
}
bool cpr(long long q[],long long w[])//�ȱ�λ������Ӹ�λ����λ�ȣ�true�ͻ���false�Ͳ��� 
{
    if(q[0]>w[0])  return false;
    if(q[0]<w[0])  return true;
    for(int i=q[0];i>0;i--)
    {
        if(q[i]<w[i])  return true;
        if(q[i]>w[i])  return false;
    }
    return false;
}
int main(){
	cin>>n;
	cin>>node[0].x>>node[0].y;
	for(int i=1;i<=n;i++) cin>>node[i].x>>node[i].y;
	sort(node+1,node+n+1,compare);
	for(int i=0;i<n;i++){
		cheng(node[i].x);
		chu(node[i+1].y);
		if(cpr(minx,ans)) memcpy(minx,ans,sizeof(ans));
	}
	print(minx);
	return 0;
}
