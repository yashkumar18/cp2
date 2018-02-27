/*
By : Yash Kumar
Dhirubhai Ambani Institute Of Information And Communication Technology, Gandhinagar (DA-IICT GANDHINAGAR)
1st Year ICT BTECH student
*/
#include<bits/stdc++.h>

#define lli long long int
#define llu unsigned long long int

const double EPS = 1e-24;
const lli MOD = 1000000007ll;
const double PI = 3.14159265359;
int INF = 2147483645;

template <class T>T Max2(T a,T b){return a<b?b:a;}
template <class T>T Min2(T a,T b){return a<b?a:b;}
template <class T>T Max3(T a,T b,T c){return Max2(Max2(a,b),c);}
template <class T>T Min3(T a,T b,T c){return Min2(Min2(a,b),c);}
template <class T>T Max4(T a,T b,T c,T d){return Max2(Max2(a,b),Max2(c,d));}
template <class T>T Min4(T a,T b,T c,T d){return Min2(Min2(a,b),Max2(c,d));}

using namespace std;

int N,M;
int a[110];
int b[110];
int ans[110][110];

struct FordFulkerson
{
    int N;
    vector<vector<int> >G;
    vector<bool> vis;
    vector<int> parent;
    int source,sink;

    void init(int _N,int _source,int _sink)
    {
        N=_N;
        vector<int> _v1(_N+1,0);
        vector<bool> _v2(_N+1,false);
        for(int i=0;i<=_N;i++)
            G.push_back(_v1);
        source=_source;
        sink=_sink;
        vis=_v2;
        parent=_v1;
    }

    void addEgde(int _u,int _v,int _w)
    {
        G[_u][_v]=_w;
    }

    bool bfs()
    {
        for(int i=1;i<=N;i++)
            vis[i]=false;

        queue<int> Q;
        Q.push(source);
        vis[source]=true;
        parent[source]=-1;

        while(!Q.empty())
        {
            int u=Q.front();
            Q.pop();
            if(u==sink)
                break;

            for(int i=1;i<=N;i++)
            {
                if(!vis[i] && G[u][i]>0)
                {
                    vis[i]=true;
                    parent[i]=u;
                    Q.push(i);
                }
            }
        }
        return vis[sink];
    }

    int maxflow()
    {
        int flow=0;
        while(bfs())
        {
            int tempflow=INF+1;
            int u;
            for(int v=sink;v!=source;v=parent[v])
            {
                u=parent[v];
                tempflow=Min2(tempflow,G[u][v]);
            }
            for(int v=sink;v!=source;v=parent[v])
            {
                u=parent[v];
                G[u][v]-=tempflow;
                G[v][u]+=tempflow;
            }
            flow+=tempflow;
        }
        return flow;
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

