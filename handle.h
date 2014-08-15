
#ifndef LEELA_HANDLE_H
#define LEELA_HANDLE_H

#include "msg_queue.h"
#include "context.h"
#include <glib.h>

struct lhandle_name {
    guint32 handle; /** unique in global handle_store*/
    gchar *name;
};

struct lhandle_store {
    guint handleIdx;
    GList *ctxList;
    GMutex mtx;
    GArray *handleAry;
};

guint32 leela_handle_findname(const char *name);
const char *leela_name_handle(guint32 handle,const char *name);
void leela_handle_init();

guint
leela_handle_register(struct leela_context *ctx);

struct leela_context *
leela_handle_grab(guint handle);

#endif
