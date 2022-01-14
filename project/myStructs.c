struct Player{
  int id;
  char* name;
  int* elo;
  char* teamPlays;
  int* gamesPlayed;


};
struct Game{
  unsigned int id;
  unsigned int blu[3];
  unsigned int red[3];
  // players stats
  unsigned int playersStatsBlu[9];
  unsigned int playersStatsRed[9];
};