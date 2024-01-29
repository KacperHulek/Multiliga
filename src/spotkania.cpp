#include "spotkania.h"
#include "ui_spotkania.h"
Spotkania::Spotkania(QWidget *parent, DatabaseManager *dbManager) :
    QDialog(parent),
    ui(new Ui::Spotkania),
    dbManager(dbManager)
{
    ui->setupUi(this);

    this->model = new QSqlQueryModel();
    model->setQuery("SELECT * FROM [HarmonogramSpotkan]");
    ui->tableView->setModel(model);

//    QSqlQuery query;
//    QDateTime today = QDateTime::currentDateTime();
//    QDateTime oneWeekAgo = today.addDays(-7);
//    query.prepare("SELECT * FROM Matches WHERE [date] > :oneWeekAgo ORDER BY [date] DESC");
//    query.bindValue(":oneWeekAgo", oneWeekAgo);
//if (query.exec()) {
//    while (query.next()) {
//        QString imieGraczaA;
//        QString nazwiskoGraczaA;
//        QString imieGraczaB;
//        QString nazwiskoGraczaB;
//        QString nazwaLigi;
//        QString dyscyplina;
//        QString nazwaBoiska;
//        QString data = query.value("date").toString();
//        int playeraID = query.value("playeraID").toInt();
//        int playerbID = query.value("playerbID").toInt();

//        QSqlQuery queryPlayeraID, queryPlayerbID;

//        queryPlayeraID.prepare("SELECT * FROM Players WHERE [ID] = :playeraID");
//        queryPlayeraID.bindValue(":playeraID", playeraID);

//        queryPlayerbID.prepare("SELECT * FROM Players WHERE [ID] = :playerbID");
//        queryPlayerbID.bindValue(":playerbID", playerbID);

//        if (queryPlayeraID.exec() && queryPlayeraID.next()) {
//            int idUzytkownikaGraczaA = queryPlayeraID.value("userID").toInt();
//            QSqlQuery queryUserA;
//            queryUserA.prepare("SELECT * FROM Users WHERE [ID] = :useraID");
//            queryUserA.bindValue(":useraID", idUzytkownikaGraczaA);

//            if (queryUserA.exec() && queryUserA.next()) {
//                imieGraczaA = queryUserA.value("name").toString();
//                nazwiskoGraczaA = queryUserA.value("surname").toString();
//            } else {
//                qDebug() << "Błąd zapytania dla queryUserA: " << queryUserA.lastError().text();
//            }
//        } else {
//            qDebug() << "Błąd zapytania dla queryPlayeraID: " << queryPlayeraID.lastError().text();
//        }

//        if (queryPlayerbID.exec() && queryPlayerbID.next()) {
//            int idUzytkownikaGraczaB = queryPlayerbID.value("userID").toInt();
//            QSqlQuery queryUserB;
//            queryUserB.prepare("SELECT * FROM Users WHERE [ID] = :userbID");
//            queryUserB.bindValue(":userbID", idUzytkownikaGraczaB);

//            if (queryUserB.exec() && queryUserB.next()) {
//                imieGraczaB = queryUserB.value("name").toString();
//                nazwiskoGraczaB = queryUserB.value("surname").toString();
//            } else {
//                qDebug() << "Błąd zapytania dla queryUserB: " << queryUserB.lastError().text();
//            }
//        } else {
//            qDebug() << "Błąd zapytania dla queryPlayerbID: " << queryPlayerbID.lastError().text();
//        }

//        int leagueID = query.value("leagueID").toInt();
//        QSqlQuery queryLeagueID;
//        queryLeagueID.prepare("SELECT * FROM Leagues WHERE [ID] = :leagueID");
//        queryLeagueID.bindValue(":leagueID", leagueID);
//        if(queryLeagueID.exec() && queryLeagueID.next()){
//            nazwaLigi = queryLeagueID.value("name").toString();
//            dyscyplina = queryLeagueID.value("discipline").toString();
//        }
//        else{

//            qDebug() << "Błąd zapytania dla queryLeagueID: " << queryLeagueID.lastError().text();
//        }

//        int courtID = query.value("courtID").toInt();
//        QSqlQuery queryCourtID;
//        queryCourtID.prepare("SELECT * FROM Courts WHERE [ID] = :courtID");
//        queryCourtID.bindValue(":courtID", courtID);
//        if(queryCourtID.exec() && queryCourtID.next()){
//            nazwaBoiska = queryCourtID.value("name").toString();
//        }
//        else{
//            qDebug() << "Błąd zapytania dla queryCourtID: " << queryCourtID.lastError().text();
//        }

//        QTableWidgetItem *item1 = new QTableWidgetItem(dyscyplina);
//        QTableWidgetItem *item2 = new QTableWidgetItem(nazwaLigi);
//        QTableWidgetItem *item3 = new QTableWidgetItem(imieGraczaA + " " +nazwiskoGraczaA);
//        QTableWidgetItem *item4 = new QTableWidgetItem(imieGraczaB + " " +nazwiskoGraczaB);
//        QTableWidgetItem *item5 = new QTableWidgetItem(nazwaBoiska);
//        QTableWidgetItem *item6 = new QTableWidgetItem(data);

//        int row = ui->tableWidget->rowCount();
//        ui->tableWidget->insertRow(row);
//        ui->tableWidget->setItem(row, 0, item1);
//        ui->tableWidget->setItem(row, 1, item2);
//        ui->tableWidget->setItem(row, 2, item3);
//        ui->tableWidget->setItem(row, 3, item4);
//        ui->tableWidget->setItem(row, 4, item5);
//        ui->tableWidget->setItem(row, 5, item6);
//    }
//    ui->tableWidget->resizeColumnsToContents();
//} else {
//    qDebug() << "Błąd zapytania dla query: " << query.lastError().text();
//}


    //ui->listWidget->addItem()
}

Spotkania::~Spotkania()
{
    delete ui;
}
