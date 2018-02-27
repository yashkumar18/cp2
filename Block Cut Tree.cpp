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

struct BlockCutTree{
    /*
    tree is alternating blocks-cuts (max size 2*N)
    AP belongs to cut node (single size) and neighbor BCC
    */
    const static int MAXN = 200010;
    int N, T, tot, ecnt;
    int compId[MAXN], low[MAXN], to[2*MAXN];
    bool vis[MAXN], isAp[MAXN], isCutComp[MAXN];
    stack<pair<int,int> > Stack;
    set<int> compNodes[MAXN];
    vector<int> tree[MAXN];

    void init(int _N, vector<int> G[], int toG[]){
        N = _N; T = 0;tot = 0;ecnt = 0;
        while(Stack.size() > 0) Stack.pop();
        for(int i=1;i<=N;i++){
            compId[i] = -1;
            low[i] = 0;
            vis[i] = isAp[i] = isCutComp[i] = false;
            compNodes[i].clear();
            tree[i].clear();
            to[2*i] = to[2*i+1] = 0;
        }
        dfs(1, 0, G, toG);
        if(!Stack.empty()){
            ++tot;
            while(!Stack.empty()){
                compNodes[tot].insert(Stack.top().F);
                compNodes[tot].insert(Stack.top().S);
                Stack.pop();
            }
            for(auto it : compNodes[tot]){
                if(isAp[it]){
                    ecnt++;
                    tree[tot].pb(ecnt);
                    to[ecnt] = compId[it];
                    ecnt++;
                    tree[compId[it]].pb(ecnt);
                    to[ecnt] = tot;
                }
                else
                    compId[it]=tot;
            }
        }
        for(int i=1;i<=tot;i++)
            if(compNodes[i].size() == 1 && isAp[*compNodes[i].begin()])
                isCutComp[i] = true;
    }

    int dfs(int u, int p, vector<int> G[], int toG[]) {
        low[u] = T++;
        vis[u] = 1;
        int utime = low[u];
        int dfsChild = 0;

        for(int e : G[u]){
            int v = toG[e];
            if(!vis[v]){
                Stack.push({u,v});
                dfsChild++;
                int vtime = dfs(v, u, G, toG);
                utime = min(utime , vtime);
                if((low[u]==0 && dfsChild>1) || (vtime >= low[u] && low[u]>0)){
                    isAp[u]=true;
                    if(compId[u] == -1){
                        ++tot;
                        compId[u] = tot;
                        compNodes[tot].insert(u);
                    }
                    tot++;
                    while(Stack.top() != mp(u,v)){
                        compNodes[tot].insert(Stack.top().F);
                        compNodes[tot].insert(Stack.top().S);
                        Stack.pop();
                    }
                    compNodes[tot].insert(Stack.top().F);
                    compNodes[tot].insert(Stack.top().S);
                    Stack.pop();
                    for(auto it : compNodes[tot]){
                        if(isAp[it]){
                            ecnt++;
                            tree[tot].pb(ecnt);
                            to[ecnt] = compId[it];
                            ecnt++;
                            tree[compId[it]].pb(ecnt);
                            to[ecnt] = tot;
                        }
                        else
                            compId[it]=tot;
                    }
                }

            }
            else if(v!=p && low[v]<utime){
                utime = min(utime, low[v]);
                Stack.push({u,v});
            }
        }
        return utime;
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
