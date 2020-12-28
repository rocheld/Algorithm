#include <iostream>
#include <algorithm>

using namespace std;

int main(int argc, char **argv)
{
    int test_case;
    cin >> test_case;
    for (int T = 1; T <= test_case; T++)
    {
        int days;
        cin >> days;

        int time[days];
        int price[days];
        int dp[days + 1];

        for (int i = 0; i < days; i++)
        {
            int t, p;
            cin >> t >> p;
            time[i] = t;
            price[i] = p;
            dp[i] = 0;
        }

        dp[days] = 0;
        for (int i = days - 1; i >= 0; i--)
        {
            if (i + time[i] > days)
                dp[i] = dp[i + 1];

            else
            {
                dp[i] = max(dp[i + 1], price[i] + dp[i + time[i]]);
            }
        }
        cout << "#" << T << " " << dp[0] << endl;
    }
    return 0;
}