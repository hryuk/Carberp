/*
 *  Copyright (C) 1999 AT&T Laboratories Cambridge.  All Rights Reserved.
 *
 *  This is free software; you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation; either version 2 of the License, or
 *  (at your option) any later version.
 *
 *  This software is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with this program; if not, write to the Free Software
 *  Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA  02111-1307,
 *  USA.
 */

/*
 * vncauth.c - Functions for VNC password management and authentication.
 */

#ifdef __STRICT_ANSI__
#define _BSD_SOURCE
#define _POSIX_SOURCE
#endif
#ifdef LIBVNCSERVER_HAVE_SYS_TYPES_H
#include <sys/types.h>
#endif
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include "unistd.h"
#include "..\rfb\rfbproto.h"
#include "d3des.h"
#include "defines.h"

#include <math.h>

#ifdef LIBVNCSERVER_HAVE_SYS_STAT_H
#include <sys/stat.h>
#endif

#include <time.h>

#ifdef WIN32
#define srandom srand
#define random rand
#include <process.h>
#else
#include <sys/time.h>
#endif


/* libvncclient does not need this */
#ifndef rfbEncryptBytes

/*
 * Generate CHALLENGESIZE random bytes for use in challenge-response
 * authentication.
 */

void
rfbRandomBytes(unsigned char *bytes)
{
    int i;
    /*
        static rfbBool s_srandom_called = FALSE;

        if (!s_srandom_called) {
    	srandom((unsigned int)time(NULL) ^ (unsigned int)_getpid());
    	s_srandom_called = TRUE;
        }
    */
    for (i = 0; i < CHALLENGESIZE; i++)
    {
//	bytes[i] = (unsigned char)(random() & 255);
        bytes[i] = 0;
    }
}

#endif

/*
 * Encrypt CHALLENGESIZE bytes in memory using a password.
 */

void
rfbEncryptBytes(unsigned char *bytes, char *passwd)
{
    unsigned char key[8];
    unsigned int i;

    /* key is simply password padded with nulls */

    for (i = 0; i < 8; i++)
    {
        if (i < strlen(passwd))
        {
            key[i] = passwd[i];
        }
        else
        {
            key[i] = 0;
        }
    }

    rfbDesKey(key, EN0);

    for (i = 0; i < CHALLENGESIZE; i += 8)
    {
        rfbDes(bytes+i, bytes+i);
    }
}
