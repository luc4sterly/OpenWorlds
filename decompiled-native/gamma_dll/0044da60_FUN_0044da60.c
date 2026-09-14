// 0044da60 FUN_0044da60 [Global]
// programa: gamma.dll

DWORD __cdecl FUN_0044da60(int param_1,LONG param_2,undefined4 param_3)

{
  LPVOID pvVar1;
  DWORD DVar2;
  DWORD unaff_EBX;
  
  if ((param_1 < 0x100) && ((undefined4 *)(&DAT_0049f448)[param_1] != (undefined4 *)0x0)) {
    switch(param_3) {
    case 0:
      unaff_EBX = 0;
      break;
    case 1:
      unaff_EBX = 1;
      break;
    case 2:
      unaff_EBX = 2;
    }
    DVar2 = SetFilePointer(*(HANDLE *)(&DAT_0049f448)[param_1],param_2,(PLONG)0x0,unaff_EBX);
    return DVar2;
  }
  pvVar1 = FUN_00453ed0();
  *(undefined4 *)((int)pvVar1 + 4) = 3;
  return 0xffffffff;
}


