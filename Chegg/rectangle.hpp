#ifndef RECTANGLE_HPP
#define RETACNGLE_HPP

class Rectangle
{
private:
    double width_;
    double height_;

public:
    double Area();
    void Width(double w);
    void Height(double h);
    double returnWidth();
    double returnHeight();
    Rectangle(double w,double h)
    {
        this->width_=w;
        this->height_=h;
        cout<<width_<<" "<<height_<<endl;
    }
};

#endif