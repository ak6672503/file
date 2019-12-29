
// FileView.cpp: CFileView 类的实现
//

#include "pch.h"
#include "framework.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "File.h"
#endif

#include "FileDoc.h"
#include "FileView.h"
#include "resource.h"
#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CFileView

IMPLEMENT_DYNCREATE(CFileView, CView)

BEGIN_MESSAGE_MAP(CFileView, CView)
	// 标准打印命令
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_COMMAND(IDM_FILE_WRITE, &CFileView::OnFileWrite)
	ON_COMMAND(IDM_FILE_READ, &CFileView::OnFileRead)
END_MESSAGE_MAP()

// CFileView 构造/析构

CFileView::CFileView() noexcept
{
	// TODO: 在此处添加构造代码

}

CFileView::~CFileView()
{
}

BOOL CFileView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// CFileView 绘图

void CFileView::OnDraw(CDC* /*pDC*/)
{
	CFileDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 在此处为本机数据添加绘制代码
}


// CFileView 打印

BOOL CFileView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 默认准备
	return DoPreparePrinting(pInfo);
}

void CFileView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加额外的打印前进行的初始化过程
}

void CFileView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加打印后进行的清理过程
}


// CFileView 诊断

#ifdef _DEBUG
void CFileView::AssertValid() const
{
	CView::AssertValid();
}

void CFileView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CFileDoc* CFileView::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CFileDoc)));
	return (CFileDoc*)m_pDocument;
}
#endif //_DEBUG


// CFileView 消息处理程序


void CFileView::OnFileWrite()
{
	FILE* pFile = fopen("1.txt", "w");
	/*
	fwrite("www.baidu.comwww", 1, strlen("www.baiduwww.com"), pFile);
	fseek(pFile, 0, SEEK_SET);
	fwrite("ftp", 1, strlen("ftp"), pFile);
	*/
	//fwrite("欢迎",1, strlen("欢迎"), pFile);

	char buf[14] = "www.baidu.com";
	buf[13] = '\0';
	fwrite(buf, 1, 14, pFile);

	fflush(pFile);
	fclose(pFile);
}


void CFileView::OnFileRead()
{/*
	FILE* pFile = fopen("1.txt", "r");
	char ch[100];
	memset(ch, 0, 100);
	fread(ch, 1, 100, pFile);
	fclose(pFile);
	::MessageBoxA(NULL, ch, "文件", 0);*/

	FILE* pFile = fopen("1.txt", "r");
	char* pBuf;
	fseek(pFile, 0, SEEK_END);
	int len = ftell(pFile);
	pBuf = new char[len + 1];
	rewind(pFile);
	fread(pBuf, 1, len, pFile);
	pBuf[len] = 0;
	fclose(pFile);
	::MessageBoxA(NULL, pBuf, "文件", 0);

}
