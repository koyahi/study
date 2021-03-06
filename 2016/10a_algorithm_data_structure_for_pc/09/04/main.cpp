#include <algorithm>
#include <cstdio>
#include <cmath>
#include <iostream>
#include <queue>
#include <string>
#include <set>
#include <vector>
#include <stdlib.h>

#define FOR(i, l, r) for (i = (l); i < r; i++ )

using namespace std;
typedef long long ll;

#define MAX_N (500010)

struct Node{
    int key;
    Node *p_p;
    Node *p_l;
    Node *p_r;
};

int m;

Node *T = NULL;


void insert(int k) {
    Node *p_y = NULL;		// parent of x
    Node *p_x = T;
    Node *p_z = (Node *)malloc(sizeof(Node));
    
    p_z->key = k;
    p_z->p_p = p_z->p_l = p_z->p_r = NULL;

    while ( p_x != NULL ) {
	p_y = p_x;
	if ( k < p_x->key ) {
	    p_x = p_x->p_l;
	}
	else {
	    p_x = p_x->p_r;
	}
    }

    p_z->p_p = p_y;		// parent of z is y.
    
    if ( p_y == NULL ) {		// T is NULL.
	T = p_z;
    }
    else if ( k < p_y->key ) {	// z is left child of y.
	p_y->p_l = p_z;

    }
    else {			// z is right child of y.
	p_y->p_r = p_z;
    }

    return;
}

void preorder( vector<int> *p_v, Node *p_x ) {
    if ( p_x == NULL ) return;
    else {
	p_v[0].push_back(p_x->key);
	preorder(p_v, p_x->p_l);
	preorder(p_v, p_x->p_r);	
    }
    
    return;
}

void inorder( vector<int> *p_v, Node *p_x ) {
    if ( p_x == NULL ) return;
    else {
	inorder(p_v, p_x->p_l);
	p_v[0].push_back(p_x->key);	
	inorder(p_v, p_x->p_r);	
    }
    
    return;
}

Node* find( Node *p_x, int k ) {
    if ( p_x == NULL || (k == p_x->key) ) return p_x;
    else if ( k < p_x->key ) {
	return find( p_x->p_l, k );
    }
    else {
	return find( p_x->p_r, k );
    }
}

void delete_node( Node *p_x ) {
    if ( p_x == NULL ) return;
    
    if ( (p_x->p_l == NULL) && (p_x->p_r == NULL) ) {
	if ( p_x == p_x->p_p->p_l ) {
	    p_x->p_p->p_l = NULL;
	}
	else {
	    p_x->p_p->p_r = NULL;
	}
	free(p_x);    	
    }
    else if ( (p_x->p_r == NULL) ) { // Left child exists.
	if ( p_x == p_x->p_p->p_l ) {
	    p_x->p_p->p_l = p_x->p_l;
	}
       	else {
	    p_x->p_p->p_r = p_x->p_l;
	}

	p_x->p_l->p_p = p_x->p_p;
	free(p_x);    	
    }
    else if ( (p_x->p_l == NULL ) ) { // Right child exists.
	if ( p_x == p_x->p_p->p_l ) {
	    p_x->p_p->p_l = p_x->p_r;
	}
	else {
	    p_x->p_p->p_r = p_x->p_r;
	}

	p_x->p_r->p_p = p_x->p_p;	
	free(p_x);    		
    }
    else { 			// Both children exist.
	// Find successor.
	Node *p_s = p_x->p_r;
	while ( p_s->p_l != NULL ) {
	    p_s = p_s->p_l;
	}

	p_x->key = p_s->key;
	delete_node(p_s);
    }

    return;
}

int main()
{
    scanf("%d", &m);
    for ( int i = 0; i < m; i++ ) {
	char str[100];
	scanf("%s", str);
	if ( str[0] == 'i' ) {	// insert
	    int k;
	    scanf("%d", &k);
	    insert(k);
	}
	else if ( str[0] == 'f' ) { // find
	    Node *p_x;
	    int k;
	    scanf("%d", &k);
	    p_x = find(T, k);
	    printf("%s\n", (p_x != NULL) ? "yes" : "no" );
	}
	else if ( str[0] == 'd' ) { // delete
	    Node *p_x;
	    int k;
	    scanf("%d", &k);
	    p_x = find(T, k);
	    if ( p_x != NULL ) delete_node(p_x);
	}
	else {			// print
	    vector<int> pre;
	    vector<int> in;
	    preorder( &pre, T );
	    inorder( &in, T );

	    for ( int i = 0; i < in.size(); i++ ) {
		printf(" %d", in[i]);
	    }
	    printf("\n");
	    for ( int i = 0; i < pre.size(); i++ ) {
		printf(" %d", pre[i]);
	    }
	    printf("\n");	    
	}
    }
    
    return 0;
}
