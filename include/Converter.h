#pragma once
#include "lib.h"
#include "Student.h"
#include "Number.h"

class StringToStudentConverter;

class StringToStudentConverter
{
public:
	Student convert(vector<string>);
	vector<string> convertBack(Student);
};