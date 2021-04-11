#include "life.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

Cell::Cell(){
    this -> live_neighbors = 0;
    this -> live = false;
    this -> symbol = ' ';
}

Cell Cell::evolve(){
    Cell new_cell;
    if (this -> live == true){
        if (!(this -> live_neighbors > 1 && this-> live_neighbors <= 3)){
            return new_cell;
        }
        new_cell.live = true;
        new_cell.symbol = '@';
        return new_cell;
    }
    else if (this -> live == false){
        if (this -> live_neighbors == 3){
            new_cell.live = true;
            new_cell.symbol = '@';
            return new_cell;
        }
    }
    return new_cell;
}

World::World(int board_size){
    Cell** cells;
    cells = new Cell*[board_size+2];
    for (int i = 0; i <= board_size+2; i++){
        cells[i]= new Cell[board_size+2];
    }
    for (int i = 1; i < board_size+1; i++){
        for (int k = 1; k < board_size+1; k++){
            if (rand() % 100 + 1 <= 12){
                cells[i][k].live = true;
                cells[i][k].symbol = '@';
                for (int n = -1; n <= 1; n++){
                    for (int m = -1; m <= 1; m++){
                        cells[i+n][k+m].live_neighbors += 1;
                    }
                }
                cells[i][k].live_neighbors -= 1;
                }
                else {cells[i][k].live = false;}
            }
        }
    this -> cells = cells;
    this -> time = 0;
    this -> board_size = board_size;
}

void World::evolve(){
    Cell** cells;
    cells = new Cell*[board_size+2];
    for (int i = 0; i <= board_size+2; i++){
        cells[i]= new Cell[board_size+2];
    }
    for (int i = 1; i < this -> board_size+1; i++){
        for (int k = 1; k < this -> board_size+1; k++){
            cells[i][k] = this -> cells[i][k].evolve();
        }
    }
    for (int i = 1; i < this -> board_size+1; i++){
        for (int k = 1; k < this -> board_size+1; k++){
            if ( cells[i][k].live == true){
                for (int n = -1; n <= 1; n++){
                    for (int m = -1; m <= 1; m++){
                        cells[i+n][k+m].live_neighbors += 1;
                    }
                }
                cells[i][k].live_neighbors -= 1;
            }
        }
    }
    this -> cells = cells;
    this -> time += 1;
}

void World::print(){
    for (int i = 0; i < this -> board_size+2; i++){
        for (int k = 0; k < this -> board_size+2; k++){
            std::cout << this -> cells[i][k].symbol;
        }
        std::cout << '\n';
    }
}
