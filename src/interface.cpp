#include "PeakSegFPOPLog.h"
#include <Python.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <stdint.h>
#include <inttypes.h>
#include <string.h>

static PyObject * PeakSegDiskInterface(PyObject *self, PyObject *args)
{
    char *coverageFile, *segmentsFile, *lossFile, *penaltyStr, *db_file;
    if(!PyArg_ParseTuple(args, "sssss", &coverageFile, &segmentsFile, &lossFile, &penaltyStr, &db_file))
    {
        return NULL;
    }

    int status = PeakSegFPOP_disk(coverageFile, segmentsFile, lossFile, penaltyStr, db_file);

    if(status==ERROR_PENALTY_NOT_FINITE)
    {
        PyErr_SetString(PyExc_ValueError, "penalty must be finite");
    }
    if(status==ERROR_PENALTY_NEGATIVE)
    {
        PyErr_SetString(PyExc_ValueError, "penalty must be non-negative");
    }
    if(status==ERROR_UNABLE_TO_OPEN_BEDGRAPH)
    {
        PyErr_SetString(PyExc_ValueError, "unable to open input file for reading");
    }
    if(status==ERROR_NOT_ENOUGH_COLUMNS)
    {
        PyErr_SetString(PyExc_ValueError, "each line of input data file should have exactly four columns");
    }
    if(status==ERROR_NON_INTEGER_DATA)
    {
        PyErr_SetString(PyExc_ValueError, "fourth column of input data file should be integer");
    }
    if(status==ERROR_INCONSISTENT_CHROMSTART_CHROMEND)
    {
        PyErr_SetString(PyExc_ValueError, "there should be no gaps (columns 2-3) in input data file");
    }
    if(status==ERROR_WRITING_COST_FUNCTIONS)
    {
    PyErr_SetString(PyExc_ValueError, "unable to write to cost function database file");
    }
    if(status==ERROR_WRITING_LOSS_OUTPUT)
    {
    PyErr_SetString(PyExc_ValueError, "unable to write to loss output file");
    }
    if(status==ERROR_WRITING_SEGMENTS_OUTPUT)
    {
    PyErr_SetString(PyExc_ValueError, "unable to write to segments output file");
    }
    if(status==ERROR_NO_DATA)
    {
        PyErr_SetString(PyExc_ValueError, "input file contains no data");
    }
    if(status==ERROR_PENALTY_NOT_NUMERIC)
    {
        PyErr_SetString(PyExc_ValueError, "penalty string is not numeric; it should be convertible to double");
    }
    if(status != 0)
    {
        PyErr_SetString(PyExc_ValueError, "error");
        return Py_False;
    }
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



