// 0040d377 thunk_FUN_0040d38a [Global]
// program: gamma.dll

/* WARNING (jumptable): Unable to track spacebase fully for stack */

undefined4 thunk_FUN_0040d38a(void)

{
  undefined4 uVar1;
  uint unaff_EBX;
  void *unaff_ESI;
  uint unaff_EDI;
  uint uVar2;
  
  while( true ) {
    do {
      while( true ) {
        if (unaff_EBX != 0) {
          FUN_0040c2c0(unaff_ESI,2,unaff_EBX);
        }
        do {
          uVar2 = unaff_EDI;
          unaff_EDI = uVar2 - 1;
          if ((int)unaff_EDI < 0) {
            return 0;
          }
        } while ((1 << ((byte)unaff_EDI & 0x1f) &
                 *(uint *)(&DAT_0048927c + ((int)unaff_EDI >> 5) * 4)) == 0);
        if (unaff_EDI < 0x100) break;
        unaff_EBX = 0;
      }
      unaff_EBX = unaff_EDI;
    } while (((0x2f < unaff_EDI) && (unaff_EDI < 0x3a)) ||
            ((0x40 < unaff_EDI && (unaff_EDI < 0x5b))));
    if (uVar2 == 0x21) break;
    unaff_EBX = unaff_EDI | 0xe300;
  }
                    /* WARNING: Could not recover jumptable at 0x0040d370. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  uVar1 = (*(code *)PTR_thunk_FUN_0040d38a_0046ef2c)();
  return uVar1;
}


