#include <stdio.h>
#include <stdlib.h>

void gauss_elimination(int n, double a[n][n], double b[n])
{
    double factor;
    
    for (int i = 0; i < n - 1; i++)
    {
        if (a[i][i] == 0)
        {
            printf("Blad: zerowy element na przekatnej (pivot = 0)\n"); // do poprawienia pozniej przy dodaniu wyboru elementu glownego
            exit(1);
        }
        
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
