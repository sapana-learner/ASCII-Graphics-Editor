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
    if(row < 0 || row >= ROWS ||
       start < 0 || end >= COLS)
    {
        printf("Invalid coordinates!\n");
        return;
    }

    if(start > end)
    {
        printf("Invalid range!\n");
        return;
    }

    for(int j = start; j <= end; j++)
    {
        canvas[row][j] = '*';
    }
}
void drawVLine(char canvas[ROWS][COLS], int col, int start, int end)
{
    if(col < 0 || col >= COLS ||
       start < 0 || end >= ROWS)
    {
        printf("Invalid coordinates!\n");
        return;
    }

    if(start > end)
    {
        printf("Invalid range!\n");
        return;
    }

    for(int i = start; i <= end; i++)
    {
        canvas[i][col] = '*';
    }
}

void drawRectangle(char canvas[ROWS][COLS], int r, int c, int height, int width)
{
    if(height <= 0 || width <= 0)
{
    printf("Invalid rectangle size!\n");
    return;
}

    if(r < 0 || c < 0 ||
       r + height > ROWS ||
       c + width > COLS)
    {
        printf("Rectangle outside canvas!\n");
        return;
    }

    // top line
    for(int j = c; j < c + width; j++)
        canvas[r][j] = '*';

    // bottom line
    for(int j = c; j < c + width; j++)
        canvas[r + height - 1][j] = '*';

    // left line
    for(int i = r; i < r + height; i++)
        canvas[i][c] = '*';

    // right line
    for(int i = r; i < r + height; i++)
        canvas[i][c + width - 1] = '*';
}

void fillRectangle(char canvas[ROWS][COLS], int r, int c, int height, int width)
{
    if(height <= 0 || width <= 0)
{
    printf("Invalid rectangle size!\n");
    return;
}

    if(r < 0 || c < 0 ||
   r + height >  ROWS ||
   c + width > COLS)
{
    printf("Rectangle outside canvas!\n");
    return;
}
    for(int i = r; i < r + height; i++)
    {
        for(int j = c; j < c + width; j++)
        {
            canvas[i][j] = '*';
        }
    }
}

void drawTriangle(char canvas[ROWS][COLS], int r, int c, int height)
{
    if(height <= 0)
    {
        printf("Invalid height!\n");
        return;
    }

    if(r < 0 || c < 0 ||
       r + height > ROWS ||
       c + height > COLS)
    {
        printf("Triangle outside canvas!\n");
        return;
    }

    for(int i = 0; i < height; i++)
    {
        for(int j = 0; j <= i; j++)
        {
            canvas[r + i][c + j] = '*';
        }
    }
}

void drawCircle(char canvas[ROWS][COLS], int r, int c)
{
    if(r <= 0 || r >= ROWS - 1 ||
       c <= 0 || c >= COLS - 1)
    {
        printf("Circle would go outside canvas!\n");
        return;
    }

    canvas[r][c] = '*';

    canvas[r-1][c] = '*';
    canvas[r+1][c] = '*';

    canvas[r][c-1] = '*';
    canvas[r][c+1] = '*';

    canvas[r-1][c-1] = '*';
    canvas[r-1][c+1] = '*';

    canvas[r+1][c-1] = '*';
    canvas[r+1][c+1] = '*';
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

void eraseRectangle(char canvas[ROWS][COLS], int r, int c, int h, int w)
{
    if(h <= 0 || w <= 0)
{
    printf("Invalid rectangle size!\n");
    return;
}

    if(r < 0 || c < 0 ||
   r + h > ROWS ||
   c + w > COLS)
{
    printf("Invalid rectangle!\n");
    return;
}
    for(int i = r; i < r + h; i++)
    {
        for(int j = c; j < c + w; j++)
        {
            canvas[i][j] = '_';
        }
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
        printf("3. Draw Triangle\n");
        printf("4. Draw Horizontal Line\n");
        printf("5. Draw Vertical Line\n");
        printf("6. Delete Rectangle\n");
        printf("7. Draw Circle\n");
        printf("8. Display Canvas\n");
        printf("9. Modify Rectangle\n");
        printf("10. Exit\n");

        printf("Enter choice: ");
        scanf("%d", &choice);

 if(choice == 1)
{
    int r, c, h, w;

    printf("Row: ");
    scanf("%d", &r);

    printf("Column: ");
    scanf("%d", &c);

    printf("Height: ");
    scanf("%d", &h);

    printf("Width: ");
    scanf("%d", &w);

    drawRectangle(canvas, r, c, h, w);
}

        else if(choice == 2)
{
    int r, c, h, w;

    printf("Row: ");
    scanf("%d", &r);

    printf("Column: ");
    scanf("%d", &c);

    printf("Height: ");
    scanf("%d", &h);

    printf("Width: ");
    scanf("%d", &w);

    fillRectangle(canvas, r, c, h, w);
}
        else if(choice == 3)
{
    int r, c, h;

    printf("Row: ");
    scanf("%d", &r);

    printf("Column: ");
    scanf("%d", &c);

    printf("Height: ");
    scanf("%d", &h);

    drawTriangle(canvas, r, c, h);
}

else if(choice == 4)
{
    int row, start, end;

    printf("Row: ");
    scanf("%d", &row);

    printf("Start Column: ");
    scanf("%d", &start);

    printf("End Column: ");
    scanf("%d", &end);

    drawHLine(canvas, row, start, end);
}
else if(choice == 5)
{
    int col, start, end;

    printf("Column: ");
    scanf("%d", &col);

    printf("Start Row: ");
    scanf("%d", &start);

    printf("End Row: ");
    scanf("%d", &end);

    drawVLine(canvas, col, start, end);
}
else if(choice == 6)
{
    int r, c, h, w;

    printf("Row: ");
    scanf("%d", &r);

    printf("Column: ");
    scanf("%d", &c);

    printf("Height: ");
    scanf("%d", &h);

    printf("Width: ");
    scanf("%d", &w);

    eraseRectangle(canvas, r, c, h, w);
}

else if(choice == 7)
{
    int r, c;

    printf("Center Row: ");
    scanf("%d", &r);

    printf("Center Column: ");
    scanf("%d", &c);

    drawCircle(canvas, r, c);
}
else if(choice == 8)
{
    display(canvas);
}
else if(choice == 9)
{
    int oldr, oldc, oldh, oldw;
    int newr, newc, newh, neww;

    printf("Old Row: ");
    scanf("%d", &oldr);

    printf("Old Column: ");
    scanf("%d", &oldc);

    printf("Old Height: ");
    scanf("%d", &oldh);

    printf("Old Width: ");
    scanf("%d", &oldw);

    eraseRectangle(canvas, oldr, oldc, oldh, oldw);

    printf("New Row: ");
    scanf("%d", &newr);

    printf("New Column: ");
    scanf("%d", &newc);

    printf("New Height: ");
    scanf("%d", &newh);

    printf("New Width: ");
    scanf("%d", &neww);

    drawRectangle(canvas, newr, newc, newh, neww);
}
else if(choice == 10)
{
    break;
}
else
{
    printf("Invalid choice!\n");
}
    }
    
    return 0;
}