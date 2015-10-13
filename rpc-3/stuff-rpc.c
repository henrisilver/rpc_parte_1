/* stuff-rpc.c - Very Simple RPC client

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

/* Instructions: modify this file to meet the project specification. */

#include <stdio.h>
#include <stdlib.h>
#include <stuff.h>
#include <rpc.h>
#include <debug.h>

/* See below. */

#define SERVER getconf ("server")
#define PORT atoi(getconf ("port"))

/* 
   Remote functions.
 */


/* Return the value of PI. */

float pi(void)
{
  char buffer[BUFFSIZE];
	/*printf("hi2\n");*/
  read_config();
	/*printf("hi5\n");*/
  call_remote (SERVER, PORT, "pi", buffer);

  return atof(buffer);
}

float phi(void)
{
  char buffer[BUFFSIZE];

  read_config();

  call_remote (SERVER, PORT, "phi", buffer);

  return atof(buffer);
}


/* Return n+1. */

int plusone (int n)
{
    char buffer[BUFFSIZE];
    
    char string[20];
    
    sprintf(string, "plusone %d", n);
    
    read_config();
    
    call_remote (SERVER, PORT, string, buffer);
    
    return atof(buffer);

}

/* Increment n. */

void increment (int *n)
{
    char buffer[BUFFSIZE];
    
    char string[20];
    
    sprintf(string, "increment %d", *n);
    
    read_config();
    
    call_remote (SERVER, PORT, string, buffer);
    
    *n = atoi(buffer);
    
    
}



