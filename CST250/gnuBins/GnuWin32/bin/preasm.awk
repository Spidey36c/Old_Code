BEGIN	{
	legal4 = " EXT INS ";
	legal3 = " ADD ADDI ADDIU ADDU SUB SUBU ROTR ROTRV SLL SLLV SRA SRAV SRL SRLV AND ANDI NOR OR ORI XOR XORI SLT SLTI SLTIU SLTU MOVN MOVZ DIV DIVU MUL BEQ BNE BLT BLE BGT BGE BLTU BLEU BGTU BGEU ";
	legal2 = " CLO CLZ LA LI LUI SEB SEH WSBH MADD MADDU MSUB MSUBU MUL MULT MULTU MFHI MFLO MTHI MTLO BGEZ BGEZAL BGTZ BLEZ BLTZ BLTZAL BLT JALR LB LBU LH LHU LW SB SH SW LW SW ";
	legal1 = " MFHI MFLO MTHI MTLO B J JAL JR ";
	legal0 = " NOP ";
#iFORM describes legal instruction formats by opcode numregs numnonregs
	iFORM = " add 30 addi 21 addiu 21 addu 30 clo 20 clz 20 la 11 li 11 lui 11 seb 20 seh 20 sub 30 subu 30";
        iFORM = iFORM " rotr 21 rotrv 30 sll 21 sllv 30 sra 21 srav 30 srl 21 srlv 30";
        iFORM = iFORM " and 30 andi 21 nor 30 or 30 ori 21 xor 30 xori 21";
        iFORM = iFORM " ext 22 ins 22 wsbh 20";
        iFORM = iFORM " slt 30 slti 21 sltiu 21 sltu 30 movn 30 movz 30";
        iFORM = iFORM " madd 20 maddu 20 msub 20 msubu mul 30 mult 20 multu 20";
        iFORM = iFORM " mfhi 10 mflo 10 mthi 10 mtlo 10";
        iFORM = iFORM " beq 21 bgez 11 bgezal 11 bgtz 11 blez 11 bltz 11 bltzal 11 bne 21";
        iFORM = iFORM " b 01 blt 21 ble 21 bgt 21 bge 21 bltu 21 bleu 21 bgtu 21 bgeu 21";
        iFORM = iFORM " j 01 jal 01 jalr 20 jr 10 nop 00";
        iFORM = iFORM " lb 11 lbu 11 lh 11 lhu 11 lw 11 sb 11 sh 11 sw 11";
        iFORM = iFORM " div 30 divu 30 ";
        loads = " lb lbu lh lhu lw sb sh sw ";
	divs = " div divu ";
	regs = " $0 zero $at at $1 v0 v1 a0 a1 a2 a3 t0 t1 t2 t3 t4 t5 t6 t7 t8 t9 s0 s1 s2 s3 s4 s5 s6 s7 s8 k0 k1 gp sp fp ra ";
	macros = " ";
}
#do new file processing
FNR == 1 {
	check = 0; comment = 0;
	if(FILENAME !~ /\.S$/) {
		print "Preasm check skipping " FILENAME;
		nextfile;
	}
}
/^[ 	]*\.data/ {	# turn off checking for data segment
	check = 0;
	next;
}
/^[ 	]*\.text/ {
	check = 1;
	next;
}
/^[ 	]*\.macro/	{ #macro directive
	sub(/^[	 ]*/,"", $0); # remove leading whitespace
	macros = macros tolower($2) " ";
	#note that macros are not case sensitive
#	print "Macros: ", macros;
	next;
}
check == 0	{
	next;
}
/^[ 	]*[A-Za-z][^:]*:[ 	]*\./	{ #directive with label
	next;
}
/^[ 	]*\./	{ #directive
	next;
}
/^[ 	]*$/	{ #empty line
	next;
}
/^[ 	]*\/\//	{ #only comment
	next;
}
/^[ 	]*#/	{ #define macro
	next;
}
	{
	line = $0;
	#process for /* comments
	#first see if comment block ends in this line
	if(comment == 1) {
		ec = index(line, "*/");
		if(ec != 0) {
			line = substr(line, ec+2, length(line)-ec-1);
			comment = 0;
		} else { #in /* comment body
			next;
		}
	}
	#then remove matched in line comment marks
	do {
		fc = 0;
		bc = index(line, "/*");
		ec = index(line, "*/");
		if(comment == 0 && bc != 0 && bc+1 < ec) {
			fc = 1; #found matched comment marks in line
			#remove them
			newline = substr(line,1,bc-1) substr(line,ec+2,length(line)-ec-1);
			line = newline;
		}
	} while(fc == 1);
	if(ec > 0) {
		print FILENAME ":" FNR ": Warning: There appears to be an isolated */: \"" $0 "\"";
	}
	if(bc > 0) { #new comment begins on this line
		comment = 1;
		line = substr(line,1,bc-1);
	}
	#debug
	#if(line != $0) { # comments removed
	#	print "--" $0 "--";
	#	print "--" line "--";
	#}
	sub(/\/\/.*$/,"", line); # remove trailing // comment
	sub(/^[^:][^:]*:/,"", line); # remove labels
	sub(/^[ 	]*/,"", line); # remove beginning whitespace
	sub(/\/\*.*$/,"", line); # remove trailing /* comment
	sub(/[ 	]*$/,"", line); # remove trailing whitespace
	if(line == "") next; # nothing left to process
	gsub(/[ 	][ 	]*/," ", line); # collapse whitespace
	procline = line; #keep for error output
	gsub(/ *, */,",", line); # remove spaces where there are commas
	sub(/ /,",",line); #first space separator should follow opcode, replace with comma
	#debug
	#print ":" line ":";
	n = split(line, ary, ",");
	if(n > 0) {
		oppat = " " tolower(ary[1]) " "; #pad with spaces and set to lower case
	#process instructions using iFORM
	#first check if opcode is a defined macro
		if((index(macros, oppat) != 0)){
			next; #macros not checked
		}
	#next make sure opcode is in the list 
		if((index(iFORM, oppat) == 0)){
		print FILENAME ":" FNR ": Error: Unrecognized or Un-allowed opcode or pseudo: \"" ary[1] "\"";
		errors++;
		next; #No need to continue
		}
		#Next check operands
		rarg = 0;
		narg = 0;
		for(k = 2; k <= n; k++) {
			pat = " " ary[k] " ";
			if(index(regs, pat) != 0) { #found reg operand
				rarg++;
			} else {
				break; #end of reg ops
			}
		} # rest should be non regs
		operr = 0;
		for(; k <= n; k++) {
			pat = " " arg[k] " ";
			if(index(regs, pat) == 0) { #found non reg operand
				narg++;
			} else {
				#should not be reg op here
				operr = 1;
				break;
			}
		}
		pat = oppat rarg narg " ";
		#debug
		#print "<" line "> <" pat ">";
		if(index(iFORM, pat) == 0) operr = 1;
		if(index(divs,oppat) != 0) {
			#found a div, already checked args, make sure $0 is first arg
			#print "Div";
			if(ary[2] != "$0" && ary[2] != "zero") operr = 1;
#		} else if (index(loads, oppat) != 0) {
			#found a load
			#decided loads don't need special processing
#			print "Load";
		} else if (oppat == " la ") {
			# found an la, already checked args, make sure off(reg) 
			# is not source (i.e. no ( in ary[3] )
		  	if(ary[3] ~ /.*\(/) operr = 1;
#			print "LA", ary[3];
		}
		if(operr == 1) {
		print FILENAME ":" FNR ": Error: Improper instruction format: \"" procline "\"";
		print "   See the Instruction Reference for opcode \"" ary[1] "\" for legal operands.";
			errors++;

		}
	} else { # split did not succeed
		print "Warning: Problem with preasm. Please report to professor";
	}
	next;
}

END	{
	if(errors > 0) {
		exit(1);
	}
}
