/* read_log.c - Read from log.

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

int main (int argc, char **argv)
{
    FILE *fp;
    int n;
    
    fp = fopen (argv[1], "r");
    
    /* If file does not exist, initialize it. */
    if (!fp)
    {
        fp = fopen (argv[1], "w");
        sysfault (!fp, -1);
        fprintf (fp, "%d\n", 0);
        fclose (fp);
        printf("%d\n", 0);
        
        return EXIT_SUCCESS;
    }
    
    sysfault (!fp, -1);
    
    fscanf (fp, "%d", &n);
    
    fclose (fp);
    
    printf("%d\n", n);
  
    return EXIT_SUCCESS;
}
