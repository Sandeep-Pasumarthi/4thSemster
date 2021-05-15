#include "HPP.h"

int main(int argc, char *argv[])
{
    FILE *fp, *op, *op1, *op2;

    fp = fopen(argv[1], "r");
    op = fopen(argv[2], "wb");
    op1 = fopen(argv[3], "wb");
    op2 = fopen(argv[4], "wb");

    if (fp == NULL || op == NULL || op1 == NULL || op2 == NULL)
    {
        printf("Couldn't open file!!!");
        exit(0);
    }

    int i, j, col, row, temp;
    char ch1, ch2;

    fscanf(fp, "%c%c", &ch1, &ch2);
    fscanf(fp, "%d %d", &col, &row);

    fprintf(op, "%c%c\n", ch1, ch2);
    fprintf(op, "%d %d\n", col, row);

    int *img, *copyImg, *hppnImage, *hppImage;
    img = (int *)malloc(col * row * sizeof(int));
    copyImg = (int *)malloc(col * row * sizeof(int));
    hppnImage = (int *)malloc(row * sizeof(int));
    hppImage = (int *)malloc(col * row * sizeof(int));

    for (i = 0; i < row; i++)
    {
        for (j = 0; j < col; j++)
        {
            fscanf(fp, "%d", &temp);
            *(img + i * col + j) = temp;
            *(copyImg + i * col + j) = temp;
        }
    }

    for (i = 0; i < row; i++)
    {
        for (j = 0; j < col; j++)
        {
            *(hppImage + i * col + j) = 0;
            *(hppnImage + i) = 0;
        }
    }

    horizantalProjecctionProfile(copyImg, hppImage, hppnImage, row, col);

    int count = 0, init[35], fin[35], linecount = 0;
    temp = 0;
    for (int i = 0; i < row; i++)
    {
        if (*(hppnImage + i) > 0)
        {
            count++;
        }
        if (count == 1)
        {
            init[linecount] = i;
            fprintf(op1, "%d ", i);
        }
        if (*(hppnImage + i) == 0 && count > 1)
        {
            fin[linecount] = i - 1;
            linecount++;
            count = 0;
            fprintf(op1, "%d\n", i - 1);
            temp++;
        }
    }

    for (int i = 0; i < 35; i++)
    {
        long long int avg = 0;
        for (int j = init[i]; j < fin[i]; j++)
        {
            avg = avg + hppnImage[j];
        }

        avg = avg / (fin[i] - init[i] + 1);

        for (int j = init[i]; j < fin[i]; j++)
        {
            if (hppnImage[j] >= avg)
            {
                fprintf(op2, "%d ", j);
                break;
            }
        }
    }

    printf("No. of lines: - %d", temp);

    for (i = 0; i < row; i++)
    {
        for (j = 0; j < col; j++)
        {
            fprintf(op, "%d", *(hppImage + i * col + j));
        }
        fprintf(op, "\n");
    }

    fclose(fp);
    fclose(op);
    fclose(op1);
    fclose(op2);

    return 0;
}