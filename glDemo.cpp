/*************************************************************
 * 1. Name:
 *      Jake Zalesny, Ryan Madsen, Jessica Johnson
 * 2. Assignment Name:
 *      Lab 04: Apollo 11 Visuals
 * 3. Assignment Description:
 *      Simulate the Apollo 11 landing
 * 4. What was the hardest part? Be as specific as possible.
 *      For us it was pretty difficult to coordinate with our team members and figure out
 *      our exact approach on how we wanted to make the visuals work 
 *      once we started communcating more frequently it went much better. 
 * 5. How long did it take for you to complete the assignment?
 *      3.5 hrs. 
 *****************************************************************/

#include "point.h"
#include "uiInteract.h"
#include "uiDraw.h"
#include "ground.h"
#include "lander.h"
#include <vector>
using namespace std;

/*************************************************************************
 * Demo
 * Test structure to capture the LM that will move around the screen
 *************************************************************************/
class Demo
{
public:
    Demo(const Point& ptUpperRight) :
        angle(0.0),
        ptStar(ptUpperRight.getX() - 20.0, ptUpperRight.getY() - 20.0),
        ptLM(ptUpperRight.getX() / 2.0, ptUpperRight.getY() / 2.0),
        ground(ptUpperRight),
        ptText(ptUpperRight.getX() / 2.0, -ptUpperRight.getY() / 2.0)
   { 

      phase = random(0, 255);
   }

   vector<Point> makeStars(int numStars) {
       vector<Point> stars = {};

       for (int x = 0; x < numStars; x++) {
           Point tempPoint(random(0, 400), random(100, 500));
           stars.push_back(tempPoint);
       }

       return stars;
   }


   // this is just for test purposes.  Don't make member variables public!
   Point ptLM;           // location of the LM on the screen
   Point ptUpperRight;   // size of the screen
   double angle;         // angle the LM is pointing
   unsigned char phase;  // phase of the star's blinking
   Ground ground;
   Point ptStar;
   Point ptText;
   lander newLander; 
   vector<Point> stars = makeStars(70);
};

/*************************************
 * All the interesting work happens here, when
 * I get called back from OpenGL to draw a frame.
 * When I am finished drawing, then the graphics
 * engine will wait until the proper amount of
 * time has passed and put the drawing on the screen.
 **************************************/
void callBack(const Interface *pUI, void * p)
{
   ogstream gout;

   // the first step is to cast the void pointer into a game object. This
   // is the first step of every single callback function in OpenGL. 
   Demo * pDemo = (Demo *)p;  

   // move the ship around
   if (pUI->isRight())
//      pDemo->angle -= 0.1;
        pDemo->ptLM.addX(1.0);
   if (pUI->isLeft())
//      pDemo->angle += 0.1;
        pDemo->ptLM.addX(-1.0);
   if (pUI->isUp())
//      pDemo->ptLM.addY(-1.0);
        pDemo->ptLM.addY(1.0);
   if (pUI->isDown())
       pDemo->ptLM.addY(-1.0);



   // put some text on the screen
   //gout.setPosition(Point(30.0, 30.0));
   //gout << "Demo (" << (int)pDemo->ptLM.getX() << ", " << (int)pDemo->ptLM.getY() << ")" << "\n";

   // draw our little star
   gout.drawStar(pDemo->ptStar, pDemo->phase++);
   
   //draw text for the altitude
   gout.setPosition(Point(10.0, 360.0));
   gout << "Altitude: " << (int)pDemo->ptLM.getY() << " meters";

   //draw text for the fuel
   gout.setPosition(Point(10.0, 380.0));
   gout << "Fuel: " << (int)pDemo->newLander.getFuel() << " lbs";

   //draw text for the velocity
   gout.setPosition(Point(10.0, 340.0)); 
   gout << "Speed: " << (int)pDemo->newLander.getTotalVelocity() << " m/s";
   

   for (auto star : pDemo->stars) {
       cout << star << endl;

       // draw our little stars
       gout.drawStar(star, pDemo->phase++);
   }

   // draw the ground
   pDemo->ground.draw(gout);

   // draw the lander and its flames
   gout.drawLander(pDemo->ptLM /*position*/, pDemo->angle /*angle*/);
   gout.drawLanderFlames(pDemo->ptLM, pDemo->angle, /*angle*/
       pUI->isDown(), pUI->isLeft(), pUI->isRight());
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
                "Open GL Demo", 
                 ptUpperRight);

   // Initialize the game class
   Demo demo(ptUpperRight);

   // set everything into action
   ui.run(callBack, &demo);             

   return 0;
}
