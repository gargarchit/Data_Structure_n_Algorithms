
// Problem Link:
// https://www.spoj.com/problems/AGGRCOW/

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
