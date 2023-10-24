#ifndef WORLD_H
#define WORLD_H

#include "block.h"
#include "chunk.h"
#include "globalSettings.h"
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <FastNoise/FastNoise.h>
#include <unordered_set>
class World
{
public:
	World();
	~World();
	void setup();
	void update(float dt);
	Block* getBlockAt(int x, int y, int z, int chunkNumber);

private:
	void createNewChunk(int x, int y);
	void loadChunks();
	void updateLoadedChunks();
	void moveCenterChunkLeft();
	void moveCenterChunkRight();
	void moveCenterChunkForward();
	void moveCenterChunkBack();
	void updateChunkIndex();
	void remeshChunks();
	Chunk* loadedChunks[LOADEDCHUNKWIDTH * LOADEDCHUNKWIDTH];
	int seed;
	glm::vec3 centerChunkPos;
	FastNoise::SmartNode<FastNoise::Simplex> grassTerrain;
	std::unordered_set<int> chunksToRemesh;
};

extern glm::vec3 playerPos;

#endif