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

int main()
{
    int rows, cols;

    printf("Enter number of rows: ");
    scanf("%d", &rows);

    printf("Enter number of columns: ");
    scanf("%d", &cols);

    char canvas[rows][cols];

    initializeCanvas(rows, cols, canvas);
    displayCanvas(rows, cols, canvas);

    return 0;
}