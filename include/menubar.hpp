#ifndef MENUBAR_HPP
#define MENUBAR_HPP

#include <QMenuBar>

class MenuBar
    : public QMenuBar {
private:
    QMenu *p_main_;

public:
    MenuBar() noexcept;
};

#endif
