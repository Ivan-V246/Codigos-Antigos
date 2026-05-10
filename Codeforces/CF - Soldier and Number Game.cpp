#include <bits/stdc++.h>
 
#define ALL(x) x.begin(), x.end()
#define endl '\n'
 
#define F first
#define S second
#define PB push_back
#define EB emplace_back
#define MP make_pair
#define INF 0x3f3f3f3f
#define INFLL 0x3f3f3f3f3f3f3f3f
 
using namespace std;
 
typedef long long ll;
typedef unsigned long long ull;
#define int ll
typedef vector<int> vi;
typedef pair<int, int> ii;
typedef vector<ii> vii;
const int MAXN = 5e6+5;
const int MOD = 1e9 +7;

vi primos;
bool eh[MAXN];
int dp[MAXN];
bool calc[MAXN];
int ps[MAXN];

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t; cin >> t;
    for(int i = 2; i <= MAXN-1; i++) {
        if(!eh[i]) {
            primos.EB(i);
            dp[i] = 1;
            calc[i] = 1;
            for(int j = i+i; j <= MAXN-1; j+=i) {
                eh[j] = 1;
            }
        }
    }
    calc[1] = 1;
    for(int i = 2; i <= MAXN-1; i++) {
        int atual = i;
        int ind = 0;
        if(calc[i]) continue;
        while(1) {
            if(calc[atual]) {
                dp[i] += dp[atual];
                break;
            }
            if(atual % primos[ind] == 0) {
                atual/= primos[ind];
                dp[i]++;
            } else {
                ind++;
            }
        }
        calc[i] = 1;
    }
    for(int i = 1; i <= MAXN-1; i++) {
        ps[i] = dp[i] +ps[i-1];
    }
    while(t--) {
        int a, b; cin >> a >> b;
        cout << ps[a]-ps[b] << endl;
    }
}

//Questão de Crivo/Teoria dos números/Dp/ Prefix-Sum. Ebaaaaaaaaaaa
