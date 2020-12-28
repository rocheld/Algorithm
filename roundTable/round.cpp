#include <iostream>

using namespace std;

int total_table, total_number, total_turn;
int numbers[50][50];
int temp_table[50][50];
int turn_command[50][3];
int ans;

void print()
{
    for (int i = 0; i < total_table; i++)
    {
        for (int j = 0; j < total_number; j++)
            cout << numbers[i][j] << " ";

        cout << endl;
    }
}
void copy()
{
    for (int i = 0; i < total_table; i++)
    {
        for (int j = 0; j < total_number; j++)
        {
            temp_table[i][j] = numbers[i][j];
        }
    }
}
void update_adj()
{
    bool removed = false;
    copy();
    for (int i = 0; i < total_table; i++)
    {
        for (int j = 0; j < total_number; j++)
        {
            int this_number = numbers[i][j];
            if (this_number == 0)
                continue;

            if (j == 0)
            {
                if (numbers[i][j + 1] == this_number)
                    temp_table[i][j + 1] = 0;
                if (numbers[i][total_number - 1] == this_number)
                    temp_table[i][total_number - 1] = 0;
            }

            if (j == total_number - 1)
            {
                if (numbers[i][j - 1] == this_number)
                    temp_table[i][j - 1] = 0;
                if (numbers[i][0] == this_number)
                    temp_table[i][0] = 0;
            }

            if (j - 1 >= 0 && numbers[i][j - 1] == this_number)
            {
                temp_table[i][j - 1] = 0;
            }

            if (j + 1 <= total_number - 1 && numbers[i][j + 1] == this_number)
            {
                temp_table[i][j + 1] = 0;
            }

            if (i + 1 <= total_table - 1 && numbers[i + 1][j] == this_number)
            {
                temp_table[i + 1][j] = 0;
            }
            if (i - 1 >= 0 && numbers[i - 1][j] == this_number)
            {
                temp_table[i - 1][j] = 0;
            }
        }
    }
}
void updateSum()
{
    ans = 0;
    for (int i = 0; i < total_table; i++)
    {
        for (int j = 0; j < total_number; j++)
        {
            numbers[i][j] = temp_table[i][j];
            ans += temp_table[i][j];
        }
    }
}
// 3135 1353
void left_shift(int table_num, int turns)
{
    for (int i = 0; i < turns; i++)
    {
        int temp = numbers[table_num][0];
        for (int j = 0; j < total_number - 1; j++)
            numbers[table_num][j] = numbers[table_num][j + 1];

        numbers[table_num][total_number - 1] = temp;
    }
}
void right_shift(int table_num, int turns)
{
    for (int i = 0; i < turns; i++)
    {
        int temp = numbers[table_num][total_number - 1];
        for (int j = total_number - 1; j >= 1; j--)
            numbers[table_num][j] = numbers[table_num][j - 1];

        numbers[table_num][0] = temp;
    }
}
void turn(int factor, int dir, int turns)
{
    for (int i = 0; i < total_table; i++)
    {
        if ((i + 1) % factor != 0)
            continue;
        if (total_number > 1 && dir == 0)
            right_shift(i, turns);
        if (total_number > 1 && dir == 1)
            left_shift(i, turns);
    }
}
void solve()
{
    for (int i = 0; i < total_turn; i++)
    {
        turn(turn_command[i][0], turn_command[i][1], turn_command[i][2]);
        update_adj();
        updateSum();
    }
}
int main(int argc, char **argv)
{
    int T;
    cin >> T;

    for (int test_case = 1; test_case <= T; test_case++)
    {
        cin >> total_table >> total_number >> total_turn;

        for (int i = 0; i < total_table; i++)
            for (int j = 0; j < total_number; j++)
                cin >> numbers[i][j];

        for (int i = 0; i < total_turn; i++)
            cin >> turn_command[i][0] >> turn_command[i][1] >> turn_command[i][2];

        solve();
        print();
        cout << "#" << test_case << " " << ans << endl;
    }

    return 0;
}