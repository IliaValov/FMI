#include "MusicFile.h"

void MusicFile::setFileName()
{
	this->SetName(this->songName + " - " + this->songName);
}

MusicFile::MusicFile(const std::string& fileName, const MusicExtension& extension, const Date& date, const double& megabytes, const std::string& performerName, const std::string& songName, const Date& dateOfSongCreation)
	: songName(songName), performerName(performerName), dateOfSongCreation(dateOfSongCreation), File(fileName, "", date, megabytes)
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

const std::string& MusicFile::GetPerformerName()const
{
	return this->performerName;
}

void MusicFile::SetPerformerName(const std::string& performerName)
{
	this->performerName = performerName;

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
