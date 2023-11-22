#include <Python.h>
#include <stdio.h>
/*
 * print_python_float - gives data of the PyFloatOBJECT
 * @p: the PyObject
 */
void print_python_float(PyObject *p);
{
	double value = 0;
	char *string = NULL;

	fflush(stdout);
	printf("[.] float object info\n");

	if (!PyFloat_CheckExact(p))
	{
		printf(" [ERROR] Invalid Float Object\n");
		return;
	}
	value = ((PyFloatObject *)p)->ob_fval;
	string = PyOS_double_to_string(value, 'r', 0, Py_DTSF_ADD_DOT_O, NULL);
	printf(" value: %s\n", string);
}
/**
 * print_python_bytes - Prints data of the PyBytesObject
 * @p: A PyObject
 */
void print_python_bytes(PyObject *p)
{
        Py_ssize_t size = 0, i = 0;
        char *string = NULL;
	
	fflush(stdout);
	printf("[.] bytes object info\n");
	if (!PyBytes_CheckExact(p))
        {
                printf("  [ERROR] Invalid Bytes Object\n");
                return;
        }
	size = PyBytes_Size(p);
	printf(" size: %zd\n", size);
	string = (assert(PyBytes_Check(p)), (((PyBytesObject *)(p))->ob_sval));
	printf(" trying string: %s\n", string);
	printf(" first %zd bytes:", size < 10 ? size + 1 : 10);

        for (i = 0; i < size; i++)
        {
                type = list->ob_item[i]->ob_type->tp_name;
                printf("Element %ld: %s\n", i, type);
                if (strcmp(type, "bytes") == 0)
                        print_python_bytes(list->ob_item[i]);
                else if (strcmp(type, "float") == 0)
                        print_python_float(list->ob_item[i]);
        }
}
