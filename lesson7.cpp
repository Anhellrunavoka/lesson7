#include <iostream>
using namespace std;
class Time {
    int sec;
    int min;
    int hour;
    void normal() {
        if (sec == 60) {
            min++;
            sec = 0;
        }
        if (min == 60) {
            hour++;
            min = 0;
        }
        if (hour == 24) {
            sec = 0;
            min = 0;
            hour = 0;
        }
    }
public:
    Time() :sec{ 0 }, min{ 0 }, hour{ 0 } {}
    Time(int secc,int minn,int hourr) :sec{ secc }, min{ minn }, hour{ hourr } {
        normal();
    }
    friend const Time operator++(Time& tiime)  {
           tiime.sec++;
           tiime.normal();
           return  tiime;
    }
    friend const Time operator-(const Time& tiime1, const Time& tiime2) {
        Time tiime3;
        if (tiime1.hour >= tiime2.hour ) {
            tiime3.sec = tiime1.sec - tiime2.sec;
            if (tiime2.sec > tiime1.sec) {
                tiime3.sec = (tiime1.sec + 60) - tiime2.sec;
                if (tiime2.min > (tiime1.min-1)) {
                    tiime3.min = (tiime1.min + 60) - tiime2.min;
                    tiime3.hour = (tiime1.hour - 1) - tiime2.hour;
                }
                else {
                    tiime3.min = tiime1.min - tiime2.min;
                    tiime3.hour = tiime1.hour - tiime2.hour;
                }
            }
            else {
                tiime3.sec = tiime1.sec - tiime2.sec;
                if (tiime2.min > tiime1.min) {
                    tiime3.min = (tiime1.min + 60) - tiime2.min;
                    tiime3.hour = (tiime1.hour - 1) - tiime2.hour;
                }
                else {
                    tiime3.min = tiime1.min - tiime2.min;
                    tiime3.hour = tiime1.hour - tiime2.hour;
                }
            }
        }
        return  tiime3;
    }
    bool operator==(const Time& tiime) const {
        return (hour == tiime.hour && min == tiime.min && sec == tiime.sec);
    }
    bool operator!=(const Time& tiime) const {
        return !(*this == tiime);
    }
    bool operator>(const Time& tiime) const {
        if (hour == tiime.hour && min == tiime.min && sec > tiime.sec) return true;
        else return false;
    }
    bool operator<(const Time& tiime) const {
        return !(*this > tiime || *this == tiime);
    }
    friend ostream& operator<<(ostream& output, const Time& tiime) {
        output << tiime.hour << ":" << tiime.min << ":" << tiime.sec;
        return output;
    }
    /*friend istream& operator>>(istream& input, const Time& tiime) {
        input >> tiime.hour;
        input.ignore(1);
        input >> tiime.min;
        input.ignore(1);
        input >> tiime.sec;
        return input;
    }*/
    Time& operator+=(int secc) {
        sec += secc;
        normal();
        return *this;
    }
    Time& operator-=(int secc) {
        sec -= secc;
        normal();
        return *this;
    }
    void operator()(int h, int m, int s) {
        hour = h;
        min = m;
        sec = s;
        normal();
    }
    Time(const Time&& timee) {
        timee.sec = 0;
        timee.min = 0;
        timee.hour = 0;
    }
    Time operator=(const Time&& timee) {
        if (!(this == &timee)) {
            sec = timee.sec;
            min = timee.min;
            hour = timee.min;

            timee.sec = 0;
            timee.min = 0;
            timee.hour = 0;
        }
        return *this;
    }
};
int main()
{
    Time t(1,4,6);
    ++t;
    cout << t << endl;
    Time t2(0,3,7);
    Time t3=t-t2;
    cout << t3<<endl;
    bool a = t > t2, b = t < t2,c=t2==t3,d=t!=t2;
    cout << a << " " << b<< " " << c<< " " << d;
    t -= 2;
    t2 += 7;
    cout << t << " " << t2 << endl;
}

