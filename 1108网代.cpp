#include<cstdio>
#include<cstring>
int max(int x,int y){return x>y?x:y;}
int a[5001],f[5001],t[5001];
//a[i]����ǵ�i���Ʊ�ļ۸�
//f[i]����ǵ�i����½������еĳ���
//t[i]�������i��β����½������е����ࣨ������
int main()
{
    memset(f,0,sizeof(f));//��ʼ������
    memset(t,0,sizeof(t));//��ʼ������
    int n,maxx=0;
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
        scanf("%d",&a[i]);
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<i;j++)
            if(a[i]<a[j])//�ӳ��Ѿ����ڵ���½�������
                f[i]=max(f[i],f[j]+1);
        if(f[i]==0)
            f[i]++;//�����ǰ������ĿǰΪֹ���ģ�����½����������Լ�
        if(f[i]>maxx)
            maxx=f[i];//��f���������Ϻ󣬴�����½������еĳ���
        for(int j=1;j<i;j++)
            if(f[i]==f[j]&&a[i]==a[j])
                t[j]=0;//�����ǰ���������ͬ������ȥǰ������У���ֹ�ظ�����
            else if(f[i]==f[j]+1&&a[i]<a[j])
                t[i]+=t[j];//������Խ���ǰ������У���̳��䷽����
        if(!t[i])//�����ǰ������ĿǰΪֹ���ģ����ǳ�ʼ����
            t[i]=1;
    }
    int sum=0;//sum���������ڴ���½������У��������ĸ���
    for(int i=1;i<=n;i++)
        if(f[i]==maxx)
            sum+=t[i];
    printf("%d %d",maxx,sum);
    return 0;
}
