cmake_minimum_required(VERSION 3.24)
project(YukonSolitaire C)

set(CMAKE_C_STANDARD 11)

add_executable(YukonSolitaire main.c loadDeck.c Card.c LinkedListManipulation.c Deck.c
        Board.c Shuffle.c Utilities.c Pile.c moveTests.c GameMove.c)
