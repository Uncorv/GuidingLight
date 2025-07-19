#pragma once

#include <map>
#include <string>

class GameState {
    public:
        GameState();
        int getHash(int x, int y);
        void addPath(int x, int y);
        int getAllCount();
        int getVisitedCount();
        bool isVisited(int x, int y);
        bool updateVisited(int x, int y, bool val);
        void reset();

    private:
        std::map<int, bool> m_visited;
        int m_nAllFieldsCount;
        int m_nVisitedFieldsCount;
};