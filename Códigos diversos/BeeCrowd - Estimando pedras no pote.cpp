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
const int MAXN = 1e4+10;
const int mod = 1e9+10;
int n;
int chu[MAXN];
vector <int> erro;
vector <int> ans;
bool vi[mod];

signed main() { 
    cin >> n; 
    for(int i = 0; i < n; i++) {
        cin >> chu[i];
    }
    stack <pii> pilha;
    int tot = 0;
    for(int i = 0; i < n; i++) {
        int a; cin >> a;
        tot += a;
        erro.emplace_back(a);
    }
    for(int i = 0; i < n; i++) {
        int mais = chu[0] + erro[i];
        if(mais <= 1e9) {
            if(!vi[mais]) {
                pilha.push(mkp(mais, tot));
            }
            vi[mais] = 1;
        } 
        int menos = chu[0] - erro[i];
        if(menos >= 1) { 
            if(!vi[menos]) {
                vi[menos] = 1; 
                pilha.push(mkp(menos, tot));
            }
        }
    }

    stack <pii> pilha2;
    sort(erro.begin(), erro.end());
    bool flag = 1;
    for(int i = 1; i < n; i++) {
        if(flag) {
            while(!pilha.empty()) {
                int atual = pilha.top().f;
                int check = pilha.top().s;
                pilha.pop();
                int busca = abs(atual-chu[i]);
                if(*(lower_bound(erro.begin(), erro.end(), busca)) == busca) {
                    pilha2.push(mkp(atual, check - busca));
                }
            }
            flag = 0;
        } else {
            while(!pilha2.empty()) {
                int atual = pilha2.top().f;
                int check = pilha2.top().s;
                pilha2.pop();
                int busca = abs(atual-chu[i]);
                if(*(lower_bound(erro.begin(), erro.end(), busca)) == busca) {
                    pilha.push(mkp(atual, check - busca));
                }
            }
            flag = 1;
        }
    }
    if(n%2 == 1) {
        while(!pilha.empty()) {
            if(pilha.top().s == abs(pilha.top().f - chu[0])) {
                ans.emplace_back(pilha.top().f);
            }
            pilha.pop();
        }
    } else {
         while(!pilha2.empty()) {
            if(pilha2.top().s == abs(pilha2.top().f - chu[0])) {
                ans.emplace_back(pilha2.top().f);
            }
            pilha2.pop();
        }
    }
    sort(ans.begin(), ans.end());
    for(auto x : ans) {
        cout << x << endl;
    }
}
/*Questão do capeta.*/
