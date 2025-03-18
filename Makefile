CC := gcc

football.exe: # fill in files here
	football: football_main.o football.o
	$(CC) $(CFLAGS) -o football football_main.o football.o

	football_main.o: football_main.c football.h
	$(CC) $(CFLAGS) -c football_main.c

	football.o: football.c football.h
	$(CC) $(CFLAGS) -c football.c

temperature.exe: # fill in files here
	temperature: temperature_main.o temperature.o
	$(CC) $(CFLAGS) -o temperature temperature_main.o temperature.o

	temperature_main.o: temperature_main.c temperature.h
	$(CC) $(CFLAGS) -c temperature_main.c

	temperature.o: temperature.c temperature.h
	$(CC) $(CFLAGS) -c temperature.c# fill in commands here
