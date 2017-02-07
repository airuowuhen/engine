//--------------------------------------------------------------------
// 文件名:		block_chunk.h
// 内  容:		
// 说  明:		
// 创建日期:	2008年6月25日
// 创建人:		陆利民
// 版权所有:	苏州蜗牛电子有限公司
//--------------------------------------------------------------------

#ifndef _BLOCK_CHUNK_H
#define _BLOCK_CHUNK_H

#include "i_block_reader.h"
#include "i_block_writer.h"
#include "height_loader.h"

// 读取分块信息 

class CBlockChunkReader: public IBlockReader
{
public:
	static IBlockReader* NewInstance(CHeightLoader::chunk_all_t* p, 
		size_t chunk_rows, size_t chunk_cols, float left, float top);
	
public:
	CBlockChunkReader(CHeightLoader::chunk_all_t* p, size_t chunk_rows,
		size_t chunk_cols, float left, float top);
	virtual ~CBlockChunkReader();

	// 释放
	virtual void Release();
	// 块尺寸
	virtual int GetSize() const;
	// 读取
	virtual int Read(void* handle);

private:
	CBlockChunkReader();

private:
	CHeightLoader::chunk_all_t* m_pData;
	size_t m_nChunkRows;
	size_t m_nChunkCols;
	float m_fLeft;
	float m_fTop;
};

// 写入分块信息 

class CTerrainZone;

class CBlockChunkWriter: public IBlockWriter
{
public:
	CBlockChunkWriter(CTerrainZone* pZone);
	virtual ~CBlockChunkWriter();

	// 块尺寸
	virtual int GetSize() const;
	// 读取
	virtual int Write(void* handle);
	
private:
	CBlockChunkWriter();
	
private:
	CTerrainZone* m_pZone;
};

// 直接写入分块信息 

class CTerrainZone;

class CBlockChunkWriter2: public IBlockWriter
{
public:
	CBlockChunkWriter2(CHeightLoader::chunk_all_t* p, size_t chunk_rows,
		size_t chunk_cols, float left, float top);
	virtual ~CBlockChunkWriter2();

	// 块尺寸
	virtual int GetSize() const;
	// 读取
	virtual int Write(void* handle);

private:
	CBlockChunkWriter2();

private:
	CHeightLoader::chunk_all_t* m_pData;
	size_t m_nChunkRows;
	size_t m_nChunkCols;
	float m_fLeft;
	float m_fTop;
};

#endif // _BLOCK_CHUNK_H
