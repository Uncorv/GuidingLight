
#include "GameLevel.h"

GameLevel::GameLevel(int width, int height, float gen, int enemis) {
    m_width = width;
    m_height = height;
    m_gen = gen;
    m_enemis = enemis;
}

int GameLevel::getWidth() {
    return m_width;
}

int GameLevel::getHeight() {
    return m_height;
}

float GameLevel::getGen() {
    return m_gen;
}

int GameLevel::getEnemis() {
    return m_enemis;
}
