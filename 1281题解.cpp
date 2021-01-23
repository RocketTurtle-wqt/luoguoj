#include <iostream>
#include <algorithm>
using namespace std;
const int maxn = 505;

int a[maxn];
int n, k;
int ans;

int check(int x) {   //̰���ж�
    int sum = 0;
    int t = 1;
    for(int i = n; i >= 1; i--) {
        if(sum + a[i] <= x)    //�����ң�����
            sum += a[i];       //��Ȼ#5��MLE
        else {
            t++;
            sum = a[i];
        }
    }
    return t <= k;
}

void print(int l, int r) {  //���ҽ����
    int sum = 0;
    for(int i = r; i >= l; i--) {
        if(sum + a[i] > ans) {
            print(l, i);  //����������
            cout << i+1 << ' ' << r << endl;
            return;
        }
        sum += a[i];
    }
    cout << 1 << ' ' << r << endl; //ע��߽磬�Ҵ���3�Σ�qwq��
}

int main() {
    cin >> n >> k;
    if(n == 0) return 0;  //�����Ǽ��أ����ǲ����أ��Ӱ�
    int l = 0x7fffff, r = 0;  //���ұ߽�
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
        l = min(l, a[i]);
        r += a[i];
    }
//    printf("%d %d\n",l,r);
    //����ģ�壬��˵��
    while(l <= r) {
        int mid = (l+r) / 2;
//        printf("%d\n",mid);
        if(check(mid)) {
            ans = mid;
            r = mid-1;
        }
        else l = mid+1;
    }

    //cout << ans << endl;

    print(1, n);  //����ans�����������д���ǵݹ飬��ӲҪѭ��Ҳ��
    return 0;
}
