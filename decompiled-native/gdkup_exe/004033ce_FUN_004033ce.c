// 004033ce FUN_004033ce [Global]
// programa: gdkup.exe

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 __fastcall FUN_004033ce(undefined4 param_1,undefined4 param_2)

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
  
  DAT_0040b438 = in_EAX;
  uVar3 = FUN_0040514d(param_1,param_2);
  DAT_0040b43c = (int)uVar3;
  if (DAT_0040b43c == 0) {
    if (in_EAX == 0) {
                    /* WARNING: Subroutine does not return */
      ExitProcess(1);
    }
    uVar2 = 0;
  }
  else {
    FUN_00404fa9(extraout_ECX,(int)((ulonglong)uVar3 >> 0x20));
    _DAT_00408e9d = GetEnvironmentStrings();
    GetModuleFileNameA((HMODULE)0x0,local_10c,0x104);
    uVar3 = FUN_00405421(extraout_ECX_00,extraout_EDX);
    _DAT_00408e70 = (undefined4)uVar3;
    GetCommandLineA();
    uVar3 = FUN_00405421(0,extraout_EDX_00);
    _DAT_00408e6c = (char *)uVar3;
    if (CONCAT31((int3)((uint)extraout_ECX_01 >> 8),*_DAT_00408e6c) != 0x22) {
      do {
        if (((&DAT_00408958)[(byte)(*_DAT_00408e6c + 1)] & 2) != 0) goto LAB_0040347a;
        if (*_DAT_00408e6c == '\0') goto LAB_0040347a;
        _DAT_00408e6c = _DAT_00408e6c + 1;
      } while( true );
    }
    do {
      _DAT_00408e6c = _DAT_00408e6c + 1;
      if (*_DAT_00408e6c == '\"') break;
    } while (*_DAT_00408e6c != '\0');
    if (*_DAT_00408e6c == '\0') goto LAB_0040347a;
    do {
      _DAT_00408e6c = _DAT_00408e6c + 1;
LAB_0040347a:
    } while (((&DAT_00408958)[(byte)(*_DAT_00408e6c + 1)] & 2) != 0);
    if (in_EAX != 0) {
      GetModuleFileNameA(unaff_EBX,local_10c,0x104);
      uVar3 = FUN_00405421(extraout_ECX_02,extraout_EDX_01);
      _DAT_00408e74 = (undefined4)uVar3;
    }
    DVar1 = GetVersion();
    DAT_00408ea3 = (undefined1)(DVar1 >> 0x18);
    DAT_00408ea5 = (undefined2)DVar1;
    DAT_00408ea4 = (byte)(DVar1 >> 0x10) & 0xf;
    uVar2 = 1;
  }
  return uVar2;
}


