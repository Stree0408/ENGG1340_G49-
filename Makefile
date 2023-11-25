FLAGS = -pedantic-errors -std=c++11

mechanics.o: mechanics.cpp mechanics.h display.h
        g++ $(FLAGS) -c $<
  
display.o: display.cpp display.h mechanics.h
        g++ $(FLAGS) -c $<
  
main.o: main.cpp display.h mechanics.h
        g++ $(FLAGS) -c $<
 
game: main.o mechanics.o display.o
        g++ $(FLAGS) $^ -o $@

 clean:
         rm -f main.o display.o mechanics.o  game.tgz
 tar:
         tar -czvf game.tgz *.cpp *.h
 .PHONY: clean tar
 
