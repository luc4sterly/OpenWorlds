// 004051d8 FUN_004051d8 [Global]
// program: gdkup.exe

longlong __fastcall FUN_004051d8(undefined4 param_1,uint param_2)

{
  LPVOID lpTlsValue;
  int iVar1;
  undefined4 uVar2;
  undefined4 extraout_ECX;
  undefined8 uVar3;
  
  if (DAT_00408b34 == 0xffffffff) {
LAB_004051e4:
    return (ulonglong)param_2 << 0x20;
  }
  uVar3 = FUN_0040514d(param_1,param_2);
  lpTlsValue = (LPVOID)uVar3;
  uVar2 = 0;
  if (lpTlsValue != (LPVOID)0x0) {
    iVar1 = FUN_0040682e(extraout_ECX,(int)lpTlsValue);
    if (iVar1 == 0) {
      FUN_00403235();
      goto LAB_004051e4;
    }
    TlsSetValue(DAT_00408b34,lpTlsValue);
    uVar2 = 1;
  }
  return CONCAT44(param_2,uVar2);
}


