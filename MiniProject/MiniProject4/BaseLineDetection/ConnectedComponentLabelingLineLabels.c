#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define min(x, y) x < y ? x : y
#define max(x, y) x > y ? x : y

int col, row;
int *p = NULL, *label = NULL, *lb = NULL;
void connected_component_label(int *, int *);
void search(int *, int *, int, int);
int *neighbors(int, int);
void insertionSort(int *, int);

int main(int argc, char *argv[])
{
	FILE *fp, *ip, *op, *op1;
	fp = fopen(argv[1], "r");
	ip = fopen(argv[2], "r");
	op = fopen(argv[3], "wb");
	op1 = fopen(argv[4], "wb");
	
	if (fp == NULL || ip == NULL || op == NULL || op1 == NULL)
	{
		printf("There is a problem in file opening!!! Please check again!!!");
		exit(0);
	}

	int i, j, k;
	int max_value, temp;
	char c, magic[4];

	fgets(magic, 3, fp);
	fscanf(fp, "\n");

	fscanf(fp, "%c", &c);
	if (c == '#')
		while (c != '\n')
			c = fgetc(fp);
	else
		fseek(fp, -1, SEEK_CUR);

	fscanf(fp, "\n%d %d", &col, &row);
	
	int start[35], end[35];
	for(i = 0; i < 35; i++)
	{
	    for(j = 0; j < 2; j++)
	    {
	        if(j == 0)
	        {
	            fscanf(ip, "%d", &temp);
	            start[i] = temp;
	            //printf("%d", start[i]);
	        }
	        else
	        {
	            fscanf(ip, "%d", &temp);
	            end[i] = temp;
	            //printf("%d\n", end[i]);
	        }
	    }
	}

	p = (int *)malloc(row * col * sizeof(int));
	label = (int *)malloc(row * col * sizeof(int));

	for (i = 0; i < row; i++)
	{
		for (j = 0; j < col; j++)
		{
			fscanf(fp, "%d\n", &temp);
			*(p + i * col + j) = temp;
			if (*(p + i * col + j) == 1)
			{
				*(label + i * col + j) = -1;
			}
			else
			{
				*(label + i * col + j) = 0;
			}
		}
		if (feof(fp))
			break;
	}

	lb = (int *)malloc(sizeof(int));
	*lb = 0;
	connected_component_label(label, lb);
	
	printf("\n");
	printf("Total no. of Portions/Labels :- %d\n", *lb);
	printf("\n");
	int arr_x_min, arr_y_min, arr_x_max, arr_y_max, x = 0;
	int n_labels = *lb;
	int arr_width[n_labels], arr_height[n_labels], arr_count[n_labels], arr_x_min_cor[n_labels];

	for (i = 1; i <= *lb; i++)
	{
		int count = 0;
		for (j = 0; j < row; j++)
		{
			for (k = 0; k < col; k++)
			{
				if (*(label + j * col + k) == i)
				{
					count++;
					if (count == 1)
					{
						arr_x_min = j;
						arr_x_max = j;
						arr_y_min = k;
						arr_y_max = k;
					}
					else
					{
						if (j > arr_x_max)
						{
							arr_x_max = j;
						}
						if (j < arr_x_min)
						{
							arr_x_min = j;
						}
						if (k > arr_y_max)
						{
							arr_y_max = k;
						}
						if (k < arr_y_min)
						{
							arr_y_min = k;
						}
					}
				}
			}
		}
		arr_count[i] = count;
		arr_width[i] = arr_x_max - arr_x_min;
		arr_height[i] = arr_y_max - arr_y_min;
		arr_x_min_cor[i] = arr_x_min;
	}
	
	int templ[n_labels], lcount = 0;
	
	for(int i = 0; i < 35; i++)
	{
	    for(int j = start[i]; j < end[i]+1; j++)
	    {
	        for(int k = 0; k < col; k++)
	        {
	            if(*(label + j * col + k) > 0)
	            {
	                if(lcount == 0)
	                {
	                    templ[lcount] = *(label + j * col + k);
	                    lcount++;
	                }
	                else
	                {
	                    int xcount = 0;
	                    for(int l = 0; l < lcount; l++)
	                    {
	                        if(templ[l] == *(label + j * col + k))
	                        {
	                            xcount++;
	                        }
	                    }
	                    if(xcount == 0)
	                    {
	                        templ[lcount] = *(label + j * col + k);
	                        lcount++;
	                    }
	                }
	            }
	        }
	    }
	    
	    for(int l = 0; l < lcount; l++)
	    {
	        fprintf(op, "%d ", templ[l]);
	    }
	    fprintf(op, "\n");
	    fprintf(op1, "%d ", lcount);
	    
	    lcount = 0;
	}
	
	fclose(fp);
	fclose(ip);
	return 0;
}

void connected_component_label(int *label, int *lb)
{
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			if (*(label + i * col + j) == -1)
			{
				*lb = *lb + 1;
				search(label, lb, i, j);
			}
		}
	}
}

void search(int *label, int *lb, int i, int j)
{
	*(label + i * col + j) = *lb;
	int *n = neighbors(i, j);
	int len = *(n + 0);
	for (int i = 1; i <= len; i++)
	{
		if (*(label + (*(n + i)) * col + (*(n + (len + i)))) == -1)
		{
			search(label, lb, *(n + i), *(n + (len + i)));
		}
	}
}

int *neighbors(int pos_x, int pos_y)
{
	int n_x[8], n_y[8];
	n_x[0] = pos_x - 1;
	n_x[1] = pos_x - 1;
	n_x[2] = pos_x - 1;
	n_x[3] = pos_x;
	n_x[4] = pos_x + 1;
	n_x[5] = pos_x + 1;
	n_x[6] = pos_x + 1;
	n_x[7] = pos_x;

	n_y[0] = pos_y - 1;
	n_y[1] = pos_y;
	n_y[2] = pos_y + 1;
	n_y[3] = pos_y + 1;
	n_y[4] = pos_y + 1;
	n_y[5] = pos_y;
	n_y[6] = pos_y - 1;
	n_y[7] = pos_y - 1;

	int fin_x[8], fin_y[8], count = 0;

	for (int i = 0; i < 8; i++)
	{
		if (n_x[i] >= 0 && n_x[i] < row && n_y[i] >= 0 && n_y[i] < col)
		{
			fin_x[count] = n_x[i];
			fin_y[count] = n_y[i];
			count++;
		}
	}
	int *fin = (int *)malloc(((2 * count) + 1) * sizeof(int));
	*(fin + 0) = count;
	for (int i = 1; i <= count; i++)
	{
		*(fin + i) = fin_x[i - 1];
		*(fin + (i + count)) = fin_y[i - 1];
	}
	return fin;
}

void insertionSort(int *arr, int n)
{
	int i, j;
	int key;

	for (i = 1; i < n; i++)
	{
		key = arr[i];
		j = i - 1;

		while (j >= 0 && arr[j] > key)
		{
			arr[j + 1] = arr[j];
			j = j - 1;
		}
		arr[j + 1] = key;
	}
}
