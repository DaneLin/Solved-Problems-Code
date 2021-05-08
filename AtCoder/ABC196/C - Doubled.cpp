#include <bits/stdc++.h>
using namespace std;
int main()
{
    long long N;
    cin >> N;
    int ans = 0;
    for (long long i = 1; i <= 1000000; i++)
    {
        string S = to_string(i);
        string T = S + S;
        long long M = stoll(T);
        if (M <= N)
        {
            ans++;
        }
    }
    cout << ans << endl;
}