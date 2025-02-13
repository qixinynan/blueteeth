#include <QApplication>
#include <QMainWindow>
#include <QTextEdit>
#include "mainwindow.h"




void myMessageOutput(QtMsgType type, const QMessageLogContext &context, const QString &msg) {
  QByteArray localMsg = msg.toLocal8Bit();
  switch (type) {
  case QtDebugMsg:
    fprintf(stderr, "Debug: %s (%s:%u, %s)\n", localMsg.constData(),
            context.file, context.line, context.function);
    break;
  case QtInfoMsg:
    fprintf(stderr, "Info: %s (%s:%u, %s)\n", localMsg.constData(),
            context.file, context.line, context.function);
    break;
  case QtWarningMsg:
    fprintf(stderr, "Warning: %s (%s:%u, %s)\n", localMsg.constData(),
            context.file, context.line, context.function);
    break;
  case QtCriticalMsg:
    fprintf(stderr, "Critical: %s (%s:%u, %s)\n", localMsg.constData(),
            context.file, context.line, context.function);
    break;
  case QtFatalMsg:
    fprintf(stderr, "Fatal: %s (%s:%u, %s)\n", localMsg.constData(),
            context.file, context.line, context.function);
    abort();
  }
}

int main(int argc, char *argv[])
{

  qDebug() << "?";
  qInstallMessageHandler(myMessageOutput);

  QApplication a(argc, argv);
  MainWindow window;





//  window.setWindowTitle("Blueteeth!");
//  QTextEdit textEdit;
//  window.setCentralWidget(&textEdit);
//  window.resize(400, 300);
  window.show();
  return a.exec();
}
