all: a.out

a.out: main.c
	gcc -o $@ $<

verify: main.c
	infer -- gcc -c $<

clean:
	rm -f a.out *.o

.PHONY: all verify clean
