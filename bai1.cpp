#include <iostream>
#include <vector>
#include <algorithm>
#include <limits>

using namespace std;

const int MAXN = 30;
const int INF = numeric_limits<int>::max();

int n, m, k;
int cost[MAXN + 1][MAXN + 1];
int nodes[MAXN + 1];
int dp[(1 << MAXN) + 1];

int main()
{
    // Nhập input
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            cost[i][j] = INF;
        }
    }
    for (int i = 0; i < m; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        cost[u][v] = cost[v][u] = w;
    }
    cin >> k;
    for (int i = 0; i < k; i++)
    {
        cin >> nodes[i];
    }

    // Khởi tạo dp
    for (int i = 0; i < (1 << k); i++)
    {
        dp[i] = INF;
    }
    for (int i = 0; i < k; i++)
    {
        dp[1 << i] = 0;
    }

    // Tính toán dp
    for (int mask = 1; mask < (1 << k); mask++)
    {
        for (int i = 0; i < k; i++)
        {
            if ((mask & (1 << i)) == 0)
            {
                continue;
            }
            for (int j = i + 1; j < k; j++)
            {
                if ((mask & (1 << j)) == 0)
                {
                    continue;
                }
                int submask = mask ^ (1 << i) ^ (1 << j);
                dp[mask] = min(dp[mask], dp[submask] + cost[nodes[i]][nodes[j]]);
            }
        }
    }

    // In kết quả
    cout << dp[(1 << k) - 1] << endl;

    return 0;
}
