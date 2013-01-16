/* -*- Mode: C; indent-tabs-mode: t; c-basic-offset: 4; tab-width: 4 -*-  */
/*
 * hangman
 * Copyright (C) 2013 alex <alex@archal>
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

#include "input.h"

#include <stdio.h>
#include <malloc.h>
#include <assert.h>
#include <stdlib.h>
#include <ctype.h>

void leeren()
{
	char c;
	do
	{
		c=getchar();
	} while (c!='\n' && c!=EOF && c!=0);

}

unsigned int getlength(unsigned char* input)
{
	unsigned int count=0;
	while (input[count]!='\0')
	{
		count++;
	}
	return count;
}

void allocate (unsigned char **ein, unsigned int *length)
{
	unsigned char *tmp;
	(*length)+=1;
	
	if(*ein==NULL)
	{
		tmp=malloc(((*length)+1)*sizeof(unsigned char));
	}
	else
		tmp=realloc(*ein,(*length)*sizeof(unsigned char));
	assert(tmp);
	tmp[(*length)-1]='\0';
	*ein=tmp;
}

void allocate_to (unsigned char **ein, unsigned int lengthdest)
{
	unsigned char *tmp;
	if (*ein==NULL)
		tmp=malloc((lengthdest+1)*sizeof(unsigned char));
	else
		tmp=realloc(*ein,(lengthdest+1)*sizeof(unsigned char));
	assert(tmp);
	tmp[lengthdest]='\0';
	*ein=tmp;
}

void eingabe (unsigned char **ein)
{
	unsigned char c=0;
	unsigned int length=0;

	allocate(ein,&length);
	c=getchar();
	while (c!='\n')
	{
		(*ein)[length-1]=c;
		allocate(ein, &length); 
		c=getchar();
	}
}

void eingabe2 (unsigned char **ein)
{
	unsigned char c=0; 
	unsigned int length=0;
	
	printf("Enter secret word: ");
	system("stty -echo > /dev/tty");
	allocate(ein,&length);
	c=getchar();
	while (c!='\n')
	{

		(*ein)[length-1]=(char)c;
		allocate(ein, &length); 
		c=getchar();
	} 
	system("stty echo > /dev/tty");
}


unsigned char einlesen_char()
{
	printf("Bitte geben Sie einen Buchstaben ein: ");
	unsigned char c=getchar();

	if (!isalpha(c) || getchar()!='\n')
	{
		printf("Fehler: nur ein Buchstabe erlaubt\n");
		leeren();
		return einlesen_char();
	}
	return c;
}

int is_in (unsigned char *ein, unsigned char *aus, unsigned char c_in)
{
	int found=0;
	int count=0;
	int length=getlength(ein);
	assert(count!=getlength(aus));

	while (count<length)
	{
		if (ein[count]==c_in)
		{
			aus[count]=c_in;
			found=1;
		}
		count++;
	}
	return found;
}

int is_in2 (unsigned char *ein, unsigned char *aus, unsigned char c_in)
{
	int found=0;
	int count=0;
	int length=getlength(ein);
	assert(count!=getlength(aus));

	while (count<length)
	{
		if (ein[count]==c_in)
		{
			aus[count*2]=c_in;
			found=1;
		}
		count++;
	}	
	return found;
}

int is_in_check (unsigned char *ein, unsigned char c_in)
{
	int found=0;
	int count=0;
	int length=getlength(ein);

	while (count<length)
	{
		if (ein[count]==c_in)
		{
			found=1;
		}
		count++;
	}
	return found;
}

int is_in_check2 (unsigned char *ein, unsigned char c_in)
{
	int found=0;
	int count=0;
	int length=getlength(ein);

	while (count<length)
	{
		if (ein[count]==c_in)
		{
			found=1;
		}
		count++;
	}
	return found;
}

int fillchar(unsigned char **ein, int length, unsigned char c)
{
	int count=0;
	if (length<0)
		return 0;
	allocate_to(ein,length);
	while (count<length)
	{
		(*ein)[count]=c;
		count++;
	}
	return 1;
}

int fillchar2(unsigned char **ein, int length, unsigned char c, unsigned char c2)
{
	int count=0;
	if (length<0)
		return 0;
	allocate_to(ein,length*2);
	while (count<length*2)
	{
		(*ein)[count]=c;
		count++;
		(*ein)[count]=c2;
		count++;
	}
	return 1;
}


