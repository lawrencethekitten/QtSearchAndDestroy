#ifndef THREADER_H
#define THREADER_H
#include <QThread>
#include <QApplication>
#include <QMessageBox>
#include "HTTPRequest.hpp"
#include <iostream>

class WorkerThread : public QThread {
    Q_OBJECT
    void run() override;
    //public slots:
    //    void process();
    // Define signal:
signals:
    void progressChanged(QString info);
};
/*
void WorkerThread::process(){
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
*/
#endif
