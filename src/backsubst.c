#include "backsubst.h"
#include <stdio.h>


int backsubst(Matrix* x, Matrix* mat, Matrix* b) {

    if (mat->c!=mat->r || mat->c!=b->r || mat->c!=x->r)
        return 2;
   

    int n=mat->r;
    n = n - 1;
    if (mat->data[n][n] == 0)
        return 1;
    x->data[n][0] = b->data[n][0] / mat->data[n][n];
    int i = n-1;
    for (i; i >= 0; i--) {
        if (mat->data[i][i] == 0)
            return 1;
        double wsp = 0;
        int j = n;
        for (j; j >i; j--)
            wsp += mat->data[i][j]*x->data[j][0];
        double wynik = (b->data[i][0] - wsp) / mat->data[i][i];
        x->data[i][0] = wynik;
        
    }
        
    


    

    return 0; 
}