// @author: Amirul Islam

#include <bits/stdc++.h>
using namespace std;

struct info {
    string id;
    int at, bt;
};

int main() {
    // freopen("in", "r", stdin);
    int n, x, y, z, sum = 0;
    string sid;
    cin >> n;
    info a[n];
    int w[n];
    int b[n];
    for (int i = 0; i < n; i++) {
        cin >> sid >> y >> z;
        a[i].id = sid;
        a[i].at = y;
        a[i].bt = z;
        b[i] = z;
        sum += z;
    }

    // SJF scheduling -- PREEMPTIVE
    int tmp = 0, m = 0;
    for (int i = 1; i <= sum; i++) {
        x = INT_MAX, z = 0;
        for (int j = 0; j < n; j++) {
            if (a[j].at < i && b[j] != 0) {
                if (b[j] < x) {
                    x = b[j];
                    z = j;
                }
            }
        }
        b[z]--;
        if (b[z] == 0) w[z] = i - a[z].at - a[z].bt;

        if (tmp != z) cout << "(" << m << " - " << i-1 << ") - " << a[tmp].id << endl, m = i;
        tmp = z;
    }
    cout << "(" << m << " - " << sum << ") - " << a[tmp].id << endl;

    // avg waiting time
    int sumWt = 0;
    for (int i = 0; i < n; i++) sumWt += w[i];
    cout << "\navg wt time: " << (sumWt * 1.0 / n) << endl;
}

/*
INPUT:
4
p1 0 8
p2 1 4
p3 2 9
p4 3 5

OUTPUT:
(0 - 1) - p1
(2 - 5) - p2
(6 - 10) - p4
(11 - 17) - p1
(18 - 26) - p3

avg wt time: 6.5
*/
