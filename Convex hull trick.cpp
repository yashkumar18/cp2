#include<bits/stdc++.h>

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
int INF = 2147483645;
lli INFINF = 9223372036854775807;
int debug = 0;

using namespace std;

void print(int a[],int s,int e){for(int i=s;i<=e;i++)cout<<a[i]<<" ";cout<<"\n";}
void print(vector<int> &v,int s,int e){for(int i=s;i<=e;i++)cout<<v[i]<<" ";cout<<"\n";}
void print(vector<int> &v){for(int x:v)cout<<x<<" ";cout<<"\n";}

lli bit_count(lli _x){lli _ret=0;while(_x){if(_x%2==1)_ret++;_x/=2;}return _ret;}
lli bit(lli _mask,lli _i){return (_mask&(1<<_i))==0?0:1;}
lli powermod(lli _a,lli _b,lli _m){lli _r=1;while(_b){if(_b%2==1)_r=(_r*_a)%_m;_b/=2;_a=(_a*_a)%_m;}return _r;}
lli add(lli a,lli b,lli m=MOD){lli x=a+b;while(x>=m)x-=m;return x;}
lli sub(lli a,lli b,lli m=MOD){lli x=a-b;while(x<0)x+=m;return x;}
lli mul(lli a,lli b,lli m=MOD){lli x=a*b;x%=m;return x;}

/*
    line = a*x + b
    insert line with insert_line(a,b)
    for given x, use evaluate(x)
    change isMax for MIN/MAX
    change fft,retlls,retll
*/

class CHT // Convex hull trick
{
    typedef ld fft;
    typedef ld retlls;
    typedef ld retll;
    bool isMax = false;

    public:

    CHT(){
    }

    struct line_segment{
        fft a, b;
        double xLeft;
        enum Type {line, maxQuery, minQuery} type;
        retlls val;
        explicit line_segment(fft aa=0, fft bb=0) : a(aa), b(bb), xLeft(-INFINITY), type(Type::line), val(0) {}
        retll valueAt(retlls x) const { return a*x+b; }
        friend bool dont_meet(const line_segment& l1, const line_segment& l2) { return l1.a==l2.a; }
        friend double meet(const line_segment& l1, const line_segment& l2) { return dont_meet(l1,l2)?INFINITY:1.0*(l2.b-l1.b)/(l1.a-l2.a); }
        bool operator<(const line_segment& l2) const{
            if (l2.type == line)return this->a     < l2.a;
            if (l2.type == maxQuery)return this->xLeft < l2.val;
            if (l2.type == minQuery)return this->xLeft > l2.val;
        }
    };
    set<line_segment>  slopes;
    bool hasPrev(set<line_segment>::iterator it) { return it!=slopes.begin(); }
    bool hasNext(set<line_segment>::iterator it) { return it!=slopes.end() && next(it)!=slopes.end(); }
    bool bad(const line_segment& l1, const line_segment& l2, const line_segment& l3) { return meet(l1,l3) <= meet(l1,l2); }
    bool bad(set<line_segment>::iterator it){
        return hasPrev(it) && hasNext(it)&& (    isMax && bad(*prev(it), *it, *next(it))|| !isMax && bad(*next(it), *it, *prev(it)) );
    }
    set<line_segment>::iterator fix(set<line_segment>::iterator it){
        if (isMax && !hasPrev(it) || !isMax && !hasNext(it))return it;
        double val = meet(*it, isMax?*prev(it):*next(it));
        line_segment buf(*it);it = slopes.erase(it);
        buf.xLeft = val;it = slopes.insert(it, buf);
        return it;
    }
    void insert_Line(fft a, fft b){
        line_segment l3 = line_segment(a, b);
        auto it = slopes.lower_bound(l3);
        if (it!=slopes.end() && dont_meet(*it, l3)){
            if (isMax && it->b < b || !isMax && it->b > b)it = slopes.erase(it);
            else return;
        }
        it = slopes.insert(it, l3);
        if (bad(it)) { slopes.erase(it); return; }
        while (hasPrev(it) && bad(prev(it))) slopes.erase(prev(it));
        while (hasNext(it) && bad(next(it))) slopes.erase(next(it));
        it = fix(it);
        if (hasPrev(it))fix(prev(it));
        if (hasNext(it))fix(next(it));
    }
    retll evaluate(retlls x) const{
        if(slopes.empty())assert(false);
        line_segment q;q.val = x;
        q.type = isMax ? line_segment::Type::maxQuery : line_segment::Type::minQuery;
        auto bestLine = slopes.lower_bound(q);
        if (isMax) --bestLine;
        return bestLine->valueAt(x);
    }
};


int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    debug = 1;
#endif
    srand (time(NULL));



    return 0;
}

