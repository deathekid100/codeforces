#include<bits/stdc++.h>
using namespace std;
int Sum[4][200001];
bool Can(int i, int j) {
	int s1 = Sum[1][j] - Sum[1][i - 1];
	int s2 = Sum[2][j] - Sum[2][i - 1];
	int s3 = Sum[3][j] - Sum[3][i - 1];
	return s1 > 0 && s2 > 0 && s3 > 0;
}
int BS(string s) {
	// pre
	for (int i = 0; i < s.length(); i++) {
		int x = s[i] - 48;
		Sum[1][i] = Sum[1][i-1];
		Sum[2][i] = Sum[2][i-1];
		Sum[3][i] = Sum[3][i-1];
		Sum[x][i] ++;
	}
	if (!Can(0, s.length() - 1)) return 0;


	int mx = INT_MAX;
	
	for (int i = 0; i < s.length(); i++)
	{
		int L = i;
		int R = s.length() - 1;
		while (L <= R) {
			int M = (L + R) / 2;
			if (Can(i, M)) {
				R = M - 1;
				mx = min(mx, M - i + 1);
				if (mx == 3) return 3;
			}
			else {
				L = M + 1;
			}
		}
	}
	return mx;


}
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int t;
	string s;
	cin >> t;
	while (t--) {
		cin >> s;
		cout << BS(s) << "\n";
	}
}