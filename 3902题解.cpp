#include<iostream>
#include<algorithm>
using namespace std;
long long n,num,now,sum,f[1001];
int main()
{
    cin>>n;
    for(long long i=1;i<=n;i++)
    {
        cin>>num;
        if(num>f[now])//������������ǰ�Ĵ�˵�����ƻ������ϸ������������ô��������������ж�����
        f[++now]=num;
        else
        {
            *lower_bound(f+1,f+now+1,num)=num;//����������֮ǰ����С��ô��lower_bound()�����ҵ����ʺϵ�λ�ý�������Ž�ȥ
            sum++;//�������൱���޸�һ�����������ۼ�����1
        }
    }
    cout<<sum;
    return 0;
}
//���˴��벻����������
