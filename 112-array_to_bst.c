#include "binary_trees.h"

/**
 * array_to_bst - builds a Binary Search Tree from an array
 * @array: pointer to the first element in the array
 * @size: number of elements in the array
 * Return: pointer to the root node of the created bst or null
 */

bst_t *array_to_bst(int *array, size_t size)
{
	int *created_nodes = malloc(sizeof(int) * size);
	int i = 0, j;
	bst_t *root = NULL;
	int csize = 0, pass = 0;

	if (array == NULL)
		return (NULL);

	while (i < (int)size)
	{
		j = 0;
		while (j < csize)
		{
			if (created_nodes[j] == array[i])
			{
				pass = 1;
				break;
			}
			j++;
		}
		if (pass == 1)
		{
			created_nodes[i] = -999;
			pass = 0;
			csize++;
			++i;
			continue;
		}
		if (i == 0)
			root = bst_insert(&root, array[i]);
		else
			bst_insert(&root, array[i]);
		created_nodes[i] = array[i];
		csize++;
		i++;
	}
	return (root);
}
