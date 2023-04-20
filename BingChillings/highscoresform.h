#ifndef HIGHSCORESFORM_H
#define HIGHSCORESFORM_H

#include <QWidget>

namespace Ui {
class HighScoresForm;
}

class HighScoresForm : public QWidget
{
    Q_OBJECT

public:
    explicit HighScoresForm(QWidget *parent = nullptr);
    ~HighScoresForm();

private:
    Ui::HighScoresForm *ui;
};

#endif // HIGHSCORESFORM_H
