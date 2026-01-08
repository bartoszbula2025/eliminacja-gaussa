#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "mat_io.h"

void gauss_elimination(Matrix *A, double *b)
{
    if (A->r != A->c)
    {
        printf("Blad: macierz nie jest kwadratowa!\n");
        exit(1);
    }

    int n = A->r;

    for (int i = 0; i < n - 1; i++)
    {
        // wybor elementu glownego
        int max_row = i;
        double max = fabs(A->data[i][i]);

        for (int r = i + 1; r < n; r++)
        {
            if (fabs(A->data[r][i]) > max)
            {
                max = fabs(A->data[r][i]);
                max_row = r;
            }
        }

        if (max == 0)
        {
            printf("Blad: macierz osobliwa (kolumna %d)\n", i);
            exit(1);
        }

        // zamiana wierszy
        if (max_row != i)
        {
            double *tmp = A->data[i];
            A->data[i] = A->data[max_row];
            A->data[max_row] = tmp;

            double tmpb = b[i];
            b[i] = b[max_row];
            b[max_row] = tmpb;
        }

        // eliminacja
        for (int j = i + 1; j < n; j++)
        {
            double factor = A->data[j][i] / A->data[i][i];

            for (int k = i; k < n; k++)
            {
                A->data[j][k] -= factor * A->data[i][k];
            }

            b[j] -= factor * b[i];
        }
    }
}
