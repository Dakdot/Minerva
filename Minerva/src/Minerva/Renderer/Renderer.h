#pragma once

#include "RenderCommand.h"
#include "Camera.h"
#include "Shader.h"

namespace Minerva {

	class Renderer
	{
	public:
		static void BeginScene(OrthoCamera& camera);
		static void EndScene();

		static void Submit(const std::shared_ptr<Shader>& shader, const std::shared_ptr<VertexArray>& vertexArray);

		static RendererAPI::API GetAPI() { return RendererAPI::GetAPI(); }

	private:
		struct SceneData
		{
			glm::mat4 VPMatrix;
		};

		static SceneData* m_SceneData;
	};

}