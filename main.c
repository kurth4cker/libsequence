// SPDX-License-Identifier: GPL-3.0-or-later
// SPDX-FileCopyrightText: 2024 kurth4cker <kurth4cker@gmail.com>

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

// #include <vector.h>
#include <dlist.h>

void
print_dlist(const struct dlist *list)
{
	const struct dlist_node *node = list->head;

	while (node) {
		printf("%d\n", node->val);
		node = node->next;
	}
}

void
rprint_dlist(const struct dlist *list)
{
	const struct dlist_node *node = list->tail;

	while (node) {
		printf("%d\n", node->val);
		node = node->prev;
	}
}

int
main(void)
{
	struct dlist *list = dlist_new();

	if (!list) {
		fprintf(stderr, "dlist_new failed\n");
		exit(EXIT_FAILURE);
	}
	assert(list->head == NULL);
	assert(list->tail == NULL);

	struct dlist_node *node = NULL;
	node = dlist_add_tail(list, 8);
	dlist_delete(list, node);
	dlist_add_tail(list, 16);
	dlist_add_tail(list, 32);
	node = dlist_add_tail(list, 64);

 
	dlist_insert_before(list, node, 128);
	node = dlist_insert_before(list, list->head, 256);
	dlist_insert_after(list, node, 512);

	dlist_insert(list, 3, 1024);
	dlist_insert(list, 4, 2048);
	dlist_insert(list, 0, 4096);

	dlist_insert(list, 9, 8192);

	dlist_delete(list, node);
	dlist_delete(list, list->head);
	dlist_delete(list, list->tail);
	dlist_delete_index(list, 1);
	dlist_delete_index(list, 1);
	dlist_delete_index(list, 0);
	dlist_delete_index(list, 3);

	print_dlist(list);

	dlist_clear(list);
	printf("after clear\n");
	print_dlist(list);
	// printf("---\n");
	// rprint_dlist(list);
}
