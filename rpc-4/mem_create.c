/* mem_create.c - Memory creation

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

/* Get the last allocated memory */
buffer_t getLastFile() {
    FILE *fp = fopen ("mem//i","r+");
    char out[sizeof(buffer_t)];
    fgets(out, sizeof(buffer_t), fp);
    fclose(fp);
    return (buffer_t)atoi(out);
}

int main (int argc, char **argv)
{
    char file[20];
    FILE *fp;
    int size = atoi(argv[1]);
    buffer_t target = getLastFile()+1;
    sprintf(file, "mem//%d",(int) target);
    fp = fopen(file, "w+");
    fprintf(fp,"%d\n",size);
    fclose(fp);
    /* increment i */
    fp = fopen ("mem//i","w");
    fprintf(fp,"%d",(int)target);
    
    /* print result */
    printf("%d",(int)target);
    fclose(fp);
    return EXIT_SUCCESS; 
}
