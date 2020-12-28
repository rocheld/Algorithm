#include <iostream>
#include <queue>

using namespace std;
const int dy[4] = {0, -1, 1, 0};
const int dx[4] = {-1, 0, 0, 1};
int width, p_cnt, fuel, trip_count, len;
int map[20][20];
int ty, tx; // taxi start pos

struct cmp
{
    bool operator()(const pair<pair<int, int>, int> lhs, const pair<pair<int, int>, int> rhs)
    {
        if (lhs.second > rhs.second)
        {
            return true;
        }
        else if (lhs.second == rhs.second)
        {
            if (lhs.first.first > rhs.first.first)
            {
                return true;
            }
            else if (lhs.first.first < rhs.first.first)
                return false;
            else
            {
                if (lhs.first.second > rhs.first.second)
                    return true;
                else
                    return false;
            }
        }
        else
        {
            return false;
        }
    }
};
typedef pair<int, int> pos;
typedef priority_queue<pair<pair<int, int>, int>, vector<pair<pair<int, int>, int>>, cmp> pq;
/*
    min = lhs > rhs
*/

bool check_range(int y, int x)
{
    if (y < 0 || y >= width || x < 0 || x >= width || map[y][x] == 1)
        return false;
    else
        return true;
}

int arrive(int y, int x, int d_y, int d_x)
{
    bool visited[20][20];
    int dist[20][20];
    for (int i = 0; i < 20; i++)
    {
        for (int j = 0; j < 20; j++)
        {
            visited[i][j] = false;
            dist[i][j] = 0;
        }
    }
    queue<pos> que;
    que.push(make_pair(y, x));
    dist[y][x] = 0;
    visited[y][x] = true;
    while (!que.empty())
    {
        pos p = que.front();
        que.pop();
        y = p.first;
        x = p.second;

        if (fuel < dist[y][x] + len)
            return -1;
        if (y == d_y && x == d_x)
        {
            ty = y;
            tx = x;
            return dist[y][x];
        }

        for (int i = 0; i < 4; i++)
        {
            int next_y = y + dy[i];
            int next_x = x + dx[i];

            if (check_range(next_y, next_x))
            {
                if (!visited[next_y][next_x])
                {
                    visited[next_y][next_x] = true;
                    dist[next_y][next_x] = dist[y][x] + 1;
                    que.push(make_pair(next_y, next_x));
                }
            }
        }
    }
    return -1;
}
pos bfs(int y, int x)
{
    bool visited[20][20];
    int dist[20][20];
    pq myque;
    for (int i = 0; i < 20; i++)
    {
        for (int j = 0; j < 20; j++)
        {
            visited[i][j] = false;
            dist[i][j] = 0;
        }
    }
    queue<pos> que;
    que.push(make_pair(y, x));
    dist[y][x] = 0;
    visited[y][x] = true;
    while (!que.empty() && myque.size() < p_cnt - trip_count)
    {
        pos p = que.front();
        que.pop();
        y = p.first;
        x = p.second;

        if (map[y][x] == -1)
        {
            myque.push(make_pair(make_pair(y, x), dist[y][x]));
        }
        for (int i = 0; i < 4; i++)
        {
            int next_y = y + dy[i];
            int next_x = x + dx[i];

            if (check_range(next_y, next_x))
            {
                if (!visited[next_y][next_x])
                {
                    visited[next_y][next_x] = true;
                    dist[next_y][next_x] = dist[y][x] + 1;
                    que.push(make_pair(next_y, next_x));
                }
            }
        }
    }
    if (!myque.empty())
    {
        pos p = myque.top().first;
        map[p.first][p.second] = 0;
        len = dist[p.first][p.second];
        trip_count++;
        return p;
    }
    else
        return make_pair(-1, -1);
}

int start(pos *src, pos *dest)
{
    pos p = bfs(ty, tx);
    pos d;
    if (p.first == -1)
        return -1;
    for (int i = 0; i < p_cnt; i++)
    {
        if (p == src[i])
        {
            d = dest[i];
            break;
        }
    }
    cout << p.first << " " << p.second << " " << len << endl;
    int gas = arrive(p.first, p.second, d.first, d.second);
    if (gas == -1)
        return -1;
    else
        fuel = fuel + gas + gas - (len + gas);
    return fuel;
}

int main(int argc, char **argv)
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int test_case, T;
    cin >> T;

    for (test_case = 1; test_case <= T; ++test_case)
    {
        cin >> width >> p_cnt >> fuel;

        int ans = 0;
        len = 0;
        trip_count = 0;
        for (int i = 0; i < width; i++)
        {
            for (int j = 0; j < width; j++)
            {
                int input;
                cin >> input;
                map[i][j] = input;
            }
        }
        pos *p_src = new pos[p_cnt];
        pos *p_dest = new pos[p_cnt];

        cin >> ty >> tx;
        ty -= 1;
        tx -= 1;

        for (int i = 0; i < p_cnt; i++)
        {
            int src_y, src_x, dst_y, dst_x;
            cin >> src_y >> src_x >> dst_y >> dst_x;
            p_src[i] = make_pair(src_y - 1, src_x - 1);
            p_dest[i] = make_pair(dst_y - 1, dst_x - 1);
            map[src_y - 1][src_x - 1] = -1;
        }

        for (int i = 0; i < p_cnt; i++)
        {
            ans = start(p_src, p_dest);
            if (ans == -1)
                break;
        }
        cout << "#" << test_case << " " << ans << endl;
    }
    return 0; //정상종료시 반드시 0을 리턴해야합니다.
}