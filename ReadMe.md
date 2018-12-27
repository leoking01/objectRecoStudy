<img src="object_ui.png" width = "40%"/>
 




功能介绍：
	目标定位，grabcut调参和多边形逼近调参。
	

<img src="object_ui.png" size="40%" />





================================================================================
    MICROSOFT 基础类库 : objectRecoStudy 项目概述
===============================================================================

应用程序向导已为您创建了此 objectRecoStudy 应用程序。此应用程序不仅演示 Microsoft 基础类的基本使用方法，还可作为您编写应用程序的起点。

本文件概要介绍组成 objectRecoStudy 应用程序的每个文件的内容。

objectRecoStudy.vcxproj
    这是使用应用程序向导生成的 VC++ 项目的主项目文件，其中包含生成该文件的 Visual C++ 的版本信息，以及有关使用应用程序向导选择的平台、配置和项目功能的信息。

objectRecoStudy.vcxproj.filters
    这是使用“应用程序向导”生成的 VC++ 项目筛选器文件。它包含有关项目文件与筛选器之间的关联信息。在 IDE 中，通过这种关联，在特定节点下以分组形式显示具有相似扩展名的文件。例如，“.cpp”文件与“源文件”筛选器关联。

objectRecoStudy.h
    这是应用程序的主头文件。
    其中包括其他项目特定的标头（包括 Resource.h），并声明 CobjectRecoStudyApp 应用程序类。

objectRecoStudy.cpp
    这是包含应用程序类 CobjectRecoStudyApp 的主应用程序源文件。

objectRecoStudy.rc
    这是程序使用的所有 Microsoft Windows 资源的列表。它包括 RES 子目录中存储的图标、位图和光标。此文件可以直接在 Microsoft Visual C++ 中进行编辑。项目资源包含在 2052 中。

res\objectRecoStudy.ico
    这是用作应用程序图标的图标文件。此图标包括在主资源文件 objectRecoStudy.rc 中。

res\objectRecoStudy.rc2
    此文件包含不在 Microsoft Visual C++ 中进行编辑的资源。您应该将不可由资源编辑器编辑的所有资源放在此文件中。


/////////////////////////////////////////////////////////////////////////////

应用程序向导创建一个对话框类：

objectRecoStudyDlg.h、objectRecoStudyDlg.cpp - 对话框
    这些文件包含 CobjectRecoStudyDlg 类。此类定义应用程序的主对话框的行为。对话框模板包含在 objectRecoStudy.rc 中，该文件可以在 Microsoft Visual C++ 中编辑。

/////////////////////////////////////////////////////////////////////////////

其他功能：

ActiveX 控件
    该应用程序包含对使用 ActiveX 控件的支持。

/////////////////////////////////////////////////////////////////////////////

其他标准文件:

StdAfx.h, StdAfx.cpp
    这些文件用于生成名为 objectRecoStudy.pch 的预编译头 (PCH) 文件和名为 StdAfx.obj 的预编译类型文件。

Resource.h
    这是标准头文件，可用于定义新的资源 ID。Microsoft Visual C++ 将读取并更新此文件。

objectRecoStudy.manifest
	Windows XP 使用应用程序清单文件来描述特定版本的并行程序集的应用程序依赖项。加载程序使用这些信息来从程序集缓存中加载相应的程序集，并保护其不被应用程序访问。应用程序清单可能会包含在内，以作为与应用程序可执行文件安装在同一文件夹中的外部 .manifest 文件进行重新分发，它还可能以资源的形式包含在可执行文件中。
/////////////////////////////////////////////////////////////////////////////

其他注释:

应用程序向导使用“TODO:”来指示应添加或自定义的源代码部分。

如果应用程序使用共享 DLL 中的 MFC，您将需要重新分发 MFC DLL。如果应用程序所使用的语言与操作系统的区域设置不同，则还需要重新分发相应的本地化资源 mfc110XXX.DLL。
有关上述话题的更多信息，请参见 MSDN 文档中有关重新分发 Visual C++ 应用程序的部分。

/////////////////////////////////////////////////////////////////////////////

