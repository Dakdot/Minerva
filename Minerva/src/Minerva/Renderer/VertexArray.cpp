#include "mvpch.h"
#include "VertexArray.h"

#include "Renderer.h"
#include "Platform/OpenGL/OpenGLVertexArray.h"

namespace Minerva {

	VertexArray* VertexArray::Create()
	{
		switch (Renderer::GetAPI())
		{
		case RendererAPI::API::NONE:
			MV_CORE_ASSERT(false, "Renderer API \"NONE\" is currently unsupported.");
			return nullptr;
		case RendererAPI::API::OPENGL:
			return new OpenGLVertexArray();
		}

		MV_CORE_ASSERT(false, "Invalid renderer API!");
		return nullptr;
	}

}