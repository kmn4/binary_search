#include <stdio.h>
#define sum(i,j) s[j+1]-s[i]

int n;
int k;
int A[100000];
int s[100001];

int p(int x)
{
    int i;
    int idx = 0;
    int cnt = 0;

    for (i = 0; i < n; i++) {
        if (sum(idx, i) > x) {
            if (idx == i) return 0;
            idx = i;
            i--;
            cnt++;
        }
        if (cnt == k) return 0;
    }

    return 1;
}

int main(){
  int i, lb, ub;
  scanf("%d%d", &n, &k);
  s[0] = 0;
  for(i = 0; i < n; i++){
    scanf("%d", &A[i]);
    s[i+1] = s[i] + A[i];
  }

  lb = 0;
  ub = 1000000000;

  while (ub - lb > 1) {
      int m = (ub + lb) / 2;
      if (p(m)) ub = m;
      else lb = m;
  }

  printf("%d\n", ub);

  return 0;
}
