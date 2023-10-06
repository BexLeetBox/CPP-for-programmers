#include <iostream>
#include <memory>
#include <string>
#include <vector>
#include <functional>


#ifndef CHESSBOARD_H
#define CHESSBOARD_H

using namespace std;
class ChessBoardPrint;


class ChessBoard {
public:
    enum class Color { WHITE,
        BLACK };

    // Functor to be called after each piece move
    mutable std::function<void(const std::string&, bool)> after_piece_move;



    class Piece {
    public:
        Piece(Color color) : color(color) {}
        virtual ~Piece() {}

        Color color;
        std::string color_string() const {
            if (color == Color::WHITE)
                return "white";
            else
                return "black";
        }

        /// Return color and type of the chess piece
        virtual std::string type() const = 0;

        /// Returns true if the given chess piece move is valid
        virtual bool valid_move(int from_x, int from_y, int to_x, int to_y) const = 0;

        virtual std::string symbol() const = 0;
    };

    class King : public Piece {

    public:

        King(Color color) : Piece(color){}

        virtual std::string symbol() const override {
            return color == Color::WHITE ? "K" : "k";
        }

        bool valid_move(int from_x, int from_y, int to_x, int to_y) const override{
            int dx = abs(from_x - to_x);
            int dy = abs(from_y - to_y);

            return(dx <= 1 && dy <=1);
        }


        std::string type() const override{
            return "king";
        }
    };

    class Knight : public Piece {

    public:

        Knight(Color color) : Piece(color){}

        virtual std::string symbol() const override {
            return color == Color::WHITE ? "N" : "n";
        }

        std::string type() const override{
            return "knight";
        }

        bool valid_move(int from_x, int from_y, int to_x, int to_y) const override{
            int dx = abs(from_x - to_x);
            int dy = abs(from_y - to_y);

            return ((dx == 2 && dy == 1) || (dx == 1 && dy == 2));
        }
    };

    ChessBoard() {
        // Initialize the squares stored in 8 columns and 8 rows:
        squares.resize(8);
        for (auto &square_column : squares)
            square_column.resize(8);
    }

    /// 8x8 squares occupied by 1 or 0 chess pieces
    vector<vector<unique_ptr<Piece>>> squares;

    /// Move a chess piece if it is a valid move.
    /// Does not test for check or checkmate.
    bool move_piece(const std::string &from, const std::string &to) {
        int from_x = from[0] - 'a';
        int from_y = stoi(string() + from[1]) - 1;
        int to_x = to[0] - 'a';
        int to_y = stoi(string() + to[1]) - 1;

        auto &piece_from = squares[from_x][from_y];
        if (piece_from) {
            if (piece_from->valid_move(from_x, from_y, to_x, to_y)) {
               // cout << piece_from->color_string() << " " << piece_from->type() << " is moving from " << from << " to " << to << endl;



                if (after_piece_move) after_piece_move(piece_from->color_string() + " " + piece_from->type()
                + " is moving from " + from + " to " + to, true);

                auto &piece_to = squares[to_x][to_y];
                bool dead = false;
                if (piece_to) {
                    if (piece_from->color != piece_to->color) {
                        if (after_piece_move) after_piece_move(piece_to->color_string() + " " + piece_to->type()
                        + " is being removed from " + to, false);
                        if (auto king = dynamic_cast<King *>(piece_to.get())) {
                            if (after_piece_move) after_piece_move(king->color_string() + " lost the game", false);
                            dead = true;
                        }
                    } else {
                        if (after_piece_move) after_piece_move("can not move " + piece_from->color_string() +
                        " " + piece_from->type() + " from " + from + " to " + to, false);
                        return false;
                    }
                }

                piece_to = move(piece_from);
                if (after_piece_move && dead) after_piece_move("", true); //just to print last change
                return true;
            } else {
                //cout << "can not move " << piece_from->color_string() << " " << piece_from->type() << " from " << from << " to " << to << endl;
                if (after_piece_move) after_piece_move("can not move " + piece_from->color_string()
                + " " + piece_from->type() + " from " + from + " to " + to, false);
                return false;
            }
        } else {
            //cout << "no piece at " << from << endl;
            if (after_piece_move) after_piece_move( "no piece at " + from, false);
            return false;
        }
    }

};

#endif // CHESSBOARD_H