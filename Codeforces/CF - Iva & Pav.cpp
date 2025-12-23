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
const int MAXN = 2e5+5;

int neutro = 0;
int lista[MAXN];
int seg[4*MAXN];

void construir(int no, int l, int r) {
    if(l == r) {
        seg[no] = lista[l];
        return;
    }
    int mid = ((r-l)/2) + l;
    int esq = no*2, dir = esq+1;
    construir(esq, l, mid);
    construir(dir, mid+1, r);

    seg[no] = seg[esq] & seg[dir];
}

int resp(int no, int l, int r, int objL, int objR) {
    if(l > objR or r < objL) {
        return neutro;
    }
    if(l >= objL and r <= objR){
        return seg[no];
    }
    int mid = ((r-l)/2) + l;
    int esq = no*2, dir = esq+1;

    return resp(esq, l, mid, objL, objR) & resp(dir, mid+1, r, objL, objR);
}

signed main() { op
    int t; cin >> t;
    for(int i = 0; i < 60; i++) {
        neutro = neutro | (1LL << i);
    }
    while(t--) {
        int n; cin >> n;
        for(int i = 1; i <= n; i++) {
            cin >> lista[i];
        }
        construir(1, 1, n);
        int q; cin >> q;
        while(q--) {
            int a, x; cin >> a >> x;
            int l = a, r = n;
            int ans = -1;
            while(l <= r) {
                int mid = (r-l)/2 + l;
                int temp = resp(1, 1, n, a, mid);
                if(temp >= x) {
                    l = mid+1;
                    ans = mid;
                } else {
                    r = mid-1;
                }
            }
            cout << ans << " ";
        }
        cout << endl;
    }
}
