; Listing generated by Microsoft (R) Optimizing Compiler Version 19.25.28614.0 

	TITLE	d:\platformer\cppgame-a38d0db726ab2ff89afdd02c18394bd0c58340c9\cppgame-a38d0db726ab2ff89afdd02c18394bd0c58340c9\platformergame\src\gameengine\camera.cpp
	.686P
	.XMM
	include listing.inc
	.model	flat

INCLUDELIB OLDNAMES

PUBLIC	??_C@_1BHO@KLILKPCO@?$AAD?$AA?3?$AA?2?$AAP?$AAl?$AAa?$AAt?$AAf?$AAo?$AAr?$AAm?$AAe?$AAr?$AA?2?$AAC@ ; `string'
PUBLIC	??_C@_1II@JJEBDBC@?$AAa?$AAb?$AAs?$AA?$CI?$AAa?$AAs?$AAp?$AAe?$AAc?$AAt?$AA?5?$AA?9?$AA?5?$AAs?$AAt@ ; `string'
PUBLIC	??_C@_1BHE@LCIIOJGD@?$AAD?$AA?3?$AA?2?$AAP?$AAl?$AAa?$AAt?$AAf?$AAo?$AAr?$AAm?$AAe?$AAr?$AA?2?$AAC@ ; `string'
PUBLIC	??_C@_1DK@BGNCJAPL@?$AAi?$AA?5?$AA?$DO?$AA?$DN?$AA?5?$AA0?$AA?5?$AA?$CG?$AA?$CG?$AA?5?$AAi?$AA?5?$AA?$DM?$AA?5?$AAt@ ; `string'
PUBLIC	??_C@_1BHI@BJHAPLJJ@?$AAD?$AA?3?$AA?2?$AAP?$AAl?$AAa?$AAt?$AAf?$AAo?$AAr?$AAm?$AAe?$AAr?$AA?2?$AAC@ ; `string'
PUBLIC	??_C@_1CG@KOFHLCJL@?$AAi?$AA?5?$AA?$DM?$AA?5?$AAt?$AAh?$AAi?$AAs?$AA?9?$AA?$DO?$AAl?$AAe?$AAn?$AAg?$AAt@ ; `string'
EXTRN	__imp___wassert:PROC
EXTRN	__imp____std_terminate:PROC
;	COMDAT ??_C@_1CG@KOFHLCJL@?$AAi?$AA?5?$AA?$DM?$AA?5?$AAt?$AAh?$AAi?$AAs?$AA?9?$AA?$DO?$AAl?$AAe?$AAn?$AAg?$AAt@
CONST	SEGMENT
??_C@_1CG@KOFHLCJL@?$AAi?$AA?5?$AA?$DM?$AA?5?$AAt?$AAh?$AAi?$AAs?$AA?9?$AA?$DO?$AAl?$AAe?$AAn?$AAg?$AAt@ DB 'i'
	DB	00H, ' ', 00H, '<', 00H, ' ', 00H, 't', 00H, 'h', 00H, 'i', 00H
	DB	's', 00H, '-', 00H, '>', 00H, 'l', 00H, 'e', 00H, 'n', 00H, 'g'
	DB	00H, 't', 00H, 'h', 00H, '(', 00H, ')', 00H, 00H, 00H ; `string'
CONST	ENDS
;	COMDAT ??_C@_1BHI@BJHAPLJJ@?$AAD?$AA?3?$AA?2?$AAP?$AAl?$AAa?$AAt?$AAf?$AAo?$AAr?$AAm?$AAe?$AAr?$AA?2?$AAC@
CONST	SEGMENT
??_C@_1BHI@BJHAPLJJ@?$AAD?$AA?3?$AA?2?$AAP?$AAl?$AAa?$AAt?$AAf?$AAo?$AAr?$AAm?$AAe?$AAr?$AA?2?$AAC@ DB 'D'
	DB	00H, ':', 00H, '\', 00H, 'P', 00H, 'l', 00H, 'a', 00H, 't', 00H
	DB	'f', 00H, 'o', 00H, 'r', 00H, 'm', 00H, 'e', 00H, 'r', 00H, '\'
	DB	00H, 'C', 00H, 'P', 00H, 'P', 00H, 'G', 00H, 'a', 00H, 'm', 00H
	DB	'e', 00H, '-', 00H, 'a', 00H, '3', 00H, '8', 00H, 'd', 00H, '0'
	DB	00H, 'd', 00H, 'b', 00H, '7', 00H, '2', 00H, '6', 00H, 'a', 00H
	DB	'b', 00H, '2', 00H, 'f', 00H, 'f', 00H, '8', 00H, '9', 00H, 'a'
	DB	00H, 'f', 00H, 'd', 00H, 'd', 00H, '0', 00H, '2', 00H, 'c', 00H
	DB	'1', 00H, '8', 00H, '3', 00H, '9', 00H, '4', 00H, 'b', 00H, 'd'
	DB	00H, '0', 00H, 'c', 00H, '5', 00H, '8', 00H, '3', 00H, '4', 00H
	DB	'0', 00H, 'c', 00H, '9', 00H, '\', 00H, 'C', 00H, 'P', 00H, 'P'
	DB	00H, 'G', 00H, 'a', 00H, 'm', 00H, 'e', 00H, '-', 00H, 'a', 00H
	DB	'3', 00H, '8', 00H, 'd', 00H, '0', 00H, 'd', 00H, 'b', 00H, '7'
	DB	00H, '2', 00H, '6', 00H, 'a', 00H, 'b', 00H, '2', 00H, 'f', 00H
	DB	'f', 00H, '8', 00H, '9', 00H, 'a', 00H, 'f', 00H, 'd', 00H, 'd'
	DB	00H, '0', 00H, '2', 00H, 'c', 00H, '1', 00H, '8', 00H, '3', 00H
	DB	'9', 00H, '4', 00H, 'b', 00H, 'd', 00H, '0', 00H, 'c', 00H, '5'
	DB	00H, '8', 00H, '3', 00H, '4', 00H, '0', 00H, 'c', 00H, '9', 00H
	DB	'\', 00H, 'P', 00H, 'l', 00H, 'a', 00H, 't', 00H, 'f', 00H, 'o'
	DB	00H, 'r', 00H, 'm', 00H, 'e', 00H, 'r', 00H, 'G', 00H, 'a', 00H
	DB	'm', 00H, 'e', 00H, '\', 00H, 's', 00H, 'r', 00H, 'c', 00H, '\'
	DB	00H, 'G', 00H, 'a', 00H, 'm', 00H, 'e', 00H, 'E', 00H, 'n', 00H
	DB	'g', 00H, 'i', 00H, 'n', 00H, 'e', 00H, '\', 00H, 'H', 00H, 'e'
	DB	00H, 'a', 00H, 'd', 00H, 'e', 00H, 'r', 00H, 'F', 00H, 'i', 00H
	DB	'l', 00H, 'e', 00H, 's', 00H, '\', 00H, 'V', 00H, 'e', 00H, 'n'
	DB	00H, 'd', 00H, 'o', 00H, 'r', 00H, '\', 00H, 'g', 00H, 'l', 00H
	DB	'm', 00H, '\', 00H, 'd', 00H, 'e', 00H, 't', 00H, 'a', 00H, 'i'
	DB	00H, 'l', 00H, '\', 00H, 't', 00H, 'y', 00H, 'p', 00H, 'e', 00H
	DB	'_', 00H, 'm', 00H, 'a', 00H, 't', 00H, '4', 00H, 'x', 00H, '4'
	DB	00H, '.', 00H, 'i', 00H, 'n', 00H, 'l', 00H, 00H, 00H ; `string'
CONST	ENDS
;	COMDAT ??_C@_1DK@BGNCJAPL@?$AAi?$AA?5?$AA?$DO?$AA?$DN?$AA?5?$AA0?$AA?5?$AA?$CG?$AA?$CG?$AA?5?$AAi?$AA?5?$AA?$DM?$AA?5?$AAt@
CONST	SEGMENT
??_C@_1DK@BGNCJAPL@?$AAi?$AA?5?$AA?$DO?$AA?$DN?$AA?5?$AA0?$AA?5?$AA?$CG?$AA?$CG?$AA?5?$AAi?$AA?5?$AA?$DM?$AA?5?$AAt@ DB 'i'
	DB	00H, ' ', 00H, '>', 00H, '=', 00H, ' ', 00H, '0', 00H, ' ', 00H
	DB	'&', 00H, '&', 00H, ' ', 00H, 'i', 00H, ' ', 00H, '<', 00H, ' '
	DB	00H, 't', 00H, 'h', 00H, 'i', 00H, 's', 00H, '-', 00H, '>', 00H
	DB	'l', 00H, 'e', 00H, 'n', 00H, 'g', 00H, 't', 00H, 'h', 00H, '('
	DB	00H, ')', 00H, 00H, 00H			; `string'
CONST	ENDS
;	COMDAT ??_C@_1BHE@LCIIOJGD@?$AAD?$AA?3?$AA?2?$AAP?$AAl?$AAa?$AAt?$AAf?$AAo?$AAr?$AAm?$AAe?$AAr?$AA?2?$AAC@
CONST	SEGMENT
??_C@_1BHE@LCIIOJGD@?$AAD?$AA?3?$AA?2?$AAP?$AAl?$AAa?$AAt?$AAf?$AAo?$AAr?$AAm?$AAe?$AAr?$AA?2?$AAC@ DB 'D'
	DB	00H, ':', 00H, '\', 00H, 'P', 00H, 'l', 00H, 'a', 00H, 't', 00H
	DB	'f', 00H, 'o', 00H, 'r', 00H, 'm', 00H, 'e', 00H, 'r', 00H, '\'
	DB	00H, 'C', 00H, 'P', 00H, 'P', 00H, 'G', 00H, 'a', 00H, 'm', 00H
	DB	'e', 00H, '-', 00H, 'a', 00H, '3', 00H, '8', 00H, 'd', 00H, '0'
	DB	00H, 'd', 00H, 'b', 00H, '7', 00H, '2', 00H, '6', 00H, 'a', 00H
	DB	'b', 00H, '2', 00H, 'f', 00H, 'f', 00H, '8', 00H, '9', 00H, 'a'
	DB	00H, 'f', 00H, 'd', 00H, 'd', 00H, '0', 00H, '2', 00H, 'c', 00H
	DB	'1', 00H, '8', 00H, '3', 00H, '9', 00H, '4', 00H, 'b', 00H, 'd'
	DB	00H, '0', 00H, 'c', 00H, '5', 00H, '8', 00H, '3', 00H, '4', 00H
	DB	'0', 00H, 'c', 00H, '9', 00H, '\', 00H, 'C', 00H, 'P', 00H, 'P'
	DB	00H, 'G', 00H, 'a', 00H, 'm', 00H, 'e', 00H, '-', 00H, 'a', 00H
	DB	'3', 00H, '8', 00H, 'd', 00H, '0', 00H, 'd', 00H, 'b', 00H, '7'
	DB	00H, '2', 00H, '6', 00H, 'a', 00H, 'b', 00H, '2', 00H, 'f', 00H
	DB	'f', 00H, '8', 00H, '9', 00H, 'a', 00H, 'f', 00H, 'd', 00H, 'd'
	DB	00H, '0', 00H, '2', 00H, 'c', 00H, '1', 00H, '8', 00H, '3', 00H
	DB	'9', 00H, '4', 00H, 'b', 00H, 'd', 00H, '0', 00H, 'c', 00H, '5'
	DB	00H, '8', 00H, '3', 00H, '4', 00H, '0', 00H, 'c', 00H, '9', 00H
	DB	'\', 00H, 'P', 00H, 'l', 00H, 'a', 00H, 't', 00H, 'f', 00H, 'o'
	DB	00H, 'r', 00H, 'm', 00H, 'e', 00H, 'r', 00H, 'G', 00H, 'a', 00H
	DB	'm', 00H, 'e', 00H, '\', 00H, 's', 00H, 'r', 00H, 'c', 00H, '\'
	DB	00H, 'G', 00H, 'a', 00H, 'm', 00H, 'e', 00H, 'E', 00H, 'n', 00H
	DB	'g', 00H, 'i', 00H, 'n', 00H, 'e', 00H, '\', 00H, 'H', 00H, 'e'
	DB	00H, 'a', 00H, 'd', 00H, 'e', 00H, 'r', 00H, 'F', 00H, 'i', 00H
	DB	'l', 00H, 'e', 00H, 's', 00H, '\', 00H, 'V', 00H, 'e', 00H, 'n'
	DB	00H, 'd', 00H, 'o', 00H, 'r', 00H, '\', 00H, 'g', 00H, 'l', 00H
	DB	'm', 00H, '\', 00H, 'd', 00H, 'e', 00H, 't', 00H, 'a', 00H, 'i'
	DB	00H, 'l', 00H, '\', 00H, 't', 00H, 'y', 00H, 'p', 00H, 'e', 00H
	DB	'_', 00H, 'v', 00H, 'e', 00H, 'c', 00H, '4', 00H, '.', 00H, 'i'
	DB	00H, 'n', 00H, 'l', 00H, 00H, 00H		; `string'
CONST	ENDS
;	COMDAT ??_C@_1II@JJEBDBC@?$AAa?$AAb?$AAs?$AA?$CI?$AAa?$AAs?$AAp?$AAe?$AAc?$AAt?$AA?5?$AA?9?$AA?5?$AAs?$AAt@
CONST	SEGMENT
??_C@_1II@JJEBDBC@?$AAa?$AAb?$AAs?$AA?$CI?$AAa?$AAs?$AAp?$AAe?$AAc?$AAt?$AA?5?$AA?9?$AA?5?$AAs?$AAt@ DB 'a'
	DB	00H, 'b', 00H, 's', 00H, '(', 00H, 'a', 00H, 's', 00H, 'p', 00H
	DB	'e', 00H, 'c', 00H, 't', 00H, ' ', 00H, '-', 00H, ' ', 00H, 's'
	DB	00H, 't', 00H, 'd', 00H, ':', 00H, ':', 00H, 'n', 00H, 'u', 00H
	DB	'm', 00H, 'e', 00H, 'r', 00H, 'i', 00H, 'c', 00H, '_', 00H, 'l'
	DB	00H, 'i', 00H, 'm', 00H, 'i', 00H, 't', 00H, 's', 00H, '<', 00H
	DB	'T', 00H, '>', 00H, ':', 00H, ':', 00H, 'e', 00H, 'p', 00H, 's'
	DB	00H, 'i', 00H, 'l', 00H, 'o', 00H, 'n', 00H, '(', 00H, ')', 00H
	DB	')', 00H, ' ', 00H, '>', 00H, ' ', 00H, 's', 00H, 't', 00H, 'a'
	DB	00H, 't', 00H, 'i', 00H, 'c', 00H, '_', 00H, 'c', 00H, 'a', 00H
	DB	's', 00H, 't', 00H, '<', 00H, 'T', 00H, '>', 00H, '(', 00H, '0'
	DB	00H, ')', 00H, 00H, 00H			; `string'
CONST	ENDS
;	COMDAT ??_C@_1BHO@KLILKPCO@?$AAD?$AA?3?$AA?2?$AAP?$AAl?$AAa?$AAt?$AAf?$AAo?$AAr?$AAm?$AAe?$AAr?$AA?2?$AAC@
CONST	SEGMENT
??_C@_1BHO@KLILKPCO@?$AAD?$AA?3?$AA?2?$AAP?$AAl?$AAa?$AAt?$AAf?$AAo?$AAr?$AAm?$AAe?$AAr?$AA?2?$AAC@ DB 'D'
	DB	00H, ':', 00H, '\', 00H, 'P', 00H, 'l', 00H, 'a', 00H, 't', 00H
	DB	'f', 00H, 'o', 00H, 'r', 00H, 'm', 00H, 'e', 00H, 'r', 00H, '\'
	DB	00H, 'C', 00H, 'P', 00H, 'P', 00H, 'G', 00H, 'a', 00H, 'm', 00H
	DB	'e', 00H, '-', 00H, 'a', 00H, '3', 00H, '8', 00H, 'd', 00H, '0'
	DB	00H, 'd', 00H, 'b', 00H, '7', 00H, '2', 00H, '6', 00H, 'a', 00H
	DB	'b', 00H, '2', 00H, 'f', 00H, 'f', 00H, '8', 00H, '9', 00H, 'a'
	DB	00H, 'f', 00H, 'd', 00H, 'd', 00H, '0', 00H, '2', 00H, 'c', 00H
	DB	'1', 00H, '8', 00H, '3', 00H, '9', 00H, '4', 00H, 'b', 00H, 'd'
	DB	00H, '0', 00H, 'c', 00H, '5', 00H, '8', 00H, '3', 00H, '4', 00H
	DB	'0', 00H, 'c', 00H, '9', 00H, '\', 00H, 'C', 00H, 'P', 00H, 'P'
	DB	00H, 'G', 00H, 'a', 00H, 'm', 00H, 'e', 00H, '-', 00H, 'a', 00H
	DB	'3', 00H, '8', 00H, 'd', 00H, '0', 00H, 'd', 00H, 'b', 00H, '7'
	DB	00H, '2', 00H, '6', 00H, 'a', 00H, 'b', 00H, '2', 00H, 'f', 00H
	DB	'f', 00H, '8', 00H, '9', 00H, 'a', 00H, 'f', 00H, 'd', 00H, 'd'
	DB	00H, '0', 00H, '2', 00H, 'c', 00H, '1', 00H, '8', 00H, '3', 00H
	DB	'9', 00H, '4', 00H, 'b', 00H, 'd', 00H, '0', 00H, 'c', 00H, '5'
	DB	00H, '8', 00H, '3', 00H, '4', 00H, '0', 00H, 'c', 00H, '9', 00H
	DB	'\', 00H, 'P', 00H, 'l', 00H, 'a', 00H, 't', 00H, 'f', 00H, 'o'
	DB	00H, 'r', 00H, 'm', 00H, 'e', 00H, 'r', 00H, 'G', 00H, 'a', 00H
	DB	'm', 00H, 'e', 00H, '\', 00H, 's', 00H, 'r', 00H, 'c', 00H, '\'
	DB	00H, 'G', 00H, 'a', 00H, 'm', 00H, 'e', 00H, 'E', 00H, 'n', 00H
	DB	'g', 00H, 'i', 00H, 'n', 00H, 'e', 00H, '\', 00H, 'H', 00H, 'e'
	DB	00H, 'a', 00H, 'd', 00H, 'e', 00H, 'r', 00H, 'F', 00H, 'i', 00H
	DB	'l', 00H, 'e', 00H, 's', 00H, '\', 00H, 'V', 00H, 'e', 00H, 'n'
	DB	00H, 'd', 00H, 'o', 00H, 'r', 00H, '\', 00H, 'g', 00H, 'l', 00H
	DB	'm', 00H, '\', 00H, 'e', 00H, 'x', 00H, 't', 00H, '\', 00H, 'm'
	DB	00H, 'a', 00H, 't', 00H, 'r', 00H, 'i', 00H, 'x', 00H, '_', 00H
	DB	'c', 00H, 'l', 00H, 'i', 00H, 'p', 00H, '_', 00H, 's', 00H, 'p'
	DB	00H, 'a', 00H, 'c', 00H, 'e', 00H, '.', 00H, 'i', 00H, 'n', 00H
	DB	'l', 00H, 00H, 00H				; `string'
CONST	ENDS
PUBLIC	??$?0HHHM@?$vec@$03M$0A@@glm@@QAE@HHHM@Z	; glm::vec<4,float,0>::vec<4,float,0><int,int,int,float>
PUBLIC	??$?0HHMH@?$vec@$03M$0A@@glm@@QAE@HHMH@Z	; glm::vec<4,float,0>::vec<4,float,0><int,int,float,int>
PUBLIC	??$?0HMHH@?$vec@$03M$0A@@glm@@QAE@HMHH@Z	; glm::vec<4,float,0>::vec<4,float,0><int,float,int,int>
PUBLIC	??$?0MHHH@?$vec@$03M$0A@@glm@@QAE@MHHH@Z	; glm::vec<4,float,0>::vec<4,float,0><float,int,int,int>
PUBLIC	?length@?$vec@$03M$0A@@glm@@SAHXZ		; glm::vec<4,float,0>::length
PUBLIC	?length@?$mat@$03$03M$0A@@glm@@SAHXZ		; glm::mat<4,4,float,0>::length
PUBLIC	?call@?$compute_abs@M$00@detail@glm@@SAMM@Z	; glm::detail::compute_abs<float,1>::call
PUBLIC	??$abs@M@glm@@YAMM@Z				; glm::abs<float>
PUBLIC	??0?$mat@$03$03M$0A@@glm@@QAE@ABM@Z		; glm::mat<4,4,float,0>::mat<4,4,float,0>
PUBLIC	??A?$mat@$03$03M$0A@@glm@@QAEAAU?$vec@$03M$0A@@1@H@Z ; glm::mat<4,4,float,0>::operator[]
PUBLIC	??A?$vec@$03M$0A@@glm@@QAEAAMH@Z		; glm::vec<4,float,0>::operator[]
PUBLIC	??$perspectiveRH_NO@M@glm@@YA?AU?$mat@$03$03M$0A@@0@MMMM@Z ; glm::perspectiveRH_NO<float>
PUBLIC	??$perspectiveRH_ZO@M@glm@@YA?AU?$mat@$03$03M$0A@@0@MMMM@Z ; glm::perspectiveRH_ZO<float>
PUBLIC	??$perspectiveLH_NO@M@glm@@YA?AU?$mat@$03$03M$0A@@0@MMMM@Z ; glm::perspectiveLH_NO<float>
PUBLIC	??$perspectiveLH_ZO@M@glm@@YA?AU?$mat@$03$03M$0A@@0@MMMM@Z ; glm::perspectiveLH_ZO<float>
PUBLIC	??$perspective@M@glm@@YA?AU?$mat@$03$03M$0A@@0@MMMM@Z ; glm::perspective<float>
PUBLIC	??$radians@M@glm@@YAMM@Z			; glm::radians<float>
PUBLIC	??0?$vec@$02M$0A@@glm@@QAE@M@Z			; glm::vec<3,float,0>::vec<3,float,0>
PUBLIC	?getView@Camera@@QAE?AU?$mat@$03$03M$0A@@glm@@XZ ; Camera::getView
PUBLIC	?getProjection@Camera@@QAE?AU?$mat@$03$03M$0A@@glm@@XZ ; Camera::getProjection
PUBLIC	?setPosition@Camera@@QAEXU?$vec@$02M$0A@@glm@@@Z ; Camera::setPosition
PUBLIC	?setSize@Camera@@QAEXMM@Z			; Camera::setSize
PUBLIC	??0Camera@@QAE@MMMU?$vec@$02M$0A@@glm@@@Z	; Camera::Camera
PUBLIC	?tan@@YAMM@Z					; tan
PUBLIC	?epsilon@?$numeric_limits@M@std@@SAMXZ		; std::numeric_limits<float>::epsilon
PUBLIC	_tanf
EXTRN	___std_terminate:PROC
END
