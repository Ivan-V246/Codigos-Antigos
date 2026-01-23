#include <bits/stdc++.h>
using namespace std;
#define op ios::sync_with_stdio(false); cin.tie(NULL);
#define INF 0x3f3f3f3f3f3f3f3f
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
        int n, m, k; cin >> n >> m >> k;
        vector <int> robos;
        vector <int> spikes;
        for(int i = 0; i < n; i++) {
            int a; cin >> a; 
            robos.emplace_back(a);
        }
        for(int i = 0; i < m; i++) {
            int a; cin >> a; 
            spikes.emplace_back(a);
        }
        sort(robos.begin(), robos.end());
        spikes.emplace_back(INF);
        spikes.emplace_back(-INF);
        sort(spikes.begin(), spikes.end());
        string s; cin >> s;

        int ans = n;
        vector <pii> espr;
        for(auto x : robos) {
            auto pont = lower_bound(spikes.begin(), spikes.end(), x);
            auto sla = pont-1;
            espr.emplace_back(mkp((*sla), (*pont)));
        }

        int atual = 0;
        int mesq[k+1], mdir[k+1];
        mesq[0] = 0;
        mdir[0] = 0;
        int mes = 0, mdi = 0;
        
        for(int i = 0; i < k; i++) {
            char y = s[i];
            if(y == 'L') {
                atual--;
            } else {
                atual++;
            }
            mes = min(mes, atual);
            mdi = max(mdi, atual);
            mesq[i+1] = mes;
            mdir[i+1] = mdi;
        }
        
        int psum[k];
        for(int i = 0; i < k; i++) {
            psum[i] = 0;
        }
        for(int i = 0; i < n; i++) {
            int l = 0, r = k;
            int ans = k+1;
            while(l <= r) {
                int mid = (l+r)/2;
                
                
                bool flag = 1;
                if(robos[i]+mesq[mid] <= espr[i].f or robos[i]+mdir[mid] >= espr[i].s) {
                    flag = 0;
                }

                if(flag) {
                    l = mid+1;
                } else {
                    r = mid-1;
                    ans = min(ans, mid);
                }

            }
            psum[ans-1]--;
        }

        int sla = n;
        for(auto x : psum) {
            sla+= x;
            cout << sla << " ";
        }
        cout << endl;
    }
}
