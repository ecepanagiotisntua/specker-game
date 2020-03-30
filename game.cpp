class Game {

private:
int players;
int heaps;
static int heap_count;
static int players_count;
int *heap_coins;
Player *player_table;


public:
Game(int heaps, int players);
~Game();

void addHeap(int coins) throw(logic_error);
void addPlayer(Player *player) throw(logic_error);
void play(ostream &out) throw(logic_error);
};

Game::Game(int heaps, int players){

