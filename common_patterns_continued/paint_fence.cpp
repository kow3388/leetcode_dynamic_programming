#include <bits/stdc++.h>

using namespace std;

//想不到
int numWays(int n, int k)
{
    vector<int> ways = {0, k, k*k};
    if(n < 3)
        return ways[n];
    else
    {
        //i表示第幾根柵欄
        //ways[0] => i%3 = 0的位置，依此類推
        //第三根不能跟前面兩根的顏色一樣，所以是k-1
        for(int i = 2; i < n; i++)
        {
            //把下面式子拆開得
            //(k-1)*ways[1] + (k-1)*ways[2]
            //意思是不能跟第一根柱子有相同的顏色所以有(k-1)*ways[1]種選擇
            //不能跟第二根柱子有相同的顏色所以有(k-1)*ways[2]種選擇
            //相加為第三根柱子的選擇數
            ways[0] = (k-1)*(ways[1]+ways[2]);
            ways[1] = ways[2];
            ways[2] = ways[0];
        }

        return ways[0];
    }
}

int main()
{
    int n = 3, k = 2;
    int ans = numWays(n, k);

    cout << ans << endl;

    return 0;
}