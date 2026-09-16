// 0040d606 thunk_FUN_0040d612 [Global]
// programa: gamma.dll

/* WARNING (jumptable): Unable to track spacebase fully for stack */

void thunk_FUN_0040d612(void)

{
  uint in_EAX;
  uint unaff_EBX;
  uint uVar1;
  int unaff_EBP;
  void *unaff_ESI;
  short unaff_DI;
  
  while( true ) {
    do {
      while( true ) {
        if (in_EAX != 0) {
          FUN_0040c2c0(unaff_ESI,2,in_EAX);
        }
        do {
          uVar1 = unaff_EBX;
          unaff_EBX = uVar1 - 1;
          if ((int)unaff_EBX < 0) {
            if ((unaff_DI != 0) && (DAT_0048929c < 0)) {
              DAT_0048929c = 0;
            }
            CallWindowProcA((WNDPROC)(&DAT_00489254)[*(int *)(unaff_EBP + 8)],
                            *(HWND *)(unaff_EBP + 0xc),*(UINT *)(unaff_EBP + 0x10),
                            *(WPARAM *)(unaff_EBP + 0x14),*(LPARAM *)(unaff_EBP + 0x18));
            return;
          }
        } while ((1 << ((byte)unaff_EBX & 0x1f) &
                 *(uint *)(&DAT_0048927c + ((int)unaff_EBX >> 5) * 4)) == 0);
        if (unaff_EBX < 0x100) break;
        in_EAX = 0;
      }
      in_EAX = unaff_EBX;
    } while (((0x2f < unaff_EBX) && (unaff_EBX < 0x3a)) ||
            ((0x40 < unaff_EBX && (unaff_EBX < 0x5b))));
    if (uVar1 == 0x21) break;
    in_EAX = unaff_EBX | 0xe300;
  }
                    /* WARNING: Could not recover jumptable at 0x0040d5ff. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*(code *)PTR_thunk_FUN_0040d612_0046ef24)();
  return;
}


