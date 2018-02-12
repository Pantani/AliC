#ifndef NET_H_
#define NET_H_

#ifdef __cplusplus
extern "C" {
#endif

#include <json-c/json.h>

json_object *
netVersion();

json_object *
netListening();

json_object *
netPeerCount();

#ifdef __cplusplus
}
#endif

#endif /* NET_H_ */