#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstdint>
using namespace std;

int main()
{
	FILE *read = fopen("input.in", "rb");
	FILE *write = fopen("output.out", "wb");

	fseek(read, 0L, SEEK_END);
	size_t size = ftell(read);
	fseek(read, 0L, SEEK_SET);

	uint8_t *dataRead = (uint8_t *) malloc(size);
	uint8_t *dataWrite = (uint8_t *) malloc(size);

    fread(dataRead, 1, size, read);

	for (size_t i=0;i<size;i++)
	{
	    dataWrite[i] = (dataRead[i]>>4);
	    printf("%X\n",dataWrite[i]);
	}



    fwrite(dataWrite, 1, size, write);

	free(dataRead);
	free(dataWrite);

	fclose(read);
	fclose(write);
	return 0;
}
