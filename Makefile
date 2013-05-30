##############################################################################
# COSC1283/1284 - Programming Techniques
# Semester 1 2012 Assignment #1
# Full Name        : Lauren Grimes
# Student Number   : s3228871
# Yallara Username : s3228871
# Course Code      : COSC1284
# Program Code     : BP162
##############################################################################

ass1: assignment1.o utility.o options.o
	gcc -o assignment1 assignment1.o utility.o options.o -ansi -Wall -pedantic -g
 
assignment1.o: assignment1.c assignment1.h
	gcc -c assignment1.c -ansi -Wall -pedantic -g 

utility.o: utility.c
	gcc -c utility.c -ansi -Wall -pedantic -g 

options.o: options.c
	gcc -c options.c -ansi -Wall -pedantic -g 

clean:
	rm utility.o assignment1.o options.o assignment1  

archive:
	zip $(USER)-a1.zip assignment1.c assignment1.h options.c options.h utility.c utility.h Makefile README

