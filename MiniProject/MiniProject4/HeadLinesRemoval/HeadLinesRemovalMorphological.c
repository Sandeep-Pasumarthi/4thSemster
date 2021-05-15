#include "DEOC.h"

int main(int argc, char *argv[])
{
    FILE *fp, *op, *op1;

    fp = fopen(argv[1], "r");
    op = fopen(argv[2], "wb");
    op1 = fopen(argv[3], "wb");

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
    
    fprintf(op1, "%c%c\n", ch1, ch2);
    fprintf(op1, "%d %d\n", col, row);

    int *img, *open_img, *structure;
    img = (int *)malloc(row * col * sizeof(int));
    open_img = (int *)malloc(row * col * sizeof(int));

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
            *(open_img + i * col + j) = temp;
        }
    }

    opening(open_img, structure, row, col, x, y);
    
    for (i = 0; i < row; i++)
    {
        for (j = 0; j < col; j++)
        {
            temp = *(open_img + i * col + j);
            fprintf(op, "%d ", temp);
        }
        fprintf(op, "\n");
    }
    
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
    
    closing(open_img, structure, row, col, x, y);
    
    for(int i = 0; i < row; i++)
    {
        for(int j = 0; j < col; j++)
        {
            *(open_img + i * col + j) = *(img + i * col + j) - *(open_img + i * col + j);
            
            if(*(open_img + i * col + j) < 0)
            {
                *(open_img + i * col + j) = 0;
            }
        }
    }
    
    for (i = 0; i < row; i++)
    {
        for (j = 0; j < col; j++)
        {
            temp = *(open_img + i * col + j);
            fprintf(op1, "%d ", temp);
        }
        fprintf(op1, "\n");
    }

    fclose(fp);
    fclose(op);

    return 0;
}
