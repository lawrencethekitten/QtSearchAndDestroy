#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <iostream>
#include "HTTPRequest.hpp"
#include <QMessageBox>
#include <fstream>
#include <QThread>
#include "mythread.h"
MyThread::MyThread(QString s): name(s)
{
}
void MyThread::run()
{
        //std::cout << "thread running" << std::endl;
        http::Request request("http://10.100.104.42/reduced.vhd");
        //std::cout << "made request object" << std::endl;

        // send a get request
        const http::Response getResponse = request.send("GET");
        //std::cout << "Request sent" << std::endl;
        std::string data = std::string(getResponse.body.begin(), getResponse.body.end()); // print the result
        //std::cout << "data stored" << std::endl;
    /*} catch (const std::exception& e) {
        QMessageBox msg;
        msg.setText("Failed to get network resources. Please try again later...");
        msg.exec();
        exit(404);
    }
    */
}
