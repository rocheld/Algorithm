#include <iostream>
#include <queue>
#include <algorithm>
#include <climits>

using namespace std;
const int max_width = 50;
const int max_virus = 10;
const int dx[4] = {-1, 1, 0, 0};
const int dy[4] = {0, 0, -1, 1};
typedef pair<int, int> pos;
int width, v_cnt, k, space, ans;
pos virus[max_virus];
int order[max_virus];
queue<pos> que;
int map[max_width][max_width];

/*
void permutation(int l)
{

    if (l == v_cnt)
    {
        int ret = bfs();
        if (ret != -1)
            ans = min(ans, ret);
        return;
    }

    for (int i = l; i < v_cnt; i++)
    {
        swap(virus[i], virus[l]);
        permutation(l + 1);
        swap(virus[i], virus[l]);
    }
}
void permutation2()
{
    do
    {
        for (int i = 0; i < v_cnt; i++)
        {
            cout << virus[i].first << "," << virus[i].second << " ";
        }
        cout << endl;

    } while (next_permutation(virus, virus + v_cnt));
}
*/
bool check_range(int y, int x)
{
    if (y < 0 || x < 0 || y >= width || x >= width || map[y][x] == 1)
        return false;
    else
        return true;
}

int bfs()
{
    int time_stamp[width][width];
    for (int i = 0; i < width; i++)
    {
        for (int j = 0; j < width; j++)
            time_stamp[i][j] = INT_MAX;
    }

    queue<pos> que;
    for (int i = 0; i < k; i++)
    {
        pos v_p = virus[order[i]];
        que.push(v_p);
        time_stamp[v_p.first][v_p.second] = 0;
        int cnt = 0;
    }
    while (!que.empty())
    {
        pos current = que.front();
        int dist = time_stamp[current.first][current.second] + 1;
        que.pop();

        for (int d = 0; d < 4; d++)
        {
            int ny = current.first + dy[d];
            int nx = current.second + dx[d];
            if (check_range(ny, nx) && (dist < time_stamp[ny][nx]))
            {
                time_stamp[ny][nx] = dist;
                que.push(make_pair(ny, nx));
            }
        }
    }

    int total = 0;
    for (int i = 0; i < width; i++)
    {
        for (int j = 0; j < width; j++)
        {
            if (map[i][j] == 1 || map[i][j] == 2)
                continue;
            if (time_stamp[i][j] == INT_MAX && map[i][j] == 0)
                return -1;
            if (time_stamp[i][j] != INT_MAX)
                total = max(total, time_stamp[i][j]);
        }
    }
    return total;
}

void comb(int N, int K)
{
    string bitmask(K, 1); // K leading 1's
    bitmask.resize(N, 0); // N-K trailing 0's
    // print integers and permute bitmask
    do
    {
        int idx = 0;
        for (int i = 0; i < N; ++i) // [0..N-1] integers
        {
            if (bitmask[i])
                order[idx++] = i;
        }
        int ret = bfs();
        if (ret != -1)
            ans = min(ans, ret);
    } while (prev_permutation(bitmask.begin(), bitmask.end()));
}

void solve()
{
    comb(v_cnt, k);
}
int main(int argc, char **argv)
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int T;
    cin >> T;
    for (int test_case = 1; test_case <= T; test_case++)
    {
        cin >> width >> k;
        v_cnt = 0;
        space = 0;
        ans = INT_MAX;
        for (int i = 0; i < width; i++)
        {
            for (int j = 0; j < width; j++)
            {
                cin >> map[i][j];
                if (map[i][j] == 2)
                    virus[v_cnt++] = make_pair(i, j);
                if (map[i][j] == 0)
                    space++;
            }
        }
        solve();
        if (ans == INT_MAX)
            ans = -1;
        cout << "#" << test_case << " " << ans << endl;
    }

    return 0;
}