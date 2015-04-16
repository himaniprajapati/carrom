#include<simplecpp>
const double lc=0.001;

const int retardation=20000;
const int error=100;
void graphics()
{
    float r=15;
float x=15;
float p=6.213;
float z=50;
     Line l1(300,200+x,300,600-x),l2(300+x,600,700-x,600),l3(700,600-x,700,200+x),l4(700-x,200,300+x,200);
     l1.imprint();
     l2.imprint();
     l3.imprint();
     l4.imprint();
     Circle c1(300-r,200+x,15),c2(300-r,600-x,15),c3(300+x,600+r,15),c4(700-x,600+r,15),c5(700+r,600-x,15),c6(700+r,200+x,15),c7(700-x,200-r,15),c8(300+x,200-r,15);
     Circle c9(300,600,p),c10(700,600,p),c11(700,200,p),c12(300,200,p);

     Line l5(300-2*r,600-x,300-2*r,200+x),l6(300+x,200-2*r,700-x,200-2*r),l7(700+2*r,200+x,700+2*r,600-x),l8(700-x,600+2*r,300+x,600+2*r);
     Line l9(300-2*r,600+2*r,400,500),l10(700+2*r,600+2*r,600,500),l11(700+2*r,200-2*r,600,300),l12(300-2*r,200-2*r,400,300);

     l5.imprint();
     l6.imprint();
     l7.imprint();
     l8.imprint();
     l9.imprint();
     l10.imprint();
     l11.imprint();
     l12.imprint();

     Turtle t1;
     Circle c13(500,400,75);
     float u=arcsine((r/z)*sine(45/2));
     t1.left(45*1.5);
     t1.penUp();t1.forward(r);t1.penDown();
     repeat(8){t1.right(u+45/2);t1.forward(z);t1.right(180-2*u);t1.forward(z);t1.left(315/2-u);}
     t1.right(90);
     t1.penUp();t1.moveTo(0,0);
     Circle c14(500,400,15);
     Circle c15(500,400,10);

     c15.setColor(COLOR("red"));
     c15.setFill(true);

    c1.setColor(COLOR("red"));
     c1.setFill(true);
     c2.setColor(COLOR("red"));
     c2.setFill(true);
     c3.setColor(COLOR("red"));
     c3.setFill(true);
     c4.setColor(COLOR("red"));
     c4.setFill(true);
     c5.setColor(COLOR("red"));
     c5.setFill(true);
     c6.setColor(COLOR("red"));
     c6.setFill(true);
     c7.setColor(COLOR("red"));
     c7.setFill(true);
     c8.setColor(COLOR("red"));
     c8.setFill(true);

Rectangle r1(500,400,600,600);
Circle c16 (225,125,25);c16.setFill(true);
Circle c17(775,125,25);c17.setFill(true);
Circle c18(775,675,25);c18.setFill(true);
Circle c19(225,675,25);c19.setFill(true);
     c1.imprint();
     c2.imprint();
     c3.imprint();
     c4.imprint();
     c5.imprint();
     c6.imprint();
     c7.imprint();
     c8.imprint();
     c9.imprint();
     c10.imprint();
     c11.imprint();
     c12.imprint();

c13.imprint();
c14.imprint();
c15.imprint();
c16.imprint();
c17.imprint();
c18.imprint();
c19.imprint();
r1.imprint();

}



class velocity
{
public:
    double x;
    double y;
    void fix(double a,double b)
    {
        x=a;
        y=b;
    }
};


class acceleration
{
public:
    double x;
    double y;
    void fix(double a,double b)
    {
        x=a;
        y=b;
    }
};
double one_root(double coeff_2,double coeff_3,double coeff_4,double coeff_5,double time)
{


    for(double T=0;T<time;T=T+lc)
    {
        if((pow(T,4)+coeff_2*pow(T,3)+coeff_3*pow(T,2)+coeff_4*T+coeff_5)<0)
            return T;

    }
    return error;

}


double roots2ndorder(double a,double b,double c)
{

    double D=b*b-4*a*c;
    if(D<0) return error;
    if(a>0)
    {
        double r=(-b-sqrt(D))/(2*a);
        return r;
    }
    else
    {
        double r=(-b+sqrt(D))/(2*a);
        return r;
    }
}

class coin;

double tym_col_statc_coin(coin *,coin *);

class coin
{
public:
    Circle c;
    acceleration a;
    velocity v;
    char ch;
    coin *next;
    coin()
    {
        c.reset(0,0,0);
        a.fix(0,0);
        v.fix(0,0);
        ch='x';
        next=0;
    }




void shift()                           //moves a coin for least count(.001)time
{
    double p=v.y/v.x;
    c.move(v.x*lc,v.y*lc);
    v.fix(v.x-a.x*lc,v.y);
    v.fix(v.x,v.x*p);

}

void col_wall()                //Changes velocity of coin after collision with wall
{
    if(ch=='y')
    {
        v.fix(v.x,-v.y);
        a.fix(a.x,-a.y);
    }
    if(ch=='x')
    {
        v.fix(-v.x,v.y);
        a.fix(-a.x,a.y);
    }
}

void terminate()               //Sets velocity and acceleration to zero after stopping
{
    a.fix(0,0);
    v.fix(0,0);
    }


double tym_till_col_with_wall()    //Calculates the minimum time till collision with any of the walls
{
    double t1=error,t2=error;
    if(v.x>0)  t1=roots2ndorder(a.x/2,-v.x,800-c.getRadius()-c.getX());
    if(v.x<0)  t1=roots2ndorder(-a.x/2,v.x,-c.getRadius()-200+c.getX());
    if(v.y>0)  t2=roots2ndorder(a.y/2,-v.y,700-c.getRadius()-c.getY());
    if(v.y<0)  t2=roots2ndorder(-a.y/2,v.y,-100-c.getRadius()+c.getY());
    if(t2>0&&t1<0)return t2;
    if(t2<0&&t1>0)return t1;
    if(t2<0&&t1<0)return error;
    if(t1<t2)
    {
        ch='x';
        return t1;
    }
    else
    {
        ch='y';
        return t2;
    }
}


double tym_till_terminate()  //Calculates time till motion of coin terminates due to friction
{
    double T1;
    T1=v.x/a.x;

    return T1;
}


double tym_till_coin_in_holes()       //Calculate minimum time till a coin goes into any one of the holes
{
    coin hole1,hole2,hole3,hole4;
    hole1.c.reset(225,125,25);
    hole2.c.reset(775,125,25);
    hole3.c.reset(775,675,25);
    hole4.c.reset(225,675,25);
    double minimum_time=error,t[4];
    t[0]=tym_col_statc_coin(this,&hole1);
    t[1]=tym_col_statc_coin(this,&hole2);
    t[2]=tym_col_statc_coin(this,&hole3);
    t[3]=tym_col_statc_coin(this,&hole4);
    for(int i=0; i<4; i++)
    {
        if(t[i]<minimum_time)
        {
            minimum_time=t[i];
        }
    }
    return minimum_time;
}
void coin_in_the_hole()  //Removes the coin from the board after it goes into the hole
{
    c.reset(2000,2000,0);
}
};

class list
{
public:
    coin*head;
    list()
    {
        head=0;
    }
    void add(coin*a)
    {
        a->next=head;
        head=a;
    }
    void remove(coin*a)
    {

        if(head==a)
        {

            head=head->next;
            a->next=0;
            return;
        }
        coin*current=head;
        coin*b;
        while(current!=0)
        {
            if(current==a)
            {
                b->next=current->next;
                a->next=0;
                return;

            }
            b=current;
            current=current->next;

        }


    }

};

double tym_col_statc_coin(coin*moving,coin*statc)
{
    bool p=false,q=false;
    if((moving->c.getX()>statc->c.getX())^(moving->v.x>0))
        p=true;
    if((moving->c.getY()>statc->c.getX())^(moving->v.x>0))
        q=true;
    if(p||q)
    {
        double x_rel=statc->c.getX()-moving->c.getX();
        double y_rel=statc->c.getY()-moving->c.getY();
        if(((y_rel*moving->v.x-x_rel*moving->v.y)/sqrt(moving->v.x*moving->v.x+moving->v.y*moving->v.y))<(moving->c.getRadius()+statc->c.getRadius()))
        {
            double time1=roots2ndorder(pow(moving->v.x,2)+pow(moving->v.y,2),-2*((moving->v.x)*x_rel+(moving->v.y)*y_rel),x_rel*x_rel+y_rel*y_rel-pow((moving->c.getRadius()+statc->c.getRadius()),2));
            double time2=roots2ndorder(moving->a.x/2,-moving->v.x,moving->v.x*time1);
            if(time2<0) return error;
            else return time2;
        }
        else return error;
    }
    else return error;
}


void col_moving_statc(coin*coin_m,coin*coin_s)
{

    double vel_x1,vel_x2,vel_y1,vel_y2;
    double hypo=coin_s->c.getRadius()+coin_m->c.getRadius();
    double x_rel=coin_s->c.getX()-coin_m->c.getX();
    double y_rel=coin_s->c.getY()-coin_m->c.getY();
    double _cos=x_rel/hypo,_sin=y_rel/hypo;
    vel_x1=_sin*(_sin*(coin_m->v.x)-_cos*(coin_m->v.y));
    vel_y1=_cos*(-_sin*(coin_m->v.x)+_cos*(coin_m->v.y));
    vel_x2=_cos*(_cos*(coin_m->v.x)+_sin*(coin_m->v.y));
    vel_y2=_sin*(_cos*(coin_m->v.x)+_sin*(coin_m->v.y));
    coin_m->v.fix(vel_x1,vel_y1);
    coin_s->v.fix(vel_x2,vel_y2);
    double coin_m_speed=sqrt(pow(coin_m->v.x,2)+pow(coin_m->v.y,2));
    double coin_s_speed=sqrt(pow(coin_s->v.x,2)+pow(coin_s->v.y,2));
    coin_m->a.fix(retardation*coin_m->v.x/coin_m_speed,retardation*coin_m->v.y/coin_m_speed);
    coin_s->a.fix(retardation*coin_s->v.x/coin_s_speed,retardation*coin_s->v.y/coin_s_speed);
}

void col_moving_moving(coin*coin_m,coin*coin_s)
{
    double vel_x1,vel_x2,vel_y1,vel_y2;
    double hypo=coin_s->c.getRadius()+coin_m->c.getRadius();
    double x_rel=coin_s->c.getX()-coin_m->c.getX();
    double y_rel=coin_s->c.getY()-coin_m->c.getY();
    double _cos=x_rel/hypo,_sin=y_rel/hypo;
    vel_x2=_cos*(_sin*(coin_m->v.y-coin_s->v.y)+_cos*(coin_m->v.x-coin_s->v.x))+coin_s->v.x;
    vel_y2=_sin*(_sin*(coin_m->v.y-coin_s->v.y)+_cos*(coin_m->v.x-coin_s->v.x))+coin_s->v.y;
    vel_x1=_sin*(_sin*(coin_m->v.x-coin_s->v.x)-_cos*(coin_m->v.y-coin_s->v.y))+coin_s->v.x;
    vel_y1=_cos*(_cos*(coin_m->v.y-coin_s->v.y)-_sin*(coin_m->v.x-coin_s->v.x))+coin_s->v.y;

    coin_m->v.fix(vel_x1,vel_y1);
    coin_s->v.fix(vel_x2,vel_y2);
    double coin_m_speed=sqrt(pow(coin_m->v.x,2)+pow(coin_m->v.y,2));
    double coin_s_speed=sqrt(pow(coin_s->v.x,2)+pow(coin_s->v.y,2));
    coin_m->a.fix(retardation*coin_m->v.x/coin_m_speed,retardation*coin_m->v.y/coin_m_speed);
    coin_s->a.fix(retardation*coin_s->v.x/coin_s_speed,retardation*coin_s->v.y/coin_s_speed);

}

double tym_till_col_moving_coin(coin*coin_m,coin*coin_s,double time)
{
    double arel_x=coin_m->a.x-coin_s->a.x;
    double arel_y=coin_m->a.y-coin_s->a.y;
    double vrel_x=coin_m->v.x-coin_s->v.x;
    double vrel_y=coin_m->v.y-coin_s->v.y;
    double x_rel=coin_s->c.getX()-coin_m->c.getX();
    double y_rel=coin_s->c.getY()-coin_m->c.getY();
    if(vrel_x*x_rel+vrel_y*y_rel>0)
    {
        double coefficient=(arel_x*arel_x+arel_y*arel_y)/4;
        double soln=one_root(-(vrel_x*arel_x+vrel_y*arel_y)/coefficient,(vrel_x*vrel_x+vrel_y*vrel_y+arel_x*x_rel+arel_y*y_rel)/coefficient,-2*(vrel_x*x_rel+vrel_y*y_rel)/coefficient,(x_rel*x_rel+y_rel*y_rel-pow((coin_m->c.getRadius()+coin_s->c.getRadius()),2))/coefficient,time);
  //soln gives time till collision
  return soln;
    }
    else return error;


}

double min(int &cases,coin* &a,coin* &b,list Lmoving,list Lstatc)
{
    coin* current1=Lmoving.head;
    double min_time=error;
    while(current1!=0)
    {

        double T1=current1->tym_till_terminate();
        if(T1<min_time)
        {
            cases=1;
            min_time=T1;
            a=current1;

        }
        double T2=current1->tym_till_col_with_wall();
        if(T2<min_time)
        {
            cases=2;
            min_time=T2;
            a=current1;
        }
        coin*current2=Lstatc.head;
        while(current2!=0)
        {

            double T3=tym_col_statc_coin(current1,current2);
            if(T3<min_time)
            {
                cases=3;
                min_time=T3;
                a=current1;
                b=current2;

            }
            current2=current2->next;
        }
        coin*current3=current1->next;
        while(current3!=0)
        {

            double T4=tym_till_col_moving_coin(current1,current3,min_time);
            if(T4<min_time)
            {

                cases=4;
                min_time=T4;
                a=current1;
                b=current3;
            }
            current3=current3->next;
        }
        double T5=current1->tym_till_coin_in_holes();
        if(T5<min_time)
        {

            cases=5;
            min_time=T5;
            a=current1;
        }
        current1=current1->next;
    }
    return min_time;
}


int main(){
//ofstream out("previous_game.txt",ios::out);
    int chance=0;
   int points[2]= {0,0};
    string player[2];
    cout<<"Enter the name of the player 1:";
    cin>>player[0];
    cout<<"Enter the name of the player 2:";
        cin>>player[1];
        string chance_name[2];
        if(player[0]=="")player[0]="player1";
        if(player[1]=="")player[1]="player2";
        chance_name[0]=player[0]+"'s turn";
        chance_name[1]=player[1]+"'s turn";
        initCanvas("CARROM MANIA",1000,800);
        graphics();

        Text score1(90,300,"SCORE:");
            Text score2(90,500,"SCORE:");
            list Lmoving,Lstatc;       //creating 2 objects of the class list
            int cases=7;
            coin *a,*b;
            coin striker,coins[9];
           {

            striker.c.reset(500,615,15);
            striker.c.setFill(true);
            striker.c.setColor(COLOR("blue"));
            double h=40/sqrt(2);
            coins[0].c.reset(500,360,10);
            coins[0].c.setFill(true);
            coins[1].c.reset(500,440,10);
            coins[1].c.setFill(true);
            coins[2].c.reset(540,400,10);
            coins[2].c.setFill(true);
            coins[3].c.reset(460,400,10);
            coins[3].c.setFill(true);
            coins[4].c.reset(500+h,400-h,10);
            coins[4].c.setFill(true);
            coins[5].c.reset(500+h,400+h,10);
            coins[5].c.setFill(true);
            coins[6].c.reset(500-h,400+h,10);
            coins[6].c.setFill(true);
            coins[7].c.reset(500-h,400-h,10);
            coins[7].c.setFill(true);
            coins[8].c.reset(500,400,10);
            coins[8].c.setFill(true);

            for( int i=0;i<9;i++)
        {
            Lstatc.add(&coins[i]);
        }
           }
           Text T,position;
            while(true)
        {                                                         //while loop for different chances
            if(Lstatc.head->next==0)
            break;
            bool shot=false;
            Text scr_1(140,300,points[0]);
            Text scr_2(140,500,points[1]);
            //Text T,position;
            if (chance%2==0)
            {
                T.reset(500,90,chance_name[0]);
                striker.c.reset(500,185,15);
                position.reset(500,130,"set the striker");
                int w=getClick();
                position.reset(500,130,"");
                int xcoor=w/65536;
                if(xcoor>685)xcoor=685;
                if(xcoor<315)xcoor=315;

                striker.c.reset(xcoor,185,15);

            }
                 else
                 {

                     T.reset(500,710,chance_name[1]);
                     striker.c.reset(500,615,15);
                     position.reset(500,670,"set the striker");
                     int w=getClick();
                     position.reset(500,670,"");
                     int xcoor=w/65536;
                if(xcoor>685)xcoor=685;
                if(xcoor<315)xcoor=315;
                striker.c.reset(xcoor,615,15);

                 }
                 while(true){//Restricts user from striking back of his line and gives chances until correct strike is made
			int m=getClick();//setting speed
			if((chance%2==0&&m%65536>185)||(chance%2==1&&m%65536<615)){
				int x=m/65536;
				int y=m%65536;
				if(x==striker.c.getX()) x=x+1;
				if(y==striker.c.getY()) y=y+1;
				striker.v.fix((x-striker.c.getX())*40,(y-striker.c.getY())*40);
				double speed=sqrt(pow(striker.v.x,2)+pow(striker.v.y,2));
				striker.a.fix(retardation*striker.v.x/speed,retardation*striker.v.y/speed);
				break;
			}
		}

                 Lstatc.remove(&striker);
                 Lmoving.add(&striker);

                double min_time=40;

                while(true)
                {

                    coin*current=Lmoving.head;
                    if(current==0)
                        break;
                    min_time=min(cases,a,b,Lmoving,Lstatc);

                    for(double i=0;i<min_time;i=i+lc)
                    {

                        while(current!=0)
                        {

                            current->shift();
                            current=current->next;
                        }
                        current=Lmoving.head;
                    }

                    if(cases==1)
                    {

                        a->terminate();
                        Lmoving.remove(a);
                        Lstatc.add(a);
                    }

                    if(cases==2)
                    {

                        a->col_wall();
                    }

                    if(cases==3)
                    {

                        col_moving_statc(a,b);
                        Lstatc.remove(b);
                        Lmoving.add(b);
                    }
                    if(cases==4)
                    {

                        col_moving_moving(a,b);
                    }

                    if(cases==5)
                    {
                        a->coin_in_the_hole();
                        Lmoving.remove(a);
                        if(a==&striker)
                        {

                            points[chance%2]--;

                        }
                        else{

                            points[chance%2]=points[chance%2]+2;
                            shot=true;
                        }
                    }

                    }
                        wait(3);
                    cout<<"chance"<<chance<<endl;
                    cout<<"SCORE OF PLAYER 1:"<<points[0]<<endl;
                    cout<<"SCORE OF PLAYER 2:"<<points[1]<<endl;
                    chance++;
                    if(shot==true)
                        chance--;

                    }
                    Text winner(500,400,"");
                    string _winner;
                    if(points[0]>points[1])
                    {
                        _winner=player[0]+"  WINS";
                        winner.reset(500,400,_winner);
                        winner.setColor(COLOR("green"));
                        cout<<_winner<<endl;
                    }
                    else if(points[0]<points[1])
                    {
                        _winner=player[1]+"  WINS";
                        winner.reset(500,400,_winner);
                        winner.setColor(COLOR("green"));
                        cout<<_winner<<endl;
                    }
                    else
                    {

                        winner.reset(500,400,"MATCH DRAWN");
                        winner.setColor(COLOR("green"));

                    }
                    getClick();                                                 //exits the program
                    cout<<"MATCH DRAWN"<<endl;




                        wait(1000);
                        }
