#ifndef REGEX_H
#define REGEX_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int regex_match(char const *str, char const *pattern);
int wildcmp(char const *str, char const *pattern);

#endif