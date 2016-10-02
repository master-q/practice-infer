#include <stdio.h>
#include <string.h>
//#define QUEUEDEBUG /* Assert at run-time */
#include "queue.h"

#define __infer_assert(E) {  \
  int *s = NULL;             \
  if (!(E)) *s = 0xDEADBEEF; \
}

struct mylist_entry {
	LIST_ENTRY(mylist_entry) link;
	int val;
};

LIST_HEAD(mylist_head, mylist_entry) g_mylist_head = LIST_HEAD_INITIALIZER(mylist_head);

struct mylist_entry *mylist_first(struct mylist_head *head) {
	return LIST_FIRST(head);
}

void mylist_remove(struct mylist_entry *elm) {
	__infer_assert(!(
		    (elm)->link.le_next &&
		    (elm)->link.le_next->link.le_prev !=
		    &(elm)->link.le_next)) /* Precondition on DbC */
	LIST_REMOVE(elm, link);
}

int main() {
	struct mylist_entry e1;
	mylist_remove(&e1);
}
