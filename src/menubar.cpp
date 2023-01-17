#include "menubar.hpp"

MenuBar::MenuBar() noexcept {
    p_main_ = new QMenu { };
    p_main_->setTitle("Главное");
    addMenu(p_main_);
}
