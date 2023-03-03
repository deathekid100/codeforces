#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
LL arr[100002];
LL GetL(LL n) {
	int x = upper_bound(arr, arr + 100001, n) - arr;
	return x;
}
int main()
{
	arr[0] = 2;
	for (int i = 1; i < 100002; i++) {
		arr[i] = arr[i - 1] + 3*i + 2;
	}
	
	int t, n;
	LL k;
	cin >> t;
	while (t--) {
		cin >> n;
		int c = 0;
		while (n > 1)
		{
			c++;
			LL L = GetL(n);
			n -= arr[L - 1];
		}
		cout << c << "\n";
	}
}