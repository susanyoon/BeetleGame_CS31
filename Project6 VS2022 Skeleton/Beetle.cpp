//
//  Beetle.cpp
//
//

#include "Beetle.h"

namespace cs31
{

Beetle::Beetle()
{
    mBody = false;
    mTail = false;
    mLeg1 = false;
    mLeg2 = false;
    mLeg3 = false;
    mLeg4 = false;
    mHead = false;
    mEye1 = false;
    mEye2 = false;
    mAntenna1 = false;
    mAntenna2 = false;
}

// convert a tossed die value into a BodyPart
Beetle::BodyPart Beetle::convertRollToBodyPart( int die ) const
{
    // if not matching, then return NOTVALID
    BodyPart part = BodyPart::NOTVALID;
    if (die == 6)
        part = BodyPart::BODY;
    if (die == 5)
        part = BodyPart::HEAD;
    if (die == 4)
        part = BodyPart::TAIL;
    if (die == 3)
        part = BodyPart::LEG;
    if (die == 2)
        part = BodyPart::ANTENNA;
    if (die == 1)
        part = BodyPart::EYE;
    return( part );
}

// build the Beetle's body
void Beetle::buildBody()
{
    mBody = true;    
}

// has the Beetle's body been built?
bool Beetle::hasBody() const
{
    bool result = false;

    if (mBody == true)
    {
        result = true;
    }
    if (mBody == false)
    {
        result = false;
    }

    return(result);
}

void Beetle::buildTail()
{
   mTail = true;
}

// has the Beetle's tail been built?
bool Beetle::hasTail() const
{
    bool result = false;

    if (mTail == true)
    {
        result = true;
    }
    if (mTail == false)
    {
        result = false;
    }
    return(result);
}

// build Leg1 before Leg2 before Leg3 before Leg4
void Beetle::buildLeg()
{
    if (mLeg1 == false && mLeg2 == false && mLeg3 == false && mLeg4 == false)
    {
        mLeg1 = true;
    }
    else if(mLeg2 == false && mLeg3 == false && mLeg4 == false)
    {
        mLeg2 = true;
    }
    else if (mLeg3 == false && mLeg4 == false)
    {
        mLeg3 = true;
    }
    else if (mLeg4 == false)
    {
        mLeg4 = true;
    }
}

// has the Beetle's leg been built?
bool Beetle::hasLeg1() const
{
    bool result = false;

    if (mLeg1 == true)
    {
        result = true;
    }
    if (mLeg1 == false)
    {
        result = false;
    }
    return( result );
}

bool Beetle::hasLeg2() const
{
    bool result = false;

    if (mLeg2 == true)
    {
        result = true;
    }
    if (mLeg2 == false)
    {
        result = false;
    }
    return(result);
}

bool Beetle::hasLeg3() const
{
    bool result = false;

    if (mLeg3 == true)
    {
        result = true;
    }
    if (mLeg3 == false)
    {
        result = false;
    }
    return(result);
}

bool Beetle::hasLeg4() const
{
    bool result = false;

    if (mLeg4 == true)
    {
        result = true;
    }
    if (mLeg4 == false)
    {
        result = false;
    }
    return(result);
}


void Beetle::buildHead()
{
    mHead = true;
}

// has the Beetle's head been built?
bool Beetle::hasHead() const
{
    bool result = false;
    if (mHead == true)
    {
        result = true;
    }
    if (mHead == false)
    {
        result = false;
    }
    return (result);
}

// build Eye1 before Eye2
void Beetle::buildEye()
{
    if (mEye1 == false && mEye2 == false)
    {
        mEye1 = true;
    }
    else
    {
        mEye2 = true;
    }
}

// has the Beetle's eye been built?
bool Beetle::hasEye1() const
{
    bool result = false;

    if (mEye1 == true)
    {
        result = true;
    }
    if (mEye1 == false)
    {
        result = false;
    }
    return( result );
}

bool Beetle::hasEye2() const
{
    bool result = false;

    if (mEye2 == true)
    {
        result = true;
    }
    if (mEye2 == false)
    {
        result = false;
    }
    return(result);
}

// builds Antenna1 before Antenna2
void Beetle::buildAntenna()
{
    if (mAntenna1 == false && mAntenna2 == false)
    {
        mAntenna1 = true;
    }
    else 
    {
        mAntenna2 = true;
    }
    
}

// has the Beetle's antenna been built?
bool Beetle::hasAntenna1() const
{
    bool result = false;

    if (mAntenna1 == true)
    {
        result = true;
    }
    if (mAntenna1 == false)
    {
        result = false;
    }
    return (result);
}

bool Beetle::hasAntenna2() const
{
    bool result = false;

    if (mAntenna2 == true)
    {
        result = true;
    }
    if (mAntenna2 == false)
    {
        result = false;
    }
    return (result);
}


// is this Beetle completely built out?
bool Beetle::isComplete() const
{
    bool result = false;

    if (mBody == true && mHead == true && mEye1 == true && mEye2 == true && mAntenna1 == true && mAntenna2 == true && mLeg1 == true && mLeg2 == true && mLeg3 == true && mLeg4 == true && mTail == true)
    {
        result = true;
    }
    else
    {
        result = false;
    }
    return (result);
}


}


