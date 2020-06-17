#include "mvpch.h"
#include "Buffer.h"

#include "Renderer.h"
#include "Platform/OpenGL/OpenGLBuffer.h"

namespace Minerva {


	/////////////////////////////////////////////////////////////////////////////////////
	// Vertex Buffer ////////////////////////////////////////////////////////////////////
	/////////////////////////////////////////////////////////////////////////////////////

	VertexBuffer* VertexBuffer::Create(float* vertices, uint32_t size)
	{
		switch (Renderer::GetAPI())
		{
		case RendererAPI::API::NONE:
			MV_CORE_ASSERT(false, "Renderer API \"NONE\" is currently unsupported.");
			return nullptr;
		case RendererAPI::API::OPENGL:
			return new OpenGLVertexBuffer(vertices, size);
		}

		MV_CORE_ASSERT(false, "Invalid renderer API!");
		return nullptr;
	}

	/////////////////////////////////////////////////////////////////////////////////////
	// Index Buffer /////////////////////////////////////////////////////////////////////
	/////////////////////////////////////////////////////////////////////////////////////

	IndexBuffer* IndexBuffer::Create(uint32_t* indices, uint32_t count)
	{
		switch (Renderer::GetAPI())
		{
		case RendererAPI::API::NONE:
			MV_CORE_ASSERT(false, "Renderer API \"NONE\" is currently unsupported.");
			return nullptr;
		case RendererAPI::API::OPENGL:
			return new OpenGLIndexBuffer(indices, count);
		}

		MV_CORE_ASSERT(false, "Invalid renderer API!");
		return nullptr;
	}

}