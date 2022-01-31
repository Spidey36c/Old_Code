#pragma once
/*************************************************************
* Author:		James Nordquist
* Filename:		Song.h
* Date Created:	6/6/18
* Modifications:	6/7/18 - Did everything
**************************************************************/
#include <string>
using std::string;

/************************************************************************
* Class: Array
*
* Purpose: This class creates an obj to hold a song name and the name of the artist of said song
*
* Manager functions:
*	Song()
*		sets the methods to nothing
*	Song(string songName, string artistName)
*		sets m_song_name and m_artist_name to songName and artistName respectively
*	string getSongName() const
*		returns m_song_name as a const
*	string getArtistName() const
*		returns m_artist_name as a const
*	void print() const
*		outputs m_song_name and m_artist_name in the console
*	void setSongName(string name)
*		sets m_song_name to name
*	void setArtistName(string name)
*		sets m_artist_name to name
* Methods:
*	m_song_name
*		string obj that holds a song name
*	m_next
*		string obj that holds a song name
*************************************************************************/
class Song
{
public:
	Song();
	Song(const Song & obj);
	Song(string songName, string artistName);
	~Song();
	Song & operator =(const Song & rhs);
	bool operator ==(const Song & obj) const;
	bool operator ==(const string name) const;
	bool operator !=(const Song & obj) const;
	bool operator !=(const string name) const;
	bool operator <(const Song & obj) const;
	bool operator <=(const Song & obj) const;
	bool operator >(const Song & obj) const;
	bool operator >=(const Song & obj) const;
	string getSongName() const;
	string getArtistName() const;
	void print() const;
	void setSongName(string name);
	void setArtistName(string name);

private:
	string m_song_name;
	string m_artist_name;
};

