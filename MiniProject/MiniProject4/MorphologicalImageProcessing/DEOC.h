#include <stdio.h>
#include <stdlib.h>

void dilation(int *dilation_img, int *structure, int row, int col, int x, int y)
{
    int s = x / 2, a = y / 2;

    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            if (((i + x) < row) && ((j + y) < col))
            {
                for (int w = 0; w < x; w++)
                {
                    for (int q = 0; q < y; q++)
                    {
                        if (*(dilation_img + (i + w) * col + (j + q)) == 1)
                        {
                            *(dilation_img + (i + s) * col + (j + a)) = 2;
                            continue;
                        }
                    }
                }
            }
        }
    }

    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            if (*(dilation_img + i * col + j) == 2)
            {
                *(dilation_img + i * col + j) = 1;
            }
        }
    }
}

void erosion(int *erosion_img, int *structure, int row, int col, int x, int y)
{
    int s = x / 2, a = y / 2;

    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            if (((i + x) < row) && ((j + y) < col))
            {
                for (int w = 0; w < x; w++)
                {
                    for (int q = 0; q < y; q++)
                    {
                        if (*(erosion_img + (i + w) * col + (j + q)) == 0)
                        {
                            *(erosion_img + (i + s) * col + (j + a)) = 2;
                            continue;
                        }
                    }
                }
            }
        }
    }

    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            if (*(erosion_img + i * col + j) == 2)
            {
                *(erosion_img + i * col + j) = 0;
            }
        }
    }
}

void opening(int *opened_img, int *structure, int row, int col, int x, int y)
{
    erosion(opened_img, structure, row, col, x, y);
    dilation(opened_img, structure, row, col, x, y);
}

void closing(int *closed_img, int *structure, int row, int col, int x, int y)
{
    dilation(closed_img, structure, row, col, x, y);
    erosion(closed_img, structure, row, col, x, y);
}