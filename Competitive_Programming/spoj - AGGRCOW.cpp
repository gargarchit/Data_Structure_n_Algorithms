
// Problem : AGGRCOW - Aggressive cows
// Link : https://www.spoj.com/problems/AGGRCOW/

/*
Farmer John has built a new long barn, with N (2 <= N <= 100,000) stalls. 
The stalls are located along a straight line at positions x1,...,xN (0 <= xi <= 1,000,000,000).

His C (2 <= C <= N) cows don't like this barn layout and become aggressive towards each other once put into a stall. 
To prevent the cows from hurting each other, FJ wants to assign the cows to the stalls, such that the minimum distance 
between any two of them is as large as possible. What is the largest minimum distance?

Input
t – the number of test cases, then t test cases follows.
Line 1: Two space-separated integers: N and C
Lines 2..N+1: Line i+1 contains an integer stall location, xi

Output
For each test case output one integer: the largest minimum distance.

Sample Input:

1
5 3
1
2
8
4
9

Sample Output:

3

*/


// Algo used - binary search

#include <iostream>
#include <math.h>
#include <vector>
#include <algorithm>
using namespace std;

#define all(x) x.begin(), x.end()
#define ll long long int

bool canCCowsBePlaced (vector<ll>& arr, ll c, ll dist) {
	ll size = arr.size();

	ll i = 0;
	ll j = 1;

	c--;

	while (i < j and j < size) {
		ll sep = arr[j] - arr[i];

		if (sep >= dist) {
			i = j;
			j++;
			c--;

			if (c == 0)
				return true;
		}
		else
			j++;
	}

	return false;
}

int main() {

	ll t;
	cin >> t;

	while (t--) {
		ll n, c;
		cin >> n >> c;

		vector<ll> arr(n);

		for (int i = 0; i < n; ++i)
			cin >> arr[i];
        
        
		sort(all(arr));

		ll start = 0;
		ll end = arr[n - 1] - arr[0];
		ll ans = 0;

		while (start <= end) {
			ll mid = (start + end) / 2;

			bool valid = canCCowsBePlaced(arr, c, mid);

			if (valid) {
				ans = mid;
				start = mid + 1;
			}
			else {
				end = mid - 1;
			}
		}

		cout << ans << "\n";
	}

	return 0;
}
