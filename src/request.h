#ifndef REQUEST_H_
#define REQUEST_H_

#ifdef __cplusplus
extern "C" {
#endif

#include <json-c/json.h>

json_object *callRPC(const char *method, json_object *params, int id);

#ifdef __cplusplus
}
#endif

#endif /* REQUEST_H_ */