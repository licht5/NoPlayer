#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QWidget>
#include <QMediaPlayer>
#include <QMediaPlaylist>
#include <QVideoWidget>
#include <QMouseEvent>
#include <QBoxLayout>
#include <QAbstractItemView>
#include <QListView>
#include "videowidget.h"
#include "playcontrols.h"
#include "playlistmodel.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QWidget
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
	//�̳е���Ӧ�¼�
	void resizeEvent(QResizeEvent *event);
	void mouseMoveEvent(QMouseEvent *event);
	void mousePressEvent(QMouseEvent *event);
	void mouseReleaseEvent(QMouseEvent *event);
	
	//�Զ��庯��
    void updateWindowSize();
	bool isPosInRect(const QPoint &pos, const QRect &rect);

private slots:
	void durationChanged(qint64 duration);
	void nextClicked();
	void previousClicked();
	void fastforword();
	void rewind();

private:
	QMediaPlayer *player;
	QMediaPlaylist *playlist;
	QAbstractItemView *playlistView;
	PlaylistModel *playlistModel;
	QVideoWidget *videoWidget;

    Ui::MainWindow *ui;
	qint64 duration;
	QSize wndSize;
	bool mousePressed;
};

#endif // MAINWINDOW_H
