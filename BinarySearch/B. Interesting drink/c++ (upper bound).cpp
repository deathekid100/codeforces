#include <bits/stdc++.h>

using namespace std;

int main()
{
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
        int xx = upper_bound(a.begin(),a.end(),x) - a.begin();
        cout<<xx<<"\n";
    }
    return 0;
}
