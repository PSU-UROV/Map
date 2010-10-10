#ifndef SURFACE_STORE_H
#define SURFACE_STORE_H

class SurfaceStore
{

	public:
		SurfaceStore();

		void insertSurface(Surface *surface);

	private:
		VolumeIndexer *m_rootIndexer;

};

#endif

