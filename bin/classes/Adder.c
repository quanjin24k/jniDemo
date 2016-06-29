#include "Adder.h"

struct Adder *AdderNew()
{
	struct Adder *t = malloc(sizeof(Adder));
	t->exec = my_exec;
	return (void *)t;
}

int my_exec(int a, int b)
{
	return (a + b);
}
