CC = "g++"
PROJECT = TestOpencv
SRC = code.cpp

Libs = `pkg-config opencv4 --cflags --libs`
$(PROJECT) : $(SRC)
	$(CC) $(SRC) -o $(PROJECT) $(Libs)
