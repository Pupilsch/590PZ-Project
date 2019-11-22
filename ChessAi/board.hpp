#ifndef BOARD_HPP
#define BOARD_HPP

#include <iostream>
#include <vector>
#include <stack>
#include "piece.hpp"

using namespace std;

#define HEIGHT 5
#define WIDTH 4
#define MAX_DEPTH 5

// enum player_t{
// 	HUMAN,COMP
// };

struct point_t
{
    int r;
    int c;
};

struct move_t{
    point_t src;
    point_t des;
};

struct minimax_return{
    move_t a_move;
    int a_score;
};

/*
// Type: point_t
// ------------
// This type is used to represent a point in the grid.
// Its component r corresponds to the row number; its component
// c corresponds to the column number.
*/

class Board{
public:
    Board();
    void init_board();
    void set_board();
    void print();
    int evaluate();
    bool white_now;
    void move(move_t s_move);
    void human_move(move_t s_move);
    void undo_move();
    bool if_checked(PieceColor color);
    bool if_lose(PieceColor color);
    bool if_draw(PieceColor color);
    minimax_return minimax(int depth);
    //void init_place();
    void valid_move();
    vector<move_t> VM_white; //list of valid of white
    vector<move_t> VM_black; //list of valid of black
    vector<vector<Piece*> > grid;
    stack<vector<vector<Piece*> > > grid_list;
};

void Board::move(move_t s_move){
    int x1=s_move.src.r;
    int y1=s_move.src.c;
    int x2=s_move.des.r;
    int y2=s_move.des.c;

    grid[x2][y2]=grid[x1][y1];
    grid[x1][y1]=NULL;
    //Add change pawn at bottom
    if(x2==0 && grid[x2][y2]->get_type()==pawn && grid[x2][y2]->get_color()==black){
        grid[x2][y2]=NULL;
        Piece *p=new Rock(black);
        grid[x2][y2]=p;
    }
    if(x2==4 && grid[x2][y2]->get_type()==pawn && grid[x2][y2]->get_color()==white){
        grid[x2][y2]=NULL;
        Piece *p=new Rock(white);
        grid[x2][y2]=p;
    }
    grid_list.push(grid);
    valid_move();
    white_now=!white_now;
}

void Board::human_move(move_t s_move){
    int x1=s_move.src.r;
    int y1=s_move.src.c;
    int x2=s_move.des.r;
    int y2=s_move.des.c;

    grid[x2][y2]=grid[x1][y1];
    grid[x1][y1]=NULL;

    if(x2==0 && grid[x2][y2]->get_type()==pawn && grid[x2][y2]->get_color()==black){
        grid[x2][y2]=NULL;
        Piece *p=new Rock(black);
        grid[x2][y2]=p;
    }
    if(x2==4 && grid[x2][y2]->get_type()==pawn && grid[x2][y2]->get_color()==white){
        grid[x2][y2]=NULL;
        Piece *p=new Rock(white);
        grid[x2][y2]=p;
    }

    grid_list.pop();
    grid_list.push(grid);
    valid_move();
    white_now=!white_now;
}

void Board::undo_move(){
    grid_list.pop();
    grid=grid_list.top();
    white_now=!white_now;
    valid_move();
}

void Board::valid_move(){
    //clean the valid move vector before start
    vector<move_t>().swap(VM_white);
    vector<move_t>().swap(VM_black);
    for(int i=0;i<HEIGHT;i++){
        for(int j=0;j<WIDTH;j++){
            move_t a_move;
            point_t src;
            //point_t des;
            src.r=i;
            src.c=j;
            a_move.src=src;
            if(grid[i][j]==NULL) continue;
            //search for pawn
            if(grid[i][j]->get_type()==pawn){
                if(grid[i][j]->get_color()==white){
                    int r=i;
                    int c=j;
                    if(r!=4 && grid[r+1][c]==NULL){
                        point_t p;
                        p.r=r+1;
                        p.c=c;
                        a_move.des=p;
                        VM_white.push_back(a_move);
                    }
                    if(r!=4 && c==0){
                        if(grid[r+1][c+1]!=NULL){
                            if(grid[r+1][c+1]->get_color()==black){
                                point_t p;
                                p.r=r+1;
                                p.c=c+1;
                                a_move.des=p;
                                VM_white.push_back(a_move);
                            }
                        }
                    }
                    if(r!=4 && c==3){
                        if(grid[r+1][c-1]!=NULL){
                            if(grid[r+1][c-1]->get_color()==black){
                                point_t p;
                                p.r=r+1;
                                p.c=c-1;
                                a_move.des=p;
                                VM_white.push_back(a_move);
                            }
                        }
                    }
                    if(r!=4 && (c==1 || c==2)){
                        if(grid[r+1][c-1]!=NULL){
                            if(grid[r+1][c-1]->get_color()==black){
                                point_t p;
                                p.r=r+1;
                                p.c=c-1;
                                a_move.des=p;
                                VM_white.push_back(a_move);
                            }
                        }
                        if(grid[r+1][c+1]!=NULL){
                            if(grid[r+1][c+1]->get_color()==black){
                                point_t p;
                                p.r=r+1;
                                p.c=c+1;
                                a_move.des=p;
                                VM_white.push_back(a_move);
                            }
                        }
                    }
                }
                if(grid[i][j]->get_color()==black){
                    int r=i;
                    int c=j;
                    if(r!=0 && grid[r-1][c]==NULL){
                        point_t p;
                        p.r=r-1;
                        p.c=c;
                        a_move.des=p;
                        VM_black.push_back(a_move);
                    }
                    if(r!=0 && c==0){
                        if(grid[r-1][c+1]!=NULL){
                            if(grid[r-1][c+1]->get_color()==white){
                                point_t p;
                                p.r=r-1;
                                p.c=c+1;
                                a_move.des=p;
                                VM_black.push_back(a_move);
                            }
                        }
                    }
                    if(r!=0 && c==3){
                        if(grid[r-1][c-1]!=NULL){
                            if(grid[r-1][c-1]->get_color()==white){
                                point_t p;
                                p.r=r-1;
                                p.c=c-1;
                                a_move.des=p;
                                VM_black.push_back(a_move);
                            }
                        }
                    }
                    if(r!=0 && (c==1 || c==2)){
                        if(grid[r-1][c-1]!=NULL){
                            if(grid[r-1][c-1]->get_color()==white){
                                point_t p;
                                p.r=r-1;
                                p.c=c-1;
                                a_move.des=p;
                                VM_white.push_back(a_move);
                            }
                        }
                        if(grid[r-1][c+1]!=NULL){
                            if(grid[r-1][c+1]->get_color()==white){
                                point_t p;
                                p.r=r-1;
                                p.c=c+1;
                                a_move.des=p;
                                VM_black.push_back(a_move);
                            }
                        }
                    }
                }
            }

            //search for rock
            if(grid[i][j]->get_type()==rock){
                int r=i;
                int c=j;
                //serach east
                while(c!=3){
                    if(grid[r][c+1]==NULL){
                        point_t p;
                        p.r=r;
                        p.c=c+1;
                        a_move.des=p;
                        if(grid[i][j]->get_color()==white){
                            VM_white.push_back(a_move);
                        }else{
                            VM_black.push_back(a_move);
                        }
                        c++;
                        continue;
                    }
                    if(grid[r][c+1]->get_color()==grid[i][j]->get_color()){
                        break;
                    }
                    if(grid[r][c+1]->get_color()!=grid[i][j]->get_color()){
                        point_t p;
                        p.r=r;
                        p.c=c+1;
                        a_move.des=p;
                        if(grid[i][j]->get_color()==white){
                            VM_white.push_back(a_move);
                        }else{
                            VM_black.push_back(a_move);
                        }
                        break;
                    }
                }
                //search south
                r=i;
                c=j;
                while(r!=4){
                    if(grid[r+1][c]==NULL){
                        point_t p;
                        p.r=r+1;
                        p.c=c;
                        a_move.des=p;
                        if(grid[i][j]->get_color()==white){
                            VM_white.push_back(a_move);
                        }else{
                            VM_black.push_back(a_move);
                        }
                        r++;
                        continue;
                    }
                    if(grid[r+1][c]->get_color()==grid[i][j]->get_color()){
                        break;
                    }
                    if(grid[r+1][c]->get_color()!=grid[i][j]->get_color()){
                        point_t p;
                        p.r=r+1;
                        p.c=c;
                        a_move.des=p;
                        if(grid[i][j]->get_color()==white){
                            VM_white.push_back(a_move);
                        }else{
                            VM_black.push_back(a_move);
                        }
                        break;
                    }
                }
                //search west
                r=i;
                c=j;
                while(c!=0){
                    if(grid[r][c-1]==NULL){
                        point_t p;
                        p.r=r;
                        p.c=c-1;
                        a_move.des=p;
                        if(grid[i][j]->get_color()==white){
                            VM_white.push_back(a_move);
                        }else{
                            VM_black.push_back(a_move);
                        }
                        c--;
                        continue;
                    }
                    if(grid[r][c-1]->get_color()==grid[i][j]->get_color()){
                        break;
                    }
                    if(grid[r][c-1]->get_color()!=grid[i][j]->get_color()){
                        point_t p;
                        p.r=r;
                        p.c=c-1;
                        a_move.des=p;
                        if(grid[i][j]->get_color()==white){
                            VM_white.push_back(a_move);
                        }else{
                            VM_black.push_back(a_move);
                        }
                        break;
                    }
                }
                //search north
                r=i;
                c=j;
                while(r!=0){
                    if(grid[r-1][c]==NULL){
                        point_t p;
                        p.r=r-1;
                        p.c=c;
                        a_move.des=p;
                        if(grid[i][j]->get_color()==white){
                            VM_white.push_back(a_move);
                        }else{
                            VM_black.push_back(a_move);
                        }
                        r--;
                        continue;
                    }
                    if(grid[r-1][c]->get_color()==grid[i][j]->get_color()){
                        break;
                    }
                    if(grid[r-1][c]->get_color()!=grid[i][j]->get_color()){
                        point_t p;
                        p.r=r-1;
                        p.c=c;
                        a_move.des=p;
                        if(grid[i][j]->get_color()==white){
                            VM_white.push_back(a_move);
                        }else{
                            VM_black.push_back(a_move);
                        }
                        break;
                    }
                }
            }

            //search for bishop
            if(grid[i][j]->get_type()==bishop){
                int r=i;
                int c=j;
                //serach east-north
                while(c!=3 && r!=0){
                    if(grid[r-1][c+1]==NULL){
                        point_t p;
                        p.r=r-1;
                        p.c=c+1;
                        a_move.des=p;
                        if(grid[i][j]->get_color()==white){
                            VM_white.push_back(a_move);
                        }else{
                            VM_black.push_back(a_move);
                        }
                        r--;
                        c++;
                        continue;
                    }
                    if(grid[r-1][c+1]->get_color()==grid[i][j]->get_color()){
                        break;
                    }
                    if(grid[r-1][c+1]->get_color()!=grid[i][j]->get_color()){
                        point_t p;
                        p.r=r-1;
                        p.c=c+1;
                        a_move.des=p;
                        if(grid[i][j]->get_color()==white){
                            VM_white.push_back(a_move);
                        }else{
                            VM_black.push_back(a_move);
                        }
                        break;
                    }
                }
                //serach east-south
                r=i;
                c=j;
                while(c!=3 && r!=4){
                    if(grid[r+1][c+1]==NULL){
                        point_t p;
                        p.r=r+1;
                        p.c=c+1;
                        a_move.des=p;
                        if(grid[i][j]->get_color()==white){
                            VM_white.push_back(a_move);
                        }else{
                            VM_black.push_back(a_move);
                        }
                        r++;
                        c++;
                        continue;
                    }
                    if(grid[r+1][c+1]->get_color()==grid[i][j]->get_color()){
                        break;
                    }
                    if(grid[r+1][c+1]->get_color()!=grid[i][j]->get_color()){
                        point_t p;
                        p.r=r+1;
                        p.c=c+1;
                        a_move.des=p;
                        if(grid[i][j]->get_color()==white){
                            VM_white.push_back(a_move);
                        }else{
                            VM_black.push_back(a_move);
                        }
                        break;
                    }
                }
                //serach west-south
                r=i;
                c=j;
                while(c!=0 && r!=4){
                    if(grid[r+1][c-1]==NULL){
                        point_t p;
                        p.r=r+1;
                        p.c=c-1;
                        a_move.des=p;
                        if(grid[i][j]->get_color()==white){
                            VM_white.push_back(a_move);
                        }else{
                            VM_black.push_back(a_move);
                        }
                        r++;
                        c--;
                        continue;
                    }
                    if(grid[r+1][c-1]->get_color()==grid[i][j]->get_color()){
                        break;
                    }
                    if(grid[r+1][c-1]->get_color()!=grid[i][j]->get_color()){
                        point_t p;
                        p.r=r+1;
                        p.c=c-1;
                        a_move.des=p;
                        if(grid[i][j]->get_color()==white){
                            VM_white.push_back(a_move);
                        }else{
                            VM_black.push_back(a_move);
                        }
                        break;
                    }
                }
                //serach west-north
                r=i;
                c=j;
                while(c!=0 && r!=0){
                    if(grid[r-1][c-1]==NULL){
                        point_t p;
                        p.r=r-1;
                        p.c=c-1;
                        a_move.des=p;
                        if(grid[i][j]->get_color()==white){
                            VM_white.push_back(a_move);
                        }else{
                            VM_black.push_back(a_move);
                        }
                        r--;
                        c--;
                        continue;
                    }
                    if(grid[r-1][c-1]->get_color()==grid[i][j]->get_color()){
                        break;
                    }
                    if(grid[r-1][c-1]->get_color()!=grid[i][j]->get_color()){
                        point_t p;
                        p.r=r-1;
                        p.c=c-1;
                        a_move.des=p;
                        if(grid[i][j]->get_color()==white){
                            VM_white.push_back(a_move);
                        }else{
                            VM_black.push_back(a_move);
                        }
                        break;
                    }
                }
            }

            //search for knight
            if(grid[i][j]->get_type()==knight){
                int r=i;
                int c=j;
                if(r+1<=4 && c+2<=3){
                    if(grid[r+1][c+2]==NULL){
                        point_t p;
                        p.r=r+1;
                        p.c=c+2;
                        a_move.des=p;
                        if(grid[i][j]->get_color()==white){
                            VM_white.push_back(a_move);
                        }else{
                            VM_black.push_back(a_move);
                        }
                    }else{
                        if(grid[r+1][c+2]->get_color()!=grid[i][j]->get_color()){
                            point_t p;
                            p.r=r+1;
                            p.c=c+2;
                            a_move.des=p;
                            if(grid[i][j]->get_color()==white){
                                VM_white.push_back(a_move);
                            }else{
                                VM_black.push_back(a_move);
                            }
                        }
                    }
                }
                if(r+2<=4 && c+1<=3){
                    if(grid[r+2][c+1]==NULL){
                        point_t p;
                        p.r=r+2;
                        p.c=c+1;
                        a_move.des=p;
                        if(grid[i][j]->get_color()==white){
                            VM_white.push_back(a_move);
                        }else{
                            VM_black.push_back(a_move);
                        }
                    }else{
                        if(grid[r+2][c+1]->get_color()!=grid[i][j]->get_color()){
                            point_t p;
                            p.r=r+2;
                            p.c=c+1;
                            a_move.des=p;
                            if(grid[i][j]->get_color()==white){
                                VM_white.push_back(a_move);
                            }else{
                                VM_black.push_back(a_move);
                            }
                        }
                    }
                }
                if(r+2<=4 && c-1>=0){
                    if(grid[r+2][c-1]==NULL){
                        point_t p;
                        p.r=r+2;
                        p.c=c-1;
                        a_move.des=p;
                        if(grid[i][j]->get_color()==white){
                            VM_white.push_back(a_move);
                        }else{
                            VM_black.push_back(a_move);
                        }
                    }else{
                        if(grid[r+2][c-1]->get_color()!=grid[i][j]->get_color()){
                            point_t p;
                            p.r=r+2;
                            p.c=c-1;
                            a_move.des=p;
                            if(grid[i][j]->get_color()==white){
                                VM_white.push_back(a_move);
                            }else{
                                VM_black.push_back(a_move);
                            }
                        }
                    }
                }
                if(r+1<=4 && c-2>=0){
                    if(grid[r+1][c-2]==NULL){
                        point_t p;
                        p.r=r+1;
                        p.c=c-2;
                        a_move.des=p;
                        if(grid[i][j]->get_color()==white){
                            VM_white.push_back(a_move);
                        }else{
                            VM_black.push_back(a_move);
                        }
                    }else{
                        if(grid[r+1][c-2]->get_color()!=grid[i][j]->get_color()){
                            point_t p;
                            p.r=r+1;
                            p.c=c-2;
                            a_move.des=p;
                            if(grid[i][j]->get_color()==white){
                                VM_white.push_back(a_move);
                            }else{
                                VM_black.push_back(a_move);
                            }
                        }
                    }
                }
                if(r-1>=0 && c-2>=0){
                    if(grid[r-1][c-2]==NULL){
                        point_t p;
                        p.r=r-1;
                        p.c=c-2;
                        a_move.des=p;
                        if(grid[i][j]->get_color()==white){
                            VM_white.push_back(a_move);
                        }else{
                            VM_black.push_back(a_move);
                        }
                    }else{
                        if(grid[r-1][c-2]->get_color()!=grid[i][j]->get_color()){
                            point_t p;
                            p.r=r-1;
                            p.c=c-2;
                            a_move.des=p;
                            if(grid[i][j]->get_color()==white){
                                VM_white.push_back(a_move);
                            }else{
                                VM_black.push_back(a_move);
                            }
                        }
                    }
                }
                if(r-2>=0 && c-1>=0){
                    if(grid[r-2][c-1]==NULL){
                        point_t p;
                        p.r=r-2;
                        p.c=c-1;
                        a_move.des=p;
                        if(grid[i][j]->get_color()==white){
                            VM_white.push_back(a_move);
                        }else{
                            VM_black.push_back(a_move);
                        }
                    }else{
                        if(grid[r-2][c-1]->get_color()!=grid[i][j]->get_color()){
                            point_t p;
                            p.r=r-2;
                            p.c=c-1;
                            a_move.des=p;
                            if(grid[i][j]->get_color()==white){
                                VM_white.push_back(a_move);
                            }else{
                                VM_black.push_back(a_move);
                            }
                        }
                    }
                }
                if(r-2>=0 && c+1<=3){
                    if(grid[r-2][c+1]==NULL){
                        point_t p;
                        p.r=r-2;
                        p.c=c+1;
                        a_move.des=p;
                        if(grid[i][j]->get_color()==white){
                            VM_white.push_back(a_move);
                        }else{
                            VM_black.push_back(a_move);
                        }
                    }else{
                        if(grid[r-2][c+1]->get_color()!=grid[i][j]->get_color()){
                            point_t p;
                            p.r=r-2;
                            p.c=c+1;
                            a_move.des=p;
                            if(grid[i][j]->get_color()==white){
                                VM_white.push_back(a_move);
                            }else{
                                VM_black.push_back(a_move);
                            }
                        }
                    }
                }
                if(r-1>=0 && c+2<=3){
                    if(grid[r-1][c+2]==NULL){
                        point_t p;
                        p.r=r-1;
                        p.c=c+2;
                        a_move.des=p;
                        if(grid[i][j]->get_color()==white){
                            VM_white.push_back(a_move);
                        }else{
                            VM_black.push_back(a_move);
                        }
                    }else{
                        if(grid[r-1][c+2]->get_color()!=grid[i][j]->get_color()){
                            point_t p;
                            p.r=r-1;
                            p.c=c+2;
                            a_move.des=p;
                            if(grid[i][j]->get_color()==white){
                                VM_white.push_back(a_move);
                            }else{
                                VM_black.push_back(a_move);
                            }
                        }
                    }
                }
            }

            //search for king
            if(grid[i][j]->get_type()==king){
                int r=i;
                int c=j;
                if(r>=1 && c>=1){
                    if(grid[r-1][c-1]==NULL){
                        point_t p;
                        p.r=r-1;
                        p.c=c-1;
                        a_move.des=p;
                        if(grid[i][j]->get_color()==white){
                            VM_white.push_back(a_move);
                        }else{
                            VM_black.push_back(a_move);
                        }
                    }else{
                        if(grid[r-1][c-1]->get_color()!=grid[i][j]->get_color()){
                            point_t p;
                            p.r=r-1;
                            p.c=c-1;
                            a_move.des=p;
                            if(grid[i][j]->get_color()==white){
                                VM_white.push_back(a_move);
                            }else{
                                VM_black.push_back(a_move);
                            }
                        }
                    }
                }
                if(r>=1){
                    if(grid[r-1][c]==NULL){
                        point_t p;
                        p.r=r-1;
                        p.c=c;
                        a_move.des=p;
                        if(grid[i][j]->get_color()==white){
                            VM_white.push_back(a_move);
                        }else{
                            VM_black.push_back(a_move);
                        }
                    }else{
                        if(grid[r-1][c]->get_color()!=grid[i][j]->get_color()){
                            point_t p;
                            p.r=r-1;
                            p.c=c;
                            a_move.des=p;
                            if(grid[i][j]->get_color()==white){
                                VM_white.push_back(a_move);
                            }else{
                                VM_black.push_back(a_move);
                            }
                        }
                    }
                }
                if(r>=1 && c<=2){
                    if(grid[r-1][c+1]==NULL){
                        point_t p;
                        p.r=r-1;
                        p.c=c+1;
                        a_move.des=p;
                        if(grid[i][j]->get_color()==white){
                            VM_white.push_back(a_move);
                        }else{
                            VM_black.push_back(a_move);
                        }
                    }else{
                        if(grid[r-1][c+1]->get_color()!=grid[i][j]->get_color()){
                            point_t p;
                            p.r=r-1;
                            p.c=c+1;
                            a_move.des=p;
                            if(grid[i][j]->get_color()==white){
                                VM_white.push_back(a_move);
                            }else{
                                VM_black.push_back(a_move);
                            }
                        }
                    }
                }
                if(c<=2){
                    if(grid[r][c+1]==NULL){
                        point_t p;
                        p.r=r;
                        p.c=c+1;
                        a_move.des=p;
                        if(grid[i][j]->get_color()==white){
                            VM_white.push_back(a_move);
                        }else{
                            VM_black.push_back(a_move);
                        }
                    }else{
                        if(grid[r][c+1]->get_color()!=grid[i][j]->get_color()){
                            point_t p;
                            p.r=r;
                            p.c=c+1;
                            a_move.des=p;
                            if(grid[i][j]->get_color()==white){
                                VM_white.push_back(a_move);
                            }else{
                                VM_black.push_back(a_move);
                            }
                        }
                    }
                }
                if(r<=3 && c<=2){
                    if(grid[r+1][c+1]==NULL){
                        point_t p;
                        p.r=r+1;
                        p.c=c+1;
                        a_move.des=p;
                        if(grid[i][j]->get_color()==white){
                            VM_white.push_back(a_move);
                        }else{
                            VM_black.push_back(a_move);
                        }
                    }else{
                        if(grid[r+1][c+1]->get_color()!=grid[i][j]->get_color()){
                            point_t p;
                            p.r=r+1;
                            p.c=c+1;
                            a_move.des=p;
                            if(grid[i][j]->get_color()==white){
                                VM_white.push_back(a_move);
                            }else{
                                VM_black.push_back(a_move);
                            }
                        }
                    }
                }
                if(r<=3){
                    if(grid[r+1][c]==NULL){
                        point_t p;
                        p.r=r+1;
                        p.c=c;
                        a_move.des=p;
                        if(grid[i][j]->get_color()==white){
                            VM_white.push_back(a_move);
                        }else{
                            VM_black.push_back(a_move);
                        }
                    }else{
                        if(grid[r+1][c]->get_color()!=grid[i][j]->get_color()){
                            point_t p;
                            p.r=r+1;
                            p.c=c;
                            a_move.des=p;
                            if(grid[i][j]->get_color()==white){
                                VM_white.push_back(a_move);
                            }else{
                                VM_black.push_back(a_move);
                            }
                        }
                    }
                }
                if(r<=3 && c>=1){
                    if(grid[r+1][c-1]==NULL){
                        point_t p;
                        p.r=r+1;
                        p.c=c-1;
                        a_move.des=p;
                        if(grid[i][j]->get_color()==white){
                            VM_white.push_back(a_move);
                        }else{
                            VM_black.push_back(a_move);
                        }
                    }else{
                        if(grid[r+1][c-1]->get_color()!=grid[i][j]->get_color()){
                            point_t p;
                            p.r=r+1;
                            p.c=c-1;
                            a_move.des=p;
                            if(grid[i][j]->get_color()==white){
                                VM_white.push_back(a_move);
                            }else{
                                VM_black.push_back(a_move);
                            }
                        }
                    }
                }
                if(c>=1){
                    if(grid[r][c-1]==NULL){
                        point_t p;
                        p.r=r;
                        p.c=c-1;
                        a_move.des=p;
                        if(grid[i][j]->get_color()==white){
                            VM_white.push_back(a_move);
                        }else{
                            VM_black.push_back(a_move);
                        }
                    }else{
                        if(grid[r][c-1]->get_color()!=grid[i][j]->get_color()){
                            point_t p;
                            p.r=r;
                            p.c=c-1;
                            a_move.des=p;
                            if(grid[i][j]->get_color()==white){
                                VM_white.push_back(a_move);
                            }else{
                                VM_black.push_back(a_move);
                            }
                        }
                    }
                }
            }
        }
    }
}

void Board::init_board(){
    Piece *temp;
    //Put Pieces on the board
    temp=new Rock(white);
    grid[0][0]=temp;
    temp=new Knight(white);
    grid[0][1]=temp;
    temp=new Bishop(white);
    grid[0][2]=temp;
    temp=new King(white);
    grid[0][3]=temp;
    for(int j=0;j<WIDTH;j++){
        temp=new Pawn(white);
        grid[1][j]=temp;
    }

    temp=new Rock(black);
    grid[4][0]=temp;
    temp=new Knight(black);
    grid[4][1]=temp;
    temp=new Bishop(black);
    grid[4][2]=temp;
    temp=new King(black);
    grid[4][3]=temp;
    for(int j=0;j<WIDTH;j++){
        temp=new Pawn(black);
        grid[3][j]=temp;
    }

    for(int j=0;j<WIDTH;j++){
        grid[2][j]=NULL;
    }
    grid_list.push(grid);
}

void Board::set_board() {
    for(int i=0;i<HEIGHT;i++){
        for(int j=0;j<WIDTH;j++){
            grid[i][j]=NULL;
        }
    }
    Piece *temp;
    temp=new Rock(white);
    grid[3][0]=temp;
    temp=new King(white);
    grid[0][3]=temp;
    temp=new Pawn(white);
    grid[1][2]=temp;
    temp=new Pawn(white);
    grid[2][3]=temp;
    temp=new Rock(black);
    grid[4][1]=temp;
    temp=new Pawn(black);
    grid[2][2]=temp;
    temp=new Pawn(black);
    grid[3][3]=temp;
    temp=new King(black);
    grid[4][3]=temp;
    temp=new Bishop(white);
    grid[2][0]=temp;

    grid_list.push(grid);
}

Board::Board(){
    grid.resize(HEIGHT);
    for(int i=0;i<HEIGHT;i++){
        for(int j=0;j<WIDTH;j++){
            grid[i].push_back(NULL);
        }
    }

    this->white_now=true;
}

void Board::print() {
    cout << "  a b c d" << endl;
    for (int i = 0; i <HEIGHT; ++i) {
        cout << i + 1 << " ";
        for (int j = 0; j < WIDTH; ++j) {
            if (grid[i][j] != NULL) {
                grid[i][j]->print();
            } else {
                wcout << L"- ";
            }
        }
        cout << endl;
    }
    cout << endl;
}

int Board::evaluate(){
    int value=0;
    for(int i=0;i<HEIGHT;i++){
        for(int j=0;j<WIDTH;j++){
            if(grid[i][j]!=NULL){
                if(grid[i][j]->get_color()==white){
                    value+=grid[i][j]->value;
                }else{
                    value-=grid[i][j]->value;
                }
            }
        }
    }
    return value;
}

bool Board::if_checked(PieceColor color){
    bool result=false;
    if(color==white){
        for(int i=0;i<HEIGHT;i++){
            for(int j=0;j<WIDTH;j++){
                if(grid[i][j]!=NULL){
                    if(grid[i][j]->get_type()==king && grid[i][j]->get_color()==white){
                        if(VM_black.empty()){
                            return false;
                        }else{
                            for(int m=0;m<VM_black.size();m++){
                                if(VM_black[m].des.r==i && VM_black[m].des.c==j) return true;
                            }
                        }
                    }
                }
            }
        }
    }
    if(color==black){
        for(int i=0;i<HEIGHT;i++){
            for(int j=0;j<WIDTH;j++){
                if(grid[i][j]!=NULL){
                    if(grid[i][j]->get_type()==king && grid[i][j]->get_color()==black){
                        if(VM_white.empty()){
                            return false;
                        }else{
                            for(int m=0;m<VM_white.size();m++){
                                if(VM_white[m].des.r==i && VM_white[m].des.c==j) return true;
                            }
                        }
                    }
                }
            }
        }
    }
    return result;
}

bool Board::if_lose(PieceColor color){//Need to be called after valid_move(), color represent the one who might lose
    bool result=false;
    int flag=0;
//    vector<move_t> white_backup(VM_white);
//    vector<move_t> black_backup(VM_black);
    if(color==white){
        if(if_checked(white)){
            if(VM_white.empty()) return true;
            for(int i=0;i<VM_white.size();i++){
                move(VM_white[i]);
                if(!if_checked(white)) flag=1;
                undo_move();
            }
            if(flag==1) return false;
            if(flag==0) return true;
        }
    }
    flag=0;
    if(color==black){
        if(if_checked(black)){
            if(VM_black.empty()) return true;
            for(int i=0;i<VM_black.size();i++){
                move(VM_black[i]);
                if(!if_checked(black)) flag=1;
                undo_move();
            }
            if(flag==1) return false;
            if(flag==0) return true;
        }
    }
    return result;
}

bool Board::if_draw(PieceColor color){
    bool result=false;
    int flag=0;
//    vector<move_t> white_backup(VM_white);
//    vector<move_t> black_backup(VM_black);
    if(color==white){
        if(!if_checked(white)){
            if(VM_white.empty()) return true;
            for(int i=0;i<VM_white.size();i++){
                move(VM_white[i]);
                if(!if_checked(white)) flag=1;
                undo_move();
            }
            if(flag==1) return false;
            if(flag==0) return true;
        }
    }
    flag=0;
    if(color==black){
        if(!if_checked(black)){
            if(VM_black.empty()) return true;
            for(int i=0;i<VM_black.size();i++){
                move(VM_black[i]);
                if(!if_checked(black)) flag=1;
                undo_move();
            }
            if(flag==1) return false;
            if(flag==0) return true;
        }
    }
    return result;
}

minimax_return Board::minimax(int depth){
    minimax_return result;
    minimax_return sol;
    int best;
    int score;
    move_t a_move;
    vector<move_t> white_backup(VM_white);
    vector<move_t> black_backup(VM_black);

    if(white_now){
        best=-10000;
    }else{
        best=10000;
    }

    //First judge if draw or lose or if depth=0
    if(white_now){
        if(if_lose(white)) {
            score=-5000;
            result.a_move.des.r=-1;
            result.a_move.des.c=-1;
            result.a_move.src.r=-1;
            result.a_move.src.c=-1;
            result.a_score=score;
            return result;
        }
        if(if_draw(white)){
            score=0;
            result.a_move.des.r=-1;
            result.a_move.des.c=-1;
            result.a_move.src.r=-1;
            result.a_move.src.c=-1;
            result.a_score=score;
            return result;
        }
        if(depth!=MAX_DEPTH && if_checked(black)){//Might have problem
            score=10000;
            result.a_move.des.r=-1;
            result.a_move.des.c=-1;
            result.a_move.src.r=-1;
            result.a_move.src.c=-1;
            result.a_score=score;
            return result;
        }
    }else{
        if(if_lose(black)) {
            score=5000;
            result.a_move.des.r=-1;
            result.a_move.des.c=-1;
            result.a_move.src.r=-1;
            result.a_move.src.c=-1;
            result.a_score=score;
            return result;
        }
        if(if_draw(black)){
            score=0;
            result.a_move.des.r=-1;
            result.a_move.des.c=-1;
            result.a_move.src.r=-1;
            result.a_move.src.c=-1;
            result.a_score=score;
            return result;
        }
        if(depth!=MAX_DEPTH && if_checked(white)){//Might have problem
            score=-10000;
            result.a_move.des.r=-1;
            result.a_move.des.c=-1;
            result.a_move.src.r=-1;
            result.a_move.src.c=-1;
            result.a_score=score;
            return result;
        }
    }

    if(depth==0){
        score=evaluate();
        result.a_move.des.r=-1;
        result.a_move.des.c=-1;
        result.a_move.src.r=-1;
        result.a_move.src.c=-1;
        result.a_score=score;
        return result;
    }

    if(white_now){
        for(int i=0;i<white_backup.size();i++){
            point_t start=white_backup[i].src;
            move(white_backup[i]);
            result=minimax(depth-1);
            undo_move();
            point_t end=white_backup[i].des;
            if(result.a_score>best){
                sol.a_move.src=start;
                sol.a_move.des=end;
                best=result.a_score;
                sol.a_score=best;
            }
        }
    }else{
        for(int i=0;i<black_backup.size();i++){
            point_t start=black_backup[i].src;
            move(black_backup[i]);
            result=minimax(depth-1);
            undo_move();
            point_t end=black_backup[i].des;
            if(result.a_score<best){
                sol.a_move.src=start;
                sol.a_move.des=end;
                best=result.a_score;
                sol.a_score=best;
            }
        }
    }

    return sol;
}

#endif