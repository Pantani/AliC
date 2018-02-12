#include "shh.h"
#include "request.h"

/**
 * ****************************************************************************
 *  Shh
 * ****************************************************************************
 */

json_object *
shhVersion()
{
    const char *method = "shh_version";
    json_object *params = json_object_new_array();
    json_object *result = callRPC(method, params, 67);
    return result;
}

json_object *
shhPost(const char *from, const char *to, const char *topics,
        const char *payload, const char *priority, const char *ttl)
{
    const char *method = "shh_post";
    json_object *params = json_object_new_array();
    json_object *jobj = json_object_new_object();

    json_object *jsFrom = json_object_new_string(from);
    json_object_object_add(jobj, "from", jsFrom);

    json_object *jsTo = json_object_new_string(to);
    json_object_object_add(jobj, "to", jsTo);

    json_object *jsTopics = json_object_new_string(topics);
    json_object_object_add(jobj, "topics", jsTopics);

    json_object *jsPayload = json_object_new_string(to);
    json_object_object_add(jobj, "payload", jsPayload);

    json_object *jsPriority = json_object_new_string(priority);
    json_object_object_add(jobj, "priority", jsPriority);

    json_object *jsTtl = json_object_new_string(ttl);
    json_object_object_add(jobj, "ttl", jsTtl);

    json_object_array_add(params, jobj);
    json_object *result = callRPC(method, params, 73);
    return result;
}

json_object *
shhNewIdentity()
{
    const char *method = "shh_newIdentity";
    json_object *params = json_object_new_array();
    json_object *result = callRPC(method, params, 73);
    return result;
}

json_object *
shhHasIdentity(const char *address)
{
    const char *method = "shh_hasIdentity";
    json_object *params = json_object_new_array();
    json_object_array_add(params, json_object_new_string(address));
    json_object *result = callRPC(method, params, 73);
    return result;
}

json_object *
shhNewFilter(const char *topics, const char *to)
{
    const char *method = "shh_newFilter";
    json_object *params = json_object_new_array();
    json_object *jobj = json_object_new_object();

    json_object *jsTopics = json_object_new_string(topics);
    json_object_object_add(jobj, "topics", jsTopics);

    json_object *jsTo = json_object_new_string(to);
    json_object_object_add(jobj, "to", jsTo);

    json_object_array_add(params, jobj);
    json_object *result = callRPC(method, params, 73);
    return result;
}

json_object *
shhUninstallFilter(const char *filterId)
{
    const char *method = "shh_uninstallFilter";
    json_object *params = json_object_new_array();
    json_object_array_add(params, json_object_new_string(filterId));
    json_object *result = callRPC(method, params, 73);
    return result;
}

json_object *
shhGetFilterChanges(const char *filterId)
{
    const char *method = "shh_getFilterChanges";
    json_object *params = json_object_new_array();
    json_object_array_add(params, json_object_new_string(filterId));
    json_object *result = callRPC(method, params, 73);
    return result;
}

json_object *
shhGetMessages(const char *filterId)
{
    const char *method = "shh_getMessages";
    json_object *params = json_object_new_array();
    json_object_array_add(params, json_object_new_string(filterId));
    json_object *result = callRPC(method, params, 73);
    return result;
}
