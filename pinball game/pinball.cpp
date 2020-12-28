#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

const int dx[4] = {0, 0, -1, 1};
const int dy[4] = {-1, 1, 0, 0};
const int DOWN = 1, UP = 0, LEFT = 2, RIGHT = 3;

int width, point, max_point, dir, hole_cnt;
int map[100][100];
pair<int, int> hole[10];
pair<int, int> s;

pair<int, int> warmhole(int y, int x)
{
    pair<int, int> p;
    for (int i = 0; i < hole_cnt; i++)
    {
        p = hole[i];
        if ((y != p.first || x != p.second) && map[p.first][p.second] == map[y][x])
            break;
    }
    return p;
}
bool is_point(int y, int x)
{
    if (map[y][x] >= 1 && map[y][x] <= 5)
        return true;
    else
        return false;
}
bool check_range(int y, int x)
{
    if (y < 0 || y >= width || x < 0 || x >= width)
        return false;
    else
        return true;
}
void find_dir(int type)
{
    switch (type)
    {
    case 1:
        if (dir == RIGHT)
            dir = LEFT;
        else if (dir == UP)
            dir = DOWN;
        else if (dir == DOWN)
            dir = RIGHT;
        else
            dir = UP;

        break;

    case 2:
        if (dir == RIGHT)
            dir = LEFT;
        else if (dir == UP)
            dir = RIGHT;
        else if (dir == LEFT)
            dir = DOWN;
        else
            dir = UP;

        break;
    case 3:
        if (dir == RIGHT)
            dir = DOWN;
        else if (dir == UP)
            dir = LEFT;
        else if (dir == LEFT)
            dir = RIGHT;
        else
            dir = UP;

        break;
    case 4:
        if (dir == RIGHT)
            dir = UP;
        else if (dir == DOWN)
            dir = LEFT;
        else if (dir == UP)
            dir = DOWN;
        else
            dir = RIGHT;
        break;
    case 5:
        if (dir == RIGHT)
            dir = LEFT;
        else if (dir == UP)
            dir = DOWN;
        else if (dir == LEFT)
            dir = RIGHT;
        else
            dir = UP;
        break;
    default:
        break;
    }
}

void dfs(int y, int x)
{
    int ny, nx;
    ny = y + dy[dir];
    nx = x + dx[dir];
    if (check_range(ny, nx))
    {
        if ((ny == s.first && nx == s.second) || map[ny][nx] == -1)
            return;

        else if (is_point(ny, nx))
        {
            find_dir(map[ny][nx]);
            point += 1;
        }
        else if (map[ny][nx] >= 6)
        {
            pair<int, int> p = warmhole(ny, nx);
            ny = p.first;
            nx = p.second;
        }
    }
    else
    {
        point += 1;
        find_dir(5);
    }
    dfs(ny, nx);
}
void start(queue<pair<int, int>> &que)
{
    while (!que.empty())
    {
        s = que.front();
        que.pop();
        for (int i = 0; i < 4; i++)
        {
            point = 0;
            dir = i;
            dfs(s.first, s.second);
            max_point = std::max(max_point, point);
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
        cin >> width;

        queue<pair<int, int>> start_point;
        point = 0;
        max_point = -1;
        hole_cnt = 0;
        for (int i = 0; i < width; i++)
        {
            for (int j = 0; j < width; j++)
            {
                int input;
                cin >> input;
                map[i][j] = input;
                if (input == 0)
                    start_point.push(make_pair(i, j));

                else if (input >= 6)
                    hole[hole_cnt++] = make_pair(i, j);
            }
        }
        start(start_point);
        cout << "#" << test_case << " " << max_point << endl;
    }

    return 0; //정상종료시 반드시 0을 리턴해야합니다.
}