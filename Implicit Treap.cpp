#include <bits/stdc++.h>

#define LOCAL 0

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
int debug = 0;
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
template<class T>void parr(T a[],int s,int e){cout<<"[";for(int i=s;i<e;i++)cout<<a[i]<<", ";cout<<a[e]<<"]\n";}


namespace Treap{
    struct Node{
        int prior,sz,val;
        struct Node *l,*r;
    };

    int Sz(Node* t){ return t!=NULL?t->sz:0; }
    void UpdSz(Node* t){ if(t)t->sz=Sz(t->l)+1+Sz(t->r); }

    void Split(Node* t,Node* &l,Node* &r,int pos,int add=0){ // 0-based, include pos
        if(!t)return void(l=r=NULL);
        int curr_pos = add + Sz(t->l);
        if(curr_pos<=pos) Split(t->r,t->r,r,pos,curr_pos+1),l=t;
        else Split(t->l,l,t->l,pos,add),r=t;
        UpdSz(t);
    }

    void Merge(Node* &t,Node* l,Node* r){
        if(!l || !r) t = (l==NULL)?r:l;
        else if(l->prior>r->prior)Merge(l->r,l->r,r),t=l;
        else Merge(r->l,l,r->l),t=r;
        UpdSz(t);
    }

    void init(Node* &t,int val){
        t->prior=rand();
        t->sz=1;
        t->val=val;
        t->l=t->r=NULL;
    }

    int getK(Node* root, int k){
        Node *l,*m,*r;
        Split(root, m, r, k);
        Split(m, l, m, k-1);
        int x = m->val;
        Merge(l, l, m);
        Merge(root, l, r);
        return x;
    }
}

int N,Q;
int A[100010];

int main()
{
if(LOCAL){
    freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    debug = 1;
}
    srand (time(NULL));
    //ios::sync_with_stdio(0);cin.tie(0);

    si(N);
    for(int i=1;i<=N;i++)
        si(A[i]);

    Treap::Node *treap = NULL;
    for(int i=1;i<=N;i++){
        Treap::Node* it = new Treap::Node();
        Treap::init(it,A[i]);
        if(i==1)
            treap = it;
        else
            Treap::Merge(treap,treap,it);
    }



    si(Q);
    while(Q--){
        int l1,r1,l2,r2;
        si(l1);si(r1);si(l2);si(r2);
        Treap::Node *l,*m,*r,*b1,*b2;
        l1--;r1--;l2--;r2--;

        Treap::Split(treap,l,r,r2);
        Treap::Split(l,l,b2,l2-1);
        Treap::Split(l,l,m,r1);
        Treap::Split(l,l,b1,l1-1);

        Treap::Merge(treap,l,b2);
        Treap::Merge(treap,treap,m);
        Treap::Merge(treap,treap,b1);
        Treap::Merge(treap,treap,r);

        for(int i=0;i<N;i++)cout<<Treap::getK(treap, i)<<" ";cout<<"\n";
    }

    return 0;
}
