.SUFFIXES: .erl .beam

.erl.beam:
	erlc -W $<

ERL = erl -boot start_clean

MODS = test

all: compile
	${ERL} -pa '/home/cai/code/Learn/Erlang/ProgrammingErlang/exe10' -s test main

compile: ${MODS:%=%.beam}

clean:
	rm -rf *beam erl_crash.dump
