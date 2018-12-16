#include "fixe.h"

int main()
{
	fixe_key *key = fixe_key_from_str("FIXE IS AWESOME!");
	char *secret = "this text is secret, so please stop reading!";
	char encrypted[strlen(secret) + 1];
	fixe(key, secret, encrypted, strlen(secret));
	fixe_free_key(key);
	for(size_t i = 0; i < strlen(secret); i++)
	{
		printf("%02x", encrypted[i]);
	}
	putchar('\n');
	return 0;
}
