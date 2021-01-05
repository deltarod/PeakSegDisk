#include <Python.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <stdint.h>
#include <inttypes.h>
#include <string.h>
#include "PeakSegFPOPLog.h"

static PyObject * PeakSegDiskInterface(PyObject *self, PyObject *args)
{
    char *coverageFile, *segmentsFile, *lossFile, *penaltyStr, *db_file;
    if(!PyArg_ParseTuple(args, "sssss", &coverageFile, &segmentsFile, &lossFile, &penaltyStr, &db_file))
    {
        return NULL;
    }
    Py_BEGIN_ALLOW_THREADS
    PeakSegFPOP_disk(coverageFile, segmentsFile, lossFile, penaltyStr, db_file);
    Py_END_ALLOW_THREADS
    return Py_True;
}

static PyMethodDef Methods[] = {
        {"interface", PeakSegDiskInterface, METH_VARARGS,
                        "the interface for PeakSegDisk"},
        {NULL, NULL, 0, NULL}
};

static struct PyModuleDef moduleDef =
        {
        PyModuleDef_HEAD_INIT,
        "PeakSegDiskInterface",
        "A Python extension for PeakSegDisk",
        -1,
        Methods
        };


PyMODINIT_FUNC
PyInit_PeakSegDiskInterface(void)
{
    PyObject *m;
    m = PyModule_Create(&moduleDef);
    if (m == NULL)
        return NULL;

    return m;
}



