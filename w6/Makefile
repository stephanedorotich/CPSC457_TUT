all: sort graph chunks set

sort: s_driver.cpp sort.cpp
	g++ -Wall -O2 -o sort s_driver.cpp

graph: g_driver.cpp graph.cpp
	g++ -Wall -O2 -o graph g_driver.cpp

chunks: chunks.cpp
	g++ -Wall -O2 -o chunks chunks.cpp

set: basic_set.cpp
	g++ -Wall -O2 -o set basic_set.cpp

clean:
	rm sort graph set chunks
