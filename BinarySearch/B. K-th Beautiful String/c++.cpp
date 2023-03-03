#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
LL arr[100002];
LL GetL(LL n, LL k) {
	int x = lower_bound(arr, arr + 100001,k) - arr;
	return x;
}
int main()
{
	arr[0] = 0;
	for (int i = 1; i < 100002; i++) {
		arr[i] = arr[i-1] + i;
	}
	int t, n;
	LL k;
	cin >> t;
	while (t--) {
		cin >> n >> k;
		LL L = GetL(n, k);
		LL lower = (L * (L - 1)) / 2LL;
		LL R = k - lower;
		L = n - L - 1;
		R = n - R;
		string s(n, 'a');
		s[L] = s[R] = 'b';
		cout <<s <<"\n";
	}
}