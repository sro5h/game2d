#include "PlayerController.hpp"
#include "CommandQueue.hpp"
#include "MoveCommand.hpp"
#include "Position.hpp"

PlayerController::PlayerController(Entity player)
        : mPlayer(player)
{
        initKeyBinding();
        initActionBinding();
}

void PlayerController::handleRealtimeInput(CommandQueue& commandQueue)
{
        for (auto pair: mKeyBinding)
        {
                if (sf::Keyboard::isKeyPressed(pair.first))
                {
                        commandQueue.push(mActionBinding[pair.second]);
                }
        }
}

void PlayerController::assignKey(Action action, sf::Keyboard::Key key)
{
        for (auto it = mKeyBinding.begin(); it != mKeyBinding.end();)
        {
                if (it->second == action)
                        it = mKeyBinding.erase(it);
                else
                        ++it;
        }

        mKeyBinding[key] = action;
}

sf::Keyboard::Key PlayerController::getAssignedKey(Action action) const
{
        for (auto pair: mKeyBinding)
        {
                if (pair.second == action)
                        return pair.first;
        }

        return sf::Keyboard::Unknown;
}

void PlayerController::initKeyBinding()
{
        mKeyBinding[sf::Keyboard::D] = Action::MoveRight;
        mKeyBinding[sf::Keyboard::A] = Action::MoveLeft;
        mKeyBinding[sf::Keyboard::W] = Action::MoveUp;
        mKeyBinding[sf::Keyboard::S] = Action::MoveDown;
}

void PlayerController::initActionBinding()
{
        const float speed = 1.0f;

        mActionBinding[Action::MoveRight].action = MoveCommand(mPlayer, speed, 0.0f);
        mActionBinding[Action::MoveLeft].action = MoveCommand(mPlayer, -speed, 0.0f);
        mActionBinding[Action::MoveUp].action = MoveCommand(mPlayer, 0.0f, speed);
        mActionBinding[Action::MoveDown].action = MoveCommand(mPlayer, 0.0f, -speed);
}
