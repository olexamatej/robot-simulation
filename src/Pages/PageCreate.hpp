#pragma once

#include <QWidget>
#include <QStackedWidget>
#include <QPushButton>
#include <QVBoxLayout>
#include <QShowEvent>
#include <QDebug>
#include <QMessageBox>
#include <QDialog>
#include <QSpinBox>
#include <QFormLayout>
#include <QDialogButtonBox>
#include <QtWidgets>
#include <QPixmap>


#include <memory>

#include "Sprite.hpp"
#include "Robot.hpp"

#include "Map.hpp"
#include "Controller.hpp"
#include "CustomGraphicsView.hpp"


class PageCreate : public QWidget
{
    Q_OBJECT;
    
    public:
        PageCreate(QStackedWidget *stackedWidget, QWidget *parent = nullptr, Controller *controller = nullptr);
        ~PageCreate();
    protected:
        void showEvent(QShowEvent *event) override;
    private slots:
        void startRecordingClicks();
        void handleMouseClick(int x, int y);
    private:
        QStackedWidget *m_stackedWidget;
        Controller *controller;
        CustomGraphicsView* view;
        std::unique_ptr<Map> map;
};
