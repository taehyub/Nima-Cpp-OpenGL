#ifndef _NIMA_GLRENDERER2D_HPP_
#define _NIMA_GLRENDERER2D_HPP_

#include "../Renderer2D.hpp"
#include "GLRenderer.hpp"

namespace nima
{
	class GLShader;
	class GLShaderProgram;
	class GLShaderAttribute;
	class GLVertexBuffer;
	class GraphicsBuffer;

	class GLRenderer2D : public GLRenderer, public Renderer2D
	{
		private:
			BlendMode m_BlendMode;
			int m_ViewportWidth;
			int m_ViewportHeight;
			float m_ProjectionMatrix[16];
			float m_ViewMatrix[16];
			float m_TransformMatrix[16];

		public:
			GLRenderer2D();

			BlendMode blendMode() const;
			void setBlendMode(BlendMode mode);
			void setViewportSize(int width, int height);
			void clear();
			void drawTextured(const Mat2D& view, const Mat2D& transform, const GraphicsBuffer* vertexBuffer, const GraphicsBuffer* indexBuffer, float opacity, const Color& color, const Texture* texture);

			Texture* makeTexture(const Bitmap* bitmap, int flags);
			GraphicsBuffer* makeVertexBuffer();
			GraphicsBuffer* makeIndexBuffer();

	};
}

#endif