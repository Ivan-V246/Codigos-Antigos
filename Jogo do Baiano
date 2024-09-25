#include <bits/stdc++.h>
using namespace std;
#define op ios::sync_with_stdio(false); cin.tie(NULL);
#define inf 0x3f3f3f3f
#define pii pair <int, int>
#define ll long long
#define mkp make_pair
#define endl '\n'
#define f first
#define s second
#define int long long
#define dbg(x) cout << #x << " " << x << endl;
#define db cout << "blz" << endl;
const int MAXN = 5e5+5;
const int mod = 1e9+7;
const int raiz = 1000;

multiset <int> menor;
multiset <int> maior;

int s1, s2;

void reb() {
    while(maior.size() > menor.size()) {
        menor.insert(*maior.begin());
        s1+= *(maior.begin());
        s2-= *(maior.begin());
        maior.erase(maior.begin());
    }
    while(menor.size()> maior.size()) {
        maior.insert( *(--(menor.end())) ); 
        s2+= (*(--menor.end()));
        s1-= *(--menor.end());
        menor.erase(--menor.end());
    }    
}

signed main() { op
    int n, m; cin >> n >> m;
    for(int i = 1; i <= n; i++) {
        int a; cin >> a;
        menor.insert(a);
        s1+=a;
    }
    reb();
    auto med = maior.begin();
    int resp = 0;
    int t1 = menor.size(), t2 = maior.size();
    resp += ((t1*(*med))-s1);
    resp += (s2 - (t2*(*med)));
    cout << resp << endl;
    while(m--) {
        int com, a; cin >> com >> a;
        if(com == 0) {
            reb();
            if(maior.empty()) {
                s2+=a;
                maior.insert(a);
            } else {
                med = maior.begin();
                if(a <= *med) {
                    menor.insert(a);
                    s1+= a;
                } else {
                    maior.insert(a);
                    s2+= a;
                }
            }

            reb();

            med = maior.begin();
            resp = 0;  
            t1 = menor.size(), t2 = maior.size();

            resp += ((t1*(*med))-s1);
            resp += (s2 - (t2*(*med)));
            cout << resp << endl;

        } else {
            auto it = menor.find(a);
            auto it2 = maior.find(a);

            if(it != menor.end()) {
                s1-=a;
                menor.erase(it);
            } else if(it2 != maior.end()) {
                s2-=a;
                maior.erase(it2);
            }

            reb();

            t1 = menor.size(), t2 = maior.size();
            if(t1 == 0 and t2 == 0) {
                cout << -1 << endl;    
            } else { 
                med = maior.begin();
                resp = 0;
                resp += ((t1*(*med))-s1);
                resp += (s2 - (t2*(*med)));
                cout << resp << endl;
            }

        }
    }
}
