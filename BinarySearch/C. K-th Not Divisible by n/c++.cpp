#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
ll kth(ll M, ll n){
    return M - M/n;
}
ll BS(ll n,ll k){
    ll L = 1;
    ll R = n*k;
    while(L <= R){
        ll M = (L + R)/ 2;
        ll K = kth(M,n);
        if(K == k && M%n !=0) return M;
        if(K < k) L = M + 1;
        else R = M - 1;
    }
    return 0;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    ll n,k,t;
    cin>>t;
    while(t--){
        cin>>n>>k;
        cout<<BS(n,k)<<"\n";
    }
    return 0;
}
