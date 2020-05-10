#ifndef C_LECTURE_H
#define C_LECTURE_H

#include <string>

class CLecture {
private:
    static std::string s_sDept[5];
    static std::string s_sLect[5];
    std::string m_sDept;
    std::string m_sLect;

public:
    CLecture(std::string = "", std::string = "");
    ~CLecture();
    std::string GetLect() const;
    void SetLect(std::string);
    void PrintInfo() const;
};

#endif // C_LECTURE_H
