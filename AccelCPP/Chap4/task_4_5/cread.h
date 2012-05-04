#ifndef GUARD_cread_h
#define GUARD_cread_h

//cread.h
#include "stdafx.h"
#include <vector>
#include <string>
#include <iostream>

typedef std::string str;
typedef std::vector<str> vector_string;

std::istream& cread(std::istream&, vector_string&);

#endif