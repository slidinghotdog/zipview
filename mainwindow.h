#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QtWidgets>
#include <quazip/quazip.h>
#include <quazip/quazipfile.h>

#include "delegate.h"

class Area : public QScrollArea {
    Q_OBJECT;

    using QScrollArea::QScrollArea;
protected:
    void resizeEvent(QResizeEvent *e) override {
        QScrollArea::resizeEvent(e);
        emit resized();
    };
signals:
    void resized();
};

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(int argc, char *argv[], QWidget *parent = nullptr);
    ~MainWindow();

private:
    QSettings *s;
    QString openFolder;
    QWidget *wid;
    QVBoxLayout *vbox;
    Area *area;
    QTimer *resizeTimer;
    QComboBox *pageComboBox;
    QSpinBox *scrollSpin;
    QLabel *currentPage;
    QPushButton *selectBtn;
    QString zipName;
    QString fileName;
    QStringList fileList;
    int lastIndex;
    QLabel *defaultLabel;
    QLabel *endLabel;
    QListView *thumbView;
    QStandardItemModel *model;
    QList<QLabel *> allLabels;
    QList<QPixmap> allPixmaps;

    int getImageWidth();
    void resizeTimeout();
//    bool compare(const QString &v1, const QString &v2);
    void loadFile(QString f);
    void loadThumbs();
    void loadFromIndex(int index = 0);
    void loadNext();
    void loadPrev();
    void loadPixmaps();
    void scrollChanged(int v);
    void updatePage();
    void dragEnterEvent(QDragEnterEvent *e) override;
    void dropEvent(QDropEvent *e) override;
    void closeEvent(QCloseEvent *e) override;
};
#endif // MAINWINDOW_H
