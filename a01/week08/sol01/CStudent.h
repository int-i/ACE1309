#ifndef C_STUDENT_H
#define C_STUDENT_H

#include <string>
#include "CLecture.h"

class CStudent {
private:
    static int s_nStudent;
    std::string m_sName;
    int m_nID;
    int m_bSex;
    CLecture* m_Lect;

public:
    CStudent(std::string = "", int = 0, int = 0, CLecture* = nullptr);
    ~CStudent();
    std::string GetName() const;
    void SetName(std::string);
    int GetID() const;
    void SetID(int);
    int GetSex() const;
    void SetSex(int);
    bool IsSameStudent(const CStudent&) const;
    void PrintInfo() const;
};

#endif // C_STUDENT_H
