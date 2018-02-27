/*
By : Yash Kumar
Dhirubhai Ambani Institute Of Information And Communication Technology, Gandhinagar (DA-IICT GANDHINAGAR)
2nd Year ICT BTECH student
*/
#include<bits/stdc++.h>

#define lli long long int
#define llu unsigned long long int
#define all(v) v.begin(),v.end()
#define pb push_back
#define mp make_pair
#define F first
#define S second
#define si(n) scanf("%d",&n)
#define slli(n) scanf("%lld",&n);
#define ss(n) scanf("%s",n);

const double EPS = 1e-10;
const lli MOD = 1000000007ll;
const lli mod1 = 1000000009ll;
const lli mod2 = 1100000009ll;
const double PI = 3.14159265359;
int INF = 2147483645;
lli INFINF = 9223372036854775807;
int debug = 0;

template <class T>T Max2(T a,T b){return a<b?b:a;}
template <class T>T Min2(T a,T b){return a<b?a:b;}
template <class T>T Max3(T a,T b,T c){return Max2(Max2(a,b),c);}
template <class T>T Min3(T a,T b,T c){return Min2(Min2(a,b),c);}
template <class T>T Max4(T a,T b,T c,T d){return Max2(Max2(a,b),Max2(c,d));}
template <class T>T Min4(T a,T b,T c,T d){return Min2(Min2(a,b),Min2(c,d));}

using namespace std;

lli bit_count(lli _x){lli _ret=0;while(_x){if(_x%2==1)_ret++;_x/=2;}return _ret;}
lli bit(lli _mask,lli _i){return (_mask&(1<<_i))==0?0:1;}
lli powermod(lli _a,lli _b,lli _m){lli _r=1;while(_b){if(_b%2==1)_r=(_r*_a)%_m;_b/=2;_a=(_a*_a)%_m;}return _r;}
lli add(lli a,lli b){lli x=a+b;if(x>MOD)x-=MOD;return x;}
lli sub(lli a,lli b){lli x=a-b;if(x<0)x+=MOD;return x;}
lli mul(lli a,lli b){lli x=a*b;x%=MOD;return x;}

/*
    change MAXN - size of array on which segment tree is built
    see main() to know how to construct the tree
    sumquery() returns numbers between x to y in range (prev+1 to curr)
    kthquery() returns the kth number in the range (prev+1 to curr)
*/

namespace PST{
    struct Node{
        int cnt;
        Node *l,*r;
        Node(){
            cnt = 0;
            l = r = NULL;
        }
    };
    const int MAXN = 100010;
    Node *root[MAXN];

    void build(Node *curr,int s,int e){
        if(s==e){
            return;
        }
        else{
            int mid=(s+e)>>1;
            curr->l=new Node();
            curr->r=new Node();
            build(curr->l,s,mid);
            build(curr->r,mid+1,e);
        }
    }

    void makeTree(Node* prev,Node*curr,int s,int e,int x){
        if(s==e){
            curr->cnt=prev->cnt+1;
            return;
        }
        int mid=(s+e)>>1;
        if(x<=mid){
            curr->l=new Node();
            curr->cnt=prev->cnt+1;
            curr->r=prev->r;
            makeTree(prev->l,curr->l,s,mid,x);
        }
        else{
            curr->r=new Node();
            curr->cnt=prev->cnt+1;
            curr->l=prev->l;
            makeTree(prev->r,curr->r,mid+1,e,x);
        }
    }

    int sumquery(Node* prev,Node* curr,int s,int e,int x,int y){
        if(s==x && e==y)
            return curr->cnt-prev->cnt;
        int mid=(s+e)>>1;
        if(y<=mid)
            return sumquery(prev->l,curr->l,s,mid,x,y);
        else if(x>mid)
            return sumquery(prev->r,curr->r,mid+1,e,x,y);
        return sumquery(prev->l,curr->l,s,mid,x,mid)+sumquery(prev->r,curr->r,mid+1,e,mid+1,y);
    }

    int kthquery(Node* prev,Node* curr,int s,int e,int k){
        if(s==e)
            return s;
        int mid=(s+e)>>1;
        int l = curr->l->cnt - prev->l->cnt;
        if(k<=l)
            return kthquery(prev->l,curr->l,s,mid,k);
        else
            return kthquery(prev->r,curr->r,mid+1,e,k-l);
    }
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    debug = 1;
#endif
    srand (time(NULL));

    int a[5]={9,8,2,7,5};

    PST::root[0] = new PST::Node();
    PST::build(PST::root[0],0,9); //  0, 9 - range of numbers, and not the size of array, this is range of elements
    for(int i=1;i<5;i++){
        PST::root[i] = new PST::Node();
        PST::makeTree(PST::root[i-1],PST::root[i],0,9,a[i]);
    }


    return 0;
}

