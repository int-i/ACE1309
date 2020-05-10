#include <iostream>
#include "CLecture.h"
#include "CStudent.h"

int main() {
    CLecture q("a", "q");
    CLecture w("s", "w");
    CLecture e("d", "e");
    CLecture r("f", "r");
    CLecture t("g", "t");
    q.PrintInfo();
    w.PrintInfo();
    e.PrintInfo();
    r.PrintInfo();
    t.PrintInfo();
    CStudent kim("Kim", 1234, 1, &q);
    CStudent lee("Lee", 2345, 1, &w);
    CStudent park("Park", 3456, 2, &e);
    CStudent choi("Choi", 4567, 2, &r);
    CStudent chung("Chung", 5678, 2, &t);
    kim.PrintInfo();
    lee.PrintInfo();
    park.PrintInfo();
    choi.PrintInfo();
    chung.PrintInfo();
    std::cout << "Check(Kim): " << kim.IsSameStudent(CStudent("Kim", 1234, 1, &q)) << std::endl;
    std::cout << "Check(Lee): " << lee.IsSameStudent(CStudent("Lee", 1234, 1, &w)) << std::endl;
    return 0;
}
