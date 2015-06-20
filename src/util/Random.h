#ifndef MOO_RANDOM_H
#define MOO_RANDOM_H




namespace moo {



    class Random
    {
    public:
        static Random * getInstance() { return _singletonInst;};


        double rndDouble();
        double rndDouble(int min, int max);
        int rndInt(int min, int max);
        bool rndBool();


    private:
        static Random * _singletonInst ;
        Random() { }
        Random(Random const&);
        void operator=(Random const&);
    };



}

#endif //MOO_RANDOM_H
