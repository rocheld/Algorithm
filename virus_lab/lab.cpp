#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

const int dy[4] = {-1, 1, 0, 0};
const int dx[4] = {0, 0, -1, 1};
const int wall_cnt = 3;
int width, height, spot_cnt, v_cnt, ans;
int map[8][8];
bool order[64];
int com;
typedef pair<int, int> pos;
pos possible_spot[64];
pos virus[10];

bool check_range(int y, int x)
{
    if (y < 0 || y >= height || x < 0 || x >= width || map[y][x] != 0)
        return false;
    else
        return true;
}

void bfs()
{
    int spread = 0;
    bool visited[height][width];
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            visited[i][j] = false;
        }
    }

    queue<pos> que;
    for (int v = 0; v < v_cnt; v++)
        que.push(virus[v]);

    while (!que.empty())
    {
        pos c = que.front();
        que.pop();
        for (int d = 0; d < 4; d++)
        {
            int ny = c.first + dy[d];
            int nx = c.second + dx[d];

            if (check_range(ny, nx) && !visited[ny][nx])
            {
                spread++;
                visited[ny][nx] = true;
                que.push(make_pair(ny, nx));
            }
        }
    }
    int safe = spot_cnt - wall_cnt - spread;
    if (ans < safe)
        ans = safe;
}
void pick_spot()
{

    string bitmask(wall_cnt, 1);
    bitmask.resize(spot_cnt, 0);
    do
    {
        pos wall_spot[3];
        int index = 0;
        for (int i = 0; i < spot_cnt; i++)
            if (bitmask[i])
                wall_spot[index++] = possible_spot[i];

        for (int i = 0; i < wall_cnt; i++)
        {
            pos p = wall_spot[i];
            map[p.first][p.second] = 1;
        }
        bfs();

        for (int i = 0; i < wall_cnt; i++)
        {
            pos p = wall_spot[i];
            map[p.first][p.second] = 0;
        }
    } while (prev_permutation(bitmask.begin(), bitmask.end()));
}
void start()
{
    pick_spot();
    cout << "!!" << spot_cnt << " C " << com << endl;
}
int main(int argc, char **argv)
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    std::cout.tie(0);
    int T;
    cin >> T;

    for (int test_case = 1; test_case <= T; test_case++)
    {
        cin >> height >> width;

        v_cnt = 0;
        spot_cnt = 0;
        ans = 0;
        com = 0;
        for (int i = 0; i < height; i++)
        {
            for (int j = 0; j < width; j++)
            {
                cin >> map[i][j];

                if (map[i][j] == 0)
                    possible_spot[spot_cnt++] = make_pair(i, j);

                else if (map[i][j] == 2)
                    virus[v_cnt++] = make_pair(i, j);
            }
        }
        start();
        std::cout << "#" << test_case << " " << ans << endl;
    }
    return 0;
}