#include "spimcore.h"


/* ALU */
/* 10 Points */
void ALU(unsigned A,unsigned B,char ALUControl,unsigned *ALUresult,char *Zero)
{

}

/* instruction fetch */
/* 10 Points */
int instruction_fetch(unsigned PC,unsigned *Mem,unsigned *instruction)
{

}


/* instruction partition */
/* 10 Points */
void instruction_partition(unsigned instruction, unsigned *op, unsigned *r1,unsigned *r2, unsigned *r3, unsigned *funct, unsigned *offset, unsigned *jsec)
{

}



/* instruction decode */
/* 15 Points */
int instruction_decode(unsigned op,struct_controls *controls)
{

}

/* Read Register */
/* 5 Points */
void read_register(unsigned r1,unsigned r2,unsigned *Reg,unsigned *data1,unsigned *data2)
{

}


/* Sign Extend */
/* 10 Points */
void sign_extend(unsigned offset,unsigned *extended_value)
{

}

/* ALU operations */
/* 10 Points */
int ALU_operations(unsigned data1,unsigned data2,unsigned extended_value,unsigned funct,char ALUOp,char ALUSrc,unsigned *ALUresult,char *Zero)
{

}

/* Read / Write Memory */
/* 10 Points */
int rw_memory(unsigned ALUresult,unsigned data2,char MemWrite,char MemRead,unsigned *memdata,unsigned *Mem)
{

}


/* Write Register */
/* 10 Points */
void write_register(unsigned r2, unsigned r3, unsigned memdata, unsigned ALUresult, char RegWrite, char RegDst, char MemtoReg, unsigned *Reg) {
    if (RegWrite) { // Only perform the write if RegWrite is enabled
        // Determine the destination register
        unsigned destReg = RegDst ? r3 : r2;
        
        // Write data to the register
        if (MemtoReg) {
            // Write memory data to register
            Reg[destReg] = memdata;
        } else {
            // Write ALU result to register
            Reg[destReg] = ALUresult;
        }
    }
}

/* PC update */
/* 10 Points */
void PC_update(unsigned jsec, unsigned extended_value, char Branch, char Jump, char Zero, unsigned *PC) {
    // If Jump is enabled, set PC to jsec shifted left by 2 bits
    if (Jump) {
        *PC = (jsec << 2);
    }
    // If Branch is enabled and Zero is true, set PC to PC + 4 + (extended_value shifted left by 2 bits)
    else if (Branch && Zero) {
        *PC = *PC + 4 + (extended_value << 2);
    }
    // Otherwise, increment PC by 4 (next instruction)
    else {
        *PC = *PC + 4;
    }
}
