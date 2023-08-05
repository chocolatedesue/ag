#include<bits/stdc++.h>

using namespace std;
typedef long long ll ;
typedef pair<int,int>PII;


void BlueFire()
{
    int n;
    cin >> n;
    vector<int> a(n + 1);
    vector<bool> st(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    int ans = 0;
    // 贪心先改2
    for (int i = 1; i <= n; i++)
    {
        if (a[i] == 2 && !st[i])
        {
            ans++;
            st[i] = 1;
            int j = i - 1;
            // 左
            while (j > 0 && a[j])
                st[j--] = 1;
            if (j > 0)
                st[j] = 1;
            // 右
            j = i + 1;
            while (j <= n && a[j])
                st[j++] = 1;
            if (j <= n)
                st[j] = 1;
        }
    }

    // 再改1
    for (int i = 1; i <= n; i++)
    {
        if (a[i] == 1 && !st[i])
        {
            ans++;
            st[i] = 1;
            int j = i - 1;
            bool flag = 0;
            while (j > 0 && a[j])
                st[j--] = 1;
            if (j > 0 && !st[j])
            {
                flag = 1;
                st[j] = 1;
            }
            j = i + 1;
            while (j <= n && a[j])
                st[j++] = 1;
            if (j <= n && !st[j] && !flag)
                st[j] = 1;
        }
        // cout << i <<" "<<ans<<endl;
    }

    for (int i = 1; i <= n; i++)
        if (!st[i])
            ans++;
    cout << ans << endl;

    return;
}



signed main(){
    freopen("in","r",stdin);

    int t  =1 ; 
    // cin >> t;
    while (t--);
    {
        // solve();
        BlueFire();
    }

    return 0;
}