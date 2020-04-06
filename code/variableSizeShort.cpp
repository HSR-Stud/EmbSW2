typedf short BASE;

Base foo(BASE last, BASE x, BASE y)
{
 0: f04f 0c00   mov.w ip, #0; 0x0
 4: e004        b.n 10 <foo+0x10>
  Base i;
  for (i = 0; i < last; i++)
    x += (y * x);
 6: fb02 1301   mla r3, r2, r1, r1
 a: f10c 0c01   add.w ip, ip, #1; 0x1
 e: b219        sxth r1, r3
10: fa0f f38c   sxth.w r3, ip
14: 4283        cmp r3, r0
16: dbf6        blt.n 6 <foo+0x6>
18: ebc2 0001   rsb r0, r2, r1
1c: b200        sxth r0, r0
  return(x-y);
}
1e: 4770        bx lr
