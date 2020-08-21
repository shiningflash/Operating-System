// SJF SCHEDULING=

#include <bits/stdc++.h>
using namespace std;

struct info {
	int id, arrivaltime, processtime;
};

int main() {
	// freopen("in.txt", "r", stdin);
	// freopen("out.txt", "w", stdout);

	int mx = 0, n, x, y, s = 0, sum = 0;
	cin >> n;
	vector <info> process;
	for (int i = 1; i <= n; i++) {
		cin >> x >> y;
		process.push_back({i, x, y});
		sum += y;
	}
	int mn_ = INT_MAX, id_ = 0, tmpx = INT_MAX;
	for (int j = 0; j < n; j++) {
		if (process[j].processtime < mn_ && process[j].arrivaltime < tmpx) {
			mn_ = process[j].processtime;
			id_ = process[j].id;
			s = process[j].arrivaltime;
			tmpx = process[j].arrivaltime;
		}
	}
	printf("Id\tST\tET\n");
	for (int i = 0; i <= sum; i++) {
		int mn = INT_MAX, tmp = 0;
		for (int j = 0; j < n; j++) {
			if (process[j].processtime < mn && i >= process[j].arrivaltime) {
				mn = process[j].processtime;
				tmp = process[j].id;
			}
		}
		process[id_].processtime = process[id_].processtime - 1;
		if (i == sum) {
			printf("%d\t%d\t%d\n", id_, s, i);
		}
		if (id_ == tmp) {
		}
		else {
			printf("%d\t%d\t%d\n", id_, s, i);
			id_ = tmp;
			s = i;
		}
	}


	// cout << "\nAverage: " << (sum / n * 1.0) << endl;
}

/*
INPUT:
4
0 8
1 4
2 9
3 5

OUTPUT:
Id	ST	ET
1	0	1
2	1	10
3	10	17
4	17	26
*/
