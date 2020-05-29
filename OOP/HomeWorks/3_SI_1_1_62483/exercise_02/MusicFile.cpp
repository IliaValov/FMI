#include "MusicFile.h"

MusicFile::MusicFile(const String& fileName, const MusicExtension& extension, const Date& date, const double& megabytes, const String& author, const String& songName, const Date& dateOfSongCreation) 
	: author(author), songName(songName), dateOfSongCreation(dateOfSongCreation), File(fileName, "", date, megabytes)
{
	if (extension == MusicExtension::MP3) {
		this->SetExtension(".mp3");
	}
	else if(extension == MusicExtension::FLAC){
		this->SetExtension(".flac");
	}
	else {
		this->SetExtension("WRONG EXTENSION");
	}
}

const String& MusicFile::GetAuthor()const
{
	return this->author;
}

void MusicFile::SetAuthor(const String& author)
{
	this->author = author;
}

const String& MusicFile::GetSongName() const
{
	return this->songName;
}

void MusicFile::SetSongName(const String& songName)
{
	this->songName = songName;
}

const Date& MusicFile::GetDateOfTheSong() const
{
	return this->dateOfSongCreation;
}

void MusicFile::SetDateOfTheSong(const Date& date)
{
	this->dateOfSongCreation = date;
}
