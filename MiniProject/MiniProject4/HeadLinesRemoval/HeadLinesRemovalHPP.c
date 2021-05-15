#include "DEOC.h"

int main(int argc, char *argv[])
{
    FILE *fp, *ip, *op;

    fp = fopen(argv[1], "r");
    ip = fopen(argv[2], "r");
    op = fopen(argv[3], "wb");

    if (fp == NULL || ip == NULL || op == NULL)
    {
        printf("There is a problem in file opening!!! Please check again!!!");
        exit(0);
    }

    int col, row, temp;
    char ch1, ch2;

    fscanf(fp, "%c%c", &ch1, &ch2);
    fscanf(fp, "%d %d", &col, &row);

    fprintf(op, "%c%c\n", ch1, ch2);
    fprintf(op, "%d %d\n", col, row);
    
    int hline[35];
    
    for(int i = 0; i < 35; i++)
    {
        fscanf(ip, "%d", &temp);
        hline[i] = temp;
    }
    
    int *img;
    img = (int*)malloc(col * row * sizeof(int));
    
    for(int i = 0; i < row; i++)
    {
        for(int j = 0; j < col; j++)
        {
            fscanf(fp, "%d", &temp);
            *(img + i * col + j) = temp;
        }
    }
    
    for(int i = 0; i < 35; i++)
    {
        int th = hline[i];
        for(int j = 0; j < col; j++)
        {
            *(img + (th-1) * col + j) = 0;
            *(img + th * col + j) = 0;
            *(img + (th+1) * col + j) = 0;
            *(img + (th+2) * col + j) = 0;
            *(img + (th+3) * col + j) = 0;
        }
    }
    
    for(int i = 0; i < row; i++)
    {
        for(int j = 0; j < col; j++)
        {
            fprintf(op, "%d ", *(img + i * col + j));
        }
        fprintf(op, "\n");
    }

    fclose(fp);
    fclose(ip);
    fclose(op);

    return 0;
}
