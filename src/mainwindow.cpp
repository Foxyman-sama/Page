#include "mainwindow.hpp"

MainWindow::MainWindow(QWidget *_p_parent) noexcept
    : QMainWindow(_p_parent) {
    p_mainwidget_ = new QWidget { };
    p_mainlayout_ = new QGridLayout { };
    p_formlayout_ = new QFormLayout { };
    p_acceptbut_  = new QPushButton { "Обработать" };
    p_furl_       = new QTextEdit { };

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
    this->setCentralWidget(p_mainwidget_);
    connect(p_acceptbut_, &QPushButton::clicked, this, &MainWindow::processing);
}

void MainWindow::processing() {
    try {
        p_fresult_->clear();

        auto                           start_time { std::chrono::steady_clock::now() };
        std::shared_ptr<IBaseReceiver> p_htmlreceiver { new HTMLReceiver { } };
        Receiver                       receiver { p_htmlreceiver };
        auto                           p_str {
            receiver.receive(p_furl_->toPlainText().toStdString().c_str())
        };
        std::shared_ptr<IBaseFormater> p_htmlformater { new HTMLFormater { } };
        Formater                       formater { p_htmlformater };
        formater.format(p_str);

        std::shared_ptr<IBaseExtractor> p_htmlextractor { new HTMLExtractor { } };
        Extractor                       extractor { p_htmlextractor };
        std::string                     begin { p_fbegin_->toPlainText().toStdString() };
        std::string                     end { p_fend_->toPlainText().toStdString() };
        auto                            extracted {
            extractor.extract(p_str, begin, end, -1, 300)
        };
        std::vector<std::string>        formats { };
        std::string                     formats_str { p_fformats_->toPlainText().toStdString() };
        std::string                     temp { };
        for (size_t i { }; i < formats_str.size(); ++i) {
            if (std::isalpha(formats_str[i])) {
                while (std::isalpha(formats_str[i])) {
                    temp += formats_str[i++];
                }

                formats.emplace_back(temp);
                temp.clear();
            }
        }

        std::shared_ptr<IBaseFilterer> p_vecfilterer { new VectorFilterer { } };
        Filterer                       filterer { p_vecfilterer };
        auto                           filtered {
            filterer.filter(&extracted, formats)
        };
        std::string                    url { p_furl_->toPlainText().toStdString() };
        std::string                    add_param { p_favgformat_->toPlainText().toStdString() };
        std::string                    directory { p_fdirectory_->toPlainText().toStdString() };
        auto                           fn { [&](std::vector<std::string> _filtered) {
            std::shared_ptr<IBaseDownloader> p_mediadownloader { new MediaDownloader { } };
            Downloader                       downloader { p_mediadownloader };
            for (size_t i { }; i < _filtered.size(); ++i) {
                downloader.download(_filtered[i], add_param, directory);
            }
        } };
        std::vector<std::future<void>> futures { };
        size_t                         count_of_thread {
            std::thread::hardware_concurrency()
        };
        size_t                         step { filtered.size() / count_of_thread };
        if (step > 0) {
            size_t iter { step };
            size_t last { };
            for (size_t i { }; i < count_of_thread; ++i) {
                if (i != count_of_thread - 1) {
                    std::vector<std::string> temp { filtered.begin() + last, filtered.begin() + iter };
                    futures.emplace_back(std::async(std::launch::async, fn, temp));
                }
                else {
                    std::vector<std::string> temp { filtered.begin() + last, filtered.end() };
                    futures.emplace_back(std::async(std::launch::async, fn, temp));
                }

                last  = iter;
                iter += step;
            }
            for (size_t i { }; i < futures.size(); ++i) {
                futures[i].get();
            }
        }
        else {
            fn(filtered);
        }

        auto        end_time { std::chrono::steady_clock::now() };
        float       delta {
            std::chrono::duration<float, std::milli>(end_time - start_time).count() / 1000
        };
        std::string time_elapsed {
            "Прошедшее время:      " + std::to_string(delta) + " секунд"
        };
        std::string count_of_downloads {
            "Загруженных файлов: " + std::to_string(filtered.size())
        };
        p_fresult_->append(time_elapsed.c_str());
        p_fresult_->append(count_of_downloads.c_str());
    }
    catch (const std::exception &e) {
        qDebug() << e.what() << '\n';
    }
}
