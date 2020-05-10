# Midterm Exam

> 문제 유형만 같으며, 코딩 문제만 포함됨

## Practice

### 1. 아래 조건을 만족하는 학생 정보 클래스를 생성하고 사용한다.

- `CStudent` 클래스
  - 멤버 변수(`private`)
    - `static int s_nStudent`: 학생 수
    - `std::string m_sName`: 학생 이름
    - `int m_nID`: 학번
    - `int m_bSex`: 학생 성별(남자=1, 여자=2)
    - `CLecture m_Lect`: 학생 수업
  - 멤버 함수(`public`)
    - 생성자(constructor): 멤버 변수를 0 또는 NULL로 자동 초기화하거나 사용자 지정값으로 초기화할 수 있어야 한다.
      객체의 생성을 알리는 문장을 출력하고 학생 수를 1 증가시킨다.
    - 소멸자(destructor): 객체의 소멸을 알리는 문장을 출력하고 학생 수를 1 감소시킨다.
    - 각 변수에 대한 get, set 함수
      - `GetName`, `SetName`, `GetID`, `SetID` 등
    - `bool IsSameStudent(const CStudent&)`: 학번을 비교해 같은 학생이면 `true`를 반환한다.
    - `void PrintInfo()`: 학생의 이름, 학번, 수업을 알아보기 쉽게 출력한다.
- `CLecture` 클래스
  - 멤버 변수(`private`)
    - `static std::string s_sDept[m]`: 학과

      ```cpp
      std::string CLecture::s_sDept[5] = {
          "",
          "전기공학과",
          "전자공학과",
          "정보통신공학과",
          "컴퓨터공학과"
      };
      ```

    - `static std::string s_sLect[n]`: 과목 이름

      ```cpp
      std::string CLecture::s_sLect[5] = {
          "",
          "OOP2",
          "선형대수",
          "일반수학",
          "일반물리학"
      };
      ```

  - 멤버 함수(`public`)
    - 생성자(constructor): 학과, 과목 이름을 `""`으로 자동 초기화하거나 사용자 지정값으로 초기화한다.
      객체의 생성을 알리는 문장을 출력한다.
    - 소멸자(destructor): 객체의 소멸을 알리는 문장을 출력한다.
    - 각 변수에 대한 get, set 함수
      - `GetLect`, `SetLect`
    - `void PrintInfo()`: 학과, 과목 이름을 알아보기 쉽게 출력한다.
- `main` 함수:
  임의의 이름과 학번을 가지는 `CStudent` 객체(최소 4개)를 생성한다.
  이를 이용한 다양한 동작을 구현하고 출력하여 클래스 설계 및 멤버 함수 동작이 잘 되었음을 보인다.

See [Sol. 1](./sol01/)
