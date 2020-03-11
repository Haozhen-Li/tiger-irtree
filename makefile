a.out: absyn.o mipsframe.o prabsyn.c symbol.c translate.c util.c env.c lex.yy.c parse.c printtree.c table.c tree.o y.tab.c errormsg.c main.c semant.o temp.c types.c
	cc -g absyn.o mipsframe.o prabsyn.c symbol.c translate.c util.c env.c lex.yy.c parse.c printtree.c table.c tree.o y.tab.c errormsg.c main.c semant.o temp.c types.c

parsetest.o: parsetest.c errormsg.h util.h parse.h absyn.h prabsyn.h symbol.h
	cc -g -c parsetest.c absyn.c symbol.c

y.tab.o: y.tab.c
	cc -g -c y.tab.c

y.tab.c: tiger.grm
	yacc -dv tiger.grm

y.tab.h: y.tab.c
	echo "y.tab.h was created at the same time as y.tab.c"

errormsg.o: errormsg.c errormsg.h util.h
	cc -g -c errormsg.c

lex.yy.o: lex.yy.c y.tab.h errormsg.h util.h
	cc -g -c lex.yy.c

#lex.yy.c: tiger.lex
#	lex tiger.lex

util.o: util.c util.h
	cc -g -c util.c

absyn.o: absyn.c absyn.h
	cc -g -c absyn.c

tree.o: tree.c tree.h
	cc -g -c tree.c

translate.o: translate.c translate.h
	cc -g -c translate.c

semant.o: semant.c semant.h
	cc -g -c semant.c

mipsframe.o: mipsframe.c frame.h
	cc -g -c mipsframe.c

prabsyn.o: prabsyn.c prabsyn.h
	cc -g -c prabsyn.c

parse.o: parse.c parse.h
	cc -g -c parse.c

symbol.o: symbol.c symbol.h
	cc -g -c symbol.c

table.o: table.c table.h
	cc -g -c table.c

output: a.exe tiger.grm
	for test in `ls ../testcases`; do \
		./$< ../testcases/$${test} $${test}.log; \
                echo $${test}; \
		diff $${test}.log ref$${test}.log; \
	done

clean: 
	rm -f a.out a.exe util.o lex.yy.o errormsg.o y.tab.c y.tab.h y.tab.o y.output symbol.o absyn.o prabsyn.o parse.o table.o mipsframe.o semant.o tree.o
