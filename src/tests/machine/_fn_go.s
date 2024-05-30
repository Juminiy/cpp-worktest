main.fn0 STEXT nosplit size=39 args=0x10 locals=0x10 funcid=0x0 align=0x0
	0x0000 00000 (C:/Users/chisato/code/cpp-worktest/src/tests/machine/_fn.go:3)	TEXT	main.fn0(SB), NOSPLIT|ABIInternal, $16-16
	0x0000 00000 (C:/Users/chisato/code/cpp-worktest/src/tests/machine/_fn.go:3)	PUSHQ	BP
	0x0001 00001 (C:/Users/chisato/code/cpp-worktest/src/tests/machine/_fn.go:3)	MOVQ	SP, BP
	0x0004 00004 (C:/Users/chisato/code/cpp-worktest/src/tests/machine/_fn.go:3)	SUBQ	$8, SP
	0x0008 00008 (C:/Users/chisato/code/cpp-worktest/src/tests/machine/_fn.go:3)	FUNCDATA	$0, gclocals·g2BeySu+wFnoycgXfElmcg==(SB)
	0x0008 00008 (C:/Users/chisato/code/cpp-worktest/src/tests/machine/_fn.go:3)	FUNCDATA	$1, gclocals·g2BeySu+wFnoycgXfElmcg==(SB)
	0x0008 00008 (C:/Users/chisato/code/cpp-worktest/src/tests/machine/_fn.go:3)	FUNCDATA	$5, main.fn0.arginfo1(SB)
	0x0008 00008 (C:/Users/chisato/code/cpp-worktest/src/tests/machine/_fn.go:3)	MOVQ	AX, main.a+24(SP)
	0x000d 00013 (C:/Users/chisato/code/cpp-worktest/src/tests/machine/_fn.go:3)	MOVQ	BX, main.b+32(SP)
	0x0012 00018 (C:/Users/chisato/code/cpp-worktest/src/tests/machine/_fn.go:3)	MOVQ	$0, main.~r0(SP)
	0x001a 00026 (C:/Users/chisato/code/cpp-worktest/src/tests/machine/_fn.go:4)	ADDQ	BX, AX
	0x001d 00029 (C:/Users/chisato/code/cpp-worktest/src/tests/machine/_fn.go:4)	MOVQ	AX, main.~r0(SP)
	0x0021 00033 (C:/Users/chisato/code/cpp-worktest/src/tests/machine/_fn.go:4)	ADDQ	$8, SP
	0x0025 00037 (C:/Users/chisato/code/cpp-worktest/src/tests/machine/_fn.go:4)	POPQ	BP
	0x0026 00038 (C:/Users/chisato/code/cpp-worktest/src/tests/machine/_fn.go:4)	RET
	0x0000 55 48 89 e5 48 83 ec 08 48 89 44 24 18 48 89 5c  UH..H...H.D$.H.\
	0x0010 24 20 48 c7 04 24 00 00 00 00 48 01 d8 48 89 04  $ H..$....H..H..
	0x0020 24 48 83 c4 08 5d c3                             $H...].
main.fn1 STEXT nosplit size=31 args=0x28 locals=0x10 funcid=0x0 align=0x0
	0x0000 00000 (C:/Users/chisato/code/cpp-worktest/src/tests/machine/_fn.go:7)	TEXT	main.fn1(SB), NOSPLIT|ABIInternal, $16-40
	0x0000 00000 (C:/Users/chisato/code/cpp-worktest/src/tests/machine/_fn.go:7)	PUSHQ	BP
	0x0001 00001 (C:/Users/chisato/code/cpp-worktest/src/tests/machine/_fn.go:7)	MOVQ	SP, BP
	0x0004 00004 (C:/Users/chisato/code/cpp-worktest/src/tests/machine/_fn.go:7)	SUBQ	$8, SP
	0x0008 00008 (C:/Users/chisato/code/cpp-worktest/src/tests/machine/_fn.go:7)	FUNCDATA	$0, gclocals·g2BeySu+wFnoycgXfElmcg==(SB)
	0x0008 00008 (C:/Users/chisato/code/cpp-worktest/src/tests/machine/_fn.go:7)	FUNCDATA	$1, gclocals·g2BeySu+wFnoycgXfElmcg==(SB)
	0x0008 00008 (C:/Users/chisato/code/cpp-worktest/src/tests/machine/_fn.go:7)	FUNCDATA	$5, main.fn1.arginfo1(SB)
	0x0008 00008 (C:/Users/chisato/code/cpp-worktest/src/tests/machine/_fn.go:7)	MOVQ	$0, main.~r0(SP)
	0x0010 00016 (C:/Users/chisato/code/cpp-worktest/src/tests/machine/_fn.go:8)	MOVQ	main.arr+32(SP), AX
	0x0015 00021 (C:/Users/chisato/code/cpp-worktest/src/tests/machine/_fn.go:8)	MOVQ	AX, main.~r0(SP)
	0x0019 00025 (C:/Users/chisato/code/cpp-worktest/src/tests/machine/_fn.go:8)	ADDQ	$8, SP
	0x001d 00029 (C:/Users/chisato/code/cpp-worktest/src/tests/machine/_fn.go:8)	POPQ	BP
	0x001e 00030 (C:/Users/chisato/code/cpp-worktest/src/tests/machine/_fn.go:8)	RET
	0x0000 55 48 89 e5 48 83 ec 08 48 c7 04 24 00 00 00 00  UH..H...H..$....
	0x0010 48 8b 44 24 20 48 89 04 24 48 83 c4 08 5d c3     H.D$ H..$H...].
main.main STEXT size=121 args=0x0 locals=0x58 funcid=0x0 align=0x0
	0x0000 00000 (C:/Users/chisato/code/cpp-worktest/src/tests/machine/_fn.go:11)	TEXT	main.main(SB), ABIInternal, $88-0
	0x0000 00000 (C:/Users/chisato/code/cpp-worktest/src/tests/machine/_fn.go:11)	CMPQ	SP, 16(R14)
	0x0004 00004 (C:/Users/chisato/code/cpp-worktest/src/tests/machine/_fn.go:11)	PCDATA	$0, $-2
	0x0004 00004 (C:/Users/chisato/code/cpp-worktest/src/tests/machine/_fn.go:11)	JLS	114
	0x0006 00006 (C:/Users/chisato/code/cpp-worktest/src/tests/machine/_fn.go:11)	PCDATA	$0, $-1
	0x0006 00006 (C:/Users/chisato/code/cpp-worktest/src/tests/machine/_fn.go:11)	PUSHQ	BP
	0x0007 00007 (C:/Users/chisato/code/cpp-worktest/src/tests/machine/_fn.go:11)	MOVQ	SP, BP
	0x000a 00010 (C:/Users/chisato/code/cpp-worktest/src/tests/machine/_fn.go:11)	SUBQ	$80, SP
	0x000e 00014 (C:/Users/chisato/code/cpp-worktest/src/tests/machine/_fn.go:11)	FUNCDATA	$0, gclocals·g2BeySu+wFnoycgXfElmcg==(SB)
	0x000e 00014 (C:/Users/chisato/code/cpp-worktest/src/tests/machine/_fn.go:11)	FUNCDATA	$1, gclocals·g2BeySu+wFnoycgXfElmcg==(SB)
	0x000e 00014 (C:/Users/chisato/code/cpp-worktest/src/tests/machine/_fn.go:12)	MOVQ	$1, main.arr+40(SP)
	0x0017 00023 (C:/Users/chisato/code/cpp-worktest/src/tests/machine/_fn.go:12)	MOVQ	$2, main.arr+48(SP)
	0x0020 00032 (C:/Users/chisato/code/cpp-worktest/src/tests/machine/_fn.go:12)	MOVQ	$3, main.arr+56(SP)
	0x0029 00041 (C:/Users/chisato/code/cpp-worktest/src/tests/machine/_fn.go:12)	MOVQ	$4, main.arr+64(SP)
	0x0032 00050 (C:/Users/chisato/code/cpp-worktest/src/tests/machine/_fn.go:12)	MOVQ	$5, main.arr+72(SP)
	0x003b 00059 (C:/Users/chisato/code/cpp-worktest/src/tests/machine/_fn.go:13)	MOVL	$1, AX
	0x0040 00064 (C:/Users/chisato/code/cpp-worktest/src/tests/machine/_fn.go:13)	MOVL	$2, BX
	0x0045 00069 (C:/Users/chisato/code/cpp-worktest/src/tests/machine/_fn.go:13)	PCDATA	$1, $0
	0x0045 00069 (C:/Users/chisato/code/cpp-worktest/src/tests/machine/_fn.go:13)	CALL	main.fn0(SB)
	0x004a 00074 (C:/Users/chisato/code/cpp-worktest/src/tests/machine/_fn.go:14)	MOVQ	main.arr+40(SP), CX
	0x004f 00079 (C:/Users/chisato/code/cpp-worktest/src/tests/machine/_fn.go:14)	MOVQ	CX, (SP)
	0x0053 00083 (C:/Users/chisato/code/cpp-worktest/src/tests/machine/_fn.go:14)	MOVUPS	main.arr+48(SP), X0
	0x0058 00088 (C:/Users/chisato/code/cpp-worktest/src/tests/machine/_fn.go:14)	MOVUPS	X0, 8(SP)
	0x005d 00093 (C:/Users/chisato/code/cpp-worktest/src/tests/machine/_fn.go:14)	MOVUPS	main.arr+64(SP), X0
	0x0062 00098 (C:/Users/chisato/code/cpp-worktest/src/tests/machine/_fn.go:14)	MOVUPS	X0, 24(SP)
	0x0067 00103 (C:/Users/chisato/code/cpp-worktest/src/tests/machine/_fn.go:14)	CALL	main.fn1(SB)
	0x006c 00108 (C:/Users/chisato/code/cpp-worktest/src/tests/machine/_fn.go:15)	ADDQ	$80, SP
	0x0070 00112 (C:/Users/chisato/code/cpp-worktest/src/tests/machine/_fn.go:15)	POPQ	BP
	0x0071 00113 (C:/Users/chisato/code/cpp-worktest/src/tests/machine/_fn.go:15)	RET
	0x0072 00114 (C:/Users/chisato/code/cpp-worktest/src/tests/machine/_fn.go:15)	NOP
	0x0072 00114 (C:/Users/chisato/code/cpp-worktest/src/tests/machine/_fn.go:11)	PCDATA	$1, $-1
	0x0072 00114 (C:/Users/chisato/code/cpp-worktest/src/tests/machine/_fn.go:11)	PCDATA	$0, $-2
	0x0072 00114 (C:/Users/chisato/code/cpp-worktest/src/tests/machine/_fn.go:11)	CALL	runtime.morestack_noctxt(SB)
	0x0077 00119 (C:/Users/chisato/code/cpp-worktest/src/tests/machine/_fn.go:11)	PCDATA	$0, $-1
	0x0077 00119 (C:/Users/chisato/code/cpp-worktest/src/tests/machine/_fn.go:11)	JMP	0
	0x0000 49 3b 66 10 76 6c 55 48 89 e5 48 83 ec 50 48 c7  I;f.vlUH..H..PH.
	0x0010 44 24 28 01 00 00 00 48 c7 44 24 30 02 00 00 00  D$(....H.D$0....
	0x0020 48 c7 44 24 38 03 00 00 00 48 c7 44 24 40 04 00  H.D$8....H.D$@..
	0x0030 00 00 48 c7 44 24 48 05 00 00 00 b8 01 00 00 00  ..H.D$H.........
	0x0040 bb 02 00 00 00 e8 00 00 00 00 48 8b 4c 24 28 48  ..........H.L$(H
	0x0050 89 0c 24 0f 10 44 24 30 0f 11 44 24 08 0f 10 44  ..$..D$0..D$...D
	0x0060 24 40 0f 11 44 24 18 e8 00 00 00 00 48 83 c4 50  $@..D$......H..P
	0x0070 5d c3 e8 00 00 00 00 eb 87                       ]........
	rel 70+4 t=7 main.fn0+0
	rel 104+4 t=7 main.fn1+0
	rel 115+4 t=7 runtime.morestack_noctxt+0
go:cuinfo.producer.<unlinkable> SDWARFCUINFO dupok size=0
	0x0000 2d 4e 20 2d 6c 20 72 65 67 61 62 69              -N -l regabi
go:cuinfo.packagename.main SDWARFCUINFO dupok size=0
	0x0000 6d 61 69 6e                                      main
main..inittask SNOPTRDATA size=8
	0x0000 00 00 00 00 00 00 00 00                          ........
main..stmp_0 SRODATA static size=40
	0x0000 01 00 00 00 00 00 00 00 02 00 00 00 00 00 00 00  ................
	0x0010 03 00 00 00 00 00 00 00 04 00 00 00 00 00 00 00  ................
	0x0020 05 00 00 00 00 00 00 00                          ........
type:.eqfunc40 SRODATA dupok size=16
	0x0000 00 00 00 00 00 00 00 00 28 00 00 00 00 00 00 00  ........(.......
	rel 0+8 t=1 runtime.memequal_varlen+0
runtime.memequal64·f SRODATA dupok size=8
	0x0000 00 00 00 00 00 00 00 00                          ........
	rel 0+8 t=1 runtime.memequal64+0
runtime.gcbits.0100000000000000 SRODATA dupok size=8
	0x0000 01 00 00 00 00 00 00 00                          ........
type:.namedata.*[5]int- SRODATA dupok size=9
	0x0000 00 07 2a 5b 35 5d 69 6e 74                       ..*[5]int
type:*[5]int SRODATA dupok size=56
	0x0000 08 00 00 00 00 00 00 00 08 00 00 00 00 00 00 00  ................
	0x0010 d2 90 a4 99 08 08 08 36 00 00 00 00 00 00 00 00  .......6........
	0x0020 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00  ................
	0x0030 00 00 00 00 00 00 00 00                          ........
	rel 24+8 t=1 runtime.memequal64·f+0
	rel 32+8 t=1 runtime.gcbits.0100000000000000+0
	rel 40+4 t=5 type:.namedata.*[5]int-+0
	rel 48+8 t=1 type:[5]int+0
runtime.gcbits. SRODATA dupok size=0
type:[5]int SRODATA dupok size=72
	0x0000 28 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00  (...............
	0x0010 82 ad 93 3d 0a 08 08 11 00 00 00 00 00 00 00 00  ...=............
	0x0020 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00  ................
	0x0030 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00  ................
	0x0040 05 00 00 00 00 00 00 00                          ........
	rel 24+8 t=1 type:.eqfunc40+0
	rel 32+8 t=1 runtime.gcbits.+0
	rel 40+4 t=5 type:.namedata.*[5]int-+0
	rel 44+4 t=-32763 type:*[5]int+0
	rel 48+8 t=1 type:int+0
	rel 56+8 t=1 type:[]int+0
gclocals·g2BeySu+wFnoycgXfElmcg== SRODATA dupok size=8
	0x0000 01 00 00 00 00 00 00 00                          ........
main.fn0.arginfo1 SRODATA static dupok size=5
	0x0000 00 08 08 08 ff                                   .....
main.fn1.arginfo1 SRODATA static dupok size=13
	0x0000 fe 00 08 08 08 10 08 18 08 20 08 fd ff           ......... ...
