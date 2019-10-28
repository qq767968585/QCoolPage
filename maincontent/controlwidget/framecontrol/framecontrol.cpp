﻿#include "framecontrol.h"
#include "ui_framecontrol.h"
#include <QFrame>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QLabel>
#include <QPushButton>

FrameControl::FrameControl(QFrame *parent) :
    QFrame(parent)
{
    this->setFixedWidth(FIXED_WIDTH);
    this->setFixedHeight(FIXED_HEIGHT);
    this->setObjectName("frameApplication");
}

FrameControl::~FrameControl()
{
}

void FrameControl::setLabelPixMap(const QPixmap &pixMap)
{
    if (labelImage != nullptr) {
        labelImage->setPixmap(pixMap);
    }
}

void FrameControl::setTitleInfo(const QString &title)
{
    if (labelTitle != nullptr) {
        labelTitle->setText(title);
    }
}

void FrameControl::createFrame(const QPixmap &pixMap, const QString &title)
{
    QHBoxLayout *hBoxLayout = new QHBoxLayout(this);
    labelImage = new QLabel(this);
    labelImage->setFixedSize(IMAGE_SIZE, IMAGE_SIZE);
    labelImage->setPixmap(pixMap);
    labelImage->setScaledContents(true);


    labelTitle = new QLabel(this);
    labelTitle->setText(title);
    labelTitle->setFixedSize(BUTTON_WIDTH, BUTTON_HEIGHT);

    pushButtonDownLoad = new QPushButton(this);
    pushButtonDownLoad->setText(tr("下载"));
    pushButtonDownLoad->setFixedSize(BUTTON_WIDTH, BUTTON_HEIGHT);
    QVBoxLayout *vBoxLayout = new QVBoxLayout();
    vBoxLayout->addWidget(labelTitle);
    vBoxLayout->addWidget(pushButtonDownLoad);
    hBoxLayout->addWidget(labelImage);
    hBoxLayout->addLayout(vBoxLayout);
}