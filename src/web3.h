#ifndef WEB3_H_
#define WEB3_H_

#ifdef __cplusplus
extern "C" {
#endif

#include <json-c/json.h>

json_object *
web3ClientVersion();

json_object *
web3Sha3(const char *text);

#ifdef __cplusplus
}
#endif

#endif /* WEB3_H_ */
