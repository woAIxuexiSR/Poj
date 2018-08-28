exefile = hh.exe
cfile = Trie.cpp

$(exefile): $(cfile)
	g++ $(cfile) -o $(exefile) -g