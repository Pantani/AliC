#include "personal.h"
#include "request.h"

/**
 * ****************************************************************************
 *  Personal
 * ****************************************************************************
 */

json_object *
personalSendTransaction(const char *from, const char *to, const char *gas, const char *gasPrice,
                        const char *value, const char *data, const char *nonce, const char *password)
{
    const char *method = "personal_sendTransaction";
    json_object *params = json_object_new_array();
    json_object *jobj = json_object_new_object();

    // params: [
    //   {
    // "from": "0x407d73d8a49eeb85d32cf465507dd71d507100c1",
    // "to": "0xa94f5374fce5edbc8e2a8697c15331677e6ebf0b",
    // "data": "0x41cd5add4fd13aedd64521e363ea279923575ff39718065d38bd46f0e6632e8e",
    // "value": "0x186a0"
    //   },
    //   "hunter2"
    // ]

    json_object *jsFrom = json_object_new_string(from);
    json_object_object_add(jobj, "from", jsFrom);
    if (to != NULL)
    {
        json_object *jsTo = json_object_new_string(to);
        json_object_object_add(jobj, "to", jsTo);
    }
    if (gas != NULL)
    {
        json_object *jsGas = json_object_new_string(gas);
        json_object_object_add(jobj, "gas", jsGas);
    }
    if (gasPrice != NULL)
    {
        json_object *jsGasPrice = json_object_new_string(gasPrice);
        json_object_object_add(jobj, "gasPrice", jsGasPrice);
    }
    if (value != NULL)
    {
        json_object *jsValue = json_object_new_string(value);
        json_object_object_add(jobj, "value", jsValue);
    }
    if (data != NULL)
    {
        json_object *jsData = json_object_new_string(data);
        json_object_object_add(jobj, "data", jsData);
    }
    if (nonce != NULL)
    {
        json_object *jsNonce = json_object_new_string(nonce);
        json_object_object_add(jobj, "nonce", jsNonce);
    }

    json_object_array_add(params, jobj);
    json_object_array_add(params, json_object_new_string(password));
    json_object *result = callRPC(method, params, 1);
    return result;
}

json_object *
personalSendValue(const char *from, const char *to, const char *value, const char *password)
{
    json_object *result = personalSendTransaction(from, to, NULL, NULL, value, NULL, NULL, password);
    return result;
}

json_object *
personalSendData(const char *from, const char *data, const char *password)
{
    json_object *result = personalSendTransaction(from, NULL, NULL, NULL, NULL, NULL, NULL, password);
    return result;
}

json_object *
personalSendDataContract(const char *from, const char *contract, const char *data, const char *password)
{
    json_object *result = personalSendTransaction(from, contract, NULL, NULL, NULL, data, NULL, password);
    return result;
}

json_object *
personalUnlockAccount(const char *address, const char *password)
{
    const char *method = "personal_unlockAccount";
    json_object *params = json_object_new_array();
    json_object_array_add(params, json_object_new_string(address));
    json_object_array_add(params, json_object_new_string(password));
    json_object *result = callRPC(method, params, 1);
    return result;
}

json_object *
personalListAccounts()
{
    const char *method = "personal_listAccounts";
    json_object *params = json_object_new_object();
    json_object *result = callRPC(method, params, 1);
    return result;
}