
#include "mainwindow.h"
#include <QLabel>
#include <QMenu>
#include <QSystemTrayIcon>
#include <QTextEdit>
#include <QFileInfo>
#include <QApplication>
#include <QCloseEvent>
#include <QPushButton>

#include <QtBluetooth/qtbluetoothglobal.h>
#include <QtBluetooth/qbluetoothlocaldevice.h>
#include <QtBluetooth/qbluetoothsocket.h>
#include <QtBluetooth/qbluetoothservicediscoveryagent.h>
#include <QtBluetooth/qbluetoothaddress.h>


void MainWindow::createTray(QWidget *parent) {
  menu = new QMenu(this);
  updateTrayMenu();

  QIcon icon(":/assets/tray.ico");
  tray = new QSystemTrayIcon(this);
  tray->setIcon(icon);
  tray->setToolTip("Blueteeth");
  tray->setContextMenu(menu);
  connect(tray,&QSystemTrayIcon::activated,this,&MainWindow::on_activatedSysTrayIcon);
  tray->show();
}

void MainWindow::updateTrayMenu() {
  showAction = new QAction("显示", this);
  quitAction = new QAction("退出", this);
  connect(showAction, &QAction::triggered, this, &MainWindow::show);
  connect(quitAction, &QAction::triggered, qApp, &QApplication::quit);

  menu->addAction(showAction);
  menu->addSeparator();

//  for (const auto &item : bluetoothDevices) {
//    qDebug() << item.name.c_str();
//    menu->addAction(new QAction(item.name.c_str(), this));
//  }

  menu->addSeparator();

  menu->addAction(quitAction);
}

MainWindow::MainWindow(QWidget *parent) {
  resize(400, 300);

  QBluetoothDeviceDiscoveryAgent *discoveryAgent;//用来对周围蓝牙进行搜寻
  QBluetoothLocalDevice *localDevice;//对本地设备进行操作，比如进行设备的打开，设备的关闭等等
  QBluetoothSocket *socket;//就是用来进行蓝牙配对链接和数据传输的
  localDevice = new QBluetoothLocalDevice();  //本地操作
  discoveryAgent = new QBluetoothDeviceDiscoveryAgent();//用来发现扫描周围设备
  socket = new QBluetoothSocket(QBluetoothServiceInfo::RfcommProtocol);//用来与蓝牙的连接和数据传输

  if( localDevice->hostMode() == QBluetoothLocalDevice::HostPoweredOff)//判断开机有没有打开蓝牙
  {
    localDevice->powerOn();//调用打开本地的蓝牙设备

  }
  discoveryAgent->start();//开始扫描蓝牙设备
  connect(discoveryAgent,SIGNAL(deviceDiscovered(QBluetoothDeviceInfo)) ,SLOT(deviceDiscovered(QBluetoothDeviceInfo)));

  qDebug() << "QDebg";

  setWindowTitle("Blueteeth!");
  createTray(this);

  auto button = new QPushButton("刷新",this) ;
  connect(button, &QPushButton::clicked, [=]() {updateTrayMenu();});

}

void MainWindow::deviceDiscovered(const QBluetoothDeviceInfo &device)
{
  qDebug() << "Found new device:" << device.name() << '(' << device.address().toString() << ')';
}

MainWindow::~MainWindow() noexcept { delete tray; }

void MainWindow::closeEvent(QCloseEvent *event) {
  tray->showMessage("Blueteeth将在后台继续运行", "你可以右键托盘菜单快速连接蓝牙");
  this->hide();
  event->ignore();
}


void MainWindow::on_activatedSysTrayIcon(
    QSystemTrayIcon::ActivationReason reason) {
  switch (reason) {
  case QSystemTrayIcon::Trigger:
    break;
  case QSystemTrayIcon::DoubleClick:
    this->show();
    break;
  default:
    break;
  }
}
