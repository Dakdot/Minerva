#pragma once

#include "Minerva/Renderer/RendererAPI.h"

namespace Minerva {

	class OpenGLRendererAPI : public RendererAPI
	{
		virtual void Clear(const glm::vec4& color) override;

		virtual void DrawIndexed(const std::shared_ptr<VertexArray>& vertexArray) override;
	};

}