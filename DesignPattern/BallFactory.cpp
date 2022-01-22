#include "BallFactory.h"
#include "BasketBall.h"
#include "BaseBall.h"
#include "TennisBall.h"

Ball* BallFactory::create(Ball::TYPE type) {
  switch(type){
    case Ball::TYPE::BASKET:
      return new BasketBall;
    case Ball::TYPE::BASE:
      return new BaseBall;
    case Ball::TYPE::TENNIS:
      return new TennisBall;
    default:
      return nullptr;
  }
}