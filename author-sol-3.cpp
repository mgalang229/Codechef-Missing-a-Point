#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int tt;
	cin >> tt;
	while (tt--) {
		int n;
		cin >> n;
		int sz = 4 * n - 1;
		int ans_x = 0;
		int ans_y = 0;
		for (int i = 0; i < sz; i++) {
			int x, y;
			cin >> x >> y;
			// use XOR technique to find the element with odd frequency
			ans_x ^= x;
			ans_y ^= y;
		}
		// key observation: x and y coordinates contain an even number of points because
		// of the placement of the rectangles (either 0 or an even number)
		// therefore, a rectangle with a missing vertex means that an x-coordinate and
		// y-coordinate contain an odd number of points (this is the answer)
		cout << ans_x << " " << ans_y << '\n';
	}
	return 0;
}
