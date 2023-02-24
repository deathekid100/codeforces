#include<bits/stdc++.h>
using namespace std;
typedef unsigned long long LL;
LL pow3[1000001];
void Pre() {
	for (LL i = 0; i < 1000001; i++)
	{
		pow3[i] = i * i * i;
	}
}
bool isPow3(LL n) {
	if (n <= 0)return 0;
	int x = lower_bound(pow3, pow3 + 1000001, n) - pow3;
	return pow3[x] == n;
}
void Search(LL n) {
	int x = pow(n, 1 / 3.00000);
	for (int i = 1; i <= x; i++)
	{
		LL pi = pow3[i];
		LL R = n - pi;
		if (isPow3(R)) {
			cout << "YES\n";
			return;
		}
	}
	cout << "NO\n";
}
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	Pre();
	LL t, n;;
	cin >> t;
	while (t--) {
		cin >> n;
		Search(n);
	}
}