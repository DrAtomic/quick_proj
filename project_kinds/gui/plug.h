#ifndef PLUG_H
#define PLUG_H

#include <stddef.h>

#ifdef __cplusplus
extern "C" {
#endif

typedef void (*plug_init_t)(void);
typedef void (*plug_update_t)(void);
typedef void *(*plug_pre_reload_t)(void);
typedef void (*plug_post_reload_t)(void *state);

#ifdef __cplusplus
}
#endif

#endif /* PLUG_H */
