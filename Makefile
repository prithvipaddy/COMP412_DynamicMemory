CC = g++
CFLAG = 

all: grading_main.exe admissions_main.exe calc_main.exe

grading_main.exe : grading.o grading_main.o
	$(CC) $(CFLAG) -o grading_main.exe grading.o grading_main.o

grading_main.o : grading_main.cpp
	$(CC) $(CFLAG) -c grading_main.cpp

grading.o : grading.cpp
	$(CC) $(CFLAG) -c grading.cpp

admissions_main.exe : admissions.o admissions_main.o
	$(CC) $(CFLAG) -o admissions_main.exe admissions.o admissions_main.o

admissions_main.o : admissions_main.cpp
	$(CC) $(CFLAG) -c admissions_main.cpp

admissions.o : admissions.cpp
	$(CC) $(CFLAG) -c admissions.cpp

calc_main.exe : calc.o calc_main.o
	$(CC) $(CFLAG) -o calc_main.exe calc.o calc_main.o

calc_main.o : calc_main.cpp
	$(CC) $(CFLAG) -c calc_main.cpp

calc.o : calc.cpp
	$(CC) $(CFLAG) -c calc.cpp
