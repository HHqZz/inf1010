
/*************************************************************
* Titre: Travail pratique #6 - Interface Graphique
* Date:  02 Decembre 2017
* Auteur : Constantin Bouis 1783438 et Xavier Ralay 1786307
**************************************************************/

//
// Classe MauvaisFormatImage
// Cette classe definit l'exception a lancee lorsque
// l'image que l'on tente d'ouvrir n'est pas
// dans un format reconnu par la classe QImage
//
#ifndef EXCEPTIONMAUVAISFORMATIMAGE_H
#define EXCEPTIONMAUVAISFORMATIMAGE_H

#include <QException>
#include <QString>

class ExceptionMauvaisFormatImage : public QException {
    /* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
     * * * * * * * * * * * * * * * *  TODO * * * * * * * * * * * * * * * * * *
     * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
public :
    // Constructeur defaut
    ExceptionMauvaisFormatImage(QString string){
        s_ = string ;
    }

    // from documentation Qexception class
    void raise()const {throw *this;}
    //ExceptionMauvaisFormatImage *ExceptionMauvaisFormatImage::clone() const { return new ExceptionMauvaisFormatImage(*this); }
        QException *clone() const { return new ExceptionMauvaisFormatImage(*this); }
    //
    QString what(){return s_;}

private :
    QString s_;
};

#endif // EXCEPTIONMAUVAISFORMATIMAGE_H
