#include <iostream>
#include <map>
using namespace std;
typedef long long LL;
LL a[200001];
map<LL,LL> m;//����һ�����ֵ����ִ�����ӳ�� map<num,times>
//A-B=C --> A-C=B
int main() {
	    freopen("data.in","r",stdin);
	    freopen("data.ans","w",stdout);
        int n;
        LL c;cin>>n>>c;
        LL ans=0;
        for(int i=1;i<=n;i++){
            cin >> a[i];
            m[a[i]]++;
            a[i]-=c;    
        }
        for(int i=1;i<=n;i++) ans+=m[a[i]];
        cout << ans << endl;
        return 0;
}
