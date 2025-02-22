#include "principal.h"
#include "ui_principal.h"

Principal::Principal(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Principal)
{
    ui->setupUi(this);
    lienzo = QPixmap(500,500);
    this->dibujar();

    ui->outCuadro->setPixmap(lienzo);

}

Principal::~Principal()
{
    delete ui;
}

void Principal::paintEvent(QPaintEvent *event)
{
    ui->outCuadro->setPixmap(lienzo);
    //Aceptar el evento
    event->accept();
}

void Principal::dibujar()
{
    lienzo.fill(Qt::white);

    QPainter painter(&lienzo);

    int x = 15;
    int y = 0;

    // Crear un pincel para los bordes
    QPen pincel;
    pincel.setWidth(5);
    pincel.setColor(Qt::blue);
    pincel.setJoinStyle(Qt::MiterJoin);
    //Establecer color de relleno
    QColor colorRelleno1(69,113,252);
    // Establecer el pincel al "pintor"
    painter.setPen(pincel);
    painter.setBrush(colorRelleno1);

    //Obtener datos para primera barra
    int nota1=ui->inNota1->value();
    int altoN1=this->getAlto(nota1);
    int incYN1=this->incY(altoN1);

    // Dibujar primera barra
    painter.drawRect(x+60, y+50+incYN1,100,altoN1);

    // Crear un objeto color para el relleno
    QColor colorRelleno(77,156,89);
    // Crear otro objeto color para el borde
    QColor colorBorde(0,120,18);

    // Cambiar el color del pincel
    pincel.setColor(colorBorde);

    // Volver a establecer el pincel al "pintor"
    painter.setPen(pincel);

    // Establecer el color al brush (relleno)
    painter.setBrush(colorRelleno);

    //Obtener datos para segunda barra
    int nota2=ui->inNota2->value();
    int altoN2=this->getAlto(nota2);
    int incYN2=this->incY(altoN2);

    // Dibujar segunda barra
    painter.drawRect(x+180, y+50+incYN2, 100, altoN2);

    // Creando los colores de la tercera barra
    QColor cRellenoBarra3(229, 166, 89);
    QColor cBordeBarra3(185, 111, 17);

    // Estableciendo colores al puncel y al painter
    pincel.setColor(cBordeBarra3);
    painter.setPen(pincel);
    painter.setBrush(cRellenoBarra3);

    //Obtener datos para tercera barra
    int nota3=ui->inNota3->value();
    int altoN3=this->getAlto(nota3);
    int incYN3=this->incY(altoN3);

    // Dibujar tercera barra
    painter.drawRect(x+300,y+50+incYN3,100,altoN3);

    //Creando los colores del plano
    QColor cProm(0, 0, 0);

    // Estableciendo colores al puncel y al painter
    pincel.setColor(cProm);
    painter.setPen(pincel);

    float prom1=promedio(nota1,nota2,nota3);
    int altoN4=this->getAlto(prom1);
    int incYN4=this->incY(altoN4);
    painter.drawLine(x+25,incYN4+50,450,incYN4+50);

    // Creando los colores del plano cartesiano
    QColor cPlano(35, 211, 187);

    // Estableciendo colores al puncel y al painter
    pincel.setColor(cPlano);
    painter.setPen(pincel);

    // Dibujar plano
    painter.drawLine(x+25,y+450,450,450);
    painter.drawLine(x+25,y+15,x+25,450);

    // Creando los colores para numero de intervalo
    QColor cIntervalo(0, 0, 0);

    // Estableciendo colores al pincel y al painter
    pincel.setColor(cIntervalo);
    painter.setPen(pincel);

    //Poner intervalos

    for(int i=0;i<=10;i++){
        QString intervalo;
        int c=0;
        int a=this->getAlto(i);
        int d=this->incY(a);
        c=i*10;
        intervalo=QString::number(c);
        painter.drawText(x-10,d+55,intervalo);
    }
    painter.drawText(x+85,y+475,"Nota 1");
    painter.drawText(x+205,y+475,"Nota 2");
    painter.drawText(x+325,y+475,"Nota 3");
}

int Principal::getAlto(int valor)
{
    return 40*valor;
}

int Principal::incY(int alto)
{
    return 400-alto;
}

int Principal::promedio(int n1, int n2, int n3)
{
    return (n1+n2+n3)/3;
}


void Principal::on_actionGuardar_triggered()
{
    QString nombreArchivo = QFileDialog::getSaveFileName(
                this,"Guardar imagen",QString(),"Imagenes (*.png)");
    if (!nombreArchivo.isEmpty()){
        if (lienzo.save(nombreArchivo))
            QMessageBox::information(this,"Guardar imagen","Archivo guarado en: " + nombreArchivo);
        else
            QMessageBox::warning(this,"Guardar imagen","No se pudo guardar el archivo");
    }
}

void Principal::on_pushButton_clicked(bool checked)
{

}

void Principal::on_inNota1_valueChanged(int arg1)
{
    dibujar();
}

void Principal::on_inNota2_valueChanged(int arg1)
{
    dibujar();
}

void Principal::on_inNota3_valueChanged(int arg1)
{
    dibujar();
}
