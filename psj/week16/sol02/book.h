#ifndef ACE1309_WEEK16_SOL02_BOOK_H
#define ACE1309_WEEK16_SOL02_BOOK_H

#include <string>

class Book {
private:
    std::string title;

public:
    Book(const std::string& title);
    virtual ~Book();
    std::string get_title() const;
    virtual void print() const;
    void set_title(const std::string& title);
};

class Novel : public Book {
public:
    Novel(const std::string& title);
    virtual ~Novel();
    virtual void print() const override;
};

class Biography : public Book {
public:
    Biography(const std::string& title);
    virtual ~Biography();
    virtual void print() const override;
};

#endif // ACE1309_WEEK16_SOL02_BOOK_H
