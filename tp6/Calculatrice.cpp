#include<QtGui>
#include<QlineEdit>
#include<QVBoxLayout>
#include<QHBoxLayout>
#include<QGridLayout>

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
    Bouton *changeSignButton = createButton(tr("+-"), SLOT(changeSignClicked()));

    Bouton *backspaceButton = createButton(tr("Backspace"), SLOT(backspaceClicked()));
    Bouton *clearButton = createButton(tr("Clear"), SLOT(clear()));
    Bouton *clearAllButton = createButton(tr("Clear All"), SLOT(clearAll()));
	
	// Créez les boutons manquants ici
	//...
    Bouton *MCButton = createButton(tr("MC"), SLOT(clearMemory()));
    Bouton *MRButton = createButton(tr("MR"), SLOT(readMemory()));
    Bouton *MSButton = createButton(tr("MS"), SLOT(setMemory()));
    Bouton *MPlusButton = createButton(tr("M+"), SLOT(addToMemory()));

    Bouton *divisionButton = createButton(tr("/"), SLOT(multiplicativeOperatorClicked()));
    Bouton *timesButton = createButton(tr("*"), SLOT(multiplicativeOperatorClicked()));
    Bouton *minusButton = createButton(tr("-"), SLOT(additiveOperatorClicked()));
    Bouton *plusButton = createButton(tr("+"), SLOT(additiveOperatorClicked()));

    Bouton *squareRootButton = createButton(tr("Sqrt"), SLOT(unaryOperatorClicked()));
    Bouton *powerButton = createButton(tr("x^2"), SLOT(unaryOperatorClicked()));
    Bouton *reciprocalButton = createButton(tr("1/x"), SLOT(unaryOperatorClicked()));
    Bouton *equalButton = createButton(tr("="), SLOT(equalClicked()));

		//Déclarez votre layout ici
		//...
        QVBoxLayout* mainLayout = new QVBoxLayout;
        QVBoxLayout* layout1 = new QVBoxLayout;
        QHBoxLayout* layout2 = new QHBoxLayout;
        QGridLayout* layout3 = new QGridLayout;
		//Gerer le positionnement des boutons sur le layout ici
		//...
        layout1->addWidget(display);

        layout2->addWidget(backspaceButton);
        layout2->addWidget(clearButton);
        layout2->addWidget(clearAllButton);

        layout3->addWidget(MCButton,0,0);
        layout3->addWidget(digitButtons[7],0,1);
        layout3->addWidget(digitButtons[8],0,2);
        layout3->addWidget(digitButtons[9],0,3);
        layout3->addWidget(divisionButton,0,4);
        layout3->addWidget(squareRootButton,0,5);
        layout3->addWidget(MRButton,1,0);
        layout3->addWidget(digitButtons[4],1,1);
        layout3->addWidget(digitButtons[5],1,2);
        layout3->addWidget(digitButtons[6],1,3);
        layout3->addWidget(timesButton,1,4);
        layout3->addWidget(powerButton,1,5);
        layout3->addWidget(MSButton,2,0);
        layout3->addWidget(digitButtons[1],2,1);
        layout3->addWidget(digitButtons[2],2,2);
        layout3->addWidget(digitButtons[3],2,3);
        layout3->addWidget(minusButton,2,4);
        layout3->addWidget(reciprocalButton,2,5);
        layout3->addWidget(MPlusButton,3,0);
        layout3->addWidget(digitButtons[0],3,1);
        layout3->addWidget(pointButton,3,2);
        layout3->addWidget(changeSignButton,3,3);
        layout3->addWidget(plusButton,3,4);
        layout3->addWidget(equalButton,3,5);

        mainLayout->addLayout(layout1);
        mainLayout->addLayout(layout2);
        mainLayout->addLayout(layout3);
		// Ajout du layout à la fenetre principale
        setLayout(mainLayout);
		// Ajout du titre de la  fenetre
        setWindowTitle(tr("Calculatrice"));
}

/********************************************************************************
 * Description      : afficher le contenu du bouton appuié
 * Paramètres       : Aucun
 * Type de retour   : void
 *******************************************************************************/
void Calculatrice::digitClicked()
{
    Bouton *clickedButton = qobject_cast<Bouton* >(sender());
    int digitValue = clickedButton->text().toInt();
    if(display->text() =="0" && digitValue == 0.0) /* si le contenu du bouton appuié est 0 , et le text
                                                   déjà affiché est 0 , on fait rien */
        return;


    if(waitingForOperand)   // si l'utilisaruer clique sur un opérande, on affiche 0
    {
        display->clear();
        waitingForOperand = false;
    }
    display->setText(display->text() + QString::number(digitValue)); /* on affiche le text qui était avant avec le
                                                                     contenu du bouton appuié */

}

/********************************************************************************
 * Description      : calcule et affiche le resultat de l'operation choisie entre
 1/x , racine(x)et carré(x)
 * Paramètres       : Aucun
 * Type de retour   : void
 *******************************************************************************/
void Calculatrice::unaryOperatorClicked()
{
    Bouton* clickedButton = qobject_cast<Bouton*>(sender());
    QString clickedOperator = clickedButton->text();
    double operand = display->text().toDouble();
    double result = 0.0;

    if(clickedOperator == tr("Sqrt")) // si le bouton cliqué est 'sqrt'
    {
        try
        {
            if(operand < 0.0)
            {
                abortOperation();    // on ne fait pas la racine d'un nombre négatif
                throw InvalidValueException("Exception racine carre negative impossible !");
            }
             result = sqrt(operand);
        }
        catch (InvalidValueException& e)
        {
            QMessageBox messageBox;
            messageBox.critical(0,"error",e.what());
            return;
        }
    }
    else if(clickedOperator == tr("x^2"))
    {
        result = pow(operand, 2.0);
    }
    else if(clickedOperator == tr("1/x"))
    {
        try
        {
            if(operand == 0.0)
            {
               abortOperation();      // on ne fait pas l'opération si l'opérand est égal à 0
              throw InvalidValueException("Exception inverse de 0 impossible !");
            }
             result = 1.0 / operand;
        }
        catch (InvalidValueException& e)
        {
            QMessageBox messageBox;
            messageBox.critical(0,"error",e.what());
            return;
        }

    }
    display->setText(QString::number(result));     // on affiche le résultat
    waitingForOperand = true;                       // on se met en atente pour nouvelle entrée d'opérande
}

/********************************************************************************
 * Description      : reconnaitre l'opérateur '+' et place
 * Paramètres       : Aucun
 * Type de retour   : void
 *******************************************************************************/
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

/********************************************************************************
 * Description      :
 * Paramètres       : Aucun
 * Type de retour   : void
 *******************************************************************************/
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
    else if(pendingOperator == tr("*"))
    {
        factorSoFar *= rightOperand;
    }
    else if(pendingOperator == tr("/"))
    {
        try
        {
            if (rightOperand == 0.0)
            {
                abortOperation();
                throw InvalidValueException("Exception division par 0 impossible !");
            }
        factorSoFar /= rightOperand;
        }
        catch(InvalidValueException& e)
        {
            QMessageBox messageBox;
            messageBox.critical(0,"error",e.what());
            return false;
        }
    }
    return true;

}



