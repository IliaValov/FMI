#pragma once
#include "String.h"
#include "File.h"
#include "Date.h"

enum class MusicExtension {
	MP3 = 1,
	FLAC = 2,
};

class MusicFile : public File
{
private:
	
	std::string author;
	std::string songName;
	Date dateOfSongCreation;

	void setFileName();
public:

	MusicFile(const std::string& fileName, const MusicExtension& extension, const Date& date,const double& megabytes,const std::string& author, const std::string& songName, const Date& dateOfSongCreation);

	const std::string& GetAuthor() const;
	void SetAuthor(const std::string& author);

	const std::string& GetSongName() const;
	void SetSongName(const std::string& songName);

	const Date& GetDateOfTheSong() const;
	void SetDateOfTheSong(const Date& date);

};

