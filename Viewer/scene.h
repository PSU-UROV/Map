#ifndef SCENE_H
#define SCENE_H

class SurfaceStore;

class Scene
	: public QObject
{
	public:
		Scene(QObject *parent = 0);

	Q_SIGNALS:
		void surfaceAdded(const Surface &surface);
		void surfaceRemoved(const Surface &surface);

	public Q_SLOTS:
		void messageReceived(MapMessage &msg);

		SurfaceStore *m_surfaceStore;

};

#endif // SCENE_H
