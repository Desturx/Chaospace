#pragma once


enum BoundingBox
{
    NOCOLIDER,
    CIRCLE,
    RECTANGLE
};
struct Pvect
{
    float x;
    float y;
    Pvect(){this->x = 0.f; this->y = 0.f;}
    Pvect(float x,float y){this->x = x; this->y = y;}
};
class Physics
{
    private:

        Pvect position;
        float orient;
        Pvect velocity;

        BoundingBox type;

        Pvect dimensions;
        float radious;

    public:

        /*
        Constructores y destructores
        */
        Physics();
        Physics(Pvect position);

        /*
        Getters & Setters
        */
        void setPosition(Pvect position);
        Pvect getPosition();

        void setVelocity(Pvect velocity);
        void setPolarVelocity(float orient, float velocity);
        Pvect getPolarVelocity();
        Pvect getVelocity();

        void setOrient(float orient);
        float getOrient();

        /*
        Funciones relativas al bb
        */
        void setCircleBB(float radious);
        void setRectangleBB(Pvect dimensions);
        BoundingBox getBBType();
        float getRadious();
        Pvect getDimensions();

        /*
        Funciones relativas al sistema
        */
        void update(float dt);

        bool colides(Physics* target);

        void moveBack();
};