#include <bits/stdc++.h>

using namespace std;

int lengthOfLIS(vector<int> &nums)
{
    if(nums.size() == 1)
        return 1;
    else
    {
        vector<int> subvec;
        for(int i = 0; i < nums.size(); i++)
            if(subvec.empty())
                subvec.push_back(nums[i]);
            else
            {
                vector<int>::iterator pos = lower_bound(subvec.begin(), subvec.end(), nums[i]);
                if(pos == subvec.end())
                    subvec.push_back(nums[i]);
                else
                    *pos = nums[i];
            }

        return subvec.size();
    }
}

int main()
{
    vector<int> nums = {10,9,4,5,3,7,101,18};
    int ans = lengthOfLIS(nums);

    cout << ans << endl;

    return 0;
}