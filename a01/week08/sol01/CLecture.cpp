#include "CLecture.h"
#include <iostream>
#include <string>

std::string CLecture::s_sDept[5] = { "", "전기공학과", "전자공학과", "정보통신공학과", "컴퓨터공학과" };
std::string CLecture::s_sLect[5] = { "", "OOP2", "선형대수", "일반수학", "일반물리학" };

CLecture::CLecture(std::string dept, std::string lect) {
    bool checkDept = false;
    for (int i = 0; i < 5; i += 1) {
        if (dept == CLecture::s_sDept[i]) {
            checkDept = true;
            m_sDept = dept;
            break;
        }
    }
    if (!checkDept) {
        m_sDept = "";
    }
    bool checkLect = false;
    for (int i = 0; i < 5; i += 1) {
        if (lect == CLecture::s_sLect[i]) {
            checkLect = true;
            m_sLect = lect;
            break;
        }
    }
    if (!checkLect) {
        m_sLect = "";
    }
    std::cout << "Lecture is " << (m_sLect == "") << std::endl;
    std::cout << "Lecture(" << m_sLect << ") created" << std::endl;
}

CLecture::~CLecture() {
    std::cout << "Lecture(" << m_sLect << ") removed" << std::endl;
}

std::string CLecture::GetLect() const {
    return m_sLect;
}

void CLecture::SetLect(std::string lect) {
    for (int i = 0; i < 5; i += 1) {
        if (lect == CLecture::s_sLect[i]) {
            m_sLect = lect;
            return;
        }
    }
    m_sLect = "";
}

void CLecture::PrintInfo() const {
    std::cout << "Dept: " << m_sDept << ", Lect: " << m_sLect << std::endl;
}
