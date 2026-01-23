#include <bits/stdc++.h>
using namespace std;
#define op ios::sync_with_stdio(false); cin.tie(NULL);
#define INF 0x3f3f3f3f
#define pii pair<int,int>
#define ll long long
#define mkp make_pair
#define endl '\n'
#define f first
#define s second
#define int long long
#define dbg(x) cout << #x << " " << x << endl;
const int MAXN = 1e6+5;


signed main() { 
    int t; cin >> t;
    while(t--) {
        int a, b, c; cin >> a >> b >> c;
        if(c == 0) {
            cout << -1 << endl;
            continue;
        }
        bool flag = 1;
        set <pii> num;
        int alt = 0;
        int rest = 0;
        while(b>0) {
            if(b >= c) {
                alt++;
                b-=c;
            } else {
                rest = c-b;
                alt++;
                b = 0;
            }
        }
        if(rest != 0) {
            num.insert(mkp(alt-1, rest));
        }
        num.insert(mkp(alt, c-rest));
        c = 0;
        while(a > 0) {
            // for(auto x : num) {
            //     cout << x.s << " " << x.f << endl;
            // }
            a--;
            pii sla = *num.begin();
            if(sla.s == 1) {
                if(num.size() == 1) {
                    flag = 0;
                    break;
                } else {
                    num.erase(num.begin());
                    pii aux = *num.begin();
                    num.erase(num.begin());
                    if(aux.s > 1) {
                        aux.s--;
                        num.insert(aux);
                    } 
                    num.insert(mkp(aux.f+1, 1));
                }
            } else {
                num.erase(num.begin());
                if(num.size() > 0) {
                    pii aux = *num.begin();
                    num.erase(num.begin());
                    aux.s++;
                    num.insert(aux);
                } else {
                    num.insert(mkp(sla.f+1, 1));
                }
                sla.s-=2;
                if(sla.s > 0) {
                    num.insert(sla);
                }
            }
        }
        if(num.size() > 1) {
            flag = 0;
        } 
        if(num.size() == 1) {
            pii ans = *num.begin();
            if(flag and ans.s == 1) {
                cout << ans.f << endl;
                continue;
            }
        }
        cout << -1 << endl;
    }
}