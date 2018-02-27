#include <bits/stdc++.h>

#define LOCAL 1

#define lli long long int
#define llu unsigned long long int
#define ld long double
#define all(v) v.begin(),v.end()
#define pb push_back
#define mp make_pair
#define F first
#define S second
#define si(n) scanf("%d",&n)
#define slli(n) scanf("%lld",&n);
#define ss(n) scanf("%s",n);

const long double EPS = 1e-10;
const int MOD = 1000000007ll;
const int mod1 = 1000000009ll;
const int mod2 = 1100000009ll;
int INF = (int)1e9;
lli INFINF = (lli)1e18;
long double PI = acos(-1.0);

using namespace std;

int bit_count(lli _x){lli _ret=0;while(_x){if(_x%2==1)_ret++;_x/=2;}return _ret;}
int bit(lli _mask,int _i){return (_mask&(1ll<<_i))==0?0:1;}
int add(int a,int b,int m=MOD){int x=a+b;while(x>=m)x-=m;while(x<0)x+=m;return x;}
int sub(int a,int b,int m=MOD){int x=a-b;while(x<0)x+=m;while(x>=m)x-=m;return x;}
int mul(int a,int b,int m=MOD){lli x=a*1ll*b;x%=m;while(x<0)x+=m;return (int)x;}
int ldtoint(ld x){return (int)(x+0.5);}lli ldtolli(ld x){return (lli)(x+0.5);}
int powermod(lli _a,lli _b,int _m=MOD){lli _r=1;while(_b){if(_b%2==1)_r=mul(_r,_a,_m);_b>>=1;_a=mul(_a,_a,_m);}return _r;}

template<class T1,class T2>ostream&operator<<(ostream& os,const pair<T1,T2>&p){os<<"["<<p.first<<","<<p.second<<"]";return os;}
template<class T>ostream&operator<<(ostream& os,const vector<T>&v){os << "[";bool first=true;for (T it:v){if (!first)os<<", ";first = false;os<<it;}os<<"]";return os;}
template<class T>ostream&operator<<(ostream& os,set<T>&v){os<<"[";bool first=true;for (T it:v){if(!first)os<<", ";first=false;os<<it;}os<<"]";return os;}
template<class T1,class T2>ostream&operator<<(ostream& os,map<T1,T2>&v){os<<"[";bool first=true;for(pair<T1,T2> it:v){if(!first)os<<", ";first=false;os<<"("<<it.F<<","<<it.S<<")";}os<<"]";return os;}
template<class T>void debug(T a[],int s,int e){if(!LOCAL)return;cout<<"[";for(int i=s;i<e;i++)cout<<a[i]<<", ";cout<<a[e]<<"]\n";}
template<class T>void debug(T x){if(!LOCAL)return;cout<<x<<"\n";}

struct AhoCorasick{
    // root is 0
    const static int MAXN = 1010;
    const static int MAXCH = 26;
    int node[MAXN][MAXCH];
    int suflink[MAXN];
    bool ends[MAXN];
    int total;
    vector<int> G[MAXN];

    void init(int N, int ch){
        total = 1;
        for(int i=0;i<=N;i++)
            for(int j=0;j<ch;j++)
                node[i][j] = -1;
        for(int i=0;i<=N;i++){
            ends[i] = false;
            suflink[i] = 0;
            G[i].clear(); // tree formed by reverse sufflinks
        }
    }

    void insert(string s, int id) {
        int curr = 0;
        for (char c : s) {
            int x = c - 'a';
            if (node[curr][x] == -1)
                node[curr][x]= ++total;
            curr = node[curr][x];
        }
        ends[curr] = true;
    }
    void bfs() {
        suflink[0] = 0;
        queue <int> q;
        for (int i = 0; i < MAXCH; i++) {
            if (node[0][i] != -1) {
                suflink[node[0][i]] = 0;
                q.push(node[0][i]);
                G[0].pb(node[0][i]);
            }
            else node[0][i] = 0;
        }
        while (!q.empty()) {
            int u = q.front();
            q.pop();
            for (int c = 0; c < MAXCH; c++) {
                int v = node[u][c];
                if (v == -1) continue;
                int f = suflink[u];
                while (node[f][c] == -1) f = suflink[f];
                suflink[v] = node[f][c];
                ends[v] |= ends[suflink[v]];
                if (suflink[v] != v) G[suflink[v]].pb(v);
                q.push(v);
            }
         }
    }
    int next_state(int curr, int c) {
        int x = curr;
        while (node[x][c] == -1) x = suflink[x];
        return node[x][c];
    }
};

int main()
{
if(LOCAL){
    freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
}
    srand (time(NULL));
    //ios::sync_with_stdio(0);cin.tie(0);



    return 0;
}

