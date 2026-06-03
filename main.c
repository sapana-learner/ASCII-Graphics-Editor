#include <stdio.h>

int main()
{
    int rows = 10;
    int cols = 20;

    char canvas[10][20];

    // Fill canvas with '_'
    for(int i = 0; i < rows; i++)
    {
        for(int j = 0; j < cols; j++)
        {
            canvas[i][j] = '_';
        }
    }
    for(int j=2;j<=15;j++)

    {
        canvas[3][j]='*';
    }

    for(int i=2;i<=9;i++)
    {
        canvas[i][3]='*';
    }
    
    // Display canvas
    for(int i = 0; i < rows; i++)
    {
        for(int j = 0; j < cols; j++)
        {
            printf("%c", canvas[i][j]);
        }
        printf("\n");
    }

    return 0;
}