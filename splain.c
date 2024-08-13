#include<stdio.h>
#include <string.h>
struct point
{
  double x;
  double y;
};

int main(int argc, char const *argv[]) {
  int csv = 0, t = 50;
if (argc == 2) {
  if (!strcmp(argv[1], "csv")) {
    csv = 1;
  }
  else if (!strcmp(argv[1], "nocsv")) {
    csv = -1;
  }
}
  long N;
  for (;;) {
    if (csv != 1) printf("Число точек: \n");
    scanf("%ld",&N );
    if (N >= 5) break;
    if (csv != 1) printf("Число точек должно быть больше или равно 5\n");
  }
  struct point tochka[N-1];
  double a[N], b[N-1], c[N], d[N-1], h[N-1], a2[N-1], l[N], m[N], z[N], s, x, y;
  if (csv != 1) printf("Координаты точек\n");
  for (size_t i = 0; i < N; i++) {
    if (csv != 1) printf("Точка %ld: ", i+1);
    scanf("%lf %lf", &tochka[i].x, &tochka[i].y);
  }
  if (csv != 1) printf("\n");
  for (size_t i = 0; i < N; i++) {
    if (csv != 1) printf("Точка %ld = (%0.3lf, %0.3lf)\n", i+1, tochka[i].x, tochka[i].y);
  }
  if (csv == 0) printf("Сколько точек вычислить между xi и xi+1\n");
  if (csv != -1) scanf("%d", &t);

  for (size_t i = 0; i < N; i++) a[i] = tochka[i].y;

  for (size_t i = 0; i <= N-2; i++) {
    h[i] = tochka[i+1].x - tochka[i].x;
  }

  for (size_t i = 1; i <= N-2; i++) {
    a2[i] = 3*(a[i+1]-a[i])/h[i]-3*(a[i]-a[i-1])/h[i-1];
  }

  l[0]=1;
  m[0]=0;
  z[0]=0;

  for (size_t i = 1; i <= N-2; i++) {
    l[i] = 2*(tochka[i+1].x-tochka[i-1].x)-h[i-1]*m[i-1];
    m[i] = h[i]/l[i];
    z[i] = (a2[i]-h[i-1]*z[i-1])/l[i];
  }

  l[N] = 1;
  z[N] = 0;
  c[N] = 0;

  for (int i = N-2; i >= 0; i--) {
    c[i] = z[i]-m[i]*c[i+1];
    b[i] = (a[i+1]-a[i])/h[i]-h[i]*(c[i+1]+2*c[i])/3;
    d[i] = (c[i+1]-c[i])/(3*h[i]);
  }

  for (size_t i = 0; i < N-1; i++) {
    if (csv != 1) printf("a[%ld]=%0.3lf, b[%ld]=%0.3lf, c[%ld]=%0.3lf, d[%ld]=%0.3lf\n", i, a[i], i, b[i], i, c[i], i, d[i]);
  }

  if (csv != -1) {
    printf("\n");
      for (size_t i = 0; i < N-1; i++) {
      s = h[i]/t;
      x = tochka[i].x;
      if (csv != -1) printf("%0.4lf,%0.4lf\n", tochka[i].x, tochka[i].y);
        for (size_t j = 0; j < t-1; j++) {
          x = x+s;
          y = a[i] + b[i]*(x-tochka[i].x)+c[i]*(x-tochka[i].x)*(x-tochka[i].x)+d[i]*(x-tochka[i].x)*(x-tochka[i].x)*(x-tochka[i].x);
          if (csv != -1) printf("%0.4lf,%0.4lf\n", x, y);
        }
      }
    if (csv != -1 || csv) printf("%0.4lf,%0.4lf\n", tochka[N-1].x, tochka[N-1].y);
  }
  return 0;
}
// 1 2 2 3 4 1 7 4
