/* -*- Mode: C; indent-tabs-mode: t; c-basic-offset: 4; tab-width: 4 -*-  */
/*
 * main.c
 * Copyright (C) 2013 alex <>
 * 
 * hangman is free software: you can redistribute it and/or modify it
 * under the terms of the GNU General Public License as published by the
 * Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 * 
 * hangman is distributed in the hope that it will be useful, but
 * WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
 * See the GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License along
 * with this program.  If not, see <http://www.gnu.org/licenses/>.
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

