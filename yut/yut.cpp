#include <iostream>

using namespace std;
const int board_point[33] = {0, 2, 4, 6, 8, 10, 12, 14, 16, 18,
                             20, 22, 24, 26, 28, 30, 32, 34, 36, 38,
                             40, 13, 16, 19, 25, 30, 35, 22, 24, 28,
                             27, 26, 0};
const int board[33][5] = {
    {1, 2, 3, 4, 5},      // idx 0
    {2, 3, 4, 5, 6},      // idx 1
    {3, 4, 5, 6, 7},      // idx 2
    {4, 5, 6, 7, 8},      // idx 3
    {5, 6, 7, 8, 9},      // 4
    {21, 22, 23, 24, 25}, // 5
    {7, 8, 9, 10, 11},    // 6
    {8, 9, 10, 11, 12},   // 7
    {9, 10, 11, 12, 13},  // 8
    {10, 11, 12, 13, 14}, // 9
    {27, 28, 24, 25, 26}, // 10
    {12, 13, 14, 15, 16}, // 11
    {13, 14, 15, 16, 17}, // 12
    {14, 15, 16, 17, 18}, // 13
    {15, 16, 17, 18, 19}, // 14
    {29, 30, 31, 24, 25}, // 15
    {17, 18, 19, 20, 32}, // 16
    {18, 19, 20, 32, 32}, // 17
    {19, 20, 32, 32, 32}, // 18
    {20, 32, 32, 32, 32}, // 19
    {32, 32, 32, 32, 32}, // 20
    {22, 23, 24, 25, 26}, // 21
    {23, 24, 25, 26, 20}, // 22
    {24, 25, 26, 20, 32}, // 23
    {25, 26, 20, 32, 32}, // 24
    {26, 20, 32, 32, 32}, // 25
    {20, 32, 32, 32, 32}, // 26
    {28, 24, 25, 26, 20}, // 27
    {24, 25, 26, 20, 32}, // 28
    {30, 31, 24, 25, 26}, // 29
    {31, 24, 25, 26, 20}, // 30
    {24, 25, 26, 20, 32}, // 31
    {32, 32, 32, 32, 32}, // 32
};
const int total_turn = 10;
const int total_horse = 4;
const int END = 32;
int roll[total_turn];
int max_point;
int position[total_horse];

bool is_valid(int pos, int h_num)
{
    for (int i = 0; i < total_horse; i++)
    {
        if (i != h_num && position[i] == pos && position[i] != END)
            return false;
    }
    return true;
}
void solve(int turn, int point)
{
    if (turn == total_turn)
        return;
    int dice = roll[turn] - 1;

    for (int h = 0; h < total_horse; h++)
    {
        int c_pos = position[h];
        int n_pos = board[c_pos][dice];

        if (c_pos == END || !is_valid(n_pos, h))
            continue;

        position[h] = n_pos;
        point += board_point[n_pos];
        max_point = max(max_point, point);
        solve(turn + 1, point);

        // backtrack
        position[h] = c_pos;
        point -= board_point[n_pos];
    }
    return;
}
int main(int argc, char **argv)
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    max_point = 0;
    for (int i = 0; i < total_turn; i++)
    {
        if (i < 4)
            position[i] = 0;
        cin >> roll[i];
    }
    solve(0, 0);
    cout << max_point << endl;
    return 0;
}