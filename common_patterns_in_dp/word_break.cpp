#include <bits/stdc++.h>

using namespace std;

//想不到
bool _wordBreak(const string &s, unordered_set<string> &dict, unordered_map<string, bool> &wb)
{
    if(wb.count(s))
        return wb[s];
    if(dict.count(s))
        return wb[s] = true;
    
    //i表示s目前的length
    for(int i = 1; i < s.length(); i++)
    {
        const string left = s.substr(0, i);
        const string right = s.substr(i);

        if(dict.count(right) and _wordBreak(left, dict, wb))
            return wb[s] = true;
    }
    return wb[s] = false;
}

bool wordBreak(string s, vector<string> &wordDict)
{
    unordered_set<string> dict(wordDict.cbegin(), wordDict.cend());
    unordered_map<string, bool> wb;
    
    return _wordBreak(s, dict, wb);
}

int main()
{
    string s = "catsandog";
    vector<string> wordDict = {"cats","dog","sand","and","cat"};
    bool ans = wordBreak(s, wordDict);

    cout << ans << endl;

    return 0;
}