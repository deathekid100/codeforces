#include <bits/stdc++.h>

using namespace std;
int BS(vector<int>a,int x){
    int ans = 0;
    int l = 0;
    int r = a.size() - 1;
    while(l <= r){
        int m = (l + r) / 2;
        if(a[m] <= x){
            ans = m +1;
            l = m + 1;
        }
        else{
            r = m - 1;
        }
    }
    return ans;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n,q,x;
    cin>>n;
    vector<int> a;
    for(int i=0;i<n;i++){
        cin>>q;
        a.push_back(q);
    }
    sort(a.begin(),a.end());
    cin>>q;
    while(q--){
        cin>>x;
        cout<<BS(a,x)<<"\n";
    }
    return 0;
}
