////////////////////////////////////////////////////////////////////////////////
// Filename: modelclass.h
////////////////////////////////////////////////////////////////////////////////
#ifndef _MODELCLASS_H_
#define _MODELCLASS_H_


//////////////
// INCLUDES //
//////////////
#include <d3d11.h>
#include <d3dx10math.h>


////////////////////////////////////////////////////////////////////////////////
// Class name: ModelClass
////////////////////////////////////////////////////////////////////////////////
class ModelClass
{
private:
	struct VertexType
	{
		D3DXVECTOR3 position;
	    D3DXVECTOR4 color;
	};
	D3DXMATRIX dee = {
			-4.0f, -0.5f, 0.0f,         0.0f,
		 -3.0f, 0.5f, 0.0f  ,      0.0f,
		 -3.0f, -0.5f, 0.0f,             0.0f,
		 0.0f,            0.0f,            0.0f,            1.0f
	};



	D3DXMATRIX  square = {
		-1.0f, 2.0f, 0.0f,         0.0f,
	 -1.0f, 3.0f, 0.0f,      0.0f,
	 1.0f, 3.0f, 0.0f,             0.0f,
	 0.0f,            0.0f,            0.0f,            1.0f
	};

	
	D3DXMATRIX square2 = {
		1.0f, 3.0f, 0.0f,         0.0f,
	1.0f, 2.0f, 0.0f  ,      0.0f,
	-1.0f, 2.0f, 0.0f,             0.0f,
	 0.0f,            0.0f,            0.0f,            1.0f
	};



	D3DXMATRIX hexagon1 = {
0.0f, 0.0f, 0.0f,            0.0f,
-1.0f,0.0f, 0.0f  ,      0.0f,
-0.5f, 1.0f, 0.0f,             0.0f,
 0.0f,            0.0f,            0.0f,            1.0f
	};

	D3DXMATRIX hexagon2 = {
0.0f, 0.0f, 0.0f,        0.0f,
-0.5f, 1.0f, 0.0f  ,      0.0f,
0.5f, 1.0f, 0.0f,             0.0f,
 0.0f,            0.0f,            0.0f,            1.0f
	};

	D3DXMATRIX hexagon3 = {
0.0f, 0.0f, 0.0f,         0.0f,
0.5f, 1.0f, 0.0f  ,      0.0f,
1.0f, 0.0f, 0.0f,             0.0f,
 0.0f,            0.0f,            0.0f,            1.0f
	};

	D3DXMATRIX hexagon4 = {
0.0f, 0.0f, 0.0f,           0.0f,
1.0f, 0.0f, 0.0f  ,      0.0f,
0.5f, -1.0f, 0.0f,             0.0f,
 0.0f,            0.0f,            0.0f,            1.0f
	};

	D3DXMATRIX hexagon5 = {
0.0f, 0.0f, 0.0f,            0.0f,
0.5f, -1.0f, 0.0f,      0.0f,
-0.5f, -1.0f, 0.0f,             0.0f,
 0.0f,            0.0f,            0.0f,            1.0f
	};

	D3DXMATRIX hexagon6 = {
0.0f, 0.0f, 0.0f,         0.0f,
-0.5f, -1.0f, 0.0f ,      0.0f,
-1.0f,0.0f, 0.0f ,             0.0f,
 0.0f,            0.0f,            0.0f,            1.0f
	};










public:
	ModelClass();
	ModelClass(const ModelClass&);
	~ModelClass();

	bool Initialize(ID3D11Device*);
	void Shutdown();
	void Render(ID3D11DeviceContext*);

	int GetIndexCount();

	void ro();

private:
	bool InitializeBuffers(ID3D11Device*);
	void ShutdownBuffers();
	void RenderBuffers(ID3D11DeviceContext*);

private:
	ID3D11Buffer *m_vertexBuffer, *m_indexBuffer;
	int m_vertexCount, m_indexCount;
};

#endif