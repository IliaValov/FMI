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
	
	String author;
	String songName;
	Date dateOfSongCreation;

public:

	MusicFile(const String& fileName, const MusicExtension& extension, const Date& date,const double& megabytes,const String& author, const String& songName, const Date& dateOfSongCreation);

	const String& GetAuthor() const;
	void SetAuthor(const String& author);

	const String& GetSongName() const;
	void SetSongName(const String& songName);

	const Date& GetDateOfTheSong() const;
	void SetDateOfTheSong(const Date& date);

};

