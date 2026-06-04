#include <stdio.h>

#define ROWS 10
#define COLS 20

void initCanvas(char canvas[ROWS][COLS])
{
    for(int i = 0; i < ROWS; i++)
    {
        for(int j = 0; j < COLS; j++)
        {
            canvas[i][j] = '_';
        }
    }
}

void drawHLine(char canvas[ROWS][COLS], int row, int start, int end)
{
    for(int j = start; j <= end; j++)
    {
        canvas[row][j] = '*';
    }
}

void drawVLine(char canvas[ROWS][COLS], int col, int start, int end)
{
    for(int i = start; i <= end; i++)
    {
        canvas[i][col] = '*';
    }
}

void display(char canvas[ROWS][COLS])
{
    for(int i = 0; i < ROWS; i++)
    {
        for(int j = 0; j < COLS; j++)
        {
            printf("%c", canvas[i][j]);
        }
        printf("\n");
    }
}


int main()
{
    char canvas[ROWS][COLS];

    initCanvas(canvas);

    drawHLine(canvas, 3, 2, 15);
    drawVLine(canvas, 3, 2, 9);

    display(canvas);

    return 0;
}