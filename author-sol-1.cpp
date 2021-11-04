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
		vector<int> x, y;
		for (int i = 0; i < sz; i++) {
			int X, Y;
			cin >> X >> Y;
			x.push_back(X);
			y.push_back(Y);
		}
		// key observation: x and y coordinates contain an even number of points because
		// of the placement of the rectangles (either 0 or an even number)
		// therefore, a rectangle with a missing vertex means that an x-coordinate and
		// y-coordinate contain an odd number of points (this is the answer)
		// sort the x-coordinates and y-coordinates
		sort(x.begin(), x.end());
		sort(y.begin(), y.end());
		int ans_x = -1;
		int ans_y = -1;
		auto FindOdd = [&](vector<int>& x) -> int {
			int i, j;
			// determine the frequency of every element:
			// create two pointers, i = start of the number and j = moving pointer every time
			// a number appears again (get the difference to find the frequency of a number)
			for (i = 0; i < (int) x.size(); i = j) {
				j = i;
				while (j < (int) x.size() && x[i] == x[j]) {
					j++;
				}
				if ((j - i) & 1) {
					return x[i];
				}
			}
			return -1;
		};
		ans_x = FindOdd(x);
		ans_y = FindOdd(y);
		cout << ans_x << " " << ans_y << '\n';
	}
	return 0;
}
