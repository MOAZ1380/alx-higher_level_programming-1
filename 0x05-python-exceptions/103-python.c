#include <Python.h>
#include <float.h>
#include <string.h>

/**
 * print_python_float - function, prints basic info about python float
 * @p: PyObject
 *
 * Return: void
 */
void print_python_float(PyObject *p)
{
	char *s;
	double f;

	printf("[.] float object info\n");
	fflush(stdout);

	if (PyFloat_Check(p))
	{
		f = PyFloat_AsDouble(p);
		s = PyOS_double_to_string(f, 'r', 0, Py_DTSF_ADD_DOT_0, NULL);
		printf("  value: %s\n", s);
		fflush(stdout);
	}
	else
	{
		printf("  [ERROR] Invalid Float Object\n");
		fflush(stdout);
	}
}

/**
 * print_python_bytes - function, prints basic info about python bytes
 * @p: PyObject
 *
 * Return: void
 */
void print_python_bytes(PyObject *p)
{
	int i;
	char *buffer;
	Py_ssize_t len;

	printf("[.] bytes object info\n");
	fflush(stdout);

	if (PyBytes_Check(p))
	{
		len = PyBytes_Size(p);
		buffer = PyBytes_AsString(p);
		printf("  size: %zu\n", len);
		fflush(stdout);
		printf("  trying string: %s\n", buffer);
		fflush(stdout);
		if (len > 9)
			len = 9;
		printf("  first %zu bytes: ", len + 1);
		fflush(stdout);
		for (i = 0; i <= len; i++)
		{
			if (i == len)
			{
				printf("%02x\n", buffer[i] & 0xff);
				fflush(stdout);
			}
			else
			{
				printf("%02x ", buffer[i] & 0xff);
				fflush(stdout);
			}
		}
	}
	else
	{
		printf("  [ERROR] Invalid Bytes Object\n");
		fflush(stdout);
	}
}

/**
 * print_python_list - function, prints some basic info about python list
 * @p: PyObject
 *
 * Return: void
 */
void print_python_list(PyObject *p)
{
	int i;
	PyObject *v;
	PyListObject *list;
	Py_ssize_t len;

	printf("[*] Python list info\n");
	fflush(stdout);

	if (PyList_Check(p))
	{
		list = (PyListObject *)(p);

		len = PyList_Size(p);
		printf("[*] Size of the Python List = %zu\n", len);
		fflush(stdout);
		printf("[*] Allocated = %zu\n", list->allocated);
		fflush(stdout);

		for (i = 0; i < len; i++)
		{
			v = PyList_GET_ITEM(p, i);
			printf("Element %d: %s\n", i, (v->ob_type)->tp_name);
			fflush(stdout);
			if (PyBytes_Check(v))
				print_python_bytes(v);
			else if (PyFloat_Check(v))
				print_python_float(v);
		}
	}
	else
	{
		printf("  [ERROR] Invalid List Object\n");
		fflush(stdout);
	}
}

