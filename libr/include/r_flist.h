/* radare - LGPL - Copyright 2010 nibble <.ds@gmail.com> */

#ifndef _INCLUDE_R_FLIST_H_
#define _INCLUDE_R_FLIST_H_

#include <stdlib.h>
#include <string.h>
//#include <r_types.h>

#define r_flist_t void**
#define RFList void**

#ifdef R_API
R_API void **r_flist_resize(void **it, int n);
#define r_flist_rewind(it) while(it!=*it) it--; it++;
#define r_flist_next(it) *it!=0
#define r_flist_get(it) *(it++)
#define r_flist_unref(x) x

#define r_flist_iterator(x) x
/*
static inline void **r_flist_iterator(void **it) {
	r_flist_iterator(it);
	return it;
}
*/

static inline void **r_flist_init(void **it, int n) {
	*it = it;
	memset (++it, 0, (n+1) * sizeof (void*));
	return it;
}

static inline void **r_flist_new(int n) {
	void **it;
	if (!(it = (void **)malloc ((n+2) * sizeof (void*))))
		return NULL;
	return r_flist_init (it, n);
}

static inline void **r_flist_prev(void **it) {
	void **p = it--;
	return (it==*it)?p:it;
}

static inline void r_flist_set(void **it, int idx, void *data) {
	r_flist_rewind (it);
	it[idx] = data;
}

static inline void r_flist_delete(void **it, int idx) {
	r_flist_rewind (it);
	free (it[idx]);
	for(it += idx; *it; it++) *it = *(it+1);
}

#define r_flist_foreach(it, pos) \
	r_flist_rewind(it); \
	while (r_flist_next (it) && (pos = r_flist_get (it)))

static inline void r_flist_free(void **it) {
	void *pos;
	r_flist_foreach (it, pos)
		free (pos);
	r_flist_rewind (it);
	free (--it);
}
#endif

#endif
