#include <algorithm>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <iostream>
#include <queue>
#include <string>
#include <set>
#include <vector>

#define FOR(i, l, r) for (i = (l); i < r; i++ )

using namespace std;
typedef long long ll;

#define MAX_N (2000010)
#define MAX_K (10010)
int A[MAX_N];
int C[MAX_K];			// temporal array
int B[MAX_N];

int counting_sort(int A[], int B[], int k, int n) {
    int i;

    memset(C, 0, k * sizeof(int));
    
    // counts the number.
    FOR(i, 0, n) C[A[i]]++;

    FOR(i, 1, k+1) C[i] += C[i-1];

    for ( i = n-1; i >= 0; i-- ) {
	B[C[A[i]]-1] = A[i];
	C[A[i]]--;
    }
}

int main()
{
    int i;
    int n;
    scanf("%d", &n);
    for ( i = 0; i < n; i++ ) {
	scanf("%d", &A[i]);
    }

    counting_sort(A, B, MAX_K-1, n);

    FOR( i, 0, n ) {
	printf("%d%c", B[i], (i==n-1) ? '\n' : ' ');
    }

    return 0;
}
