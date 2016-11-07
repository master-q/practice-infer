all: a.out

a.out: main.c
	gcc -o $@ $<

verify: main.c
	infer -- gcc -c $<

clean:
	rm -rf a.out *.o infer-out/

.PHONY: all verify clean
