// push constant 17
@17
D=A
@SP
A=M
M=D
@SP
M=M+1
// push constant 17
@17
D=A
@SP
A=M
M=D
@SP
M=M+1
// eq  
@SP
A=M
A=A-1
D=M
A=A-1
D=M-D
@_EQ0_
D;JEQ
@SP
M=M-1
A=M
A=A-1
M=0
@_END0_
0;JMP
(_EQ0_)
@SP
M=M-1
A=M
A=A-1
M=-1
(_END0_)
// push constant 17
@17
D=A
@SP
A=M
M=D
@SP
M=M+1
// push constant 16
@16
D=A
@SP
A=M
M=D
@SP
M=M+1
// eq  
@SP
A=M
A=A-1
D=M
A=A-1
D=M-D
@_EQ1_
D;JEQ
@SP
M=M-1
A=M
A=A-1
M=0
@_END1_
0;JMP
(_EQ1_)
@SP
M=M-1
A=M
A=A-1
M=-1
(_END1_)
// push constant 16
@16
D=A
@SP
A=M
M=D
@SP
M=M+1
// push constant 17
@17
D=A
@SP
A=M
M=D
@SP
M=M+1
// eq  
@SP
A=M
A=A-1
D=M
A=A-1
D=M-D
@_EQ2_
D;JEQ
@SP
M=M-1
A=M
A=A-1
M=0
@_END2_
0;JMP
(_EQ2_)
@SP
M=M-1
A=M
A=A-1
M=-1
(_END2_)
// push constant 892
@892
D=A
@SP
A=M
M=D
@SP
M=M+1
// push constant 891
@891
D=A
@SP
A=M
M=D
@SP
M=M+1
// lt  
@SP
A=M
A=A-1
D=M
A=A-1
D=M-D
@_LT3_
D;JLT
@SP
M=M-1
A=M
A=A-1
M=0
@_END3_
0;JMP
(_LT3_)
@SP
M=M-1
A=M
A=A-1
M=-1
(_END3_)
// push constant 891
@891
D=A
@SP
A=M
M=D
@SP
M=M+1
// push constant 892
@892
D=A
@SP
A=M
M=D
@SP
M=M+1
// lt  
@SP
A=M
A=A-1
D=M
A=A-1
D=M-D
@_LT4_
D;JLT
@SP
M=M-1
A=M
A=A-1
M=0
@_END4_
0;JMP
(_LT4_)
@SP
M=M-1
A=M
A=A-1
M=-1
(_END4_)
// push constant 891
@891
D=A
@SP
A=M
M=D
@SP
M=M+1
// push constant 891
@891
D=A
@SP
A=M
M=D
@SP
M=M+1
// lt  
@SP
A=M
A=A-1
D=M
A=A-1
D=M-D
@_LT5_
D;JLT
@SP
M=M-1
A=M
A=A-1
M=0
@_END5_
0;JMP
(_LT5_)
@SP
M=M-1
A=M
A=A-1
M=-1
(_END5_)
// push constant 32767
@32767
D=A
@SP
A=M
M=D
@SP
M=M+1
// push constant 32766
@32766
D=A
@SP
A=M
M=D
@SP
M=M+1
// gt  
@SP
A=M
A=A-1
D=M
A=A-1
D=M-D
@_GT6_
D;JGT
@SP
M=M-1
A=M
A=A-1
M=0
@_END6_
0;JMP
(_GT6_)
@SP
M=M-1
A=M
A=A-1
M=-1
(_END6_)
// push constant 32766
@32766
D=A
@SP
A=M
M=D
@SP
M=M+1
// push constant 32767
@32767
D=A
@SP
A=M
M=D
@SP
M=M+1
// gt  
@SP
A=M
A=A-1
D=M
A=A-1
D=M-D
@_GT7_
D;JGT
@SP
M=M-1
A=M
A=A-1
M=0
@_END7_
0;JMP
(_GT7_)
@SP
M=M-1
A=M
A=A-1
M=-1
(_END7_)
// push constant 32766
@32766
D=A
@SP
A=M
M=D
@SP
M=M+1
// push constant 32766
@32766
D=A
@SP
A=M
M=D
@SP
M=M+1
// gt  
@SP
A=M
A=A-1
D=M
A=A-1
D=M-D
@_GT8_
D;JGT
@SP
M=M-1
A=M
A=A-1
M=0
@_END8_
0;JMP
(_GT8_)
@SP
M=M-1
A=M
A=A-1
M=-1
(_END8_)
// push constant 57
@57
D=A
@SP
A=M
M=D
@SP
M=M+1
// push constant 31
@31
D=A
@SP
A=M
M=D
@SP
M=M+1
// push constant 53
@53
D=A
@SP
A=M
M=D
@SP
M=M+1
// add  
@SP
A=M
A=A-1
D=M
A=A-1
M=D+M
@SP
M=M-1
// push constant 112
@112
D=A
@SP
A=M
M=D
@SP
M=M+1
// sub  
@SP
A=M
A=A-1
D=M
A=A-1
M=M-D
@SP
M=M-1
// neg  
@SP
A=M
A=A-1
M=-M
// and  
@SP
A=M
A=A-1
D=M
A=A-1
D=D&M
M=D
@SP
M=M-1
// push constant 82
@82
D=A
@SP
A=M
M=D
@SP
M=M+1
// or  
@SP
A=M
A=A-1
D=M
A=A-1
D=D|M
M=D
@SP
M=M-1
// not  
@SP
A=M
A=A-1
M=!M
