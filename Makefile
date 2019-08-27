CC=g++ 
CFLAGS=-Wall -c

workout: workoutrandomizer.o main1.o
	$(CC) workoutrandomizer.o main1.o -o workout
workoutrandomizer.o: workoutrandomizer.cc
	$(CC)$(CFLAGS) workoutrandomizer.cc
main1.o: main1.cc
	$(CC)$(CFLAGS) main1.cc


clean:
	rm -f workout workoutrandomizer.o main1.o
run: workout
	./workout
	