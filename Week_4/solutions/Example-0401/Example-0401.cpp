#include "Song.h"
#include "MusicAlbum.h"
#include <iostream>
using namespace std;

int main()
{
    Song chopSuey("Chop Suey!", "System Of A Down", Rock, 3.26);
    Song whitesnake("Here I Go Again", "Whitesnake", Rock, 4.31);
    Song elmazIStuklo("Elmaz i staklo", "BTR", Rock, 5.07);
    Song chernaOvca("Elmaz i staklo", "BTR", Rock, 5.07);
    Song animal("Three Days Grace", "Animal I Have Become", Rock, 3.50);
    Song hate("Three Days Grace", "I Hate Everything About You", Rock, 3.39);

    Song songs[5];
    songs[0] = chopSuey;
    songs[1] = whitesnake;
    songs[2] = elmazIStuklo;
    songs[3] = chernaOvca;
    songs[4] = animal;

    MusicAlbum rockBallads(songs, 5);
    cout << "Total length is: " << rockBallads.TotalLength() << endl;
    cout << "Number of rock songs is: " << rockBallads.CountOfSongsOfGenre(Rock) << endl;
    cout << "Songs from \'Three Days Grace\' is : " << rockBallads.CountOfSongsOfArtist("Three Days Grace") << endl;
    rockBallads.AddSong(hate);
    cout << "Total length is: " << rockBallads.TotalLength() << endl;
    cout << "Number of rock songs is: " << rockBallads.CountOfSongsOfGenre(Rock) << endl;
    cout << "Songs from \'Three Days Grace\' is : " << rockBallads.CountOfSongsOfArtist("Three Days Grace") << endl;
    return 0;
}
