#ifndef SHH_H_
#define SHH_H_

#ifdef __cplusplus
extern "C" {
#endif

#include <json-c/json.h>

json_object *
shhVersion();

json_object *
shhPost(const char *from, const char *to, const char *topics,
        const char *payload, const char *priority, const char *ttl);

json_object *
shhNewIdentity();

json_object *
shhHasIdentity(const char *address);

json_object *
shhNewFilter(const char *topics, const char *to);

json_object *
shhUninstallFilter(const char *filterId);

json_object *
shhGetFilterChanges(const char *filterId);

json_object *
shhGetMessages(const char *filterId);

#ifdef __cplusplus
}
#endif

#endif /* SHH_H_ */