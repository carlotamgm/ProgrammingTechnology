# PRÁCTICA 2
# Autoras: Carlota Moncasi y E. Lilai Naranjo
# NIPs: 839841 y 840091

PROG:=main
SRCS:= main.cc \
	   Instruccion.cc \
	   Programa.cc 

CXX:= g++ -std=c++11 -O3

OBJS:=$(SRCS:.cc=.o)
DEPS:=$(SRCS:.cc=.d)

all: $(PROG)

$(PROG): $(OBJS)
	$(CXX) -o $@ $(OBJS)

.cc.o:
	$(CXX) -c $<
	
edit:
	geany -i -s *.h *.cc &

clean:
	@rm -f $(PROG) $(OBJS) $(DEPS) core

# Dependencias
-include $(DEPS)