#include <bits/stdc++.h>

using namespace std;

string s;
int n, R, C;
vector<string> M;
bool mark[1001][1001];

bool fit(int i, int j) {
    for (int k = 0; k < n; k++) {
        if (s[k] == '1' && M[j][(i + k) % n] == '1') {
            return false;
        }
    }
    return true;
}

bool DFSStack(int xi, int xj) {
    stack<pair<int, int>> st;
    st.push({xi, xj});

    while (!st.empty()) {
        pair<int, int> p = st.top();
        st.pop();
        int i = p.first;
        int j = p.second;
        mark[i][j] = true;
        if (j == R - 1) {
            return true;
        }

        //up
        int J = j - 1;
        if (J >= 0) {
            if (!mark[i][J] && fit(i, J)) {
                st.push({i, J});
            }
        }

        //right
        int I = (i + 1) % n;
        if (!mark[I][j] && fit(I, j)) {
            st.push({I, j});
        }

        //left
        I = (i - 1 + n) % n;
        if (!mark[I][j] && fit(I, j)) {
            st.push({I, j});
        }

        J = j + 1;
        if (J < R) {
            if (!mark[i][J] && fit(i, J)) {
                st.push({i, J});
            }
        }
    }
    return false;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    string a;
    cin >> R >> C >> s;
    n = C;
    for (int i = 0; i < R; i++) {
        cin >> a;
        M.push_back(a);
    }

    for (int i = 0; i < n; i++) {
        if (fit(i, 0)) {
            bool ans = DFSStack(i, 0);
            if (ans) {
                cout << "Y\n";
                return 0;
            }
        }
    }

    memset(mark, false, sizeof(mark));

    reverse(s.begin(), s.end());

    for (int i = 0; i < n; i++) {
        if (fit(i, 0)) {
            bool ans = DFSStack(i, 0);
            if (ans) {
                cout << "Y\n";
                return 0;
            }
        }
    }

    cout << "N\n";
    return 0;
}
