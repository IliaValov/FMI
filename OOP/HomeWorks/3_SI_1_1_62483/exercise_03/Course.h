#pragma once
#include<iostream>
#include <string>
#include <vector>
#include "Teacher.h"

class Student;

class Course
{
private:
	std::string courseName;
	std::string courseType;

	std::string courseCode;

	Teacher teacher;

	std::vector<Student> students;

public:
	const std::string& GetName() const;
	void SetName(const std::string&);

	const std::string& GetCourseType() const;
	void SetCourseType(const std::string&);

	const std::string& GetCourseCode() const;
	void SetCourseCode(const std::string&);

	const Teacher& GetTeacher() const;
	void SetTeacher(const Teacher&);

	void AddStudent(const Student&);
	void DeleteStudent(const int&);
};

