#include "ca.h"
#include "table_fill.h"

static void fill_with_zeros_until_k(struct cellaton *ca, int count)
{
	int i;
	for (i = 0; i < count; i++) {
		ca->bin_rule[i] = 0;
	}
}

/* The algorithm of converting the rule number to a binary form. */ 
static void rule_to_bin(struct cellaton *ca)
{
	int idx = ca->idx_last_bit;
	int n = ca->rule;

	while (n) {
		if (n % 2 == 0)
			ca->bin_rule[idx] = 0;
		else
			ca->bin_rule[idx] = 1;

		idx--;
		n = n / 2;
	}
	fill_with_zeros_until_k(ca, idx);
}

void fill_rule_table(struct cellaton *ca)
{
	int i, j, k;
	int count = ca->idx_last_bit;

	rule_to_bin(ca);

	for (i = 0; i < 2; i++) {
		for (j = 0; j < 2; j++) {
			for (k = 0; k < 2; k++) {
				ca->rule_table[i][j][k] = ca->bin_rule[count];
				count--;
			}
		}
	}
}
