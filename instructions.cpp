#include<simplecpp>
main_program
{
    initCanvas("INSTRUCTIONS",1000,600);
    Text t1(500,100,"INSTRUCTIONS");
    t1.setColor(COLOR("green"));
    Circle c1(150,200,5);
    c1.setFill(true);c1.setColor(COLOR("blue"));
    Text t2(400,200,"DEFAULT SETTINGS:TWO PLAYERS,BOTH MANUALLY OPERATED");
    Circle c2(150,220,5);
    c2.setFill(true);c2.setColor(COLOR("blue"));
    Text t3(250,240,"HOW TO PLAY:");
    Text t4(450,270,"1. GAME HAS 2 COMPONENTS i.e,1 BLUE COLORED STRIKER AND 9 BLACK COINS.");
    t4.setFill(true);t4.setColor(COLOR("red"));
    Text t5(385,300,"2. SET STRIKER TO THE DESIRED POSITION BY MOUSE CLICK. ");
    t5.setFill(true);t5.setColor(COLOR("red"));
    Text t6(418,330,"3. POWER(SPEED) GIVEN TO THE STRIKER IS DIRECTLY PROPORTIONAL");
    t6.setFill(true);t6.setColor(COLOR("red"));
    Text t7(488,360,"TO THE DISTANCE OF THE CLICK FROM THE STRIKER ALONG THE REQUIRED DIRECTION.");
    t7.setFill(true);t7.setColor(COLOR("red"));
    Text t8(475,390,"4. EACH PLAYER SCORES A POINT IN THE CASE THE COIN GOES IN ANY OF THE 4 HOLES.");
    t8.setFill(true);t8.setColor(COLOR("red"));
    Text t9(458,420,"5. PLAYERS ARE PENALIZED BY 1 POINT IN CASE THE STRIKER GOES IN ANY HOLE.");
    t9.setFill(true);t9.setColor(COLOR("red"));
    Rectangle r1(100,500,200,60);
    r1.setFill(true);r1.setColor(COLOR("blue"));
    Text t10(100,500,"BACK TO HOME SCREEN");
    t10.setFill(true);
    int o=getClick();
    double ox=o/65536,oy=o%655536;
    if((ox>0&&ox<200)&&(oy>470&&oy<530))
    {


    }


    wait(1000);


}
