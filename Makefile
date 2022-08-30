check: main.c src/dict.c src/check.c src/print.c src/ctree.c src/list.c src/corr.c
	- gcc -g -std=c99 -Wall -Werror main.c src/dict.c src/check.c src/print.c src/ctree.c src/corr.c src/list.c -o check
	- ./check files/dictionary.txt files/text.txt
	- rm check

time: main.c src/dict.c src/check.c src/print.c src/ctree.c src/list.c src/corr.c
	- gcc -g -std=c99 -Wall -Werror main.c src/dict.c src/check.c src/print.c src/ctree.c src/corr.c src/list.c -o time
	- time ./time files/dictionary.txt files/text.txt
	- rm time