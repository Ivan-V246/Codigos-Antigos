#include <bits/stdc++.h>
using namespace std;
#define op ios::sync_with_stdio(false); cin.tie(NULL);
#define INF 0x3f3f3f3f
#define pii pair<int, pair<int, int>>
#define ll long long
#define mkp make_pair
#define endl '\n'
#define f first
#define s second
#define dbg(x) cout << #x << " " << x << endl;
const int MAXN = 2*1e5+10;
int n;
vector<int> lista(MAXN);
map <int, bool> vi;
map <int, int> dp;
int ans[MAXN];

signed main() { 
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> lista[i];
    }
    int ini, last, resp = 0;
    for(int i = n; i >= 1; i--) {
        
            vi[lista[i]] = 1;
            int temp = dp[lista[i]+1];
            dp[lista[i]] = max(dp[lista[i]],temp+1);
        
        ans[i] = dp[lista[i]];
        if(ans[i] > resp) {
            resp = ans[i];
            ini = i;
            last = lista[i];
        }
    }
    cout << resp << endl;
    cout << ini << " ";
    for (int i = ini; i <= n; i++) {
        if(lista[i] == last+1 and ans[i] == resp-1) {
            cout << i << " ";
            resp--;
            last = lista[i];
        }            
    }
    cout << endl;
}
/*Dp iterativa, que usa bactracking e o fato de para um cara definido a resp dele sempre vai ser a resp do maior valor[dele]+1 seguinte, que já foi calculado.*/
