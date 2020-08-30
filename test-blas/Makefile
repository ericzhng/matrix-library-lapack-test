
all: level1 level2 level3 cblas

level1:
	make -C level-1

level2:
	make -C level-2

level3:
	make -C level-3

cblas:
	make -C test-cblas

clean :
	make -C level-1 clean
	make -C level-2 clean
	make -C level-3 clean
	make -C test-cblas clean
	