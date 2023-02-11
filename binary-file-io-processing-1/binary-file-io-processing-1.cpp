#define _CRT_SECURE_NO_DEPRECATE
#include <iostream>

//defining variables
#define DATASIZE 375000
FILE* file_id1, * file_id2;
unsigned char data[DATASIZE], outdata[DATASIZE];
int i, j;
int filter[9] = { -1, -2, -3, -4, 0, 4, 3, 2, 1 };

int main()
{
	//opening input file
	file_id1 = fopen("D:\\unesco750-1.raw", "rb");
	if (file_id1 == NULL)
	{
		printf("Error: Could not open input file\n");
		return 0;
	}

	//reading input file
	fread(data, 1, DATASIZE, file_id1);
	fclose(file_id1);

	//applying filter
	for (i = 4; i < DATASIZE - 4; ++i)
	{
		int sum = 0;
		for (j = 0; j < 9; ++j)
			sum += data[i + j - 4] * filter[j];
		outdata[i] = sum;
	}

	//creating and opening output file
	file_id2 = fopen("D:\\output.raw", "wb");
	if (file_id2 == NULL)
	{
		printf("Error: Could not open output file\n");
		return 0;
	}

	//writing data to output file
	fwrite(outdata, 1, DATASIZE, file_id2);
	fclose(file_id2);

	printf("Success: File processed\n");
	return 1;
}