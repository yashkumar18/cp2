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

vector<ld> gaussianElimination(vector<vector<ld> > &a){
    int N = a.size();
    for (int k=0; k<N; k++){
        int imax = k;
        ld vmax = a[imax][k];
        for (int i = k+1; i < N; i++)
            if (fabs(a[i][k]) > vmax)
                vmax = a[i][k], imax = i;
        if (imax != k)
            for(int i=0;i<=N;i++)
                swap(a[k][i] , a[imax][i]);

        for (int i=k+1; i<N; i++){
            ld f = a[i][k]/a[k][k];
            for (int j=k+1; j<=N; j++)
                a[i][j] -= a[k][j]*f;
            a[i][k] = 0;
        }
    }
    vector<ld> x(a.size());
    for (int i = N-1; i >= 0; i--){
        x[i] = a[i][N];
        for (int j=i+1; j<N; j++)
            x[i] -= a[i][j]*x[j];
        x[i] = x[i]/a[i][i];
    }
    return x;
}

int main()
{
if(LOCAL){
    freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
}
    srand (time(NULL));
    //ios::sync_with_stdio(0);cin.tie(0);
    /*
     2x + y -  z =   8
    -3x - y + 2z = -11
    -2x + y + 2z =  -3
    */
    vector<vector<ld> > a = {
                    {2,1,-1,8},
                    {-3,-1,2,-11},
                    {-2,1,2,-3}};

    vector<ld> x = gaussianElimination(a);
    for(auto it : x) cout<<it<<" ";cout<<"\n";

    return 0;
}
