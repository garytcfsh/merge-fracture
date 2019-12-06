#include <QCoreApplication>
#include <QDebug>
#include <QFile>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    QString inPath = "E:\\toothpick\\program\\merge_fracture\\a_set1_all.fab";
    QFile fileIn( inPath);
    fileIn.open( QFile::ReadOnly|QFile::Text);
    QTextStream fileInQTS( &fileIn);

    QString outPath = "E:\\toothpick\\program\\mff\\build-mff-Desktop_Qt_5_13_0_MinGW_32_bit-Debug\\debug\\MaficDefinition_regionbox_2_1.mff";
    QFile fileOut( outPath);
    fileOut.open( QFile::WriteOnly|QFile::Text);
    QTextStream fileOutQTS( &fileOut);

    QStringList in, oneLine, initiative, passive;
    while (!fileInQTS.atEnd())
        in.append(fileInQTS.readLine());

    int row = -1;
    for (int i=0; i<in.count()-3; i++)
    {
        if (in[i] == "BEGIN FRACTURE")
            row = i;
    }
qDebug()<<row;
    for (int i=row+1; i<in.count()-3; i++)
    {
//        initiative = (in[i].simplified().split(" "));
        for (int j=i+1; j<in.count(); j++)
        {
//            passive = (in[j].simplified().split(" "));
            if (in[i] == in[j])
            {
                qDebug()<<in[i];
                in.removeAt(j);
                j--;
            }
        }
    }

qDebug()<<"finish";
    return a.exec();
}
