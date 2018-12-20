#include "fixe.h"

fixe_key *fixe_key_from_bts(char *bts, size_t len, bool free)
{
	fixe_key *key = malloc(sizeof(fixe_key));
	key->bts = bts;
	key->len = len;
	key->free = free;
	return key;
}

fixe_key *fixe_key_from_str(char *str)
{
	return fixe_key_from_bts(str, strlen(str), false);
}

fixe_key *fixe_key_from_int(int i)
{
	int *j = malloc(sizeof(int));
	*j = i;
	return fixe_key_from_bts(j, sizeof(int), true);
}

fixe_key *fixe_key_from_lng(long l)
{
	long *m = malloc(sizeof(long));
	*m = l;
	return fixe_key_from_bts(m, sizeof(long), true);
}

void fixe(fixe_key *key, char *in, char *out, size_t count)
{
	char *k = key->bts;
	size_t m = key->len;
	if(X64 && m % sizeof(long) == 0 && count % sizeof(long) == 0)
	{
		long *o = out;
		long *i = in;
		long *_k = k;
		m /= sizeof(long);
		count /= sizeof(long);
		for(size_t j = 0; j < count; j++)
		{
			o[j] = i[j] ^ _k[j % m];
		}
	}
	else if(X86 && m % sizeof(int) == 0 && count % sizeof(int) == 0)
	{
		int *o = out;
		int *i = in;
		int *_k = k;
		m /= sizeof(int);
		count /= sizeof(int);
		for(size_t j = 0; j < count; j++)
		{
			o[j] = i[j] ^ _k[j % m];
		}
	}
	else
	{
		for(size_t i = 0; i < count; i++)
		{
			out[i] = in[i] ^ k[i % m];
		}
	}
}

void fixe_free_key(fixe_key *key)
{
	if(key->free)
	{
		free(key->bts);
	}
	free(key);
}
