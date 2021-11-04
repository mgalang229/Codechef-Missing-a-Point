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
		map<int, int> X, Y;
		for (int i = 0; i < sz; i++) {
			int x, y;
			cin >> x >> y;
			// count the frequency of every element
			X[x]++;
			Y[y]++;
		}
		// key observation: x and y coordinates contain an even number of points because
		// of the placement of the rectangles (either 0 or an even number)
		// therefore, a rectangle with a missing vertex means that an x-coordinate and
		// y-coordinate contain an odd number of points (this is the answer)
		int ans_x = -1;
		for (auto& i : X) {
			if (i.second & 1) {
				ans_x = i.first;
			}
		}
		int ans_y = -1;
		for (auto& i : Y) {
			if (i.second & 1) {
				ans_y = i.first;
			}
		}
		cout << ans_x << " " << ans_y << '\n';
	}
	return 0;
}
