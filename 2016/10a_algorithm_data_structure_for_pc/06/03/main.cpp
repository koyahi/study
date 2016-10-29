#include <algorithm>
#include <cstdio>
#include <cmath>
#include <iostream>
#include <queue>
#include <string>
#include <set>
#include <vector>

using namespace std;
typedef long long ll;
typedef pair<double, double> P;
int n;
double cos60 = cos(60.0 / 180.0 * M_PI);
double sin60 = sin(60.0 / 180.0 * M_PI);

void koch(int n, P p1, P p2) {
    if ( n == 0 ) {
	printf("%lf %lf\n", p1.first, p1.second);
    }
    else {
	P d = make_pair(p2.first - p1.first, p2.second - p1.second);
	P e = make_pair(d.first / 3.0, d.second / 3.0);
	P s = make_pair(p1.first + e.first, p1.second + e.second);

	P r = make_pair(cos60 * e.first - sin60 * e.second, sin60 * e.first + cos60 * e.second);

	P t = make_pair(s.first + r.first, s.second + r.second);
	P u = make_pair(s.first + e.first, s.second + e.second);
    
	koch(n - 1, p1, s);
	koch(n - 1, s, t);
	koch(n - 1, t, u);
	koch(n - 1, u, p2);
    }
    return;
}

int main()
{
    P l = make_pair(0.0, 0.0);
    P r = make_pair(100.0, 0.0);

    scanf("%d", &n);
    koch(n, l, r);
    printf("%lf %lf\n", r.first, r.second);
    return 0;
}
