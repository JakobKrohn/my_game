#include "Player/Player.hpp"

#include <iostream>

#include "Logger/Logger.hpp"

using namespace components;

Player::Player(std::string name, std::shared_ptr<Movable_I> movable,
               std::shared_ptr<Sprite_I> sprite)
    : m_name(name), m_movable(movable), m_sprite(sprite), m_isMoving(false)
{
    m_moveTime = std::chrono::system_clock::now();
    auto position = m_movable->getPosition();

    m_sprite->setAngleOffset(270);
    m_sprite->setPosition(position->x, position->y, position->angle);
    // clang-format off
    std::vector<const char *> gunIdle = 
    {
        "assets/Top_Down_Survivor/handgun/idle/survivor-idle_handgun_0.png",
        "assets/Top_Down_Survivor/handgun/idle/survivor-idle_handgun_1.png",
        "assets/Top_Down_Survivor/handgun/idle/survivor-idle_handgun_2.png",
        "assets/Top_Down_Survivor/handgun/idle/survivor-idle_handgun_3.png",
        "assets/Top_Down_Survivor/handgun/idle/survivor-idle_handgun_4.png",
        "assets/Top_Down_Survivor/handgun/idle/survivor-idle_handgun_5.png",
        "assets/Top_Down_Survivor/handgun/idle/survivor-idle_handgun_6.png",
        "assets/Top_Down_Survivor/handgun/idle/survivor-idle_handgun_7.png",
        "assets/Top_Down_Survivor/handgun/idle/survivor-idle_handgun_8.png",
        "assets/Top_Down_Survivor/handgun/idle/survivor-idle_handgun_9.png",
        "assets/Top_Down_Survivor/handgun/idle/survivor-idle_handgun_10.png",
        "assets/Top_Down_Survivor/handgun/idle/survivor-idle_handgun_11.png",
        "assets/Top_Down_Survivor/handgun/idle/survivor-idle_handgun_12.png",
        "assets/Top_Down_Survivor/handgun/idle/survivor-idle_handgun_13.png",
        "assets/Top_Down_Survivor/handgun/idle/survivor-idle_handgun_14.png",
        "assets/Top_Down_Survivor/handgun/idle/survivor-idle_handgun_15.png",
        "assets/Top_Down_Survivor/handgun/idle/survivor-idle_handgun_16.png",
        "assets/Top_Down_Survivor/handgun/idle/survivor-idle_handgun_17.png",
        "assets/Top_Down_Survivor/handgun/idle/survivor-idle_handgun_18.png",
        "assets/Top_Down_Survivor/handgun/idle/survivor-idle_handgun_19.png",
    };
    std::vector<const char *> gunMove = 
    {
        "assets/Top_Down_Survivor/handgun/move/survivor-move_handgun_0.png",
        "assets/Top_Down_Survivor/handgun/move/survivor-move_handgun_1.png",
        "assets/Top_Down_Survivor/handgun/move/survivor-move_handgun_2.png",
        "assets/Top_Down_Survivor/handgun/move/survivor-move_handgun_3.png",
        "assets/Top_Down_Survivor/handgun/move/survivor-move_handgun_4.png",
        "assets/Top_Down_Survivor/handgun/move/survivor-move_handgun_5.png",
        "assets/Top_Down_Survivor/handgun/move/survivor-move_handgun_6.png",
        "assets/Top_Down_Survivor/handgun/move/survivor-move_handgun_7.png",
        "assets/Top_Down_Survivor/handgun/move/survivor-move_handgun_8.png",
        "assets/Top_Down_Survivor/handgun/move/survivor-move_handgun_9.png",
        "assets/Top_Down_Survivor/handgun/move/survivor-move_handgun_10.png",
        "assets/Top_Down_Survivor/handgun/move/survivor-move_handgun_11.png",
        "assets/Top_Down_Survivor/handgun/move/survivor-move_handgun_12.png",
        "assets/Top_Down_Survivor/handgun/move/survivor-move_handgun_13.png",
        "assets/Top_Down_Survivor/handgun/move/survivor-move_handgun_14.png",
        "assets/Top_Down_Survivor/handgun/move/survivor-move_handgun_15.png",
        "assets/Top_Down_Survivor/handgun/move/survivor-move_handgun_16.png",
        "assets/Top_Down_Survivor/handgun/move/survivor-move_handgun_17.png",
        "assets/Top_Down_Survivor/handgun/move/survivor-move_handgun_18.png",
        "assets/Top_Down_Survivor/handgun/move/survivor-move_handgun_19.png",
    };
    std::vector<const char *> gunShoot = 
    {
        "assets/Top_Down_Survivor/handgun/shoot/survivor-shoot_handgun_0.png",
        "assets/Top_Down_Survivor/handgun/shoot/survivor-shoot_handgun_1.png",
        "assets/Top_Down_Survivor/handgun/shoot/survivor-shoot_handgun_2.png",
    };

    std::vector<const char *> rifleIdle = 
    {
        "assets/Top_Down_Survivor/rifle/idle/survivor-idle_rifle_0.png",
        "assets/Top_Down_Survivor/rifle/idle/survivor-idle_rifle_1.png",
        "assets/Top_Down_Survivor/rifle/idle/survivor-idle_rifle_2.png",
        "assets/Top_Down_Survivor/rifle/idle/survivor-idle_rifle_3.png",
        "assets/Top_Down_Survivor/rifle/idle/survivor-idle_rifle_4.png",
        "assets/Top_Down_Survivor/rifle/idle/survivor-idle_rifle_5.png",
        "assets/Top_Down_Survivor/rifle/idle/survivor-idle_rifle_6.png",
        "assets/Top_Down_Survivor/rifle/idle/survivor-idle_rifle_7.png",
        "assets/Top_Down_Survivor/rifle/idle/survivor-idle_rifle_8.png",
        "assets/Top_Down_Survivor/rifle/idle/survivor-idle_rifle_9.png",
        "assets/Top_Down_Survivor/rifle/idle/survivor-idle_rifle_10.png",
        "assets/Top_Down_Survivor/rifle/idle/survivor-idle_rifle_11.png",
        "assets/Top_Down_Survivor/rifle/idle/survivor-idle_rifle_12.png",
        "assets/Top_Down_Survivor/rifle/idle/survivor-idle_rifle_13.png",
        "assets/Top_Down_Survivor/rifle/idle/survivor-idle_rifle_14.png",
        "assets/Top_Down_Survivor/rifle/idle/survivor-idle_rifle_15.png",
        "assets/Top_Down_Survivor/rifle/idle/survivor-idle_rifle_16.png",
        "assets/Top_Down_Survivor/rifle/idle/survivor-idle_rifle_17.png",
        "assets/Top_Down_Survivor/rifle/idle/survivor-idle_rifle_18.png",
        "assets/Top_Down_Survivor/rifle/idle/survivor-idle_rifle_19.png",
    };
    std::vector<const char *> rifleMove = 
    {
        "assets/Top_Down_Survivor/rifle/move/survivor-move_rifle_0.png",
        "assets/Top_Down_Survivor/rifle/move/survivor-move_rifle_1.png",
        "assets/Top_Down_Survivor/rifle/move/survivor-move_rifle_2.png",
        "assets/Top_Down_Survivor/rifle/move/survivor-move_rifle_3.png",
        "assets/Top_Down_Survivor/rifle/move/survivor-move_rifle_4.png",
        "assets/Top_Down_Survivor/rifle/move/survivor-move_rifle_5.png",
        "assets/Top_Down_Survivor/rifle/move/survivor-move_rifle_6.png",
        "assets/Top_Down_Survivor/rifle/move/survivor-move_rifle_7.png",
        "assets/Top_Down_Survivor/rifle/move/survivor-move_rifle_8.png",
        "assets/Top_Down_Survivor/rifle/move/survivor-move_rifle_9.png",
        "assets/Top_Down_Survivor/rifle/move/survivor-move_rifle_10.png",
        "assets/Top_Down_Survivor/rifle/move/survivor-move_rifle_11.png",
        "assets/Top_Down_Survivor/rifle/move/survivor-move_rifle_12.png",
        "assets/Top_Down_Survivor/rifle/move/survivor-move_rifle_13.png",
        "assets/Top_Down_Survivor/rifle/move/survivor-move_rifle_14.png",
        "assets/Top_Down_Survivor/rifle/move/survivor-move_rifle_15.png",
        "assets/Top_Down_Survivor/rifle/move/survivor-move_rifle_16.png",
        "assets/Top_Down_Survivor/rifle/move/survivor-move_rifle_17.png",
        "assets/Top_Down_Survivor/rifle/move/survivor-move_rifle_18.png",
        "assets/Top_Down_Survivor/rifle/move/survivor-move_rifle_19.png",
    };
    std::vector<const char *> rifleReload = 
    {
        "assets/Top_Down_Survivor/rifle/reload/survivor-reload_rifle_0.png",
        "assets/Top_Down_Survivor/rifle/reload/survivor-reload_rifle_1.png",
        "assets/Top_Down_Survivor/rifle/reload/survivor-reload_rifle_2.png",
        "assets/Top_Down_Survivor/rifle/reload/survivor-reload_rifle_3.png",
        "assets/Top_Down_Survivor/rifle/reload/survivor-reload_rifle_4.png",
        "assets/Top_Down_Survivor/rifle/reload/survivor-reload_rifle_5.png",
        "assets/Top_Down_Survivor/rifle/reload/survivor-reload_rifle_6.png",
        "assets/Top_Down_Survivor/rifle/reload/survivor-reload_rifle_7.png",
        "assets/Top_Down_Survivor/rifle/reload/survivor-reload_rifle_8.png",
        "assets/Top_Down_Survivor/rifle/reload/survivor-reload_rifle_9.png",
        "assets/Top_Down_Survivor/rifle/reload/survivor-reload_rifle_10.png",
        "assets/Top_Down_Survivor/rifle/reload/survivor-reload_rifle_11.png",
        "assets/Top_Down_Survivor/rifle/reload/survivor-reload_rifle_12.png",
        "assets/Top_Down_Survivor/rifle/reload/survivor-reload_rifle_13.png",
        "assets/Top_Down_Survivor/rifle/reload/survivor-reload_rifle_14.png",
        "assets/Top_Down_Survivor/rifle/reload/survivor-reload_rifle_15.png",
        "assets/Top_Down_Survivor/rifle/reload/survivor-reload_rifle_16.png",
        "assets/Top_Down_Survivor/rifle/reload/survivor-reload_rifle_17.png",
        "assets/Top_Down_Survivor/rifle/reload/survivor-reload_rifle_18.png",
        "assets/Top_Down_Survivor/rifle/reload/survivor-reload_rifle_19.png",
    };
    std::vector<const char *> rifleShoot = 
    {
        "assets/Top_Down_Survivor/rifle/shoot/survivor-shoot_rifle_0.png",
        "assets/Top_Down_Survivor/rifle/shoot/survivor-shoot_rifle_1.png",
        "assets/Top_Down_Survivor/rifle/shoot/survivor-shoot_rifle_2.png",
    };

    std::vector<const char *> knifeIdle = 
    {
        "assets/Top_Down_Survivor/knife/idle/survivor-idle_knife_0.png",
        "assets/Top_Down_Survivor/knife/idle/survivor-idle_knife_1.png",
        "assets/Top_Down_Survivor/knife/idle/survivor-idle_knife_2.png",
        "assets/Top_Down_Survivor/knife/idle/survivor-idle_knife_3.png",
        "assets/Top_Down_Survivor/knife/idle/survivor-idle_knife_4.png",
        "assets/Top_Down_Survivor/knife/idle/survivor-idle_knife_5.png",
        "assets/Top_Down_Survivor/knife/idle/survivor-idle_knife_6.png",
        "assets/Top_Down_Survivor/knife/idle/survivor-idle_knife_7.png",
        "assets/Top_Down_Survivor/knife/idle/survivor-idle_knife_8.png",
        "assets/Top_Down_Survivor/knife/idle/survivor-idle_knife_9.png",
        "assets/Top_Down_Survivor/knife/idle/survivor-idle_knife_10.png",
        "assets/Top_Down_Survivor/knife/idle/survivor-idle_knife_11.png",
        "assets/Top_Down_Survivor/knife/idle/survivor-idle_knife_12.png",
        "assets/Top_Down_Survivor/knife/idle/survivor-idle_knife_13.png",
        "assets/Top_Down_Survivor/knife/idle/survivor-idle_knife_14.png",
        "assets/Top_Down_Survivor/knife/idle/survivor-idle_knife_15.png",
        "assets/Top_Down_Survivor/knife/idle/survivor-idle_knife_16.png",
        "assets/Top_Down_Survivor/knife/idle/survivor-idle_knife_17.png",
        "assets/Top_Down_Survivor/knife/idle/survivor-idle_knife_18.png",
        "assets/Top_Down_Survivor/knife/idle/survivor-idle_knife_19.png",
    };
    std::vector<const char *> knifeMove = 
    {
        "assets/Top_Down_Survivor/knife/move/survivor-move_knife_0.png",
        "assets/Top_Down_Survivor/knife/move/survivor-move_knife_1.png",
        "assets/Top_Down_Survivor/knife/move/survivor-move_knife_2.png",
        "assets/Top_Down_Survivor/knife/move/survivor-move_knife_3.png",
        "assets/Top_Down_Survivor/knife/move/survivor-move_knife_4.png",
        "assets/Top_Down_Survivor/knife/move/survivor-move_knife_5.png",
        "assets/Top_Down_Survivor/knife/move/survivor-move_knife_6.png",
        "assets/Top_Down_Survivor/knife/move/survivor-move_knife_7.png",
        "assets/Top_Down_Survivor/knife/move/survivor-move_knife_8.png",
        "assets/Top_Down_Survivor/knife/move/survivor-move_knife_9.png",
        "assets/Top_Down_Survivor/knife/move/survivor-move_knife_10.png",
        "assets/Top_Down_Survivor/knife/move/survivor-move_knife_11.png",
        "assets/Top_Down_Survivor/knife/move/survivor-move_knife_12.png",
        "assets/Top_Down_Survivor/knife/move/survivor-move_knife_13.png",
        "assets/Top_Down_Survivor/knife/move/survivor-move_knife_14.png",
        "assets/Top_Down_Survivor/knife/move/survivor-move_knife_15.png",
        "assets/Top_Down_Survivor/knife/move/survivor-move_knife_16.png",
        "assets/Top_Down_Survivor/knife/move/survivor-move_knife_17.png",
        "assets/Top_Down_Survivor/knife/move/survivor-move_knife_18.png",
        "assets/Top_Down_Survivor/knife/move/survivor-move_knife_19.png",
    };
    std::vector<const char *> knifeShoot = 
    {
        "assets/Top_Down_Survivor/knife/meleeattack/survivor-meleeattack_knife_0.png",
        "assets/Top_Down_Survivor/knife/meleeattack/survivor-meleeattack_knife_1.png",
        "assets/Top_Down_Survivor/knife/meleeattack/survivor-meleeattack_knife_2.png",
        "assets/Top_Down_Survivor/knife/meleeattack/survivor-meleeattack_knife_3.png",
        "assets/Top_Down_Survivor/knife/meleeattack/survivor-meleeattack_knife_4.png",
        "assets/Top_Down_Survivor/knife/meleeattack/survivor-meleeattack_knife_5.png",
        "assets/Top_Down_Survivor/knife/meleeattack/survivor-meleeattack_knife_6.png",
        "assets/Top_Down_Survivor/knife/meleeattack/survivor-meleeattack_knife_7.png",
        "assets/Top_Down_Survivor/knife/meleeattack/survivor-meleeattack_knife_8.png",
        "assets/Top_Down_Survivor/knife/meleeattack/survivor-meleeattack_knife_9.png",
        "assets/Top_Down_Survivor/knife/meleeattack/survivor-meleeattack_knife_10.png",
        "assets/Top_Down_Survivor/knife/meleeattack/survivor-meleeattack_knife_11.png",
        "assets/Top_Down_Survivor/knife/meleeattack/survivor-meleeattack_knife_12.png",
        "assets/Top_Down_Survivor/knife/meleeattack/survivor-meleeattack_knife_13.png",
        "assets/Top_Down_Survivor/knife/meleeattack/survivor-meleeattack_knife_14.png",
    };

    m_sprite->setSizePercentage(0.4);

    // m_idleSequence =    m_sprite->addSequence(gunIdle);
    // m_movingSequence =  m_sprite->addSequence(gunMove);
    // m_shootSequence =   m_sprite->addSequence(gunShoot, true);

    m_idleSequence =    m_sprite->addSequence(rifleIdle, 80);
    m_movingSequence =  m_sprite->addSequence(rifleMove, 1);
    m_shootSequence =   m_sprite->addSequence(rifleShoot, 50, true);
    m_reloadSequence =  m_sprite->addSequence(rifleReload, 20, true);

    // m_idleSequence =    m_sprite->addSequence(knifeIdle, 1);
    // m_movingSequence =  m_sprite->addSequence(knifeMove, 1);
    // m_shootSequence =   m_sprite->addSequence(knifeShoot, 1, true);

    // clang-format on
    m_sprite->setCurrentSequence(m_idleSequence);
}

Player::~Player()
{
    print("Player destroyed");
}

void Player::update()
{
    if (!m_isMoving)
        return;
    using namespace std::chrono;

    std::chrono::duration<double> move_time = system_clock::now() - m_moveTime;

    if (move_time.count() > 0.05)
    {
        m_isMoving = false;
        m_sprite->setCurrentSequence(m_idleSequence);
        std::cout << "reset\n";
    }
}

bool Player::isMoving() const
{
    return m_isMoving;
}

void Player::shoot()
{
    m_sprite->setCurrentSequence(m_shootSequence);
    // m_sprite->setCurrentSequence(m_reloadSequence); 
}

void Player::moveForward(int velocity)
{
    m_moveTime = std::chrono::system_clock::now();
    m_isMoving = true;
    m_sprite->setCurrentSequence(m_movingSequence);
    m_movable->move(velocity);
}

void Player::moveBackward(int velocity)
{
    print_limitimed("not implemented");
    m_sprite->setCurrentSequence(m_idleSequence);
}

void Player::rotateLeft(int velocity)
{
    m_movable->rotate(-velocity);
}

void Player::rotateRight(int velocity)
{
    m_movable->rotate(velocity);
}

const char *Player::getName() const
{
    return m_name.c_str();
}

std::shared_ptr<Movable_I> Player::getMovable() const
{
    return m_movable;
}
