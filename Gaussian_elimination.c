#include  <stdio.h>
/*
We consider an algebric linear system Ax = b 
We want to solve this system using "Gauss elimination" method 
As an example we consider the system:
             |  1,  2, -1 |   | x_0 |   | -1 |
A*X = B <=>  | -2,  3,  1 | * | x_1 | = |  0 |
             |  4, -1, -3 |   | x_2 |   | -2 | 
*/
int main(void)
{
    // Example 1
    float a[3][3] =  {{ 1, 2,-1}, {-2, 3, 1},{4,-1,-3}};
    float b[3] = {-1,0,-2};
    // Example 2 
    //float a[3][3] =  {{ 8,1,-1}, {2,1,9},{1, -7, 2}};
    //float b[3] = {8,12,-4};
/////////////////////////////////////////////////////////////////////////
    int size = 3;
    float x[3] = {0,0,0}; // the vector of variables x_i
    int i,j,k,n;
    n = size -1;
///////////////////////////////////////////////////////////////////////////////
    printf("\n-------------------------------------------"); 
    printf("\nThe initial matrix A has the values: \n");
    for (i = 0; i<size; i++ )
    {
        for(j =0; j < size; j++)
        {
            printf("%.2f ", a[i][j]); 
        }
        printf("\n");
    }
    printf("\n-------------------------------------------"); 
    printf("\nThe vector b has the values: \n");

    for (i = 0; i < size; i++)
    {
        printf("%.2f ", b[i]);
    }

////////////////////////////////////////////////////////////////////////////////////////
/////////////////The first stage: Gaussian elimination (triangularization) /////////////
/////////////////////////////////////////////////////////////////////////////////////////

    for (k = 0; k < size; k++)
    { 
        for (i = k + 1; i < size; i++)
        {
            float p = - a[i][k]/a[k][k];
            for (j = k; j < size; j++)
            {
                a[i][j] = a[i][j] + p*a[k][j] ; // element din ecuatia 2 + element din ecuatia 1 
            }
            b[i] = b[i] + p*b[k];
        }
    }


////////////////////// WRITE MATRIX //////////////////////////////////////////
    printf("\n-------------------------------------------"); 
    printf("\nThe new matrix A has the values: \n");
    for (i = 0; i<size; i++ )
    {
        for(j =0; j < size; j++)
        {
            printf("%.2f ", a[i][j]); 
        }
        printf("\n");
    }
////////////////////// WRITE THE FREE TERMS ////////////////////////////////
    printf("\n-------------------------------------------"); 
    printf("\nThe new vector b has the values: \n");
    for (i = 0; i < size; i++)
    {
        printf("%.2f ", b[i]);
    } 
    printf("\n-------------------------------------------"); 
/////////////////////////////////////////////////////////////////////////////////////////
///////// The second stage: retrosubstitution (regressive substitution) ///////////////
///////////////////////// DETERMINE value of vector X ////////////////////
    x[n] = b[n]/a[n][n]; // n = max = 2
    printf("\nThe solution of the sistem");
    printf("\nx[%d] = %.2f", n, x[n]);
    
    for (i = n-1; i >= 0 ; i--)
    {
        float s = 0; 
        for( j = i; j <= n; j++)
        {
            s = s + a[i][j]*x[j];
        }
        x[i] = (b[i]-s)/ a[i][i];
        printf("\nx[%d] = %.2f", i, x[i]); 
    }
    return 0;
}



