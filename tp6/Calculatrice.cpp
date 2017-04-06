#include<QtGui>

#include<math.h>

#include"Bouton.h"
#include"Calculatrice.h"
#include"Erreur.h"

Calculatrice::Calculatrice(QWidget *parent): QWidget(parent)
{

    sumInMemory = 0.0;
    sumSoFar = 0.0;
    factorSoFar = 0.0;
    waitingForOperand = true;
	//creation d'un objet de type QLineEdit avec par défaut la chaine de caractère 0
	//cette objet représente une zone de texte qui sera utilisé comme afficheur de la calculatrice
    display = new QLineEdit("0");
	
	// la zone de texte est paramétrée en lecture seule
    display->setReadOnly(true);
	
	// l'affichage se fera de la droite vers la gauche
    display->setAlignment(Qt::AlignRight);
	
	// définition de la largeur de la zone de texte à 15
    display->setMaxLength(15);

    QFont font = display->font();
    font.setPointSize(font.pointSize() + 8);
    display->setFont(font);

    //MaFenetre  fenetre1;
    for(int i=0; i<NumDigitButtons; ++i)
    {
        digitButtons[i] = createButton(QString::number(i), SLOT(digitClicked()));
    }

    Bouton *pointButton = createButton(tr("."), SLOT(pointCliked()));
    Bouton *changeSignButton = createButton(tr("\261"), SLOT(changeSignClicked()));

    Bouton *backspaceButton = createButton(tr("Backspace"), SLOT(backspaceClicked()));
    Bouton *clearButton = createButton(tr("Clear"), SLOT(clear()));
    Bouton *clearAllButton = createButton(tr("Clear All"), SLOT(clearAll()));
	
	// Créez les boutons manquants ici
	//...


    Bouton *divisionButton = createButton(tr("\367"), SLOT(multiplicativeOperatorClicked()));
    Bouton *timesButton = createButton(tr("\327"), SLOT(multiplicativeOperatorClicked()));
    Bouton *minusButton = createButton(tr("-"), SLOT(additiveOperatorClicked()));
    Bouton *plusButton = createButton(tr("+"), SLOT(additiveOperatorClicked()));

    Bouton *squareRootButton = createButton(tr("Sqrt"), SLOT(unaryOperatorClicked()));
    Bouton *powerButton = createButton(tr("x\262"), SLOT(unaryOperatorClicked()));
    Bouton *reciprocalButton = createButton(tr("1/x"), SLOT(unaryOperatorClicked()));
    Bouton *equalButton = createButton(tr("="), SLOT(equalClicked()));

		//Déclarez votre layout ici
		//...
		
		//Gerer le positionnement des boutons sur le layout ici
		//...
		
		// Ajout du layout à la fenetre principale
		setLayout(mainLayout);
		// Ajout du titre de la  fenetre
        setWindowTitle(tr("Calculatrice"));
}

void Calculatrice::digitClicked()
{
    Bouton *clickedButton = qobject_cast<Bouton* >(sender());
    int digitValue = clickedButton->text().toInt();
    if(display->text() =="0" && digitValue == 0.0)
        return;


    if(waitingForOperand)
    {
        display->clear();
        waitingForOperand = false;
    }
    display->setText(display->text() + QString::number(digitValue));

}

void Calculatrice::unaryOperatorClicked()
{
    Bouton* clickedButton = qobject_cast<Bouton*>(sender());
    QString clickedOperator = clickedButton->text();
    double operand = display->text().toDouble();
    double result = 0.0;

    if(clickedOperator == tr("Sqrt"))
    {
            if(operand < 0.0)
            {
                abortOperation();
                return;
            }
        result = sqrt(operand);
    }
    else if(clickedOperator == tr("x\262"))
    {
        result = pow(operand, 2.0);
    }
    else if(clickedOperator == tr("1/x"))
    {
            if(operand == 0.0)
            {
               abortOperation();
              return;
            }
             result = 1.0 / operand;
    }
    display->setText(QString::number(result));
    waitingForOperand = true;
}

void Calculatrice::additiveOperatorClicked()
{
    Bouton* clickedButton = qobject_cast<Bouton*>(sender());
    QString clickedOperator = clickedButton->text();
    double operand = display->text().toDouble();

    sumSoFar = operand;

    pendingAdditiveOperator = clickedOperator;

    waitingForOperand = true;
}

void Calculatrice:: multiplicativeOperatorClicked()
{
    Bouton* clickedButton = qobject_cast<Bouton*>(sender());
    QString clickedOperator = clickedButton->text();
    double operand = display->text().toDouble();

    factorSoFar = operand;

    pendingMultiplicativeOperator = clickedOperator;

    waitingForOperand = true;
}

void Calculatrice::equalClicked()
{
    double operand = display->text().toDouble();

    if(!pendingMultiplicativeOperator.isEmpty())
    {
        if(!calculate(operand, pendingMultiplicativeOperator))
        {
            abortOperation();
            return;
        }
        operand = factorSoFar;
        factorSoFar = 0.0;
        pendingMultiplicativeOperator.clear();
    }
    if(!pendingAdditiveOperator.isEmpty())
    {
        if(!calculate(operand, pendingAdditiveOperator))
        {
            abortOperation();
            return;
        }
        pendingAdditiveOperator.clear();
    }
    else
    {
        sumSoFar = operand;
    }

    display->setText(QString::number(sumSoFar));
    sumSoFar = 0.0;
    waitingForOperand = true;
}

void Calculatrice::pointClicked()
{
    if(waitingForOperand)
    {
        display->setText("0");
    }
    if(!display->text().contains("."))
    {
        display->setText(display->text() + tr("."));
    }
    waitingForOperand = false;
}

void Calculatrice::changeSignClicked()
{
    QString text = display->text();
    double value = text.toDouble();

    if(value > 0.0)
    {
        text.prepend(tr("-"));
    }
    else if(value < 0.0)
    {
        text.remove(0, 1);
    }
    display->setText(text);
}

void Calculatrice::backspaceClicked()
{
    if(waitingForOperand)
        return;

    QString text = display->text();
    text.chop(1);
    if(text.isEmpty())
    {
        text = "0";
        waitingForOperand = true;
    }
    display->setText(text);
}

void Calculatrice::clear()
{
    if(waitingForOperand)
        return;

    display->setText("0");
    waitingForOperand = true;
}

/********************************************************************************
 * Description      : Réinitialise toutes les valeurs et toutes les opérations
 * Paramètres       : Aucun
 * Type de retour   : void
 *******************************************************************************/ 
void Calculatrice::clearAll()
{
    sumSoFar = 0.0;
    factorSoFar = 0.0;
    pendingAdditiveOperator.clear();
    pendingMultiplicativeOperator.clear();
    display->setText("0");
    waitingForOperand = true;

}

void Calculatrice::clearMemory()
{
    sumInMemory = 0.0;
}

void Calculatrice::readMemory()
{
    display->setText(QString::number(sumInMemory));
    waitingForOperand = true;
}

void Calculatrice::setMemory()
{
    equalClicked();
    sumInMemory = display->text().toDouble();
}

void Calculatrice::addToMemory()
{
    equalClicked();
    sumInMemory += display->text().toDouble();
}

Bouton *Calculatrice::createButton(const QString &text, const char *member)
{
    Bouton *button = new Bouton(text);
    connect(button, SIGNAL(clicked()), this, member);
    return button;
}

void Calculatrice::abortOperation()
{
    clearAll();
    return;
}

bool Calculatrice::calculate(double rightOperand, const QString &pendingOperator)
{
    if(pendingOperator == tr("+"))
    {
        sumSoFar +=rightOperand;
    }
    else if(pendingOperator == tr("-"))
    {
        sumSoFar -= rightOperand;
    }
    else if(pendingOperator == tr("\327"))
    {
        factorSoFar *= rightOperand;
    }
    else if(pendingOperator == tr("\367"))
    {
        try
        {
            if (rightOperand == 0.0)
            {
                abortOperation();
                 return false;
            }
        factorSoFar /= rightOperand;
        }
        catch(std::exception const& e)
        {
            QMessageBox::critical(this, "Error", e.what());
        }
    }
    return true;

}



