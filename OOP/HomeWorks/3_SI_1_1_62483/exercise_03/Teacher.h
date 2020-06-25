#pragma once
#include <iostream>
#include <string>
#include <vector>

class Course;

enum class Title {
	honorary = 1,
	ChiefAssistant = 2,
	Doctor = 3,
	AssociateProfessor = 4,
	Professor = 5,
};

class Teacher
{
private:
	std::string teacherName;
	Title title;
	std::vector<Course> courses;

public:

	const std::string& GetTeacherName() const;
	void SetTeacher(const std::string&);

	const Title& GetTitle() const;
	void SetTitle(const Title&);

	void AddCourse(const Course&);
	void DeleteCourse(const int&);

};

