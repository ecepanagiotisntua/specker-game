#include <iostream>
#include <stdexcept>

using namespace std;

class Game {

private:
int players;
int heaps;
int heap_count;
int players_count;
int *heap_coins;
Player **player_table;


public:
Game(int heaps, int players);
~Game();

void addHeap(int coins) throw(logic_error);
void addPlayer(Player *player) throw(logic_error);
void play(ostream &out) throw(logic_error);
};

Game::Game(int heaps, int players){
  players = players;
  heaps = heaps;
  heap_count = 0;
  player_count = 0;
  heap_coins = new int[heaps];
  player_table = new Player*[players];
}

Game::~Game(){
  delete [] heap_coins;
  delete [] player_table;
}

void Game::addHeap(int coins) throw(logic_error){
  if (coins < 0) throw logic_error("No negative coins");
  else if (heap_count >= heaps) throw logic_error("No  more heaps");
  else{
    heap_coins[heap_count] = coins;
    heap_count++;
  }
}

void Game::addPlayer(Player *player) throw(logic_error){
  if (player_count >= players) throw logic_error("No more players");
  else{
    player_table[player_count] = player;
    player_count++;
  }
  
void Game::play(ostream &out) throw(logic_error){
  if(player_count != players || heap_count != heaps) throw logic_error("Not enough players yet");
  else{
    State game(heaps, heap_coins []);
    int i = 0;
    while(!game.winning()){
      out << "State: " << game << endl;
      out << *player_table[i] << " " << player_table[i]->play(game) << endl;
      game.next(player_table[i]->play(game));
      
      i++;
    }
    out << "State: " << game << endl;
    i--;
    out << *player[i] << " wins" << endl;
  }
}
  
  
  
    

