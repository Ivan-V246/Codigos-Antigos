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

map <string, string> mapa;
map <string, string> hor; 

signed main() { op
    int t; cin >> t;
    mapa["00"] = "12";
    mapa["01"] = "01";
    mapa["02"] = "02";
    mapa["03"] = "03";
    mapa["04"] = "04";
    mapa["05"] = "05";
    mapa["06"] = "06";
    mapa["07"] = "07";
    mapa["08"] = "08";
    mapa["09"] = "09";
    mapa["10"] = "10";
    mapa["11"] = "11";
    mapa["12"] = "12";
    mapa["13"] = "01";
    mapa["14"] = "02";
    mapa["15"] = "03";
    mapa["16"] = "04";
    mapa["17"] = "05";
    mapa["18"] = "06";
    mapa["19"] = "07";
    mapa["20"] = "08";
    mapa["21"] = "09";
    mapa["22"] = "10";
    mapa["23"] = "11";

    hor["00"] = "AM";
    hor["01"] = "AM";
    hor["02"] = "AM";
    hor["03"] = "AM";
    hor["04"] = "AM";
    hor["05"] = "AM";
    hor["06"] = "AM";
    hor["07"] = "AM";
    hor["08"] = "AM";
    hor["09"] = "AM";
    hor["10"] = "AM";
    hor["11"] = "AM";

    hor["12"] = "PM";
    hor["13"] = "PM";
    hor["14"] = "PM";
    hor["15"] = "PM";
    hor["16"] = "PM";
    hor["17"] = "PM";
    hor["18"] = "PM";
    hor["19"] = "PM";
    hor["20"] = "PM";
    hor["21"] = "PM";
    hor["22"] = "PM";
    hor["23"] = "PM";

    
    
    while(t--) {
        string s; cin >> s;
        string temp = "";
        temp += s[0];
        temp += s[1]; 
        cout << mapa[temp] << s[2] << s[3] << s[4] << " " << hor[temp] << endl;
    }

}
