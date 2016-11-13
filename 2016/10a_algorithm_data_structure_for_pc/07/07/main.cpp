#include <algorithm>
#include <cstdio>
#include <cmath>
#include <iostream>
#include <queue>
#include <string>
#include <set>
#include <vector>

#define FOR(i, l, r) for (i = (l); i < r; i++ )

using namespace std;
typedef long long ll;
#define MAX_N (1010)
#define MAX_V (10010)

int n;
int A[MAX_N];
int g_min = MAX_V;		// global min
int B[MAX_N];			// sorted array
int T[MAX_V];			// index of sorted array
bool V[MAX_N];			// check whether it is already used.

int solve() {

    for ( int i = 0; i < n; i++ ) {
	V[i] = false;
	B[i] = A[i];
    }

    sort(B, B + n);

    for ( int i = 0; i < n; i++ ) {
	T[B[i]] = i;
    }

    int ret = 0;
    for ( int i = 0; i < n; i++ ) {
	if ( V[i] ) continue;
	// has not visited yet.
	int cur = i;
	int num = 0;
	int l_min = MAX_V;	// local min
	int sum_l = 0;
	while ( 1 ) {
	    V[cur] = true;
	    num++;
	    l_min = min(l_min, A[cur]);
	    sum_l += A[cur];
	    cur = T[A[cur]];
	    if ( V[cur] ) break; // 
	}

	int c0 = sum_l + (num - 2) * l_min;
	int c1 = sum_l + l_min + (num + 1) * g_min;
	ret += min(c0, c1);
    }
    return ret;
}

int main()
{
    scanf("%d", &n);
    
    for ( int i = 0; i < n; i++ ) {
	scanf("%d", &A[i]);
	g_min = min(g_min, A[i]);
    }

    int ans = solve();
    printf("%d\n", ans);

    return 0;
}
