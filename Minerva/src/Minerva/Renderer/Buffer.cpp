#include "mvpch.h"
#include "Buffer.h"

#include "Renderer.h"
#include "Minerva/Platform/OpenGL/OpenGLBuffer.h"

namespace Minerva {

	VertexBuffer* VertexBuffer::Create(float* vertices, uint32_t size)
	{
		switch (Renderer::GetAPI())
		{
		case RendererAPI::NONE:
			MV_CORE_ASSERT(false, "Renderer API \"NONE\" is currently unsupported.");
		case RendererAPI::OPENGL:
			return new OpenGLVertexBuffer(vertices, size);
		}

		MV_CORE_ASSERT(false, "Unknown renderer API!");
		return nullptr;
	}

	IndexBuffer* IndexBuffer::Create(uint32_t* indices, uint32_t count)
	{
		switch (Renderer::GetAPI())
		{
		case RendererAPI::NONE:
			MV_CORE_ASSERT(false, "Renderer API \"NONE\" is currently unsupported.");
		case RendererAPI::OPENGL:
			return new OpenGLIndexBuffer(indices, count);
		}

		MV_CORE_ASSERT(false, "Unknown renderer API!");
		return nullptr;
	}

}