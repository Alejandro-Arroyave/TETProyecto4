CXX=icpc
CXXFLAGS=-xMIC-AVX512 -qopenmp -mkl -std=c++11
OPTRPT=-qopt-report=5

default : app


perm.o : perm.cc
	${CXX} -c ${OPTRPT} ${CXXFLAGS} -o "$@" "$<"

app :  perm.o
	${CXX} ${OPTRPT} ${CXXFLAGS} -o "$@" "$<"

clean :
	rm app perm.o *.optrpt
