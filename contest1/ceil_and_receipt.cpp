#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main() 
{
    int t;
    cin >> t;
    
    int arr[12] = {1,2,4,8,16,32,64,128,256,512,1024,2048};
    int dp[100001];
    dp[0] = 0;
    
    for(int i=1;i<=100000;i++)
        dp[i] = INT_MAX;
        
    for(int cost=1;cost<=100000;cost++)
    {
        for(int j=0;j<=11;j++)
        {
            if(cost >= arr[j])
                dp[cost] = min(dp[cost],1 + dp[cost-arr[j]]);
        }
    }
    
    while(t--)
    {
        int x;
        cin >> x;
        
        cout << dp[x] << endl;
    }
    
	return 0;
}
