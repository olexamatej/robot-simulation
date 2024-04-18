#include "Controller.hpp"
#include <iostream>

#define ROBOT_SPRITE_HEIGHT 64
#define ROBOT_SPRITE_WIDTH 64

Controller::Controller() {
}

Controller::~Controller() {

    for (Robot* robot : robots) {
        delete robot;
    }
}

void Controller::addRobot(int x, int y){
    //this might need some changes
    QRect newRobotRect(x, y, 50, 50); 

    for (Robot* robot : robots) {
        QRect existingRobotRect(robot->getPosX(), robot->getPosY(), 50, 50); 

        if (newRobotRect.intersects(existingRobotRect)) {
            return;
        }
    }
    // The new robot does not overlap with any existing robots, so add it
    robots.push_back(new Robot(x, y));
}



void Controller::spawnTopmostRobot(){
    robots.back()->spawn(&scene);
}


void Controller::spawnRobots(){
     for (Robot* robot : robots) {
        robot->spawn(&scene);
    }
    // robots.clear();
}

void Controller::addBox(int x, int y){
    //this might need some changes
    QRect newBoxRect(x, y, 64, 64); 

    for (Box* box : boxes) {
        QRect existingBoxRect(box->getPosX(), box->getPosY(), 64, 64); 

        if (newBoxRect.intersects(existingBoxRect)) {
            return;
        }
    }
    // The new robot does not overlap with any existing robots, so add it
    boxes.push_back(new Box(x, y));
}



void Controller::spawnTopmostBox(){
    boxes.back()->spawn(&scene);
}

void Controller::removeItem(int x, int y)
{
    //Remove box
    QRect newBoxRect(x, y, 64, 64); 
    for (Box* box : boxes) {
        QRect existingBoxRect(box->getPosX(), box->getPosY(), 64, 64); 

        if (newBoxRect.intersects(existingBoxRect)) {
            boxes.erase(std::remove(boxes.begin(), boxes.end(), box), boxes.end());
            box->despawn(&scene);
            return;
        }
    }

    //Remove robot
    QRect newRobotRect(x, y, 50, 50); 

    for (Robot* robot : robots) {
        QRect existingRobotRect(robot->getPosX(), robot->getPosY(), 50, 50); 

        if (newRobotRect.intersects(existingRobotRect)) {
            robots.erase(std::remove(robots.begin(), robots.end(), robot), robots.end());
            robot->despawn(&scene);
            return;
        }
    }
}