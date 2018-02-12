#include "db.h"
#include "request.h"

/**
 * ****************************************************************************
 *  Db
 * ****************************************************************************
 */

json_object *
dbPutString(const char *database, const char *key, const char *value)
{
    const char *method = "db_putString";
    json_object *params = json_object_new_array();
    json_object_array_add(params, json_object_new_string(database));
    json_object_array_add(params, json_object_new_string(key));
    json_object_array_add(params, json_object_new_string(value));
    json_object *result = callRPC(method, params, 73);
    return result;
}

json_object *
dbGetString(const char *database, const char *key)
{
    const char *method = "db_getString";
    json_object *params = json_object_new_array();
    json_object_array_add(params, json_object_new_string(database));
    json_object_array_add(params, json_object_new_string(key));
    json_object *result = callRPC(method, params, 73);
    return result;
}

json_object *
dbPutHex(const char *database, const char *key, const char *value)
{
    const char *method = "db_putHex";
    json_object *params = json_object_new_array();
    json_object_array_add(params, json_object_new_string(database));
    json_object_array_add(params, json_object_new_string(key));
    json_object_array_add(params, json_object_new_string(value));
    json_object *result = callRPC(method, params, 73);
    return result;
}

json_object *
dbGetHex(const char *database, const char *key)
{
    const char *method = "db_getHex";
    json_object *params = json_object_new_array();
    json_object_array_add(params, json_object_new_string(database));
    json_object_array_add(params, json_object_new_string(key));
    json_object *result = callRPC(method, params, 73);
    return result;
}