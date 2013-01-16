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

#ifndef _INPUT_H_
#define _INPUT_H_

void eingabe (unsigned char **ein);
void eingabe2 (unsigned char **ein);
int is_in (unsigned char *ein, unsigned char *aus, unsigned char c_in);
int is_in2 (unsigned char *ein, unsigned char *aus, unsigned char c_in);
int is_in_check (unsigned char *ein, unsigned char c_in);
int fillchar(unsigned char **ein, int length,unsigned char c);
int fillchar2(unsigned char **ein, int length,unsigned char c,unsigned char c2);
unsigned char einlesen_char();
unsigned int getlength(unsigned char* input);

#endif // _INPUT_H_

