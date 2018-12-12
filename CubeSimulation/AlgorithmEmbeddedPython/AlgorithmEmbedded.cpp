#include "AlgorithmEmbedded.h"


std::string call_python_solver(std::string cubestring, int max_length, int timeout, bool first_run, bool final_run)
{
	std::string solution;
	//Run Algorithm using Python API
	PyObject *pName, *pModule, *pDict, *pFunc;

	//setenv("PYTHONDONTWRITEBYTECODE", " ", 1);

	// Initialize the Python Interpreter
	Py_Initialize();
	//PyRun_SimpleString("import os"); 
	//PyRun_SimpleString("print(os.getcwd())");

	//CALL FUNCTION FROM FOLDER 1:
	PyObject *sys = PyImport_ImportModule("sys");
	PyObject *path = PyObject_GetAttrString(sys, "path");
	PyList_Append(path, PyUnicode_FromString("\AlgorithmEmbeddedPython"));

	// Build the name object
	pName = PyUnicode_FromString((char*)"solver");
	// Load the module object
	pModule = PyImport_Import(pName);
	// pDict is a borrowed reference
	pDict = PyModule_GetDict(pModule);
	// pFunc is also a borrowed reference
	pFunc = PyDict_GetItemString(pDict, (char*)"solve");




	if (pFunc != NULL)
	{
		if (PyCallable_Check(pFunc))
		{
			PyObject *pResult = PyObject_CallFunction(pFunc, "s",cubestring.c_str(), "i", max_length,"i", timeout);
			
			solution = PyUnicode_AsUTF8(pResult);
			
			Py_DECREF(pResult);
		}
		else { PyErr_Print(); }
	}
	else { std::cout << "pFunc is NULL!" << std::endl; }

	// Clean up
	
	Py_DECREF(pFunc);
	Py_DECREF(pDict);
	Py_DECREF(pModule);
	Py_DECREF(pName);

	// Finish the Python Interpreter
	if (final_run == 1)
	{
		Py_Finalize();
	}
	
	return solution;
}
/*
void main()
{
	
	std::string cubestring = "DUUBULDBFRBFRRULLLBRDFFFBLURDBFDFDRFRULBLUFDURRBLBDUDL"; //Scrambled Cube in string format 
	cubestring = "DLRRUUDFDBBBDRBLLBRRLFFBRFDFUFDDULULFDBBLDFLUUFRLBRURU"; //Scrambled Cube in string format 

	int max_length = 20; //Maximum of moves of solution 
	int timeout = 3;	//time in seconds before timeout 


	std::string solutionstring = call_python_solver(cubestring, max_length, timeout);
	std::cout << solutionstring << std::endl;
	
}
*/