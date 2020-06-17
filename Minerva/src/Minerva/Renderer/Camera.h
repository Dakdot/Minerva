#pragma once

#include <glm/glm.hpp>

namespace Minerva {

	class OrthoCamera {
	public:
		OrthoCamera(float left, float right, float top, float bottom);

		const glm::vec3& GetPosition() const { return m_Position; }
		const float GetRotation() const { return m_Rotation;  }

		void SetPosition(const glm::vec3& position) { RecalculateViewMatrix(); m_Position = position; }
		void SetRotation(const float rotation) { RecalculateViewMatrix(); m_Rotation = rotation; }

		const glm::mat4 GetViewMatrix() const { return m_ViewMatrix; }
		const glm::mat4 GetProjectionMatrix() const { return m_ProjectionMatrix; }
		const glm::mat4 GetVPMatrix() const { return m_VPMatrix; }

	private:
		void RecalculateViewMatrix();

	private:
		glm::mat4 m_ViewMatrix;
		glm::mat4 m_ProjectionMatrix;
		glm::mat4 m_VPMatrix;

		glm::vec3 m_Position = glm::vec3(0.0f);
		float m_Rotation = 0.0f; // Z rotation

	};

}