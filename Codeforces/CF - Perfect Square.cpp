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
        int matriz[n+2][n+2];
        for(int i = 0; i < n+2; i++) {
            for(int j = 0; j < n+2; j++) {
                if(i == 0 or j == 0 or i == n+1 or j == n+1) {
                    matriz[i][j] = -1;
                } else {
                    char a; cin >> a;
                    matriz[i][j] = a- 'a';
                }
            }
        }
        int ans = 0;
        int resp[n][2]; //Primeira guarda a soma, segunda guarda o maior
        int cont = 0;
        int index = 0;
        int i = 1, j = 1;
        while(cont < n*n) {
            memset(resp, 0, sizeof resp);

            index = 0;
            for(;; j++) {
                if(matriz[i][j+1] == -1) {
                    break;
                } else {
                    resp[index][0] += matriz[i][j];
                    resp[index][1] = max(resp[index][1], matriz[i][j]);
                    index++;
                    matriz[i][j] = -1;
                    cont++;
                }
            }

            index = 0;
            for(;; i++) {
                if(matriz[i+1][j] == -1) {
                    break;
                } else {
                    resp[index][0] += matriz[i][j];
                    resp[index][1] = max(resp[index][1], matriz[i][j]);
                    index++;
                    matriz[i][j] = -1;
                    cont++;
                }
            }

            index = 0;
            for(;; j--) {
                if(matriz[i][j-1] == -1) {
                    break;
                } else {
                    resp[index][0] += matriz[i][j];
                    resp[index][1] = max(resp[index][1], matriz[i][j]);
                    index++;
                    matriz[i][j] = -1;
                    cont++;
                }
            }

            index = 0;
            for(;; i--) {
                if(matriz[i][j] == -1) {
                    break;
                } else {
                    resp[index][0] += matriz[i][j];
                    resp[index][1] = max(resp[index][1], matriz[i][j]);
                    index++;
                    matriz[i][j] = -1;
                    cont++;
                }
            }

            for(int k = 0; k < index; k++) {
                ans += (4*resp[k][1]) - (resp[k][0]);
            }

            i++;
            j++;
        }

        cout << ans << endl;
    }
}
