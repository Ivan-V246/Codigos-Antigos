#include <bits/stdc++.h>
using namespace std;

#define INF 0x3f3f3f3f3f3f3f3f
#define ll long long
#define  int ll
#define op cin.tie(0); ios::sync_with_stdio(0);
#define pii pair<int, int>
signed main() { op
    int n; cin >> n;
    string str; cin >> str;
    deque <int> sla;
    int ant = -1;
    int cont = 0;
    for(int i = 0; i < n; i++) {
        int v = str[i]-'0';
        if(v != ant) {
            sla.emplace_back(cont);
            ant = v;
            cont = 1;
        } else {
            cont++;
        }
    }
    sla.emplace_back(cont);
    sla.pop_front();
    int l = 0;
    int r = 0;
    int tam = sla.size();
    bool flag = 0;
    int ans = 0;

    while(tam) {
        if(sla[l] == 1) {
            while(r <= l){
                r++;
            }
            while(sla[r] == 1) {
                r++;
               
                if(r == sla.size()) {
                    flag = 1;
                    break;
                }
            }
            if(flag) break;
            sla[r]--;
        }
        l++;
        tam--;
        ans++;
    }
    ans += tam/2;
    ans += tam%2 == 1;
    cout << ans << endl;
}