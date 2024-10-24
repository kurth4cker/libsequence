// SPDX-License-Identifier: GPL-3.0-or-later
// SPDX-FileCopyrightText: 2024 kurth4cker <kurth4cker@gmail.com>

#include <stdlib.h>

#include <dlist.h>

struct dlist *
dlist_new(void)
{
	struct dlist *list = malloc(sizeof(*list));
	if (!list)
		return NULL;

	list->head = list->tail = NULL;

	return list;
}

struct dnode *
dlist_add_head(struct dlist *list, int val)
{
	struct dnode *node = malloc(sizeof(*node));
	if (!node)
		return NULL;
	node->val = val;
	node->prev = NULL;

	node->next = list->head;
	list->head = node;
	list->size++;
	if (!list->tail)
		list->tail = node;
	else
		node->next->prev = node;

	return node;
}

struct dnode *
dlist_add_tail(struct dlist *list, int val)
{
	struct dnode *node = malloc(sizeof(*node));
	if (!node)
		return NULL;
	node->val = val;
	node->next = NULL;

	node->prev = list->tail;
	list->tail = node;
	list->size++;
	if (!list->head)
		list->head = node;
	else
		node->prev->next = node;

	return node;
}

struct dnode *
dlist_insert(struct dlist *list, size_t idx, int val)
{
	if (idx == 0)
		return dlist_add_head(list, val);
	if (idx == list->size)
		return dlist_add_tail(list, val);

	struct dnode *node = list->head;
	for (size_t i = 0; i < idx; i++)
		node = node->next;

	return dlist_insert_before(list, node, val);
}

struct dnode *
dlist_insert_after(struct dlist *list, struct dnode *prev, int val)
{
	struct dnode *node = malloc(sizeof(*node));
	if (!node)
		return NULL;

	list->size++;
	node->val = val;
	node->prev = prev;
	node->next = prev->next;
	prev->next = node;
	if (node->next)
		node->next->prev = node;
	else
		list->tail = node;

	return node;
}

struct dnode *
dlist_insert_before(struct dlist *list, struct dnode *next, int val)
{
	struct dnode *node = malloc(sizeof(*node));
	if (!node)
		return NULL;

	list->size++;
	node->val = val;
	node->next = next;
	node->prev = next->prev;
	next->prev = node;
	if (node->prev)
		node->prev->next = node;
	else
		list->head = node;

	return node;
}

void
dlist_delete(struct dlist *list, struct dnode *node)
{
	if (node->next)
		node->next->prev = node->prev;
	else
		list->tail = node->prev;

	if (node->prev)
		node->prev->next = node->next;
	else
		list->head = node->next;

	free(node);
	list->size--;
}

void
dlist_delete_index(struct dlist *list, size_t idx)
{
	struct dnode *node = list->head;
	while (idx--)
		node = node->next;

	dlist_delete(list, node);
}

void
dlist_clear(struct dlist *list)
{
	struct dnode *node = list->head;
	struct dnode *next;

	while (node) {
		next = node->next;
		free(node);
		node = next;
	}

	list->head = NULL;
	list->tail = NULL;
	list->size = 0;
}

void
dlist_free(struct dlist *list)
{
	dlist_clear(list);
	free(list);
}
