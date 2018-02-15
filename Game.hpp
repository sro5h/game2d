#ifndef GAME_HPP_INCLUDED
#define GAME_HPP_INCLUDED

#include "CommandQueue.hpp"
#include "Common.hpp"
#include "PlayerController.hpp"
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
        void processInput();
        void updateView();
        void terminate();
        void createObstacle(float x, float y, float r);
        void registerSystems();

private:
        sf::RenderWindow mWindow;

        Registry mRegistry;
        CommandQueue mCommandQueue;
        std::vector<System::Ptr> mFixedSystems;
        std::vector<System::Ptr> mRenderSystems;

        Entity mPlayer;
        PlayerController::Ptr mPlayerController;

        float mRotation;
        bool mIsRunning;
};

#endif // GAME_HPP_INCLUDED
