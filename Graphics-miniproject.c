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
        printf("2. Display Canvas\n");
        printf("3. Exit\n");
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
                displayCanvas(rows, cols, canvas);
                break;

            case 3:
                printf("Exiting...\n");
                break;

            default:
                printf("Invalid choice!\n");
        }

    } while(choice != 3);

    return 0;
}