/* log-rpc.c - Very Simple RPC Server, vr. 01
 
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


/* Read log file and return the value. */
int read_log (void)
{
    char buffer[LOGBUFFSIZE];
    char string[30];
    int timeout;
    
    timeout = 0;
    
    do {
        
        
        
        sprintf(string, "read_log %s", LOGFILE);
        
        read_config();
        
        timeout = call_remote (SERVER, PORT, string, buffer);
        
    } while(timeout);
    
    return atoi(buffer);
}

/* Increment the value on the log file. */
int write_log (void)
{
    char buffer[LOGBUFFSIZE];
    
    char string[30];
    
    int timeout;
    
    int loop, new_n, old_n;
    
    sprintf(string, "write_log %s", LOGFILE);
    
    read_config();
    
   
    
    timeout = 0;
    
    loop = 0;
    
    old_n = read_log();
    
    new_n = old_n;
    
    do {
        
        loop = 0;
        
        timeout = call_remote (SERVER, PORT, string, buffer);
        
        if(!timeout) {
            new_n = atoi(buffer);
        }
        else {
            new_n = read_log();
        }
        
        if(new_n <= old_n) {
            loop = 1;
        }
        else {
            old_n = new_n;
        }
        
    } while (loop);
    
    return atoi(buffer);
}
