#include "CStudent.h"
#include <iostream>
#include <string>
#include "CLecture.h"

int CStudent::s_nStudent = 0;

CStudent::CStudent(std::string name, int id, int sex, CLecture* lect) {
    m_sName = name;
    m_nID = id;
    m_bSex = sex;
    lect->PrintInfo();
    m_Lect = lect;
    CStudent::s_nStudent += 1;
    std::cout << "Student(" << m_sName << ") created" << std::endl;
    std::cout << "Studnet Count: " << CStudent::s_nStudent << std::endl;
}

CStudent::~CStudent() {
    CStudent::s_nStudent -= 1;
    std::cout << "Student(" << m_sName << ") removed" << std::endl;
    std::cout << "Studnet Count: " << CStudent::s_nStudent << std::endl;
}

std::string CStudent::GetName() const {
    return m_sName;
}

void CStudent::SetName(std::string name) {
    m_sName = name;
}

int CStudent::GetID() const {
    return m_nID;
}

void CStudent::SetID(int id) {
    m_nID = id;
}

int CStudent::GetSex() const {
    return m_bSex;
}

void CStudent::SetSex(int sex) {
    m_bSex = sex;
}

bool CStudent::IsSameStudent(const CStudent& student) const {
    return m_nID == student.GetID();
}

void CStudent::PrintInfo() const {
    std::cout << "Name: " << m_sName << ", ID: " << m_nID << ", Lect: " << m_Lect->GetLect() << std::endl;
}
