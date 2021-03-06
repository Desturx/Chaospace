#pragma once

//External headers
#include <vector>
#include <string>

//Forward declarations
class Player;
class Ship;
class GameObject;
class Bullet;
class Npc;
class PowerUp;
class Hud;
class Asteroid;
class EmptyAnimation;

class Map
{
    private:
        Hud* hud;

        Player* player;
        
        Npc* boss;

        std::vector<Npc*> npcs;
        std::vector<Bullet*> bullets;
        std::vector<PowerUp*> powerUps;
        std::vector<Asteroid*> asteroids;
        std::vector<EmptyAnimation*> animations;

        Map();
        float mapPosition;
        float mapIncPosition;
        unsigned int score = 0;
        unsigned int kills = 0;
        int playerHp = 100;

        int level = -1;
        unsigned int fondoEntrada;
        unsigned int fondoSalida;
        int veces = 0;
        bool mapa1_cargado = false;
        bool sumado = false;
        int tipo_lvl = 0;


        int _score;
        int _level;
    public:

        ~Map();
        
        static Map* getInstance()
        {
            static Map onlyInstance;
            return &onlyInstance;
        }
        bool update(float dt);

        void updateObjects(float dt);

        void updateColisions();

        void clear();

        void init();

        void createNpc();

        void createAsteroid();

        void createBoss();

        void createBullet(float x, float y, float orient, int type, bool fromPlayer);

        void createAnimation(float x, float y, float orient, int type);
        
        Player* createPlayer(float x, float y);

        void createLife(float x, float y);

        void createMaxLife(float x, float y);

        void createSpeed(float x, float y);
       
        void createShield(float x, float y);

        void createWeapon(float x, float y);

        void loadLevel();

        void loadMapInfoEntrada(int lvl);
       
        void loadMapInfoSalida(int lvl);

        void draw();
        
        void changeBackground();

        void drawObjects();

        float getMapIncPosition();
        
        void moveMap(float dx);

        float getPlayerX();

        float getPlayerY();

        void tryCreate();

        int getScore();

        int getLevel();

};
