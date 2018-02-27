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

namespace DominatorTree{// tree[] is the dominator tree
    const int MAXN = 200010;
    int N, T;
    int arr[MAXN], rev[MAXN], sdom[MAXN], label[MAXN], dsu[MAXN], par[MAXN], dom[MAXN];
    vector<int> rG[MAXN], bucket[MAXN], tree[MAXN];

    void init(int _N){
        N = _N; T = 0;
        for(int i=1;i<=N;i++)
            arr[i] = rev[i] = sdom[i] = label[i] = dsu[i] = par[i] = dom[i] = 0,
            rG[i].clear(), bucket[i].clear(), tree[i].clear();
        buildTree(1, G);
    }

    int Find(int u,int x=0){
        if(u==dsu[u])return x?-1:u;
        int v = Find(dsu[u],x+1);
        if(v<0)return u;
        if(sdom[label[dsu[u]]]<sdom[label[u]])
            label[u]=label[dsu[u]];
        dsu[u]=v;
        return x?v:label[u];
    }
    void Union(int u,int v){
        dsu[v]=u;
    }

    void dfs(int u, vector<int> G[]){
        ++T;
        arr[u] = T;rev[T] = u;sdom[T]=T;
        label[T]=T;dsu[T]=T;
        for(int v : G[u]){
            if(!arr[v])
                dfs(v,G),par[arr[v]]=arr[u];
            rG[arr[v]].pb(arr[u]);
        }
    }

    void buildTree(int d, vector<int> G[]){
        T = 0;
        dfs(d, G);
        for(int i=T;i>=1;i--){
			for(int j : rG[i])
				sdom[i] = min(sdom[i],sdom[Find(j)]);
			if(i>1)bucket[sdom[i]].pb(i);
			for(int j=0;j<bucket[i].size();j++){
				int w = bucket[i][j];
				int v = Find(w);
				if(sdom[w]==sdom[v])dom[w]=sdom[w];
				else dom[w] = v;
			}
			if(i>1)Union(par[i],i);
		}
		for(int i=2;i<=T;i++){
			if(dom[i]!=sdom[i])
				dom[i]=dom[dom[i]];
			tree[rev[dom[i]]].pb(rev[i]);
			tree[rev[i]].pb(rev[dom[i]]);
		}
    }
}

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
