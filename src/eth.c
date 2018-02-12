#include "eth.h"
#include "request.h"

/**
 * ****************************************************************************
 *  Eth
 * ****************************************************************************
 */

json_object *
ethProtocolVersion()
{
    const char *method = "eth_protocolVersion";
    json_object *result = callRPC(method, NULL, 67);
    return result;
}

json_object *
ethSyncing()
{
    const char *method = "eth_protocolVersion";
    json_object *result = callRPC(method, NULL, 1);
    return result;
}

json_object *
ethCoinbase()
{
    const char *method = "eth_coinbase";
    json_object *result = callRPC(method, NULL, 64);
    return result;
}

json_object *
ethMining()
{
    const char *method = "eth_mining";
    json_object *result = callRPC(method, NULL, 71);
    return result;
}

json_object *
ethHashrate()
{
    const char *method = "eth_hashrate";
    json_object *result = callRPC(method, NULL, 71);
    return result;
}

json_object *
ethGasPrice()
{
    const char *method = "eth_gasPrice";
    json_object *result = callRPC(method, NULL, 73);
    return result;
}

json_object *
ethAccounts()
{
    const char *method = "eth_accounts";
    json_object *result = callRPC(method, NULL, 1);
    return result;
}

json_object *
ethBlockNumber()
{
    const char *method = "eth_blockNumber";
    json_object *result = callRPC(method, NULL, 83);
    return result;
}

const char *
eth_getBalance(const char *address, char *quantity)
{
    const char *method = "eth_getBalance";
    json_object *params = json_object_new_array();
    json_object_array_add(params, json_object_new_string(address));
    json_object_array_add(params, json_object_new_string(quantity));
    json_object *result = callRPC(method, params, 1);
    
    json_object *obj_result;
    json_object_object_get_ex(result, "result", &obj_result);
    const char *charResult = json_object_get_string(obj_result);

    return charResult;
}

const char *
ethGetBalance(const char *address, QUANTITY_TAG qtyType)
{
    char *quantity;
    switch (qtyType)
    {
    case kQtyEarliest:
        quantity = "earliest";
        break;
    case kQtyPending:
        quantity = "pending";
        break;
    default:
        quantity = "latest";
        break;
    }

    const char *result = eth_getBalance(address, quantity);
    return result;
}

json_object *
eth_getStorageAt(const char *address, char *quantity, int qtyIndex)
{
    const char *method = "eth_getStorageAt";
    json_object *params = json_object_new_array();
    json_object_array_add(params, json_object_new_string(address));
    json_object_array_add(params, json_object_new_string(quantity));
    json_object_array_add(params, json_object_new_int(qtyIndex));
    json_object *result = callRPC(method, params, 1);
    return result;
}

json_object *
ethGetStorageAt(const char *address, QUANTITY_TAG qtyType, int qtyIndex)
{
    char *quantity;
    switch (qtyType)
    {
    case kQtyEarliest:
        quantity = "earliest";
        break;
    case kQtyPending:
        quantity = "pending";
        break;
    default:
        quantity = "latest";
        break;
    }

    json_object *result = eth_getStorageAt(address, quantity, qtyIndex);
    return result;
}

json_object *
eth_getTransactionCount(const char *address, char *quantity)
{
    const char *method = "eth_getTransactionCount";
    json_object *params = json_object_new_array();
    json_object_array_add(params, json_object_new_string(address));
    json_object_array_add(params, json_object_new_string(quantity));
    json_object *result = callRPC(method, params, 1);
    return result;
}

json_object *
ethGetTransactionCount(const char *address, QUANTITY_TAG qtyType)
{
    char *quantity;
    switch (qtyType)
    {
    case kQtyEarliest:
        quantity = "earliest";
        break;
    case kQtyPending:
        quantity = "pending";
        break;
    default:
        quantity = "latest";
        break;
    }

    json_object *result = eth_getTransactionCount(address, quantity);
    return result;
}

json_object *
ethGetBlockTransactionCountByHash(const char *blockHash)
{
    const char *method = "eth_getBlockTransactionCountByHash";
    json_object *params = json_object_new_array();
    json_object_array_add(params, json_object_new_string(blockHash));
    json_object *result = callRPC(method, params, 1);
    return result;
}

json_object *
eth_getBlockTransactionCountByNumber(char *quantity)
{
    const char *method = "eth_getBlockTransactionCountByNumber";
    json_object *params = json_object_new_array();
    json_object_array_add(params, json_object_new_string(quantity));
    json_object *result = callRPC(method, params, 1);
    return result;
}

json_object *
ethGetBlockTransactionCountByNumber(QUANTITY_TAG qtyType)
{
    char *quantity;
    switch (qtyType)
    {
    case kQtyEarliest:
        quantity = "earliest";
        break;
    case kQtyPending:
        quantity = "pending";
        break;
    default:
        quantity = "latest";
        break;
    }

    json_object *result = eth_getBlockTransactionCountByNumber(quantity);
    return result;
}

json_object *
ethGetUncleCountByBlockHash(const char *blockHash)
{
    const char *method = "eth_getUncleCountByBlockHash";
    json_object *params = json_object_new_array();
    json_object_array_add(params, json_object_new_string(blockHash));
    json_object *result = callRPC(method, params, 1);
    return result;
}

json_object *
eth_getUncleCountByBlockNumber(char *quantity)
{
    const char *method = "eth_getUncleCountByBlockNumber";
    json_object *params = json_object_new_array();
    json_object_array_add(params, json_object_new_string(quantity));
    json_object *result = callRPC(method, params, 1);
    return result;
}

json_object *
ethGetUncleCountByBlockNumber(QUANTITY_TAG qtyType)
{
    char *quantity;
    switch (qtyType)
    {
    case kQtyEarliest:
        quantity = "earliest";
        break;
    case kQtyPending:
        quantity = "pending";
        break;
    default:
        quantity = "latest";
        break;
    }

    json_object *result = eth_getUncleCountByBlockNumber(quantity);
    return result;
}

json_object *
eth_getCode(const char *address, char *quantity)
{
    const char *method = "eth_getCode";
    json_object *params = json_object_new_array();
    json_object_array_add(params, json_object_new_string(address));
    json_object_array_add(params, json_object_new_string(quantity));
    json_object *result = callRPC(method, params, 1);
    return result;
}
json_object *
ethGetCode(const char *address, QUANTITY_TAG qtyType)
{
    char *quantity;
    switch (qtyType)
    {
    case kQtyEarliest:
        quantity = "earliest";
        break;
    case kQtyPending:
        quantity = "pending";
        break;
    default:
        quantity = "latest";
        break;
    }

    json_object *result = eth_getCode(address, quantity);
    return result;
}

json_object *
ethSign(const char *address, const char *message)
{
    const char *method = "eth_sign";
    json_object *params = json_object_new_array();
    json_object_array_add(params, json_object_new_string(address));
    json_object_array_add(params, json_object_new_string(message));
    json_object *result = callRPC(method, params, 1);
    return result;
}

json_object *
ethSendTransaction(const char *from, const char *to, const char *gas, const char *gasPrice,
                   const char *value, const char *data)
{
    const char *method = "eth_sendTransaction";
    json_object *params = json_object_new_array();
    json_object *jobj = json_object_new_object();

    //     params: [{
    //   "from": "0xb60e8dd61c5d32be8058bb8eb970870f07233155",
    //   "to": "0xd46e8dd67c5d32be8058bb8eb970870f07244567",
    //   "gas": "0x76c0", // 30400
    //   "gasPrice": "0x9184e72a000", // 10000000000000
    //   "value": "0x9184e72a", // 2441406250
    //   "data": "0xd46e8dd67c5d32be8d46e8dd67c5d32be8058bb8eb970870f072445675058bb8eb970870f072445675"
    // }]

    json_object *jsFrom = json_object_new_string(from);
    json_object *jsTo = json_object_new_string(to);
    json_object *jsGas = json_object_new_string(gas);
    json_object *jsGasPrice = json_object_new_string(gasPrice);
    json_object *jsValue = json_object_new_string(value);
    json_object *jsData = json_object_new_string(data);

    json_object_object_add(jobj, "from", jsFrom);
    json_object_object_add(jobj, "to", jsTo);
    json_object_object_add(jobj, "gas", jsGas);
    json_object_object_add(jobj, "gasPrice", jsGasPrice);
    json_object_object_add(jobj, "value", jsValue);
    json_object_object_add(jobj, "data", jsData);

    json_object_array_add(params, jobj);
    json_object *result = callRPC(method, params, 1);
    return result;
}

// params: ["0xd46e8dd67c5d32be8d46e8dd67c5d32be8058bb8eb970870f072445675058bb8eb970870f072445675"]
//curl -X POST --data '{"jsonrpc":"2.0","method":"eth_sendRawTransaction","params":[{see above}],"id":1}'

json_object *
eth_call(const char *from, const char *to, const char *gas, const char *gasPrice,
         const char *value, const char *data, const char *quantity)
{
    const char *method = "eth_call";
    json_object *params = json_object_new_array();
    json_object *jobj = json_object_new_object();

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

    json_object_array_add(params, jobj);
    json_object_array_add(params, json_object_new_string(quantity));
    json_object *result = callRPC(method, params, 1);
    return result;
}

json_object *
ethCall(const char *from, const char *to, const char *gas, const char *gasPrice,
        const char *value, const char *data, QUANTITY_TAG qtyType)
{
    char *quantity;
    switch (qtyType)
    {
    case kQtyEarliest:
        quantity = "earliest";
        break;
    case kQtyPending:
        quantity = "pending";
        break;
    default:
        quantity = "latest";
        break;
    }

    json_object *result = eth_call(from, to, gas, gasPrice, value, data, quantity);
    return result;
}

const char *
getContractData(const char *from, const char *contract, const char *data)
{
    json_object *result = ethCall(from, contract, NULL, NULL, NULL, data, kQtyLatest);
    json_object *obj_result;
    json_object_object_get_ex(result, "result", &obj_result);
    const char *charResult = json_object_get_string(obj_result);
    return charResult;
}

json_object *
ethEstimateDataGas(const char *from, const char *data)
{
    const char *method = "eth_estimateGas";
    json_object *params = json_object_new_array();
    json_object *jobj = json_object_new_object();

    json_object *jsFrom = json_object_new_string(from);
    json_object *jsData = json_object_new_string(data);

    json_object_object_add(jobj, "form", jsFrom);
    json_object_object_add(jobj, "data", jsData);
    json_object_array_add(params, jobj);
    json_object *result = callRPC(method, params, 1);
    return result;
}

json_object *
ethEstimateTransferGas(const char *from, double value)
{
    const char *method = "eth_estimateGas";
    json_object *params = json_object_new_array();
    json_object *jobj = json_object_new_object();

    json_object *jsFrom = json_object_new_string(from);
    json_object *jsValue = json_object_new_double(value);

    json_object_object_add(jobj, "form", jsFrom);
    json_object_object_add(jobj, "value", jsValue);
    json_object_array_add(params, jobj);
    json_object *response = callRPC(method, params, 1);
    return response;
}

json_object *
ethGetBlockByHash(const char *address, const char *fullTransaction)
{
    const char *method = "eth_getBlockByHash";
    json_object *params = json_object_new_array();
    json_object_array_add(params, json_object_new_string(address));
    //boolean
    json_object_array_add(params, json_object_new_string(fullTransaction));
    json_object *response = callRPC(method, params, 1);
    return response;
}

// QUANTITY|TAG - integer of a block number, or the string "earliest", "latest" or "pending", as in the default block parameter.
// Boolean - If true it returns the full transaction objects, if false only the hashes of the transactions.
// curl -X POST --data '{"jsonrpc":"2.0","method":"eth_getBlockByNumber","params":["0x1b4", true],"id":1}'

// DATA, 32 Bytes - hash of a transaction
// curl -X POST --data '{"jsonrpc":"2.0","method":"eth_getTransactionByHash","params":["0xb903239f8543d04b5dc1ba6579132b143087c68db1b2168786408fcbce568238"],"id":1}'

// DATA, 32 Bytes - hash of a block.
// QUANTITY - integer of the transaction index position.
// curl -X POST --data '{"jsonrpc":"2.0","method":"eth_getTransactionByBlockHashAndIndex","params":[0xc6ef2fc5426d6ad6fd9e2a26abeab0aa2411b7ab17f30a99d3cb96aed1d1055b, "0x0"],"id":1}'

// QUANTITY|TAG - a block number, or the string "earliest", "latest" or "pending", as in the default block parameter.
// QUANTITY - the transaction index position.
// curl -X POST --data '{"jsonrpc":"2.0","method":"eth_getTransactionByBlockNumberAndIndex","params":["0x29c", "0x0"],"id":1}'

json_object *
ethGetTransactionReceipt(const char *address)
{
    const char *method = "eth_getTransactionReceipt";
    json_object *params = json_object_new_array();
    json_object_array_add(params, json_object_new_string(address));
    json_object *response = callRPC(method, params, 1);
    return response;
}

// DATA, 32 Bytes - hash a block.
// QUANTITY - the uncle's index position.
// curl -X POST --data '{"jsonrpc":"2.0","method":"eth_getUncleByBlockHashAndIndex","params":["0xc6ef2fc5426d6ad6fd9e2a26abeab0aa2411b7ab17f30a99d3cb96aed1d1055b", "0x0"],"id":1}'

// QUANTITY|TAG - a block number, or the string "earliest", "latest" or "pending", as in the default block parameter.
// QUANTITY - the uncle's index position.
// curl -X POST --data '{"jsonrpc":"2.0","method":"eth_getUncleByBlockNumberAndIndex","params":["0x29c", "0x0"],"id":1}'

json_object *
ethGetCompilers()
{
    const char *method = "eth_getCompilers";
    json_object *params = json_object_new_array();
    json_object *response = callRPC(method, params, 1);
    return response;
}

json_object *
ethCompileSolidity(const char *code)
{
    const char *method = "eth_compileSolidity";
    json_object *params = json_object_new_array();
    json_object_array_add(params, json_object_new_string(code));
    json_object *response = callRPC(method, params, 1);
    return response;
}

json_object *
ethCompileLLL(const char *code)
{
    const char *method = "eth_compileLLL";
    json_object *params = json_object_new_array();
    json_object_array_add(params, json_object_new_string(code));
    json_object *response = callRPC(method, params, 1);
    return response;
}

json_object *
ethCompileSerpent(const char *code)
{
    const char *method = "eth_compileSerpent";
    json_object *params = json_object_new_array();
    json_object_array_add(params, json_object_new_string(code));
    json_object *response = callRPC(method, params, 1);
    return response;
}

// fromBlock: QUANTITY|TAG - (optional, default: "latest") Integer block number, or "latest" for the last mined block or "pending", "earliest" for not yet mined transactions.
// toBlock: QUANTITY|TAG - (optional, default: "latest") Integer block number, or "latest" for the last mined block or "pending", "earliest" for not yet mined transactions.
// address: DATA|Array, 20 Bytes - (optional) Contract address or a list of addresses from which logs should originate.
// topics: Array of DATA, - (optional) Array of 32 Bytes DATA topics. Topics are order-dependent. Each topic can also be an array of DATA with "or" options.
// curl -X POST --data '{"jsonrpc":"2.0","method":"eth_newFilter","params":[{"topics":["0x12341234"]}],"id":73}'

json_object *
ethNewBlockFilter()
{
    const char *method = "eth_newBlockFilter";
    json_object *params = json_object_new_array();
    json_object *response = callRPC(method, params, 73);
    return response;
}

json_object *
ethNewPendingTransactionFilter()
{
    const char *method = "eth_newPendingTransactionFilter";
    json_object *params = json_object_new_array();
    json_object *response = callRPC(method, params, 73);
    return response;
}

//QUANTITY - The filter id.
// curl -X POST --data '{"jsonrpc":"2.0","method":"eth_uninstallFilter","params":["0xb"],"id":73}'

// QUANTITY - the filter id.
// curl -X POST --data '{"jsonrpc":"2.0","method":"eth_getFilterChanges","params":["0x16"],"id":73}'

// QUANTITY - The filter id.
// curl -X POST --data '{"jsonrpc":"2.0","method":"eth_getFilterLogs","params":["0x16"],"id":74}'

// Object - the filter object, see eth_newFilter parameters.
// curl -X POST --data '{"jsonrpc":"2.0","method":"eth_getLogs","params":[{"topics":["0x000000000000000000000000a94f5374fce5edbc8e2a8697c15331677e6ebf0b"]}],"id":74}'

json_object *
ethGetWork()
{
    const char *method = "eth_getWork";
    json_object *params = json_object_new_array();
    json_object *response = callRPC(method, params, 73);
    return response;
}

// DATA, 8 Bytes - The nonce found (64 bits)
// DATA, 32 Bytes - The headers pow-hash (256 bits)
// DATA, 32 Bytes - The mix digest (256 bits)
// curl -X POST --data '{"jsonrpc":"2.0", "method":"eth_submitWork", "params":["0x0000000000000001", "0x1234567890abcdef1234567890abcdef1234567890abcdef1234567890abcdef", "0xD1GE5700000000000000000000000000D1GE5700000000000000000000000000"],"id":73}'

// Hashrate, a hexadecimal string representation (32 bytes) of the hash rate
// ID, String - A random hexadecimal(32 bytes) ID identifying the client
// curl -X POST --data '{"jsonrpc":"2.0", "method":"eth_submitHashrate", "params":["0x0000000000000000000000000000000000000000000000000000000000500000", "0x59daa26581d0acd1fce254fb7e85952f4c09d0915afd33d3886cd914bc7d283c"],"id":73}'