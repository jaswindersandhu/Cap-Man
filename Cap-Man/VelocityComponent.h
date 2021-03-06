#pragma once
#include "Component.h"
#include "Velocity.h"
#include "Constants.h"

class VelocityComponent
    : public Component<VelocityComponent> {
public:
    VelocityComponent(float vx, float vy, float speed);
    VelocityComponent(Velocity velocity, float speed);
    ~VelocityComponent();

    Velocity    velocity() const                    { return mVelocity; }
    void        setVelocity(float vx, float vy)     { mVelocity.setVx(vx); mVelocity.setVy(vy); }
    void        setVelocityFromDirection(Directions::Direction direction);
    void        stopMovement()                      { setVelocity(0.0f, 0.0f); }
    float       currentSpeed() const                { return mCurrentSpeed; }
    float       defaultSpeed() const                { return mSpeed; }
    float       halfSpeed() const                   { return mHalfSpeed; }
    float       doubleSpeed() const                 { return mDoubleSpeed; }
    void        setCurrentSpeed(float speed)        { mCurrentSpeed = speed; }
    bool        isMoving() const                    { return mVelocity.isMoving(); }

private:
    Velocity    mVelocity;
    float       mSpeed;
    float       mCurrentSpeed;
    float       mHalfSpeed;
    float       mDoubleSpeed;
};

