#include <stdio.h>

static int max_array_size = 100 * 1000;

int count_shifts(int *array, int count, int index_to_check)
{
	int ret = 0;
	for (int i = index_to_check + 1; i < count; ++i)
		if (array[index_to_check] > array[i])
			++ret;
	return ret;
}

int perform_single_test(int *array, int count)
{
	int ret = 0;
	for (int i = 0; i < count - 1; ++i)
		ret += count_shifts(array, count, i);
	return ret;
}

void perform_all_tests(int num_tests)
{
	int array[max_array_size];
	int current_array_size;

	for (int i = 0; i < num_tests; ++i)
	{
		scanf("%d", &current_array_size);

		for (int i = 0; i < current_array_size; ++i)
			scanf("%d", array + i);

		printf("%d\n", perform_single_test(array, current_array_size));
	}
}

int main(void)
{
	int num_tests;
	scanf("%d", &num_tests);
	perform_all_tests(num_tests);
	return 0;
}

