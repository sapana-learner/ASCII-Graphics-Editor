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

void drawRectangle(char canvas[ROWS][COLS], int r, int c, int height, int width)
{
    // top line
    for(int j = c; j < c + width; j++)
        canvas[r][j] = '*';

    // bottom line
    for(int j = c; j < c + width; j++)
        canvas[r + height][j] = '*';

    // left line
    for(int i = r; i < r + height; i++)
        canvas[i][c] = '*';

    // right line
    for(int i = r; i < r + height; i++)
        canvas[i][c + width] = '*';
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

    //drawHLine(canvas, 3, 2, 15);
    //drawVLine(canvas, 3, 2, 9);
    

    drawRectangle(canvas, 2, 5, 5, 10);



    display(canvas);

    return 0;
}