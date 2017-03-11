#include <stdio.h>
#include <string.h>

#define MAX_ARRAY_SIZE 100 * 1000
#define MAX_VALUE      10  * 1000 * 1000

static int array[MAX_ARRAY_SIZE];
static int count;
static int tallies[MAX_VALUE];

void read_args()
{
	scanf("%d", &count);
	for (int i = 0; i < count; ++i)
		scanf("%d", array + i);
}

int count_all_shifts()
{
	int shifts = 0;
	memset(tallies, 0, MAX_VALUE);

	for (int i = 0; i < count; ++i)
	{
		for (int j = array[i] + 1; j < count; ++j)
			shifts += tallies[j];
		++tallies[array[i]];
	}

	return shifts;
}

int main(void)
{
	int num_tests;
	scanf("%d", &num_tests);
	for (int i = 0; i < num_tests; ++i)
	{
		read_args();
		printf("%d\n", count_all_shifts());
	}
	return 0;
}

