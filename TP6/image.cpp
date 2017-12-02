
/*************************************************************
* Titre: Travail pratique #6 - Interface Graphique
* Date:  02 Decembre 2017
* Auteur : Constantin Bouis 1783438 et Xavier Ralay 1786307
**************************************************************/


#include <QImageReader>
#include <QMessageBox>
#include <QGuiApplication>
#include <QDir>
#include "image.h"
#include "commandes.h"
#include "exceptionmauvaisformatimage.h"

using namespace std;
// Constructeur par defaut (construit une QImage par defaut)
Image::Image() {}

// Constructeur par parametre string
Image::Image(const std::string &cheminVersLeFichier) {
    // Convertit une string en QString avant d'ouvrir l'image
    QString chemin = QString::fromStdString(cheminVersLeFichier);
    ouverturDeImage(chemin);
}

// Constructeur par QString
Image::Image(const QString &cheminVersLeFichier) {
    ouverturDeImage(cheminVersLeFichier);
}

// Fonction permettant d'ouvrir une image
bool Image::ouverturDeImage(const QString &cheminVersLeFichier) {
    // Cree un QImageReader avec le chemin vers une image
    QImageReader reader(cheminVersLeFichier);
    // Tente de lire l'image

    reader.setAutoTransform(true);
    const QImage newImage = reader.read();

    // Si l'image est nulle
    if (newImage.isNull()) {
        QString msg = tr("Impossible de lire l'image %1: %2")
                .arg(QDir::toNativeSeparators(cheminVersLeFichier), reader.errorString());



        /* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
        * * * * * * * * * * * * * * * *  TODO * * * * * * * * * * * * * * * * * * 
        * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
        // Lancer une exception mauvais format image
        throw ExceptionMauvaisFormatImage(msg);
        return false;
    }

    // L'image est enregistree dans l'attribut image_
    image_ = newImage;
    nomDuFichier_ = QFileInfo(cheminVersLeFichier);
    undoRedo_.clear();
    
    // Emettre un signal pour que la vue se mette a jour avec la nouvelle image
       emit signal_changementImage(image_);
    return true;
}

// Fonction qui enregistre une image a l'emplacement indique
bool Image::enregistrerImage(const QString &cheminVersEnregistrement) {
    image_.save(cheminVersEnregistrement);
    return true;
}

// Fonction qui converti une image en nuance de gris
void Image::convertirEnNuanceDeGris() {
    shared_ptr<InterfaceCommande> c(new ConvertirEnGris(&image_));
    c->Executer();
    undoRedo_.insererDansUndosRedos(c);
    /* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
     * * * * * * * * * * * * * * * *  TODO * * * * * * * * * * * * * * * * * * 
     * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
    // emettre le signal de changement dans l'image
    emit signal_changementImage(image_); // ou image_
}

// Fonction qui converti une image en NB
void Image::convertirEnNoirEtBlanc() {
    shared_ptr<InterfaceCommande> c(new ConvertirEnNoirEtBlanc(&image_));
    c->Executer();
    undoRedo_.insererDansUndosRedos(c);
     /* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
     * * * * * * * * * * * * * * * *  TODO * * * * * * * * * * * * * * * * * *
     * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
    // emettre le signal de changement dans l'image
    emit signal_changementImage(image_); // ou image_
}

// Fonction qui converti une image en negatif
void Image::mettreEnNegatif() {
    shared_ptr<InterfaceCommande> c(new MettreEnNegatif(&image_));
    c->Executer();
    undoRedo_.insererDansUndosRedos(c);
    /* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
     * * * * * * * * * * * * * * * *  TODO * * * * * * * * * * * * * * * * * *
     * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
    // emettre le signal de changement dans l'image
    emit signal_changementImage(image_); // ou image_
}

// Fonction qui permet d'annuler la derniere action effectuee sur limage
void Image::undo(){
    undoRedo_.undo();
    emit signal_changementImage(image_);
}

// Fonction qui permet deffectuer laction qui a ete precedemment effectuee sur limage
void Image::redo(){
    undoRedo_.redo();
    emit signal_changementImage(image_);
}
