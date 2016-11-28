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
#define MAX_N (105)
int n;

int pre[MAX_N];
int in[MAX_N];
int pos;
int printed;

void dfs(int l, int r) {
    if ( r - l <= 0 ) return;
    int num = pre[pos++];
    int pos_in;
    // linear search.
    for ( int i = l; i < r; i++ ) {
	if ( in[i] == num ) {
	    pos_in = i;
	    break;
	}
    }

    dfs( l, pos_in );
    dfs( pos_in + 1, r );
    printf("%d%c", num, ((printed == n - 1) ? '\n' : ' '));
    printed++;
}

int main()
{
    scanf("%d", &n);
    for ( int i = 0; i < n; i++ ) scanf("%d", &pre[i]);
    for ( int i = 0; i < n; i++ ) scanf("%d", &in[i]);

    dfs(0, n);

    return 0;
}
