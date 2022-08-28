//Widad Abdullah(SE-085)
//Muhammad Anas Khan(SE-079)

#include <iostream>
#include <iomanip>
#include <windows.h>
using namespace std;

class km_m
{
    public:
    double km;
    double m;
    public:
    void input_km()
    {
        cout << "Enter Kilometers to convert: ";
        cin >> km;
        cout <<endl;
    }
    void display()
    {
        m = km * 1000;
        cout << ">" << km << " Kilometers equals to " << m << " Meters." << endl;
    }
};
class m_km : public km_m    //Inheritance
{
    public:
    void input_m()
    {
        cout << "Enter Meters to convert to Kilometers: ";
        cin >> m;
        cout <<endl;
    }
    void display()
    {
        km = m / 1000;
        cout << ">" << m << " Meters equals to " << km << " Kilometers." << endl;
    }
};
class km_mi
{
    protected:
    km_m k;                 //Composition k
    double mi;
    public:
    void input_km()
    {
        k.input_km();
    }
    void display()
    {
        mi = k.km / 1.609;
        cout << ">" << k.km << " Kilometers equals to " << mi << " Miles." << endl;     
    }
};
class mi_km : public km_mi , public km_m  //Multiple Inheritance
{
    public:
    void input_mi()
    {
        cout << "Enter Miles to convert to Kilometers: ";
        cin >> mi;
        cout <<endl;
    }
    void display()
    {
        km = mi * 1.609;
        cout << ">" << mi << " Miles equals to " << km << " Kilometers." << endl;
    }
};
class km_y
{
    protected:
    km_m kk;        //Composition
    double y;
    public:
    void input_km()
    {
        kk.input_km();
    }
    void display()
    {
        y = kk.km * 1094;
        cout << ">" << kk.km << " Kilometers equals to " << y << " yards." << endl;     
    }
};
class y_km : public km_y , public km_m      //Multiple Inheritance
{
    public:
    void input_y()
    {
        cout << "Enter Yards to convert to Kilometers: ";
        cin >> y;
        cout <<endl;
    }
    void display()
    {
        km = y / 1094;
        cout << ">" << y << " yards equals to " << km << " Kilometers." << endl;
    }
};
class in_cm
{
    protected:
    double in;
    double cm;
    public:
    void input_in()
    {
        cout << "Enter Inches to convert to Centimeters: ";
        cin >> in;
        cout <<endl;
    }
    void display()
    {
        cm = in * 2.54;
        cout << ">" << in << " Inches equals to " << cm << " Centimeters." << endl;
    }
};
class cm_in : public in_cm  //Inheritance
{
    public:
    void input_cm()
    {
        cout << "Enter Centimeters to convert to Inches: ";
        cin >> cm;
        cout <<endl;
    }
    void display()
    {
        in = cm / 2.54;
        cout << ">" << cm << " Centimeters equals to " << in << " Inches." << endl;
    }
};
class ft_m 
{
    protected:
    double ft;
    double m;
    public:
    void input_ft()
    {
        cout << "Enter Feets to convert to Meters: ";
        cin >> ft;
        cout <<endl;
    }
    void display()
    {
        m = ft / 3.281;
        cout << ">" << ft << " Feets equals to " << m << " Meters." << endl;     
    }
};
class m_ft  : public ft_m   //Inheritance
{
    public:
    void input_m()
    {
        cout << "Enter Meters to convert to Feets: ";
        cin >> m;
        cout <<endl;
    }
    void display()
    {
        ft = m * 3.281;
        cout << ">" << m << " Meters equals to " << ft << " Feets." << endl;
    }
};

class kg_lb
{
    protected:
    double kg;
    double lb;
    public:
    friend istream &operator>>( istream &input, kg_lb &c )  //Operator Overloading 
    {
        input >> c.kg;
        c.lb = c.kg * 2.2055;
        return input;
    }
    friend ostream &operator<<( ostream &output, const kg_lb &c )
    {
        output << ">" << c.kg << " Kilograms equals to " << c.lb << " pounds.";
        return output;
    }

};
class lb_kg : public kg_lb      //Inheritance
{
    friend istream &operator>>( istream &input, lb_kg &c )  //Operator Overloading 
    {
        input >> c.lb;
        c.kg = c.lb / 2.2055;
        return input;
    }
    friend ostream &operator<<( ostream &output, const lb_kg &c )
    {
        output << ">" << c.lb << " Pounds equals to " << c.kg << " Kilograms.";
        return output;
    }

};
class cl_fr{
    public:
        double centigrade;
        double fahrenhiet;
        void input_cl()
        {
            cout<<"Enter the value in centigrade to convert : "<<endl;
            cin>>centigrade;
        }
        void display()
        {
            fahrenhiet = (1.8*centigrade)+32;
            cout<<">"<<centigrade<<" centigrade equals to "<<fahrenhiet<<" fahrenhiets."<<endl;
        }
};
class fr_cl : public cl_fr
{                                  //Inheritance
    public:
        void input_fr()
        {
            cout<<"Enter the value in fahrenhiet to convert it into centigrade: "<<endl;
            cin>>fahrenhiet;
        }
        void display(){
            centigrade = 0.55*(fahrenhiet-32);
            cout<<">"<<fahrenhiet<<" fahrenhiet equals to "<<centigrade<<" centigrades."<<endl;
        }
};

class cl_kel{
    public:
        cl_fr cc;       //Composition
        double kelvin;
        void input_cl()
        {
        cc.input_cl();
        }
        void display()
        {
            kelvin = cc.centigrade+273; 
            cout<<">"<<cc.centigrade<<" centigrades equals to "<<kelvin<<" kelvins"<<endl;
        }  
};
class kel_cl: public cl_kel , public cl_fr   //Multiple Inheritance
    {                       
    public:
        void input_kel()
        {
            cout<<"Enter the value in Kelvins to convert it into centigrade"<<endl;
            cin>>kelvin;
        }
    void display()
        {
        centigrade = kelvin-273;
        cout<<">"<<kelvin<<" kelvin equals to "<<centigrade<<" centigrades."<<endl;
        }
};
class kel_fr : public cl_fr, public cl_kel{           //Multiple Inheritance
    public:
        void input_kl(){
            cout<<"Enter the value in kelvins to convert it into fahrenhiet"<<endl;
            cin>>kelvin;
        }
        void display(){
        fahrenhiet = ((1.8*(kelvin-273.15))+32);
        cout<<">"<<kelvin<<" kelvin equals to "<<fahrenhiet<<" fahrenhiets."<<endl;
    }
};
class km_ms
{
    public:
        double kmh;
        double ms;
        void input_km()
        {
            cout<<"Enter Speed in km/hr: ";
            cin>>kmh;
        }
        void display()
        {
            ms=(kmh*1000)/3600;
            cout<<">"<<kmh<<" km/hr equals to "<<ms<<" m/s"<<endl;
        }
};
class ms_km: km_ms
{
    public:
        double ms;
        void input_ms()
        {
            cout<<"Enter the value in meter per seconds"<<endl;
            cin>>ms;
        }
        void display(){
            kmh=(ms*3600/1000);
            cout<<">"<<ms<<" m/s equals to "<<kmh<<" km/hr"<<endl;
        }
};

int main()
{
    char choice;

    cout << setprecision(2) << fixed << showpoint;
    cout << "\n\n";
    char arr[]={'U','N','I','T',' ','C','O','N','V','E','R','T','E','R'};
    for(int i=0;i<14;i++)   //For Loop
    {
        cout << arr[i] ;
        Sleep(70);
    }
    do                      //Do-While Loop
    {
        cout << endl << endl;
        cout << "  Unit Conversion List" << endl << endl;
        cout << "A: Kilometers  ->  Meter" << endl;
        cout << "B: Meter       ->  Kilometer" << endl;
        cout << "C: Kilometers  ->  Miles" << endl;
        cout << "D: Miles       ->  Kilometers" << endl;
        cout << "E: Kilometers  ->  Yards" << endl;
        cout << "F: Yards       ->  Kilometers" << endl;
        cout << "G: Inches      ->  Centimeters" << endl;
        cout << "H: Centimeters ->  Inches" << endl;
        cout << "I: Feets       ->  Meters" << endl;
        cout << "J: Meters      ->  Feets" << endl;
        cout << "K: Kilograms   ->  Pounds" << endl;
        cout << "L: Pounds      ->  Kilograms" << endl;
        cout << "M: Celsius     ->  Fahrenhiet" <<endl;
        cout << "N: Fahrenhiet  ->  Celsius" <<endl;
        cout << "O: Celsius     ->  Kelvin" <<endl;
        cout << "P: Kelvin      ->  Celsius" <<endl;
        cout << "Q: Kelvin      ->  Fahrenhiet" <<endl;
        cout << "R: Km/hr       ->   m/s    " <<endl;
        cout << "S: m/s         ->   Km/hr    " <<endl<<endl;





        cout << "Enter Respective Choice..." << endl;
        cout << "Enter 0 to Exit the Program!" << endl;
        cin >> choice;
        switch(choice)      //Switch
        {
            case 'a':
            case 'A': km_m a;
            a.input_km();
            a.display();
            break;
            case 'b':
            case 'B':m_km b;
            b.input_m();
            b.display();
            break;
            case 'c':
            case 'C':km_mi c;
            c.input_km();
            c.display();
            break;
            case 'd':
            case 'D':mi_km d;
            d.input_mi();
            d.display();
            break;
            case 'e':
            case 'E':km_y e;
            e.input_km();
            e.display();
            break;
            case 'f':
            case 'F':y_km f;
            f.input_y();
            f.display();
            break;
            case 'g':
            case 'G':in_cm g;
            g.input_in();
            g.display();
            break;
            case 'h':
            case 'H':cm_in h;
            h.input_cm();
            h.display();
            break;
            case 'i':
            case 'I':ft_m i;
            i.input_ft();
            i.display();
            break;
            case 'j':
            case 'J':m_ft j;
            j.input_m();
            j.display();
            break;
            case 'k':
            case 'K':kg_lb k;
            cout << "Enter Kilograms to convert to Pounds: ";
            cin >> k;
            cout << k;
            break;
            case 'l':
            case 'L': lb_kg l;
            cout << "Enter Pounds to convert to Kilograms: ";
            cin >> l;
            cout << l;
            break;
            case 'm':
            case 'M': cl_fr m;
            m.input_cl();
            m.display();
            break;
            case 'n':
            case 'N':  fr_cl n;
            n.input_fr();
            n.display();
            break;
            case 'o':
            case 'O':  cl_kel o;
            o.input_cl();
            o.display();
            break;
            case 'p':
            case 'P':  kel_cl p;
            p.input_kel();
            p.display();
            break;
            case 'q':
            case 'Q':  kel_fr q;
            q.input_kl();
            q.display();
            break;
            case 'r':
            case 'R': km_ms r;
            r.input_km();
            r.display();
            break;
            case 's':
            case 'S': ms_km s;
            s.input_ms();
            s.display();
            break;


            case '0':cout<<"Exiting";
            for(int i=0;i<7;i++)
            {cout<<".";
            Sleep(100);}
            break;
            default:cout<<"Invalid Input!"<<endl;
        }

    }while (choice != '0' );    //Priming the read
    
    return 0;
}