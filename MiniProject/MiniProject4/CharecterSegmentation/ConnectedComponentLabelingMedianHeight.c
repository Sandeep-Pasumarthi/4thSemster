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
	FILE *fp, *ip1, *op;
	fp = fopen(argv[1], "r");
	ip1 = fopen(argv[2], "r");
	op = fopen(argv[3], "wb");
	
	if (fp == NULL || ip1 == NULL || op == NULL)
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
	
	int linelabelcount[35];
	for(int i = 0; i < 35; i++)
	{
	    fscanf(ip1, "%d", &temp);
	    linelabelcount[i] = temp;
	    // printf("%d", linelabelcount[i]);
	}
	
	int maxlabelcount = linelabelcount[0];
	
	for(int i = 0; i < 35; i++)
	{
	    if(maxlabelcount < linelabelcount[i])
	    {
	        maxlabelcount = linelabelcount[i];
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
	int arr_width[n_labels], arr_height[n_labels], arr_count[n_labels];

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
		// arr_count[i] = count;
		arr_width[i] = arr_x_max - arr_x_min;
		// arr_height[i] = arr_y_max - arr_y_min;
		//printf("%d\n", arr_x_max);
	}
	
	int tempmed[maxlabelcount], lc = 0;
	
	for(int i = 0; i < 35; i++)
	{
	    for(int j = 0; j < linelabelcount[i]; j++)
	    {
	        tempmed[j] = arr_width[j + lc];
	    }
	    lc = linelabelcount[i] + lc;
	    insertionSort(tempmed, linelabelcount[i]);
	    printf("%d", tempmed[linelabelcount[i] / 2]);
	    fprintf(op, "%d ", tempmed[linelabelcount[i] / 2]);
	}	
	
	fclose(fp);
	fclose(ip1);
	fclose(op);
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
