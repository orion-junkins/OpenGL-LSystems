main:		main.cpp
		g++ --std=c++17 -framework OpenGL -framework GLUT main.cpp LSystem.cpp -o main -Wno-deprecated
