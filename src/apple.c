#include <stdio.h>

int n;
int k;
int A[100000];

int ok(int x) {
    int i;
    int cnt = 0;
    for (i = 0; i < n; i++) {
        cnt += (A[i] - 1) / x + 1;
        if (cnt > k) return 0;
    }
    return 1;
}

int main(){
  int i, lb, ub;
  scanf("%d%d", &n, &k);
  for(i = 0; i < n; i++){
    scanf("%d", &A[i]);
  }

  ub = 1000000000;
  lb = 0;
  while (ub - lb > 1) {
      int m = (ub + lb) / 2;
      if (ok(m)) ub = m;
      else lb = m;
  }

  printf("%d\n", ub);

  return 0;
}
