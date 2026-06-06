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

void fillRectangle(char canvas[ROWS][COLS], int r, int c, int height, int width)
{
    for(int i = r; i < r + height; i++)
    {
        for(int j = c; j < c + width; j++)
        {
            canvas[i][j] = '*';
        }
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
    int choice;

    initCanvas(canvas);

    while(1)
    {
        printf("\n1. Draw Rectangle\n");
        printf("2. Fill Rectangle\n");
        printf("3. Display Canvas\n");
        printf("4. Exit\n");

        printf("Enter choice: ");
        scanf("%d", &choice);

        if(choice == 1)
        {
            drawRectangle(canvas, 2, 5, 5, 10);
        }
        else if(choice == 2)
        {
            fillRectangle(canvas, 2, 5, 5, 10);
        }
        else if(choice == 3)
        {
            display(canvas);
        }
        else if(choice == 4)
        {
            break;
        }
    }

    return 0;
}