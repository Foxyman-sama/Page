#ifndef MAINWINDOW_HPP
#define MAINWINDOW_HPP

#include <QMainWindow>
#include <QLabel>
#include <QTextEdit>
#include <QFormLayout>
#include <QGridLayout>
#include <QPushButton>
#include <chrono>
#include "handler.hpp"
#include "menubar.hpp"

class MainWindow : public QMainWindow {
    Q_OBJECT

private:
    QWidget     *p_mainwidget_;
    QGridLayout *p_mainlayout_;
    QFormLayout *p_formlayout_;
    QPushButton *p_acceptbut_;
    QTextEdit   *p_furl_ { };
    QTextEdit   *p_fbegin_ { };
    QTextEdit   *p_fend_ { };
    QTextEdit   *p_fformats_ { };
    QTextEdit   *p_fdirectory_ { };
    QTextEdit   *p_favgformat_ { };
    QTextEdit   *p_fresult_ { };
    MenuBar     *p_menubar_ { };

public:
    explicit MainWindow(QWidget *_p_parent = nullptr) noexcept;

public slots:
    void processing();

};
#endif
