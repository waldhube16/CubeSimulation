#pragma once

#include <Python.h>
#include <string>
#include <iostream>

std::string call_python_solver(std::string cubestring, int max_length, int timeout, bool first_run, bool final_run);
