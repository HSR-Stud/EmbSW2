typedef int BASE;

BASE foo(BASE last, BASE x, BASE y)
{
 0: 2300        movs r3, #0
 2: e002        b.n a <foo+0xa>
  BASE i;
  for (i = 0; i < last; i++)
    x += (y * x);
 4: fb02 1101   mla r1, r2, r1, r1
 8: 3301        adds r3, #1
 a: 4283        cmp r3, r0
 c: dbfa        blt.n 4 <foo+0x4>
 e: ebc2 0001   rsb r0, r2, r1
  return(x-y);
}
12: 4770        bx lr
