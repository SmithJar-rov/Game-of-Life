class Cell{
    public:
        bool live;
        int live_neighbors;
        char symbol;
        Cell();
        Cell evolve();
};

class World{
    private:
        Cell** cells;
        int time;
        int board_size;
    public:
        World(int board_size);
        void evolve();
        void print();
};
