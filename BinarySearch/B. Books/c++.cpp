#include <bits/stdc++.h>

using namespace std;
bool CanReadMBooks(vector<int> a,int M,int n,int t){
    int sum = 0;
    for(int i=0;i<M;i++){
        sum+=a[i];
    }
    if(sum <= t) return true;
    for(int i = M ; i<n;i++){
        sum+=a[i] - a[i - M];
        if(sum <= t) return true;
    }
    return false;
}
int BS(vector<int>a,int n,int t){
    int L = 0;
    int R = n;
    int ans = 0;
    while(L <= R){
        int M = (L + R) / 2;
        if(CanReadMBooks(a,M,n,t)){
          L = M + 1;
          ans = M;
        }
        else R = M - 1;
    }
    return ans;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n,t,x;
    cin>>n>>t;
    vector<int> a;
    for(int i = 0;i<n;i++){
        cin>>x;
        a.push_back(x);
    }
    cout<<BS(a,n,t)<<"\n";
    return 0;
}
