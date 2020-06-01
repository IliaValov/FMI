#include "MusicFile.h"

void MusicFile::setFileName()
{
	this->SetName(this->author + " - " + this->songName);
}

MusicFile::MusicFile(const std::string& fileName, const MusicExtension& extension, const Date& date, const double& megabytes, const std::string& author, const std::string& songName, const Date& dateOfSongCreation)
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

	this->setFileName();
}

const std::string& MusicFile::GetAuthor()const
{
	return this->author;
}

void MusicFile::SetAuthor(const std::string& author)
{
	this->author = author;

	this->setFileName();
}

const std::string& MusicFile::GetSongName() const
{
	return this->songName;
}

void MusicFile::SetSongName(const std::string& songName)
{
	this->songName = songName;

	this->setFileName();
}

const Date& MusicFile::GetDateOfTheSong() const
{
	return this->dateOfSongCreation;
}

void MusicFile::SetDateOfTheSong(const Date& date)
{
	this->dateOfSongCreation = date;
}
