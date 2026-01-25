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


signed main() { op
    int t; cin >> t;
    while(t--) {
        int n; cin >> n;
        int maior = n;
        int l = -2;
        int r = -2;
        bool flag = 0;
        int num[n];
        for(int i = 0; i < n; i++) {
            int a; cin >> a;
            num[i] = a;
            if(!flag) {
                if(maior != a) {
                    flag = 1;
                    l = i;
                    maior++;
                }
                maior--;
            } else {
                if(a == maior) {
                    r = i;
                }
            }
        }
        if(l != -2 and r != -2) {
            while(l <= r) {
                swap(num[l], num[r]);
                l++;
                r--;
            }
        }
        for(auto x : num) {
            cout << x << " ";
        }
        cout << endl;
    }
}