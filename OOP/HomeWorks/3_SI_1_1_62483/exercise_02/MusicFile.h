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
	
	std::string songName;
	std::string performerName;
	Date dateOfSongCreation;

	void setFileName();
public:

	MusicFile(const std::string& fileName, const MusicExtension& extension, const Date& date,const double& megabytes,const std::string& performerName, const std::string& songName, const Date& dateOfSongCreation);

	const std::string& GetPerformerName() const;
	void SetPerformerName(const std::string& performerName);

	const std::string& GetSongName() const;
	void SetSongName(const std::string& songName);

	const Date& GetDateOfTheSong() const;
	void SetDateOfTheSong(const Date& date);

};

