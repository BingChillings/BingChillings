#include "highscoresform.h"
#include "ui_highscoresform.h"

HighScoresForm::HighScoresForm(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::HighScoresForm)
{
    ui->setupUi(this);
}

HighScoresForm::~HighScoresForm()
{
    delete ui;
}
