#include <iostream>
#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

unsigned long long int nc2(int a)
{
    if(a < 2)
        return 0;
    unsigned long long int  k = (a);
    k = k*(k-1);
    k = k/2;
    return k;
}

int main() 
{
    ll n,d;
    cin >> n >> d;
    
    vector <ll> v;
    ll x;
    for(int i=1;i<=n;i++)
    {
        cin >> x;
        v.push_back(x);
    }
    
    sort(v.begin(),v.end());
    
    unsigned long long int  ans = 0;
    for(auto it1=v.begin();it1<=v.end()-3;it1++)
    {
        ll a = *it1 + d;
        auto it2 = lower_bound(it1,v.end(),a);
        
        if(it2 == v.end())
            it2--;
        
        if(*it2 > a)
            it2--;
        
        int z = it2-it1;
        ans += nc2(z);
    }
    
    cout << ans << endl;
	return 0;
}
