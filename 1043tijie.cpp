#include<bits/stdc++.h>
using namespace std;
int n,m,f1[110][110][110],f2[110][110][110],a[110],sum[110];
int mod(int x){
    return (x%10+10)%10;
}
int main(){
    cin>>n>>m;
    for(int i=1;i<=n;i++){cin>>a[i];sum[i]=sum[i-1]+a[i];}
    for(int i=1;i<=n;i++){a[i+n]=a[i],sum[i+n]=sum[i]+sum[n];}
    memset(f2,127,sizeof(f2));//f2��¼������Сֵ ����Ҫ��ʼ��Ϊ����ֵ
    for(int i=1;i<=2*n;i++){
        for(int j=i;j<=2*n;j++){
            f1[i][j][1]=f2[i][j][1]=mod(sum[j]-sum[i-1]);//Ԥ����ÿ�ε�ֵ
        }
    }
    for(int l=1;l<=n;l++){//���䳤��
        for(int i=1,j=i+l-1;j<=2*n;i++,j++){//���Ҷ˵�
            for(int h=2;h<=m;h++){//����
                for(int k=i+h-1;k<j;k++){//�̵�
                    f1[i][j][h]=max(f1[i][j][h],f1[i][k][h-1]*mod(sum[j]-sum[k]));
                    f2[i][j][h]=min(f2[i][j][h],f2[i][k][h-1]*mod(sum[j]-sum[k]));
                }
            }
        }
    }
    int maxn=0,minn=0x7fffffff;
    for(int i=1;i<=n;i++){//�Ҵ���������
        maxn=max(maxn,f1[i][i+n-1][m]);
        minn=min(minn,f2[i][i+n-1][m]);
    }
    cout<<minn<<endl<<maxn;
}
