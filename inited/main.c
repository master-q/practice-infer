#include <stdio.h>

#define __infer_assert(E) {  \
  int *s = NULL;             \
  if (!(E)) *s = 0xDEADBEEF; \
}

struct foo {
	char *p;
};

void check_foo (struct foo *f) {
#if 1
	__infer_assert(f && f->p == NULL);
#endif
}

int main() {
#if 1
	struct foo f = { NULL };
#else
	char c;
	struct foo f = { &c };
#endif
	check_foo(&f);
}
