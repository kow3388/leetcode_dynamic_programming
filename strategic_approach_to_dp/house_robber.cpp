#include <bits/stdc++.h>

using namespace std;

int rob(vector<int> &nums)
{
    if(nums.size() == 1)
        return nums[0];
    else
    {
        int n = nums.size();
        vector<int> pro;
        pro.push_back(nums[0]);
        pro.push_back(max(pro[0], nums[1]));

        for(int i = 2; i < n; i++)
            pro.push_back(max(pro[i-1], pro[i-2]+nums[i]));
        
        return pro.back();
    }
}

int main()
{
    vector<int> nums = {7,2,3,9,1};
    int ans = rob(nums);

    cout << ans << endl;
    
    return 0;
}