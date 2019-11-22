#ifndef PIECE_HPP
#define PIECE_HPP

#include <iostream>
#include <vector>

using namespace std;

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
};

class King:public Piece{
public:
    King(PieceColor color){
        this->type=king;
        this->color=color;
        this->value=100;

    }
    void print(){
        if(get_color()==white){
            cout<<"K ";
        }else{
            cout<<"k ";
        }
    }
};


#endif