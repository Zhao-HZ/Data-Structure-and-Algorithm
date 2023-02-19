#include <bits/stdc++.h>
#include <algorithm>

using namespace std;

static bool min(int &a, int &b) {
	return a > b;
}

int main() {
	int arr[] = {3, 1, 4, 5};
	sort(arr, arr + 4, greater<int>());
	for (auto x : arr) {
		printf("%d\n", x);
	}
	return 0;
}
