//-----------------------------------------------------------------------------
// Copyright 2022, Ed Keenan, all rights reserved.
//----------------------------------------------------------------------------- 

#include "MathEngine.h"

namespace Azul
{
// Do your magic here
   
    Matrix::Matrix()
    {
        this->_m0 = 0;
        this->_m1 = 0;
        this->_m2 = 0;
        this->_m3 = 0;
        this->_m4 = 0;
        this->_m5 = 0;
        this->_m6 = 0;
        this->_m7 = 0;
        this->_m8 = 0;
        this->_m9 = 0;
        this->_m10 = 0;
        this->_m11 = 0;
        this->_m12 = 0;
        this->_m13 = 0;
        this->_m14 = 0;
        this->_m15 = 0;

    }

    Matrix::Matrix(Vect vA, Vect vB, Vect vC, Vect vD)
    {
        this->_v0 = vA;
        this->_v1 = vB;
        this->_v2 = vC;
        this->_v3 = vD;

        this->SetMs(vA);
        this->SetMs(vB);
        this->SetMs(vC);
        this->SetMs(vD);
    }

    Matrix::Matrix(const Matrix& inMatrix)
    {
        this->_v0 = inMatrix._v0;
        this->_v1 = inMatrix._v1;
        this->_v2 = inMatrix._v2;
        this->_v3 = inMatrix._v3;
    }

    const Matrix& Matrix::operator=(const Matrix& inMatrix)
    {
        this->_v0 = inMatrix._v0;
        this->_v1 = inMatrix._v1;
        this->_v2 = inMatrix._v2;
        this->_v3 = inMatrix._v3;

        return *this;
    }

    Matrix::~Matrix()
    {
    }

    Matrix Matrix::T()
    {
        //swap rows and columns 
        //our matrix is a 4x4
        Vect v0 = Vect(_rows[0][x], _rows[1][x], _rows[2][x], _rows[3][x]);
        Vect v1 = Vect(_rows[0][y], _rows[1][y], _rows[2][y], _rows[3][y]);
        Vect v2 = Vect(_rows[0][z], _rows[1][z], _rows[2][z], _rows[3][z]);
        Vect v3 = Vect(_rows[0][w], _rows[1][w], _rows[2][w], _rows[3][w]);

        Matrix tmpMat = Matrix(v0, v1, v2, v3);
        *this = tmpMat;

        return tmpMat;

    }

    Matrix Matrix::getT()
    {
        //swap rows and columns 
        //our matrix is a 4x4
        Vect v0 = Vect(_rows[0][x], _rows[1][x], _rows[2][x], _rows[3][x]);
        Vect v1 = Vect(_rows[0][y], _rows[1][y], _rows[2][y], _rows[3][y]);
        Vect v2 = Vect(_rows[0][z], _rows[1][z], _rows[2][z], _rows[3][z]);
        Vect v3 = Vect(_rows[0][w], _rows[1][w], _rows[2][w], _rows[3][w]);

        Matrix tmpMat = Matrix(v0, v1, v2, v3);
        //this = tmpMat;

        return tmpMat;
    }

    Matrix::Matrix(Matrix::Special special)
    {
        if (special == Matrix::Special::Identity)
        {
            this->_m0 = 1.0f;
            this->_m1 = 0.0f;
            this->_m2 = 0.0f;
            this->_m3 = 0.0f;
            this->_m4 = 0.0f;
            this->_m5 = 1.0f;
            this->_m6 = 0.0f;
            this->_m7 = 0.0f;
            this->_m8 = 0.0f;
            this->_m9 = 0.0f;
            this->_m10 = 1.0f;
            this->_m11 = 0.0f;
            this->_m12 = 0.0f;
            this->_m13 = 0.0f;
            this->_m14 = 0.0f;
            this->_m15 = 1.0f;       
        }
        else if (special == Matrix::Special::Zero)
        {
            this->_m0 = 0.0f;
            this->_m1 = 0.0f;
            this->_m2 = 0.0f;
            this->_m3 = 0.0f;
            this->_m4 = 0.0f;
            this->_m5 = 0.0f;
            this->_m6 = 0.0f;
            this->_m7 = 0.0f;
            this->_m8 = 0.0f;
            this->_m9 = 0.0f;
            this->_m10 = 0.0f;
            this->_m11 = 0.0f;
            this->_m12 = 0.0f;
            this->_m13 = 0.0f;
            this->_m14 = 0.0f;
            this->_m15 = 0.0f;           
        }
    }

    Matrix::Matrix(Matrix::Trans tran, float in1, float in2, float in3)
    {
        if (tran == Matrix::Trans::XYZ)
        {
            this->_m0 = 1.0f;
            this->_m1 = 0.0f;
            this->_m2 = 0.0f;
            this->_m3 = 0.0f;
            this->_m4 = 0.0f;
            this->_m5 = 1.0f;
            this->_m6 = 0.0f;
            this->_m7 = 0.0f;
            this->_m8 = 0.0f;
            this->_m9 = 0.0f;
            this->_m10 = 1.0f;
            this->_m11 = 0.0f;
            this->_m12 = in1;
            this->_m13 = in2;
            this->_m14 = in3;
            this->_m15 = 1.0f;
        }
    }

    Matrix::Matrix(Matrix::Trans tran, Vect inVect)
    {
        float in1 = inVect.x();
        float in2 = inVect.y();
        float in3 = inVect.z();

        if (tran == Matrix::Trans::XYZ)
        {
            this->_m0 = 1.0;
            this->_m1 = 0.0f;
            this->_m2 = 0.0f;
            this->_m3 = 0.0f;
            this->_m4 = 0.0f;
            this->_m5 = 1.0;
            this->_m6 = 0.0f;
            this->_m7 = 0.0f;
            this->_m8 = 0.0f;
            this->_m9 = 0.0f;
            this->_m10 = 1.0;
            this->_m11 = 0.0f;
            this->_m12 = in1;
            this->_m13 = in2;
            this->_m14 = in3;
            this->_m15 = 1.0f;
        }
    }

    Matrix::Matrix(Matrix::Scale scale, float in1, float in2, float in3)
    {
        if (scale == Matrix::Scale::XYZ)
        {
            this->_m0 = in1;
            this->_m1 = 0.0f;
            this->_m2 = 0.0f;
            this->_m3 = 0.0f;
            this->_m4 = 0.0f;
            this->_m5 = in2;
            this->_m6 = 0.0f;
            this->_m7 = 0.0f;
            this->_m8 = 0.0f;
            this->_m9 = 0.0f;
            this->_m10 = in3;
            this->_m11 = 0.0f;
            this->_m12 = 0.0f;
            this->_m13 = 0.0f;
            this->_m14 = 0.0f;
            this->_m15 = 1.0f;
        }
    }

    Matrix::Matrix(Matrix::Scale scale, Vect inVect)
    {
        float in1 = inVect.x();
        float in2 = inVect.y();
        float in3 = inVect.z();

        if (scale == Matrix::Scale::XYZ)
        {
            this->_m0 = in1;
            this->_m1 = 0.0f;
            this->_m2 = 0.0f;
            this->_m3 = 0.0f;
            this->_m4 = 0.0f;
            this->_m5 = in2;
            this->_m6 = 0.0f;
            this->_m7 = 0.0f;
            this->_m8 = 0.0f;
            this->_m9 = 0.0f;
            this->_m10 = in3;
            this->_m11 = 0.0f;
            this->_m12 = 0.0f;
            this->_m13 = 0.0f;
            this->_m14 = 0.0f;
            this->_m15 = 1.0f;
        }
    }

    Matrix::Matrix(Matrix::Rot rot)
    {
    }

    Matrix::Matrix(Matrix::Rot rot, Vect& inVect, float inFloat)
    {
        if (rot == Matrix::Rot::AxisAngle)
        {
            // angle
            // axis;
            const float angle_a = 0.5f * inFloat;
            float cos_a;
            float sin_a;

            cos_a = cosf(angle_a);
            sin_a = sinf(angle_a);

            Vect qV = inVect.getNorm();

            qV *= sin_a;

            Vect Q;
            Q[x] = qV[x];
            Q[y] = qV[y];
            Q[z] = qV[z];
            Q[w] = cos_a;

            // this function has been transposed
            float x2, y2, z2;
            float xx, xy, xz;
            float yy, yz, zz;
            float wx, wy, wz;

            // ADD test to make sure that quat is normalized

            x2 = Q[x] + Q[x];
            y2 = Q[y] + Q[y];
            z2 = Q[z] + Q[z];

            xx = Q[x] * x2;
            xy = Q[x] * y2;
            xz = Q[x] * z2;

            yy = Q[y] * y2;
            yz = Q[y] * z2;
            zz = Q[z] * z2;

            wx = Q[w] * x2;
            wy = Q[w] * y2;
            wz = Q[w] * z2;

            this->_m0 = 1.0f - (yy + zz);
            this->_m1 = xy + wz;
            this->_m2 = xz - wy;
            this->_m3 = 0.0f;

            this->_m4 = xy - wz;
            this->_m5 = 1.0f - (xx + zz);
            this->_m6 = yz + wx;
            this->_m7 = 0.0f;

            this->_m8 = xz + wy;
            this->_m9 = yz - wx;
            this->_m10 = 1.0f - (xx + yy);
            this->_m11 = 0.0f;

            this->_v3.set(0.0f, 0.0f, 0.0f, 1.0f);
        }
    }

    Matrix::Matrix(Matrix::Rot1 rot, float inFloat)
    {
        if (rot == Matrix::Rot1::X)
        {
            this->_m0 = 1.0f;
            this->_m1 = 0.0f;
            this->_m2 = 0.0f;
            this->_m3 = 0.0f;
            this->_m4 = 0.0f;
            this->_m5 = Trig::cos(inFloat);
            this->_m6 = Trig::sin(inFloat);
            this->_m7 = 0.0f;
            this->_m8 = 0.0f;
            this->_m9 = -Trig::sin(inFloat);
            this->_m10 = Trig::cos(inFloat);
            this->_m11 = 0.0f;
            this->_m12 = 0.0f;
            this->_m13 = 0.0f;
            this->_m14 = 0.0f;
            this->_m15 = 1.0f;
        }
        else if (rot == Matrix::Rot1::Y)
        {
            this->_m0 = Trig::cos(inFloat);
            this->_m1 = 0.0f;
            this->_m2 = -Trig::sin(inFloat);
            this->_m3 = 0.0f;
            this->_m4 = 0.0f;
            this->_m5 = 1.0f;
            this->_m6 = 0.0f;
            this->_m7 = 0.0f;
            this->_m8 = Trig::sin(inFloat);
            this->_m9 = 0.0f;
            this->_m10 = Trig::cos(inFloat);
            this->_m11 = 0.0f;
            this->_m12 = 0.0f;
            this->_m13 = 0.0f;
            this->_m14 = 0.0f;
            this->_m15 = 1.0f;
        }
        else if (rot == Matrix::Rot1::Z)
        {
            this->_m0 = Trig::cos(inFloat);
            this->_m1 = Trig::sin(inFloat);
            this->_m2 = 0.0f;
            this->_m3 = 0.0f;
            this->_m4 = -Trig::sin(inFloat);
            this->_m5 = Trig::cos(inFloat);
            this->_m6 = 0.0f;
            this->_m7 = 0.0f;
            this->_m8 = 0.0f;
            this->_m9 = 0.0f;
            this->_m10 = 1.0f;
            this->_m11 = 0.0f;
            this->_m12 = 0.0f;
            this->_m13 = 0.0f;
            this->_m14 = 0.0f;
            this->_m15 = 1.0f;
        }
    }

    Matrix::Matrix(Matrix::Rot3 rot, float inFloatX, float inFloatY, float inFloatZ)
    {
        Matrix rotX;
        Matrix rotY;
        Matrix rotZ;

        if (rot == Matrix::Rot3::XYZ)
        {
            rotX.set(Matrix::Rot1::X, inFloatX);
            rotY.set(Matrix::Rot1::Y, inFloatY);
            rotZ.set(Matrix::Rot1::Z, inFloatZ);

            *this = rotX * rotY * rotZ;
        }
    }

    Matrix Matrix::operator*(Matrix inMatrix)
    {
        Matrix newMatrix;

        //Vector 1
        newMatrix._m0 = this->m0() * inMatrix.m0() + this->m1() * inMatrix.m4() + this->m2() * inMatrix.m8() + this->m3() * inMatrix.m12();
        newMatrix._m1 = this->m0() * inMatrix.m1() + this->m1() * inMatrix.m5() + this->m2() * inMatrix.m9() + this->m3() * inMatrix.m13();
        newMatrix._m2 = this->m0() * inMatrix.m2() + this->m1() * inMatrix.m6() + this->m2() * inMatrix.m10() + this->m3() * inMatrix.m14();
        newMatrix._m3 = this->m0() * inMatrix.m3() + this->m1() * inMatrix.m7() + this->m2() * inMatrix.m11() + this->m3() * inMatrix.m15();

        //Vector 2
        newMatrix._m4 = this->m4() * inMatrix.m0() + this->m5() * inMatrix.m4() + this->m6() * inMatrix.m8() + this->m7() * inMatrix.m12();
        newMatrix._m5 = this->m4() * inMatrix.m1() + this->m5() * inMatrix.m5() + this->m6() * inMatrix.m9() + this->m7() * inMatrix.m13();
        newMatrix._m6 = this->m4() * inMatrix.m2() + this->m5() * inMatrix.m6() + this->m6() * inMatrix.m10() + this->m7() * inMatrix.m14();
        newMatrix._m7 = this->m4() * inMatrix.m3() + this->m5() * inMatrix.m7() + this->m6() * inMatrix.m11() + this->m7() * inMatrix.m15();

        //Vector 3
        newMatrix._m8 = this->m8() * inMatrix.m0() + this->m9() * inMatrix.m4() + this->m10() * inMatrix.m8() + this->m11() * inMatrix.m12();
        newMatrix._m9 = this->m8() * inMatrix.m1() + this->m9() * inMatrix.m5() + this->m10() * inMatrix.m9() + this->m11() * inMatrix.m13();
        newMatrix._m10 = this->m8() * inMatrix.m2() + this->m9() * inMatrix.m6() + this->m10() * inMatrix.m10() + this->m11() * inMatrix.m14();
        newMatrix._m11 = this->m8() * inMatrix.m3() + this->m9() * inMatrix.m7() + this->m10() * inMatrix.m11() + this->m11() * inMatrix.m15();

        //Vector 4
        newMatrix._m12 = this->m12() * inMatrix.m0() + this->m13() * inMatrix.m4() + this->m14() * inMatrix.m8() + this->m15() * inMatrix.m12();
        newMatrix._m13 = this->m12() * inMatrix.m1() + this->m13() * inMatrix.m5() + this->m14() * inMatrix.m9() + this->m15() * inMatrix.m13();
        newMatrix._m14 = this->m12() * inMatrix.m2() + this->m13() * inMatrix.m6() + this->m14() * inMatrix.m10() + this->m15() * inMatrix.m14();
        newMatrix._m15 = this->m12() * inMatrix.m3() + this->m13() * inMatrix.m7() + this->m14() * inMatrix.m11() + this->m15() * inMatrix.m15();


        return newMatrix;
    }
    Matrix Matrix::operator*=(Matrix inMatrix)
    {
        Matrix newMatrix;

        //Vector 1
        newMatrix._m0 = this->m0() * inMatrix.m0() + this->m1() * inMatrix.m4() + this->m2() * inMatrix.m8() + this->m3() * inMatrix.m12();
        newMatrix._m1 = this->m0() * inMatrix.m1() + this->m1() * inMatrix.m5() + this->m2() * inMatrix.m9() + this->m3() * inMatrix.m13();
        newMatrix._m2 = this->m0() * inMatrix.m2() + this->m1() * inMatrix.m6() + this->m2() * inMatrix.m10() + this->m3() * inMatrix.m14();
        newMatrix._m3 = this->m0() * inMatrix.m3() + this->m1() * inMatrix.m7() + this->m2() * inMatrix.m11() + this->m3() * inMatrix.m15();

        //Vector 2
        newMatrix._m4 = this->m4() * inMatrix.m0() + this->m5() * inMatrix.m4() + this->m6() * inMatrix.m8() + this->m7() * inMatrix.m12();
        newMatrix._m5 = this->m4() * inMatrix.m1() + this->m5() * inMatrix.m5() + this->m6() * inMatrix.m9() + this->m7() * inMatrix.m13();
        newMatrix._m6 = this->m4() * inMatrix.m2() + this->m5() * inMatrix.m6() + this->m6() * inMatrix.m10() + this->m7() * inMatrix.m14();
        newMatrix._m7 = this->m4() * inMatrix.m3() + this->m5() * inMatrix.m7() + this->m6() * inMatrix.m11() + this->m7() * inMatrix.m15();

        //Vector 3
        newMatrix._m8 = this->m8() * inMatrix.m0() + this->m9() * inMatrix.m4() + this->m10() * inMatrix.m8() + this->m11() * inMatrix.m12();
        newMatrix._m9 = this->m8() * inMatrix.m1() + this->m9() * inMatrix.m5() + this->m10() * inMatrix.m9() + this->m11() * inMatrix.m13();
        newMatrix._m10 = this->m8() * inMatrix.m2() + this->m9() * inMatrix.m6() + this->m10() * inMatrix.m10() + this->m11() * inMatrix.m14();
        newMatrix._m11 = this->m8() * inMatrix.m3() + this->m9() * inMatrix.m7() + this->m10() * inMatrix.m11() + this->m11() * inMatrix.m15();

        //Vector 4
        newMatrix._m12 = this->m12() * inMatrix.m0() + this->m13() * inMatrix.m4() + this->m14() * inMatrix.m8() + this->m15() * inMatrix.m12();
        newMatrix._m13 = this->m12() * inMatrix.m1() + this->m13() * inMatrix.m5() + this->m14() * inMatrix.m9() + this->m15() * inMatrix.m13();
        newMatrix._m14 = this->m12() * inMatrix.m2() + this->m13() * inMatrix.m6() + this->m14() * inMatrix.m10() + this->m15() * inMatrix.m14();
        newMatrix._m15 = this->m12() * inMatrix.m3() + this->m13() * inMatrix.m7() + this->m14() * inMatrix.m11() + this->m15() * inMatrix.m15();

        *this = newMatrix;

        return *this;
    }
    Matrix Matrix::operator+(Matrix inMatrix)
    {
        Matrix newMatrix;

        //Vector 1
        newMatrix._m0 = this->_m0 + inMatrix._m0;
        newMatrix._m1 = this->_m1 + inMatrix._m1;
        newMatrix._m2 = this->_m2 + inMatrix._m2;
        newMatrix._m3 = this->_m3 + inMatrix._m3;
        
        //newMatrix._v0 = this->_v0 + inMatrix._v0;

        //Vector 2
        newMatrix._m4 = this->_m4 + inMatrix._m4;
        newMatrix._m5 = this->_m5 + inMatrix._m5;
        newMatrix._m6 = this->_m6 + inMatrix._m6;
        newMatrix._m7 = this->_m7 + inMatrix._m7;        

        //newMatrix._v1 = this->_v1 + inMatrix._v1;

        //Vector 3
        newMatrix._m8 = this->_m8 + inMatrix._m8;
        newMatrix._m9 = this->_m9 + inMatrix._m9;
        newMatrix._m10 = this->_m10 + inMatrix._m10;
        newMatrix._m11 = this->_m11 + inMatrix._m11;        

        //newMatrix._v2 = this->_v2 + inMatrix._v2;

        //Vector 4
        newMatrix._m12 = this->_m12 + inMatrix._m12;
        newMatrix._m13 = this->_m13 + inMatrix._m13;
        newMatrix._m14 = this->_m14 + inMatrix._m14;
        newMatrix._m15 = this->_m15 + inMatrix._m15;    

        //newMatrix._v3 = this->_v3 + inMatrix._v3;

        return newMatrix;

    }
    Matrix Matrix::operator+=(Matrix inMatrix)
    {
        //Vector 1
        this->_m0 += inMatrix._m0;
        this->_m1 += inMatrix._m1;
        this->_m2 += inMatrix._m2;
        this->_m3 += inMatrix._m3;

        //newMatrix._v0 = this->_v0 + inMatrix._v0;

        //Vector 2
        this->_m4 += inMatrix._m4;
        this->_m5 += inMatrix._m5;
        this->_m7 += inMatrix._m7;
        this->_m6 += inMatrix._m6;

        //newMatrix._v1 = this->_v1 + inMatrix._v1;

        //Vector 3
        this->_m8 += inMatrix._m8;
        this->_m9 += inMatrix._m9;
        this->_m10 += inMatrix._m10;
        this->_m11 += inMatrix._m11;

        //newMatrix._v2 = this->_v2 + inMatrix._v2;

        //Vector 4
        this->_m12 += inMatrix._m12;
        this->_m13 += inMatrix._m13;
        this->_m14 += inMatrix._m14;
        this->_m15 += inMatrix._m15;

        //newMatrix._v3 = this->_v3 + inMatrix._v3;

        return *this;
    }

    Matrix Matrix::operator-(Matrix inMatrix)
    {
        Matrix newMatrix;

        //Vector 1
        newMatrix._m0 = this->_m0 - inMatrix._m0;
        newMatrix._m1 = this->_m1 - inMatrix._m1;
        newMatrix._m2 = this->_m2 - inMatrix._m2;
        newMatrix._m3 = this->_m3 - inMatrix._m3;

        //newMatrix._v0 = this->_v0 + inMatrix._v0;

        //Vector 2
        newMatrix._m4 = this->_m4 - inMatrix._m4;
        newMatrix._m5 = this->_m5 - inMatrix._m5;
        newMatrix._m6 = this->_m6 - inMatrix._m6;
        newMatrix._m7 = this->_m7 - inMatrix._m7;

        //newMatrix._v1 = this->_v1 + inMatrix._v1;

        //Vector 3
        newMatrix._m8 = this->_m8 - inMatrix._m8;
        newMatrix._m9 = this->_m9 - inMatrix._m9;
        newMatrix._m10 = this->_m10 - inMatrix._m10;
        newMatrix._m11 = this->_m11 - inMatrix._m11;

        //newMatrix._v2 = this->_v2 + inMatrix._v2;

        //Vector 4
        newMatrix._m12 = this->_m12 - inMatrix._m12;
        newMatrix._m13 = this->_m13 - inMatrix._m13;
        newMatrix._m14 = this->_m14 - inMatrix._m14;
        newMatrix._m15 = this->_m15 - inMatrix._m15;

        //newMatrix._v3 = this->_v3 + inMatrix._v3;

        return newMatrix;
    }

    Matrix Matrix::operator-=(Matrix inMatrix)
    {
        //Vector 1
        this->_m0 -= inMatrix._m0;
        this->_m1 -= inMatrix._m1;
        this->_m2 -= inMatrix._m2;
        this->_m3 -= inMatrix._m3;

        //newMatrix._v0 = this->_v0 + inMatrix._v0;

        //Vector 2
        this->_m4 -= inMatrix._m4;
        this->_m5 -= inMatrix._m5;
        this->_m7 -= inMatrix._m7;
        this->_m6 -= inMatrix._m6;

        //newMatrix._v1 = this->_v1 + inMatrix._v1;

        //Vector 3
        this->_m8 -= inMatrix._m8;
        this->_m9 -= inMatrix._m9;
        this->_m10 -= inMatrix._m10;
        this->_m11 -= inMatrix._m11;

        //newMatrix._v2 = this->_v2 + inMatrix._v2;

        //Vector 4
        this->_m12 -= inMatrix._m12;
        this->_m13 -= inMatrix._m13;
        this->_m14 -= inMatrix._m14;
        this->_m15 -= inMatrix._m15;

        //newMatrix._v3 = this->_v3 + inMatrix._v3;

        return *this;
    }

    Matrix Matrix::operator+()
    {
        Matrix newMatrix;

        newMatrix._v0 = this->_v0;
        SetMs(newMatrix._v0);

        newMatrix._v1 = this->_v1;
        SetMs(newMatrix._v1);

        newMatrix._v2 = this->_v2;
        SetMs(newMatrix._v2);

        newMatrix._v3 = this->_v3;
        SetMs(newMatrix._v3);

        return newMatrix;
    }

    Matrix Matrix::operator-()
    {
        Matrix newMatrix;

        newMatrix._v0 = -this->_v0;
        newMatrix._m0 = -this->_m0;
        newMatrix._m1 = -this->_m1;
        newMatrix._m2 = -this->_m2;
        newMatrix._m3 = -this->_m3;
        

        newMatrix._v1 = -this->_v1;
        newMatrix._m4 = -this->_m4;
        newMatrix._m5 = -this->_m5;
        newMatrix._m6 = -this->_m6;
        newMatrix._m7 = -this->_m7;

        newMatrix._v2 = -this->_v2;
        newMatrix._m8 = -this->_m8;
        newMatrix._m9 = -this->_m9;
        newMatrix._m10 = -this->_m10;
        newMatrix._m11 = -this->_m11;

        newMatrix._v3 = -this->_v3;
        newMatrix._m12 = -this->_m12;
        newMatrix._m13 = -this->_m13;
        newMatrix._m14 = -this->_m14;
        newMatrix._m15 = -this->_m15;

        return newMatrix;
    }

    void Matrix::SetMs(Vect& inVect)
    {
        if (this->_v0.isEqual(inVect, 0.1f))
        {
            this->_m0 = inVect.x();
            this->_m1 = inVect.y();
            this->_m2 = inVect.z();
            this->_m3 = inVect.w();
        }
        else if (this->_v1.isEqual(inVect, 0.1f))
        {
            this->_m4 = inVect.x();
            this->_m5 = inVect.y();
            this->_m6 = inVect.z();
            this->_m7 = inVect.w(); 
        }
        else if (this->_v2.isEqual(inVect, 0.1f))
        {
            this->_m8 = inVect.x();
            this->_m9 = inVect.y();
            this->_m10 = inVect.z();
            this->_m11 = inVect.w();
        }
        else if (this->_v3.isEqual(inVect, 0.1f))
        {
            this->_m12 = inVect.x();
            this->_m13 = inVect.y();
            this->_m14 = inVect.z();
            this->_m15 = inVect.w();
        }
    }

    void Matrix::set(Matrix::Special type)
    {
        if (type == Matrix::Special::Identity)
        {
            this->_m0 = 1.0f;
            this->_m1 = 0.0f;
            this->_m2 = 0.0f;
            this->_m3 = 0.0f;
            this->_m4 = 0.0f;
            this->_m5 = 1.0f;
            this->_m6 = 0.0f;
            this->_m7 = 0.0f;
            this->_m8 = 0.0f;
            this->_m9 = 0.0f;
            this->_m10 = 1.0f;
            this->_m11 = 0.0f;
            this->_m12 = 0.0f;
            this->_m13 = 0.0f;
            this->_m14 = 0.0f;
            this->_m15 = 1.0f;
        }
        else if (type == Matrix::Special::Zero)
        {
            this->_m0 = 0.0f;
            this->_m1 = 0.0f;
            this->_m2 = 0.0f;
            this->_m3 = 0.0f;
            this->_m4 = 0.0f;
            this->_m5 = 0.0f;
            this->_m6 = 0.0f;
            this->_m7 = 0.0f;
            this->_m8 = 0.0f;
            this->_m9 = 0.0f;
            this->_m10 = 0.0f;
            this->_m11 = 0.0f;
            this->_m12 = 0.0f;
            this->_m13 = 0.0f;
            this->_m14 = 0.0f;
            this->_m15 = 0.0f;
        }
    }

    void Matrix::set(Matrix::Trans type, float in1, float in2, float in3)
    {
        if (type == Matrix::Trans::XYZ)
        {
            this->_m0 = 1.0f;
            this->_m1 = 0.0f;
            this->_m2 = 0.0f;
            this->_m3 = 0.0f;
            this->_m4 = 0.0f;
            this->_m5 = 1.0f;
            this->_m6 = 0.0f;
            this->_m7 = 0.0f;
            this->_m8 = 0.0f;
            this->_m9 = 0.0f;
            this->_m10 = 1.0f;
            this->_m11 = 0.0f;
            this->_m12 = in1;
            this->_m13 = in2;
            this->_m14 = in3;
            this->_m15 = 1.0f;
        }
    }

    void Matrix::set(Matrix::Trans type, Vect inVect)
    {
        float in1 = inVect.x();
        float in2 = inVect.y();
        float in3 = inVect.z();

        if (type == Matrix::Trans::XYZ)
        {
            this->_m0 = 1.0f;
            this->_m1 = 0.0f;
            this->_m2 = 0.0f;
            this->_m3 = 0.0f;
            this->_m4 = 0.0f;
            this->_m5 = 1.0f;
            this->_m6 = 0.0f;
            this->_m7 = 0.0f;
            this->_m8 = 0.0f;
            this->_m9 = 0.0f;
            this->_m10 = 1.0f;
            this->_m11 = 0.0f;
            this->_m12 = in1;
            this->_m13 = in2;
            this->_m14 = in3;
            this->_m15 = 1.0f;
        }
    }

    void Matrix::set(Matrix::Scale type, float in1, float in2, float in3)
    {
        if (type == Matrix::Scale::XYZ)
        {
            this->_m0 = in1;
            this->_m1 = 0.0f;
            this->_m2 = 0.0f;
            this->_m3 = 0.0f;
            this->_m4 = 0.0f;
            this->_m5 = in2;
            this->_m6 = 0.0f;
            this->_m7 = 0.0f;
            this->_m8 = 0.0f;
            this->_m9 = 0.0f;
            this->_m10 = in3;
            this->_m11 = 0.0f;
            this->_m12 = 0.0f;
            this->_m13 = 0.0f;
            this->_m14 = 0.0f;
            this->_m15 = 1.0f;
        }
    }

    void Matrix::set(Matrix::Scale type, Vect inVect)
    {
        float in1 = inVect.x();
        float in2 = inVect.y();
        float in3 = inVect.z();

        if (type == Matrix::Scale::XYZ)
        {
            this->_m0 = in1;
            this->_m1 = 0.0f;
            this->_m2 = 0.0f;
            this->_m3 = 0.0f;
            this->_m4 = 0.0f;
            this->_m5 = in2;
            this->_m6 = 0.0f;
            this->_m7 = 0.0f;
            this->_m8 = 0.0f;
            this->_m9 = 0.0f;
            this->_m10 = in3;
            this->_m11 = 0.0f;
            this->_m12 = 0.0f;
            this->_m13 = 0.0f;
            this->_m14 = 0.0f;
            this->_m15 = 1.0f;
        }
    }


    void Matrix::set(Matrix::Row row, Vect inVect)
    {
        if (row == Matrix::Row::i0)
        {
            this->_v0 = inVect;
            SetMs(inVect);
        }
        else if (row == Matrix::Row::i1)
        {
            this->_v1 = inVect;
            SetMs(inVect);
        }
        else if (row == Matrix::Row::i2)
        {
            this->_v2 = inVect;
            SetMs(inVect);
        }
        else if (row == Matrix::Row::i3)
        {
            this->_v3 = inVect;
            SetMs(inVect);
        }
    }

    Vect Matrix::get(Matrix::Row row)
    {
        Vect foundVector;

        if (row == Matrix::Row::i0)
        {
            foundVector = this->_v0;
        }
        else if (row == Matrix::Row::i1)
        {
            foundVector = this->_v1;
        }
        else if (row == Matrix::Row::i2)
        {
            foundVector = this->_v2;
        }
        else if (row == Matrix::Row::i3)
        {
            foundVector = this->_v3;
        }

        return foundVector;
    }

    void Matrix::set(Matrix::Rot rot, Vect& inVect, float inFloat)
    {
        if (rot == Matrix::Rot::AxisAngle)
        {
            // angle
            // axis;
            const float angle_a = 0.5f * inFloat;
            float cos_a;
            float sin_a;

            cos_a = cosf(angle_a);
            sin_a = sinf(angle_a);

            Vect qV = inVect.getNorm();

            qV *= sin_a;

            Vect Q;
            Q[x] = qV[x];
            Q[y] = qV[y];
            Q[z] = qV[z];
            Q[w] = cos_a;

            // this function has been transposed
            float x2, y2, z2;
            float xx, xy, xz;
            float yy, yz, zz;
            float wx, wy, wz;

            // ADD test to make sure that quat is normalized

            x2 = Q[x] + Q[x];
            y2 = Q[y] + Q[y];
            z2 = Q[z] + Q[z];

            xx = Q[x] * x2;
            xy = Q[x] * y2;
            xz = Q[x] * z2;

            yy = Q[y] * y2;
            yz = Q[y] * z2;
            zz = Q[z] * z2;

            wx = Q[w] * x2;
            wy = Q[w] * y2;
            wz = Q[w] * z2;

            this->_m0 = 1.0f - (yy + zz);
            this->_m1 = xy + wz;
            this->_m2 = xz - wy;
            this->_m3 = 0.0f;

            this->_m4 = xy - wz;
            this->_m5 = 1.0f - (xx + zz);
            this->_m6 = yz + wx;
            this->_m7 = 0.0f;

            this->_m8 = xz + wy;
            this->_m9 = yz - wx;
            this->_m10 = 1.0f - (xx + yy);
            this->_m11 = 0.0f;

            this->_v3.set(0.0f, 0.0f, 0.0f, 1.0f);
        }
    }

    void Matrix::set(Matrix::Rot1 rot, float inFloat)
    {
        if (rot == Matrix::Rot1::X)
        {
            this->_m0 = 1.0f;
            this->_m1 = 0.0f;
            this->_m2 = 0.0f;
            this->_m3 = 0.0f;
            this->_m4 = 0.0f;
            this->_m5 = Trig::cos(inFloat);
            this->_m6 = Trig::sin(inFloat);
            this->_m7 = 0.0f;
            this->_m8 = 0.0f;
            this->_m9 = -Trig::sin(inFloat);
            this->_m10 = Trig::cos(inFloat);
            this->_m11 = 0.0f;
            this->_m12 = 0.0f;
            this->_m13 = 0.0f;
            this->_m14 = 0.0f;
            this->_m15 = 1.0f;
        }
        else if (rot == Matrix::Rot1::Y)
        {
            this->_m0 = Trig::cos(inFloat);
            this->_m1 = 0.0f;
            this->_m2 = -Trig::sin(inFloat);
            this->_m3 = 0.0f;
            this->_m4 = 0.0f;
            this->_m5 = 1.0f;
            this->_m6 = 0.0f;
            this->_m7 = 0.0f;
            this->_m8 = Trig::sin(inFloat);
            this->_m9 = 0.0f;
            this->_m10 = Trig::cos(inFloat);
            this->_m11 = 0.0f;
            this->_m12 = 0.0f;
            this->_m13 = 0.0f;
            this->_m14 = 0.0f;
            this->_m15 = 1.0f;
        }
        else if (rot == Matrix::Rot1::Z)
        {
            this->_m0 = Trig::cos(inFloat);
            this->_m1 = Trig::sin(inFloat);
            this->_m2 = 0.0f;
            this->_m3 = 0.0f;
            this->_m4 = -Trig::sin(inFloat);
            this->_m5 = Trig::cos(inFloat);
            this->_m6 = 0.0f;
            this->_m7 = 0.0f;
            this->_m8 = 0.0f;
            this->_m9 = 0.0f;
            this->_m10 = 1.0f;
            this->_m11 = 0.0f;
            this->_m12 = 0.0f;
            this->_m13 = 0.0f;
            this->_m14 = 0.0f;
            this->_m15 = 1.0f;
        }
    }

    void Matrix::set(Matrix::Rot3 rot, float inFloatX, float inFloatY, float inFloatZ)
    {
        Matrix rotX;
        Matrix rotY;
        Matrix rotZ;


        if (rot == Matrix::Rot3::XYZ)
        {
            rotX.set(Matrix::Rot1::X, inFloatX);
            rotY.set(Matrix::Rot1::Y, inFloatY);
            rotZ.set(Matrix::Rot1::Z, inFloatZ);

            *this = rotX * rotY * rotZ;
        }
    }

    void Matrix::set(Matrix::Orient orientType, Vect inVect1, Vect inVect2)
    {
        if (orientType == Matrix::Orient::LocalToWorld)
        {
            this->privSetRotOrient(inVect1, inVect2);
        }
        else if (orientType == Matrix::Orient::WorldToLocal)
        {
            this->privSetRotOrient(inVect1, inVect2);
            this->inv();
        }
    }

    float Matrix::det()
    {
        //is the mass or magnitude of the matrix
        //need to break down into other determinants

        float tmp =
            this->_m12 * this->_m9 * this->_m6 * this->_m3 - this->_m8 * this->_m13 * this->_m6 * this->_m3 -
            this->_m12 * this->_m5 * this->_m10 * this->_m3 + this->_m4 * this->_m13 * this->_m10 * this->_m3 +
            this->_m8 * this->_m5 * this->_m14 * this->_m3 - this->_m4 * this->_m9  * this->_m14 * this->_m3 -
            this->_m12 * this->_m9 * this->_m2 * this->_m7 + this->_m8 * this->_m13 * this->_m2 * this->_m7 +
            this->_m12 * this->_m1 * this->_m10 * this->_m7 - this->_m0 * this->_m13 * this->_m10 * this->_m7 -
            this->_m8 * this->_m1 * this->_m14 * this->_m7 + this->_m0 * this->_m9  * this->_m14 * this->_m7 +
            this->_m12 * this->_m5 * this->_m2 * this->_m11 - this->_m4 * this->_m13 * this->_m2 * this->_m11 -
            this->_m12 * this->_m1 * this->_m6 * this->_m11 + this->_m0 * this->_m13 * this->_m6 * this->_m11 +
            this->_m4 * this->_m1 * this->_m14 * this->_m11 - this->_m0 * this->_m5  * this->_m14 * this->_m11 -
            this->_m8 * this->_m5 * this->_m2 * this->_m15 + this->_m4 * this->_m9  * this->_m2 * this->_m15 +
            this->_m8 * this->_m1 * this->_m6 * this->_m15 - this->_m0 * this->_m9  * this->_m6 * this->_m15 -
            this->_m4 * this->_m1 * this->_m10 * this->_m15 + this->_m0 * this->_m5  * this->_m10 * this->_m15;

        return tmp;
        ////Determinant of a 4x4 matrix. Different from my subMDet because that's a 3x3 matrix.

        //float Adet = (_m0 * ((_m5 * +(_m10 * _m15 - _m11 * _m14)) - (_m6 * (_m9 * _m15 - _m11 * _m13)) + (_m7 * (_m9 * _m14 - _m10 * _m13))));
        //float Bdet = -(_m1 * ((_m4 * +(_m10 * _m15 - _m11 * _m14)) - (_m6 * (_m8 * _m15 - _m11 * _m12)) + (_m7 * (_m8 * _m14 - _m10 * _m12))));
        //float Cdet = (_m2 * ((_m4 * +(_m9 * _m15 - _m11 * _m13)) - (_m5 * (_m8 * _m15 - _m11 * _m12)) + (_m7 * (_m8 * _m13 - _m9 * _m12))));
        //float Ddet = -(_m3 * ((_m4 * +(_m9 * _m14 - _m10 * _m13)) - (_m5 * (_m8 * _m14 - _m10 * _m12)) + (_m6 * (_m8 * _m13 - _m9 * _m12))));

        //return Adet + Bdet + Cdet + Ddet;
    }


    Matrix::Matrix(Matrix::Orient orientType, Vect inVect1, Vect inVect2)
    {
        if (orientType == Matrix::Orient::LocalToWorld)
        {
            this->privSetRotOrient(inVect1, inVect2);
        }
        else if (orientType == Matrix::Orient::WorldToLocal)
        {
           this->privSetRotOrient(inVect1, inVect2);
           this->inv();

        }
    }

    void Matrix::privSetRotOrient(Vect& v1, Vect& v2)
    {

        Vect rz = v1.getNorm();

        Vect rx = v2.cross(rz);
        rx.norm();

        Vect ry = rz.cross(rx);
        ry.norm();

        this->set(rx, ry, rz, Vect(0.0f, 0.0f, 0.0f, 1.0f));
        this->_m3 = 0.0f;
        this->_m7 = 0.0f;
        this->_m11 = 0.0f;
        this->_m15 = 1.0f;

    }

    void Matrix::privSetRotInverseOrient()
    {

    }

    void Matrix::set(Vect inVect1, Vect inVect2, Vect inVect3, Vect inVect4)
    {
        this->_v0 = inVect1;
        SetMs(inVect1);

        this->_v1 = inVect2;
        SetMs(inVect2);

        this->_v2 = inVect3;
        SetMs(inVect3);

        this->_v3 = inVect4;
        SetMs(inVect4);
    }

    bool Matrix::isEqual(Matrix inMatrix)
    {
        bool result = false;

        if (Util::isEqual(this->_m0, inMatrix._m0, MATH_TOLERANCE)
            && Util::isEqual(this->_m1, inMatrix._m1, MATH_TOLERANCE)
            && Util::isEqual(this->_m2, inMatrix._m2, MATH_TOLERANCE)
            && Util::isEqual(this->_m3, inMatrix._m3, MATH_TOLERANCE)
            && Util::isEqual(this->_m4, inMatrix._m4, MATH_TOLERANCE)
            && Util::isEqual(this->_m5, inMatrix._m5, MATH_TOLERANCE)
            && Util::isEqual(this->_m6, inMatrix._m6, MATH_TOLERANCE)
            && Util::isEqual(this->_m7, inMatrix._m7, MATH_TOLERANCE)
            && Util::isEqual(this->_m8, inMatrix._m8, MATH_TOLERANCE)
            && Util::isEqual(this->_m9, inMatrix._m9, MATH_TOLERANCE)
            && Util::isEqual(this->_m10, inMatrix._m10, MATH_TOLERANCE)
            && Util::isEqual(this->_m11, inMatrix._m11, MATH_TOLERANCE)
            && Util::isEqual(this->_m12, inMatrix._m12, MATH_TOLERANCE)
            && Util::isEqual(this->_m13, inMatrix._m13, MATH_TOLERANCE)
            && Util::isEqual(this->_m14, inMatrix._m14, MATH_TOLERANCE)
            && Util::isEqual(this->_m15, inMatrix._m15, MATH_TOLERANCE)) //one big check
        {
            //if it's all true - we are equal
            result = true;
        }

        return result;
    }

    bool Matrix::isIdentity(float tolerance)
    {
        bool result = false;

        if (Util::isEqual(this->_m0, 1, tolerance) &&
            Util::isEqual(this->_m1, 0, tolerance) &&
            Util::isEqual(this->_m2, 0, tolerance) &&
            Util::isEqual(this->_m3, 0, tolerance) &&
            Util::isEqual(this->_m4, 0, tolerance) &&
            Util::isEqual(this->_m5, 1, tolerance) &&
            Util::isEqual(this->_m6, 0, tolerance) &&
            Util::isEqual(this->_m7, 0, tolerance) &&
            Util::isEqual(this->_m8, 0, tolerance) &&
            Util::isEqual(this->_m9, 0, tolerance) &&
            Util::isEqual(this->_m10, 1, tolerance) &&
            Util::isEqual(this->_m11, 0, tolerance) &&
            Util::isEqual(this->_m12, 0, tolerance) &&
            Util::isEqual(this->_m13, 0, tolerance) &&
            Util::isEqual(this->_m14, 0, tolerance) &&
            Util::isEqual(this->_m15, 1, tolerance))//one big check
        {
            //if it's all true - we are equal
            result = true;
        }

        return result;
    }

    bool Matrix::isRotation()
    {
        bool result = false;

        if (this->det() == 1)
        {
            Matrix invMatrix = this->getInv();
            Matrix transposeMatrix = this->getT();

            if (invMatrix.isEqual(transposeMatrix))
            {
                result = true;
            }
        }

        return result;
    }


    Matrix Matrix::inv()
    {
        Matrix tmpMat;

        float a00 = this->m0();
        float a01 = this->m1();
        float a02 = this->m2();
        float a03 = this->m3();
        float a10 = this->m4();
        float a11 = this->m5();
        float a12 = this->m6();
        float a13 = this->m7();
        float a20 = this->m8();
        float a21 = this->m9();
        float a22 = this->m10();
        float a23 = this->m11();
        float a30 = this->m12();
        float a31 = this->m13();
        float a32 = this->m14();
        float a33 = this->m15();

        tmpMat._m0 = (a12 * a23 * a31) - (a13 * a22 * a31) + (a13 * a21 * a32) - (a11 * a23 * a32) - (a12 * a21 * a33) + (a11 * a22 * a33);
        tmpMat._m1 = (a03 * a22 * a31) - (a02 * a23 * a31) - (a03 * a21 * a32) + (a01 * a23 * a32) + (a02 * a21 * a33) - (a01 * a22 * a33);
        tmpMat._m2 = (a02 * a13 * a31) - (a03 * a12 * a31) + (a03 * a11 * a32) - (a01 * a13 * a32) - (a02 * a11 * a33) + (a01 * a12 * a33);
        tmpMat._m3 = (a03 * a12 * a21) - (a02 * a13 * a21) - (a03 * a11 * a22) + (a01 * a13 * a22) + (a02 * a11 * a23) - (a01 * a12 * a23);
        tmpMat._m4 = (a13 * a22 * a30) - (a12 * a23 * a30) - (a13 * a20 * a32) + (a10 * a23 * a32) + (a12 * a20 * a33) - (a10 * a22 * a33);
        tmpMat._m5 = (a02 * a23 * a30) - (a03 * a22 * a30) + (a03 * a20 * a32) - (a00 * a23 * a32) - (a02 * a20 * a33) + (a00 * a22 * a33);
        tmpMat._m6 = (a03 * a12 * a30) - (a02 * a13 * a30) - (a03 * a10 * a32) + (a00 * a13 * a32) + (a02 * a10 * a33) - (a00 * a12 * a33);
        tmpMat._m7 = (a02 * a13 * a20) - (a03 * a12 * a20) + (a03 * a10 * a22) - (a00 * a13 * a22) - (a02 * a10 * a23) + (a00 * a12 * a23);
        tmpMat._m8 = (a11 * a23 * a30) - (a13 * a21 * a30) + (a13 * a20 * a31) - (a10 * a23 * a31) - (a11 * a20 * a33) + (a10 * a21 * a33);
        tmpMat._m9 = (a03 * a21 * a30) - (a01 * a23 * a30) - (a03 * a20 * a31) + (a00 * a23 * a31) + (a01 * a20 * a33) - (a00 * a21 * a33);
        tmpMat._m10 = (a01 * a13 * a30) - (a03 * a11 * a30) + (a03 * a10 * a31) - (a00 * a13 * a31) - (a01 * a10 * a33) + (a00 * a11 * a33);
        tmpMat._m11 = (a03 * a11 * a20) - (a01 * a13 * a20) - (a03 * a10 * a21) + (a00 * a13 * a21) + (a01 * a10 * a23) - (a00 * a11 * a23);
        tmpMat._m12 = (a12 * a21 * a30) - (a11 * a22 * a30) - (a12 * a20 * a31) + (a10 * a22 * a31) + (a11 * a20 * a32) - (a10 * a21 * a32);
        tmpMat._m13 = (a01 * a22 * a30) - (a02 * a21 * a30) + (a02 * a20 * a31) - (a00 * a22 * a31) - (a01 * a20 * a32) + (a00 * a21 * a32);
        tmpMat._m14 = (a02 * a11 * a30) - (a01 * a12 * a30) - (a02 * a10 * a31) + (a00 * a12 * a31) + (a01 * a10 * a32) - (a00 * a11 * a32);
        tmpMat._m15 = (a01 * a12 * a20) - (a02 * a11 * a20) + (a02 * a10 * a21) - (a00 * a12 * a21) - (a01 * a10 * a22) + (a00 * a11 * a22);

        const float det = this->det();
        const float inverseDet = 1.0f / det;

        //Trace::out("%f", det);
        //Trace::out("%f", inverseDet);

        tmpMat = tmpMat * inverseDet;
        *this = tmpMat;


        //return tmpMat;
        return *this;
    }

    Matrix Matrix::getInv()
    {   
        Matrix tmpMat;

        float a00 = this->m0();
        float a01 = this->m1();
        float a02 = this->m2();
        float a03 = this->m3();
        float a10 = this->m4();
        float a11 = this->m5();
        float a12 = this->m6();
        float a13 = this->m7();
        float a20 = this->m8();
        float a21 = this->m9();
        float a22 = this->m10();
        float a23 = this->m11();
        float a30 = this->m12();
        float a31 = this->m13();
        float a32 = this->m14();
        float a33 = this->m15();

        tmpMat._m0 = (a12 * a23 * a31) - (a13 * a22 * a31) + (a13 * a21 * a32) - (a11 * a23 * a32) - (a12 * a21 * a33) + (a11 * a22 * a33);
        tmpMat._m1 = (a03 * a22 * a31) - (a02 * a23 * a31) - (a03 * a21 * a32) + (a01 * a23 * a32) + (a02 * a21 * a33) - (a01 * a22 * a33);
        tmpMat._m2 = (a02 * a13 * a31) - (a03 * a12 * a31) + (a03 * a11 * a32) - (a01 * a13 * a32) - (a02 * a11 * a33) + (a01 * a12 * a33);
        tmpMat._m3 = (a03 * a12 * a21) - (a02 * a13 * a21) - (a03 * a11 * a22) + (a01 * a13 * a22) + (a02 * a11 * a23) - (a01 * a12 * a23);
        tmpMat._m4 = (a13 * a22 * a30) - (a12 * a23 * a30) - (a13 * a20 * a32) + (a10 * a23 * a32) + (a12 * a20 * a33) - (a10 * a22 * a33);
        tmpMat._m5 = (a02 * a23 * a30) - (a03 * a22 * a30) + (a03 * a20 * a32) - (a00 * a23 * a32) - (a02 * a20 * a33) + (a00 * a22 * a33);
        tmpMat._m6 = (a03 * a12 * a30) - (a02 * a13 * a30) - (a03 * a10 * a32) + (a00 * a13 * a32) + (a02 * a10 * a33) - (a00 * a12 * a33);
        tmpMat._m7 = (a02 * a13 * a20) - (a03 * a12 * a20) + (a03 * a10 * a22) - (a00 * a13 * a22) - (a02 * a10 * a23) + (a00 * a12 * a23);
        tmpMat._m8 = (a11 * a23 * a30) - (a13 * a21 * a30) + (a13 * a20 * a31) - (a10 * a23 * a31) - (a11 * a20 * a33) + (a10 * a21 * a33);
        tmpMat._m9 = (a03 * a21 * a30) - (a01 * a23 * a30) - (a03 * a20 * a31) + (a00 * a23 * a31) + (a01 * a20 * a33) - (a00 * a21 * a33);
        tmpMat._m10 = (a01 * a13 * a30) - (a03 * a11 * a30) + (a03 * a10 * a31) - (a00 * a13 * a31) - (a01 * a10 * a33) + (a00 * a11 * a33);
        tmpMat._m11 = (a03 * a11 * a20) - (a01 * a13 * a20) - (a03 * a10 * a21) + (a00 * a13 * a21) + (a01 * a10 * a23) - (a00 * a11 * a23);
        tmpMat._m12 = (a12 * a21 * a30) - (a11 * a22 * a30) - (a12 * a20 * a31) + (a10 * a22 * a31) + (a11 * a20 * a32) - (a10 * a21 * a32);
        tmpMat._m13 = (a01 * a22 * a30) - (a02 * a21 * a30) + (a02 * a20 * a31) - (a00 * a22 * a31) - (a01 * a20 * a32) + (a00 * a21 * a32);
        tmpMat._m14 = (a02 * a11 * a30) - (a01 * a12 * a30) - (a02 * a10 * a31) + (a00 * a12 * a31) + (a01 * a10 * a32) - (a00 * a11 * a32);
        tmpMat._m15 = (a01 * a12 * a20) - (a02 * a11 * a20) + (a02 * a10 * a21) - (a00 * a12 * a21) - (a01 * a10 * a22) + (a00 * a11 * a22);

        const float det = this->det();
        const float inverseDet = 1.0f / det;

        //Trace::out("%f", det);
        //Trace::out("%f", inverseDet);

        tmpMat = tmpMat * inverseDet;
        //*this = tmpMat;


        //return tmpMat;
        return tmpMat;


        //Matrix newMatrix;


        //float det = this->det();
        //float invDet = 1 / det;

        //////get cofactor of matrix
        ////newMatrix = this->getAdjoint();


        ///*
        //
        //copying ed's notes


        //a00 a01 a02 a03
        //a10 a11 a12 a13 
        //a20 a21 a22 a23  
        //a30 a31 a32 a33

        //is the same as

        //m00 m01 m02 m03
        //m04 m05 m06 m07
        //m08 m09 m10 m11
        //m12 m13 m14 m15        
        //
        //*/

        //float a00 = this->m0();
        //float a01 = this->m1();
        //float a02 = this->m2();
        //float a03 = this->m3();
        //float a10 = this->m4();
        //float a11 = this->m5();
        //float a12 = this->m6();
        //float a13 = this->m7();
        //float a20 = this->m8();
        //float a21 = this->m9();
        //float a22 = this->m10();
        //float a23 = this->m11();
        //float a30 = this->m12();
        //float a31 = this->m13();
        //float a32 = this->m14();
        //float a33 = this->m15();

        //newMatrix._m0  = (a12 * a23 * a31) - (a13 * a22 * a31) + (a13 * a21 * a32) - (a11 * a23 * a32) - (a12 * a21 * a33) + (a11 * a22 * a33);
        //newMatrix._m1  = (a03 * a22 * a31) - (a02 * a23 * a31) - (a03 * a21 * a32) + (a01 * a23 * a32) + (a02 * a21 * a33) - (a01 * a22 * a33);
        //newMatrix._m2  = (a02 * a13 * a31) - (a03 * a12 * a31) + (a03 * a11 * a32) - (a01 * a13 * a32) - (a02 * a11 * a33) + (a01 * a12 * a33);
        //newMatrix._m3  = (a03 * a12 * a21) - (a02 * a13 * a21) - (a03 * a11 * a22) + (a01 * a13 * a22) + (a02 * a11 * a23) - (a01 * a12 * a23);
        //newMatrix._m4  = (a13 * a22 * a30) - (a12 * a23 * a30) - (a13 * a20 * a32) + (a10 * a23 * a32) + (a12 * a20 * a33) - (a10 * a22 * a33);
        //newMatrix._m5  = (a02 * a23 * a30) - (a03 * a22 * a30) + (a03 * a20 * a32) - (a00 * a23 * a32) - (a02 * a20 * a33) + (a00 * a22 * a33);
        //newMatrix._m6  = (a03 * a12 * a30) - (a02 * a13 * a30) - (a03 * a10 * a32) + (a00 * a13 * a32) + (a02 * a10 * a33) - (a00 * a12 * a33);
        //newMatrix._m7  = (a02 * a13 * a20) - (a03 * a12 * a20) + (a03 * a10 * a22) - (a00 * a13 * a22) - (a02 * a10 * a23) + (a00 * a12 * a23);
        //newMatrix._m8  = (a11 * a23 * a30) - (a13 * a21 * a30) + (a13 * a20 * a31) - (a10 * a23 * a31) - (a11 * a20 * a33) + (a10 * a21 * a33);
        //newMatrix._m9  = (a03 * a21 * a30) - (a01 * a23 * a30) - (a03 * a20 * a31) + (a00 * a23 * a31) + (a01 * a20 * a33) - (a00 * a21 * a33);
        //newMatrix._m10 = (a01 * a13 * a30) - (a03 * a11 * a30) + (a03 * a10 * a31) - (a00 * a13 * a31) - (a01 * a10 * a33) + (a00 * a11 * a33);
        //newMatrix._m11 = (a03 * a11 * a20) - (a01 * a13 * a20) - (a03 * a10 * a21) + (a00 * a13 * a21) + (a01 * a10 * a23) - (a00 * a11 * a23);
        //newMatrix._m12 = (a12 * a21 * a30) - (a11 * a22 * a30) - (a12 * a20 * a31) + (a10 * a22 * a31) + (a11 * a20 * a32) - (a10 * a21 * a32);
        //newMatrix._m13 = (a01 * a22 * a30) - (a02 * a21 * a30) + (a02 * a20 * a31) - (a00 * a22 * a31) - (a01 * a20 * a32) + (a00 * a21 * a32);
        //newMatrix._m14 = (a02 * a11 * a30) - (a01 * a12 * a30) - (a02 * a10 * a31) + (a00 * a12 * a31) + (a01 * a10 * a32) - (a00 * a11 * a32);
        //newMatrix._m15 = (a01 * a12 * a20) - (a02 * a11 * a20) + (a02 * a10 * a21) - (a00 * a12 * a21) - (a01 * a10 * a22) + (a00 * a11 * a22);

        //newMatrix *= invDet;

        //return newMatrix;
    }

    Matrix Matrix::getAdjoint()
    {
        //float cof = 0.0f;

        Matrix newMatrix;

        //Location in matrix: x,y
        //1,1
        newMatrix._m0  = subMDet(this->m5(), this->m9(), this->m13(), this->m6(), this->m10(), this->m14(), this->m7(), this->m11(), this->m15());
        //2,1
        newMatrix._m1  = subMDet(this->m4(), this->m8(), this->m12(), this->m6(), this->m10(), this->m14(), this->m7(), this->m11(), this->m15());
        //3,1
        newMatrix._m2  = subMDet(this->m4(), this->m8(), this->m12(), this->m5(), this->m9(), this->m13(), this->m7(), this->m11(), this->m15());
        //4,1
        newMatrix._m3  = subMDet(this->m4(), this->m8(), this->m12(), this->m5(), this->m9(), this->m13(), this->m6(), this->m10(), this->m14());
        //1,2
        newMatrix._m4  = subMDet(this->m1(), this->m9(), this->m13(), this->m2(), this->m10(), this->m14(), this->m3(), this->m11(), this->m15());
        //2,2
        newMatrix._m5  = subMDet(this->m0(), this->m8(), this->m12(), this->m2(), this->m10(), this->m14(), this->m3(), this->m11(), this->m15());
        //3,2
        newMatrix._m6  = subMDet(this->m0(), this->m8(), this->m12(), this->m1(), this->m9(), this->m13(), this->m3(), this->m11(), this->m15());
        //4,2
        newMatrix._m7  = subMDet(this->m0(), this->m8(), this->m12(), this->m1(), this->m9(), this->m13(), this->m2(), this->m10(), this->m14());
        //1,3
        newMatrix._m8  = subMDet(this->m1(), this->m5(), this->m13(), this->m2(), this->m6(), this->m14(), this->m3(), this->m7(), this->m15());
        //2,3
        newMatrix._m9  = subMDet(this->m0(), this->m4(), this->m12(), this->m2(), this->m6(), this->m14(), this->m3(), this->m7(), this->m15());
        //3,3
        newMatrix._m10 = subMDet(this->m0(), this->m4(), this->m12(), this->m1(), this->m5(), this->m13(), this->m3(), this->m7(), this->m15());
        //4,3
        newMatrix._m11 = subMDet(this->m0(), this->m4(), this->m12(), this->m1(), this->m5(), this->m13(), this->m2(), this->m6(), this->m14());
        //1,4
        newMatrix._m12 = subMDet(this->m1(), this->m5(), this->m9(), this->m2(), this->m6(), this->m10(), this->m3(), this->m7(), this->m11());
        //2,4
        newMatrix._m13 = subMDet(this->m0(), this->m4(), this->m8(), this->m2(), this->m6(), this->m10(), this->m3(), this->m7(), this->m11());
        //3,4
        newMatrix._m14 = subMDet(this->m0(), this->m4(), this->m8(), this->m1(), this->m5(), this->m9(), this->m3(), this->m7(), this->m11());
        //4,4
        newMatrix._m15 = subMDet(this->m0(), this->m4(), this->m8(), this->m1(), this->m5(), this->m9(), this->m2(), this->m6(), this->m10());

        ////Location in matrix: x,y
        ////1,1
        //newMatrix._m0 = powf(-1, 2) * subMDet(this->m5(), this->m9(), this->m13(), this->m6(), this->m10(), this->m14(), this->m7(), this->m11(), this->m15());
        ////2,1
        //newMatrix._m1 = powf(-1, 3) * subMDet(this->m4(), this->m8(), this->m12(), this->m6(), this->m10(), this->m14(), this->m7(), this->m11(), this->m15());
        ////3,1
        //newMatrix._m2 = powf(-1, 4) * subMDet(this->m4(), this->m8(), this->m12(), this->m5(), this->m9(), this->m13(), this->m7(), this->m11(), this->m15());
        ////4,1
        //newMatrix._m3 = powf(-1, 5) * subMDet(this->m4(), this->m8(), this->m12(), this->m5(), this->m9(), this->m13(), this->m6(), this->m10(), this->m14());
        ////1,2
        //newMatrix._m4 = powf(-1, 3) * subMDet(this->m1(), this->m9(), this->m13(), this->m2(), this->m10(), this->m14(), this->m3(), this->m11(), this->m15());
        ////2,2
        //newMatrix._m5 = powf(-1, 4) * subMDet(this->m0(), this->m8(), this->m12(), this->m2(), this->m10(), this->m14(), this->m3(), this->m11(), this->m15());
        ////3,2
        //newMatrix._m6 = powf(-1, 5) * subMDet(this->m0(), this->m8(), this->m12(), this->m1(), this->m9(), this->m13(), this->m3(), this->m11(), this->m15());
        ////4,2
        //newMatrix._m7 = powf(-1, 6) * subMDet(this->m0(), this->m8(), this->m12(), this->m1(), this->m9(), this->m13(), this->m2(), this->m10(), this->m14());
        ////1,3
        //newMatrix._m8 = powf(-1, 4) * subMDet(this->m1(), this->m5(), this->m13(), this->m2(), this->m6(), this->m14(), this->m3(), this->m7(), this->m15());
        ////2,3
        //newMatrix._m9 = powf(-1, 5) * subMDet(this->m0(), this->m4(), this->m12(), this->m2(), this->m6(), this->m14(), this->m3(), this->m7(), this->m15());
        ////3,3
        //newMatrix._m10 = powf(-1, 6) * subMDet(this->m0(), this->m4(), this->m12(), this->m1(), this->m5(), this->m13(), this->m3(), this->m7(), this->m15());
        ////4,3
        //newMatrix._m11 = powf(-1, 7) * subMDet(this->m0(), this->m4(), this->m12(), this->m1(), this->m5(), this->m13(), this->m2(), this->m6(), this->m14());
        ////1,4
        //newMatrix._m12 = powf(-1, 5) * subMDet(this->m1(), this->m5(), this->m9(), this->m2(), this->m6(), this->m10(), this->m3(), this->m7(), this->m11());
        ////2,4
        //newMatrix._m13 = powf(-1, 6) * subMDet(this->m0(), this->m4(), this->m8(), this->m2(), this->m6(), this->m10(), this->m3(), this->m7(), this->m11());
        ////3,4
        //newMatrix._m14 = powf(-1, 7) * subMDet(this->m0(), this->m4(), this->m8(), this->m1(), this->m5(), this->m9(), this->m3(), this->m7(), this->m11());
        ////4,4
        //newMatrix._m15 = powf(-1, 8) * subMDet(this->m0(), this->m4(), this->m8(), this->m1(), this->m5(), this->m9(), this->m2(), this->m6(), this->m10());


        return newMatrix;
    }

    //4x4 matrix, so we pass in a 3x3 subMatrix, or 9 floats
    float Matrix::subMDet(float inX1, float inX2, float inX3, float inY1, float inY2, float inY3, float inZ1, float inZ2, float inZ3)
    {

        //sub matrix looks like this
        /*
        x1, y1, z1
        x2, y2, z2
        x3, y3, z3           
        */

        float subMatrixDet = 0.0f;

        subMatrixDet = (inX1 * inY2 * inZ3) + (inY1 * inZ2 * inX3) + (inZ1 * inX2 * inY3) 
            - (inZ1 * inY2 * inX3) - (inY1 * inX2 * inZ3) - (inX1 * inZ2 * inY3);

        return subMatrixDet;
    }

    Vect& Matrix::GetV0()
    {
        return this->_v0;
    }
    Vect& Matrix::GetV1()
    {
        return this->_v1;
    }
    Vect& Matrix::GetV2()
    {
        return this->_v2;
    }
    Vect& Matrix::GetV3()
    {
        return this->_v3;
    }

    const float Matrix::m0()  const
    {
        return this->_m0;
    }
    const float Matrix::m1()  const
    {
        return this->_m1;
    }
    const float Matrix::m2()  const
    {
        return this->_m2;
    }
    const float Matrix::m3()  const
    {
        return this->_m3;
    }
    const float Matrix::m4()  const
    {
        return this->_m4;
    }
    const float Matrix::m5()  const
    {
        return this->_m5;
    }
    const float Matrix::m6()  const
    {
        return this->_m6;
    }
    const float Matrix::m7()  const
    {
        return this->_m7;
    }
    const float Matrix::m8()  const
    {
        return this->_m8;
    }
    const float Matrix::m9()  const
    {
        return this->_m9;
    }
    const float Matrix::m10()  const
    {
        return this->_m10;
    }
    const float Matrix::m11()  const
    {
        return this->_m11;
    }
    const float Matrix::m12()  const
    {
        return this->_m12;
    }
    const float Matrix::m13()  const
    {
        return this->_m13;
    }
    const float Matrix::m14()  const
    {
        return this->_m14;
    }
    const float Matrix::m15()  const
    {
        return this->_m15;
    }

    float& Matrix::m0()
    {
        return this->_m0;
    }

    float& Matrix::m1()
    {
        return this->_m1;
    }

    float& Matrix::m2()
    {
        return this->_m2;
    }

    float& Matrix::m3()
    {
        return this->_m3;
    }

    float& Matrix::m4()
    {
        return this->_m4;
    }

    float& Matrix::m5()
    {
        return this->_m5;
    }

    float& Matrix::m6()
    {
        return this->_m6;
    }

    float& Matrix::m7()
    {
        return this->_m7;
    }

    float& Matrix::m8()
    {
        return this->_m8;
    }

    float& Matrix::m9()
    {
        return this->_m9;
    }

    float& Matrix::m10()
    {
        return this->_m10;
    }

    float& Matrix::m11()
    {
        return this->_m11;
    }

    float& Matrix::m12()
    {
        return this->_m12;
    }

    float& Matrix::m13()
    {
        return this->_m13;
    }

    float& Matrix::m14()
    {
        return this->_m14;
    }

    float& Matrix::m15()
    {
        return this->_m15;
    }

    const float Matrix::operator[](m0_enum) const
    {
        return this->_m0;
    }
    const float Matrix::operator[](m1_enum) const
    {
        return this->_m1;
    }
    const float Matrix::operator[](m2_enum) const
    {
        return this->_m2;
    }
    const float Matrix::operator[](m3_enum) const
    {
        return this->_m3;
    }
    const float Matrix::operator[](m4_enum) const
    {
        return this->_m4;
    }
    const float Matrix::operator[](m5_enum) const
    {
        return this->_m5;
    }
    const float Matrix::operator[](m6_enum) const
    {
        return this->_m6;
    }
    const float Matrix::operator[](m7_enum) const
    {
        return this->_m7;
    }
    const float Matrix::operator[](m8_enum) const
    {
        return this->_m8;
    }
    const float Matrix::operator[](m9_enum) const
    {
        return this->_m9;
    }
    const float Matrix::operator[](m10_enum) const
    {
        return this->_m10;
    }
    const float Matrix::operator[](m11_enum) const
    {
        return this->_m11;
    }
    const float Matrix::operator[](m12_enum) const
    {
        return this->_m12;
    }
    const float Matrix::operator[](m13_enum) const
    {
        return this->_m13;
    }
    const float Matrix::operator[](m14_enum) const
    {
        return this->_m14;
    }
    const float Matrix::operator[](m15_enum) const
    {
        return this->_m15;
    }

    float& Matrix::operator[](m0_enum)
    {
        return this->_m0;
    }
    float& Matrix::operator[](m1_enum)
    {
        return this->_m1;
    }
    float& Matrix::operator[](m2_enum)
    {
        return this->_m2;
    }
    float& Matrix::operator[](m3_enum)
    {
        return this->_m3;
    }
    float& Matrix::operator[](m4_enum)
    {
        return this->_m4;
    }
    float& Matrix::operator[](m5_enum)
    {
        return this->_m5;
    }
    float& Matrix::operator[](m6_enum)
    {
        return this->_m6;
    }
    float& Matrix::operator[](m7_enum)
    {
        return this->_m7;
    }
    float& Matrix::operator[](m8_enum)
    {
        return this->_m8;
    }
    float& Matrix::operator[](m9_enum)
    {
        return this->_m9;
    }
    float& Matrix::operator[](m10_enum)
    {
        return this->_m10;
    }
    float& Matrix::operator[](m11_enum)
    {
        return this->_m11;
    }
    float& Matrix::operator[](m12_enum)
    {
        return this->_m12;
    }
    float& Matrix::operator[](m13_enum)
    {
        return this->_m13;
    }
    float& Matrix::operator[](m14_enum)
    {
        return this->_m14;
    }
    float& Matrix::operator[](m15_enum)
    {
        return this->_m15;
    }

    Matrix operator*(float inFloat, Matrix inMatrix)
    {
        Matrix newMatrix;

        newMatrix._m0 = inMatrix._m0 * inFloat;
        newMatrix._m1 = inMatrix._m1 * inFloat;
        newMatrix._m2 = inMatrix._m2 * inFloat;
        newMatrix._m3 = inMatrix._m3 * inFloat;
        newMatrix._m4 = inMatrix._m4 * inFloat;
        newMatrix._m5 = inMatrix._m5 * inFloat;
        newMatrix._m6 = inMatrix._m6 * inFloat;
        newMatrix._m7 = inMatrix._m7 * inFloat;
        newMatrix._m8 = inMatrix._m8 * inFloat;
        newMatrix._m9 = inMatrix._m9 * inFloat;
        newMatrix._m10 = inMatrix._m10 * inFloat;
        newMatrix._m11 = inMatrix._m11 * inFloat;
        newMatrix._m12 = inMatrix._m12 * inFloat;
        newMatrix._m13 = inMatrix._m13 * inFloat;
        newMatrix._m14 = inMatrix._m14 * inFloat;
        newMatrix._m15 = inMatrix._m15 * inFloat;

        return newMatrix;
    }

    Matrix operator*(Matrix inMatrix, float inFloat)
    {
        Matrix newMatrix;

        newMatrix._m0 = inMatrix._m0 * inFloat;
        newMatrix._m1 = inMatrix._m1 * inFloat;
        newMatrix._m2 = inMatrix._m2 * inFloat;
        newMatrix._m3 = inMatrix._m3 * inFloat;
        newMatrix._m4 = inMatrix._m4 * inFloat;
        newMatrix._m5 = inMatrix._m5 * inFloat;
        newMatrix._m6 = inMatrix._m6 * inFloat;
        newMatrix._m7 = inMatrix._m7 * inFloat;
        newMatrix._m8 = inMatrix._m8 * inFloat;
        newMatrix._m9 = inMatrix._m9 * inFloat;
        newMatrix._m10 = inMatrix._m10 * inFloat;
        newMatrix._m11 = inMatrix._m11 * inFloat;
        newMatrix._m12 = inMatrix._m12 * inFloat;
        newMatrix._m13 = inMatrix._m13 * inFloat;
        newMatrix._m14 = inMatrix._m14 * inFloat;
        newMatrix._m15 = inMatrix._m15 * inFloat;

        return newMatrix;
    }

    Matrix operator/(Matrix inMatrix, float inFloat)
    {
        Matrix newMatrix;

        newMatrix._m0 = inMatrix._m0 / inFloat;
        newMatrix._m1 = inMatrix._m1 / inFloat;
        newMatrix._m2 = inMatrix._m2 / inFloat;
        newMatrix._m3 = inMatrix._m3 / inFloat;
        newMatrix._m4 = inMatrix._m4 / inFloat;
        newMatrix._m5 = inMatrix._m5 / inFloat;
        newMatrix._m6 = inMatrix._m6 / inFloat;
        newMatrix._m7 = inMatrix._m7 / inFloat;
        newMatrix._m8 = inMatrix._m8 / inFloat;
        newMatrix._m9 = inMatrix._m9 / inFloat;
        newMatrix._m10 = inMatrix._m10 / inFloat;
        newMatrix._m11 = inMatrix._m11 / inFloat;
        newMatrix._m12 = inMatrix._m12 / inFloat;
        newMatrix._m13 = inMatrix._m13 / inFloat;
        newMatrix._m14 = inMatrix._m14 / inFloat;
        newMatrix._m15 = inMatrix._m15 / inFloat;

        return newMatrix;
    }

    Matrix Matrix::operator*=(float inFloat)
    {
        this->_m0 *= inFloat;
        this->_m1 *= inFloat;
        this->_m2 *= inFloat;
        this->_m3 *= inFloat;
        this->_m4 *= inFloat;
        this->_m5 *= inFloat;
        this->_m6 *= inFloat;
        this->_m7 *= inFloat;
        this->_m8 *= inFloat;
        this->_m9 *= inFloat;
        this->_m10 *= inFloat;
        this->_m11 *= inFloat;
        this->_m12 *= inFloat;
        this->_m13 *= inFloat;
        this->_m14 *= inFloat;
        this->_m15 *= inFloat;

        return *this;
    }

}

// ---  End of File --------------
