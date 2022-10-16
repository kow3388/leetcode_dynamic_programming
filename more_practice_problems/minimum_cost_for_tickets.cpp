#include <bits/stdc++.h>

using namespace std;

//想不到
int mincostTickets(vector<int> &days, vector<int> &costs)
{
    //req => 哪些天需要出遊
    vector<int> req(days.back()+1);
    //dp => 所花的費用
    vector<int> dp(days.back()+1);

    for(int day : days)
        req[day] = 1;
    
    //沒有第0天，所以是0
    dp[0] = 0;
    for(int i = 1; i < dp.size(); i++)
    {
        //如果不用出遊，則不花費
        if(!req[i])
        {
            dp[i] = dp[i-1];
            continue;
        }
        //分別去計算用日票，週票和月票哪個划算
        dp[i] = dp[i-1] + costs[0];
        dp[i] = min(dp[i], dp[max(0, i-7)] + costs[1]);
        dp[i] = min(dp[i], dp[max(0, i-30)] + costs[2]);
    }

    return dp.back();
}

int main()
{
    vector<int> days = {1,4,6,7,8,20};
    vector<int> costs = {2,7,15};
    int ans = mincostTickets(days, costs);

    cout << ans << endl;

    return 0;
}