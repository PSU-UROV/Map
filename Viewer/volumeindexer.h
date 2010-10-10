#ifndef VOLUME_INDEXER_H
#define VOLUME_INDEXER_H

class VolumeIndexer
{

	public:
		VolumeIndexer();

	private:
		// Octree nodes
		VolumeIndexer *ufl;
		VolumeIndexer *ufr;
		VolumeIndexer *ubl;
		VolumeIndexer *ubr;
		VolumeIndexer *dfl;
		VolumeIndexer *dfr;
		VolumeIndexer *dbl;
		VolumeIndexer *dbr;

};

#endif

