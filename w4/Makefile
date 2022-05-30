all: ser_pro par_pro extender ser_db par_db

ser_pro: serial_processor.cpp
	g++ -O2 -Wall -o ser_pro serial_processor.cpp

par_pro: parallel_processor.cpp
	g++ -O2 -Wall -pthread -o par_pro parallel_processor.cpp

extender: extender.cpp
	g++ -O2 -Wall -o extender extender.cpp

ser_db:
	g++ -O2 -Wall -o ser_db serial_dartboard.cpp

par_db:
	g++ -O2 -Wall -pthread -o par_db dartboard.cpp

clean:
	rm ser_* par_* extender
