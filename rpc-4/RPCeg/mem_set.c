/* mem_set.c - Memory set

   Copyright 2014  Monaco F. J.   <monaco@icmc.usp.br>

   This file is part of POSIXeg. 

    POSIXeg is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    POSIXeg is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with .  If not, see <http://www.gnu.org/licenses/>. 

*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef char * buffer_t;

int main (int argc, char **argv)
{
    buffer_t target = (buffer_t)atoi(argv[1]);
    const char* source = argv[2];
    int length = atoi(argv[3]);
    char file[20];
    int i,fileSize;
    FILE *fp;
    sprintf(file, "mem//%d",(int) target);
    fp = fopen(file, "r");
    /* check size and seek */
    if (fp == NULL)
    {
        printf("-1\n");/*seg fault*/
        return EXIT_FAILURE;
    }
    fscanf(fp,"%d\n",&fileSize);
    fclose(fp);
    if (length > fileSize)
    {
        printf("-1\n");/*seg fault*/
        return EXIT_FAILURE;
    }
    /* rewrite the file */
    fp = fopen(file, "w");
    fprintf(fp,"%d\n",fileSize);
    /* if size ok */
    for (i=0; i<length; i++)
        fputc(source[i], fp);
    fclose(fp);

    return EXIT_SUCCESS;
}
