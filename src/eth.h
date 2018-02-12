#ifndef WEB3_H_
#define WEB3_H_

#ifdef __cplusplus
extern "C" {
#endif

#include <json-c/json.h>

typedef enum {
    kQtyLatest = 1,
    kQtyEarliest = 2,
    kQtyPending = 3
} QUANTITY_TAG;


json_object *
ethProtocolVersion();

json_object *
ethSyncing();

json_object *
ethCoinbase();

json_object *
ethMining();

json_object *
ethHashrate();

json_object *
ethGasPrice();

json_object *
ethAccounts();

json_object *
ethBlockNumber();

const char *
ethGetBalance(const char *address, QUANTITY_TAG qtyType);

json_object *
ethGetStorageAt(const char *address, QUANTITY_TAG qtyType, int qtyIndex);

json_object *
ethGetTransactionCount(const char *address, QUANTITY_TAG qtyType);

json_object *
ethGetBlockTransactionCountByHash(const char *blockHash);

json_object *
ethGetBlockTransactionCountByNumber(QUANTITY_TAG qtyType);

json_object *
ethGetUncleCountByBlockHash(const char *blockHash);

json_object *
ethGetUncleCountByBlockNumber(QUANTITY_TAG qtyType);

json_object *
ethGetCode(const char *address, QUANTITY_TAG qtyType);

json_object *
ethSign(const char *address, const char *message);

json_object *
ethSendTransaction(const char *from, const char *to, const char *gas, const char *gasPrice,
                   const char *value, const char *data);

// params: ["0xd46e8dd67c5d32be8d46e8dd67c5d32be8058bb8eb970870f072445675058bb8eb970870f072445675"]
//curl -X POST --data '{"jsonrpc":"2.0","method":"eth_sendRawTransaction","params":[{see above}],"id":1}'

json_object *
ethCall(const char *from, const char *to, const char *gas, const char *gasPrice,
        const char *value, const char *data, QUANTITY_TAG qtyType);

const char *
getContractData(const char *from, const char *contract, const char *data);

json_object *
ethEstimateDataGas(const char *from, const char *data);

json_object *
ethEstimateTransferGas(const char *from, double value);
json_object *
ethGetBlockByHash(const char *address, const char *fullTransaction);

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
ethGetTransactionReceipt(const char *address);

// DATA, 32 Bytes - hash a block.
// QUANTITY - the uncle's index position.
// curl -X POST --data '{"jsonrpc":"2.0","method":"eth_getUncleByBlockHashAndIndex","params":["0xc6ef2fc5426d6ad6fd9e2a26abeab0aa2411b7ab17f30a99d3cb96aed1d1055b", "0x0"],"id":1}'

// QUANTITY|TAG - a block number, or the string "earliest", "latest" or "pending", as in the default block parameter.
// QUANTITY - the uncle's index position.
// curl -X POST --data '{"jsonrpc":"2.0","method":"eth_getUncleByBlockNumberAndIndex","params":["0x29c", "0x0"],"id":1}'

json_object *
ethGetCompilers();

json_object *
ethCompileSolidity(const char *code);

json_object *
ethCompileLLL(const char *code);

json_object *
ethCompileSerpent(const char *code);

json_object *
ethNewBlockFilter();

json_object *
ethNewPendingTransactionFilter();

json_object *
ethGetWork();

#ifdef __cplusplus
}
#endif

#endif /* WEB3_H_ */
