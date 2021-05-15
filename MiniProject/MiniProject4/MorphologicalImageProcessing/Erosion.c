#include "DEOC.h"

int main(int argc, char *argv[])
{
    FILE *fp, *op;

    fp = fopen(argv[1], "r");
    op = fopen(argv[2], "wb");

    if (fp == NULL)
    {
        printf("There is a problem in file opening!!! Please check again!!!");
        exit(0);
    }

    int i, j, col, row, x, y, temp;
    char ch1, ch2;

    fscanf(fp, "%c%c", &ch1, &ch2);
    fscanf(fp, "%d %d", &col, &row);

    fprintf(op, "%c%c\n", ch1, ch2);
    fprintf(op, "%d %d\n", col, row);

    int *img, *eroted_img, *structure;
    img = (int *)malloc(row * col * sizeof(int));
    eroted_img = (int *)malloc(row * col * sizeof(int));

    printf("Enter x: - ");
    scanf("%d", &x);

    printf("Enter y: - ");
    scanf("%d", &y);

    structure = (int *)malloc(x * y * sizeof(int));

    for (i = 0; i < x; i++)
    {
        for (j = 0; j < y; j++)
        {
            *(structure + i * y + j) = 1;
        }
    }

    printf("Used Structure is: -\n");
    for (i = 0; i < x; i++)
    {
        for (j = 0; j < y; j++)
        {
            printf("%d ", *(structure + i * y + j));
        }
        printf("\n");
    }

    for (i = 0; i < row; i++)
    {
        for (j = 0; j < col; j++)
        {
            fscanf(fp, "%d", &temp);
            *(img + i * col + j) = temp;
            *(eroted_img + i * col + j) = temp;
        }
    }

    erosion(eroted_img, structure, row, col, x, y);

    for (i = 0; i < row; i++)
    {
        for (j = 0; j < col; j++)
        {
            fprintf(op, "%d ", *(eroted_img + i * col + j));
        }
        fprintf(op, "\n");
    }

    fclose(fp);
    fclose(op);

    return 0;
}
