; Listing generated by Microsoft (R) Optimizing Compiler Version 19.25.28614.0 

	TITLE	d:\platformer\cppgame-a38d0db726ab2ff89afdd02c18394bd0c58340c9\cppgame-a38d0db726ab2ff89afdd02c18394bd0c58340c9\platformergame\src\gameengine\entity.cpp
	.686P
	.XMM
	include listing.inc
	.model	flat

INCLUDELIB OLDNAMES

EXTRN	@__security_check_cookie@4:PROC
EXTRN	__imp____CxxFrameHandler3:PROC
PUBLIC	?getTRS@Entity@@QAE?AU?$mat@$03$03M$0A@@glm@@XZ	; Entity::getTRS
PUBLIC	?getReflect@Entity@@QAEMXZ			; Entity::getReflect
PUBLIC	?getDamping@Entity@@QAEMXZ			; Entity::getDamping
PUBLIC	?setscale@Entity@@QAEXM@Z			; Entity::setscale
PUBLIC	?setRotation@Entity@@QAEXU?$vec@$02M$0A@@glm@@@Z ; Entity::setRotation
PUBLIC	?setPosition@Entity@@QAEXU?$vec@$02M$0A@@glm@@@Z ; Entity::setPosition
PUBLIC	?Draw@Entity@@QAEXXZ				; Entity::Draw
PUBLIC	??0Entity@@QAE@AAVModel@@U?$vec@$02M$0A@@glm@@1MMM@Z ; Entity::Entity
PUBLIC	___isa_available_default
PUBLIC	__real@34000000
PUBLIC	__real@3b800000
PUBLIC	__real@3c8efa35
PUBLIC	__real@3dcccccd
PUBLIC	__real@3f000000
PUBLIC	__real@3f490fdb
PUBLIC	__real@3f800000
PUBLIC	__real@3f91111111111111
PUBLIC	__real@3f91df46a2529e84
PUBLIC	__real@3fdd1745c0000000
PUBLIC	__real@3ff0000000000000
PUBLIC	__real@40200000
PUBLIC	__real@40400000
PUBLIC	__real@40800000
PUBLIC	__real@41200000
PUBLIC	__real@41cdcd6500000000
PUBLIC	__real@41f00000
PUBLIC	__real@42480000
PUBLIC	__real@428c0000
PUBLIC	__real@42c80000
PUBLIC	__real@437f0000
PUBLIC	__real@43f00000
PUBLIC	__real@44200000
PUBLIC	__real@44480000
PUBLIC	__real@477fff00
PUBLIC	__real@bc8efa35
PUBLIC	__real@bf800000
PUBLIC	__real@c2480000
PUBLIC	__xmm@00000000000000040000000000000000
PUBLIC	__xmm@00000002000000000000000400000000
PUBLIC	__xmm@00000002000000020000000200000002
PUBLIC	__xmm@00000003000000030000000300000003
PUBLIC	__xmm@00000004000000040000000800000008
PUBLIC	__xmm@00000004000000080000000800000008
PUBLIC	__xmm@00000200000002000000020000000200
PUBLIC	__xmm@00080008000800080008000800080008
PUBLIC	__xmm@00ff00ff00ff00ff00ff00ff00ff00ff
PUBLIC	__xmm@01010000010100000101000001010000
PUBLIC	__xmm@08a914e808a914e808a914e808a914e8
PUBLIC	__xmm@11c8e09e11c8e09e11c8e09e11c8e09e
PUBLIC	__xmm@11c8f9c311c8f9c311c8f9c311c8f9c3
PUBLIC	__xmm@12d0046b12d0046b12d0046b12d0046b
PUBLIC	__xmm@166f166f166f166f166f166f166f166f
PUBLIC	__xmm@1c5a1c5a1c5a1c5a1c5a1c5a1c5a1c5a
PUBLIC	__xmm@41f00000000000000000000000000000
PUBLIC	__xmm@7fffffff7fffffff7fffffff7fffffff
PUBLIC	__xmm@80000000800000008000000080000000
PUBLIC	__xmm@80808080808080808080808080808080
PUBLIC	__xmm@e09ee565e09ee565e09ee565e09ee565
PUBLIC	__xmm@e9cf12d0e9cf12d0e9cf12d0e9cf12d0
PUBLIC	__xmm@eb1a08a9eb1a08a9eb1a08a9eb1a08a9
PUBLIC	__xmm@f493f493f493f493f493f493f493f493
PUBLIC	__xmm@f9c31a9df9c31a9df9c31a9df9c31a9d
PUBLIC	__xmm@fa7efa7efa7efa7efa7efa7efa7efa7e
EXTRN	__CIfmod:PROC
EXTRN	__CxxThrowException@8:PROC
EXTRN	___CxxFrameHandler3:PROC
EXTRN	__alldiv:PROC
EXTRN	__alldvrm:PROC
EXTRN	__allmul:PROC
EXTRN	__chkstk:PROC
EXTRN	__ftoui3:PROC
EXTRN	__libm_sse2_cos_precise:PROC
EXTRN	__libm_sse2_pow_precise:PROC
EXTRN	__libm_sse2_sin_precise:PROC
EXTRN	__libm_sse2_sqrt_precise:PROC
EXTRN	__libm_sse2_tan_precise:PROC
EXTRN	__ltod3:PROC
EXTRN	_ceil:PROC
EXTRN	_floor:PROC
EXTRN	_memchr:PROC
EXTRN	_memcpy:PROC
EXTRN	_memmove:PROC
EXTRN	_memset:PROC
EXTRN	___isa_available:DWORD
EXTRN	___security_cookie:DWORD
EXTRN	__fltused:DWORD
;	COMDAT ___isa_available_default
_BSS	SEGMENT
___isa_available_default DD 01H DUP (?)
_BSS	ENDS
;	COMDAT __xmm@fa7efa7efa7efa7efa7efa7efa7efa7e
CONST	SEGMENT
__xmm@fa7efa7efa7efa7efa7efa7efa7efa7e DB '~', 0faH, '~', 0faH, '~', 0faH
	DB	'~', 0faH, '~', 0faH, '~', 0faH, '~', 0faH, '~', 0faH
CONST	ENDS
;	COMDAT __xmm@f9c31a9df9c31a9df9c31a9df9c31a9d
CONST	SEGMENT
__xmm@f9c31a9df9c31a9df9c31a9df9c31a9d DB 09dH, 01aH, 0c3H, 0f9H, 09dH, 01aH
	DB	0c3H, 0f9H, 09dH, 01aH, 0c3H, 0f9H, 09dH, 01aH, 0c3H, 0f9H
CONST	ENDS
;	COMDAT __xmm@f493f493f493f493f493f493f493f493
CONST	SEGMENT
__xmm@f493f493f493f493f493f493f493f493 DB 093H, 0f4H, 093H, 0f4H, 093H, 0f4H
	DB	093H, 0f4H, 093H, 0f4H, 093H, 0f4H, 093H, 0f4H, 093H, 0f4H
CONST	ENDS
;	COMDAT __xmm@eb1a08a9eb1a08a9eb1a08a9eb1a08a9
CONST	SEGMENT
__xmm@eb1a08a9eb1a08a9eb1a08a9eb1a08a9 DB 0a9H, 08H, 01aH, 0ebH, 0a9H, 08H
	DB	01aH, 0ebH, 0a9H, 08H, 01aH, 0ebH, 0a9H, 08H, 01aH, 0ebH
CONST	ENDS
;	COMDAT __xmm@e9cf12d0e9cf12d0e9cf12d0e9cf12d0
CONST	SEGMENT
__xmm@e9cf12d0e9cf12d0e9cf12d0e9cf12d0 DB 0d0H, 012H, 0cfH, 0e9H, 0d0H, 012H
	DB	0cfH, 0e9H, 0d0H, 012H, 0cfH, 0e9H, 0d0H, 012H, 0cfH, 0e9H
CONST	ENDS
;	COMDAT __xmm@e09ee565e09ee565e09ee565e09ee565
CONST	SEGMENT
__xmm@e09ee565e09ee565e09ee565e09ee565 DB 'e', 0e5H, 09eH, 0e0H, 'e', 0e5H
	DB	09eH, 0e0H, 'e', 0e5H, 09eH, 0e0H, 'e', 0e5H, 09eH, 0e0H
CONST	ENDS
;	COMDAT __xmm@80808080808080808080808080808080
CONST	SEGMENT
__xmm@80808080808080808080808080808080 DB 080H, 080H, 080H, 080H, 080H, 080H
	DB	080H, 080H, 080H, 080H, 080H, 080H, 080H, 080H, 080H, 080H
CONST	ENDS
;	COMDAT __xmm@80000000800000008000000080000000
CONST	SEGMENT
__xmm@80000000800000008000000080000000 DB 00H, 00H, 00H, 080H, 00H, 00H, 00H
	DB	080H, 00H, 00H, 00H, 080H, 00H, 00H, 00H, 080H
CONST	ENDS
;	COMDAT __xmm@7fffffff7fffffff7fffffff7fffffff
CONST	SEGMENT
__xmm@7fffffff7fffffff7fffffff7fffffff DB 0ffH, 0ffH, 0ffH, 07fH, 0ffH, 0ffH
	DB	0ffH, 07fH, 0ffH, 0ffH, 0ffH, 07fH, 0ffH, 0ffH, 0ffH, 07fH
CONST	ENDS
;	COMDAT __xmm@41f00000000000000000000000000000
CONST	SEGMENT
__xmm@41f00000000000000000000000000000 DB 00H, 00H, 00H, 00H, 00H, 00H, 00H
	DB	00H, 00H, 00H, 00H, 00H, 00H, 00H, 0f0H, 'A'
CONST	ENDS
;	COMDAT __xmm@1c5a1c5a1c5a1c5a1c5a1c5a1c5a1c5a
CONST	SEGMENT
__xmm@1c5a1c5a1c5a1c5a1c5a1c5a1c5a1c5a DB 'Z', 01cH, 'Z', 01cH, 'Z', 01cH
	DB	'Z', 01cH, 'Z', 01cH, 'Z', 01cH, 'Z', 01cH, 'Z', 01cH
CONST	ENDS
;	COMDAT __xmm@166f166f166f166f166f166f166f166f
CONST	SEGMENT
__xmm@166f166f166f166f166f166f166f166f DB 'o', 016H, 'o', 016H, 'o', 016H
	DB	'o', 016H, 'o', 016H, 'o', 016H, 'o', 016H, 'o', 016H
CONST	ENDS
;	COMDAT __xmm@12d0046b12d0046b12d0046b12d0046b
CONST	SEGMENT
__xmm@12d0046b12d0046b12d0046b12d0046b DB 'k', 04H, 0d0H, 012H, 'k', 04H, 0d0H
	DB	012H, 'k', 04H, 0d0H, 012H, 'k', 04H, 0d0H, 012H
CONST	ENDS
;	COMDAT __xmm@11c8f9c311c8f9c311c8f9c311c8f9c3
CONST	SEGMENT
__xmm@11c8f9c311c8f9c311c8f9c311c8f9c3 DB 0c3H, 0f9H, 0c8H, 011H, 0c3H, 0f9H
	DB	0c8H, 011H, 0c3H, 0f9H, 0c8H, 011H, 0c3H, 0f9H, 0c8H, 011H
CONST	ENDS
;	COMDAT __xmm@11c8e09e11c8e09e11c8e09e11c8e09e
CONST	SEGMENT
__xmm@11c8e09e11c8e09e11c8e09e11c8e09e DB 09eH, 0e0H, 0c8H, 011H, 09eH, 0e0H
	DB	0c8H, 011H, 09eH, 0e0H, 0c8H, 011H, 09eH, 0e0H, 0c8H, 011H
CONST	ENDS
;	COMDAT __xmm@08a914e808a914e808a914e808a914e8
CONST	SEGMENT
__xmm@08a914e808a914e808a914e808a914e8 DB 0e8H, 014H, 0a9H, 08H, 0e8H, 014H
	DB	0a9H, 08H, 0e8H, 014H, 0a9H, 08H, 0e8H, 014H, 0a9H, 08H
CONST	ENDS
;	COMDAT __xmm@01010000010100000101000001010000
CONST	SEGMENT
__xmm@01010000010100000101000001010000 DB 00H, 00H, 01H, 01H, 00H, 00H, 01H
	DB	01H, 00H, 00H, 01H, 01H, 00H, 00H, 01H, 01H
CONST	ENDS
;	COMDAT __xmm@00ff00ff00ff00ff00ff00ff00ff00ff
CONST	SEGMENT
__xmm@00ff00ff00ff00ff00ff00ff00ff00ff DB 0ffH, 00H, 0ffH, 00H, 0ffH, 00H
	DB	0ffH, 00H, 0ffH, 00H, 0ffH, 00H, 0ffH, 00H, 0ffH, 00H
CONST	ENDS
;	COMDAT __xmm@00080008000800080008000800080008
CONST	SEGMENT
__xmm@00080008000800080008000800080008 DB 08H, 00H, 08H, 00H, 08H, 00H, 08H
	DB	00H, 08H, 00H, 08H, 00H, 08H, 00H, 08H, 00H
CONST	ENDS
;	COMDAT __xmm@00000200000002000000020000000200
CONST	SEGMENT
__xmm@00000200000002000000020000000200 DB 00H, 02H, 00H, 00H, 00H, 02H, 00H
	DB	00H, 00H, 02H, 00H, 00H, 00H, 02H, 00H, 00H
CONST	ENDS
;	COMDAT __xmm@00000004000000080000000800000008
CONST	SEGMENT
__xmm@00000004000000080000000800000008 DB 08H, 00H, 00H, 00H, 08H, 00H, 00H
	DB	00H, 08H, 00H, 00H, 00H, 04H, 00H, 00H, 00H
CONST	ENDS
;	COMDAT __xmm@00000004000000040000000800000008
CONST	SEGMENT
__xmm@00000004000000040000000800000008 DB 08H, 00H, 00H, 00H, 08H, 00H, 00H
	DB	00H, 04H, 00H, 00H, 00H, 04H, 00H, 00H, 00H
CONST	ENDS
;	COMDAT __xmm@00000003000000030000000300000003
CONST	SEGMENT
__xmm@00000003000000030000000300000003 DB 03H, 00H, 00H, 00H, 03H, 00H, 00H
	DB	00H, 03H, 00H, 00H, 00H, 03H, 00H, 00H, 00H
CONST	ENDS
;	COMDAT __xmm@00000002000000020000000200000002
CONST	SEGMENT
__xmm@00000002000000020000000200000002 DB 02H, 00H, 00H, 00H, 02H, 00H, 00H
	DB	00H, 02H, 00H, 00H, 00H, 02H, 00H, 00H, 00H
CONST	ENDS
;	COMDAT __xmm@00000002000000000000000400000000
CONST	SEGMENT
__xmm@00000002000000000000000400000000 DB 00H, 00H, 00H, 00H, 04H, 00H, 00H
	DB	00H, 00H, 00H, 00H, 00H, 02H, 00H, 00H, 00H
CONST	ENDS
;	COMDAT __xmm@00000000000000040000000000000000
CONST	SEGMENT
__xmm@00000000000000040000000000000000 DB 00H, 00H, 00H, 00H, 00H, 00H, 00H
	DB	00H, 04H, 00H, 00H, 00H, 00H, 00H, 00H, 00H
CONST	ENDS
;	COMDAT __real@c2480000
CONST	SEGMENT
__real@c2480000 DD 0c2480000r			; -50
CONST	ENDS
;	COMDAT __real@bf800000
CONST	SEGMENT
__real@bf800000 DD 0bf800000r			; -1
CONST	ENDS
;	COMDAT __real@bc8efa35
CONST	SEGMENT
__real@bc8efa35 DD 0bc8efa35r			; -0.0174533
CONST	ENDS
;	COMDAT __real@477fff00
CONST	SEGMENT
__real@477fff00 DD 0477fff00r			; 65535
CONST	ENDS
;	COMDAT __real@44480000
CONST	SEGMENT
__real@44480000 DD 044480000r			; 800
CONST	ENDS
;	COMDAT __real@44200000
CONST	SEGMENT
__real@44200000 DD 044200000r			; 640
CONST	ENDS
;	COMDAT __real@43f00000
CONST	SEGMENT
__real@43f00000 DD 043f00000r			; 480
CONST	ENDS
;	COMDAT __real@437f0000
CONST	SEGMENT
__real@437f0000 DD 0437f0000r			; 255
CONST	ENDS
;	COMDAT __real@42c80000
CONST	SEGMENT
__real@42c80000 DD 042c80000r			; 100
CONST	ENDS
;	COMDAT __real@428c0000
CONST	SEGMENT
__real@428c0000 DD 0428c0000r			; 70
CONST	ENDS
;	COMDAT __real@42480000
CONST	SEGMENT
__real@42480000 DD 042480000r			; 50
CONST	ENDS
;	COMDAT __real@41f00000
CONST	SEGMENT
__real@41f00000 DD 041f00000r			; 30
CONST	ENDS
;	COMDAT __real@41cdcd6500000000
CONST	SEGMENT
__real@41cdcd6500000000 DQ 041cdcd6500000000r	; 1e+09
CONST	ENDS
;	COMDAT __real@41200000
CONST	SEGMENT
__real@41200000 DD 041200000r			; 10
CONST	ENDS
;	COMDAT __real@40800000
CONST	SEGMENT
__real@40800000 DD 040800000r			; 4
CONST	ENDS
;	COMDAT __real@40400000
CONST	SEGMENT
__real@40400000 DD 040400000r			; 3
CONST	ENDS
;	COMDAT __real@40200000
CONST	SEGMENT
__real@40200000 DD 040200000r			; 2.5
CONST	ENDS
;	COMDAT __real@3ff0000000000000
CONST	SEGMENT
__real@3ff0000000000000 DQ 03ff0000000000000r	; 1
CONST	ENDS
;	COMDAT __real@3fdd1745c0000000
CONST	SEGMENT
__real@3fdd1745c0000000 DQ 03fdd1745c0000000r	; 0.454545
CONST	ENDS
;	COMDAT __real@3f91df46a2529e84
CONST	SEGMENT
__real@3f91df46a2529e84 DQ 03f91df46a2529e84r	; 0.0174533
CONST	ENDS
;	COMDAT __real@3f91111111111111
CONST	SEGMENT
__real@3f91111111111111 DQ 03f91111111111111r	; 0.0166667
CONST	ENDS
;	COMDAT __real@3f800000
CONST	SEGMENT
__real@3f800000 DD 03f800000r			; 1
CONST	ENDS
;	COMDAT __real@3f490fdb
CONST	SEGMENT
__real@3f490fdb DD 03f490fdbr			; 0.785398
CONST	ENDS
;	COMDAT __real@3f000000
CONST	SEGMENT
__real@3f000000 DD 03f000000r			; 0.5
CONST	ENDS
;	COMDAT __real@3dcccccd
CONST	SEGMENT
__real@3dcccccd DD 03dcccccdr			; 0.1
CONST	ENDS
;	COMDAT __real@3c8efa35
CONST	SEGMENT
__real@3c8efa35 DD 03c8efa35r			; 0.0174533
CONST	ENDS
;	COMDAT __real@3b800000
CONST	SEGMENT
__real@3b800000 DD 03b800000r			; 0.00390625
CONST	ENDS
;	COMDAT __real@34000000
CONST	SEGMENT
__real@34000000 DD 034000000r			; 1.19209e-07
CONST	ENDS
END
