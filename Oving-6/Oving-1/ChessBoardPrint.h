//
// Created by jerry on 10/6/2023.
//

#ifndef CHESSBOARDPRINT_H
#define CHESSBOARDPRINT_H


#include "ChessBoard.h"

#include "ChessBoard.h"

class ChessBoardPrint {
private:
    ChessBoard& board;
public:
    ChessBoardPrint(ChessBoard& b) : board(b) {
        board.after_piece_move = [&](const std::string& message, bool shouldPrint) {
            if (shouldPrint) {
                this->print_board();
            }
            this->handle_message(message);
        };
    }


    void handle_message(const std::string& message) {
        std::cout << message << std::endl;
    }

    void print_board() const {
        std::cout << "  Black side" << std::endl;
        for (int y = 7; y >= 0; y--) {
            for (int x = 0; x < 8; x++) {
                if (board.squares[x][y]) {
                    std::cout << board.squares[x][y]->symbol() << " ";
                } else {
                    std::cout << ". ";
                }
            }
            std::cout << std::endl;
        }
        std::cout << "  White side" << std::endl;
    }
};



#endif // CHESSBOARDPRINT_H
