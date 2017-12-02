
/*************************************************************
* Titre: Travail pratique #6 - Interface Graphique
* Date:  02 Decembre 2017
* Auteur : Constantin Bouis 1783438 et Xavier Ralay 1786307
**************************************************************/


#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QFileInfo>
#include "exceptionmauvaisformatimage.h"

// Constructeur de la fenetre principale de l'applicatin
MainWindow::MainWindow(QWidget *parent) :
   QMainWindow(parent),ui(new Ui::MainWindow), imageLabel_(new QLabel)

{
    ui->setupUi(this);
    creeActions();
    initUI();
    initConnections();
    //MainWindow : Constructeur de la fenêtre principale. Vous devez créer la variable
    //imageLabel_, tout le reste est fait pour vous.
}

// Destructeur de la fenetre principale de l'application
MainWindow::~MainWindow()
{
    delete ui;
}

// Fonction qui gere toutes les connections
void MainWindow::initConnections() {
    /* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
     * * * * * * * * * * * * * * * *  TODO * * * * * * * * * * * * * * * * * *
     * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
    // Connectez Ficher + ouvrir a la fonction ouvrirImage
    connect(actionOuvrir_,SIGNAL(triggered(bool)), this,SLOT(ouvrirImage()));
    // Connectez Fichier + enregistrer sous avec la fonction approprié)
    connect(actionEnregistrerSous_, SIGNAL(triggered(bool)),this, SLOT(enregistrerImage()));
    // Connectez aide + a propos a la fonction appropriée
    connect(actionAPropos_, SIGNAL(triggered(bool)),this, SLOT(about()));
    // Connectez Edition + undo a la fonction appropriée
    connect(undo_,SIGNAL(triggered(bool)), &image_, SLOT(undo()));
    // Connectez Edition + redo a la fonction appropriée
    connect(redo_,SIGNAL(triggered(bool)), &image_,SLOT(redo()));

    // Connectez le signal de mise a jour de l'image aux fonctions appropriées
    connect(&image_, SIGNAL(signal_changementImage(QImage)),this,SLOT(updateImage(QImage)));
    connect(&image_, SIGNAL(signal_changementImage(QImage)),this,SLOT(updateTableViewWidget(QImage)));

    // Connectez le click du bouton Noir et Blanc a la fonction appropriée
    connect(boutonNB_,SIGNAL(clicked(bool)),&image_,SLOT(convertirEnNoirEtBlanc()));
    // Connectez le click du bouton Nuance de Gris a la fonction appropriée
    connect(boutonGris_,SIGNAL(clicked(bool)),&image_,SLOT(convertirEnNuanceDeGris()));
    // Connectez le click du bouton Negatif a la fonction appropriée
    connect(boutonNegatif_,SIGNAL(clicked(bool)),&image_,SLOT(mettreEnNegatif()));
}

// Fonction permettant la selection et l'ouverture d'une image
void MainWindow::ouvrirImage() {
    QFileDialog dialog(this, tr("Ouvrir une image"));
    fileExplorer(dialog, QFileDialog::AcceptOpen);
    // Tant qu'aucune image n'a ete choisie ou que le dialogue
    // ne s'est pas conclu, demande de choisir une image.
    /* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
     * * * * * * * * * * * * * * * *  TODO * * * * * * * * * * * * * * * * * *
     * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
    // Attraper l'exception lancee par image_.ouvertureDeImage
    try{
    while(dialog.exec() == QDialog::Accepted && !image_.ouverturDeImage(dialog.selectedFiles().first())) {}
    }
    catch(ExceptionMauvaisFormatImage &e){
        afficherMessage(e.what());
    }
}

// Fonction qui permet d'enregistrer une image
void MainWindow::enregistrerImage() {
    // Enregistrer l'image avec le format jpg par defaut
    QString filename = QFileDialog::getSaveFileName(
                this, tr("Enregistrer l'image"),
                "", tr("JPEG (*.jpg);;All Files (*)")
    );

    // Si le nom du fichier n'est pas vide, enregistre l'image
    if(!filename.isEmpty()) {
        image_.enregistrerImage(filename);
    }
}

// Fonction qui cree une QMessageBox et affiche le message dans msg
void MainWindow::afficherMessage(QString msg) {
    /* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
     * * * * * * * * * * * * * * * *  TODO * * * * * * * * * * * * * * * * * *
     * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
    // Creez la boite de dialogue avec une QMessageBox.
    QMessageBox boiteDialogue ;
    boiteDialogue.setText(msg);
    // Cette boite doit afficher le message contenu dans msg
    boiteDialogue.exec();
}

// Fonction qui appelle afficherMessage pour afficher une QMessageBox
// comportant une explication du programme
void MainWindow::about() {
    QString msg = tr("Poly GIMP est une application QT simple permettant de lire une image et de la transformer en noir et blanc, nuance de gris ou negatif.\n©INF1010 automne 2017");
    afficherMessage(msg);
}

// Fonction mettant a jour la vue sur l'image
void MainWindow::updateImage(QImage image){
    /* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
     * * * * * * * * * * * * * * * *  TODO * * * * * * * * * * * * * * * * * *
     * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
    static bool first = true;
    // Modifiez la vue sur l'image. Attention, l'image
    // doit garder sa taille d'origine et ne pas etre distortionnee

    imageLabel_->setPixmap(QPixmap::fromImage(image));
    imageLabel_->adjustSize();

     // Lorsque ce sera fait, decommentez cette ligne
    const QString message = tr("Image \"%1\", %2x%3, Profondeur: %4")
            .arg(QDir::toNativeSeparators(image_.obtenirNomDuFichier().filePath())).arg(image.width()).arg(image.height()).arg(image.depth());
    ui->statusBar->showMessage(message);

    // Activez les boutons de modification ainsi que
    // la fonction d'enregistrement de l'image.
    if(first){
        activateButtons();
       actionEnregistrerSous_->setEnabled(true);
        first = false;
    }
}

// Fonction qui initialise le QTableWidget avec les informations de l'image
void MainWindow::updateTableViewWidget(QImage image) {
    /* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
     * * * * * * * * * * * * * * * *  TODO * * * * * * * * * * * * * * * * * *
     * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
    // Mettre a jour la table view avec les information de l'image
    QFileInfo fileInfo = image_.obtenirNomDuFichier();
    QString name = fileInfo.fileName();
    tableWidget_->setItem(0,1, new QTableWidgetItem(name));
    tableWidget_->setItem(1,1,new QTableWidgetItem(QString::number(image.width())));
    tableWidget_->setItem(2,1,new QTableWidgetItem(QString::number(image.height())));

}

// Fonction permettant d'activer tous les boutons
void MainWindow::activateButtons() {
    /* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
     * * * * * * * * * * * * * * * *  TODO * * * * * * * * * * * * * * * * * *
     * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
    // Activez les boutons, ne doit etre appele que lorsque l'image est ouverte
    boutonGris_->setEnabled(true);
    boutonNB_->setEnabled(true);
    boutonNegatif_ ->setEnabled(true);
}


// Dialogue permettant de choisir une image
void MainWindow::fileExplorer(QFileDialog &dialog, QFileDialog::AcceptMode acceptMode)
{
    static bool firstDialog = true;
    // S'il s'agit de la premiere fois que cette fenetre est ouverte
    if(firstDialog) {
        firstDialog = false;
        // Determine l'endroit ou se trouve le dossier image sur cet ordinateur
        const QStringList picturesLocations = QStandardPaths::standardLocations(QStandardPaths::PicturesLocation);
        if(picturesLocations.isEmpty())
        {   // S'il n'en existe pas, commencer a partir du repertoire courant
            dialog.setDirectory(QDir::currentPath());
        } else {
            dialog.setDirectory(picturesLocations.last());
        }

        // Filtre les types de fichiers afficher dans la fenetre de dialogue
        QStringList mimeTypeFilters;
        const QByteArrayList supportedMimeTypes = acceptMode == QFileDialog::AcceptOpen ? QImageReader::supportedMimeTypes() : QImageWriter::supportedMimeTypes();

        foreach(const QByteArray &mimeTypeName, supportedMimeTypes)
            mimeTypeFilters.append(mimeTypeName);

        dialog.setMimeTypeFilters(mimeTypeFilters);
        // Affiche les jpg par defaut
        dialog.selectMimeTypeFilter("image/jpeg");
        if(acceptMode == QFileDialog::AcceptSave)
            dialog.setDefaultSuffix("jpg");
    }
}

// Cree les actions de la barre de menu
void MainWindow::creeActions() {
    // Action fichier + ouvrir
    actionOuvrir_ = new QAction(tr("Ouvrir"), this);
    actionOuvrir_->setShortcut(QKeySequence::Open);
    // Action fichier + enregistrer sous
    actionEnregistrerSous_ = new QAction(tr("Enregistrer sous"), this);
    actionEnregistrerSous_->setEnabled(false);
    actionEnregistrerSous_->setShortcut(QKeySequence::SaveAs);
    // Action aide + a propos
    actionAPropos_ = new QAction(tr("À propos"), this);
    // Action edition + undo
    undo_ = new QAction(tr("Undo"), this);
    undo_->setShortcut(QKeySequence::Undo);
    // Action edition + redo
    redo_ =new QAction(tr("Redo"), this);
    redo_->setShortcut(QKeySequence::Redo);
}

// Initialisation de la fenetre principale
void MainWindow::initUI()
{
    // Donne une taille plus approriee a l'interface
    resize(QGuiApplication::primaryScreen()->availableSize() * 3 / 5);
    // Centre l'interface dans l'ecran
    QSize newSize(this->width(), this->height());
    setGeometry(
            QStyle::alignedRect(
                    Qt::LeftToRight,
                    Qt::AlignCenter,
                    newSize,
                    qApp->desktop()->availableGeometry()
            )
    );

    // Donne acces au QTableWidget
    tableWidget_ = ui->tableWidget;

    // Permet de configurer la portion avec scroll bar de l'interface
    imageScrollArea_ = ui->ImageScrollArea;
    imageScrollArea_->setBackgroundRole(QPalette::Dark);

    /* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
     * * * * * * * * * * * * * * * *  TODO * * * * * * * * * * * * * * * * * *
     * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
    // Ajoutes le menu fichier a la barre de menu principale
       QMenu *menu =menuBar()->addMenu("Fichier");
       menu->addAction(actionOuvrir_);
       menu->addAction(actionEnregistrerSous_);

    // Ajoutez le menu Edition a la barre de menu principale
       QMenu *edition =menuBar()->addMenu("Edition");;
       edition->addAction(undo_);
       edition->addAction(redo_);

    // Ajoutez le menu Aide a la barre de menu principale
       QMenu *aide= menuBar()->addMenu("Aide");
       aide->addAction(actionAPropos_);
    // GroupBox contenant les boutons
    groupBox_ = ui->groupBox;
    // Layout du groupBox (QHboxLayout)
    QLayout *groupBoxLayout = groupBox_->layout();

    // Ajoutez le bouton Noir et Blanc
       boutonNB_ = new QPushButton("Noir et Blanc");
       boutonNB_->setEnabled(false);
    // Ajoutez le bouton Nuances de Gris
        boutonGris_ = new QPushButton("Nuances de Gris");
        boutonGris_->setEnabled(false);
    // Ajoutez le bouton Negatif
        boutonNegatif_ = new QPushButton("Negative");
        boutonNegatif_->setEnabled(false);
    // Ajoutez les boutons au layout du groupBox
        groupBoxLayout->addWidget(boutonGris_);
        groupBoxLayout->addWidget(boutonNB_);
        groupBoxLayout->addWidget(boutonNegatif_);
    // Ajoutez l'attribut imageLabel_ au widget imageScrollArea_ et configurez le tel que demande
    imageScrollArea_->setWidget(imageLabel_);
    imageLabel_->setAlignment(Qt::AlignCenter);

}
