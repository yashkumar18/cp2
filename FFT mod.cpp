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

namespace FFT {
    lli gcd(lli a, lli b, lli c, lli d, lli e, lli f, lli& o, lli& p){
        if(b==0){
            o=c;
            p=e;
            return a;
        }
        lli k=a/b;
        return gcd(b, a-b*k, d, c-d*k, f, e-f*k, o, p);
    }

    lli modinv(lli a, lli b){
        lli c, d;
        gcd(a, b, 1, 0, 0, 1, c, d);
        return (c+b)%b;
    }

    lli primitive_root(lli X) {
        vector<lli> prime_factors, test;
        lli factor=2;
        lli S=X-1;
        while(factor*factor<=S) {
            if(S%factor==0) {
                prime_factors.push_back(factor);
                while(S%factor==0)
                    S/=factor;
            }
            factor++;
        }
        if(S>1)
            prime_factors.push_back(S);
        for(size_t i=0; i<prime_factors.size(); i++)
            test.push_back((X-1)/prime_factors[i]);
        for(lli ret=2; ret<X; ret++) {
            bool good=true;
            for(size_t i=0; i<test.size(); i++)
                if(powermod(ret, test[i], X)==1) {
                    good=false;
                    break;
                }
            if(good)
                return ret;
        }
        return -1;
    }

    lli nth_root_of_unity(lli n, lli pr, lli MOD) {
        return powermod(pr, (MOD-1)/n, MOD);
    }

    int calc_max_pow2(lli X) {
        int ret=0;
        while(X%2==0)
            ret++, X/=2;
        return ret;
    }

    const lli MOD=924844033;
    const lli ROOT=primitive_root(MOD);
    const lli IROOT=modinv(ROOT, MOD);
    const int EXP=calc_max_pow2(MOD-1);

    void fft(int n, lli *A, bool invert) {
        int lgn=0;
        while((1<<lgn)<n)
            lgn++;
        for(int i=0; i<n; i++) {
            int x=0;
            for(int j=0; j<lgn; j++)
                x|=((i>>j)&1)<<(lgn-j-1);
            if(i<x)
                swap(A[i], A[x]);
        }
        lli rt=nth_root_of_unity(1<<EXP, invert?IROOT:ROOT, MOD);
        lli *w=new lli[1<<(lgn-1)];
        w[0]=1;
        for(int i=1; i<=lgn; i++)
        {
            int len=1<<i;
            int hlen=len/2;
            // powmod(lenroot, len, MOD) == 1
            lli lenroot=rt;
            for(int j=i; j<EXP; j++)
                lenroot=((lli)lenroot*lenroot)%MOD;
            for(int j=1; j<hlen; j++)
                w[j]=((lli)w[j-1]*lenroot)%MOD;
            for(int j=0; j<n; j+=len)
            {
                for(int k=0; k<hlen; k++)
                {
                    lli u=A[j+k], v=((lli)A[j+k+hlen]*w[k])%MOD;
                    lli tmp=(lli)u+v;
                    if(tmp>=MOD)
                        tmp-=MOD;
                    A[j+k]=tmp;
                    tmp=(lli)u-v;
                    if(tmp<0)
                        tmp+=MOD;
                    A[j+k+hlen]=tmp;
                }
            }
        }
        delete[] w;
        if(invert)
        {
            lli minv=modinv(n, MOD);
            for(int i=0; i<n; i++)
                A[i]=((lli)A[i]*minv)%MOD;
        }
    }

    void convolve(int n, lli *A, lli *B, lli *C) {
        fft(n, A, false);
        fft(n, B, false);
        for(int i=0; i<n; i++)
            C[i]=((lli)A[i]*(lli)B[i])%MOD;
        fft(n, C, true);
    }

    void multiply(vector<lli>& _a, vector<lli>& _b, vector <lli> &c) {
        int n=_a.size();
        int logn=1;
        while((1<<logn)<n)
            logn++;
        logn++;
        n=1<<logn;
        _a.resize(n);
        _b.resize(n);
        static vector<lli> a, b;
        a=_a, b=_b;
        c.resize(n);
        convolve(n, a.data(), b.data(), c.data());
    }
}

int main()
{
if(LOCAL){
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
}
    srand (time(NULL));
    //ios::sync_with_stdio(0);cin.tie(0);



    return 0;
}
