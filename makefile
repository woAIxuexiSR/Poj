exefile = hh.exe
cfile = ATP.cpp

$(exefile): $(cfile)
	g++ $(cfile) -o $(exefile) -g