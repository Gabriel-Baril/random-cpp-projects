#include "Renderer.h"

Renderer::Renderer() {}

void Renderer::render(const std::vector<std::vector<Chunk>>& chunks,const GLuint& fullTransformationUniformLocation, const glm::mat4& viewProjectionMatrix)
{
	std::vector<Chunk> toRender = RendererOptimizer::selectChunkToLoad(chunks);
	toRender = RendererOptimizer::viewFrustumCullingAlgorithm(toRender, Application::camera.getViewFrustum());
	glm::mat4 fullTransformMatrix;
	std::vector<Block> visible_blocks;
	for (GLuint i = 0; i < toRender.size(); i++)
	{
		visible_blocks = RendererOptimizer::selectNonObstruedBlocks(toRender[i].getBlocks());
		for (GLuint j = 0; j < visible_blocks.size(); j++)
		{
			Block c_block = visible_blocks[j];
			fullTransformMatrix = glm::translate(viewProjectionMatrix, (vec3)c_block.getPositionRelativeToWorld());
			glUniformMatrix4fv(fullTransformationUniformLocation, 1, GL_FALSE, &fullTransformMatrix[0][0]); // - 3/8 fps
			glDrawElements(GL_TRIANGLES, 36, GL_UNSIGNED_SHORT, (void*)0);
		}
	}
}
