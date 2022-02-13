#include <stdlib.h>
#include <stdio.h>

#include "ca.h"
#include "viewca.h"
#include "table_fill.h"

static void copy_cells(struct cellaton *ca)
{
	int i;
	for (i = 0; i < ca->n_cells; i++)
		ca->initgen[i] = ca->nextgen[i];
}

static void generate(struct cellaton *ca)
{
	int prev_idx, curr_idx, next_idx;
	int prev_cell, curr_cell, next_cell;
	int cell;

	for (curr_idx = 0; curr_idx < ca->n_cells; curr_idx++) {
		prev_idx = curr_idx - 1;
		next_idx = curr_idx + 1;
		if (curr_idx == 0)
			prev_idx = ca->n_cells - 1;
		if (curr_idx == ca->n_cells)
			next_idx = 0;

		prev_cell = ca->initgen[prev_idx];
		curr_cell = ca->initgen[curr_idx];
		next_cell = ca->initgen[next_idx];

		print_cell(curr_cell, ca);

		cell = ca->rule_table[prev_cell][curr_cell][next_cell];
		ca->nextgen[curr_idx] = cell;
	}
	putchar('\n');

	copy_cells(ca);
}

static void init_first_gen(struct cellaton *ca)
{
	int i;
	for (i = 0; i < ca->n_cells; i++) {
		if (i != ca->n_cells / 2)
			ca->initgen[i] = 0;
		else
			ca->initgen[i] = 1;
	}
}

void start_ca(struct cellaton *ca)
{
	int i;

	ca->initgen = malloc(ca->n_cells * sizeof(char));
	ca->nextgen = malloc(ca->n_cells * sizeof(char));

	init_first_gen(ca);

	for (i = 0; i < ca->n_gens; i++)
		generate(ca);

	free(ca->initgen);
	free(ca->nextgen);
}
