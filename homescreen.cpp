#include<simplecpp>
 int main(){
initCanvas("carrom mania",600,500);
Rectangle r0(300,250,600,500);
r0.setFill(true);r0.setColor(COLOR("black"));//outer border
Rectangle r00(300,250,550,450);
r00.setFill(true);r00.setColor(COLOR("yellow"));//inner border
Rectangle r1(300,100,textWidth("WELCOME TO CARROM MANIA")+40,60);
r1.setFill(true);r1.setColor(COLOR("blue"));
Text t1(300,100,"WELCOME TO CARROM MANIA");
Rectangle r2(180,200,textWidth("INSTRUCTIONS"),60);
r2.setFill(true);r2.setColor(COLOR("green"));
Text t2(180,200,"PLAY GAME");
Rectangle r3(300,270,textWidth("INSTRUCTIONS")+20,60);
r3.setFill(true);r3.setColor(COLOR("green"));
Text t3(300,270,"INSTRUCTIONS");
Rectangle r4(400,350,textWidth("INSTRUCTIONS")-20,60);
r4.setFill(true);r4.setColor(COLOR("green"));
Text t4(400,350,"EXIT");
wait(1000);

}
