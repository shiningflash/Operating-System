// PRIORITY SCHEDULING

#include <bits/stdc++.h>
using namespace std;

struct info {
	int priority, id, processtime, waitingtime, endtime;
};

bool cmp(info a, info b) {
    return (a.priority < b.priority);
}

int main() {
	// freopen("in.txt", "r", stdin);
	// freopen("out.txt", "w", stdout);

	int n, x, y, s = 0, sum = 0;
	cin >> n;
	vector <info> process;
	for (int i = 1; i <= n; i++) {
		cin >> x >> y;
		process.push_back({y, i, x, 0, 0});
	}
	sort(process.begin(), process.end(), cmp);
	for (int i = 0; i < n; i++) {
		x = process[i].processtime;
		sum += s;
		process[i].waitingtime = s;
		process[i].endtime = s+x;
		s += x;
	}
	printf("Id\tProcess Time\tPriority\tWaiting Time\tEnd Time\n");
	for (int i = 0; i < n; i++) {
		printf("%d\t\t%d\t\t%d\t\t%d\t\t%d\n", process[i].id, process[i].processtime, process[i].priority, process[i].waitingtime, process[i].endtime);
	}
	cout << "\nAverage: " << (sum / n * 1.0) << endl;
}

/*
INPUT:
5
10 3
1 1
2 4
1 5
5 2

OUTPUT:
Id	Process Time	Priority	Waiting Time	End Time
2		1		1		0		1
5		5		2		1		6
1		10		3		6		16
3		2		4		16		18
4		1		5		18		19

Average: 8
*/
