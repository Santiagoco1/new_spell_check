check: main.c src/dict.c src/check.c src/print.c src/ctree.c src/list.c src/corr.c src/metd.c src/auxi.c
	gcc -g -std=c99 -Wall -Werror main.c src/dict.c src/check.c src/print.c src/ctree.c src/corr.c src/list.c src/metd.c src/auxi.c -o check

test_auxi: tests/test_auxi.c src/auxi.c
	gcc -g -std=c99 -Wall -Werror tests/test_auxi.c src/auxi.c -o test_auxi

test_check: tests/test_check.c src/check.c src/ctree.c src/metd.c src/corr.c src/list.c src/auxi.c
	gcc -g -std=c99 -Wall -Werror tests/test_check.c src/check.c src/ctree.c src/metd.c src/corr.c src/list.c src/auxi.c -o test_check

test_corr: tests/test_corr.c src/corr.c
	gcc -g -std=c99 -Wall -Werror tests/test_corr.c src/corr.c -o test_corr

test_ctree: tests/test_ctree.c src/ctree.c
	gcc -g -std=c99 -Wall -Werror tests/test_ctree.c src/ctree.c -o test_ctree

test_dict: tests/test_dict.c src/dict.c src/ctree.c
	gcc -g -std=c99 -Wall -Werror tests/test_dict.c src/dict.c src/ctree.c -o test_dict

test_list: tests/test_list.c src/list.c src/corr.c
	gcc -g -std=c99 -Wall -Werror tests/test_list.c src/list.c src/corr.c -o test_list

test_metd: tests/test_metd.c src/metd.c src/ctree.c src/auxi.c
	gcc -g -std=c99 -Wall -Werror tests/test_metd.c src/metd.c src/ctree.c src/auxi.c -o test_metd