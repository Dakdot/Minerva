#pragma once

#include "VertexArray.h"
#include <glm/glm.hpp>

#include <memory>

namespace Minerva {

	class RendererAPI
	{
	public:
		enum class API
		{
			NONE = 0, OPENGL = 1
		};

	public:
		virtual void Clear(const glm::vec4& color) = 0;

		virtual void DrawIndexed(const std::shared_ptr<VertexArray>& vertexArray) = 0;

		static API GetAPI() { return s_API; }

	private:
		static API s_API;

	};

}