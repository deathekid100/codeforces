#include <bits/stdc++.h>

using namespace std;
int r, c;
int M[101][101];
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};
typedef pair<int, int> pi;
typedef pair<int, pi> node;
struct CompareNode
{
    bool operator()(const node &n1, const node &n2)
    {
        return n1.first > n2.first;
    }
};
bool check(int i, int j)
{
    return (i >= 0 && i < r && j >= 0 && j < c);
}

int BFS(int i, int j)
{
    bool mark[101][101];
    memset(mark, false, sizeof(mark));
    int cont = 0;
    priority_queue<node, vector<node>, CompareNode> pq;
    node x = {M[i][j], {i, j}};
    pq.push(x);
    mark[i][j] = true;
    while (!pq.empty())
    {
        cont++;
        node xi = pq.top();
        pq.pop();
        pi pos = xi.second;

        int val = xi.first;
        for (int i = 0; i < 4; i++)
        {
            int fx = pos.first + dx[i];
            int fy = pos.second + dy[i];
            if (check(fx, fy))
            {
                if (!mark[fx][fy])
                {
                    if (M[fx][fy] > val)
                    {
                        pq.push({M[fx][fy], {fx, fy}});
                        mark[fx][fy] = true;
                    }
                }
            }
        }
    }
    return cont;
}

int main()
{

    cin >> r >> c;
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            cin >> M[i][j];
        }
    }
    int ans = 0;
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            ans = max(ans, BFS(i, j));
        }
    }
    cout << ans << "\n";
    return 0;
}