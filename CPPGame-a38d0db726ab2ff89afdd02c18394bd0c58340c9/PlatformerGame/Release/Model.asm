; Listing generated by Microsoft (R) Optimizing Compiler Version 19.25.28614.0 

	TITLE	d:\platformer\cppgame-a38d0db726ab2ff89afdd02c18394bd0c58340c9\cppgame-a38d0db726ab2ff89afdd02c18394bd0c58340c9\platformergame\src\gameengine\model.cpp
	.686P
	.XMM
	include listing.inc
	.model	flat

INCLUDELIB OLDNAMES

PUBLIC	?renderMode@Model@@0HA				; Model::renderMode
PUBLIC	??_C@_0O@NDFELJM@model?5created@		; `string'
PUBLIC	??_C@_0O@HHAGBHMN@model?5deleted@		; `string'
EXTRN	___glewGenVertexArrays:DWORD
EXTRN	___glewDeleteVertexArrays:DWORD
EXTRN	___glewBindVertexArray:DWORD
;	COMDAT ??_C@_0O@HHAGBHMN@model?5deleted@
CONST	SEGMENT
??_C@_0O@HHAGBHMN@model?5deleted@ DB 'model deleted', 00H ; `string'
CONST	ENDS
;	COMDAT ??_C@_0O@NDFELJM@model?5created@
CONST	SEGMENT
??_C@_0O@NDFELJM@model?5created@ DB 'model created', 00H ; `string'
?renderMode@Model@@0HA DD 04H				; Model::renderMode
PUBLIC	?clear@?$vector@U?$vec@$02M$0A@@glm@@V?$allocator@U?$vec@$02M$0A@@glm@@@std@@@std@@QAEXXZ ; std::vector<glm::vec<3,float,0>,std::allocator<glm::vec<3,float,0> > >::clear
PUBLIC	?clear@?$vector@U?$vec@$01M$0A@@glm@@V?$allocator@U?$vec@$01M$0A@@glm@@@std@@@std@@QAEXXZ ; std::vector<glm::vec<2,float,0>,std::allocator<glm::vec<2,float,0> > >::clear
PUBLIC	?clear@?$vector@U?$vec@$02I$0A@@glm@@V?$allocator@U?$vec@$02I$0A@@glm@@@std@@@std@@QAEXXZ ; std::vector<glm::vec<3,unsigned int,0>,std::allocator<glm::vec<3,unsigned int,0> > >::clear
PUBLIC	??A?$vector@U?$vec@$02I$0A@@glm@@V?$allocator@U?$vec@$02I$0A@@glm@@@std@@@std@@QAEAAU?$vec@$02I$0A@@glm@@I@Z ; std::vector<glm::vec<3,unsigned int,0>,std::allocator<glm::vec<3,unsigned int,0> > >::operator[]
PUBLIC	?enableAtrib@Model@@AAEXXZ			; Model::enableAtrib
PUBLIC	?changeMode@Model@@SAXH@Z			; Model::changeMode
PUBLIC	??0Model@@QAE@V?$vector@U?$vec@$02M$0A@@glm@@V?$allocator@U?$vec@$02M$0A@@glm@@@std@@@std@@V?$vector@U?$vec@$01M$0A@@glm@@V?$allocator@U?$vec@$01M$0A@@glm@@@std@@@2@0V?$vector@U?$vec@$02I$0A@@glm@@V?$allocator@U?$vec@$02I$0A@@glm@@@std@@@2@@Z ; Model::Model
PUBLIC	??1Model@@QAE@XZ				; Model::~Model
PUBLIC	?Draw@Model@@QAEXXZ				; Model::Draw
;	COMDAT xdata$x
xdata$x	SEGMENT
__ehfuncinfo$??1Model@@QAE@XZ DQ 00000000019930522r ; 2.11987e-315
	DQ	00000000000000000r		; 0
	DQ	00000000000000000r		; 0
	DQ	00000000000000000r		; 0
	DD	05H
xdata$x	ENDS
;	COMDAT xdata$x
xdata$x	SEGMENT
__ehfuncinfo$??0Model@@QAE@V?$vector@U?$vec@$02M$0A@@glm@@V?$allocator@U?$vec@$02M$0A@@glm@@@std@@@std@@V?$vector@U?$vec@$01M$0A@@glm@@V?$allocator@U?$vec@$01M$0A@@glm@@@std@@@2@0V?$vector@U?$vec@$02I$0A@@glm@@V?$allocator@U?$vec@$02I$0A@@glm@@@std@@@2@@Z DQ 00000000419930522r ; 8.69997e-314
	DD	FLAT:__unwindtable$??0Model@@QAE@V?$vector@U?$vec@$02M$0A@@glm@@V?$allocator@U?$vec@$02M$0A@@glm@@@std@@@std@@V?$vector@U?$vec@$01M$0A@@glm@@V?$allocator@U?$vec@$01M$0A@@glm@@@std@@@2@0V?$vector@U?$vec@$02I$0A@@glm@@V?$allocator@U?$vec@$02I$0A@@glm@@@std@@@2@@Z
	DQ	00000000000000000r		; 0
	DQ	00000000000000000r		; 0
	DQ	00000000100000000r		; 2.122e-314
__unwindtable$??0Model@@QAE@V?$vector@U?$vec@$02M$0A@@glm@@V?$allocator@U?$vec@$02M$0A@@glm@@@std@@@std@@V?$vector@U?$vec@$01M$0A@@glm@@V?$allocator@U?$vec@$01M$0A@@glm@@@std@@@2@0V?$vector@U?$vec@$02I$0A@@glm@@V?$allocator@U?$vec@$02I$0A@@glm@@@std@@@2@@Z DD 0ffffffffH
	DD	FLAT:__unwindfunclet$??0Model@@QAE@V?$vector@U?$vec@$02M$0A@@glm@@V?$allocator@U?$vec@$02M$0A@@glm@@@std@@@std@@V?$vector@U?$vec@$01M$0A@@glm@@V?$allocator@U?$vec@$01M$0A@@glm@@@std@@@2@0V?$vector@U?$vec@$02I$0A@@glm@@V?$allocator@U?$vec@$02I$0A@@glm@@@std@@@2@@Z$0
	DD	00H
	DD	FLAT:__unwindfunclet$??0Model@@QAE@V?$vector@U?$vec@$02M$0A@@glm@@V?$allocator@U?$vec@$02M$0A@@glm@@@std@@@std@@V?$vector@U?$vec@$01M$0A@@glm@@V?$allocator@U?$vec@$01M$0A@@glm@@@std@@@2@0V?$vector@U?$vec@$02I$0A@@glm@@V?$allocator@U?$vec@$02I$0A@@glm@@@std@@@2@@Z$1
	DD	01H
	DD	FLAT:__unwindfunclet$??0Model@@QAE@V?$vector@U?$vec@$02M$0A@@glm@@V?$allocator@U?$vec@$02M$0A@@glm@@@std@@@std@@V?$vector@U?$vec@$01M$0A@@glm@@V?$allocator@U?$vec@$01M$0A@@glm@@@std@@@2@0V?$vector@U?$vec@$02I$0A@@glm@@V?$allocator@U?$vec@$02I$0A@@glm@@@std@@@2@@Z$2
	DD	02H
	DD	FLAT:__unwindfunclet$??0Model@@QAE@V?$vector@U?$vec@$02M$0A@@glm@@V?$allocator@U?$vec@$02M$0A@@glm@@@std@@@std@@V?$vector@U?$vec@$01M$0A@@glm@@V?$allocator@U?$vec@$01M$0A@@glm@@@std@@@2@0V?$vector@U?$vec@$02I$0A@@glm@@V?$allocator@U?$vec@$02I$0A@@glm@@@std@@@2@@Z$3
END
