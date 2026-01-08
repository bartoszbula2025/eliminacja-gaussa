#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void gauss_elimination(int n, double a[n][n], double b[n])
{
    double factor;
    
    for (int i = 0; i < n - 1; i++)
    {
        // wybor glownego elementu
        int max_row = i;
        double max = fabs(a[i][i]);

        for (int r = i + 1; r < n; r++)
        {
            if (fabs(a[r][i]) > max)
            {
                max = fabs(a[r][i]);
                max_row = r;
            }
        }

        if (max == 0)
        {
            printf("Blad: macierz osobliwa (kolumna %d)\n", i);
            exit(1);
        }

        // eliminacja
        for (int j = i + 1; j < n; j++)
        {
            factor = a[j][i] / a[i][i];
            
            for (int k = i; k < n; k++)
            {
                a[j][k] -= factor * a[i][k];
            }
            
            b[j] -= factor * b[i];
        }
    }
}
