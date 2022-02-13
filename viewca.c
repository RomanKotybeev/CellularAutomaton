#include <stdio.h>

#include "viewca.h"
#include "ca.h"

static void print_bin_number(const int *bin_number)
{
	int i;
	int n_bits = 8;
	for (i = 0; i < n_bits; i++)
		printf("%d", bin_number[i]);
	putchar('\n');
}

void print_cell(int cell, struct cellaton *ca)
{
	if (cell)
		putchar(ca->on);
	else
		putchar(ca->off);
}

void print_info(struct cellaton *ca)
{
	printf("----------------------------\n");
	printf("Rule:                    %03d\n", ca->rule);
	printf("Binary rule:        ");
	print_bin_number(ca->bin_rule);
	printf("Number of gens:          %03d\n", ca->n_gens);
	printf("Number of cells:         %03d\n", ca->n_cells);
	printf("----------------------------\n");
	putchar('\n');
}
