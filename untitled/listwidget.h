#ifndef LISTWIDGET_H
#define LISTWIDGET_H

#include <QListWidget>
#include <QWidget>
#include <QtUiPlugin/QDesignerExportWidget>
#include <QLineEdit>
#include <QGridLayout>


class ListWidget : public QWidget
{
    Q_OBJECT

public:
    explicit ListWidget(QWidget *parent = nullptr);
    QListWidget *listWidget = new QListWidget(this);
    QLineEdit *text=new QLineEdit;
    QGridLayout *gridlayout=new QGridLayout;
    void adding(QString,QString);
protected:
    void paintEvent(QPaintEvent *event) override;

public slots:
  void read(QString);

};


#endif // LISTWIDGET_H
