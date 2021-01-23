#include <cstdio>
#include <algorithm>

using namespace std;
const int N = 3000;

int c, l, ans;

struct cow {
    int a, b;
} a[N];

struct spf {
    int a, b;
} b[N];

inline bool cmp(cow x, cow y) {return x.a > y.a;}
inline bool cmp_s(spf x, spf y) {return x.a > y.a;}

int main() {
//  freopen("in.txt", "r", stdin);

    scanf("%d %d", &c, &l);
    for(int i = 1; i <= c; ++i) scanf("%d %d", &a[i].a, &a[i].b);
    for(int i = 1; i <= l; ++i) scanf("%d %d", &b[i].a, &b[i].b);

    sort(a + 1, a + 1 + c, cmp);//��minspf�ݼ���˳������ 
    sort(b + 1, b + 1 + l, cmp_s);//���̶���ɹ�ȴӴ�С���� 

    for(int i = 1; i <= c; ++i)
        for(int j = 1; j <= l; ++j) {
            if(b[j].a >= a[i].a && b[j].a <= a[i].b && b[j].b) {
                ans++;
                b[j].b--;
                break;//�ҵ��˾�ֱ������һͷ��ţ���õķ�ɹ˪ 
            }
        }

    printf("%d\n", ans);
    return 0;
}
