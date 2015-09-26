#ifndef RANDOM_H
#define RANDOM_H


class Random
{
    public:
        Random();
        ~Random();
        static float MoroInverseCumulativeNormal(float);
        static float CumulativeNormal(float);
    protected:
    private:
};

#endif // RANDOM_H
