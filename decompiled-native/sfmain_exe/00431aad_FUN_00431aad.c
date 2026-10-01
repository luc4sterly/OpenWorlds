// 00431aad FUN_00431aad [Global]
// program: sfmain.exe

longlong __fastcall FUN_00431aad(undefined4 param_1,uint param_2)

{
  LPVOID lpTlsValue;
  int iVar1;
  undefined4 uVar2;
  undefined4 extraout_ECX;
  undefined8 uVar3;
  
  if (DAT_0043e7e8 == 0xffffffff) {
LAB_00431ab9:
    return (ulonglong)param_2 << 0x20;
  }
  uVar3 = FUN_00431a22(param_1,param_2);
  lpTlsValue = (LPVOID)uVar3;
  uVar2 = 0;
  if (lpTlsValue != (LPVOID)0x0) {
    iVar1 = FUN_00432645(extraout_ECX,(int)lpTlsValue);
    if (iVar1 == 0) {
      FUN_0042b9b8();
      goto LAB_00431ab9;
    }
    TlsSetValue(DAT_0043e7e8,lpTlsValue);
    uVar2 = 1;
  }
  return CONCAT44(param_2,uVar2);
}


