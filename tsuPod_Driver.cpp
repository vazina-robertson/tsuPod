
/****************************************************

File Name: tsuPodDriver.cpp

Authors: L.Provvidente and V.Robertson
Date: February 20, 2015

This is the driver file for the TsuPod. In conjunction with the source
and header file, it runs basic functions found in a music iPod.
This will test functions such as adding, removing, shuffling and displaying
songs that are stored in an array.

*****************************************************/

#include <iostream>
#include <fstream>

#include "tsuPod.h"

using namespace std;

int main()
{

   cout << "Displaying testing of all functions: " << endl << endl;

   cout << "Successful initialization of TsuPod: "<< endl;
   initTsuPod();

   showSongList();
   cout << endl;

   cout << "Successful addition of songs: " << endl;

   int retCode;

   retCode = addSong("Runaway1", "Bon Jovi1", 1);
   retCode = addSong("Runaway2", "Bon Jovi2", 2);
   retCode = addSong("Runaway3", "Bon Jovi3", 3);
   retCode = addSong("Runaway4", "Bon Jovi4", 1);
   retCode = addSong("Runaway5", "Bon Jovi5", 5);
   retCode = addSong("Runaway6", "Bon Jovi6", 6);
   retCode = addSong("Runaway7", "Bon Jovi7", 1);
   retCode = addSong("Runaway8", "Bon Jovi8", 1);

   cout << retCode << endl;

   showSongList();
   cout << endl;

   cout << "Unsuccessful addition of song without title: " << endl;
   retCode = addSong(" ", "artist", 3);
   cout << retCode << endl; // Should return -2
   cout << endl;

   cout << "Unsuccessful addition of song without artist: " << endl;
   retCode = addSong("songName", " ", 4);
   cout << retCode << endl; // Should return -2
   cout << endl;

   cout << "Unsuccessful addition of song of no size: " << endl;
   retCode = addSong("songNoSize", "artistNoSize", 0);
   cout << retCode << endl; // Should return -2
   cout << endl;

   cout << "Unsuccessful addition of song when there is no memory: " << endl;
   retCode = addSong("bigSong", "someArtist", 20);
   cout << retCode << endl; // Should return -2
   cout << endl;

   cout << "Unsuccessful addition of nineth song: " << endl;
   retCode = addSong("Runaway9", "Bon Jovi9", 1);
   cout << retCode << endl; // Should return -2
   cout << endl;

   cout << "Successful shuffle: " << endl;
   shuffle();

   showSongList();
   cout << endl;

   cout << "Successful removal of song: " << endl;
   retCode = removeSong("Runaway");
   cout << retCode << endl;

   showSongList();
   cout << endl;

   cout << "Unsuccessful removal of song. Song with wrong title: " << endl;

   retCode = removeSong("Singing in the rain");
   cout << retCode << endl;

   showSongList();
   cout << endl;

   cout << "Testing clearing of memory: " << endl;
   clearMemory();

   showSongList();
   cout << endl;

   return 0;
}




