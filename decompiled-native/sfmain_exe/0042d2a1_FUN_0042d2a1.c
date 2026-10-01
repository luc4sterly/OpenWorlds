// 0042d2a1 FUN_0042d2a1 [Global]
// program: sfmain.exe

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 __fastcall FUN_0042d2a1(undefined4 param_1,undefined4 param_2)

{
  int in_EAX;
  DWORD DVar1;
  undefined4 extraout_ECX;
  undefined4 extraout_ECX_00;
  undefined4 extraout_ECX_01;
  undefined4 extraout_ECX_02;
  undefined4 uVar2;
  undefined4 extraout_EDX;
  undefined4 extraout_EDX_00;
  undefined4 extraout_EDX_01;
  HMODULE unaff_EBX;
  undefined8 uVar3;
  CHAR local_10c [260];
  
  _DAT_004e57ac = in_EAX;
  uVar3 = FUN_00431a22(param_1,param_2);
  _DAT_004e57b0 = (int)uVar3;
  if (_DAT_004e57b0 == 0) {
    if (in_EAX == 0) {
                    /* WARNING: Subroutine does not return */
      ExitProcess(1);
    }
    uVar2 = 0;
  }
  else {
    FUN_0043187e(extraout_ECX,(int)((ulonglong)uVar3 >> 0x20));
    _DAT_0043e86d = GetEnvironmentStrings();
    GetModuleFileNameA((HMODULE)0x0,local_10c,0x104);
    uVar3 = FUN_0042cd01(extraout_ECX_00,extraout_EDX);
    _DAT_0043e840 = (undefined4)uVar3;
    GetCommandLineA();
    uVar3 = FUN_0042cd01(0,extraout_EDX_00);
    _DAT_0043e83c = (char *)uVar3;
    if (CONCAT31((int3)((uint)extraout_ECX_01 >> 8),*_DAT_0043e83c) != 0x22) {
      do {
        if (((&DAT_00437bd8)[(byte)(*_DAT_0043e83c + 1)] & 2) != 0) goto LAB_0042d34d;
        if (*_DAT_0043e83c == '\0') goto LAB_0042d34d;
        _DAT_0043e83c = _DAT_0043e83c + 1;
      } while( true );
    }
    do {
      _DAT_0043e83c = _DAT_0043e83c + 1;
      if (*_DAT_0043e83c == '\"') break;
    } while (*_DAT_0043e83c != '\0');
    if (*_DAT_0043e83c == '\0') goto LAB_0042d34d;
    do {
      _DAT_0043e83c = _DAT_0043e83c + 1;
LAB_0042d34d:
    } while (((&DAT_00437bd8)[(byte)(*_DAT_0043e83c + 1)] & 2) != 0);
    if (in_EAX != 0) {
      GetModuleFileNameA(unaff_EBX,local_10c,0x104);
      uVar3 = FUN_0042cd01(extraout_ECX_02,extraout_EDX_01);
      _DAT_0043e844 = (undefined4)uVar3;
    }
    DVar1 = GetVersion();
    DAT_0043e873 = (undefined1)(DVar1 >> 0x18);
    DAT_0043e875 = (undefined2)DVar1;
    DAT_0043e874 = (byte)(DVar1 >> 0x10) & 0xf;
    uVar2 = 1;
  }
  return uVar2;
}


