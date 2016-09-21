
CC=g++
EXEC=DevMoteur
INC= $(wildcard _Librairies/Moteur2D/*.h) $(wildcard DevDuMoteur/*.h)
SRC= $(wildcard _Librairies/Moteur2D/*.cpp) $(wildcard DevDuMoteur/*.cpp)
OBJ= $(SRC:.cpp=.o)

LIBDIR= _Librairies/SFML/lib/
LIBS= -lsfml-graphics-s -lsfml-system-s -lsfml-window-s
LDFLAGS= -L$(LIBDIR) $(LIBS)

INCDIR= -I_Librairies/SFML/include/ -I_Librairies/Moteur2D/
CFLAGS= $(INCDIR) -W -Wall -ansi -pedantic

all: $(EXEC)
	@echo $(SRC)

DevMoteur: $(OBJ)
	$(CC) -o $@ $^ $(LDFLAGS)

MainDev.o: $(INC)

%.o: %.cpp
	$(CC) -o $@ -c $< $(CFLAGS)

.PHONY: clean mrproper

clean:
	rm -rf $(OBJ)

mrproper: clean
	rm -rf $(EXEC)
