#include "DEOC.h"

int main(int argc, char *argv[])
{
	FILE *fp, *op1, *op2, *op3, *op4;

	fp = fopen(argv[1], "r");
	op1 = fopen(argv[2], "wb");
	op2 = fopen(argv[3], "wb");
	op3 = fopen(argv[4], "wb");
	op4 = fopen(argv[5], "wb");

	if (fp == NULL)
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

	fprintf(op2, "%c%c\n", ch1, ch2);
	fprintf(op2, "%d %d\n", col, row);

	fprintf(op3, "%c%c\n", ch1, ch2);
	fprintf(op3, "%d %d\n", col, row);

	fprintf(op4, "%c%c\n", ch1, ch2);
	fprintf(op4, "%d %d\n", col, row);

	int *img, *dilated_img, *eroted_img, *opened, *closed, *structure;
	img = (int *)malloc(row * col * sizeof(int));
	dilated_img = (int *)malloc(row * col * sizeof(int));
	eroted_img = (int *)malloc(row * col * sizeof(int));
	opened = (int *)malloc(row * col * sizeof(int));
	closed = (int *)malloc(row * col * sizeof(int));

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
			*(dilated_img + i * col + j) = temp;
			*(eroted_img + i * col + j) = temp;
			*(opened + i * col + j) = temp;
			*(closed + i * col + j) = temp;
		}
	}

	dilation(dilated_img, structure, row, col, x, y);
	erosion(eroted_img, structure, row, col, x, y);
	opening(opened, structure, row, col, x, y);
	closing(closed, structure, row, col, x, y);

	for (i = 0; i < row; i++)
	{
		for (j = 0; j < col; j++)
		{
			fprintf(op1, "%d", *(dilated_img + i * col + j));
			fprintf(op2, "%d", *(eroted_img + i * col + j));
			fprintf(op3, "%d", *(opened + i * col + j));
			fprintf(op4, "%d", *(closed + i * col + j));
		}
		fprintf(op1, "\n");
		fprintf(op2, "\n");
		fprintf(op3, "\n");
		fprintf(op4, "\n");
	}

	fclose(fp);
	fclose(op1);
	fclose(op2);
	fclose(op3);
	fclose(op4);

	return 0;
}