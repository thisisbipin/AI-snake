app: link
	export LD_LIBRARY_PATH=SFML/lib && ./sfml-app
link: compile
	g++ main.o -o sfml-app -LSFML/lib -lsfml-graphics -lsfml-window -lsfml-system
compile:
	g++ -c main.cpp -ISFML/include