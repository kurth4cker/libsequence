#pragma once

#include <stddef.h>

struct dlist_node {
	int val;
	struct dlist_node *next;
	struct dlist_node *prev;
};

struct dlist {
	struct dlist_node *head;
	struct dlist_node *tail;
	size_t size;
};

struct dlist *dlist_new(void);

struct dlist_node *dlist_add_head(struct dlist *, int);
struct dlist_node *dlist_add_tail(struct dlist *, int);

struct dlist_node *dlist_insert(struct dlist *, size_t, int);
struct dlist_node *dlist_insert_after(struct dlist *, struct dlist_node *, int);
struct dlist_node *dlist_insert_before(struct dlist *, struct dlist_node *, int);

void dlist_delete(struct dlist *, struct dlist_node *);
void dlist_delete_index(struct dlist *, size_t);

void dlist_clear(struct dlist *);
void dlist_free(struct dlist *);
