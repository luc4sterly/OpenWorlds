// 0040dbe2 FUN_0040dbe2 [Global]
// program: sfmain.exe

void FUN_0040dbe2(void)

{
  int iVar1;
  int iVar2;
  undefined4 extraout_ECX;
  undefined4 local_20;
  undefined4 local_1c;
  
  DAT_00445b20 = 0;
  DAT_004393b8 = 0;
  if (DAT_004393a4 != 0) {
    while( true ) {
      local_1c = DAT_00445b20;
      iVar1 = FUN_0040daee(&DAT_00445b58,&local_20);
      if (iVar1 == 0) break;
      if ((DAT_00445b5b & 1) != 0) {
        iVar2 = FUN_0040d6c0(extraout_ECX,DAT_004393b8 + 1);
        iVar1 = DAT_004393b8;
        if (iVar2 == 0) {
          return;
        }
        DAT_004393b8 = DAT_004393b8 + 1;
        *(undefined4 *)(DAT_004393b0 + iVar1 * 4) = local_1c;
      }
    }
  }
  DAT_00445b20 = 0;
  return;
}


