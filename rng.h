#pragma once

class CRng
{
public:
        CRng();
        CRng(int m_nType);
        ~CRng();

        //Seed by system timer
        void Seed();
        //Seed by a 32-bit integer
        void Seed(unsigned int seed);
        //Seed by a arbitrary buffer
        void Seed(const char *pBuf, int buflen);

        double Get01();
        int GetUniformInterval(int a, int b);
        double GetUniformInterval(double a, double b);
        double GetExponential(double mean);
        double GetTriangular(double a, double b, double c);
        double GetNormal(double mean, double std);
        double GetCustomDiscrete(int nCount, double *pfWeights, double *pfValues);
        double GetCustomContinious(int nCount, double *pfWeights, double *pfValues);

protected:
        int m_nType;

        void _init( const char *key, size_t len );
        int _rng ( char *data, size_t len );

        //RNG state
    int _x;
    int _y;
    unsigned char _m[256];
};

