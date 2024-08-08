//
//  BeetleGame.cpp
//

#include "BeetleGame.h"
#include "BeetleDrawing.h"

#include <iostream>

namespace cs31
{

BeetleGame::BeetleGame() : mHuman(), mComputer(), mHumanDie(), mComputerDie()
{
    
}

// draw the board by using a BeetleDrawing to draw the two Beetles
std::string BeetleGame::display( std::string msg ) const
{
    BeetleDrawing drawing( mHuman, mComputer );
    std::string result = drawing.draw() + "\n" + msg;
    return( result );
}


// TODO when amount is zero, it is a random roll...
// otherwise, an amount value is a cheating value...
void BeetleGame::humanRoll( int amount )
{
    // if the amount is zero, roll the Human's die
    if (amount == 0)
    {
        mHumanDie.roll();  
    }
    // otherwise, cheat by forcing the amount into the Human's die
    else
    {
        mHumanDie.setValue(amount);
    }
}

// TODO return the value of the Human's die
int BeetleGame::getHumanDie( ) const
{
    return mHumanDie.getValue();
}

// TODO convert the Human's die value to a Beetle's body part
// then depending on the body part involved, enforce the game ordering of body parts:
// - namely, body before everything else and head before eyes or antenna
// if allowed, build the desired body part on the Human's beetle
// if a body part was successfully built, return true
// otherwise, return false
bool BeetleGame::humanPlay( )
{
    bool result = false;

    if (mHumanDie.getValue() == 6)
    {
        if (mHuman.hasBody())     // to account for redundant body part-if already has Body
        {
            result = false;
        }
        else
        {
            mHuman.buildBody();
            result = true;
        }
    }
    if(mHuman.hasBody())
    {

        if (mHumanDie.getValue() == 5)
        {
            if(mHuman.hasHead())
            {
                result = false;
            }
            else
            {
                mHuman.buildHead();
                result = true;
            }
        }
        if (mHumanDie.getValue() == 4)
        {
            if (mHuman.hasTail())
            {
                result = false;
            }
            else
            {
                mHuman.buildTail();
                result = true;
            }
        }
        if (mHumanDie.getValue() == 3)
        {
            if (mHuman.hasLeg4())
            {
                result = false;
            }
            else
            {
                mHuman.buildLeg();
                result = true;
            }
        }
        if(mHuman.hasHead())
        {
            if (mHumanDie.getValue() == 2)
            {
                if (mHuman.hasAntenna2())
                {
                    result = false;
                }
                else
                {
                    mHuman.buildAntenna();
                    result = true;
                }
            }
            if (mHumanDie.getValue() == 1)
            {
                if (mHuman.hasEye2())
                {
                    result = false;
                }
                else
                {
                    mHuman.buildEye();
                    result = true;
                }
            }
        }
    }
    else
    {
        result = false;
    }

    return( result );
}

// TODO when amount is zero, it is a random roll...
// otherwise, an amount value is a cheating value...
void BeetleGame::computerRoll( int amount )
{
    // if the amount is zero, roll the Computer's die
    if (amount == 0)
    {
        mComputerDie.roll();
    }
    // otherwise, cheat by forcing the amount into the Computer's die
    else
    {
        mComputerDie.setValue(amount);
    }
}

// TODO return the value of the Computer's die
int BeetleGame::getComputerDie( ) const
{
    return mComputerDie.getValue();
}

// TODO convert the Computer's die value to a Beetle's body part
// then depending on the body part involved, enforce the game ordering of body parts:
// - namely, body before everything else and head before eyes or antenna
// if allowed, build the desired body part on the Computer's beetle
// if a body part was successfully built, return true
// otherwise, return false
bool BeetleGame::computerPlay( )
{
    bool result = false;     

    if (mComputerDie.getValue() == 6)
    {
        if (mComputer.hasBody())     // to account for redundant body part-if already has Body
        {
            result = false;
        }
        else
        {
            mComputer.buildBody();
            result = true;
        }
    }
    if (mComputer.hasBody())
    {

        if (mComputerDie.getValue() == 5)
        {
            if (mComputer.hasHead())
            {
                result = false;
            }
            else
            {
                mComputer.buildHead();
                result = true;
            }
        }
        if (mComputerDie.getValue() == 4)
        {
            if (mComputer.hasTail())
            {
                result = false;
            }
            else
            {
                mComputer.buildTail();
                result = true;
            }
        }
        if (mComputerDie.getValue() == 3)
        {
            if (mComputer.hasLeg4())
            {
                result = false;
            }
            else
            {
                mComputer.buildLeg();
                result = true;
            }
        }
        if (mComputer.hasHead())
        {
            if (mComputerDie.getValue() == 2)
            {
                if (mComputer.hasAntenna2())
                {
                    result = false;
                }
                else
                {
                    mComputer.buildAntenna();
                    result = true;
                }
            }
            if (mComputerDie.getValue() == 1)
            {
                if (mComputer.hasEye2())
                {
                    result = false;
                }
                else
                {
                    mComputer.buildEye();
                    result = true;
                }
            }
        }
    }
    else
    {
        result = false;
    }

    return( result );
}

// TODO what is the current state of the game
BeetleGame::GameOutcome  BeetleGame::determineGameOutcome( ) const
{
    GameOutcome result = GameOutcome::GAMENOTOVER;

    if (mHuman.isComplete() == true && mComputer.isComplete() == false)
    {
        result = GameOutcome::HUMANWONGAME;
    }
    else if (mHuman.isComplete() == false && mComputer.isComplete() == true)
    {
        result = GameOutcome::COMPUTERWONGAME;
    }
    else
    {
        result = GameOutcome::GAMENOTOVER;
    }

    return(result);
}

std::string  BeetleGame::stringifyGameOutcome( ) const
{
    std::string result = "";
    switch( determineGameOutcome() )
    {
        case GameOutcome::COMPUTERWONGAME:
            result = "Computer Won!";
            break;
        case GameOutcome::HUMANWONGAME:
            result = "Human Won!";
            break;
        case GameOutcome::GAMENOTOVER:
            result = "Game Not Over!";
            break;
    }
    return( result );
}

// TODO has the game ended with a winner?
bool BeetleGame::gameIsOver() const
{
    bool result = false;

    if (mHuman.isComplete() == true && mComputer.isComplete() == false)
    {
        result = true;
    }
    else if (mHuman.isComplete() == false && mComputer.isComplete() == true)
    {
        result = true;
    }
    else
    {
        result = false;
    }

    return(result);
}


Beetle BeetleGame::getHumanBeetle( ) const
{
    return( mHuman );
}

Beetle BeetleGame::getComputerBeetle( ) const
{
    return( mComputer );
}

}


