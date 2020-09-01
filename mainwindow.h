#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPushButton>
#include <QThread>
QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
private slots:
      void handleDownload();
      void handleInstall();
      void doWork(const QString);
      void startUP();
      void onProgressChanged();
private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
