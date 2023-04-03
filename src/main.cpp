#include <QApplication>
#include <QTextEdit>
#include <boost/log/core.hpp>
#include <boost/log/trivial.hpp>
#include <boost/log/expressions.hpp>

namespace logger {
    void info(char *message) {
        ::boost::log::trivial::logger_type logger = ::boost::log::trivial::logger::get();
        ::boost::log::record record = ::boost::log::trivial::logger::get().open_record();
        ::boost::log::aux::make_record_pump(logger, record).stream() << message;
    }
}

int main(int argc, char *argv[]) {

    for (int i = 0; i < argc; ++i) logger::info(argv[i]);

    const QApplication a(argc, argv);
    QTextEdit editor;
    editor.show();
    return QApplication::exec();
}
