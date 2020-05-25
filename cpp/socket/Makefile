client : client.o
	g++ -o client client.o -I./
client.o : client.cc
	g++ -c client.cc -I./
	
server : server.o
	g++ -o server server.o -I./
server.o : server.cc
	g++ -c server.cc -I./

.PHONY : clean
clean:
	-rm server client *.o
