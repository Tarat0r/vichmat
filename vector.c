#include <stdio.h>
#include <stdlib.h>



int main() {
  int n, m;
  float ratio, det;
  printf("Скалярное или векторное произведение в n-мерном пространстве\n");
  printf("n равно:");
  scanf("%d", &n); if (n < 2) return 0;
  printf("число векторов:");
  scanf("%d", &m); if (m < 2) return 0;
  float arr[m+1][n];
  float arr2[m+1][n];
  int n2=n-1;

  for (size_t i = 0; i <= n; i=i+2) {
    arr[m][i] = 1;
  }
  for (size_t i = 1; i <= n; i=i+2) {
    arr[m][i] = -1;
  }


  printf("Координаты %d-мерных векторов\n",n);
  for (size_t i = 0; i < m; i++) {
    for (size_t j = 0; j < n; j++)
      scanf("%f", &arr[i][j]);
}

  for (size_t i = 0; i < m; i++) {
    printf("Вектор %ld = {", i+1);
    printf("%0.3f", arr[i][0]);
    for (size_t j = 1; j < n; j++) printf(", %0.3f", arr[i][j]);
    printf("}\n");
  }

  //Скалярное произведение
  float sproizvedenie = 0;
  for (size_t i = 0; i < n; i++) {
  sproizvedenie = sproizvedenie + arr[0][i] * arr[1][i];
  }
  printf("Скалярное произведение векторов 1 и 2 = %0.3f\n", sproizvedenie);

  if (n-1 != m && (n != 2 && m != 2)) {
    printf("Нельзя посчитать векторное произведение\n");
    return 0;
  }
  if (n == 2 && m == 2) {
    printf("Векторное произведение = {0, 0, %0.3f}\n", arr[0][0]*arr[1][1]-arr[0][1]*arr[1][0]);
  }
  else{
    int v;
    for (size_t i = 0; i < n; i++) {
      for (size_t k = 0; k < m; k++) {
        v=0;

        for (size_t j = 0; j < n; j++) {
          if (j==i) v++;

          arr2[k][j] = arr[k][v];
          v++;

        }
      }

      for (size_t i = 0; i < m; i++) {
        for (size_t j = 0; j < n2; j++) printf("%0.2f ", arr2[i][j]);
        printf("\n");
      }
      //---
      det =1;
      for(size_t i=0;i< n2;i++)
      {
         for(size_t j=i+1;j< n2;j++)
         {
            ratio = arr2[j][i]/arr2[i][i];

            for(size_t k=0;k< n2;k++)
            {
               arr2[j][k] = arr2[j][k] - ratio*arr2[i][k];
            }
         }
      }

      for(size_t i=0;i< n2;i++)
        {
            det = det * arr2[i][i];
        }

      printf("Данная матрица имеет детерминат: %0.3f\n\n", det);
      //---


      arr[m][i] = arr[m][i] * det;
    }

    printf("Векторное произведение = {%0.3f", arr[m][0]);
    for (size_t i = 1; i < n; i++) {
      printf(", %0.3f",arr[m][i]);
    }
    printf("}\n");
  }
//3 2 1 2 3 3 4 5


  return 0;


}
