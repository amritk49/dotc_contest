#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main() 
{
	int n;
	cin >> n;
	
	int arr[n+1];
	for(int i=1;i<=n;i++)
	    cin >> arr[i];
	
	sort(arr+1,arr+n+1);
	
	int l = 1;
	int r = 1;
	int ans = 0;
	
	while(l<=r && r<=n)
	{
	    if(arr[r]-arr[l] <= 5)
	        ans = max(ans,r-l+1);
	    else
	    {
	        while(arr[r]-arr[l] > 5 && l <= r)
	            l++;
	    }
	    r++;
	}
	
	cout << ans << endl;
	return 0;
}
