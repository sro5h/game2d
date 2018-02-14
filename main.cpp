#include "Game.hpp"

int main()
{
        Game game;

        sf::Clock clock;
        sf::Time accumulator;
        sf::Time elapsed;

        while (game.isRunning())
        {
                elapsed = clock.restart();
                accumulator += elapsed;

                const sf::Time timeStep = game.getTimeStep();
                while (accumulator >= timeStep)
                {
                        accumulator -= timeStep;

                        game.update(timeStep);
                }

                game.render(elapsed);
        }

        return 0;
}
