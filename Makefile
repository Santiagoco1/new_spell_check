check: main.c src/dict.c src/check.c src/print.c src/ctree.c src/list.c src/corr.c src/metd.c
	gcc -g -std=c99 -Wall -Werror main.c src/dict.c src/check.c src/print.c src/ctree.c src/corr.c src/list.c src/metd.c -o check
	./check dictionary.txt text.txt
	rm check

time: main.c src/dict.c src/check.c src/print.c src/ctree.c src/list.c src/corr.c src/metd.c
	gcc -g -std=c99 -Wall -Werror main.c src/dict.c src/check.c src/print.c src/ctree.c src/corr.c src/list.c src/metd.c -o time
	time ./time dictionary.txt text.txt
	rm time

valgrind: main.c src/dict.c src/check.c src/print.c src/ctree.c src/list.c src/corr.c src/metd.c
	gcc -g -std=c99 -Wall -Werror main.c src/dict.c src/check.c src/print.c src/ctree.c src/list.c src/corr.c src/metd.c -o valgrind
	valgrind ./valgrind dictionary.txt text.txt
	rm valgrind