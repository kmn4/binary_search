#include <stdio.h>

int n;
int k;
int A[100000];

int ok(int x) {
    int spears = 0;
    int i;
    for (i = 0; i < n; i++) {
        spears += A[i] / x;
        if (spears >= k) return 1;
    }

    return 0;
}

int main(){
  int i, lb, ub;
  scanf("%d%d", &n, &k);
  for(i = 0; i < n; i++){
    scanf("%d", &A[i]);
  }

  ub = 1000000001;
  lb = 0;
  while (ub - lb > 1) {
      int m = (ub + lb) / 2;
      if (ok(m)) lb = m;
      else ub = m;
  }

  printf("%d\n", lb);

  return 0;
}
