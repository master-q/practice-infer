#include <glib.h>

struct foo {
	int *p;
};

struct foo* wrap(int *p) {
	struct foo* f = g_malloc(sizeof(struct foo));
	f->p = p;
	return f;
}

struct foo* create(void) {
	int *new_p = g_malloc(sizeof(int));
	return wrap(new_p);
}

void delete(struct foo *f) {
	g_free(f->p);
	g_free(f);
}

int main() {
	struct foo *f;
	f = create();
	delete(f);
}
