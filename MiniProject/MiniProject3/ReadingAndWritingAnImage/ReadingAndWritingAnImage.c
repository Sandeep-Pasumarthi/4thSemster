#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
	FILE *ip, *op;
	int **image;
	int i, j, max_value, num_rows, num_cols;
	char ch1, ch2;

	if (argc != 3)
	{
		exit(1);
	}

	ip = fopen(argv[1], 'r');
	op = fopen(argv[2], 'w');

	if (ip == NULL)
	{
		/* Checking whether the file exists or not */

		printf("Can't open file !!!. Please re-check the file name or execute code in right folder....");
		exit(1);
	}

	fscanf(ip, "%c%c", &ch1, &ch2);              /* Scanning the header file name */
	fscanf(ip, "%d %d", &num_cols, &num_rows);   /* Scanning number of columns and rows */
	fscanf(ip, "%d", &max_value);                /* Scanning the maximum value of pixel */

	/* Writing the header, number of columns and rows, maximum value of pixel */

	fprintf(op, "%c%c\n", ch1, ch2);
	fprintf(op, "%d %d\n", num_cols, num_rows);
	fprintf(op, "%d", max_value);

	/* Dynamically allocating memory */

	image = (int**) malloc(num_rows * sizeof(int*));

	for (i = 0; i < num_rows; i++)
	{
		image[i] = (int*) malloc(num_cols * sizeof(int));
	}


	/* Scanning and storing the pixel values of the image file */

	for (i = 0; i < num_rows; i++)
	{
		for (j = 0; j < num_cols; j++)
		{
			fscanf(ip, "%d", &image[i][j]);
		}
	}


	/* Writing the image pixels from the array we stored */

	for (i = 0; i < num_rows; i++)
	{
		for (j = 0; j < num_cols; j++)
		{
			fprintf(op, "%d", image[i][j]);
			fprintf(op, "\n");
		}
	}

	fclose(ip);
	fclose(op);

	return 0;
}
