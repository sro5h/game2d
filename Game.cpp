#include "Game.hpp"
#include "Body.hpp"
#include "DebugRenderSystem.hpp"
#include "PhysicsSystem.hpp"
#include "PlayerController.hpp"
#include "Position.hpp"
#include <SFML/Window/Event.hpp>

Game::Game()
        : mWindow(sf::VideoMode(500, 500), "App")
        , mPlayer(0)
        , mPlayerController(nullptr)
        , mRotation(0.0f)
        , mIsRunning(true)
{
        registerSystems();

        createPlayer();
        createObstacle(-100, -150, 30);
        createObstacle(100, 150, 50);

        mPlayerController = std::make_unique<PlayerController>(mPlayer);
}

Game::~Game()
{
        terminate();
}

void Game::update(const sf::Time)
{
        processInput();

        while (!mCommandQueue.isEmpty())
        {
                mCommandQueue.pop().action(mRegistry);
        }

        for (System::Ptr& system: mFixedSystems)
        {
                system->update();
        }

        updateView();
}

void Game::render(const sf::Time)
{
        mWindow.clear();

        for (System::Ptr& system: mRenderSystems)
        {
                system->update();
        }

        mWindow.display();
}

void Game::processInput()
{
        sf::Event event;
        while (mWindow.pollEvent(event))
        {
                if (event.type == sf::Event::Closed)
                        terminate();
        }

        mPlayerController->handleRealtimeInput(mCommandQueue);
}

void Game::updateView()
{
        Position& position = mRegistry.get<Position>(mPlayer);

        sf::View view = mWindow.getView();
        view.setSize(500, -500);
        view.setCenter(position.position);
        mWindow.setView(view);
}

void Game::terminate()
{
        if (mIsRunning)
        {
                mIsRunning = false;
                mWindow.close();
        }
}

void Game::registerSystems()
{
        mFixedSystems.push_back(std::make_unique<PhysicsSystem>(mRegistry));

        mRenderSystems.push_back(std::make_unique<DebugRenderSystem>(
                                mRegistry, mWindow));
}

void Game::createPlayer()
{
        mPlayer = mRegistry.create();
        mRegistry.assign<Position>(mPlayer, 0.0f, 0.0f);
        Body& body = mRegistry.assign<Body>(mPlayer);
        body.shape = std::make_unique<Circle>(20.0f);
        body.dynamic = true;
}

void Game::createObstacle(float x, float y, float r)
{
        Entity e = mRegistry.create();
        mRegistry.assign<Position>(e, x, y);
        Body& body = mRegistry.assign<Body>(e);
        body.shape = std::make_unique<Circle>(r);
}

sf::Time Game::getTimeStep() const
{
        return sf::microseconds(15625);
}

bool Game::isRunning() const
{
        return mIsRunning;
}
