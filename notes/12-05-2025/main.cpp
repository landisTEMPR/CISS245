#include <iostream>

class LivingThing
{
public:
    LivingThing(int id, int x)
        : id_(id), x_(x)
    {}
    int x() const
    {
        return x_;
    }
    int & x()
    {
        return x_;
    }
    int id() const
    {
        return id_;
    }
    int & id()
    {
        return id_;
    }
    virtual void talk() = 0;
private:
    int id_;
    int x_;
};
std::ostream & operator<<(std::ostream & cout, const LivingThing & lthing)
{
    cout << "<LivingThing id:" << lthing.id() << ", x:" << lthing.x() << '>';
    return cout;
}

class Human: public LivingThing
{
public:
    Human(int id, int x)
        : LivingThing(id, x)
    {}
    virtual void talk()
    {
        std::cout << "?!?!!?\n";
    }
private:
};
std::ostream & operator<<(std::ostream & cout, const Human & human)
{
    cout << "<Human id:" << human.id() << ", x:" << human.x() << '>';
    return cout;
}

class Man: public Human
{
public:
    Man(int id, int x)
        : Human(id, x)
    {}
    virtual void talk()
    {
        std::cout << "hi how are you?\n";
    }
private:
};

std::ostream & operator<<(std::ostream & cout, const Man & man)
{
    cout << "<Man id:" << man.id() << ", x:" << man.x() << '>';
    return cout;
}

class Woman: public Human
{
public:
    Woman(int id, int x)
        : Human(id, x)
    {}
    virtual void talk()
    {
        std::cout << "hello\n";
    }
private:
};
std::ostream & operator<<(std::ostream & cout, const LivingThing & lthing)
{
    cout << "<Woman id:" << woman.id() << ", x:" << woman.x() << '>';
    return cout;
}

class Dog: public LivingThing
{
public:
    Dog(int id, int x)
        : LivingThing(id, x)
    {}
    virtual void talk()
    {
        std::cout << "bark bark bark\n";
    }
private:
};

std::ostream & operator<<(std::ostream & cout, const Dog & dog)
{
    cout << "<Dog id:" << dog.id() << ", x:" << dog.x() << '>';
    return cout;
}

    
int main()
{
    Man john(0, 42);
    Dog rex(1, 43);

    LivingThing * livingthing[2] = {&john, &rex};
    for (int i = 0; i < 2; ++i)
    {
        std::cout << (*livingthing[i]); livingthing[i]->talk(); 
    }

    return 0;
}
