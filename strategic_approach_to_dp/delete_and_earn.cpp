#include <bits/stdc++.h>

using namespace std;

int deleteAndEarn(vector<int> &nums)
{
    int n = nums.size();
    vector<int> point;
    vector<int> num;
    sort(nums.begin(), nums.end());
    point.push_back(nums[0]);
    num.push_back(nums[0]);

    for(int i = 1; i < n; i++)
        if(nums[i] == num.back())
            point.back() += nums[i];
        else
        {
            num.push_back(nums[i]);
            point.push_back(nums[i]);
        }
    
    if(point.size() == 1)
        return point[0];
    else
    {
        vector<int> max_point;
        max_point.push_back(point[0]);
        if(num[1]-num[0] > 1)
            max_point.push_back(point[0] + point[1]);
        else
            max_point.push_back(max(point[0], point[1]));
        
        for(int i = 2; i < num.size(); i++)
            if(num[i]-num[i-1] > 1)
                max_point.push_back(max_point[i-1]+point[i]);
            else
                max_point.push_back(max(max_point[i-1], max_point[i-2]+point[i]));
        
        return max_point.back();
    }
}

int main()
{
    vector<int> nums = {2,2,3,3,3,4};
    int ans = deleteAndEarn(nums);

    cout << ans << endl;

    return 0;
}