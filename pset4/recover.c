/**
 * recover.c
 *
 * Computer Science 50
 * Problem Set 4
 *
 * Recovers JPEGs from a forensic image.
 */

#include <stdio.h>
#include <stdint.h>
#include <string.h>

int main(int argc, char* argv[])
{
    // read the card file
    FILE *file_in = fopen("card.raw", "r");

    if (file_in == NULL)
    {
        printf("unable to open card file");
        return 1;
    }

    // counter for file name
    int file_num = 0;

    // set buffer size
    uint8_t buffer[512];

    // pointer to out file
    FILE* file_out = NULL;

    // iterate across the card file
    while (fread(buffer, 512, 1, file_in))
    {
        //check for JPEG start
        if (buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff && (buffer[3] >= 0xe0 && buffer[3] <= 0xef))
        {
            //close last outfile if there is one open
            if (file_out != NULL)
                fclose(file_out);

            // create out file name
            char file_name[8];
            sprintf(file_name, "%03d.jpg", file_num);

            file_num++;

            // open file out to write to
            file_out = fopen(file_name, "w");
        }

        // if file out is still open, write the block
        if (file_out != NULL)
            fwrite(buffer, 512, 1, file_out);
    }

    // close everything
    fclose(file_in);

    if (file_out != NULL)
        fclose(file_out);


    return 0;
}
