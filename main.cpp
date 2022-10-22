// Ryan Madsen
// Jake Zalesny
// Jessica Johnson

#include "point.h"
#include "uiInteract.h"
#include "uiDraw.h"
#include "ground.h"
#include "lander.h"
#include "star.h"
#include <vector>
#include <iomanip>
using namespace std;

const double landerStartPosX = random(0, 400);
const double landerStartPosY = 400;

void callBack(const Interface *pUI, void *p, void *ground, void *stars)
{
   ogstream gout;

   // the first step is to cast the void pointer into a game object. This
   // is the first step of every single callback function in OpenGL. 
    Lander * pLander = (Lander *)p;
    Ground * pGround = (Ground *)ground;
    vector<Star> * pStars = (vector<Star> *)stars;
    
    bool landed = pLander->getLanded();

   // move the ship around
   if (pUI->isRight() && !landed)
       pLander->rotate("right");
    
   if (pUI->isLeft() && !landed)
       pLander->rotate("left");
       
   if (pUI->isUp() && !landed)
       pLander->applyThrust();
    
    if (!landed) {
        pLander->applyGravity();
        pLander->applyInertia();
    }
    
    if(landed && pUI->isSpace()) {
        pLander->resetLander();
        pGround->reset();
    }


   // draw the lander and its flames
   gout.setPosition(Point(200.0, 200.0));
   gout.drawLander(pLander->getPosition() /*position*/, pLander->getAngle() /*angle*/);
   gout.drawLanderFlames(pLander->getPosition(), pLander->getAngle(), /*angle*/
                    pUI->isUp(), pUI->isLeft(), pUI->isRight());
    
    vector<Star>::iterator starIterator;

    for (starIterator = pStars->begin(); starIterator != pStars->end(); starIterator++) {
        gout.drawStar(starIterator->getStarPoint(), starIterator->getStarPhase());
        starIterator->updatePhase();
    }
        
   //draw text for the altitude
   gout.setPosition(Point(10.0, 360.0));
   gout << "Altitude: " << (int)pGround->getElevation(pLander->getPosition()) << " meters";

   //draw text for the fuel
   gout.setPosition(Point(10.0, 380.0));
    gout << "Fuel: " << pLander->getFuel() << " lbs";

   //draw text for the velocity
   gout.setPosition(Point(10.0, 340.0));
   gout << "Speed: " << fixed << setprecision(2) << pLander->getTotalVelocity() << " m/s";
    
   // draw the ground
   pGround->draw(gout);

   if (pGround->hitGround(pLander->getPosition(), 20)) {
       gout.setPosition(Point(90, 300.0));
       gout << "Houston we have a problem!";
       
       gout.setPosition(Point(110, 280));
       gout << "Press \"Space\" to restart.";
       
       pLander->setLanded(true);
       pLander->setAngle(3.14159);
   }

   else if (pGround->onPlatform(pLander->getPosition(), 20)) {
       gout.setPosition(Point(110, 300.0));
       pLander->getTotalVelocity() < 4 ? gout << "Mission Accomplished!" : gout << "Houston we have a problem!";
       pLander->setLanded(true);
   }
}

/*********************************
 * Main is pretty sparse.  Just initialize
 * my Demo type and call the display engine.
 * That is all!
 *********************************/
#ifdef _WIN32_X
#include <windows.h>
int WINAPI wWinMain(
   _In_ HINSTANCE hInstance, 
   _In_opt_ HINSTANCE hPrevInstance, 
   _In_ PWSTR pCmdLine, 
   _In_ int nCmdShow)
#else // !_WIN32
int main(int argc, char ** argv)
#endif // !_WIN32
{
   // Initialize OpenGL
   Point ptUpperRight(400.0, 400.0);
   Interface ui(0, NULL,
                "Apollo 11 Physics Simulator",
                 ptUpperRight);
    ui.setFramesPerSecond(30);
    
    Point landerStartPt = Point(landerStartPosX, landerStartPosY);

    // Initialize the game class
    Lander lander(landerStartPt);
    Ground ground(ptUpperRight);
    vector<Star> stars;

   for (int i = 0; i < 100; i++) {
       Star star = Star();
       stars.push_back(star);
   }


   // set everything into action
   ui.run(callBack, &lander, &ground, &stars);

   return 0;
}

