#include <unistd.h>
#include <sys/types.h>

#define __infer_assert(E) {  \
  int *s = NULL;             \
  if (!(E)) *s = 0xDEADBEEF; \
}

int main() {
	uid_t id;
	id = getuid();
	__infer_assert(id != 0);
}
