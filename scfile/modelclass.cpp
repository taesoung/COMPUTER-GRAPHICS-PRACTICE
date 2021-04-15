////////////////////////////////////////////////////////////////////////////////
// Filename: modelclass.cpp
////////////////////////////////////////////////////////////////////////////////
#include "modelclass.h"


ModelClass::ModelClass()
{
	m_vertexBuffer = 0;
	m_indexBuffer = 0;
}


ModelClass::ModelClass(const ModelClass& other)
{
}


ModelClass::~ModelClass()
{
}


bool ModelClass::Initialize(ID3D11Device* device)
{
	bool result;


	// Initialize the vertex and index buffers.
	result = InitializeBuffers(device);
	if(!result)
	{
		return false;
	}

	return true;
}


void ModelClass::Shutdown()
{
	// Shutdown the vertex and index buffers.
	ShutdownBuffers();

	return;
}


void ModelClass::Render(ID3D11DeviceContext* deviceContext)
{
	// Put the vertex and index buffers on the graphics pipeline to prepare them for drawing.
	RenderBuffers(deviceContext);

	return;
}


int ModelClass::GetIndexCount()
{
	return m_indexCount;
}
void ModelClass::ro() {

	D3DXMATRIX roX;
	D3DXMATRIX roY;
	D3DXMATRIX roZ;


	D3DXMatrixRotationX(&roX, 0.04f);
	D3DXMatrixRotationY(&roY, 0.02f);
	D3DXMatrixRotationZ(&roZ, 0.004f);


	square *= roY;
	square2 *= roY;
	hexagon1 *= roX;
	hexagon2 *= roX;
	hexagon3 *= roX;
	hexagon4 *= roX;
	hexagon5 *= roX;
	hexagon6 *= roX;
	dee *= roZ;


}

bool ModelClass::InitializeBuffers(ID3D11Device* device)
{
	D3DXMATRIX viewRotXMat;
	D3DXMATRIX viewRotYMat;
	D3DXMATRIX viewRotZMat;






	VertexType* vertices;
	unsigned long* indices;
	D3D11_BUFFER_DESC vertexBufferDesc, indexBufferDesc;
    D3D11_SUBRESOURCE_DATA vertexData, indexData;
	HRESULT result;

	
	// Set the number of vertices in the vertex array.
	m_vertexCount = 27;

	// Set the number of indices in the index array.
	m_indexCount = 54;

	// Create the vertex array.
	vertices = new VertexType[m_vertexCount];
	if(!vertices)
	{
		return false;
	}

	// Create the index array.
	indices = new unsigned long[m_indexCount];
	if(!indices)
	{
		return false;
	}
		

	// Load the vertex array with data.
	vertices[0].position = D3DXVECTOR3(dee._11, dee._12, dee._13);  // Bottom left.
	vertices[0].color = D3DXVECTOR4(1.0f, 1.0f, 0.0f, 1.0f);

	vertices[1].position = D3DXVECTOR3(dee._21, dee._22, dee._23);  // Top middle.
	vertices[1].color = D3DXVECTOR4(1.0f, 1.0f, 0.0f, 1.0f);

	vertices[2].position = D3DXVECTOR3(dee._31, dee._32, dee._33);  // Top middle.
	vertices[2].color = D3DXVECTOR4(1.0f, 1.0f, 0.0f, 1.0f);




	//사각형

	vertices[3].position = D3DXVECTOR3(square._11, square._12, square._13);  // Bottom right.
	vertices[3].color = D3DXVECTOR4(1.0f, 0.0f, 1.0f, 1.0f);


	vertices[4].position = D3DXVECTOR3(square._21, square._22, square._23);  // Bottom left.
	vertices[4].color = D3DXVECTOR4(1.0f, 0.0f, 1.0f, 1.0f);


	vertices[5].position = D3DXVECTOR3(square._31, square._32, square._33);  // Top middle.
	vertices[5].color = D3DXVECTOR4(1.0f, 0.0f, 1.0f, 1.0f);


	vertices[6].position = D3DXVECTOR3(square2._11, square2._12, square2._13);  // Bottom right.
	vertices[6].color = D3DXVECTOR4(1.0f, 0.0f, 1.0f, 1.0f);

	vertices[7].position = D3DXVECTOR3(square2._21, square2._22, square2._23);  // Bottom left.
	vertices[7].color = D3DXVECTOR4(1.0f, 0.0f, 1.0f, 1.0f);


	vertices[8].position = D3DXVECTOR3(square2._31, square2._32, square2._33);  // Top middle.
	vertices[8].color = D3DXVECTOR4(1.0f, 0.0f, 1.0f, 1.0f);




	//육각형

	vertices[9].position = D3DXVECTOR3(hexagon1._11, hexagon1._12, hexagon1._13);  // Bottom right.
	vertices[9].color = D3DXVECTOR4(0.0f, 1.0f, 1.0f, 1.0f);


	vertices[10].position = D3DXVECTOR3(hexagon1._21, hexagon1._22, hexagon1._23);  // Bottom left.
	vertices[10].color = D3DXVECTOR4(0.0f, 1.0f, 1.0f, 1.0f);


	vertices[11].position = D3DXVECTOR3(hexagon1._31, hexagon1._32, hexagon1._33);  // Top middle.
	vertices[11].color = D3DXVECTOR4(0.0f, 1.0f, 1.0f, 1.0f);



	vertices[12].position = D3DXVECTOR3(hexagon2._11, hexagon2._12, hexagon2._13);  // Bottom right.
	vertices[12].color = D3DXVECTOR4(0.0f, 1.0f, 1.0f, 1.0f);


	vertices[13].position = D3DXVECTOR3(hexagon2._21, hexagon2._22, hexagon2._23);  // Bottom left.
	vertices[13].color = D3DXVECTOR4(0.0f, 1.0f, 1.0f, 1.0f);

	vertices[14].position = D3DXVECTOR3(hexagon2._31, hexagon2._32, hexagon2._33);  // Top middle.
	vertices[14].color = D3DXVECTOR4(0.0f, 1.0f, 1.0f, 1.0f);


	vertices[15].position = D3DXVECTOR3(hexagon3._11, hexagon3._12, hexagon3._13);  // Bottom right.
	vertices[15].color = D3DXVECTOR4(0.0f, 1.0f, 1.0f, 1.0f);


	vertices[16].position = D3DXVECTOR3(hexagon3._21, hexagon3._22, hexagon3._23);  // Bottom left.
	vertices[16].color = D3DXVECTOR4(0.0f, 1.0f, 1.0f, 1.0f);


	vertices[17].position = D3DXVECTOR3(hexagon3._31, hexagon3._32, hexagon3._33);  // Top middle.
	vertices[17].color = D3DXVECTOR4(0.0f, 1.0f, 1.0f, 1.0f);


	vertices[18].position = D3DXVECTOR3(hexagon4._11, hexagon4._12, hexagon4._13);  // Bottom right.
	vertices[18].color = D3DXVECTOR4(0.0f, 1.0f, 1.0f, 1.0f);


	vertices[19].position = D3DXVECTOR3(hexagon4._21, hexagon4._22, hexagon4._23);  // Bottom left.
	vertices[19].color = D3DXVECTOR4(0.0f, 1.0f, 1.0f, 1.0f);


	vertices[20].position = D3DXVECTOR3(hexagon4._31, hexagon4._32, hexagon4._33);  // Top middle.
	vertices[20].color = D3DXVECTOR4(0.0f, 1.0f, 1.0f, 1.0f);


	vertices[21].position = D3DXVECTOR3(hexagon5._11, hexagon5._12, hexagon5._13);  // Bottom right.
	vertices[21].color = D3DXVECTOR4(0.0f, 1.0f, 1.0f, 1.0f);


	vertices[22].position = D3DXVECTOR3(hexagon5._21, hexagon5._22, hexagon5._23);  // Bottom left.
	vertices[22].color = D3DXVECTOR4(0.0f, 1.0f, 1.0f, 1.0f);


	vertices[23].position = D3DXVECTOR3(hexagon5._31, hexagon5._32, hexagon5._33);  // Top middle.
	vertices[23].color = D3DXVECTOR4(0.0f, 1.0f, 1.0f, 1.0f);


	vertices[24].position = D3DXVECTOR3(hexagon6._11, hexagon6._12, hexagon6._13);  // Bottom right.
	vertices[24].color = D3DXVECTOR4(0.0f, 1.0f, 1.0f, 1.0f);


	vertices[25].position = D3DXVECTOR3(hexagon6._21, hexagon6._22, hexagon6._23);  // Bottom left.
	vertices[25].color = D3DXVECTOR4(0.0f, 1.0f, 1.0f, 1.0f);


	vertices[26].position = D3DXVECTOR3(hexagon6._31, hexagon6._32, hexagon6._33);  // Top middle.
	vertices[26].color =  D3DXVECTOR4(0.0f, 1.0f, 1.0f, 1.0f);




	for (int i = 0; i < 27; i++) {
		indices[i] = i;
	}
	for (int i = 0 ; i <27; i++) {
		indices[i+27] = 26-i;
	}



	//	D3DXMatrixRotationX(&dee,GetTickCount() * 0.004f);

	// Set up the description of the static vertex buffer.
    vertexBufferDesc.Usage = D3D11_USAGE_DEFAULT;
    vertexBufferDesc.ByteWidth = sizeof(VertexType) * m_vertexCount;
    vertexBufferDesc.BindFlags = D3D11_BIND_VERTEX_BUFFER;
    vertexBufferDesc.CPUAccessFlags = 0;
    vertexBufferDesc.MiscFlags = 0;
	vertexBufferDesc.StructureByteStride = 0;

	// Give the subresource structure a pointer to the vertex data.
    vertexData.pSysMem = vertices;
	vertexData.SysMemPitch = 0;
	vertexData.SysMemSlicePitch = 0;

	// Now create the vertex buffer.
    result = device->CreateBuffer(&vertexBufferDesc, &vertexData, &m_vertexBuffer);
	if(FAILED(result))
	{
		return false;
	}

	// Set up the description of the static index buffer.
    indexBufferDesc.Usage = D3D11_USAGE_DEFAULT;
    indexBufferDesc.ByteWidth = sizeof(unsigned long) * m_indexCount;
    indexBufferDesc.BindFlags = D3D11_BIND_INDEX_BUFFER;
    indexBufferDesc.CPUAccessFlags = 0;
    indexBufferDesc.MiscFlags = 0;
	indexBufferDesc.StructureByteStride = 0;

	// Give the subresource structure a pointer to the index data.
    indexData.pSysMem = indices;
	indexData.SysMemPitch = 0;
	indexData.SysMemSlicePitch = 0;

	// Create the index buffer.
	result = device->CreateBuffer(&indexBufferDesc, &indexData, &m_indexBuffer);
	if(FAILED(result))
	{
		return false;
	}

	// Release the arrays now that the vertex and index buffers have been created and loaded.
	delete [] vertices;
	vertices = 0;

	delete [] indices;
	indices = 0;

	return true;
}


void ModelClass::ShutdownBuffers()
{
	// Release the index buffer.
	if(m_indexBuffer)
	{
		m_indexBuffer->Release();
		m_indexBuffer = 0;
	}

	// Release the vertex buffer.
	if(m_vertexBuffer)
	{
		m_vertexBuffer->Release();
		m_vertexBuffer = 0;
	}

	return;
}

// This sets the vertex buffer and index buffer as active on the input assembler in the GPU. 
// Once the GPU has an active vertex buffer, it can then use the shader to render that buffer. 
// This function also defines how those buffers should be drawn such as triangles, lines, fans, 
// and etc using the IASetPrimitiveTopology DirectX function.
void ModelClass::RenderBuffers(ID3D11DeviceContext* deviceContext)
{
	unsigned int stride;
	unsigned int offset;


	// Set vertex buffer stride and offset.
	stride = sizeof(VertexType); 
	offset = 0;
    
	// Set the vertex buffer to active in the input assembler so it can be rendered.
	deviceContext->IASetVertexBuffers(0, 1, &m_vertexBuffer, &stride, &offset);

    // Set the index buffer to active in the input assembler so it can be rendered.
	deviceContext->IASetIndexBuffer(m_indexBuffer, DXGI_FORMAT_R32_UINT, 0);

    // Set the type of primitive that should be rendered from this vertex buffer, in this case triangles.
	deviceContext->IASetPrimitiveTopology(D3D11_PRIMITIVE_TOPOLOGY_TRIANGLELIST);

	return;
}