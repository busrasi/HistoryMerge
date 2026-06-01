#include "GameBoardModel.h"

GameBoardModel::GameBoardModel(QObject *parent)
    : QAbstractListModel(parent)
{
    m_cells.resize(m_columns * m_rows);

    m_cells[0].itemLevel = 1;
    m_cells[0].itemName = nameForLevel(1);

    m_cells[1].itemLevel = 1;
    m_cells[1].itemName = nameForLevel(1);

    m_cells[5].itemLevel = 2;
    m_cells[5].itemName = nameForLevel(2);
}

int GameBoardModel::rowCount(const QModelIndex &parent) const
{
    if (parent.isValid())
        return 0;

    return m_cells.size();
}

QVariant GameBoardModel::data(const QModelIndex &index, int role) const
{
    if (!index.isValid())
        return {};

    const int row = index.row();

    if (row < 0 || row >= m_cells.size())
        return {};

    const Cell &cell = m_cells[row];

    switch (role) {
    case ItemLevelRole:
        return cell.itemLevel;
    case ItemNameRole:
        return cell.itemName;
    default:
        return {};
    }
}

QHash<int, QByteArray> GameBoardModel::roleNames() const
{
    return {
        { ItemLevelRole, "itemLevel" },
        { ItemNameRole, "itemName" }
    };
}

int GameBoardModel::columns() const
{
    return m_columns;
}

int GameBoardModel::rows() const
{
    return m_rows;
}

QString GameBoardModel::nameForLevel(int level) const
{
    switch (level) {
    case 1:
        return "Taş";
    case 2:
        return "Keskin Taş";
    case 3:
        return "El Baltası";
    case 4:
        return "Mızrak Ucu";
    case 5:
        return "İlkel Mızrak";
    default:
        return "";
    }
}