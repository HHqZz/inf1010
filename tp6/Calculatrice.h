/*********************************************************
* Titre: Travail pratique #6 - Calculatrice.cpp
* Date:  19 Avril 2017
*Auteur : Constantin Bouis 1783438, Hammami Ahmed 1796523
**********************************************************/

#ifndef CALCULATRICE_H
#define CALCULATRICE_H


#include<QWidget>
#include<QMessageBox>
#include<QPushButton>


QT_BEGIN_NAMESPACE
class QLineEdit;
QT_END_NAMESPACE

class Bouton;
class Calculatrice : public QWidget
{
    Q_OBJECT
public:
    Calculatrice(QWidget *parent = 0);

private slots:
    void digitClicked();
    void unaryOperatorClicked();
    void additiveOperatorClicked();
    void multiplicativeOperatorClicked();
    void equalClicked();
    void pointClicked();
    void changeSignClicked();
    void backspaceClicked();
    void clear();
    void clearAll();
    void clearMemory();
    void readMemory();
    void setMemory();
    void addToMemory();

private:
    Bouton *createButton(const QString &text, const char *member);
    void abortOperation();
    bool calculate(double rightOperand, const QString &spendingOperator);
    double sumInMemory;
    double sumSoFar;
    double factorSoFar;
    QString pendingAdditiveOperator;
    QString pendingMultiplicativeOperator;
    bool waitingForOperand;
    QLineEdit *display;

    enum {NumDigitButtons = 10};
    Bouton *digitButtons[NumDigitButtons];
    QPushButton *m_boutonDialogue;

};


#endif // CALCULATRICE_H
