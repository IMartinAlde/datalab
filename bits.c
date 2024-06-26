/*
 * CS:APP Data Lab
 *
 * <Please put your name and userid here>
 *
 * bits.c - Source file with your solutions to the Lab.
 *          This is the file you will hand in to your instructor.
 *
 * WARNING: Do not include the <stdio.h> header; it confuses the dlc
 * compiler. You can still use printf for debugging without including
 * <stdio.h>, although you might get a compiler warning. In general,
 * it's not good practice to ignore compiler warnings, but in this
 * case it's OK.
 */

#if 0
/*
 * Instructions to Students:
 *
 * STEP 1: Read the following instructions carefully.
 */

You will provide your solution to the Data Lab by
editing the collection of functions in this source file.

INTEGER CODING RULES:

  Replace the "return" statement in each function with one
  or more lines of C code that implements the function. Your code
  must conform to the following style:

  int Funct(arg1, arg2, ...) {
      /* brief description of how your implementation works */
      int var1 = Expr1;
      ...
      int varM = ExprM;

      varJ = ExprJ;
      ...
      varN = ExprN;
      return ExprR;
  }

  Each "Expr" is an expression using ONLY the following:
  1. Integer constants 0 through 255 (0xFF), inclusive. You are
      not allowed to use big constants such as 0xffffffff.
  2. Function arguments and local variables (no global variables).
  3. Unary integer operations ! ~
  4. Binary integer operations & ^ | + << >>

  Some of the problems restrict the set of allowed operators even further.
  Each "Expr" may consist of multiple operators. You are not restricted to
  one operator per line.

  You are expressly forbidden to:
  1. Use any control constructs such as if, do, while, for, switch, etc.
  2. Define or use any macros.
  3. Define any additional functions in this file.
  4. Call any functions.
  5. Use any other operations, such as &&, ||, -, or ?:
  6. Use any form of casting.
  7. Use any data type other than int.  This implies that you
     cannot use arrays, structs, or unions.


  You may assume that your machine:
  1. Uses 2s complement, 32-bit representations of integers.
  2. Performs right shifts arithmetically.
  3. Has unpredictable behavior when shifting if the shift amount
     is less than 0 or greater than 31.


EXAMPLES OF ACCEPTABLE CODING STYLE:
  /*
   * pow2plus1 - returns 2^x + 1, where 0 <= x <= 31
   */
  int pow2plus1(int x) {
     /* exploit ability of shifts to compute powers of 2 */
     return (1 << x) + 1;
  }

  /*
   * pow2plus4 - returns 2^x + 4, where 0 <= x <= 31
   */
  int pow2plus4(int x) {
     /* exploit ability of shifts to compute powers of 2 */
     int result = (1 << x);
     result += 4;
     return result;
  }

FLOATING POINT CODING RULES

For the problems that require you to implement floating-point operations,
the coding rules are less strict.  You are allowed to use looping and
conditional control.  You are allowed to use both ints and unsigneds.
You can use arbitrary integer and unsigned constants. You can use any arithmetic,
logical, or comparison operations on int or unsigned data.

You are expressly forbidden to:
  1. Define or use any macros.
  2. Define any additional functions in this file.
  3. Call any functions.
  4. Use any form of casting.
  5. Use any data type other than int or unsigned.  This means that you
     cannot use arrays, structs, or unions.
  6. Use any floating point data types, operations, or constants.


NOTES:
  1. Use the dlc (data lab checker) compiler (described in the handout) to
     check the legality of your solutions.
  2. Each function has a maximum number of operations (integer, logical,
     or comparison) that you are allowed to use for your implementation
     of the function.  The max operator count is checked by dlc.
     Note that assignment ('=') is not counted; you may use as many of
     these as you want without penalty.
  3. Use the btest test harness to check your functions for correctness.
  4. Use the BDD checker to formally verify your functions
  5. The maximum number of ops for each function is given in the
     header comment for each function. If there are any inconsistencies
     between the maximum ops in the writeup and in this file, consider
     this file the authoritative source.

/*
 * STEP 2: Modify the following functions according the coding rules.
 *
 *   IMPORTANT. TO AVOID GRADING SURPRISES:
 *   1. Use the dlc compiler to check that your solutions conform
 *      to the coding rules.
 *   2. Use the BDD checker to formally verify that your solutions produce
 *      the correct answers.
 */


#endif
//1
/*
 * bitAnd - x&y using only ~ and |
 *   Example: bitAnd(6, 5) = 4
 *   Legal ops: ~ |
 *   Max ops: 8
 *   Rating: 1
 */
int bitAnd(int x, int y) {
  return  ~(~ x | ~ y);
}
/*
 * bitMatch - Create mask indicating which bits in x match those in y
 *            using only ~ and &
 *   Example: bitMatch(0x7, 0xE) = 0x6
 *   Legal ops: ~ & |
 *   Max ops: 14
 *   Rating: 1
 */
int bitMatch(int x, int y) {
  // 0101 0111 -> 1101?
  // 
  return ~((x | y) & (~x | ~y));
}
/*
 * bitNor - ~(x|y) using only ~ and &
 *   Example: bitNor(0x6, 0x5) = 0xFFFFFFF8
 *   Legal ops: ~ &
 *   Max ops: 8
 *   Rating: 1
 */
int bitNor(int x, int y) {
  return (~x & ~y);
}
/*
 * bitXor - x^y using only ~ and &
 *   Example: bitXor(4, 5) = 1
 *   Legal ops: ~ &
 *   Max ops: 14
 *   Rating: 1
 */
int bitXor(int x, int y) {
  return ~(~x & ~y) & ~(x & y) ;
}
//2
/*
 * allOddBits - return 1 if all odd-numbered bits in word set to 1
 *   where bits are numbered from 0 (least significant) to 31 (most significant)
 *   Examples allOddBits(0xFFFFFFFD) = 0, allOddBits(0xAAAAAAAA) = 1
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 12
 *   Rating: 2
 */
int allOddBits(int x) {
  int m8 = 0xAA;
  int m16 = m8 | m8<< 8;
  int m32 = m16 | m16 <<16;
  //10101010101010101010101010101010 m32 
  //10101010101010111010111011101011 x
  int resultado_parcial =(x & m32);
  return !(resultado_parcial ^ m32);
}

/*
 * anyEvenBit - return 1 if any even-numbered bit in word set to 1
 *   where bits are numbered from 0 (least significant) to 31 (most significant)
 *   Examples anyEvenBit(0xA) = 0, anyEvenBit(0xE) = 1
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 12
 *   Rating: 2
 */
int anyEvenBit(int x) {

  int m8, m16, m32, evenx;

  m8 = 0x55;
  m16 = m8 | m8 << 8;
  m32 = m16 | m16 << 16;
  evenx = x & m32;

  return !!evenx;
}
/*
 * byteSwap - swaps the nth byte and the mth byte
 *  Examples: byteSwap(0x12345678, 1, 3) = 0x56341278                 
 *            byteSwap(0xDEADBEEF, 0, 2) = 0xDEEFBEAD
 *  You may assume that 0 <= n <= 3, 0 <= m <= 3
 *  Legal ops: ! ~ & ^ | + << >>
 *  Max ops: 25
 *  Rating: 2
 */
int byteSwap(int x, int n, int m) {

    int n_bits, m_bits, m_n, m_m, m_resto, primer_byte, segundo_byte;

    n_bits = n << 3;
    m_bits = m << 3;
    m_n = 0xFF << n_bits;
    m_m = 0xFF << m_bits;
    m_resto = ~ (m_n | m_m);
    
    primer_byte = (((x >> n_bits) & 0xFF) << m_bits);
    segundo_byte = (((x >> m_bits) & 0Xff) << n_bits);

  return primer_byte | segundo_byte | (x & m_resto);
}
/*
 * fitsBits - return 1 if x can be represented as an
 *  n-bit, two's complement integer.
 *   1 <= n <= 32
 *   Examples: fitsBits(5,3) = 0, fitsBits(-4,3) = 1
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 15
 *   Rating: 2
 */
int fitsBits(int x, int n) {
  int m8= 0xFF; 
  int m16= m8 | m8 <<8;
  int m32= m16 | m16 <<16;
  int mask = m32 <<(n + m32);
  int copia_x = (mask) & (x);
  int copia_x2 = (copia_x >> n);
  int copia_x3 = ~(copia_x2 ^ copia_x);
  int rta = copia_x3 & mask;
  return !(rta ^ mask);
}
/*
 * negate - return -x
 *   Example: negate(1) = -1.
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 5
 *   Rating: 2
 */
int negate(int x) {
  return  ~x + 1;
}
/*
 * sign - return 1 if positive, 0 if zero, and -1 if negative
 *  Examples: sign(130) = 1
 *            sign(-23) = -1
 *  Legal ops: ! ~ & ^ | + << >>
 *  Max ops: 10
 *  Rating: 2
 */
int sign(int x) {
  return (x >> 31) | (!!x);

  //Mi otro procedimiento: (((x | (~x + 1)) >> 31) & 0xFF) + (((!!x) << 1) + (~1 + 1))
}
//3
/*
 * addOK - Determine if can compute x+y without overflow
 *   Example: addOK(0x80000000,0x80000000) = 0,
 *            addOK(0x80000000,0x70000000) = 1,
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 20
 *   Rating: 3
 */
int addOK(int x, int y) {
  int m8= 0x01; 
  int m16= m8 | m8 <<8;
  int m32= m16 | m16 <<16;
  int mask = m32 << 31;
  int suma= x+y;
  int copia_x= (mask & x);
  int copia_y= (mask & y);
  int son_diff = ~(copia_x ^ copia_y);
  suma = suma & mask;
  int result = (suma ^ copia_x);
  return !(result & son_diff);
}
/*
 * bitMask - Generate a mask consisting of all 1's
 *   lowbit and highbit
 *   Examples: bitMask(5,3) = 0x38
 *   Assume 0 <= lowbit <= 31, and 0 <= highbit <= 31
 *   If lowbit > highbit, then mask should be all 0's
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 16
 *   Rating: 3
 */
int bitMask(int highbit, int lowbit) {
  int negative = ~0;
  int mask1 = negative << highbit << 1;
  int mask2 = negative << lowbit;
  return ~mask1 & mask2 ; 
}
/*
 * conditional - same as x ? y : z
 *   Example: conditional(2,4,5) = 4
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 16
 *   Rating: 3
 */
int conditional(int x, int y, int z) {
  int es_cero;
  es_cero = ((0xFF << 24) >> 24) + (!x);
    
  return (~es_cero & z) | ((es_cero) & y);
}
/*
 * isAsciiDigit - return 1 if 0x30 <= x <= 0x39 (ASCII codes for characters '0' to '9')
 *   Example: isAsciiDigit(0x35) = 1.
 *            isAsciiDigit(0x3a) = 0.
 *            isAsciiDigit(0x05) = 0.
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 15
 *   Rating: 3
 */
int isAsciiDigit(int x) {
  int m8= 0xFF;
  int m16= m8 | m8 <<8;
  int m32= m16 | m16 <<16;
  int mask = m32 << 4; 
  int num=0x30;
  int es_30= mask & x;
  es_30= (es_30 ^ num);
  int mayor_igual_8= x << 28 ;
  mayor_igual_8= (mayor_igual_8 >>31);
  int menor_a_9= (x & 0x06);
  menor_a_9 = (!(menor_a_9 & mayor_igual_8));
  return (! (es_30 | !menor_a_9));
}
/*
 * isGreater - if x > y  then return 1, else return 0
 *   Example: isGreater(4,5) = 0, isGreater(5,4) = 1
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 24
 *   Rating: 3
 */
int isGreater(int x, int y) {
  int signo_X;
  int signo_Y;
  signo_X = (x >> 31) & 1;  
  signo_Y = (y >> 31) & 1;  
  return ((!(signo_X ^ signo_Y) & !(((x+~y)>>31) & 1)) | ((!signo_X) & signo_Y)) & 1;
}
/*
 * replaceByte(x,n,c) - Replace byte n in x with c
 *   Bytes numbered from 0 (LSB) to 3 (MSB)
 *   Examples: replaceByte(0x12345678,1,0xab) = 0x1234ab78
 *   You can assume 0 <= n <= 3 and 0 <= c <= 255
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 10
 *   Rating: 3
 */
int replaceByte(int x, int n, int c) {
  int bits, byte, m_byte;
  bits = n << 3;
  byte = c << bits;
  m_byte = 0xFF << bits;

  return (x & (~ m_byte)) | byte;
}
//4
/*
 * absVal - absolute value of x
 *   Example: absVal(-1) = 1.
 *   You may assume -TMax <= x <= TMax
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 10
 *   Rating: 4
 */
int absVal(int x) {
  int m8= 0x01;
  int mask= m8<<31;
  int es_neg= !!(mask & x);
  int mask_aux= x>>31; 
  return (mask_aux ^ x ) + (es_neg);
}
/*
 * bang - Compute !x without using !
 *   Examples: bang(3) = 0, bang(0) = 1
 *   Legal ops: ~ & ^ | + << >>
 *   Max ops: 12
 *   Rating: 4
 */
int bang(int x) {
    return (((x | (~x + 1)) >> 31) + 1) & 1;
}
/*
 * isNonZero - Check whether x is nonzero using
 *              the legal operators except !
 *   Examples: isNonZero(3) = 1, isNonZero(0) = 0
 *   Legal ops: ~ & ^ | + << >>
 *   Max ops: 10
 *   Rating: 4
 */
int isNonZero(int x) {
  int mask = x | (~x+1);
  int most_significant = mask >> 31;
  return most_significant & 1;
}
/*
 * logicalNeg - implement the ! operator, using all of
 *              the legal operators except !
 *   Examples: logicalNeg(3) = 0, logicalNeg(0) = 1
 *   Legal ops: ~ & ^ | + << >>
 *   Max ops: 12
 *   Rating: 4
 */
int logicalNeg(int x) {
    return (((x | (~x + 1)) >> 31) + 1) & 1;
}
//float
/*
 * floatAbsVal - Return bit-level equivalent of absolute value of f for
 *   floating point argument f.
 *   Both the argument and result are passed as unsigned int's, but
 *   they are to be interpreted as the bit-level representations of
 *   single-precision floating point values.
 *   When argument is NaN, return argument..
 *   Legal ops: Any integer/unsigned operations incl. ||, &&. also if, while
 *   Max ops: 10
 *   Rating: 2
 */
unsigned floatAbsVal(unsigned uf) {
    int mask_nan = 0xFF;
    int mask = mask_nan << 31;
    mask_nan =  mask_nan << 23;
    int uf2 = uf ^ mask;
    if(mask & uf){
        int exponente_all_1 = ( (uf & (mask_nan)) ^ (mask_nan));
        int distinto = (mask_nan ^ (uf2));
        if ( (!exponente_all_1) && distinto){
            return (uf);
        }
        return (uf2);
    }
    return uf;
}
/*
 * floatIsEqual - Compute f == g for floating point arguments f and g.
 *   Both the arguments are passed as unsigned int's, but
 *   they are to be interpreted as the bit-level representations of
 *   single-precision floating point values.
 *   If either argument is NaN, return 0.
 *   +0 and -0 are considered equal.
 *   Legal ops: Any integer/unsigned operations incl. ||, &&. also if, while
 *   Max ops: 25
 *   Rating: 2
 */
  int floatIsEqual(unsigned uf, unsigned ug) {

      int signo_uf, signo_ug, frac_uf, frac_ug, exp_uf, exp_ug, numero_uf, numero_ug;

      signo_uf = uf >> 31;
      signo_ug = ug >> 31;
      frac_uf = (uf << 9) >> 17;
      frac_ug = (ug << 9) >> 17;
      exp_uf = (uf >> 23) & 0xFF;
      exp_ug = (ug >> 23) & 0xFF;
      numero_uf = uf << 1;
      numero_ug = ug << 1; //12

      if (((frac_uf != 0x00) && (exp_uf == 0xFF)) || ((frac_ug != 0x00) && (exp_ug == 0xFF))){
        return 0;
      }

      if (signo_uf == signo_ug){
        if (numero_uf == numero_ug){
          return 1;
        }
      }else{
        if ((numero_uf == 0) && (numero_ug == 0)){
          return 1;
        }
      }
      return 0;
  }
/*
 * floatNegate - Return bit-level equivalent of expression -f for
 *   floating point argument f.
 *   Both the argument and result are passed as unsigned int's, but
 *   they are to be interpreted as the bit-level representations of
 *   single-precision floating point values.
 *   When argument is NaN, return argument.
 *   Legal ops: Any integer/unsigned operations incl. ||, &&. also if, while
 *   Max ops: 10
 *   Rating: 2
 */
unsigned floatNegate(unsigned uf) {
  int uf_exp, uf_frac;

  uf_exp = (uf >> 23) & 0xFF;
  uf_frac = (uf << 9) >> 17;

  if ((uf_frac != 0x00) && (uf_exp == 0xFF)){
    return uf;
  }
  return (0x80 << 24) ^ uf;
}
/*
 * floatIsLess - Compute f < g for floating point arguments f and g.
 *   Both the arguments are passed as unsigned int's, but
 *   they are to be interpreted as the bit-level representations of
 *   single-precision floating point values.
 *   If either argument is NaN, return 0.
 *   +0 and -0 are considered equal.
 *   Legal ops: Any integer/unsigned operations incl. ||, &&. also if, while
 *   Max ops: 30
 *   Rating: 3
 */
int floatIsLess(unsigned uf, unsigned ug) {
    int signo_ug;
    int signo_uf;
    int uf_exp, uf_frac;
    int ug_exp, ug_frac;

    signo_uf = uf >> 31;
    signo_ug = ug >> 31;
    uf_exp = (uf >> 23) & 0xFF;
    uf_frac = (uf << 9) >> 17;
    ug_exp = (ug >> 23) & 0xFF;
    ug_frac = (ug << 9) >> 17;

    if (((uf_frac != 0x00) && (uf_exp == 0xFF)) ||((ug_frac != 0x00) && (ug_exp == 0xFF))|| !((uf | ug) << 1))
      // Si alguno de los dos es NaN o si g y f son +0 -0
        return 0;
    if (signo_uf > signo_ug) 
      // uf es negativo pero no ug => g > f
        return 1;
    if(signo_ug == signo_uf && ((signo_ug && ug < uf) || ((signo_ug == 0) && ug > uf)))
      // si son del mismo signo hay 2 escenarios
      // si son negativos f > g => g > f
      // si son positivos g > f => g > f
        return 1;
    return 0;
}

/*
 * floatFloat2Int - Return bit-level equivalent of expression (int) f
 *   for floating point argument f.
 *   Argument is passed as unsigned int, but
 *   it is to be interpreted as the bit-level representation of a
 *   single-precision floating point value.
 *   Anything out of range (including NaN and infinity) should return
 *   0x80000000u.
 *   Legal ops: Any integer/unsigned operations incl. ||, &&. also if, while
 *   Max ops: 30
 *   Rating: 4
 */
int floatFloat2Int(unsigned uf) {
  int mask;
  int cota_uf;
  int signo_uf;
  int frac_uf;
  int exponente_uf;
  signo_uf = uf >> 31;   
  cota_uf = 0x1 << 31; 
  exponente_uf= ((uf >> 23) & 0xff) - 127;  
  frac_uf = uf & 0x007fffff;   
  mask  = frac_uf | (0x1 << 23);

  if(exponente_uf < 0) 
    return 0;

  if(exponente_uf > 31) 
    return cota_uf;

  if(exponente_uf > 23){ 

      mask = mask << (exponente_uf - 23);
  }else{

      mask = mask >> (23-exponente_uf); 
  }

  if(!(( mask >> 31) ^ signo_uf)){ 

    return mask;

  }else if(mask >> 31){

      return cota_uf;

  }else{
      return ~mask + 1;
  }   

}

/*
 * floatPower2 - Return bit-level equivalent of the expression 2.0^x
 *   (2.0 raised to the power x) for any 32-bit integer x.
 *
 *   The unsigned value that is returned should have the identical bit
 *   representation as the single-precision floating-point number 2.0^x.
 *   If the result is too small to be represented as a denorm, return
 *   0. If too large, return +INF.
 *
 *   Legal ops: Any integer/unsigned operations incl. ||, &&. Also if, while
 *   Max ops: 30
 *   Rating: 4
 */
unsigned floatPower2(int x) {

    int exp_despl = x + 127;

    if (exp_despl > 0xFF) {
        return (0xFF << 23);
    } else if (exp_despl < 1) {
        return 0;
    } else {
        return (exp_despl << 23);
    }
}
