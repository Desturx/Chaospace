#pragma once

//Headers
#include <Menu.h>


class MainMenu : public Menu
{

    private:
        unsigned int titulo;

    public:
        MainMenu() : Menu()
        {   
            //Buttons
            Button* button = new Button(1, (char*)"resources/MenuElements/PLAY2.png", 
                                                (char*)"resources/MenuElements/PLAY1.png", 540, 300);

            buttons.push_back(button);            

            button = new Button(2, (char*)"resources/MenuElements/EXIT2.png",
                                                (char*)"resources/MenuElements/EXIT1.png", 540, 540);
            buttons.push_back(button);
            
            buttons.at(focus)->focus();

            button = new Button(3, (char*)"resources/MenuElements/CONTROLS2.png",
                                                (char*)"resources/MenuElements/CONTROLS1.png", 540, 420);
            buttons.push_back(button);

            titulo = Render::getInstance() -> createSprite("resources/Titulo.png");
            background = Render::getInstance() -> createSprite("resources/MenuElements/BACKGROUND_menu.png");

        }

        ~MainMenu()
        {
        }

        void draw(){
            Menu::draw();
            Render::getInstance()->drawSprite(titulo, Rvect(540,130), 0.f, 1.f, true);
        }

        void clear(){
            Menu::clear();
            Render::getInstance()->deleteSprite(titulo);
        }

};