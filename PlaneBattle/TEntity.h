#pragma once
#include <objbase.h>
#include <QPointF>
#include <QGraphicsPixmapItem>

/* ʵ���� */
class CTEntity
{
public:
	/* ��Ӫ */
	enum Camp
	{
		Red = 0, // �췽
		Blue = 1, // ����
	};

	CTEntity(void);
	~CTEntity(void);

	/* ��ȡʵ��ID */
	GUID getID();

	/* ʵ��λ�� */
	QPointF getPos();
	void setPos(QPointF point);

	/* ʵ���С */
	QSize getSize();
	void setSize(QSize size);

	/* ����ʵ��ͼ�� */
	QString getIconPath();
	void setIconPath(QString iconPath);

	/* ʵ����Ӫ */
	Camp getCamp();
	void setCamp(Camp camp);

private:
	GUID m_id; // ʵ��ID
	QPointF m_pos; // ʵ��λ��
	QSize m_size; // ʵ���С
	Camp m_camp; // ʵ����Ӫ
	QString m_iconPath; // ʵ��ͼ��·��
};

typedef std::shared_ptr<CTEntity> CTEntityPtr;
typedef std::list<CTEntityPtr> CTEntityList;