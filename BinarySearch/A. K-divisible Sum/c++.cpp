#include<bits/stdc++.h>
using namespace std;
typedef unsigned long long LL;
LL divInRange(LL min, LL max, LL k) {
	min--;
	return max / k - (min / k);
}
LL BS(LL n, LL k) {
	LL L = 1;
	LL R = n*k;
	LL ans = 0;
	while (L <= R) {
		LL M = (L + R) / 2;
		LL min = n + M - 1;
		LL max = n * M;
		LL count = divInRange(min, max, k);

		if (count > 0) {
			ans = M;
			R = M - 1;
		}
		else {
			L = M + 1;
		}
	}
	return ans;
}
int main()
{
	LL t, n, k;
	cin >> t;
	while (t--) {
		cin >> n >> k;
		cout << BS(n, k) << "\n";
	}
}