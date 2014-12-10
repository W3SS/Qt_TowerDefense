/*
    @mainpage HW6
    @author Tim Maytom (104016902)
    @date 11/14/2014
    @section DESCRIPTION

    This is an update of my previous assignment. I have worked on adding game logic to the GUI
    that I had already constructed. The game draws a game map from array data. The enemies navigation
    coordinates have been manually updated to follow the new path. I have added an ingame GUI. This
    GUI includes the wave and score displays at the top of the screen. The number images for these displays
    are drawn from a parsed string with Images that I have created. I have also added a toggle menu on the right
    to select the tower type that you want to build. The towers target enemies by drawing QLine's to the enemy
    and then comparing the distance of that QLine to its range property. If the enemy is within range, the tower
    will reduce its health. When an enemy's health reaches 0, the enemy will be deleted from the game and the score
    will be updated by the appropriate value.

    Issues:
    -no end game event
    -only a single wave. Need to store wave data, and then create a system to load the waves
    -no attacking animations
    -building towers doesn't affect the player's score so the user can create as many towers as they like
    -no tower upgrade system
*/
#ifndef TOWER_H
#define TOWER_H

#include "gameobject.h"
#include <QPointF>
#include "image.h"
#include "enemy.h"
#include <QDebug>

/*
    @class Tower
    @brief Class that manages individual tower information in the game.
    @detail This class holds the towers Image and stats which are relevant to attacking events.
*/

namespace TOWER{
    const QString TOWER_FIRE = "C:/Qt/Projects/GameProject/fire.png";
    const QString TOWER_ICE = "C:/Qt/Projects/GameProject/ice.png";
    const QString TOWER_EARTH = "C:/Qt/Projects/GameProject/rock.png";

    const QString FIRE_FRAME_1 = "C:/Qt/Projects/GameProject/fire_1.png";
    const QString FIRE_FRAME_2 = "C:/Qt/Projects/GameProject/fire_2.png";
}

enum Type{FIRE,ICE,EARTH};

class Tower : public GameObject
{
    Q_OBJECT
public:
    //Constructor
    Tower(QString fileName, QRect tile);
    ~Tower();
    //Getters
    //int getDamage() const;
    //int getRange() const;
    int getTimer() const { return timerID; }
    bool isCoolDown() const { return coolDown; }
    //int getCoolDown() const;
    Type getType() const { return type; }

    void setTimer(int id) { timerID = id; }
    void setCoolDown(bool c) { coolDown = c; }

    static int getDamageCost(Type t);
    static int getRangeCost(Type t);
    static int getRateCost(Type t);
    static int getDamage(Type t);
    static int getRange(Type t);
    static int getCoolDown(Type t);
    static void upgradeDamage(Type t, int change);
    static void upgradeRange(Type t, int change);
    static void upgradeSpeed(Type t, int change);
    static void resetUpgrades();
public slots:
    void testing(){setCoolDown(false);}
private:
    //Attacking stats
    Type type;
    int timerID;
    bool coolDown;

    class TowerStats{
    public:
        TowerStats():d_count(0), r_count(0), s_count(0){}
        int d_count, r_count, s_count;
    };

    static TowerStats fire;
    static TowerStats ice;
    static TowerStats earth;
    static int fireCount;
    static int iceCount;
    static int earthCount;
};

#endif // TOWER_H
