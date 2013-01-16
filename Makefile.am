## Process this file with automake to produce Makefile.in

## Created by Anjuta

AM_CPPFLAGS = \
	-DPACKAGE_DATA_DIR=\""$(pkgdatadir)"\" \
	$(NCURSES_CFLAGS)

AM_CFLAGS =\
	 -Wall\
	 -g

bin_PROGRAMS = hangman

hangman_SOURCES = \
	main.c \
	input.h \
	input.c

hangman_LDFLAGS = 

hangman_LDADD =  \
	$(NCURSES_LIBS)

