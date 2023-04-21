#include "newuserwindow.h"
#include "ui_newuserwindow.h"

NewUserWindow::NewUserWindow(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::NewUserWindow)
{
    ui->setupUi(this);
    setupGenderBox();
    connect(ui->submitButton, &QPushButton::clicked, this, &NewUserWindow::fillUserInfo);
    connect(ui->resetButton, &QPushButton::clicked, this, &NewUserWindow::resetFields);
}

NewUserWindow::~NewUserWindow()
{
    delete ui;
}

void NewUserWindow::setupGenderBox(){
    ui->genderComboBox->addItem("Male");
    ui->genderComboBox->addItem("Female");
    ui->genderComboBox->addItem("Other");
    ui->genderComboBox->addItem("Prefer Not to Say");
}

void NewUserWindow::fillUserInfo(){
    QString profilePictureFileName;
    if (ui->icecreamIconButton->isChecked()){
        profilePictureFileName = ":/images/images/ice-cream.png";
    }
    else if (ui->carIconButton->isChecked()){
        profilePictureFileName = ":/images/images/car.png";
    }
    else if (ui->dogIconButton->isChecked()){
        profilePictureFileName = ":/images/images/dog.png";
    }
    else if (ui->moonIconButton->isChecked()){
        profilePictureFileName = ":/images/images/moon.png";
    }
    else if (ui->planeIconButton->isChecked()){
        profilePictureFileName = ":/images/images/plane.png";
    }
    else if (ui->sunIconButton->isChecked()){
        profilePictureFileName = ":/images/images/sun.png";
    }
    else if (ui->treeIconButton->isChecked()){
        profilePictureFileName = ":/images/images/tree.png";
    }
    else if (ui->catIconButton->isChecked()){
        profilePictureFileName = ":/images/images/cat.png";
    }
    else if (ui->monsterIconButton->isChecked()){
        profilePictureFileName = ":/images/images/monster.png";
    }
    else if (ui->heartIconButton->isChecked()){
        profilePictureFileName = ":/images/images/heart.png";
    }
    else if (ui->starIconButton->isChecked()){
        profilePictureFileName = ":/images/images/star.png";
    }
    else if (ui->wheatIconButton->isChecked()){
        profilePictureFileName = ":/images/images/wheat.png";
    }
}

void NewUserWindow::resetFields(){
    QList<QPushButton *> listIcons = ui->userIconGroup->findChildren<QPushButton *>();
    for (auto icon : listIcons){
        icon->setAutoExclusive(false);
        icon->setChecked(false);
        icon->setAutoExclusive(true);
    }
    ui->icecreamIconButton->setChecked(true);
    ui->firstNameEdit->clear();
    ui->lastNameEdit->clear();
    ui->usernameEdit->clear();
    ui->passwordEdit->clear();
    ui->genderComboBox->clear();
    ui->birthdayEdit->setDate(QDate(2000,01,01));
}
