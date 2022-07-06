#ifndef PRINCIPAL_H
#define PRINCIPAL_H

#include <QMainWindow>
#include <QPainter>
#include <QFileDialog>
#include <QMessageBox>
#include <QPaintEvent>

QT_BEGIN_NAMESPACE
namespace Ui { class Principal; }
QT_END_NAMESPACE

class Principal : public QMainWindow
{
    Q_OBJECT

public:
    Principal(QWidget *parent = nullptr);
    ~Principal();

protected:
    void paintEvent(QPaintEvent *event) override;

private slots:
    void on_actionGuardar_triggered();

    void on_pushButton_clicked(bool checked);

    void on_inNota1_valueChanged(int arg1);

    void on_inNota2_valueChanged(int arg1);

    void on_inNota3_valueChanged(int arg1);

private:
    Ui::Principal *ui;
    QPixmap lienzo;

    void dibujar();
    int getAlto(int valor);
    int incY(int alto);



    int promedio(int n1,int n2,int n3);
};
#endif // PRINCIPAL_H
