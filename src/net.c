#include "net.h"
#include "request.h"

/**
 * ****************************************************************************
 *  Net
 * ****************************************************************************
 */

json_object *
netVersion()
{
    /*************************
    *  "1": Ethereum Mainnet
    *  "2": Morden Testnet (deprecated)
    *  "3": Ropsten Testnet
    *  "4": Rinkeby Testnet
    *  "42": Kovan Testnet
    ************************/
    const char *method = "net_version";
    json_object *result = callRPC(method, NULL, 67);
    return result;
}

json_object *
netListening()
{
    const char *method = "net_listening";
    json_object *result = callRPC(method, NULL, 67);
    return result;
}

json_object *
netPeerCount()
{
    const char *method = "net_peerCount";
    json_object *result = callRPC(method, NULL, 67);
    return result;
}