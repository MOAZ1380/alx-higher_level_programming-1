#include "Python.h"

/**
 * print_python_string - Prints information about Python strings.
 * @p: A PyObject string object.
 *
 * Return: void
 */
void print_python_string(PyObject *p)
{
	long int size;

	printf("[.] string object info\n");

	if (PyUnicode_Check(p))
	{
		size = ((PyASCIIObject *)(p))->length;

		if (PyUnicode_IS_COMPACT_ASCII(p))
			printf("  type: compact ascii\n");
		else
			printf("  type: compact unicode object\n");
		printf("  length: %ld\n", size);
		printf("  value: %ls\n", PyUnicode_AsWideCharString(p, &size));
	}
	else
	{
		printf("  ERROR] Invalid String Object\n");
	}
}

