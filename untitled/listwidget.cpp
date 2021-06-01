#include "listwidget.h"
#include <QPainter>
#include <QListWidget>
#include <QLineEdit>
#include <QPushButton>
#include <QVBoxLayout>
#include <QLabel>
#include <QMessageBox>

ListWidget::ListWidget(QWidget *parent)
    : QWidget(parent)
{
    listWidget->setSelectionMode(QAbstractItemView::MultiSelection);
    //sort items
    listWidget->sortItems();
    //window title
    //setWindowTitle(tr("widget plugin"));
    resize(400, 400);


    connect(text, SIGNAL(textChanged(QString)),this, SLOT(read(QString)));

    QVBoxLayout *vboxlist=new QVBoxLayout;
    vboxlist->addWidget(listWidget);
    gridlayout->addWidget(text,0,0,1,1);
    gridlayout->addLayout(vboxlist,1,0,1,1);
    this->setLayout(gridlayout);
}

void ListWidget::read(QString s)
{
    for(int row(0); row < listWidget->count(); row++ )
    listWidget->item(row)->setHidden(true);
    QList<QListWidgetItem *> list= listWidget->findItems(s, Qt::MatchStartsWith);
    for(QListWidgetItem* item : list)
    item->setHidden(false);
}

void ListWidget::adding(QString ikon,QString item)
{
    new QListWidgetItem(QIcon(ikon),item, listWidget);
}

void ListWidget::paintEvent(QPaintEvent *)
{
    QPainter painter(this);
}

