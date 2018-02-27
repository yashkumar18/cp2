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

struct PalindromicTree{
    const static int SZ = 26;
    struct node{
        /*
        s,e,len - start, end, length of this palindrome
        sufflink - index of maximum suffix palindrome node
        cnt - number of occurrence of this palindrome in the string
        */
        int next[SZ];
        int len, sufflink, s, e, cnt;
    };
    int N, tot, suff; // tot - count of nodes in tree, suff - idx of max suffix palindromic node after addition of letter
    string s;
    vector<node> tree;

    void init(string _s){
        s = _s;
        N = s.size();
        tree.resize(3);
        tot = 2; suff = 2;
        tree[1].len = -1; tree[1].sufflink = 1;
        tree[2].len = 0; tree[2].sufflink = 1;

        for (int i=0;i<N;i++) {
            bool success = addLetter(i);
            tree[suff].cnt ++;
        }
        for(int i=tot;i>=3;i--){
            tree[tree[i].sufflink].cnt += tree[i].cnt;
        }
    }

    bool addLetter(int pos) {
        int cur = suff, curlen = 0;
        int let = s[pos] - 'a';

        while (true) {
            curlen = tree[cur].len;
            if (pos - 1 - curlen >= 0 && s[pos - 1 - curlen] == s[pos])
                break;
            cur = tree[cur].sufflink;
        }
        if (tree[cur].next[let]) {
            suff = tree[cur].next[let];
            return false;
        }

        tot++;
        tree.pb(*(new node()));
        suff = tot;
        tree[tot].len = tree[cur].len + 2;
        tree[tot].e = pos; tree[tot].s = pos - tree[tot].len + 1;
        tree[cur].next[let] = tot;

        if (tree[tot].len == 1) {
            tree[tot].sufflink = 2;
            return true;
        }

        while (true) {
            cur = tree[cur].sufflink;
            curlen = tree[cur].len;
            if (pos - 1 - curlen >= 0 && s[pos - 1 - curlen] == s[pos]) {
                tree[tot].sufflink = tree[cur].next[let];
                break;
            }
        }
        return true;
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
