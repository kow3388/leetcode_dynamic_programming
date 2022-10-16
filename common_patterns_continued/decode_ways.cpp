#include <bits/stdc++.h>

using namespace std;

//自己寫的垃圾code
//time: O(n^2), space: O(n^2)
int _numDecoding1(string s, unordered_map<string, int> &cnt)
{
    if(s[0] == '0')
        return 0;
    
    if(s.length() < 3)
    {
        if(stoi(s) < 10 or stoi(s) == 10 or stoi(s) == 20)
            return 1;
        else if(stoi(s) <= 26 and stoi(s) > 10)
            return 2;
    }
    
    if(cnt.count(s))
        return cnt[s];
    
    const int n = s.length();
    int ans = 0;
    for(int i = 1; i < n; i++)
    {
        string left = s.substr(0, i);
        string right = s.substr(i);
        if(stoi(left) > 26)
            break;
        else
        {
            int tmp = _numDecoding1(right, cnt);
            cnt[right] = tmp;
            ans += cnt[right];
        }
    }

    return ans;
}

int numDecodings1(string s)
{
    unordered_map<string, int> cnt;

    return _numDecoding1(s, cnt);
}

//跟我的想法相同，但更有效率
//time: O(n^2), space: O(n^2)
int _numDecoding2(string s, unordered_map<string, int> &m_ways)
{
    if(m_ways.count(s))
        return m_ways[s];

    if(s[0] == '0')
        return 0;
    
    if(s.length() == 1)
        return 1;

    int w = _numDecoding2(s.substr(1), m_ways);
    const int prefix = stoi(s.substr(0, 2));

    if(prefix <= 26)
        w += _numDecoding2(s.substr(2), m_ways);
    
    m_ways[s] = w;
    
    return w;
}

int numDecodings2(string s)
{
    if(s.length() == 0)
        return 0;
    unordered_map<string, int> m_ways;
    m_ways[""] = 1;

    return _numDecoding2(s, m_ways);
}

//time: O(n), space: O(n)
int _numDecoding(string s, unordered_map<int, int> &m_ways, int l, int r)
{
    if(m_ways.count(l))
        return m_ways[l];
    
    if(s[l] == '0')
        return 0;
    
    //single digit or empty
    if(l >= r)
        return 1;
    
    int w = _numDecoding(s, m_ways, l+1, r);
    const int prefix = (s[l] - '0')*10 + (s[l+1] - '0');

    if(prefix <= 26)
        w += _numDecoding(s, m_ways, l+2, r);

    m_ways[l] = w;

    return w;
}

int numDecodings(string s)
{
    if(s.length() == 0)
        return 0;
    unordered_map<int, int> m_ways;

    return _numDecoding(s, m_ways, 0, s.length()-1);
}

int main()
{
    string s = "11106";
    int ans = numDecodings(s);

    cout << ans << endl;

    return 0;
}