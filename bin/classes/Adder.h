#ifndef ADDER_H
#define ADDER_H

struct Adder {
	int (* exec)(int a, int b);
};

typedef struct Adder Adder;

struct Adder *AdderNew();
int my_exec(int a, int b);

#endif /* ADDER_H */
