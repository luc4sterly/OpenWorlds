// 00424019 FUN_00424019 [Global]
// program: sfmain.exe

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00424019(void)

{
  DWORD DVar1;
  BOOL BVar2;
  undefined4 extraout_ECX;
  undefined4 extraout_ECX_00;
  undefined4 extraout_EDX;
  tagMSG local_34;
  
  DVar1 = GetTickCount();
  if (0x15e < DVar1 - _DAT_0043d7e4) {
    DAT_0043d6c8 = DAT_0043d6c8 + 1;
    FUN_004173ab(extraout_ECX,DAT_0043d6c8);
    while( true ) {
      BVar2 = PeekMessageA(&local_34,(HWND)0x0,0,0,1);
      if (BVar2 == 0) break;
      FUN_00423f69(extraout_ECX_00,extraout_EDX);
    }
  }
  return;
}


