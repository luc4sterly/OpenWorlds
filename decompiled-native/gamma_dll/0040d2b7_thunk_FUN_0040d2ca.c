// 0040d2b7 thunk_FUN_0040d2ca [Global]
// programa: gamma.dll

/* WARNING (jumptable): Unable to track spacebase fully for stack */

undefined4 thunk_FUN_0040d2ca(void)

{
  undefined4 uVar1;
  uint unaff_EBX;
  uint uVar2;
  void *unaff_ESI;
  uint unaff_EDI;
  
  while( true ) {
    do {
      while( true ) {
        if (unaff_EDI != 0) {
          FUN_0040c2c0(unaff_ESI,2,unaff_EDI);
        }
        do {
          uVar2 = unaff_EBX;
          unaff_EBX = uVar2 - 1;
          if ((int)unaff_EBX < 0) {
            return 0;
          }
        } while ((1 << ((byte)unaff_EBX & 0x1f) &
                 *(uint *)(&DAT_0048927c + ((int)unaff_EBX >> 5) * 4)) == 0);
        if (unaff_EBX < 0x100) break;
        unaff_EDI = 0;
      }
      unaff_EDI = unaff_EBX;
    } while (((0x2f < unaff_EBX) && (unaff_EBX < 0x3a)) ||
            ((0x40 < unaff_EBX && (unaff_EBX < 0x5b))));
    if (uVar2 == 0x21) break;
    unaff_EDI = unaff_EBX | 0xe300;
  }
                    /* WARNING: Could not recover jumptable at 0x0040d2b0. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  uVar1 = (*(code *)PTR_thunk_FUN_0040d2ca_0046ef30)();
  return uVar1;
}


