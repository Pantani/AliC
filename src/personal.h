#ifndef PERSONAL_H_
#define PERSONAL_H_

#ifdef __cplusplus
extern "C" {
#endif

#include <json-c/json.h>

json_object *
personalSendTransaction(const char *from, const char *to, const char *gas, const char *gasPrice,
                        const char *value, const char *data, const char *nonce, const char *password);

json_object *
personalSendValue(const char *from, const char *to, const char *value, const char *password);

json_object *
personalSendData(const char *from, const char *data, const char *password);

json_object *
personalSendDataContract(const char *from, const char *contract, const char *data, const char *password);

json_object *
personalUnlockAccount(const char *address, const char *password);

json_object *
personalListAccounts();

#ifdef __cplusplus
}
#endif

#endif /* PERSONAL_H_ */