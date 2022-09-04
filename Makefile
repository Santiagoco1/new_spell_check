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

test_check: tests/test_check.c src/check.c src/ctree.c src/metd.c src/corr.c src/list.c
	gcc -g -std=c99 -Wall -Werror tests/test_check.c src/check.c src/ctree.c src/metd.c src/corr.c src/list.c -o test_check

test_corr: tests/test_corr.c src/corr.c
	gcc -g -std=c99 -Wall -Werror tests/test_corr.c src/corr.c -o test_corr

test_ctree: tests/test_ctree.c src/ctree.c
	gcc -g -std=c99 -Wall -Werror tests/test_ctree.c src/ctree.c -o test_ctree

test_dict: tests/test_dict.c src/dict.c src/ctree.c
	gcc -g -std=c99 -Wall -Werror tests/test_dict.c src/dict.c src/ctree.c -o test_dict

test_list: tests/test_list.c src/list.c src/corr.c
	gcc -g -std=c99 -Wall -Werror tests/test_list.c src/list.c src/corr.c -o test_list

test_metd: tests/test_metd.c src/metd.c src/ctree.c
	gcc -g -std=c99 -Wall -Werror tests/test_metd.c src/metd.c src/ctree.c -o test_metd