#include "web3.h"
#include "request.h"

/**
 * ****************************************************************************
 *  Web3
 * ****************************************************************************
 */

json_object *
web3ClientVersion()
{
    const char *method = "web3_clientVersion";
    json_object *result = callRPC(method, NULL, 67);
    return result;
}

json_object *
web3Sha3(const char *text)
{
    const char *method = "web3_sha3";
    json_object *params = json_object_new_array();
    json_object_array_add(params, json_object_new_string(text));
    json_object *result = callRPC(method, params, 64);
    return result;
}