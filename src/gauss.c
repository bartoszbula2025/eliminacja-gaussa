#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "mat_io.h"

int eliminate(Matrix *A, Matrix *B)
{
    if (A->r != A->c)
    {
        fprintf(stderr, "Blad: macierz A nie jest kwadratowa!\n");
        return 1;
    }

    if (B->c != 1 || B->r != A->r)
    {
        fprintf(stderr, "Blad: macierz B musi byc wektorem kolumnowym o tym samym rozmiarze!\n");
        return 2;
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

        if (max == 0.0)
        {
            fprintf(stderr, "Blad: macierz osobliwa (kolumna %d)\n", i);
            return 3;
        }

        // zamiana wierszy
        if (max_row != i)
        {
            double *tmp = A->data[i];
            A->data[i] = A->data[max_row];
            A->data[max_row] = tmp;

            double tmpb = B->data[i][0];
            B->data[i][0] = B->data[max_row][0];
            B->data[max_row][0] = tmpb;
        }

        // eliminacja
        for (int j = i + 1; j < n; j++)
        {
            double factor = A->data[j][i] / A->data[i][i];

            for (int k = i; k < n; k++)
            {
                A->data[j][k] -= factor * A->data[i][k];
            }

            B->data[j][0] -= factor * B->data[i][0];
        }
    }

    return 0; // sukces
}

