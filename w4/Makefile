all: ser_pro par_pro par_pro_sol extender ser_db db

ser_pro: serial_processor.cpp
	g++ -O2 -Wall -o ser_pro serial_processor.cpp

par_pro: parallel_processor.cpp
	g++ -O2 -Wall -pthread -o par_pro parallel_processor.cpp

par_pro_sol: parallel_processor_sol.cpp
	g++ -O2 -Wall -pthread -o par_pro parallel_processor_sol.cpp

extender: extender.cpp
	g++ -O2 -Wall -o extender extender.cpp

ser_db: serial_dartboard.cpp
	g++ -O2 -Wall -o ser_db serial_dartboard.cpp

db: dartboard.cpp
	g++ -O2 -Wall -pthread -o db dartboard.cpp

clean:
	rm ser_* par_pro db extender
