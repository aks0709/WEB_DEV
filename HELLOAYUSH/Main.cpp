#include<bits/stdc++.h>

using namespace std;

bool solveRecMem(vector<int> &arr, int n, int index, int target, vector<vector<int>>& dp) {

	if (target == 0) {
		return true;
	}

	if (index >= n) {
		return false;
	}

	if (target < 0) {
		return false;
	}

	if (dp[index][target] != -1) {
		return dp[index][target];
	}

	bool include = solveRecMem(arr, n, index + 1, target - arr[index], dp);
	bool exclude = solveRecMem(arr, n, index + 1, target, dp);

	return dp[index][target] || include || exclude;
}


bool canPartition(vector<int> &arr, int n)
{

	int totalSum = 0;
	for (int i : arr) {
		totalSum += i;
	}


	if (totalSum % 2 == 1) {
		return false;
	}

	int partSum = totalSum / 2;

	vector<vector<int>> dp(n + 1, vector<int>(partSum + 1, -1));


	return solveRecMem(arr, n, 0, partSum, dp);
}

void solve() {
	int n;
	cin >> n;
	vector<int>arr(n);
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}

	if (canPartition(arr, n)) {
		cout << "true" << endl;
	}
	else cout << "false" << endl;

}


int main() {

// #ifndef ONLINE_JUDGE
// 	freopen("input.txt", "r", stdin);
// 	freopen("output.txt", "w", stdout);
// #endif

	int t;
	cin >> t;
	while (t--) solve();

	return 0;
}