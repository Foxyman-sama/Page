#include "mainwindow.hpp"

MainWindow::MainWindow(QWidget *_p_parent) noexcept
    : QMainWindow(_p_parent) {
    setFixedSize(450, 350);
    p_mainwidget_ = new QWidget { };
    p_mainlayout_ = new QGridLayout { };
    p_formlayout_ = new QFormLayout { };
    p_acceptbut_  = new QPushButton { "Обработать" };
    p_menubar_    = new MenuBar { };

    auto initTextEdit { [](QTextEdit **_p_textedit) {
        *_p_textedit     = new QTextEdit { };
        (*_p_textedit)->setVerticalScrollBarPolicy(Qt::ScrollBarPolicy::ScrollBarAlwaysOff);
        (*_p_textedit)->setWordWrapMode(QTextOption::NoWrap);
        (*_p_textedit)->setMaximumHeight(40);
        (*_p_textedit)->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Fixed);
    } };
    initTextEdit(&p_furl_);
    initTextEdit(&p_fbegin_);
    initTextEdit(&p_fend_);
    initTextEdit(&p_fformats_);
    initTextEdit(&p_fdirectory_);
    initTextEdit(&p_favgformat_);
    initTextEdit(&p_fresult_);

    p_formlayout_->addRow("Ссылка на сайт:", p_furl_);
    p_formlayout_->addRow("Начальный диапазон:", p_fbegin_);
    p_formlayout_->addRow("Конечный диапазон:", p_fend_);
    p_formlayout_->addRow("Форматы:", p_fformats_);
    p_formlayout_->addRow("Директория:", p_fdirectory_);
    p_formlayout_->addRow("Общий формат:", p_favgformat_);
    p_formlayout_->addRow("Результат:", p_fresult_);
    p_formlayout_->addWidget(p_acceptbut_);
    p_mainlayout_->addLayout(p_formlayout_, 0, 0);
    p_mainwidget_->setLayout(p_mainlayout_);
    setCentralWidget(p_mainwidget_);
    setMenuBar(p_menubar_);
    connect(p_acceptbut_, &QPushButton::clicked, this, &MainWindow::processing);
}

void MainWindow::processing() {
    auto   start { std::chrono::steady_clock::now() };
    size_t count_of_downloaded { Handler::handle(
        p_furl_->toPlainText().toStdString(),
        p_fbegin_->toPlainText().toStdString(),
        p_fend_->toPlainText().toStdString(),
        p_fformats_->toPlainText().toStdString(),
        p_fdirectory_->toPlainText().toStdString(),
        p_favgformat_->toPlainText().toStdString()
    ) };
    auto   end { std::chrono::steady_clock::now() };
    auto   delta { std::chrono::duration<double, std::milli>(end - start).count() };
    p_fresult_->append(("Количество загруженных файлов: " +
                        std::to_string(count_of_downloaded)).c_str());
    p_fresult_->append(("Количество пройденных секунд: " +
                        std::to_string(delta / 1000)).c_str());
}
