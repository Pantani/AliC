#include "util.h"
#include "request.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <string.h>

/**
 * ****************************************************************************
 *  Util
 * ****************************************************************************
 */

int hex2Number(char *content)
{
    int number = (int)strtol(content, NULL, 0);
    return number;
}

void
char2Hex(char *content, char *result)
{
    int i, len;
    len = strlen(content);
    for (i = 0; i < len; i++)
    {
        sprintf(result, "%x", content[i]);
    }
}

