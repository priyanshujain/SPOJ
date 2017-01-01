/*
Author - Priyanshu Jain
*/
//#include <atomic>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <algorithm>
#include <cassert>
#include <cstring>
using namespace std;


#define mod 1000000007
#define inf 100000000000000000LL
#define pb push_back
#define mp make_pair
struct _{ios_base::Init i; _(){
  cin.sync_with_stdio(0);
  cin.tie(0);cout.tie(0);
}}_ ;
typedef long long int  ll;
#define pll pair<ll,ll>
#define ict int t;cin>>t;while(t--)
#define rep(i,n) for(ll i=0;i<n;i++)
#define repi(i,a,b) for(ll i=a;i<=b;i++)
#define ain(A, B, C) assert(IN(A, B, C))
#define ull unsigned long long int
#define pii pair<int,int>
#define MAXX 20500
#define fr(a,b,i) for(int i=a;i<b;i++)
#define dbg(x) cout<<"Here we are "<<x<<"\n"
vector<pair<int,int> >G[MAXX];
#pragma comment(linker, "/STACK:1000000000")
#define init(Arr) memset((Arr), 0, sizeof (Arr))

static int BIT[MAXX+1], ANS[MAXX], N, T;
inline void update(int i, int v){
    for (; i<=MAXX; i+=(i & -i)) BIT[i]+=v;
}
inline int query(int i){
    int ans=0;
    for (; i>0; i-=(i & -i)) ans+=BIT[i];
    return ans;
}

int main()
{
    scanf("%d", &T);
    while(T--){
        init(BIT); init(ANS);
        scanf("%d", &N);
        for (int i=1; i<=N; ++i) update(i, 1);
        int M=N, L=1, s, e;

        for(int i=1; i<=N; ++i){
            L= (L+i)%M;
            L= (!L)? M: L; M--;

            s=1; e=N;
            while(s<=e){
                int mid = (s+e)>>1;
                if (query(mid)>=L) e=mid-1;
                else if (query(mid)<L) s=mid+1;
            }
            ANS[s]=i; update(s, -1);
        }
        for(int i=1; i<=N; ++i) printf("%d ", ANS[i]);
        printf("\n");
    }
    return 0;
}
