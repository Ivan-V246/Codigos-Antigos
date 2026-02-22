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
#define vi vector<int>
#define dbg(x) cout << #x << " " << x << endl;
const int MAXN = 1e3+5;

signed main() {
    fstream Snake_Scales_2;
    fstream vali_input;
    vali_input.open("snake_scales_chapter_2_input.txt", ios::in);
    Snake_Scales_2.open("Snake_Scales_2.txt", ios::out);
    int t; vali_input >> t;
    for(int j = 0; j < t; j++) {
        int n; vali_input >> n;
        vi escadas; 
        vi alc;
        for(int i = 0; i < n; i++) {
            int a; vali_input >> a;
            escadas.emplace_back(a);
        }
        int resp = 10000000000000;
        int l = 0, r = 10000000000;
        while(l <= r) {
            int mid = (l+(r-l)/2);
            bool vis[n]; for(int i = 0; i < n; i++) vis[i] = 0;
            stack <int> pilha;
            for(int i = 0; i < n; i++) {
                if(mid >= escadas[i]) {
                    pilha.emplace(i);
                    vis[i] = 1;
                }
            }
            while(pilha.size()) {
                int atual = pilha.top();
                pilha.pop();
                if(atual-1 >= 0) {
                    if(!vis[atual-1]) {
                        if(abs(escadas[atual-1] - escadas[atual]) <= mid) {
                            vis[atual-1] = 1;
                            pilha.emplace(atual-1);
                        }
                    }
                }
                if(atual+1 < n) {
                    if(!vis[atual+1]) {
                        if(abs(escadas[atual+1] - escadas[atual]) <= mid) {
                            vis[atual+1] = 1;
                            pilha.emplace(atual+1);
                        }
                    }
                }
            }
            bool flag = 1;
            for(int i = 0; i < n; i++) {
                flag = flag and vis[i];
            }
            if(flag) {
                resp = min(resp, mid);
                r = mid-1;
            } else {
                l = mid+1;
            }
        }
        Snake_Scales_2 << "Case #" << j+1 << ": " << resp << endl;
    }
    Snake_Scales_2.close();
    vali_input.close();
    return 0;
}