exefile = hh.exe
cfile = hh.cpp

$(exefile): $(cfile)
	g++ $(cfile) -o $(exefile) -g