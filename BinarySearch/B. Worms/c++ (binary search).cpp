#include <bits/stdc++.h>

using namespace std;
void BS(int a [],int n,int x){
    int L = 0;
    int R = n - 1;
    int ans = 0;
    while(L <= R){
        int M = (L + R) / 2;
        if(a[M] >= x){
            ans = M;
            R = M - 1;
        }
        else{
            L = M + 1;
        }
    }
    cout<<ans + 1<<"\n";
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n,x;
    cin>>n;
    int a[n];
    cin>>a[0];
    for(int i = 1;i<n;i++){
        cin>>x;
        a[i] = a[i-1] + x;
    }
    int q;
    cin>>q;
    while(q--){
        cin>>x;
        BS(a,n,x);
    }
    return 0;
}
