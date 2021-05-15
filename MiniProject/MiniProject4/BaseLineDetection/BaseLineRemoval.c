#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    FILE *fp, *ip, *op;

    fp = fopen(argv[1], "r");
    ip = fopen(argv[2], "r");
    op = fopen(argv[3], "wb");

    if (fp == NULL || ip == NULL)
    {
        printf("There is a problem in file opening!!! Please check again!!!");
        exit(0);
    }
    
    int lmed[35];
    int i, j, col, row, x, y, temp;
    char ch1, ch2;
    
    for(int i = 0; i < 35; i++)
    {
        fscanf(ip, "%d", &temp);
        lmed[i] = temp;
        // printf("%d\n", lmed[i]);
    }

    fscanf(fp, "%c%c", &ch1, &ch2);
    fscanf(fp, "%d %d", &col, &row);

    fprintf(op, "%c%c\n", ch1, ch2);
    fprintf(op, "%d %d\n", col, row);

    int *img, *new_img;
    img = (int *)malloc(row * col * sizeof(int));
    new_img = (int *)malloc(row * col * sizeof(int));

    for (i = 0; i < row; i++)
    {
        for (j = 0; j < col; j++)
        {
            fscanf(fp, "%d", &temp);
            *(img + i * col + j) = temp;
            *(new_img + i * col + j) = temp;
        }
    }
    
    for(int i = 0; i < 35; i++)
    {
        for(int j = 0; j < col; j++)
        {
            *(new_img + lmed[i] * col + j) = 0;
        }
    }

    for (i = 0; i < row; i++)
    {
        for (j = 0; j < col; j++)
        {
            fprintf(op, "%d ", *(new_img + i * col + j));
        }
        fprintf(op, "\n");
    }

    fclose(fp);
    fclose(ip);
    fclose(op);

    return 0;
}
