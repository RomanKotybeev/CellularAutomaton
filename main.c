#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#include "ca.h"
#include "viewca.h"
#include "table_fill.h"

void parse_args(int argc, char **argv, struct cellaton *ca)
{
	int opt;

	ca->idx_last_bit = 7;
	/* The default values, if no cmdagrs passed */
	ca->n_gens = 10;
	ca->n_cells = 28;
	ca->rule = 30;
	ca->on = '.';
	ca->off = ' ';

	while ((opt = getopt(argc, argv, "r:n:g:t:f:h")) != -1) {
		switch (opt) {
		case 'r':
			ca->rule = atoi(optarg);
			if (ca->rule < 0 || ca->rule > 256) {
				fprintf(stderr, "Rule must be from 0 to 255\n");
				exit(1);
			}
			break;
		case 'n':
			ca->n_cells = atoi(optarg);
			break;
		case 'g':
			ca->n_gens = atoi(optarg);
			break;
		case 't':
			ca->on = *optarg;
			break;
		case 'f':
			ca->off = *optarg;
			break;
		case 'h':
			fprintf(stderr, "Usage [-r rule] [-t on] [-f off] [-n n_cells] [-g n_gens]\n");
			exit(0);
		case '?':
			if (optopt == 'r' || optopt == 'n' || optopt == 'g')
				fprintf(stderr, "Option -%c requires an argument\n", optopt);
			exit(1);
		default:
			abort();
		}
	}
}

int main(int argc, char **argv)
{
	struct cellaton *ca;
	ca = malloc(sizeof(*ca));

	parse_args(argc, argv, ca);
	fill_rule_table(ca);
	print_info(ca);
	start_ca(ca);

	free(ca);

	return 0;
}
