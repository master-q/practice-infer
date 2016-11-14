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

LIST_HEAD(mylist_head, mylist_entry) g_mylist_head =
    LIST_HEAD_INITIALIZER(mylist_head);

void mylist_insert_head(struct mylist_head *head, struct mylist_entry *elm) {
	__infer_assert(!(
		    (head)->lh_first &&
		    (head)->lh_first->link.le_prev != &(head)->lh_first
		)) /* Precondition on DbC */
	LIST_INSERT_HEAD(head, elm, link);
}

int main() {
	struct mylist_entry e1;
	mylist_insert_head(&g_mylist_head, &e1);
}
