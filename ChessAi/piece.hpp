#ifndef PIECE_HPP
#define PIECE_HPP

#include <iostream>
#include <vector>
#include <windows.h>
#include <wchar.h>

using namespace std;


#define PAWN 0
#define ROOK 1
#define KNIGHT 2
#define BISHOP 3
#define KING 4

enum PieceColor {
	white, black
};
enum PieceType {
	pawn, rock, bishop, knight, queen, king
};

class Piece{
public:
    virtual void print()=0;
    //virtual void get_possible_move()=0;
    PieceColor get_color(){
        return color;
    }
    PieceType get_type(){
        return type;
    }
    int value;

protected:
    PieceType type;
    PieceColor color;
};

class Pawn:public Piece{
public:
    Pawn(PieceColor color){
        this->type=pawn;
        this->color=color;
        this->value=1;
        
    }
    void print(){
        if(get_color()==white){
            cout<<"P ";
        }else{
            cout<<"p ";
        }
    }
    // void get_possible_move(){
    //     //vector<vector<Piece*>> parent->grid=parent->grid;
    //     if(this->color==white){
    //         int r=this->position.r;
    //         int c=this->position.c;
    //         if(r!=4 && parent->grid[r+1][c]==NULL){
    //             point_t p;
    //             p.r=r+1;
    //             p.c=c;
    //             move_list.push_back(p);
    //         }
    //         if(r!=4 && c==0){
    //             if(parent->grid[r+1][c+1]->get_color()==black){
    //                 point_t p;
    //                 p.r=r+1;
    //                 p.c=c+1;
    //                 move_list.push_back(p);
    //             }
    //         }
    //         if(r!=4 && c==3){
    //             if(parent->grid[r+1][c-1]->get_color()==black){
    //                 point_t p;
    //                 p.r=r+1;
    //                 p.c=c-1;
    //                 move_list.push_back(p);
    //             }
    //         }
    //     }
    //     if(this->color==black){
    //         int r=this->position.r;
    //         int c=this->position.c;
    //         if(r!=0 && parent->grid[r-1][c]==NULL){
    //             point_t p;
    //             p.r=r-1;
    //             p.c=c;
    //             move_list.push_back(p);
    //         }
    //         if(r!=0 && c==0){
    //             if(parent->grid[r-1][c+1]->get_color()==black){
    //                 point_t p;
    //                 p.r=r-1;
    //                 p.c=c+1;
    //                 move_list.push_back(p);
    //             }
    //         }
    //         if(r!=0 && c==3){
    //             if(parent->grid[r-1][c-1]->get_color()==black){
    //                 point_t p;
    //                 p.r=r-1;
    //                 p.c=c-1;
    //                 move_list.push_back(p);
    //             }
    //         }
    //     }
    // }
};

class Rock:public Piece{
public:
    Rock(PieceColor color){
        this->type=rock;
        this->color=color;
        this->value=5;
        
    }
    void print(){
        if(get_color()==white){
            cout<<"R ";
        }else{
            cout<<"r ";
        }
    }
    // void get_possible_move(){
    //     //vector<vector<Piece*>> parent->grid=parent->grid;
    //     int r=position.r;
    //     int c=position.c;
    //     //serach east
    //     while(c!=3){
    //         if(parent->grid[r][c+1]==NULL){
    //             point_t p;
    //             p.r=r;
    //             p.c=c+1;
    //             move_list.push_back(p);
    //             c++;
    //             continue;
    //         }
    //         if(parent->grid[r][c+1]->get_color()==this->color){
    //             break;
    //         }
    //         if(parent->grid[r][c+1]->get_color()!=this->color){
    //             point_t p;
    //             p.r=r;
    //             p.c=c+1;
    //             move_list.push_back(p);
    //             break;
    //         }
    //     }
    //     //search south
    //     while(r!=4){
    //         if(parent->grid[r+1][c]==NULL){
    //             point_t p;
    //             p.r=r+1;
    //             p.c=c;
    //             move_list.push_back(p);
    //             r++;
    //             continue;
    //         }
    //         if(parent->grid[r+1][c]->get_color()==this->color){
    //             break;
    //         }
    //         if(parent->grid[r+1][c]->get_color()!=this->color){
    //             point_t p;
    //             p.r=r+1;
    //             p.c=c;
    //             move_list.push_back(p);
    //             break;
    //         }
    //     }
    //     //search west
    //     while(c!=0){
    //         if(parent->grid[r][c-1]==NULL){
    //             point_t p;
    //             p.r=r;
    //             p.c=c-1;
    //             move_list.push_back(p);
    //             c--;
    //             continue;
    //         }
    //         if(parent->grid[r][c-1]->get_color()==this->color){
    //             break;
    //         }
    //         if(parent->grid[r][c-1]->get_color()!=this->color){
    //             point_t p;
    //             p.r=r;
    //             p.c=c-1;
    //             move_list.push_back(p);
    //             break;
    //         }
    //     }
    //     //search north
    //     while(r!=0){
    //         if(parent->grid[r-1][c]==NULL){
    //             point_t p;
    //             p.r=r-1;
    //             p.c=c;
    //             move_list.push_back(p);
    //             r--;
    //             continue;
    //         }
    //         if(parent->grid[r-1][c]->get_color()==this->color){
    //             break;
    //         }
    //         if(parent->grid[r-1][c]->get_color()!=this->color){
    //             point_t p;
    //             p.r=r-1;
    //             p.c=c;
    //             move_list.push_back(p);
    //             break;
    //         }
    //     }
    // }
};

class Bishop:public Piece{
public:
    Bishop(PieceColor color){
        this->type=bishop;
        this->color=color;
        this->value=3;
        
    }
    void print(){
        if(get_color()==white){
            cout<<"B ";
        }else{
            cout<<"b ";
        }
    }
    // void get_possible_move(){
    //     //vector<vector<Piece*>> parent->grid=parent->grid;
    //     int r=position.r;
    //     int c=position.c;
    //     //serach east-north
    //     while(c!=3 && r!=0){
    //         if(parent->grid[r-1][c+1]==NULL){
    //             point_t p;
    //             p.r=r-1;
    //             p.c=c+1;
    //             move_list.push_back(p);
    //             r--;
    //             c++;
    //             continue;
    //         }
    //         if(parent->grid[r-1][c+1]->get_color()==this->color){
    //             break;
    //         }
    //         if(parent->grid[r-1][c+1]->get_color()!=this->color){
    //             point_t p;
    //             p.r=r-1;
    //             p.c=c+1;
    //             move_list.push_back(p);
    //             break;
    //         }
    //     }
    //     //serach east-south
    //     while(c!=3 && r!=4){
    //         if(parent->grid[r+1][c+1]==NULL){
    //             point_t p;
    //             p.r=r+1;
    //             p.c=c+1;
    //             move_list.push_back(p);
    //             r++;
    //             c++;
    //             continue;
    //         }
    //         if(parent->grid[r+1][c+1]->get_color()==this->color){
    //             break;
    //         }
    //         if(parent->grid[r+1][c+1]->get_color()!=this->color){
    //             point_t p;
    //             p.r=r+1;
    //             p.c=c+1;
    //             move_list.push_back(p);
    //             break;
    //         }
    //     }
    //     //serach west-south
    //     while(c!=0 && r!=4){
    //         if(parent->grid[r+1][c-1]==NULL){
    //             point_t p;
    //             p.r=r+1;
    //             p.c=c-1;
    //             move_list.push_back(p);
    //             r++;
    //             c--;
    //             continue;
    //         }
    //         if(parent->grid[r+1][c-1]->get_color()==this->color){
    //             break;
    //         }
    //         if(parent->grid[r+1][c-1]->get_color()!=this->color){
    //             point_t p;
    //             p.r=r+1;
    //             p.c=c-1;
    //             move_list.push_back(p);
    //             break;
    //         }
    //     }
    //     //serach west-north
    //     while(c!=0 && r!=0){
    //         if(parent->grid[r-1][c-1]==NULL){
    //             point_t p;
    //             p.r=r-1;
    //             p.c=c-1;
    //             move_list.push_back(p);
    //             r--;
    //             c--;
    //             continue;
    //         }
    //         if(parent->grid[r-1][c-1]->get_color()==this->color){
    //             break;
    //         }
    //         if(parent->grid[r-1][c-1]->get_color()!=this->color){
    //             point_t p;
    //             p.r=r-1;
    //             p.c=c-1;
    //             move_list.push_back(p);
    //             break;
    //         }
    //     }
    // }
};

class Knight:public Piece{
public:
    Knight(PieceColor color){
        this->type=knight;
        this->color=color;
        this->value=3;
        
    }
    void print(){
        if(get_color()==white){
            cout<<"N ";
        }else{
            cout<<"n ";
        }
    }
    // void get_possible_move(){
        //vector<vector<Piece*>> parent->grid=parent->grid;
        // int r=position.r;
        // int c=position.c;
        // if(r+1<=4 && c+2<=3){
        //     if(parent->grid[r+1][c+2]==NULL){
        //         point_t p;
        //         p.r=r+1;
        //         p.c=c+2;
        //         move_list.push_back(p);
        //     }else{
        //         if(parent->grid[r+1][c+2]->get_color()!=this->color){
        //             point_t p;
        //             p.r=r+1;
        //             p.c=c+2;
        //             move_list.push_back(p);
        //         }
        //     }
        // }
        // if(r+2<=4 && c+1<=3){
        //     if(parent->grid[r+2][c+1]==NULL){
        //         point_t p;
        //         p.r=r+2;
        //         p.c=c+1;
        //         move_list.push_back(p);
        //     }else{
        //         if(parent->grid[r+2][c+1]->get_color()!=this->color){
        //             point_t p;
        //             p.r=r+2;
        //             p.c=c+1;
        //             move_list.push_back(p);
        //         }
        //     }
        // }
        // if(r+2<=4 && c-1>=0){
        //     if(parent->grid[r+2][c-1]==NULL){
        //         point_t p;
        //         p.r=r+2;
        //         p.c=c-1;
        //         move_list.push_back(p);
        //     }else{
        //         if(parent->grid[r+2][c-1]->get_color()!=this->color){
        //             point_t p;
        //             p.r=r+2;
        //             p.c=c-1;
        //             move_list.push_back(p);
        //         }
        //     }
        // }
        // if(r+1<=4 && c-2>=0){
        //     if(parent->grid[r+2][c-2]==NULL){
        //         point_t p;
        //         p.r=r+1;
        //         p.c=c-2;
        //         move_list.push_back(p);
        //     }else{
        //         if(parent->grid[r+1][c-2]->get_color()!=this->color){
        //             point_t p;
        //             p.r=r+1;
        //             p.c=c-2;
        //             move_list.push_back(p);
        //         }
        //     }
        // }
        // if(r-1>=0 && c-2>=0){
        //     if(parent->grid[r-1][c-2]==NULL){
        //         point_t p;
        //         p.r=r-1;
        //         p.c=c-2;
        //         move_list.push_back(p);
        //     }else{
        //         if(parent->grid[r-1][c-2]->get_color()!=this->color){
        //             point_t p;
        //             p.r=r-1;
        //             p.c=c-2;
        //             move_list.push_back(p);
        //         }
        //     }
        // }
        // if(r-2>=0 && c-1>=0){
        //     if(parent->grid[r-2][c-1]==NULL){
        //         point_t p;
        //         p.r=r-2;
        //         p.c=c-1;
        //         move_list.push_back(p);
        //     }else{
        //         if(parent->grid[r-2][c-1]->get_color()!=this->color){
        //             point_t p;
        //             p.r=r-2;
        //             p.c=c-1;
        //             move_list.push_back(p);
        //         }
        //     }
        // }
        // if(r-2>=0 && c+1<=3){
        //     if(parent->grid[r-2][c+1]==NULL){
        //         point_t p;
        //         p.r=r-2;
        //         p.c=c+1;
        //         move_list.push_back(p);
        //     }else{
        //         if(parent->grid[r-2][c+1]->get_color()!=this->color){
        //             point_t p;
        //             p.r=r-2;
        //             p.c=c+1;
        //             move_list.push_back(p);
        //         }
        //     }
        // }
        // if(r-1>=0 && c+2<=3){
        //     if(parent->grid[r-1][c+2]==NULL){
        //         point_t p;
        //         p.r=r-1;
        //         p.c=c+2;
        //         move_list.push_back(p);
        //     }else{
        //         if(parent->grid[r-1][c+2]->get_color()!=this->color){
        //             point_t p;
        //             p.r=r-1;
        //             p.c=c+2;
        //             move_list.push_back(p);
        //         }
        //     }
        // }
    // }
};

class King:public Piece{
public:
    King(PieceColor color){
        this->type=king;
        this->color=color;
        this->value=1000;
        
    }
    void print(){
        if(get_color()==white){
            cout<<"K ";
        }else{
            cout<<"k ";
        }
    }
    // void get_possible_move(){
    //     //vector<vector<Piece*>> parent->grid=parent->grid;
    //     int r=position.r;
    //     int c=position.c;
    //     if(r>=1 && c>=1){
    //         if(parent->grid[r-1][c-1]==NULL){
    //             point_t p;
    //             p.r=r-1;
    //             p.c=c-1;
    //             move_list.push_back(p);
    //         }else{
    //             if(parent->grid[r-1][c-1]->get_color()!=this->color){
    //                 point_t p;
    //                 p.r=r-1;
    //                 p.c=c-1;
    //                 move_list.push_back(p);
    //             }
    //         }
    //     }
    //     if(r>=1){
    //         if(parent->grid[r-1][c]==NULL){
    //             point_t p;
    //             p.r=r-1;
    //             p.c=c;
    //             move_list.push_back(p);
    //         }else{
    //             if(parent->grid[r-1][c]->get_color()!=this->color){
    //                 point_t p;
    //                 p.r=r-1;
    //                 p.c=c;
    //                 move_list.push_back(p);
    //             }
    //         }
    //     }
    //     if(r>=1 && c<=2){
    //         if(parent->grid[r-1][c+1]==NULL){
    //             point_t p;
    //             p.r=r-1;
    //             p.c=c+1;
    //             move_list.push_back(p);
    //         }else{
    //             if(parent->grid[r-1][c+1]->get_color()!=this->color){
    //                 point_t p;
    //                 p.r=r-1;
    //                 p.c=c+1;
    //                 move_list.push_back(p);
    //             }
    //         }
    //     }
    //     if(c<=2){
    //         if(parent->grid[r][c+1]==NULL){
    //             point_t p;
    //             p.r=r;
    //             p.c=c+1;
    //             move_list.push_back(p);
    //         }else{
    //             if(parent->grid[r][c+1]->get_color()!=this->color){
    //                 point_t p;
    //                 p.r=r;
    //                 p.c=c+1;
    //                 move_list.push_back(p);
    //             }
    //         }
    //     }
    //     if(r<=3 && c<=2){
    //         if(parent->grid[r+1][c+1]==NULL){
    //             point_t p;
    //             p.r=r+1;
    //             p.c=c+1;
    //             move_list.push_back(p);
    //         }else{
    //             if(parent->grid[r+1][c+1]->get_color()!=this->color){
    //                 point_t p;
    //                 p.r=r+1;
    //                 p.c=c+1;
    //                 move_list.push_back(p);
    //             }
    //         }
    //     }
    //     if(r<=3){
    //         if(parent->grid[r+1][c]==NULL){
    //             point_t p;
    //             p.r=r+1;
    //             p.c=c;
    //             move_list.push_back(p);
    //         }else{
    //             if(parent->grid[r+1][c]->get_color()!=this->color){
    //                 point_t p;
    //                 p.r=r+1;
    //                 p.c=c;
    //                 move_list.push_back(p);
    //             }
    //         }
    //     }
    //     if(r<=3 && c>=1){
    //         if(parent->grid[r+1][c-1]==NULL){
    //             point_t p;
    //             p.r=r+1;
    //             p.c=c-1;
    //             move_list.push_back(p);
    //         }else{
    //             if(parent->grid[r+1][c-1]->get_color()!=this->color){
    //                 point_t p;
    //                 p.r=r+1;
    //                 p.c=c-1;
    //                 move_list.push_back(p);
    //             }
    //         }
    //     }
    //     if(c>=1){
    //         if(parent->grid[r][c-1]==NULL){
    //             point_t p;
    //             p.r=r;
    //             p.c=c-1;
    //             move_list.push_back(p);
    //         }else{
    //             if(parent->grid[r][c-1]->get_color()!=this->color){
    //                 point_t p;
    //                 p.r=r;
    //                 p.c=c-1;
    //                 move_list.push_back(p);
    //             }
    //         }
    //     }
    // }
};


#endif