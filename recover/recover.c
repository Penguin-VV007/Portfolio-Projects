#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

typedef uint8_t BYTE;

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        printf("Usage: ./recover MEMORY_IMAGE\n");
        return 1;
    }

    FILE *finput = fopen(argv[1], "r");

    if (finput == NULL)
    {
        printf("Error: File could not be read.\n");
        return 2;
    }

    BYTE buffer[512];
    char file_name[8];
    int counter = 0;
    FILE *foutput = NULL;

    while (fread(buffer, sizeof(BYTE), 512, finput) == 512)
    {
        if (buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff &&
            (buffer[3] & 0xf0) == 0xe0)
        {
            if (foutput != NULL)
            {
                fclose(foutput);
            }

            sprintf(file_name, "%03i.jpg", counter);
            foutput = fopen(file_name, "w");
            counter++;
        }

        if (foutput != NULL)
        {
            fwrite(buffer, sizeof(BYTE), 512, foutput);
        }
    }

    fclose(foutput);
    fclose(finput);
    return 0;
}
