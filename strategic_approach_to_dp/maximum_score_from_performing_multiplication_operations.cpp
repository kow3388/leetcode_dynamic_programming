#include <bits/stdc++.h>

using namespace std;

//想不到
int maximumScore(vector<int> &nums, vector<int> &multipliers)
{
    const int n = nums.size(), m = multipliers.size();
    if(m == 1)
        return max(multipliers[0]*nums.front(), multipliers[0]*nums.back());
    else
    {
        vector<vector<int>> cache(m, vector<int>(m, INT_MIN));
        function<int(int, int)> dp = [&](int i, int j)
        {
            //k表示multipliers的位置
            //i表示頭，j表示尾
            const int k = n - (j - i + 1);
            //表示求解結束
            if(k == m)
                return 0;
            else
            {
                //cache[i][k]
                //i表示有i個從頭開始取，k表示multipliers用了前k個後的最佳解
                //ex:n = [1, 2, 3], m = [3, 2, 1]
                //   cache[1][1]表示有1個被從頭取，multipliers用了1個
                //   要解n = [2, 3], m = [2, 1]的最佳解
                int &ans = cache[i][k];
                //求解結束
                if(ans != INT_MIN)
                    return ans;
                else
                //分別把頭尾相乘的結果送到下一層
                    return ans = max(dp(i+1, j)+nums[i]*multipliers[k],
                                     dp(i, j-1)+nums[j]*multipliers[k]);
            }
        };

        return dp(0, n-1);
    }
}

int main()
{
    vector<int> n = {1,2,3};
    vector<int> m = {3,2,1};
    int ans = maximumScore(n, m);

    //cout << ans << endl;

    return 0;
}