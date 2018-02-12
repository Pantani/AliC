#ifndef UTIL_H_
#define UTIL_H_

#ifdef __cplusplus
extern "C" {
#endif

int 
hex2Number(char *content);

// char *
// char2Hex(char *content);

void
char2Hex(char *content, char *result);

#ifdef __cplusplus
}
#endif

#endif /* UTIL_H_ */