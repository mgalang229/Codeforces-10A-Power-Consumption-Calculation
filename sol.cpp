#include <bits/stdc++.h>

using namespace std;

struct Interval {
	int start;
	int end;
};

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n, p1, p2, p3, t1, t2;
	cin >> n >> p1 >> p2 >> p3 >> t1 >> t2;
	int mn = INT_MAX;
	int mx = INT_MIN;
	vector<Interval> a(n);
	// view the image in this repository for better understanding
	for (int i = 0; i < n; i++) {
		cin >> a[i].start >> a[i].end;
		// determine the starting and ending time
		mn = min(mn, a[i].start);
		mx = max(mx, a[i].end);
	}
	int ans = 0;
	int mode = 0;
	int change = 0;
	int id = 0;
	// brute-force approach: take the watts per minute
	// terminologies used:
	// 'active' interval = Tom moves the mouse or touches the keyboard
	// 'inactive' interval = Tom stays away from the laptop
	for (int minute = mn + 1; minute <= mx; minute++) {
		// if the minute is within the 'active' interval, then the mode will be p1
		// and if the end time of the interval is reached, determine the time wherein it will switch to p2
		if (minute >= a[id].start && minute <= a[id].end) {
			mode = p1;
			change = 0;
			if (minute == a[id].end && id < n) {
				change = minute + t1;
				id++;
			}
		}
		// if the switch-to-p2 is reached, then change the mode to p2
		// and determine the time wherein it will switch to p3
		if (minute == change && mode == p1) {
			mode = p2;
			change = minute + t2;
		}
		// if the switch-to-p3 is reached, then change the mode to p3
		if (minute == change && mode == p2) {
			mode = p3;
			change = 0;
		}
		// for every minute, keep adding the watts (depending on the mode)
		ans += mode;
	}
	cout << ans << '\n';
	return 0;
}
