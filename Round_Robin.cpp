// Round Robin

#include <bits/stdc++.h>
using namespace std;

struct info {
	int id, processtime;
};

int main() {
	// freopen("in.txt", "r", stdin);
	// freopen("out.txt", "w", stdout);

	int n, x, s = 0, sum = 0, m;
	cin >> n >> m; // n = total process, m = time quantam
	queue <info> process;
	for (int i = 1; i <= n; i++) {
		cin >> x;
		process.push({i, x});
	}
	printf("Id\tST\tET\n");
	while (!process.empty()) {
		info tmp = process.front();
		process.pop();

		int tmp1 = tmp.id;
		int tmp2 = tmp.processtime;
		int tmp3 = min(m, tmp2);
		if (tmp2 - tmp3 > 0) process.push({tmp1, tmp2 - tmp3});
		printf("%d\t%d\t%d\n", tmp1, sum, sum + tmp3);
		sum += tmp3;
	}
	cout << "\nAverage: " << (sum / n * 1.0) << endl;
}
