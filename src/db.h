#ifndef DB_H_
#define DB_H_

#ifdef __cplusplus
extern "C" {
#endif

#include <json-c/json.h>

json_object *
dbPutString(const char *database, const char *key, const char *value);

json_object *
dbGetString(const char *database, const char *key);

json_object *
dbPutHex(const char *database, const char *key, const char *value);

json_object *
dbGetHex(const char *database, const char *key);

#ifdef __cplusplus
}
#endif

#endif /* DB_H_ */