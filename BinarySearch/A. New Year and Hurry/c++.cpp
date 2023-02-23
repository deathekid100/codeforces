//Binary Search https://codeforces.com/problemset/problem/750/A
#include <bits/stdc++.h>

using namespace std;

int calc(int p , int k){
   return k + (5 * p * (p + 1))/2;
}
int BS(int n,int k){
    int ans = 0;
    int l = 0;
    int r = n;

    while(l <= r){
        int m = (l + r) /2;
        int c = calc(m,k);
        if(c == 240) return m;
        if(c < 240){
            ans = m;
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
    int n,k;
    cin>>n>>k;
    cout<<BS(n,k);
    return 0;
}
