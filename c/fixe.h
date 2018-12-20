#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "arch.h"

#pragma once

typedef struct _fixe_key
{
	char *bts;
	size_t len;
	bool free;
} fixe_key;

fixe_key *fixe_key_from_bts(char *bts, size_t len, bool free);
fixe_key *fixe_key_from_str(char *str);
fixe_key *fixe_key_from_int(int i);
fixe_key *fixe_key_from_lng(long l);

void fixe(fixe_key *key, char *in, char *out, size_t count);

void fixe_free_key(fixe_key *key);
