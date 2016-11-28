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

#define MAX_N (100010)
#define NIL (-1)

typedef struct {
    int par;
    int l_c;			// left child
    int r_s;			// right sibling
    int dep;			// depth
} Node;

Node tree[MAX_N];

int get_depth( int id ) {
    if ( id == NIL ) return -1;
    if ( tree[id].dep != -1 ) return tree[id].dep;
    else {
	int r_s = tree[id].r_s;
	tree[id].dep = 1 + get_depth( tree[id].par );

	while ( r_s != NIL ) {
	    tree[r_s].dep = tree[id].dep;
	    r_s = tree[r_s].r_s;
	}

	return tree[id].dep;
    }
}

void output( int id ) {
    char type[100];
    vector<int> children;
    int cur_chi = tree[id].l_c;

    if ( tree[id].par == NIL ) sprintf( type, "root" );
    else if ( tree[id].l_c == NIL ) sprintf( type, "leaf" );
    else sprintf( type, "internal node" );
	
    while ( cur_chi != NIL ) {
	children.push_back( cur_chi );
	cur_chi = tree[cur_chi].r_s;
    }

    printf("node %d: ", id);
    printf("parent = %d, ", tree[id].par );
    printf("depth = %d, ", tree[id].dep );
    printf("%s, ", type );
    printf("[");

    for ( int i = 0; i < children.size(); i++ ) {
	printf("%d", children[i]);
	if ( i < children.size() - 1 ) printf(", ");
    }
    printf("]\n");

    return;
}

int main()
{
    int n;
    scanf("%d", &n);
    for ( int i = 0; i < n; i++ ) {
	tree[i].par = tree[i].l_c = tree[i].r_s = NIL; 
	tree[i].dep = -1;
    }

    for ( int i = 0; i < n; i++ ) {
	int id;
	int k;
	int pre_chi = NIL;
	scanf("%d %d", &id, &k);

	// k個のchild
	for ( int j = 0; j < k; j++ ) {
	    int chi;
	    scanf("%d", &chi);
	    // 子の親はid
	    tree[chi].par = id;

	    if ( j == 0 ) {	// 左の子
		tree[id].l_c = chi;
	    }
	    else if ( j < k ) { // 右の兄弟
		tree[pre_chi].r_s = chi;
	    }
	    pre_chi = chi;
	}
    }
    int root = NIL;
    // rootを見つける
    {
	int cur = 0;
	while ( true ) {
	    if ( tree[cur].par == NIL ) {
		root = cur;
		break;
	    }
	    cur = tree[cur].par;
	}
    }

    // 各ノードの深さを求める
    for ( int i = 0; i < n; i++ ) {
	if ( tree[i].dep == -1 ) get_depth( i );
    }

    for ( int i = 0; i < n; i++ ) {
	output(i);
    }
    
    return 0;
}
