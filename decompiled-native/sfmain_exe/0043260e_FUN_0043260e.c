// 0043260e FUN_0043260e [Global]
// programa: sfmain.exe

undefined8 __fastcall FUN_0043260e(undefined4 param_1,uint param_2)

{
  undefined4 extraout_ECX;
  undefined4 extraout_ECX_00;
  undefined4 uVar1;
  LPVOID pvVar2;
  longlong lVar3;
  
  lVar3 = FUN_00431aad(param_1,param_2);
  pvVar2 = (LPVOID)0x0;
  uVar1 = extraout_ECX;
  if ((int)lVar3 != 0) {
    pvVar2 = TlsGetValue(DAT_0043e7e8);
    uVar1 = extraout_ECX_00;
  }
  if (pvVar2 == (LPVOID)0x0) {
    FUN_00431f58(uVar1,1);
  }
  return CONCAT44(param_2,pvVar2);
}


