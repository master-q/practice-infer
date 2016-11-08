all: a.out

a.out: main.c
	gcc `pkg-config glib-2.0 --cflags --libs` -o $@ $<

verify: main.c
	infer -- gcc `pkg-config glib-2.0 --cflags` -c $<

clean:
	rm -rf a.out *.o infer-out/

.PHONY: all verify clean
