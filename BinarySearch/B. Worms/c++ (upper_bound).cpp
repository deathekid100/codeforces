#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n,x;
    cin>>n;
    vector<int>a(n);
    fill(a.begin(),a.end(),0);
    for(int i = 0;i<n;i++){
        cin>>x;
        a[i] = i == 0 ? x: a[i-1] + x;
    }
    int q;
    cin>>q;
    while(q--){
        cin>>x;
        int ans = upper_bound(a.begin(),a.end(),x) - a.begin();
        if(a[ans - 1] != x) ans++;
        cout<<ans<<"\n";
    }
    return 0;
}
