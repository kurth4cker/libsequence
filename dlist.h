#pragma once

#include <stddef.h>

struct dnode {
	struct dnode *next;
	struct dnode *prev;
	int val;
};

struct dlist {
	struct dnode *head;
	struct dnode *tail;
	size_t size;
};

struct dlist *dlist_new(void);

struct dnode *dlist_add_head(struct dlist *, int);
struct dnode *dlist_add_tail(struct dlist *, int);

struct dnode *dlist_insert(struct dlist *, size_t, int);
struct dnode *dlist_insert_after(struct dlist *, struct dnode *, int);
struct dnode *dlist_insert_before(struct dlist *, struct dnode *, int);

void dlist_delete(struct dlist *, struct dnode *);
void dlist_delete_index(struct dlist *, size_t);

void dlist_clear(struct dlist *);
void dlist_free(struct dlist *);
