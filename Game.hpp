#ifndef GAME_HPP_INCLUDED
#define GAME_HPP_INCLUDED

#include "Common.hpp"
#include "System.hpp"
#include <SFML/Graphics/RenderWindow.hpp>
#include <vector>

class Game final
{
public:
        Game();
        ~Game();

        void update(const sf::Time delta);
        void render(const sf::Time delta);

        sf::Time getTimeStep() const;
        bool isRunning() const;

private:
        void handleInput();
        void updateView();
        void terminate();
        void addObstacle(float x, float y, float r);
        void registerSystems();

private:
        sf::RenderWindow mWindow;

        Registry mRegistry;
        std::vector<System::Ptr> mFixedSystems;
        std::vector<System::Ptr> mRenderSystems;

        Entity mPlayer;

        float mRotation;
        bool mIsRunning;
};

#endif // GAME_HPP_INCLUDED
