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
        int n, x, y; cin >> n >> x >> y;
        vector<int> fora;
        vector<int> dentro;
        for(int i = 0; i < x; i++) {
            int a; cin >> a;
            fora.emplace_back(a);
        }
        int ini = 0;
        int me = INF;
        for(int i = x; i < y; i++) {
            int a; cin >> a;
            dentro.emplace_back(a);
        }
        for(int i = 0; i < dentro.size(); i++) {
            if(dentro[i] < me) {
                me = dentro[i];
                ini = i;
            }
        }
        for(int i = y; i < n; i++) {
            int a; cin >> a;
            fora.emplace_back(a);
        }
        vector <int> sla;
        for(int i = ini; i < dentro.size(); i++) {
            sla.emplace_back(dentro[i]);
        }
        for(int i = 0; i < ini; i++) {
            sla.emplace_back(dentro[i]);
        }
        if(fora.size()==0) {
            for(auto x : sla){
                cout << x << " ";
            }
            cout << endl;
        } else {
            bool flag = 0;
            for(auto x : fora) {
                // cout << x << " -> " << sla[0] << endl; 
                if(x > sla[0] and !flag) {
                    flag = 1;
                    for(auto y : sla){
                        cout << y << " ";
                    }
                } 
                cout << x << " ";
            }
            if(!flag) {
                for(auto y : sla){
                    cout << y << " ";
                }
            }
            cout << endl;
        }
    }
}