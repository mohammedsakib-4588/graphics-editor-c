#include <stdio.h>

void initializeCanvas(int rows, int cols, char canvas[rows][cols])
{
    for(int i = 0; i < rows; i++)
    {
        for(int j = 0; j < cols; j++)
        {
            canvas[i][j] = '_';
        }
    }
}

void displayCanvas(int rows, int cols, char canvas[rows][cols])
{
    printf("\nCanvas:\n\n");

    for(int i = 0; i < rows; i++)
    {
        for(int j = 0; j < cols; j++)
        {
            printf("%c ", canvas[i][j]);
        }
        printf("\n");
    }
}
void drawPoint(int rows, int cols, char canvas[rows][cols], int r, int c)
{
    if(r >= 0 && r < rows && c >= 0 && c < cols)
    {
        canvas[r][c] = '*';
    }
}

void drawRectangle(int rows, int cols, char canvas[rows][cols],
                   int r, int c, int h, int w)
{
    for(int i = r; i < r + h && i < rows; i++)
    {
        for(int j = c; j < c + w && j < cols; j++)
        {
            if(i >= 0 && j >= 0)
            {
                canvas[i][j] = '*';
            }
        }
    }
}

void drawLine(int rows, int cols, char canvas[rows][cols],
              int r1, int c1, int r2, int c2)
{
    int dr = (r2 > r1) ? 1 : -1;
    int dc = (c2 > c1) ? 1 : -1;

    int r = r1;
    int c = c1;

    while(r != r2 || c != c2)
    {
        if(r >= 0 && r < rows && c >= 0 && c < cols)
        {
            canvas[r][c] = '*';
        }

        if(r != r2) r += dr;
        if(c != c2) c += dc;
    }

    if(r2 >= 0 && r2 < rows && c2 >= 0 && c2 < cols)
    {
        canvas[r2][c2] = '*';
    }
}

int main()
{
    int rows, cols;
    int choice;
    int r, c;

    printf("Enter number of rows: ");
    scanf("%d", &rows);

    printf("Enter number of columns: ");
    scanf("%d", &cols);

    char canvas[rows][cols];

    initializeCanvas(rows, cols, canvas);

    do
    {
        printf("\n===== 2D Graphics Editor =====\n");
        printf("1. Draw Point\n");
        printf("2. Draw Rectangle\n");
        printf("3. Draw line\n");
        printf("4. Display Canvas\n");
        printf("5. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch(choice)
        {
            case 1:
                printf("Enter row and column: ");
                scanf("%d %d", &r, &c);
                drawPoint(rows, cols, canvas, r, c);
                break;
            case 2:
            {
                int r, c, h, w;

                printf("Enter start row and column: ");
                scanf("%d %d", &r, &c);

                printf("Enter height and width: ");
                scanf("%d %d", &h, &w);

                drawRectangle(rows, cols, canvas, r, c, h, w);
                break;
            }
            case 3:
            {
                int r1, c1, r2, c2;

                printf("Enter start row and column: ");
                scanf("%d %d", &r1, &c1);

                printf("Enter end row and column: ");
                scanf("%d %d", &r2, &c2);

                drawLine(rows, cols, canvas, r1, c1, r2, c2);
                break;
            }
            case 4:
                displayCanvas(rows, cols, canvas);
                break;

            case 5:
                printf("Exiting...\n");
                break;

            default:
                printf("Invalid choice!\n");
        }

    } while(choice != 5);

    return 0;
}