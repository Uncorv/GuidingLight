
#include "GameState.h"


GameState::GameState() {
    m_nAllFieldsCount = 0;
    m_nVisitedFieldsCount = 0;
}

int GameState::getHash(int x, int y) {
    return x*1000 + y;
}

void GameState::addPath(int x, int y) {
    int hash = getHash(x, y);
    std::map<int, bool>::iterator it = m_visited.find(hash);
    if (it == m_visited.end()) {
        m_visited[hash] = false;
        m_nAllFieldsCount++;
    }
}

int GameState::getAllCount() {
    return m_nAllFieldsCount;
}

int GameState::getVisitedCount() {
    return m_nVisitedFieldsCount;
}

bool GameState::isVisited(int x, int y) {
    int hash = getHash(x, y);
    std::map<int, bool>::iterator it = m_visited.find(hash);
    if (it != m_visited.end()) {
        return it->second;
    }
    return false;
}

bool GameState::updateVisited(int x, int y, bool val) {
    int hash = getHash(x, y);
    std::map<int, bool>::iterator it = m_visited.find(hash);
    if (it != m_visited.end()) {
        if (it->second != val) {
            it->second = val;
            m_nVisitedFieldsCount++;
            return true;
        };
    }
    return false;
}

void GameState::reset() {
    m_visited.clear();
    m_nAllFieldsCount = 0;
    m_nVisitedFieldsCount = 0;
}