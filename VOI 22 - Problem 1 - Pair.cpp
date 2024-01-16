#include <bits/stdc++.h>
using namespace std;
#define file(name) if(fopen(name".inp","r")) {freopen(name".inp","r",stdin); freopen(name".out","w",stdout);}
#define pb push_back
#define fi first
#define se second
#define REP(i,n) for (int i=0; i<n; i++)
#define REPD(i,n) for (int i=n-1; i>=0; i--)
#define FOR(i,a,b) for(int i=a; i<=b; i++)
#define FORD(i,a,b) for(int i=a; i>=b; i--)
#define ll long long
#define vi vector <int>
#define vll vector <ll>
#define pii pair <int,int>
#define INF LLONG_MAX
#define TIME 1.0*clock()/CLOCKS_PER_SEC
const int N=1e6+5;

int n,d,a[N],res=INT_MIN;
struct pairing{
    ll s;
    int i,j;
};
bool comp(pairing a,pairing b) {
    if (a.s!=b.s) return a.s<b.s;
    else if (a.i!=b.i) return a.i<b.i;
    else return a.j>b.j;
}
bool comp2(pairing a,pairing b) {
    if (a.i!=b.i) return a.i<b.i;
    else return a.j>b.j;
}
vector <pairing> q;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    file("PAIR");
    
    cin >> n >> d;
    REP(i,n) cin >> a[i];
    sort(a,a+n);
    FOR(i,0,n-2) FOR(j,i+1,n-1) q.pb({a[i]+a[j],i,j});
    sort(q.begin(),q.end(),comp);
    REP(i,q.size()) {
        if (i!=0 and q[i].s==q[i-1].s) continue; 
        vector <pairing> t;
        int j=i; int cnt=0;
        while (j<q.size() and q[j].s-q[i].s<=d) {t.pb(q[j]); j++;}
        sort(t.begin(),t.end(),comp2);
        int l=-1; int r=n;
        for (auto p:t) if (p.i>l and p.j<r) {cnt++; l=p.i; r=p.j;}
        res=max(res,cnt);
    }
    cout << res;
    cerr << "Time elapsed: " << TIME << "s.\n";
    return 0;
}