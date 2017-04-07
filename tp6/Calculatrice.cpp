/*********************************************************
* Titre: Travail pratique #6 - Calculatrice.cpp
* Date:  19 Avril 2017
*Auteur : Constantin Bouis 1783438, Hammami Ahmed 1796523
**********************************************************/


#include <QtGui>
#include <QlineEdit>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QGridLayout>

#include <math.h>

#include "Bouton.h"
#include "Calculatrice.h"
#include "Erreur.h"

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

    // Ajouts boutons memoire
    Bouton *MCButton = createButton(tr("MC"), SLOT(clearMemory()));
    Bouton *MRButton = createButton(tr("MR"), SLOT(readMemory()));
    Bouton *MSButton = createButton(tr("MS"), SLOT(setMemory()));
    Bouton *MPlusButton = createButton(tr("M+"), SLOT(addToMemory()));

    // Ajouts boutons du signe de loperation
    Bouton *divisionButton = createButton(tr("/"), SLOT(multiplicativeOperatorClicked()));
    Bouton *timesButton = createButton(tr("*"), SLOT(multiplicativeOperatorClicked()));
    Bouton *minusButton = createButton(tr("-"), SLOT(additiveOperatorClicked()));
    Bouton *plusButton = createButton(tr("+"), SLOT(additiveOperatorClicked()));

    Bouton *squareRootButton = createButton(tr("Sqrt"), SLOT(unaryOperatorClicked()));
    Bouton *powerButton = createButton(tr("x^2"), SLOT(unaryOperatorClicked()));
    Bouton *reciprocalButton = createButton(tr("1/x"), SLOT(unaryOperatorClicked()));
    Bouton *equalButton = createButton(tr("="), SLOT(equalClicked()));

		//Déclarez votre layout ici
        QVBoxLayout* mainLayout = new QVBoxLayout;  // Layout principale
        QVBoxLayout* layout1 = new QVBoxLayout;     // Layout text editor
        QHBoxLayout* layout2 = new QHBoxLayout;     // Layout des boutons clear et backspace
        QGridLayout* layout3 = new QGridLayout;     // Layout de la grille de bouton
		//Gerer le positionnement des boutons sur le layout ici
// layout
        layout1->addWidget(display);

// layout Clear et backSpace bouton
        layout2->addWidget(backspaceButton);
        layout2->addWidget(clearButton);
        layout2->addWidget(clearAllButton);

// layout grille
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
/******** FIN GRILLE *******************/

    // On ajoute les sous layout dans le mainLayout
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

/**********************************************************************************************
 * Description      : reconnait l'opérateur '+' et "-"
 * Paramètres       : Aucun
 * Type de retour   : void
 **********************************************************************************************/
void Calculatrice::additiveOperatorClicked()
{
    Bouton* clickedButton = qobject_cast<Bouton*>(sender());
    QString clickedOperator = clickedButton->text();
    double operand = display->text().toDouble();

    sumSoFar = operand;      // On stocke la valeur actuelle en memoire

    pendingAdditiveOperator = clickedOperator; // pendingAdditiveOperator prend + ou -

    waitingForOperand = true; //  Flag de loperation en attente true
}



/********************************************************************************
 * Description      : Reconnait lorsque l on selectionne multiplie ou diviser
 * Paramètres       : Aucun
 * Type de retour   : void
 *******************************************************************************/
void Calculatrice:: multiplicativeOperatorClicked()
{
    Bouton* clickedButton = qobject_cast<Bouton*>(sender());
    QString clickedOperator = clickedButton->text();
    double operand = display->text().toDouble();

    factorSoFar = operand; // Stocke la valeur actuelle en memoire

    pendingMultiplicativeOperator = clickedOperator;  // Loperation en attente devient loperateur clique : multiplier ou diviser

    waitingForOperand = true; //  Flag de loperation en attente true
}


/********************************************************************************
 * Description      : Reconnait la touche "=" et affiche le resultat
 * Paramètres       : Aucun
 * Type de retour   : void
 *******************************************************************************/
void Calculatrice::equalClicked()
{
    double operand = display->text().toDouble();  // Convertit le texte affiche en double et le stocke dans operand

    if(!pendingMultiplicativeOperator.isEmpty())  // S il y a une multiplication en attente
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

    display->setText(QString::number(sumSoFar)); // Affichage
    sumSoFar = 0.0;
    waitingForOperand = true;
}



/******************************************************************************************************
 * Description      : Reconnait si il y a un "." dans laffichage et affiche le texte suivit d'un point
 * Paramètres       : Aucun
 * Type de retour   : void
 *****************************************************************************************************/
void Calculatrice::pointClicked()
{
    if(waitingForOperand)
    {
        display->setText("0");    // Ne fait rien si on est toujours en attente d'un operand
    }
    if(!display->text().contains("."))
    {
        display->setText(display->text() + tr("."));
    }
    waitingForOperand = false;
}



/********************************************************************************
 * Description      : Change le signe du texte affiche
 * Paramètres       : Aucun
 * Type de retour   : void
 *******************************************************************************/
void Calculatrice::changeSignClicked()
{
    QString text = display->text(); // recupere le texte affiche a lecran en string
    double value = text.toDouble(); // stocke le texte en double

    if(value > 0.0)
    {
        text.prepend(tr("-"));  // Ajoute un "-" devant le texte si cest une valeur positive
    }
    else if(value < 0.0)
    {
        text.remove(0, 1);    // Remove le signe si cest une valeur negative
    }
    display->setText(text);   // Affiche le texte avec le nouveau signe
}


/********************************************************************************
 * Description      : Permet de retirer le dernier element du texte
 * Paramètres       : Aucun
 * Type de retour   : void
 *******************************************************************************/
void Calculatrice::backspaceClicked()
{
    if(waitingForOperand)
        return;                     // Quitte la fonction si on est en attente dun operand

    QString text = display->text(); // Recupere le texte affiche en string
    text.chop(1);                   // Enleve le premier element du texte
    if(text.isEmpty())
    {
        text = "0";
        waitingForOperand = true;     // Affiche 0 si le texte est maintenant vide
    }
    display->setText(text);           // Affiche le novueau texte
}


/********************************************************************************
 * Description      : Permet de vider laffichage = Affiche "0"
 * Paramètres       : Aucun
 * Type de retour   : void
 *******************************************************************************/
void Calculatrice::clear()
{
    if(waitingForOperand)
        return;                 // Quitte la fonction si on est en attente dun operand

    display->setText("0");      // Affiche 0 = clear
    waitingForOperand = true;   // Se met en attente dun operand
}



/********************************************************************************
 * Description      : Réinitialise toutes les valeurs et toutes les opérations
 * Paramètres       : Aucun
 * Type de retour   : void
 *******************************************************************************/
void Calculatrice::clearAll()
{
    sumSoFar = 0.0;               // Reinitialise la valeur de sumSoFar
    factorSoFar = 0.0;            // Reinitialise la valeur de factorSoFar
    pendingAdditiveOperator.clear();    // Reinitialise l'etat de pendingAdditiveOperator
    pendingMultiplicativeOperator.clear();    // Reinitialise l'etat de pendingMultiplicativeOperator
    display->setText("0");      // Affiche 0
    waitingForOperand = true;

}


/********************************************************************************
 * Description      : Vide toutes les valeurs en memoire
 * Paramètres       : Aucun
 * Type de retour   : void
 *******************************************************************************/
void Calculatrice::clearMemory()
{
    sumInMemory = 0.0;   // Reinitialise la valeur dans la memoire = 0
}


/********************************************************************************
 * Description      : Affiche le contenu de la memoire
 * Paramètres       : Aucun
 * Type de retour   : void
 *******************************************************************************/
void Calculatrice::readMemory()
{
    display->setText(QString::number(sumInMemory));   // Affiche la valeur contenu dans la memoire
    waitingForOperand = true;   // Passe en attente dun operand
}


/*****************************************************************************************************
 * Description      : Stocke dans la memoire la valeur affichee a lecran (apres avoir appuye sur "=")
 * Paramètres       : Aucun
 * Type de retour   : void
 *****************************************************************************************************/
void Calculatrice::setMemory()
{
    equalClicked();
    sumInMemory = display->text().toDouble();   // Convertit le texte en double et le stocke dans la memoire
}


/***************************************************************************************
 * Description      : Fait la somme entre le contenu de la memoire et le texte a lecran
 * Paramètres       : Aucun
 * Type de retour   : void
 **************************************************************************************/
void Calculatrice::addToMemory()
{
    equalClicked();
    sumInMemory += display->text().toDouble();    // Fais la somme entre le contenu de la memoire et le texte affiche
}


/*******************************************************************************************
 * Description      : Permet de creer un nouveau bouton en lui assignant un signal(connect)
 * Paramètres       : String&, char*
 * Type de retour   : Pointeur de type Bouton
 ******************************************************************************************/
Bouton *Calculatrice::createButton(const QString &text, const char *member)
{
    Bouton *button = new Bouton(text);        // Cree un bouton
    connect(button, SIGNAL(clicked()), this, member);   // Connect le bouton cree au signal
    return button;
}



/***************************************************************************************
 * Description      : Permet d'annuler une operation, vide laffichage
 * Paramètres       : Aucun
 * Type de retour   : void
 **************************************************************************************/
void Calculatrice::abortOperation()
{
    clearAll();   // Vide l'affichage
    return;     // Quitte la fonction sans rien faire de plus
}



/***************************************************************************************
 * Description      : Permet de faire le calcul de loperation suivant son operand
 * Paramètres       : Double, Qstring
 * Type de retour   :  Bool = Renvoie true si loperation sest effectuee sans erreur
 **************************************************************************************/
bool Calculatrice::calculate(double rightOperand, const QString &pendingOperator)
{
    if(pendingOperator == tr("+"))      // Reconnait loeprateur +
    {
        sumSoFar +=rightOperand;    // Fait une somme
    }
    else if(pendingOperator == tr("-")) // Reconnait loeprateur -
    {
        sumSoFar -= rightOperand;     // Fait une difference
    }
    else if(pendingOperator == tr("*")) // Reconnait loperateur +
    {
        factorSoFar *= rightOperand;
    }
    else if(pendingOperator == tr("/"))   // Reconnait loperateur de division
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
