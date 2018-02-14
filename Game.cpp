#include "Game.hpp"
#include "DebugRenderSystem.hpp"
#include "Body.hpp"
#include "Position.hpp"
#include <SFML/Window/Event.hpp>

Game::Game()
        : mWindow(sf::VideoMode(500, 500), "App")
        , mRotation(0.0f)
        , mIsRunning(true)
{
        registerSystems();
        Entity e = mRegistry.create();
        mRegistry.assign<Position>(e, 0.0f, 0.0f);
        Body& body = mRegistry.assign<Body>(e);
        body.shape = std::make_unique<Circle>(20.0f);

        addObstacle(-100, -150, 30);
        addObstacle(100, 150, 50);
}

Game::~Game()
{
        terminate();
}

void Game::update(const sf::Time)
{
        handleInput();
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

void Game::handleInput()
{
        sf::Event event;
        while (mWindow.pollEvent(event))
        {
                if (event.type == sf::Event::Closed)
                        terminate();
        }

        Position& position = mRegistry.get<Position>(mPlayer);

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
                position.x += 1.0f;

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
                position.x -= 1.0f;

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
                position.y += 1.0f;

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
                position.y -= 1.0f;
}

void Game::updateView()
{
        Position& position = mRegistry.get<Position>(mPlayer);

        sf::View view = mWindow.getView();
        view.setSize(500, -500);
        view.setCenter(position.x, position.y);
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
        mRenderSystems.push_back(std::make_unique<DebugRenderSystem>(
                                mRegistry, mWindow));
}

void Game::addObstacle(float x, float y, float r)
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
