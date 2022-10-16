#include <bits/stdc++.h>

using namespace std;

int findLength(vector<int> &nums1, vector<int> &nums2)
{
    nums1.insert(nums1.begin(), -1);
    nums2.insert(nums2.begin(), -1);
    const int n = nums1.size();
    const int m = nums2.size();
    vector<vector<int>> len(n, vector<int>(m, 0));
    int max_val = 0;

    for(int i = 1; i < n; i++)
        for(int j = 1; j < m; j++)
            if(nums2[j] == nums1[i])
            {
                len[i][j] = len[i-1][j-1] +1;
                max_val = max(max_val, len[i][j]);
            }

    return max_val;
}

int main()
{
    vector<int> nums1 = {1,2,3,2,1,5};
    vector<int> nums2 = {3,2,1,4,7,5};
    int ans = findLength(nums1, nums2);

    cout << ans << endl;

    return 0;
}