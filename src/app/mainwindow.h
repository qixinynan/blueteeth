#ifndef _MAIN_WINDOW_H_
#define _MAIN_WINDOW_H_
#include <QMainWindow>
#include <QSystemTrayIcon>
#include <QBluetoothDeviceInfo>

class MainWindow: public QMainWindow {
  Q_OBJECT
public:
  explicit MainWindow(QWidget *parent = nullptr);
  ~MainWindow() override;

private:
  QSystemTrayIcon *tray;

  QMenu *menu;
  QAction *showAction;
  QAction *quitAction;


  void createTray(QWidget *parent);
  void closeEvent(QCloseEvent *event);
  void updateTrayMenu();
private slots:
  void on_activatedSysTrayIcon(QSystemTrayIcon::ActivationReason reason);

  void deviceDiscovered(const QBluetoothDeviceInfo &device);
};
#endif