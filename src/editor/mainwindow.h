#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <iostream>
#include <QMainWindow>
#include <QtWidgets>

#include "Widgets/ennemy_editor.h"
#include "Widgets/qpathcreator.h"
#include "Widgets/bullet_editor.h"

#include "configfile.h"

#include"project.h"

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = 0);
    ~MainWindow();

    void createDockWindows();
    void createCentralArea();
    void createActions();
    void refreshProjectTree();

    void loadProject(std::string path, bool addToRecent = true);

    void loadTreeFile(QString file);


public slots:
    void loadProject();
    void loadProject(int);
    void saveProject();
    void newFile(int sender);
    void addFile(int sender);
    void loadTreeFile(QModelIndex index);

signals:
    void projectLoaded(bool);

private:
    QMdiArea *centralArea;

    std::vector<QMdiSubWindow*> window_list;

    QDir *projectRoot;

    QFileSystemModel *projectModel;
    QTreeView *projectView;

    Project *project;
    ConfigFile *config_file;

};

#endif // MAINWINDOW_H
