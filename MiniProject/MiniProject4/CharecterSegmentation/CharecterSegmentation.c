#include <stdio.h>
#include <stdlib.h>

void seperateCharecter(int *img, int *sep, int *h, int *l, int row, int col);

int main(int argc, char *argv[])
{
    FILE *fp, *ip, *ip1, *ip2, *op1;

    fp = fopen(argv[1], "r");
    ip = fopen(argv[2], "r");
    ip1 = fopen(argv[3], "r");
    op1 = fopen(argv[4], "wb");

    if (fp == NULL || ip == NULL || ip1 == NULL || op1 == NULL)
    {
        printf("There is a problem in file opening!!! Please check again!!!");
        exit(0);
    }

    int i, j, col, row, x, y, temp;
    char ch1, ch2;

    fscanf(fp, "%c%c", &ch1, &ch2);
    fscanf(fp, "%d %d", &col, &row);
    
    fprintf(op1, "%c%c\n", ch1, ch2);
    fprintf(op1, "%d %d\n", col, row);
    
    int hline[35];
    
    for(int i = 0; i < 35; i++)
    {
        fscanf(ip, "%d", &temp);
        hline[i] = temp;
    }
    
    int lline[35];
    
    for(int i = 0; i < 35; i++)
    {
        fscanf(ip1, "%d", &temp);
        lline[i] = temp;
    }

    int *img, *sep_img;
    img = (int *)malloc(row * col * sizeof(int));
    sep_img = (int *)malloc(row * col * sizeof(int));
    
    for (i = 0; i < row; i++)
    {
        for (j = 0; j < col; j++)
        {
            fscanf(fp, "%d", &temp);
            *(img + i * col + j) = temp;
            *(sep_img + i * col + j) = temp;
        }
    }
    
    seperateCharecter(img, sep_img, hline, lline, row, col);
    
    for (i = 0; i < row; i++)
    {
        for (j = 0; j < col; j++)
        {
            temp = *(sep_img + i * col + j);
            fprintf(op1, "%d ", temp);
        }
        fprintf(op1, "\n");
    }

    fclose(fp);
    fclose(ip);
    fclose(ip1);
    fclose(op1);

    return 0;
}

void seperateCharecter(int *img, int *sep, int *h, int *l, int row, int col)
{
    int curr, curc;
    for(int i = 0; i < 35; i++)
    {
        for(int j = 0; j < col; j++)
        {
            int k = l[i];
            curr = k;
            curc = j;
            while(k >= h[i])
            {
                if(*(img + curr * col + curc) == 0)
                {
                    curr--;
                }
                else if (*(img + curr * col + (curc-1)) == 0)
                {
                    curc = curc - 1;
                    curr--;
                }
                else if(*(img + curr * col + (curc+1)) == 0)
                {
                    curc = curc + 1;
                    curr--;
                }
                else
                {
                    break;
                }
                
                k--;
            }
            
            if((h[i] + 4) >= curr)
            {
                for(int a = curr; a >= (h[i] - 6); a--)
                {
                    *(sep + a * col + curc) = 0;
                }
            }
        }
    }
}
