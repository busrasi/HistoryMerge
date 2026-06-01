#ifndef GAMEBOARDMODEL_H
#define GAMEBOARDMODEL_H

#include <QAbstractListModel>
#include <QObject>
#include <QVector>

class GameBoardModel : public QAbstractListModel
{
    Q_OBJECT

public:
    enum Roles {
        ItemLevelRole = Qt::UserRole + 1,
        ItemNameRole
    };

    explicit GameBoardModel(QObject *parent = nullptr);

    int rowCount(const QModelIndex &parent = QModelIndex()) const override;
    QVariant data(const QModelIndex &index, int role) const override;
    QHash<int, QByteArray> roleNames() const override;

    Q_INVOKABLE int columns() const;
    Q_INVOKABLE int rows() const;

private:
    struct Cell {
        int itemLevel = 0;
        QString itemName;
    };

    QVector<Cell> m_cells;
    int m_columns = 7;
    int m_rows = 9;

    QString nameForLevel(int level) const;
};

#endif