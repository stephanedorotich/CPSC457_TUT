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

day2: barrier dice th_reuse share

barrier: barrier.cpp
	g++ -O2 -Wall -pthread -o barrier barrier.cpp

dice: dice.cpp
	g++ -O2 -Wall -pthread -o dice dice.cpp

th_reuse: thread_reuse.cpp
	g++ -O2 -Wall -pthread -o th_reuse thread_reuse.cpp

share: sharing_work.cpp
	g++ -O2 -Wall -pthread -o share sharing_work.cpp

clean:
	rm ser_* par_pro db extender
	rm barrier dice th_reuse share
