#include <glib.h>

struct foo {
	int *p;
};

void set_foo(int v, struct foo *f) {
	f->p = g_realloc(f->p, 10*sizeof(int));
	f->p[0] = 9191;
	g_free(f->p);
}

int main() {
	struct foo f;
	f.p = g_malloc(sizeof(int));
	set_foo(1, &f);
}
