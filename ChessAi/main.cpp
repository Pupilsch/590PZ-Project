#include <iostream>
#include "board.hpp"
#include <vector>

using namespace std;

int main(){
    Board *b=new Board();
    //b->init_place();
    b->print();
    //cout<<b->evaluate();
    char in;
    cout<<"choose to play white or balck [w/b]:";
    cin>>in;
    
    //PieceColor color=white;

    while(true){
        // if(b->if_lose(white)) cout<<"Game ends! Black wins."<<endl;
        // if(b->if_lose(black)) cout<<"Game ends! White wins."<<endl;
        // if(b->if_draw(white) || b->if_draw(black))
        int x1,y1,x2,y2;
        move_t go;
        if(in=='w'){
            cout<<"please enter your move by 4 numbers. From (0,1) to (2,3) is 0 1 2 3:";
            cin>>x1>>y1>>x2>>y2;
            go.src.r=x1;
            go.src.c=y1;
            go.des.r=x2;
            go.des.c=y2;
            b->human_move(go);
            b->print();
        }
        go=b->minimax(MAX_DEPTH).a_move;
        b->human_move(go);
        b->print();
        //judge if game ends.
        if(b->white_now){
            if(b->if_lose(white)){
                cout<<"Game ends! Black wins."<<endl;
                break;
            }
            if(b->if_draw(white)){
                cout<<"Draw! "<<endl;
                break;
            }
        }else{
            if(b->if_lose(black)){
                cout<<"Game ends! White wins."<<endl;
                break;
            }
            if(b->if_draw(black)){
                cout<<"Draw! "<<endl;
                break;
            }
        }
        //Human turn
        cout<<"please enter your move by 4 numbers. From (0,1) to (2,3) is 0 1 2 3:";
        cin>>x1>>y1>>x2>>y2;
        go.src.r=x1;
        go.src.c=y1;
        go.des.r=x2;
        go.des.c=y2;
        b->human_move(go);
        b->print();
        //judge if game ends
        if(b->white_now){
            if(b->if_lose(white)){
                cout<<"Game ends! Black wins."<<endl;
                break;
            }
            if(b->if_draw(white)){
                cout<<"Draw! "<<endl;
                break;
            }
        }else{
            if(b->if_lose(black)){
                cout<<"Game ends! White wins."<<endl;
                break;
            }
            if(b->if_draw(black)){
                cout<<"Draw! "<<endl;
                break;
            }
        }
    }
    return 0;
}