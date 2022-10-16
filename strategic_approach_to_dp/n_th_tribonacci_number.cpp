#include <bits/stdc++.h>

using namespace std;

int tribonacci(int n)
{
    if(n == 0)
        return 0;
    else if(n == 1 or n == 2)
        return 1;
    else
    {
       vector<int> tri_table;
       tri_table.push_back(0);
       tri_table.push_back(1);
       tri_table.push_back(1);

       for(int i = 3; i <= n; i++)
       {
            int sum = tri_table[i-1] + tri_table[i-2] + tri_table[i-3];
            tri_table.push_back(sum);
       }

       return tri_table.back();
    }
}

int main()
{
    int n = 25;
    int ans = tribonacci(n);

    cout << ans << endl;

    return 0;
}