#include <iostream>
#include <queue>

using namespace std;
const int dr[4] = {0, 0, 1, -1};
const int dc[4] = {-1, 1, 0, 0};
const int max_h = 15;
const int max_w = 12;
int n, w, h, ans, total;
int ball[4] = {0, 0, 0, 0};
int map[max_h][max_w];
int temp[max_h][max_w];

bool check_range(int row, int col)
{
    if (row < 0 || row >= w || col < 0 || col >= h)
        return false;
    else
        return true;
}
void copy(int a[][max_w], int b[][max_w])
{
    for (int i = 0; i < h; i++)
    {
        for (int j = 0; j < w; j++)
        {
            a[i][j] = b[i][j];
        }
    }
}
int boom(queue<pair<int, int>> &que, int cnt)
{
    while (!que.empty())
    {
        pair<int, int> b = que.front();
        que.pop();
        int row = b.second;
        int col = b.first;
        const int range = map[col][row];
        if (range == 0)
            continue;

        cnt++;
        map[col][row] = 0;
        if (range == 1)
            continue;

        for (int d = 0; d < 4; d++)
        {
            row = b.second;
            col = b.first;
            for (int r = 1; r < range; r++)
            {
                row += dr[d];
                col += dc[d];
                if (!check_range(row, col))
                    break;
                if (map[col][row] != 0)
                    que.push(make_pair(col, row));
            }
        }
    }
    return cnt;
}
void gravity()
{
    for (int i = 0; i < w; i++)
    {
        int index = h - 1;
        for (int j = h - 1; j >= 0; j--)
        {
            if (map[j][i] != 0)
                swap(map[j][i], map[index--][i]);
        }
    }
}

void game_start()
{
    int cnt = 0;
    queue<pair<int, int>> que;
    for (int i = 0; i < n; i++)
    {
        int row = ball[i];
        for (int c = 0; c < h; c++)
        {
            if (map[c][row] != 0)
            {
                que.push(make_pair(c, row));
                cnt = boom(que, cnt);
                gravity();
                break;
            }
        }
    }
    ans = max(cnt, ans);
}

void dfs(int cnt)
{
    if (cnt == n)
    {
        game_start();
        copy(map, temp);
    }
    else
    {
        for (int i = 0; i < w; i++)
        {
            ball[cnt] = i;
            dfs(cnt + 1);
            if (ans == total)
                break;
        }
    }
}

int main(int argc, char **argv)
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int test_case;
    int T;
    cin >> T;

    for (test_case = 1; test_case <= T; ++test_case)
    {
        int input;
        ans = -1;
        total = 0;

        cin >> n >> w >> h;

        for (int i = 0; i < h; i++)
        {
            for (int j = 0; j < w; j++)
            {
                cin >> input;
                total = (input != 0) ? ++total : total;
                map[i][j] = input;
                temp[i][j] = input;
            }
        }
        if (total == 0 || total <= n)
        {
            total = 0;
            cout << "#" << test_case << " " << total << endl;
        }
        else
        {
            dfs(0);
            cout << "#" << test_case << " " << total - ans << endl;
        }
    }
    return 0; //정상종료시 반드시 0을 리턴해야합니다.
}