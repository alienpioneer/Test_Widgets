#include "TableModel.h"

TableModel::TableModel(QObject *parent)
    : QAbstractTableModel(parent),
      m_rowCount(0),
      m_columnCount(0)
{
}

QVariant TableModel::headerData(int section, Qt::Orientation orientation, int role) const
{
    if (role != Qt::DisplayRole) {
        return QVariant();
    }
    if (orientation == Qt::Horizontal) {

        if( section < m_headerLabels.size())
            return m_headerLabels.at(section);
        else
            qCritical() << "Section out of range!";
    }

    // vertical rows
    return QString("Not Implemented");
}

int TableModel::rowCount(const QModelIndex &parent) const
{
    if (parent.isValid())
        return m_rowCount;
}

int TableModel::columnCount(const QModelIndex &parent) const
{
    if (parent.isValid())
        return m_columnCount;
}

QVariant TableModel::data(const QModelIndex &index, int role) const
{
    if (!index.isValid())
        return QVariant();

    // FIXME: Implement me!
    return QVariant();
}

bool TableModel::setData(const QModelIndex &index, const QVariant &value, int role)
{
    return true;
}

bool TableModel::setHeaderData(int section, Qt::Orientation orientation, const QVariant &value, int role)
{
    if (role != Qt::DisplayRole)
    {
        return false;
    }

    if (orientation == Qt::Horizontal)
    {
        insertColumns(section, 1, QModelIndex());
        m_headerLabels.append(value.toString());

        emit headerDataChanged(orientation, section, section);
        return true;
    }

    return false;
}

bool TableModel::insertRows(int row, int count, const QModelIndex &parent)
{
    beginInsertRows(parent, row, row+count-1);
    m_rowCount+=count;
    endInsertRows();

    return  true;
}

bool TableModel::insertColumns(int column, int count, const QModelIndex &parent)
{
    beginInsertColumns(parent, column, column+count-1);
    m_columnCount+=count;
    endInsertColumns();

    return true;
}


bool TableModel::removeRows(int row, int count, const QModelIndex &parent)
{
    return true;
}

Qt::ItemFlags TableModel::flags(const QModelIndex &index) const
{
    if (!index.isValid())
    {
        return QAbstractItemModel::flags(index);
    }
    return QAbstractItemModel::flags(index) | Qt::ItemIsEditable;
}
