#pragma once

#include "RendererAPI.h"

namespace Minerva {

	class RenderCommand
	{
	public:
		inline static void Clear(const glm::vec4& color)
		{
			s_RendererAPI->Clear(color);
		}

		inline static void DrawIndexed(const std::shared_ptr<VertexArray>& vertexArray)
		{
			s_RendererAPI->DrawIndexed(vertexArray);
		}

	private:
		static RendererAPI* s_RendererAPI;
	};

}