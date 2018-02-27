#include<bits/stdc++.h>

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
const lli MOD = 1000000007ll;
const lli mod1 = 1000000009ll;
const lli mod2 = 1100000009ll;
int INF = (int)1e9;
lli INFINF = (lli)1e18;
int debug = 0;

using namespace std;

void print(int a[],int s,int e){for(int i=s;i<=e;i++)cout<<a[i]<<" ";cout<<"\n";}
void print(vector<int> &v,int s,int e){for(int i=s;i<=e;i++)cout<<v[i]<<" ";cout<<"\n";}
void print(vector<int> &v){for(int x:v)cout<<x<<" ";cout<<"\n";}

lli bit_count(lli _x){lli _ret=0;while(_x){if(_x%2==1)_ret++;_x/=2;}return _ret;}
lli bit(lli _mask,lli _i){return (_mask&(1<<_i))==0?0:1;}
lli powermod(lli _a,lli _b,lli _m){lli _r=1;while(_b){if(_b%2==1)_r=(_r*_a)%_m;_b/=2;_a=(_a*_a)%_m;}return _r;}
lli add(lli a,lli b,lli m=MOD){lli x=a+b;while(x>=m)x-=m;return x;while(x<0)x+=m;return x;}
lli sub(lli a,lli b,lli m=MOD){lli x=a-b;while(x<0)x+=m;return x;while(x>=m)x-=m;return x;}
lli mul(lli a,lli b,lli m=MOD){lli x=a*b;x%=m;return x;}

using namespace std;

/*
    0-based matrix
*/

struct matrix{
    int SZ;
    vector<vector<lli> > arr;
    void init(int _N){
        SZ = _N;
        arr.resize(SZ);
        for(int i=0;i<SZ;i++)
            arr[i].resize(SZ);
    }
    void reset(){
        for(int i=0;i<SZ;i++)
            for(int j=0;j<SZ;j++)
                arr[i][j] = 0;
    }
    void makeidentity(){
        reset();
        for(int i=0;i<SZ;i++)
            arr[i][i] = 1;
    }
    matrix operator + (const matrix &o) const {
        matrix res;
        res.init(SZ);
        res.reset();
        for(int i=0;i<SZ;i++)
            for(int j=0;j<SZ;j++)
                res.arr[i][j] = add(arr[i][j] , o.arr[i][j]);
        return res;
    }
    matrix operator * (const matrix &o) const {
        matrix res;
        res.init(SZ);
        res.reset();
        for(int i=0;i<SZ;i++)
            for(int j=0;j<SZ;j++)
                for(int k=0;k<SZ;k++)
                    res.arr[i][j] = add(res.arr[i][j] , mul(arr[i][k] , o.arr[k][j]));
        return res;
    }
};

matrix matrixexpo(matrix a , lli b){
    matrix res;
    res.init(a.SZ);
    res.makeidentity();
    while(b){
        if(b & 1){
            res = res * a;
        }
        a = a * a;
        b >>= 1;
    }
    return res;
}

int nthfibo(lli N){
    if(N <= 2)
        return 1;
    matrix mmm;
    mmm.init(2);
    mmm.arr[0][0] = 1;
    mmm.arr[0][1] = 1;
    mmm.arr[1][0] = 1;
    mmm.arr[1][1] = 0;
    mmm = matrixexpo(mmm,N-2);
    return add(mmm.arr[0][0],mmm.arr[0][1]);
}

/*
    for doubles
*/
struct matrix{
    int SZ;
    vector<vector<ld> > arr;
    void init(int _N){
        SZ = _N;
        arr.resize(SZ);
        for(int i=0;i<SZ;i++)
            arr[i].resize(SZ);
    }
    void reset(){
        for(int i=0;i<SZ;i++)
            for(int j=0;j<SZ;j++)
                arr[i][j] = 0;
    }
    void makeidentity(){
        reset();
        for(int i=0;i<SZ;i++)
            arr[i][i] = 1;
    }
    matrix operator + (const matrix &o) const {
        matrix res;
        res.init(SZ);
        res.reset();
        for(int i=0;i<SZ;i++)
            for(int j=0;j<SZ;j++)
                res.arr[i][j] = arr[i][j] + o.arr[i][j];
        return res;
    }
    matrix operator * (const matrix &o) const {
        matrix res;
        res.init(SZ);
        res.reset();
        for(int i=0;i<SZ;i++)
            for(int j=0;j<SZ;j++)
                for(int k=0;k<SZ;k++)
                    res.arr[i][j] = res.arr[i][j] + (arr[i][k]*o.arr[k][j]);
        return res;
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

