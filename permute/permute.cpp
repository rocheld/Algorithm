#include <iostream>
#include <vector>
using namespace std;
const int chance = 10;
void permute(vector<int> roll, int l, int s)
{
    if (l == s - 1)
    {
        return;
    }
    for (int k = l; k < s; k++)
    {
        if (k != l && roll[k] == roll[l])
            continue;

        swap(roll[k], roll[l]);
        permute(roll, l + 1, s);
    }
}
int main(int argc, char **argv)
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int T;
    cin >> T;

    for (int test_case = 0; test_case <= T; test_case++)
    {
        vector<int> roll(chance, 0);
        for (int i = 0; i < chance; i++)
        {
            cin >> roll[i];
        }

        permute(roll, 0, chance);
    }
    return 0;
}