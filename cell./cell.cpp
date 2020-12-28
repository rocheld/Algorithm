#include <iostream>
#include <queue>
/*

#1 22
#2 36
#3 90
#4 164
#5 712


life - 2 birth:0 dead: 4

t == life+life+birth
*/
using namespace std;
const int dh[4] = {0, 0, -1, 1};
const int dw[4] = {1, -1, 0, 0};
int h, w, TIME, h_pos, w_pos;
const int max_size = 350;

int map[max_size][max_size];
int active[max_size][max_size];

typedef queue<pair<int, int>> q;

bool check_range(int r, int c)
{
    if (r < 0 || r >= 350 || c < 0 || c >= 350 || map[c][r] == -1)
        return false;
    else
        return true;
}
void reproduce(int t, int c, int r, q &que)
{
    const int life = map[c][r];
    for (int i = 0; i < 4; i++)
    {
        int col = c + dh[i];
        int row = r + dw[i];
        int spot = map[col][row];

        if (check_range(row, col))
        {
            //first insert
            if ((active[col][row] == 0) && (spot == 0))
            {
                map[col][row] = life;
                active[col][row] = t;
                que.push(make_pair(col, row));
            }
            else if ((active[col][row] == t) && (spot < life))
            {
                map[col][row] = life;
            }
        }
    }
}
void print()
{
    int offset = TIME / 2;
    if (TIME % 2 == 1)
        ++offset;

    for (int i = h_pos - offset; i < h_pos + h + offset; i++)
    {
        for (int j = w_pos - offset; j < w_pos + w + offset; j++)
        {
            cout << map[i][j] << " ";
        }
        cout << endl;
    }
}
void reset()
{
    int offset = TIME / 2;
    if (TIME % 2 == 1)
        ++offset;

    for (int i = h_pos - offset; i < h_pos + h + offset; i++)
    {
        for (int j = w_pos - offset; j < w_pos + w + offset; j++)
        {
            map[i][j] = 0;
            active[i][j] = 0;
        }
    }
}
void start(int t, q &que)
{
    const int size = que.size();
    if (t > TIME)
        return;

    for (int i = 0; i < size; i++)
    {
        pair<int, int> p = que.front();
        int c = p.first;
        int r = p.second;
        int life = map[c][r];
        que.pop();

        if (active[c][r] + life + 1 > t)
            que.push(p);
        else if (active[c][r] + life + 1 == t)
            reproduce(t, c, r, que);

        if (active[c][r] + life + 1 <= t)
        {
            if (active[c][r] + life + life == t)
            {
                map[c][r] = -1;
            }
            else
                que.push(p);
        }
    }
    start(t + 1, que);
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
        cin >> h >> w >> TIME;
        h_pos = (max_size - h) / 2;
        w_pos = (max_size - w) / 2;

        if (h % 2 == 1)
            --h_pos;
        if (w % 2 == 1)
            --w_pos;

        q que;
        for (int i = 0; i < h; i++)
        {
            for (int j = 0; j < w; j++)
            {
                int input;
                int col = i + h_pos;
                int row = j + w_pos;
                cin >> input;
                if (input != 0)
                {
                    map[col][row] = input;
                    active[col][row] = 0;
                    que.push(make_pair(col, row));
                }
            }
        }
        start(1, que);
        cout << "#" << test_case << " " << que.size() << endl;
        if (test_case != T)
            reset();
    }
    return 0; //정상종료시 반드시 0을 리턴해야합니다.
}