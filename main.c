/* -*- Mode: C; indent-tabs-mode: t; c-basic-offset: 4; tab-width: 4 -*-  */
/*
 * main.c
 * Copyright (C) 2013 alex <>
 * 
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 * 3. Neither the name ``alex'' nor the name of any other
 *    contributor may be used to endorse or promote products derived
 *    from this software without specific prior written permission.
 * 
 * hangman IS PROVIDED BY alex ``AS IS'' AND ANY EXPRESS
 * OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
 * WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED.  IN NO EVENT SHALL alex OR ANY OTHER CONTRIBUTORS
 * BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
 * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
 * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR
 * BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY,
 * WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR
 * OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF
 * ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */
#include <stdio.h>
#include <malloc.h>
#include "input.h"

#define empty_placeholder '_'
#define space ' '

int main()
{
	int tries=5;
	unsigned char x;
	unsigned char* eingabe_henker=NULL;
	unsigned char* eingabe_reveal=NULL;
	eingabe2(&eingabe_henker);
	if (fillchar2(&eingabe_reveal,getlength(eingabe_henker),empty_placeholder,space)==0)
		return 1;
	printf("%s\n",eingabe_reveal);
	while (tries>0)
	{

		x=einlesen_char();

		if(is_in2(eingabe_henker,eingabe_reveal,x)==0)
		{
			tries--;
		}
		printf("Noch %i Versuche.\n",tries);
		printf("%s\n",eingabe_reveal);
		if (is_in_check(eingabe_reveal,empty_placeholder)==0)
			break;
	}

	if(tries>=1)
		printf("Die Spieler haben gewonnen\n");
	else
		printf("Der Sensenmann hat euch alle gep0wnt\n");

	free(eingabe_reveal);
	eingabe_reveal=NULL;
	free(eingabe_henker);
	eingabe_henker=NULL;
	return (0);
}

