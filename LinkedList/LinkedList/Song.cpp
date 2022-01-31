/*************************************************************
* Author:		James Nordquist
* Filename:		Song.cpp
* Date Created:	6/6/18
* Modifications:	6/6/18 - Did everything
**************************************************************/
#include <iostream>
using std::cin;
using std::endl;
using std::cout;
#include "Song.h"



Song::Song()
{
	setSongName("");
	setArtistName("");
}

Song::Song(const Song & obj):m_song_name(obj.m_song_name),m_artist_name(obj.m_artist_name)
{

}

Song::Song(string songName, string artistName):m_song_name(songName),m_artist_name(artistName)
{
	
}

Song::~Song()
{

}

Song & Song::operator =(const Song & rhs)
{
	if (m_song_name != rhs.m_song_name)
	{
		m_song_name = rhs.m_song_name;
	}
	if (m_artist_name != rhs.m_artist_name)
	{
		m_artist_name = rhs.m_artist_name;
	}
	return *this;
}
bool Song::operator ==(const Song & obj) const
{
	return m_song_name == obj.m_song_name ? true : false;
}
bool Song::operator ==(const string name) const
{
	return m_song_name == name ? true : false;
}
bool Song::operator !=(const Song & obj) const
{
	return m_song_name != obj.m_song_name ? true : false;
}
bool Song::operator !=(const string name) const
{
	return m_song_name != name ? true : false;
}
bool Song::operator <(const Song & obj) const
{
	return m_song_name < obj.m_song_name ? true : false;
}
bool Song::operator <=(const Song & obj) const
{
	return m_song_name <= obj.m_song_name ? true : false;
}
bool Song::operator >(const Song & obj) const
{
	return m_song_name > obj.m_song_name ? true : false;
}
bool Song::operator >=(const Song & obj) const
{
	return m_song_name >= obj.m_song_name ? true : false;
}
string Song::getSongName() const
{
	return m_song_name;
}

string Song::getArtistName() const
{
	return m_artist_name;
}

void Song::print() const
{
	cout << "Song Name: " << m_song_name << endl;
	cout << "Artist Name: " << m_artist_name << endl << endl;
}

void Song::setSongName(string name)
{
	m_song_name = name;
}

void Song::setArtistName(string name)
{
	m_artist_name = name;
}
