/*
By : Yash Kumar
Dhirubhai Ambani Institute Of Information And Communication Technology, Gandhinagar (DA-IICT GANDHINAGAR)
2nd Year ICT BTECH student
*/
#include<bits/stdc++.h>

#define lli long long int
#define llu unsigned long long int
#define all(v) v.begin(),v.end()

const double EPS = 1e-24;
const lli MOD = 1000000007ll;
const double PI = 3.14159265359;
int INF = 2147483645;
lli INFINF = 9223372036854775807;

template <class T>T Max2(T a,T b){return a<b?b:a;}
template <class T>T Min2(T a,T b){return a<b?a:b;}
template <class T>T Max3(T a,T b,T c){return Max2(Max2(a,b),c);}
template <class T>T Min3(T a,T b,T c){return Min2(Min2(a,b),c);}
template <class T>T Max4(T a,T b,T c,T d){return Max2(Max2(a,b),Max2(c,d));}
template <class T>T Min4(T a,T b,T c,T d){return Min2(Min2(a,b),Max2(c,d));}

using namespace std;

/*
    1 based indexing
    change MAXN and LOGN
    call init()
*/

struct LCA{
    const static int MAXN = 100010;
    const static int LOGN = 20;
    int N;
    int lca[LOGN][MAXN],depth[MAXN];

    void init(int _N,vector<int> G[],int to[]){
        N = _N;
        for(int j=0;j<LOGN;j++)
            for(int i=1;i<=N;i++)
                lca[j][i] = 0;
        dfs(G,to,1,0,1);
        for(int j=1;j<LOGN;j++)
            for(int i=1;i<=N;i++)
                lca[j][i] = lca[j-1][lca[j-1][i]];
    }

    void dfs(vector<int> G[],int to[],int u,int p,int d){
        lca[0][u] = p;
        depth[u] = d;
        for(int i:G[u]){
            int v = to[i];
            if(v!=p)
                dfs(G,to,v,u,d+1);
        }
    }

    int LCAquery(int u,int v){
        if(depth[u]<depth[v])
            swap(u,v);
        int diff = depth[u]-depth[v];
        for(int i=0;i<LOGN;i++)
            if( (diff>>i)&1 )
                u=lca[i][u];
        if(u==v)
            return u;
        for(int j=LOGN-1;j>=0;j--)
            if(lca[j][u]!=lca[j][v])
                u=lca[j][u],
                v=lca[j][v];
        return lca[0][u];
    }
};

int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);



    return 0;
}

