
class GameLevel {
    public:
        GameLevel(int width, int height, float gen, int enemis);
        int getWidth();
        int getHeight();
        float getGen();
        int getEnemis();

    private:
        int m_width;
        int m_height;
        float m_gen;
        int m_enemis;
};