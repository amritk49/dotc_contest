//greedy 

#include <iostream>
#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

static bool mycomp(pair<int,int> p1,pair<int,int> p2)
{
    int a1 = abs(p1.first-p1.second);
    int a2 = abs(p2.first-p2.second);
    
    if(abs(a1) >= abs(a2))
        return true;
    return false;
}

int main()
{
    int n,a,b;
    cin >> n >> a >> b;
    
    int arr1[n+1];
    for(int i=1;i<=n;i++)
        cin >> arr1[i];
    
    int arr2[n+1];
    for(int i=1;i<=n;i++)
        cin >> arr2[i];
    
    vector <pair<int,int>> v;
    
    for(int i=1;i<=n;i++)
        v.push_back({arr1[i],arr2[i]});
    
    sort(v.begin(),v.end(),mycomp);
    int ans = 0;
    
    for(int i=0;i<n;i++)
    {
        pair<int,int> p =v[i];
        
        if(p.first > p.second)
        {
            if(a>0)
            {
                ans += p.first;
                a--;
            }
            else
            {
                ans += p.second;
                b--;
            }
        }
        else if(p.first == p.second)
        {
            ans += p.first;
            if(a >= b)
                a--;
            else
                b--;
        }
        else
        {
            if(b>0)
            {
                ans += p.second;
                b--;
            }
            else
            {
                ans += p.first;
                a--;
            }
        }
    }
    
    cout << ans << endl;
    return 0;
}
