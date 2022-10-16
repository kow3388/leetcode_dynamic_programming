#include <bits/stdc++.h>

using namespace std;

//寫不出來
//有兩種情況
//第一種情況是最大合不包含頭尾(和一般的maximum subarray相同)
//第二種情況是最大合有包含頭尾(循環)
//第二種情況可以換一種思考，最大合是出現在頭尾
//那表示最小合出現不在頭尾(minimum subarray)
//此時最大合 = total - 最小合
//因此我們計算兩個分別為最大合和最小合
int maxSubarraySumCircular(vector<int> &nums)
{
    int total = 0, cur_max = 0, cur_min = 0;
    int max_sum = nums[0], min_sum = nums[0];

    for(int &num : nums)
    {
        //要不要包含現在的數字
        cur_max = max(cur_max + num, num);
        //目前最大
        max_sum = max(max_sum, cur_max);
        //要不要包含現在的數字
        cur_min = min(cur_min + num, num);
        //目前最小
        min_sum = min(min_sum, cur_min);

        total += num;
    }

    //回傳時看哪個值大，一個是沒有循環的情況，一個是有循環的情況
    //如果是復值，表示array裡沒有正值
    return max_sum > 0? max(max_sum, total - min_sum) : max_sum;
}

int main()
{
    vector<int> nums = {5,-3,5};
    int ans = maxSubarraySumCircular(nums);

    cout << ans << endl;

    return 0;
}