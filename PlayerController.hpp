#ifndef PLAYER_CONTROLLER_HPP_INCLUDED
#define PLAYER_CONTROLLER_HPP_INCLUDED

#include "Command.hpp"
#include "Common.hpp"
#include <SFML/Window/Event.hpp>
#include <map>

class PlayerController final
{
public:
        typedef std::unique_ptr<PlayerController> Ptr;

        enum class Action
        {
                MoveRight,
                MoveLeft,
                MoveUp,
                MoveDown,
        };

public:
        PlayerController(Entity player);

        void handleRealtimeInput(CommandQueue& commandQueue);

        void assignKey(Action action, sf::Keyboard::Key key);
        sf::Keyboard::Key getAssignedKey(Action action) const;

private:
        void initKeyBinding();
        void initActionBinding();

private:
        Entity mPlayer;

        std::map<sf::Keyboard::Key, Action> mKeyBinding;
        std::map<Action, Command> mActionBinding;
};

#endif // PLAYER_CONTROLLER_HPP_INCLUDED
