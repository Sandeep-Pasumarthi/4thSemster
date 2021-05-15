#include <stdio.h>
#include <stdlib.h>

void horizantalProjecctionProfile(int *copyImage, int *hppImage, int *hppnImage, int row, int col)
{
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            *(hppnImage + i) = *(hppnImage + i) + *(copyImage + i * col + j);
        }
    }

    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < *(hppnImage + i); j++)
        {
            *(hppImage + i * col + j) = 1;
        }
    }
}
