#pragma once
#include <iostream>
#include <string>
#include <vector>

#include "Teacher.h"
#include "Course.h"

class Student
{
private:
	std::string name;
	int fnNumber;
	std::vector<Course> courses;
	std::vector<double> gradesFromFinishedCourses;

public:
	const std::string& GetName() const;
	void SetName(const std::string&);

	const int& GetFnNumber() const;
	void SetFnNumber(const int&);

	void AddCourse(const Course&);
	void DeleteCourse(const int&);

	void AddGradeFromFinishedCourse(const double&);
	void DeleteGradeFromFinishedCourse(const int&);
};

