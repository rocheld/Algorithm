#include <iostream>
#include <queue>

using namespace std;
const int max_width = 20;
const int max_shark = 400;
const int dy[5] = {0, -1, 1, 0, 0};
const int dx[5] = {0, 0, 0, -1, 1};
struct node
{
    int symbol, shark_num, trace;
};
int shark_cnt, width, k;
node map[max_width][max_width];
int p_table[max_shark][5][5];
int dir[max_shark];
typedef pair<int, int> pos;

void print_trace()
{
    for (int i = 0; i < width; i++)
    {
        for (int j = 0; j < width; j++)
        {
            cout << map[i][j].trace << " ";
        }
        cout << endl;
    }

    cout << endl;
}
void print()
{
    for (int i = 0; i < width; i++)
    {
        for (int j = 0; j < width; j++)
        {
            cout << map[i][j].symbol << " ";
        }
        cout << endl;
    }

    cout << endl;
}

bool check_range(int y, int x, bool visitable)
{
    if (y < 0 || y >= width || x < 0 || x >= width || !visitable)
        return false;
    else
        return true;
}

// return alternative direction
int find_dir(int y, int x, int cur_dir, int sym)
{
    for (int i = 1; i < 5; i++)
    {
        int ny = y + dy[p_table[sym - 1][cur_dir][i]];
        int nx = x + dx[p_table[sym - 1][cur_dir][i]];
        if (ny < 0 || ny >= width || nx < 0 || nx >= width || map[ny][nx].shark_num != map[y][x].shark_num)
            continue;
        else
            return p_table[sym - 1][cur_dir][i];
    }
    return 0;
}
int start(queue<pos> &que)
{
    int size, time = 0;
    bool temp_map[width][width];
    while (!que.empty() && time < 1000 && shark_cnt > 1)
    {
        size = que.size();
        time++;

        //cout << "TIME: " << time << endl;

        for (int i = 0; i < width; i++)
        {
            for (int j = 0; j < width; j++)
            {
                temp_map[i][j] = false;
                if (map[i][j].trace > 0)
                {
                    map[i][j].trace = --map[i][j].trace;
                }

                if (map[i][j].trace == 0 && map[i][j].symbol == 0)
                {
                    temp_map[i][j] = true;
                    map[i][j].shark_num = 0;
                }
            }
        }
        //print_trace();
        for (int i = 0; i < size; i++)
        {
            pos p = que.front();
            que.pop();
            int y = p.first;
            int x = p.second;
            int s_num = map[y][x].shark_num;
            int sym = map[y][x].symbol;
            int ny, nx;
            int cur_dir = dir[sym - 1];
            if (sym == 0)
                continue;
            for (int d = 1; d < 6; d++)
            {

                // go back to previous position
                if (d == 5)
                {
                    cur_dir = find_dir(y, x, cur_dir, sym);
                    if (cur_dir == 0)
                        return -1;
                    ny = y + dy[cur_dir];
                    nx = x + dx[cur_dir];
                    dir[sym - 1] = cur_dir;
                    temp_map[ny][nx] = true;
                }
                else
                {
                    ny = y + dy[p_table[sym - 1][cur_dir][d]];
                    nx = x + dx[p_table[sym - 1][cur_dir][d]];
                }
                if (check_range(ny, nx, temp_map[ny][nx]))
                {
                    map[y][x].symbol = 0;
                    if (map[ny][nx].symbol > sym)
                    {
                        shark_cnt--;
                        map[ny][nx].symbol = sym;
                        map[ny][nx].shark_num = s_num;
                        map[ny][nx].trace = k;
                        dir[s_num - 1] = p_table[sym - 1][cur_dir][d];
                        que.push(make_pair(ny, nx));
                    }
                    else if (map[ny][nx].symbol != 0 && map[ny][nx].symbol < sym)
                    {
                        shark_cnt--;
                    }
                    else if (d == 5)
                    {
                        map[ny][nx].symbol = sym;
                        map[ny][nx].shark_num = s_num;
                        map[ny][nx].trace = k;
                        temp_map[ny][nx] = false;
                        que.push(make_pair(ny, nx));
                    }
                    else
                    {
                        map[ny][nx].symbol = sym;
                        map[ny][nx].shark_num = s_num;
                        map[ny][nx].trace = k;
                        dir[s_num - 1] = p_table[sym - 1][cur_dir][d];
                        que.push(make_pair(ny, nx));
                    }

                    break;
                }
            }
        }

        //print();

        // end of while
    }
    if (shark_cnt == 1)
        return time;
    else
        return -1;
}
int main(int argc, char **argv)
{
    int test_case;
    cin >> test_case;

    for (int T = 1; T <= test_case; T++)
    {
        cin >> width >> shark_cnt >> k;
        queue<pos> que;
        k++;
        for (int i = 0; i < width; i++)
        {
            for (int j = 0; j < width; j++)
            {
                int input;
                cin >> input;
                map[i][j].symbol = input;
                map[i][j].shark_num = input;
                // read shark
                if (input != 0)
                {
                    que.push(make_pair(i, j));
                    map[i][j].trace = k;
                }
                else
                    map[i][j].trace = 0;
            }
        }
        for (int i = 0; i < shark_cnt; i++)
            cin >> dir[i];

        for (int i = 0; i < shark_cnt; i++)
        {
            for (int j = 1; j < 5; j++)
            {
                for (int k = 1; k < 5; k++)
                {
                    cin >> p_table[i][j][k];
                }
            }
        }
        int ans = start(que);
        cout << "#" << T << " " << ans << endl;
    }
    return 0;
}