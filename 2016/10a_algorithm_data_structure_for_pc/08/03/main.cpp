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

typedef struct {
    int p;			// parent
    int l;			// left child
    int r;			// right child
    int dep;			// depth
    int hei;			// height
    bool is_l;			// whether this is left child.
    int deg;		// the number of children.
} Node;

#define MAX_N (30)
#define NIL (-1)
int n;
Node N[MAX_N];

void output( int id ) {
    int sib = -1;
    char type[100];

    if ( N[id].p != NIL ) {
	if ( N[id].is_l ) 
	    sib = N[N[id].p].r;
	else 
	    sib = N[N[id].p].l;
    }

    if ( N[id].p == NIL )
	sprintf( type, "root" );
    else if ( N[id].l == NIL && N[id].r == NIL ) 
	sprintf( type, "leaf" );
    else 
	sprintf( type, "internal node" );
	
    printf("node %d: ", id);
    printf("parent = %d, ", N[id].p );
    printf("sibling = %d, ", sib );
    printf("degree = %d, ", N[id].deg );
    printf("depth = %d, ", N[id].dep );
    printf("height = %d, ", N[id].hei );
    printf("%s", type );
    printf("\n");
    return;
}

int set_depth_height( int id, int dep ) {
    N[id].dep = dep;
    int h0 = 0;
    int h1 = 0;
    if ( N[id].l != NIL ) {
	h0 = set_depth_height( N[id].l, dep + 1 ) + 1;
    }

    if ( N[id].r != NIL ) {
	h1 = set_depth_height( N[id].r, dep + 1 ) + 1;
    }

    N[id].hei = max(h0, h1);

    return N[id].hei;
}

int main()
{
    scanf("%d", &n);
    for ( int i = 0; i < n; i++ ) {
	N[i].p = N[i].l = N[i].r = NIL;
    }

    for ( int i = 0; i < n; i++ ) {
	int id;
	scanf("%d", &id);
	scanf("%d %d", &N[id].l, &N[id].r);
	if (N[id].l != -1 ) {
	    N[id].deg++;
	    N[N[id].l].is_l = true;
	    N[N[id].l].p = id;
	}

	if (N[id].r != -1 ) {
	    N[id].deg++;	
	    N[N[id].r].is_l = false;
	    N[N[id].r].p = id;
	}
    }

    int root = -1;
    for ( int i = 0; i < n; i++ ) {
	if ( N[i].p == NIL ) {
	    root = i;
	    break;
	}
    }

    set_depth_height( root, 0 );

    for ( int i = 0; i < n; i++ ) {
	output( i );
    }

    return 0;
}
